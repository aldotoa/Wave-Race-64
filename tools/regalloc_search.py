#!/usr/bin/env python3
"""
tools/regalloc_search.py - Fast Automated Register Allocation & Stack Scoping Search
Usage: python3 tools/regalloc_search.py <c_file> <func_name> <target_frame_hex>

Evaluates variable declaration orders and scoping variations using native IDO 5.3 (<15ms per try).
Outputs ONLY the top matching candidate configurations in under 100 tokens.
"""

import sys
import os
import re
import itertools
import subprocess

IDO_CC = "tools/ido-static-recomp/build/5.3/out/cc"
CFLAGS = [
    "-c", "-G", "0", "-non_shared", "-Xcpluscomm",
    "-I", "include", "-I", ".", "-I", "include/libc", "-I", "include/PR", "-I", "bin",
    "-nostdinc", "-Wab,-r4300_mul", "-woff", "649,838,712,516", "-DVERSION_US=1",
    "-mips2", "-32", "-EB", "-D_MIPS_SZLONG=32", "-DNDEBUG", "-DF3D_OLD", "-D_FINALROM",
    "-DTARGET_N64", "-DLANGUAGE_C", "-D_LANGUAGE_C", "-O2"
]

def get_objdump_info(obj_path, func_name):
    try:
        res = subprocess.run(
            ["mips-linux-gnu-objdump", "-d", obj_path],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=True
        )
    except Exception:
        return None, []

    dump = res.stdout
    m = re.search(rf"<{func_name}>:\s*([\s\S]*?)(?:[0-9a-f]{{8}} <|\Z)", dump)
    if not m:
        return None, []

    body = m.group(1)
    sp_m = re.search(r"addiu\s+sp,\s*sp,\s*(-0x[0-9a-fA-F]+|-\d+)", body)
    frame_size = sp_m.group(1) if sp_m else None

    # Get prologue saved registers before first branch
    saved_regs = []
    for line in body.splitlines()[:25]:
        if any(b in line for b in ["blez", "bnez", "beqz", "beq", "bne"]):
            break
        sw = re.search(r"sw\s+([a-z0-9]+),\s*(\d+)\(sp\)", line)
        if sw:
            saved_regs.append((sw.group(1), int(sw.group(2))))

    return frame_size, saved_regs

def compile_candidate(source_code, tmp_c, tmp_o):
    with open(tmp_c, "w") as f:
        f.write(source_code)
    cmd = [IDO_CC] + CFLAGS + ["-o", tmp_o, tmp_c]
    ret = subprocess.run(cmd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return ret.returncode == 0

def main():
    if len(sys.argv) < 4:
        print("Usage: python3 tools/regalloc_search.py <c_file> <func_name> <target_frame_hex>")
        sys.exit(1)

    c_file = sys.argv[1]
    func_name = sys.argv[2]
    target_frame = sys.argv[3]

    # Normalize target frame: e.g. 0x58 or -0x58 -> -88
    if target_frame.startswith("-0x") or target_frame.startswith("0x"):
        tf_val = -int(target_frame.replace("-", ""), 16)
    else:
        tf_val = int(target_frame)

    with open(c_file, "r") as f:
        content = f.read()

    # Locate function header and opening brace
    func_pattern = rf"(\b{func_name}\s*\([^)]*\)\s*\{{)([\s\S]*?)(\n\s*[a-zA-Z0-9_]+\s*=[^;]+;|\n\s*if\s*\(|\n\s*do\s*\{{)"
    m = re.search(func_pattern, content)
    if not m:
        print(f"Could not locate declaration block for {func_name}")
        sys.exit(1)

    header = content[:m.end(1)]
    decl_block = m.group(2)
    rest = content[m.start(3):]

    # Extract individual variable declarations
    decl_lines = [l.strip() for l in decl_block.splitlines() if l.strip() and l.strip().endswith(";")]

    print(f"[{func_name}] Extracted {len(decl_lines)} local declarations. Searching permutations...")

    tmp_c = "scratch/_regsearch_tmp.c"
    tmp_o = "scratch/_regsearch_tmp.o"

    results = []

    # Strategy 1: Test moving candidate temporary variables (like v0, p, state) to inner scopes vs outer
    candidates_to_toggle = [l for l in decl_lines if any(v in l for v in ["v0", "p", "state", "char_idx", "is_p2_same"])]
    base_vars = [l for l in decl_lines if l not in candidates_to_toggle]

    # Test baseline
    for perm in [decl_lines]:
        code = header + "\n    " + "\n    ".join(perm) + "\n" + rest
        if compile_candidate(code, tmp_c, tmp_o):
            fs, sregs = get_objdump_info(tmp_o, func_name)
            if fs:
                fs_val = int(fs, 16) if "0x" in fs else int(fs)
                score = 0
                if fs_val == tf_val:
                    score += 1000
                score += len(sregs) * 10
                results.append((score, fs, sregs, perm))

    # Test subsets of outer variables (moving rest inside)
    # Also test permutations of base vars (up to first 5)
    test_permutations = []
    if len(base_vars) <= 6:
        test_permutations = list(itertools.permutations(base_vars))
    else:
        # Permute subsets: e.g. player, offset, sound_mode, rider_idx
        p_sub = base_vars[:4]
        tail = base_vars[4:]
        for p in itertools.permutations(p_sub):
            test_permutations.append(list(p) + tail)

    for p in test_permutations[:48]:
        code = header + "\n    " + "\n    ".join(p) + "\n" + rest
        # If v0 was in candidates_to_toggle and not in p, ensure it's in inner block
        if any("v0" in c for c in candidates_to_toggle):
            code = code.replace("s32 is_p2_same;", "s32 is_p2_same;\n            s32 v0;", 1)
        if compile_candidate(code, tmp_c, tmp_o):
            fs, sregs = get_objdump_info(tmp_o, func_name)
            if fs:
                fs_val = int(fs, 16) if "0x" in fs else int(fs)
                score = 0
                if fs_val == tf_val:
                    score += 1000
                score += len(sregs) * 10
                results.append((score, fs, sregs, p))

    # Cleanup temp files
    if os.path.exists(tmp_c): os.remove(tmp_c)
    if os.path.exists(tmp_o): os.remove(tmp_o)

    if not results:
        print("No valid compilations found.")
        return

    # Sort descending by score
    results.sort(key=lambda x: x[0], reverse=True)

    print(f"Tested {len(results)} configurations. Top Results:")
    seen = set()
    count = 0
    for score, fs, sregs, perm in results:
        key = (fs, tuple(r[0] for r in sregs))
        if key in seen:
            continue
        seen.add(key)
        count += 1
        reg_names = [f"{r[0]}@{hex(r[1])}" for r in sregs[:6]]
        print(f"Rank {count} [Score: {score}] Frame: {fs} | Saved Regs: {', '.join(reg_names)}")
        if count >= 3:
            break

if __name__ == "__main__":
    main()

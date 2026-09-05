import subprocess
import re
import sys

with open("scratch/test_tmp.c") as f:
    orig = f.read()

# Make sure s1 and s5 use &arr[player]
orig = orig.replace("s1 = ARR_PTR(D_i2_802C8BB0);", "s1 = &D_i2_802C8BB0[player];")
orig = orig.replace("s5 = ARR_PTR(D_i2_802C8BB8);", "s5 = &D_i2_802C8BB8[player];")

header, body = orig.split("u32 func_i2_802C5E28", 1)
body = "u32 func_i2_802C5E28" + body
matches = list(re.finditer(r"ARR_VAL\(([a-zA-Z0-9_]+)\)", body))
n_matches = len(matches)
print(f"Testing 2^{n_matches} = {1 << n_matches} subsets...")

found = []

for mask in range(1 << n_matches):
    new_body = body
    for i in reversed(range(n_matches)):
        m = matches[i]
        if (mask & (1 << i)):
            # replace with arr[player]
            new_body = new_body[:m.start()] + f"{m.group(1)}[player]" + new_body[m.end():]
        else:
            # keep ARR_VAL
            pass
    code = header + new_body
    with open("scratch/test_sub.c", "w") as f:
        f.write(code)
    
    cmd = ("tools/ido-static-recomp/build/5.3/out/cc -c -G 0 -non_shared -Xcpluscomm "
           "-I include -I . -I include/libc -I include/PR -I bin "
           "-nostdinc -Wab,-r4300_mul -woff 649,838,712,516 -DVERSION_US=1 "
           "-mips2 -32 -EB -D_MIPS_SZLONG=32 -DNDEBUG -DF3D_OLD -D_FINALROM "
           "-DTARGET_N64 -DLANGUAGE_C -D_LANGUAGE_C -O2 "
           "-o scratch/test_sub.o scratch/test_sub.c")
    ret = subprocess.run(cmd, shell=True, capture_output=True)
    if ret.returncode != 0:
        continue
    dump = subprocess.run("/opt/homebrew/bin/mips-linux-gnu-objdump -d -M reg-names=mips3 scratch/test_sub.o",
                          shell=True, capture_output=True, text=True).stdout
    m_func = re.search(r'<func_i2_802C5E28>:\s*([\s\S]*?)(?:[0-9a-f]{8} <|\Z)', dump)
    if not m_func:
        continue
    lines = [l.strip() for l in m_func.group(1).splitlines() if l.strip()]
    blez_lines = [j for j, l in enumerate(lines) if 'blez' in l]
    if not blez_lines:
        continue
    idx = blez_lines[0]
    delay = lines[idx+1]
    after = lines[idx+2:idx+8]
    after_str = " ".join(after)
    
    # Check conditions:
    # 1. delay slot is move s0, zero
    is_s0 = "move" in delay and "s0,zero" in delay
    # 2. after has move s4, zero
    is_s4 = "move" in after_str and "s4,zero" in after_str
    # 3. after has li s3, 1
    is_s3 = "li" in after_str and "s3,1" in after_str
    # 4. after has li s8, 4
    is_s8 = "li" in after_str and "s8,4" in after_str
    # 5. after has s7 for D_800DA9C0
    is_s7 = "lui" in after_str and "s7," in after_str
    
    if is_s0 and is_s4 and is_s3 and is_s8 and is_s7:
        print(f"PERFECT MATCH FOUND at mask={mask:07b} ({mask})!")
        found.append(mask)
    elif is_s0 and is_s4:
        print(f"Candidate s0+s4 at mask={mask:07b}: {delay} | {after_str}")

print(f"Total perfect matches: {len(found)}")

#!/usr/bin/env python3
"""
Stack Frame Layout Differ for Wave Race 64 Decompilation
Usage:
    python3 tools/stack_diff.py <func_name> <path/to/target.s> [path/to/current.o]

Features:
- Extracts target frame size and all ($sp) offsets from target assembly (.s).
- Disassembles current object (.o) and extracts current frame size and (sp) offsets.
- Displays a concise side-by-side comparison of:
    1. Total frame size (detecting 8- or 16-byte inflation)
    2. High-stack outer declared locals
    3. Middle padding / buffer zones
    4. Low-stack register spills and callee-saved registers
"""

import sys
import os
import re
import subprocess

def parse_target_s(path, func_name):
    if not os.path.exists(path):
        print(f"Error: Target file '{path}' not found.", file=sys.stderr)
        sys.exit(1)
    
    with open(path, "r", encoding="utf-8", errors="ignore") as f:
        lines = f.readlines()
        
    in_func = False
    frame_size = None
    offsets = set()
    
    for line in lines:
        if f"glabel {func_name}" in line:
            in_func = True
            continue
        if in_func and f"endlabel {func_name}" in line:
            break
        if in_func:
            m_frame = re.search(r"addiu\s+\$sp,\s+\$sp,\s+-0x([0-9a-fA-F]+)", line)
            if m_frame and frame_size is None:
                frame_size = int(m_frame.group(1), 16)
            
            for m_off in re.finditer(r"0x([0-9a-fA-F]+)\(\$sp\)", line):
                offsets.add(int(m_off.group(1), 16))
                
    return frame_size, sorted(offsets)

def parse_current_o(obj_path, func_name):
    if not os.path.exists(obj_path):
        return None, []
        
    cmd = ["mips-linux-gnu-objdump", "-d", obj_path]
    try:
        out = subprocess.check_output(cmd).decode("utf-8")
    except Exception as e:
        print(f"Error running objdump: {e}", file=sys.stderr)
        return None, []
        
    start_tag = f"<{func_name}>:"
    start = out.find(start_tag)
    if start == -1:
        return None, []
        
    next_func = re.search(r"\n[0-9a-fA-F]+ <[^>]+>:", out[start + len(start_tag):])
    end = (start + len(start_tag) + next_func.start()) if next_func else len(out)
    func_disasm = out[start:end]
    
    frame_size = None
    offsets = set()
    
    for line in func_disasm.splitlines():
        # Match addiu sp,sp,-248 or addiu sp,sp,-0xf8
        m_frame = re.search(r"addiu\s+sp,\s*sp,\s*-([0-9a-fA-F]+)", line)
        if m_frame and frame_size is None:
            raw_val = m_frame.group(1)
            frame_size = int(raw_val, 16) if any(c in "abcdefABCDEF" for c in raw_val) else int(raw_val, 10)
            
        # Match displacements like 64(sp) or 0x40(sp)
        for m_off in re.finditer(r"\b([0-9a-fA-F]+)\(sp\)", line):
            raw_val = m_off.group(1)
            val = int(raw_val, 16) if any(c in "abcdefABCDEF" for c in raw_val) else int(raw_val, 10)
            offsets.add(val)
            
    return frame_size, sorted(offsets)

def main():
    if len(sys.argv) < 3:
        print("Usage: python3 tools/stack_diff.py <func_name> <target.s> [current.o]")
        sys.exit(1)
        
    func_name = sys.argv[1]
    target_s = sys.argv[2]
    current_o = sys.argv[3] if len(sys.argv) > 3 else "build/src/overlays/ovl_i2/ovl_1B9440.o"
    
    tgt_frame, tgt_offs = parse_target_s(target_s, func_name)
    cur_frame, cur_offs = parse_current_o(current_o, func_name)
    
    print(f"=== Stack Layout Analysis for `{func_name}` ===")
    
    # Frame size comparison
    if tgt_frame is not None and cur_frame is not None:
        delta = cur_frame - tgt_frame
        delta_str = f"({delta:+d} bytes)" if delta != 0 else "(MATCH)"
        status = "MATCH" if delta == 0 else "MISMATCH"
        print(f"Frame Size: Target = 0x{tgt_frame:X} ({tgt_frame}b) | Current = 0x{cur_frame:X} ({cur_frame}b)  --> [{status} {delta_str}]")
    else:
        print(f"Frame Size: Target = {hex(tgt_frame) if tgt_frame else 'None'} | Current = {hex(cur_frame) if cur_frame else 'None'}")
        
    print("-" * 60)
    print(f"{'Offset':<10} | {'Target':<12} | {'Current':<12} | {'Status'}")
    print("-" * 60)
    
    all_offs = sorted(set(tgt_offs + cur_offs), reverse=True)
    
    for off in all_offs:
        in_tgt = off in tgt_offs
        in_cur = off in cur_offs
        hex_off = f"0x{off:X}"
        
        tgt_str = hex_off if in_tgt else "-"
        cur_str = hex_off if in_cur else "-"
        
        if in_tgt and in_cur:
            stat = "MATCH"
        elif in_tgt and not in_cur:
            stat = "MISSING in Current"
        else:
            stat = "EXTRA in Current"
            
        print(f"{hex_off:<10} | {tgt_str:<12} | {cur_str:<12} | {stat}")
        
    print("-" * 60)

if __name__ == "__main__":
    main()

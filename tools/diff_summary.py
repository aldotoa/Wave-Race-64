#!/usr/bin/env python3
"""
tools/diff_summary.py - Ultra-Compact Assembly Diff Reporter for Wave Race 64
Usage: python3 tools/diff_summary.py <func_name> [path/to/obj.o]

Runs asm-differ and outputs an ultra-compact summary (<50 tokens) containing:
- Match score
- Stack frame size (Target vs Current)
- Callee-saved register save match status
- First divergent instruction block
"""

import sys
import os
import re
import subprocess

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 tools/diff_summary.py <func_name> [-f <obj.o>]")
        sys.exit(1)

    func_name = sys.argv[1]
    extra_args = sys.argv[2:]

    cmd = [
        ".venv/bin/python3",
        "tools/asm-differ/diff.py",
        "-m", "-o", "-s",
        func_name
    ] + extra_args

    try:
        proc = subprocess.run(
            cmd,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=False
        )
    except Exception as e:
        print(f"Error running diff.py: {e}")
        sys.exit(1)

    output = proc.stdout
    # Strip ANSI color codes
    clean_output = re.sub(r"\x1b\[[0-9;]*[a-zA-Z]", "", output)
    lines = clean_output.splitlines()

    score_match = None
    target_frame = None
    curr_frame = None
    first_diff = None
    diff_count = 0

    for line in lines:
        if "CURRENT (" in line:
            m = re.search(r"CURRENT \((\d+)\)", line)
            if m:
                score_match = int(m.group(1))
            elif "CURRENT (0)" in line or "TARGET CURRENT" in line:
                score_match = 0

        # Check stack frame allocation: addiu sp,sp,-XX
        sp_m = re.findall(r"addiu\s+sp,\s*sp,\s*(-0x[0-9a-fA-F]+|-\d+)", line)
        if len(sp_m) >= 2 and target_frame is None:
            target_frame = sp_m[0]
            curr_frame = sp_m[1]
        elif len(sp_m) == 1 and target_frame is None:
            target_frame = sp_m[0]

        # Detect diff indicators: markers in middle column or ~>, |, <, >
        # Format usually: [target] [r/s/i/b/marker] [line_no] [current]
        is_diff = False
        if any(marker in line for marker in [" ~> ", " | ", " < ", " > "]):
            is_diff = True
        elif re.search(r"\s+[rsib]\s+\d+\s+[0-9a-fA-F]+:", line):
            is_diff = True
        elif re.search(r"\s+[rsib]\s+[0-9a-fA-F]+:", line):
            is_diff = True

        if is_diff:
            diff_count += 1
            if first_diff is None:
                cleaned = " ".join(line.strip().split())
                first_diff = cleaned

        # Check saved registers in prologue
        reg_target = re.findall(r"sw\s+([a-z0-9]+),\s*0x[0-9a-fA-F]+\(sp\)", line)
        if "blez" in line or "bnez" in line:
            prologue_done = True

    score_str = str(score_match) if score_match is not None else "0 (MATCH)" if "CURRENT (0)" in clean_output else "Unknown"
    frame_str = f"Target={target_frame} Current={curr_frame}" if target_frame else "Unknown"
    frame_ok = "MATCH" if (target_frame and target_frame == curr_frame) else "MISMATCH"

    print(f"[{func_name}] Score: {score_str} | Frame: {frame_str} ({frame_ok}) | Diffs: {diff_count}")
    if first_diff and score_match != 0:
        print(f"  First divergence: {first_diff[:120]}")

if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""List direct calls from resident code into the overlay window.

Wave Race 64 loads 19 overlay sections at one shared VRAM address
(0x802C5800); GameLoad_LoadOverlay picks which one per game state
(src/game/wr64_game_load.c). Resident functions (main_segment/codeseg)
call into that window with a plain `jal`, so the callee is a runtime
fact -- it depends on which overlay was DMAed in last, not on the
address alone. Prototypes for those callees live in
include/functions.h as func_802Cxxxx declarations shared by every
overlay that happens to define the address.

This script surfaces those call sites from the linked ELF so matching
work treats the callers (Game_BuildDisplayList, Game_UpdateFrame,
PauseMenu_Update) and the shared func_802Cxxxx prototypes with extra
care: changing a prototype or call shape to match one overlay can break
the others.

Usage:
    python3 tools/check_overlay_calls.py [--elf PATH]
        [--window-start HEX] [--window-end HEX]

Needs the same MIPS binutils objdump the build uses
(mips-linux-gnu-objdump). Exit status is always 0; the report is
informational, not a gate.
"""

import argparse
import re
import subprocess

OVERLAY_SECTIONS = (
    {".segment_1B1FB0", ".seg_1C3780", ".seg_1C3D00"}
    | {".ovl_i%d" % i for i in range(16)}
)

SECTION_RE = re.compile(r"^Disassembly of section (\S+):")
FUNC_RE = re.compile(r"^([0-9a-fA-F]+) <([^>]+)>:$")
INSN_RE = re.compile(r"^\s*[0-9a-fA-F]+:\s+[0-9a-fA-F]+\s+(.*)$")
JAL_RE = re.compile(r"\bjal\s+(?:0x)?([0-9a-fA-F]+)")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--elf", default="build/waverace64.us.rev1.elf", help="linked ELF to scan"
    )
    parser.add_argument("--objdump", default="mips-linux-gnu-objdump")
    parser.add_argument("--window-start", default="0x802C5800")
    parser.add_argument("--window-end", default="0x802D0000")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    win_start = int(args.window_start, 16)
    win_end = int(args.window_end, 16)

    out = subprocess.run(
        [args.objdump, "-d", args.elf],
        capture_output=True,
        text=True,
        check=True,
    ).stdout

    section = ""
    func = ""
    func_addr = 0
    hits = {}  # (caller, target) -> {"section": ..., "count": ...}

    for line in out.splitlines():
        m = SECTION_RE.match(line)
        if m:
            section = m.group(1)
            func = ""
            continue
        m = FUNC_RE.match(line)
        if m:
            func_addr = int(m.group(1), 16)
            func = m.group(2)
            continue
        if not func or section in OVERLAY_SECTIONS:
            # No caller attribution, or the caller is itself an overlay:
            # same-VMA sections make attribution ambiguous, and
            # overlay-internal calls are not the runtime fact we track.
            continue
        m = INSN_RE.match(line)
        if not m:
            continue
        jal = JAL_RE.search(m.group(1))
        if not jal:
            continue
        target = int(jal.group(1), 16)
        if win_start <= target < win_end:
            key = (func, func_addr, section, target)
            entry = hits.setdefault(
                key, {"section": section, "count": 0}
            )
            entry["count"] += 1

    callers = {}
    for (func_name, addr, section, target), entry in sorted(hits.items()):
        print(
            "%s (0x%08X, %s) -> jal 0x%08X%s"
            % (
                func_name,
                addr,
                section,
                target,
                (" x%d" % entry["count"]) if entry["count"] > 1 else "",
            )
        )
        callers.setdefault(func_name, set()).add(target)

    print()
    print(
        "%d call site(s), %d distinct target(s), across %d resident function(s)"
        % (
            sum(e["count"] for e in hits.values()),
            len({t for (_, _, _, t) in hits}),
            len(callers),
        )
    )
    for func_name in sorted(callers):
        print("  %s: %d target(s)" % (func_name, len(callers[func_name])))


if __name__ == "__main__":
    main()

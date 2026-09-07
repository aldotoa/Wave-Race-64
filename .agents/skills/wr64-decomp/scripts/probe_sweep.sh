#!/bin/bash
# probe_sweep.sh — build N IDO probe variants with the Makefile's exact flags
# and score each against a sliced base asm via asm-differ.
# Invoke through the `terminal` tool from the repo root:
#   .agents/skills/wr64-decomp/scripts/probe_sweep.sh --obj build/src/<tu>.o --func <name> \
#       --base scratch/base_<name>.slice scratch/probe_A.c scratch/probe_B.c
# Prints one `path: CURRENT (n)` score line per variant (lower is better).
# Prerequisites: IDO toolchain built (`make dependencies`), `.venv` with
# asm-differ, and a base slice made per the skill (assembled stub, `.set
# noreorder`, sliced to the single function).
set -u
OBJ=""; FUNC=""; BASE=""
while [ $# -gt 0 ]; do
  case "$1" in
    --obj) OBJ="$2"; shift 2;;
    --func) FUNC="$2"; shift 2;;
    --base) BASE="$2"; shift 2;;
    --) shift; break;;
    -*) echo "probe_sweep.sh: unknown flag $1" >&2; exit 2;;
    *) break;;
  esac
done
if [ -z "$OBJ" ] || [ -z "$FUNC" ] || [ -z "$BASE" ] || [ $# -eq 0 ]; then
  echo "usage: probe_sweep.sh --obj <build/...o> --func <name> --base <slice> <probe.c>..." >&2
  exit 2
fi
[ -f "$BASE" ] || { echo "probe_sweep.sh: base slice $BASE not found" >&2; exit 1; }
# Capture the exact IDO command for this TU straight from the build so probe
# flags can never drift from the Makefile (a single stray -D invalidates
# every score). Refuse to run if the decomp flag is missing.
CMD=$(make -n -B "$OBJ" NON_MATCHING=1 2>/dev/null | grep -m1 'ido-static-recomp/build')
[ -n "$CMD" ] || { echo "probe_sweep.sh: could not capture IDO command for $OBJ" >&2; exit 1; }
echo "$CMD" | grep -q 'DNON_MATCHING' || { echo "probe_sweep.sh: captured command lacks -DNON_MATCHING; refusing" >&2; exit 1; }
for SRC in "$@"; do
  OUT="${SRC%.c}.o"
  sleep 1; touch "$SRC"
  RUN=$(echo "$CMD" | sed "s|-o $OBJ [^ ]*|-o $OUT $SRC|")
  if ! eval "$RUN" >/dev/null 2>&1; then echo "$SRC: BUILD-FAILED"; continue; fi
  mips-linux-gnu-objcopy --remove-section .mdebug "$OUT" 2>/dev/null || true
  [ "$OUT" -nt "$SRC" ] || { echo "$SRC: STALE-OBJECT (not rebuilt)"; continue; }
  mips-linux-gnu-objdump -dr "$OUT" | grep -q "<$FUNC>:" || { echo "$SRC: symbol $FUNC missing"; continue; }
  mkdir -p "expected/$(dirname "$OUT")"
  cp "$OUT" "expected/$OUT"
  SCORE=$(.venv/bin/python3 tools/asm-differ/diff.py -o -f "$OUT" --base-asm "$BASE" --format plain --no-pager "$FUNC" 2>/dev/null | head -1 | grep -o 'CURRENT ([0-9]*)')
  echo "$SRC: ${SCORE:-DIFF-FAILED}"
done

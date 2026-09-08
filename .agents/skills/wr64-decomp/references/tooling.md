# Token-efficient diffing and testing

- Compress diffs: always `-U 2` (`--compress-matching 2`) to collapse
  identical runs.
- Terse tests: `make test 2>&1 | tail -n 5` — never raw `make test` (700+
  lines).
- Score check without disassembly:
  `diff.py -m -o -s <func> 2>/dev/null | head -n 3`.
- Micro-permutation search (score < 50): do NOT hand-edit per turn (~3,800
  tokens + roundtrip each). Write `scratch/test_perm.py` driving
  `tools/ido-static-recomp/build/5.3/out/cc` directly — 100+ permutations in
  <5s for <1,000 tokens (~70x).
- `python3 tools/stack_diff.py <func> <target.s> [current.o]` — frame sizes,
  shifted offsets, missing slots, padding gaps in <50 tokens. Prefer over
  manual objdump arithmetic.
- `python3 tools/diff_summary.py <func> <current.o>` — score, frame match,
  saved-reg mapping, first divergence in <50 tokens. Prefer over full diffs.
- `python3 tools/regalloc_search.py` — declaration permutations against
  direct IDO for frame size / `$s0`-`$s8` mismatches. Prefer over manual
  trial-and-error.
- Never multiline `python3 -c '...'` in zsh — expansions break quoting.
  Save helpers to `tools/` or `scratch/`.
- Scope mechanical edits: bare `str.replace` rewrites every occurrence —
  a short pattern corrupts unrelated drafts sharing the TU. Anchor with
  unique context (or `count=1`), then `git diff --stat` + grep the new text
  appears only in the target function.

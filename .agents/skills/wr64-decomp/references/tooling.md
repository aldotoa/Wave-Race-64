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
- Formatter pin: `tools/format.py` prefers `clang-format-20` (CI apt version)
  and silently falls back to any `clang-format`. Local default (Homebrew,
  v23+) drifts from CI: `python3 -m pip install --user 'clang-format==20.1.8'`
  + `ln -sf ~/Library/Python/3.13/bin/clang-format ~/.local/bin/clang-format-20`.
  Verify single-file with `clang-format-20 --output-replacements-xml <file> |
  grep -c '<replacement '` (expect 0) — never run tree-wide `check_format.sh`
  casually, it rewrites every drifted file as a side effect (revert with
  `git checkout -- <unrelated files>`).
- Scope mechanical edits: bare `str.replace` rewrites every occurrence —
  a short pattern corrupts unrelated drafts sharing the TU. Anchor with
  unique context (or `count=1`), then `git diff --stat` + grep the new text
  appears only in the target function.

## Overlay + splat triage

- 19 sections share VRAM `0x802C5800` (`grep -c 'exclusive_ram_id:
  overlay' waverace64.us.rev1.yaml` → 19: 16x `ovl_i0-15` +
  `segment_1B1FB0` + `seg_1C3780` + `seg_1C3D00`, pinned with
  `exclusive_ram_id: overlay` + `symbol_name_format: iN_$VRAM`).
- Splat facts (`waverace64.us.rev1.yaml:10,34,40`): `compiler: IDO`,
  `migrate_rodata_to_functions: True` (each function gets a private rodata
  copy — grounds the NEEDS_RODATA wrapper rule in `ido-codegen.md`),
  `mips_abi_float_regs: o32` (float args after int/ptr args ride `$a2`/`$a3`
  via `lw`, not `lwc1`).
- Before triaging a `func_802Cxxxx` target: `python3
  tools/check_overlay_calls.py` lists resident→overlay-window `jal` sites
  from the built ELF (window `0x802C5800-0x802D0000`). Shared prototypes in
  `include/functions.h` serve every overlay defining that address — check
  all callers before changing one (reason: `docs/recomp-crossref.md`).
- Live `NEEDS_RODATA` wrappers: `src/audio/audio_load.c` (PRINTF strings)
  + 4 sites in `src/game/code_52CD0.c`. Check these first when a
  switch/float-pool function scores ~105 with a phantom `> .rodata+0x0`
  row.

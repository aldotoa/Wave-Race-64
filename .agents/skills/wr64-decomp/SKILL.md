---
name: wr64-decomp
description: Decompiles Wave Race 64 (N64) functions to byte-matching IDO 5.3 C. Use when building the ROM, running tests, diffing assembly, matching or promoting a function, or debugging codegen in this repo.
---

# Wave Race 64 Decompilation Runbook

Project rules in repo-root `AGENTS.md` are always loaded (ROM hash gate,
IDO flags, scaffolding, probe mechanics, promotion checklist). This skill
adds the workflow and repo tooling on top — no duplication.

Gates, in order: asm-differ `CURRENT (0)` on compiled C → `make` ROM
`waverace64.us.rev1.z64: OK` → `make test` green → `make progress`.

## Quick Reference

| Command | Purpose |
|---|---|
| `make` | Builds ROM, verifies SHA-1 retail match |
| `make test 2>&1 \| tail -n 5` | 416-test suite, terse output |
| `make progress` | Function/byte counts and percentage |
| `./diff <func>` | Interactive assembly differ vs retail |
| `tools/m2ctx src/<path>/<file>.c` | Preprocessed context (`ctx.c`) for m2c |
| `python3 tools/m2c/m2c.py -t mips-ido-c --context ctx.c <func.s>` | Initial IDO C89 candidate (`-t` value: check `--help`) |
| `python3 tools/stack_diff.py <func> <target.s> [current.o]` | Stack/frame differ, <50ms |
| `python3 tools/diff_summary.py <func> <current.o>` | Score + frame + first divergence, <50 tokens |
| `.venv/bin/python3 tools/asm-differ/diff.py -m -o -s -U 2 <func>` | Canonical diff (drop `-s` for multi-`jr` functions) |
| `python3 tools/promote.py <func> <source.c>` | Automated promotion (commit first — always) |

## Workflow

1. **Select.** Small leaf stubs first:
   `find asm/us/rev1/nonmatchings -name "*.s" -exec wc -l {} + | awk '$1 <= 60' | sort -n`.
   Skip `D_*` data stubs, jump-table switches, parked floors.
2. **Translate.** `tools/m2ctx`, then m2c. Apply the 5 mechanical fixes
   (pointer scales, void calls, `extern ?`, dropped lines, verbatim protos):
   `references/matching-workflow.md`.
3. **Diff.** Canonical flags above. `GLOBAL_ASM` self-match trap, base
   slicing, `expected/` mirroring: `references/matching-workflow.md`
   (mechanics also in `AGENTS.md`).
4. **Prototype.** Direct IDO invocation or batched sweeps via
   `scripts/probe_sweep.sh` (exact Makefile flags, `touch` + mtime-checks):
   `references/matching-workflow.md`.
5. **Promote.** Commit or stash first — `promote.py` reverts the file to
   HEAD on failure, including `--dry-run`. Then manual sequence
   (unwrap, `rm` stub, `touch` + `make`, tests, progress):
   `references/matching-workflow.md`.
6. **Hygiene.** `sleep 2` + `touch`, confirm the `Compiling:` line; `rm`
   stale `NON_MATCHING=1` objects before matching builds.
7. **Switches.** Case order must match jump-table layout; blob tables stay
   behind `NEEDS_RODATA || NON_MATCHING` — never force-promote:
   `references/ido-codegen.md`.

## IDO codegen

Float discipline, Chow-Hennessy regalloc, loop selection, frame layout,
delay-slot stores, branch-likely: `references/ido-codegen.md`. Token-cheap
tooling (perm search, `stack_diff`, `diff_summary`, `regalloc_search`):
`references/tooling.md`.

## Engine patterns

Scene exits (`ovl_i8/i9/i10/i13`) share one shape:
`gPrevGameState = gGameState; D_801CE630 = arg0; gGameState = <target>;`
`D_801CE638 = <sub>; D_801CE63C = 1; D_801CE640 = D_801CE644 = 0;`
`D_800DAB1C = 0; D_800D461C = 2 (or 3); FadeTransition_SetProps(1, 4, 0);`
Course overlays route display lists through `glistp = func_ovl_render(Draw_Water);`

## References

- `references/matching-workflow.md` — translate → diff → prototype → promote → hygiene
- `references/ido-codegen.md` — float, regalloc, loops, frame, branches, rodata
- `references/tooling.md` — token-efficient diffing/testing protocols
- `scripts/probe_sweep.sh` — multi-variant build+diff driver

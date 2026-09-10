# Matching workflow (translate → diff → prototype → promote)

## Context + m2c

```bash
tools/m2ctx src/<path>/<file>.c
python3 tools/m2c/m2c.py -t mips-ido-c --context ctx.c \
  asm/us/rev1/nonmatchings/<path>/<func>.s > scratch/<func>.c
```

m2c integration fixes (mechanical — verify each against the stub):

- Pointer scales: m2c emits `gptr + 8` (elements) where the stub does
  `addiu ..., 8` (bytes). On `Gfx*` (8 bytes) write `+ 1`; `+0x50` bytes is
  `+ 10` elements (or `+ 1` on a 0x50-sized struct). Audit every m2c
  `+ <bytes>` on typed pointers.
- Void calls: m2c invents an argument from a stale arg register (`f(&x)`);
  if the callee takes none, call with `()`.
- Unknown `extern ?` symbols: resolve via headers first; address-only use is
  codegen-safe as `extern Gfx name[]`.
- Never drop m2c lines while integrating — each omission returns as missing
  stores in the first diff.
- Forward declarations: draft calling a same-file function defined later
  needs a prototype copied verbatim from the definition signature (implicit
  decl conflicts with the later definition). Never modernize `()` vs
  `(void)`.
- Target is always `mips-ido-c` (the default; `--help` lists other
  platform/compiler pairs but this repo never uses them).
- `m2ctx` always writes repo-root `ctx.c` (+ `ctx.c.m2c` cache, auto-
  regenerated per `--help`) with pinned defines (`-DVERSION_US -DTARGET_N64
  -D_LANGUAGE_C -DF3D_OLD -D_MIPS_SZLONG=32` — see `CPP_FLAGS` in
  `tools/m2ctx`).
- Multi-function stub files: add `-f <func>` to decompile one function.
- Wrong stack var types/names: re-run with `--stack-structs`, edit the
  template, feed back via `--context`. Loop shapes are weak upstream
  (m2c README: "suboptimal code (especially for loops)") — prefer sibling
  loop spellings in `ido-codegen.md` over m2c's output.

## Diffing

Canonical diff (compress runs, recompile, object-direct, stop-at-ret):

```bash
.venv/bin/python3 tools/asm-differ/diff.py -m -o -s -U 2 <func>
```

- Drop `-s` for functions with multiple `jr $ra` — stop-at-ret truncates at
  the first return and reports vacuous scores. Confirm output reaches the
  final `jr`.
- `GLOBAL_ASM` self-match trap: for drafts under `#ifdef NON_MATCHING`,
  `-m` rebuilds select the stub and report false `CURRENT (0)`. Either
  `make NON_MATCHING=1 build/src/<path>/<file>.o` then diff WITHOUT `-m`,
  or `python3 tools/promote.py --dry-run <func> <file.c>`, or compile a
  standalone probe (`scratch/probe_<func>.c` = includes + draft body) with
  the Makefile's exact flags and diff with `-f <probe.o> --base-asm
  <slice>`. Full probe mechanics in `AGENTS.md`.
- `--base-asm` must be sliced to the single function:
  `awk '/^0.*<func>:/{f=1} f{print} f&&/^$/{c++; if(c==1) exit}'`.
  A whole-object dump anchors TARGET on the wrong function. Rebuild the base
  from a matching tree — never trust `build/` objects when src holds drafts.
- `-f` resolves under `expected/`: `cp scratch/probe_<func>.o
  expected/scratch/probe_<func>.o`.
- Delete `scratch/probe_*`, `scratch/base_*`, and probe copies under
  `expected/` before committing.

## Fast prototyping

Get exact flags, then invoke IDO 5.3 directly (<50ms feedback):

```bash
make -n build/src/<path>/<file>.o
tools/ido-static-recomp/build/5.3/out/cc -c -G 0 -non_shared -Xcpluscomm \
    -I include -I . -I include/libc -I include/PR -I bin \
    -nostdinc -Wab,-r4300_mul -woff 649,838,712,516 -DVERSION_US=1 \
    -mips2 -32 -EB -D_MIPS_SZLONG=32 -DNDEBUG -DF3D_OLD -D_FINALROM \
    -DTARGET_N64 -DLANGUAGE_C -D_LANGUAGE_C -O2 \
    -o scratch/test.o scratch/test.c
mips-linux-gnu-objdump -dr scratch/test.o
```

3+ structural variants → sweep instead of hand-rolling loops:

```bash
.agents/skills/wr64-decomp/scripts/probe_sweep.sh --obj build/src/<tu>.o \
  --func <name> --base scratch/base_<name>.slice scratch/probe_A.c scratch/probe_B.c
```

It captures the IDO command via `make -n -B <obj> NON_MATCHING=1` (refuses
without `-DNON_MATCHING`), `touch`es + mtime-checks each variant, mirrors
objects under `expected/`, prints one `CURRENT (n)` line each.

## Promotion

Commit or stash first — even for `--dry-run`. `tools/promote.py` reverts
the source file to HEAD whenever the post-promotion matching build fails,
wiping ALL uncommitted drafts in that file. Proven 2026-09-06: a
`--dry-run` on `func_8009934C` reverted `src/game/code_52CD0.c`, deleting
the in-progress `func_800998B0`/`func_800AC098` bodies.

```bash
python3 tools/promote.py <func> <path/to/source.c>
```

Manual sequence: remove `#ifdef NON_MATCHING` + `#pragma GLOBAL_ASM`
wrappers → `rm asm/us/rev1/nonmatchings/.../<func>.s` → `touch
src/<path>/<file>.c && make` (ROM OK) → `make test && make progress`.

Zero-pragma audit for a finished file:

```bash
gcc -E -DNON_MATCHING -Iinclude -Iinclude/libc <path/to/file.c> | grep -c "#pragma GLOBAL_ASM"
# Expected: 0
```

Before renaming a matched global, grep `asm/` too: nonmatching stubs call
it via `jal func_<addr>` and the link breaks once renamed — retarget the
stub's `jal` (encoded address unchanged, ROM still matches).

## Hygiene

- `touch` + immediate `make` in the same second can skip recompilation
  (coarse mtime): always `sleep 2` before `touch`, confirm the `Compiling:`
  line before trusting a score.
- A stale `NON_MATCHING=1` object in `build/` is treated as up-to-date by
  plain `make`: link failure normally, or a SHA-1 change failing all 400+
  ROM-dependent tests. Fix is `touch src/<file>.c && make`, not
  investigation. Never `make clean` + `make extract` for staleness — it
  wipes splat artifacts and regresses hand-assigned stub names.

## Switch case order

IDO emits case bodies in source order. If the diff shows a whole case body
misaligned, check jump-table label addresses in the target `.s`: a later
case number sitting EARLIER in the binary (e.g. case 5 at `0x6150` before
case 2 at `0x6174`) means moving that `case N:` block earlier in source,
keeping its number. One reorder fixed ~1600 points in `ovl_1B9440`.

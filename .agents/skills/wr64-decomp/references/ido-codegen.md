# IDO 5.3 codegen (Wave Race 64 measurements)

## Float

- Literal discipline: always `1.0f`, never `0.5` — untyped literals become
  `f64`, pulled from `.rodata` with `cvt.d.s` / `mul.d` / `add.d` on `$f0`/`$f1`
  pairs instead of `mul.s` / `add.s`.
- Float args after integer/pointer args (MIPS O32) ride integer regs
  (`$a2`, `$a3`), loaded with `lw` not `lwc1` — needs full explicit prototypes.
- Callee-saved `$f20`/`$f22`: locals live across calls land here. Under
  `-mips2 -32` IDO saves them with `s.d`/`l.d` only on 8-byte-aligned slots —
  target `s.d` vs your split `swc1` pair means 4-byte misalignment. Reorder
  scalars to realign the float save block.

## Chow-Hennessy regalloc

`uopt` assigns `$s0`, `$s1`, … by priority = savings / live-range length.
Reusing a variable after a call dilutes its priority and lets a tighter loop
variable steal `$s0`. Remedies: scope-isolate declarations in `{ ... }`;
prefer `&arr[index]` over pointer arithmetic (boosts `index` over `offset`);
cache `state = *s2;` across branch fan-out; extend a competitor's live range
to equalize; saved-source + cursor (`Type *s0 = arg0;` up front, call
`f(s0)`) when the stub passes the saved reg via delay-slot `move a0,s0`.
In leaf functions, `register` or declaration order can guide selection.

## Loops

- Selection diagnostic: leading `b` down to bottom `blt`/`bne` → `for`;
  immediate top test → `while`; body-first with bottom branch only →
  `do-while` (also in `AGENTS.md`: tail branches favor `do-while`).
  EXCEPTION (proven on `func_i5_802C7594`): multi-cursor address-walk
  loops with extern bounds unroll+frame under `do-while` (subu/andi/beqz
  prelude, s-reg spills) while the stub keeps a plain walk. `goto loop`
  and `while (1)` + `break` both inhibit the unroll and converge to
  identical rows — micro-bisect loop skeletons (do/while-break/goto)
  before sweeping coloring, and distrust a `do-while`-only floor.
- Small counted loops: `uopt` hoists bounds (`li $a2, 2` + `bne`) where the
  target uses `slti` + `bnez` (`blt`). Reusing the counter in a following
  loop keeps it live and suppresses hoisting.
- Statement order controls negative-offset delay-slot stores: storing the
  induction variable last emits the dependent store first, bumps pointers,
  and schedules the final zero store as `bnez $at, .Lloop; sw $zero,
  -4($a0)`.
- `.loc` quirk: unrolled stores on separate lines get distinct `.loc`
  directives, which `as1` treats as scheduling boundaries (out-of-order
  offsets). One `for (i = 0; i < 4; i++) D[i] = 0;` on a single line binds
  one `.loc` and emits sequential offsets.

## Frame layout

- High-to-low: first-declared locals sit highest (below caller args), later
  ones near `$sp`. Scalars declared LAST absorb bottom padding above saved
  regs — e.g. loop index `i` at `0x88` under five nested matrices prevents a
  +8 shift across all buffers.
- `cfe` reserves slots for ALL outer-scope scalars, even eliminated ones:
  crossing an 8-byte boundary inflates the frame (`0x58`→`0x60`) and shifts
  offsets. Kill intermediate holders or isolate them in inner blocks.
- 4-tier zones: outer locals (top) → large structs/padding → `uopt` spill
  slots (from ~`$sp+0x48`) → outgoing-arg space + saved regs (base).
- When only frame size + spill offsets differ (no opcode/reg mismatches),
  permute declaration order (~6 tries), then park — the rest is
  allocator-opaque.

## Branches and delay slots

- Early return vs single epilogue: multiple `jr $ra` → early returns; one
  shared epilogue → single exit with `goto end;` (two C `return`s flip the
  tail to `move;jr;nop` + likely-fills).
- Non-likely delay-slot store (`bne`/`beqz` + `sw`) runs on BOTH paths —
  model as straight-line code before the `if`. Doubled store
  (`D = 1; if (f == 1) { D = 1; }`) merges into a normal-`bne` delay slot;
  the single store emits `bnel`. Empty `else {}` arms can be load-bearing.
- `D++` keeps the value in a t-reg; a named `s32 temp = D + 1` parks it in a
  v-reg. Equivalent tail spellings (`goto end` vs nested `if`) emit identical
  bytes at function end — try the other to shift upstream scheduling.
- Dense 0..N switch needs `case 0: break;` first; addend order
  (`D[0] + (D[1]*2)` vs swapped) rotates temp coloring — try both. Flat C
  can emit `beqz`+fill where nested emits `beqzl`+hoist: micro-bisect shapes
  (switch vs if-chain vs goto, flat vs nested) before editing the draft.
- Park at the floor when only scheduler-opaque rows remain (documented
  score + load-bearing constructs in a comment, draft stays behind
  `#ifdef NON_MATCHING`).
- IDO re-materializes `%hi` per store even same-page (proven on
  `func_i1_802C9380`: five stores, five `lui`). One shared `lui` across two
  symbols implies one source address computation — if rewrites keep two
  `lui`s, park it.
- Keep m2c's per-case locals SPLIT under dispatch: merging extends live
  ranges across the jump and explodes spills (1544 → ~77k on
  `AudioGeneral_PlaySound`). Never "clean" m2c's goto skeleton: moving a
  join label out of its `if` cost +1900 on `func_800C010C`.
- Comments must be ASCII-only: asm-processor encodes euc-jp, so an em-dash
  fails the TU build, and a stray `*/` turns the rest into code.

## Rodata and jump tables

Functions whose tables live in unmigrated `.rodata.s` stay under
`#if defined(NEEDS_RODATA) || defined(NON_MATCHING)` until the whole block's
functions match. Fingerprint: text-identical switch scoring ~105 from one
phantom `> .rodata+0x0` row — re-run with `-R`; near-0 means the C is
correct. Never `--force` promote: repointed entries link but reference the
private table copy (proven: `func_800ADC8C` text-identical yet
unpromotable). Blob carving fails too (+12 bytes: 4 gas tail-padding + 8
start-alignment; IDO rodata is align-16, the slot 4-aligned) — promotion
needs whole-file rodata reconstruction.

## Pointer materialization

IDO `-O2` folds constant offsets (`(base+0x5C)+0x18` → `0x74(base)`). To
force a materialized base (`addiu $v0, $a0, 0x5c` + relative stores),
init a sub-struct pointer at declaration and use it across branch blocks.
Same-`%hi` sharing across consecutive stores wants array/struct symbols,
not separate globals. Unrolled vector stores (`swc1 $f4, -4($t0)`) want a
local sub-struct cast, not flat float indexing.

## Build flags (verified: Makefile + yaml)

- IDO driver is `tools/ido-static-recomp/build/5.3/out/cc`
  (Makefile:222); phases on disk under `tools/ido-static-recomp/ido/5.3/usr/lib/`: `cfe`
  (front end — owns the frame-slot reservation above), `uopt` (Chow-Hennessy
  + copy propagation + redundant-store removal — pass names visible in root
  `uoptlist`), `as1` (assembler — treats `.loc` as a scheduling boundary,
  cf. Loops above).
- Matching flags are `-G 0 -non_shared -Xcpluscomm -nostdinc
  -Wab,-r4300_mul` with `-mips2 -32 -EB` (Makefile:105-106), NOT `-mips3`:
  despite R4300i being MIPS III, the matching build targets MIPS II 32-bit
  big-endian. `-mips3` at Makefile:102 is the experimental GCC path only.
- Per-file `-O` overrides (Makefile:344-354): `src/libultra/os|io|libc`
  build at `-O1`, `src/libultra/gu|audio` at `-O3` (plus two `-O2` pins).
  Never assume `-O2` for libultra targets — read the stanza first.
- `asm-processor` flags (Makefile:228,241): `--input-enc=utf-8
  --output-enc=euc-jp --convert-statics=global-with-filename`. This grounds
  the ASCII-only comment rule (euc-jp output path) and means file-statics
  are renamed with the filename — objdump names won't match source statics
  verbatim.

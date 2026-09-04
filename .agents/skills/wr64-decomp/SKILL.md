---
name: wr64-decomp
description: >-
  Workflows, build commands, testing procedures, and debugging tools for the
  Wave Race 64 (N64) decompilation project. Use whenever building, testing,
  matching functions, or auditing source files in this repository.
---

# Wave Race 64 Decompilation Workflow Runbook

## Core Commands Quick Reference

| Command | Purpose |
| :--- | :--- |
| `make` | Builds the ROM and verifies byte-for-byte SHA-1 match |
| `make test` | Runs the 416-test Test-Driven Engineering (TDE) verification suite |
| `make clean` | Cleans all build artifacts in `build/` |
| `make progress` | Displays current function count, byte count, and percentage progress |
| `./diff <func_name>` | Interactive assembly differ comparing compiled C against retail ROM |
| `tools/m2ctx <file.c>` | Generates preprocessed C context for decomp.me |

## Verification Procedures

### 1. TDE Test Suite
Always verify that all tests pass:
```bash
make test
```

### 2. Checksum Verification
Ensure the generated ROM matches the target retail hash:
```bash
sha1sum build/waverace64.us.rev1.z64
# Expected: 508dfc2d4caa42b6f6de5263d0aed5e44ac7966a
```

### 3. Non-Matching Pragma Audit
To verify that a source file has 0 assembly pragmas remaining under `NON_MATCHING`:
```bash
gcc -E -DNON_MATCHING -Iinclude -Iinclude/libc <path/to/file.c> | grep -c "#pragma GLOBAL_ASM"
# Expected: 0
```

## Decompilation Matching Workflow

1. **Select Candidate Functions**:
   Query nonmatching assembly stubs by line count to prioritize small leaf functions and overlay stubs:
   ```bash
   find asm/us/rev1/nonmatchings -name "*.s" -exec wc -l {} + | awk '$1 <= 60 {print $1, $2}' | sort -n
   ```
2. **Interactive Differ (CRITICAL FLAGS: `-m -o -s`)**:
   Always include `-m` (recompile `.o`), `-o` (diff object file directly to prevent self-matching false positives), and `-s` (stop at return):
   ```bash
   .venv/bin/python3 tools/asm-differ/diff.py -m -o -s <func_name>
   ```
3. **Scratchpad Fast Prototyping (Direct IDO Invocation)**:
   When iterating on register allocation or compiler quirks, write minimal isolated functions to a scratch file (e.g. `scratch/test.c`) and compile directly using the recompiled IDO 5.3 compiler with exact project flags for sub-50ms feedback:
   ```bash
   tools/ido-static-recomp/build/5.3/out/cc -c -G 0 -non_shared -Xcpluscomm \
       -I include -I . -I include/libc -I include/PR -I bin -I src/libultra \
       -nostdinc -Wab,-r4300_mul -woff 649,838,712,516 -DVERSION_US=1 \
       -mips2 -32 -EB -D_MIPS_SZLONG=32 -DNDEBUG -DF3D_OLD -D_FINALROM \
       -DCOMPILING_LIBULTRA -DTARGET_N64 -DSSSV -DWIN32 -DLANGUAGE_C -D_LANGUAGE_C -O2 \
       -o scratch/test.o scratch/test.c
   mips-linux-gnu-objdump -dr scratch/test.o
   ```
4. **Promotion on 100% Match (`CURRENT (0)`)**:
   Once 0 diffs are verified:
   - Remove `#ifdef NON_MATCHING` / `#pragma GLOBAL_ASM` wrapper in the `.c` file.
   - Delete `asm/us/rev1/nonmatchings/.../<func_name>.s` from disk.
   - Verify: `make && make test && make progress`.
5. **`NON_MATCHING=1` Object File Hygiene**:
   Compiling a target with `make NON_MATCHING=1 build/src/<file>.o` leaves an unmatching object file in `build/`. A subsequent standard `make` may treat this `.o` as up-to-date and fail at the link stage with unresolved symbols. Always invalidate the object cache before running matching verification:
   ```bash
   touch src/<file>.c && make
   ```

## IDO 5.3 C89 Optimization & Register Matching Techniques

- **Base Pointer Materialization (Suppressing Constant Offset Folding)**:
  IDO at `-O2` eagerly folds constant offsets (e.g., `(base + 0x5C) + 0x18` folds into `0x74(base)`).
  To force IDO to materialize the base pointer into a register (`addiu v0, a0, 0x5c`) and emit relative stores (`0x18(v0)`, `0x24(v0)`, `0x30(v0)`):
  - Initialize the sub-struct pointer at declaration (`Struct_B* b = (Struct_B*)(dst + 0x5C);`).
  - Access `b` across multiple branch blocks (`if (src1 != NULL)` and `if (src2 != NULL)`). IDO treats `b` as live across blocks and reuses the computed pointer in `$v0`.
- **Multi-Symbol `%hi` Address Sharing**:
  When consecutive stores share a single `lui at, %hi(...)` (e.g., storing to 4 consecutive `s16` addresses), declare the symbols as an array (`s16 D_802C8C70[4]`) or struct rather than separate scalar globals. Independent globals force IDO to reload `%hi` for each store.
- **Sub-struct Strength Reduction**:
  When targeting unrolled vector stores like `swc1 $f4, -4($t0)` or `swc1 $f16, 0x20($a1)`, cast the base pointer to a local sub-struct pointer (`(SubStruct*)(dst + offset)`) rather than indexing a flat float array. This produces IDO's canonical pointer-offset register choices (`$t0`, `$a1`).
- **Branch-Likely (`beql` / `bnel`) & Delay Slot Idioms**:
  - `while ((val = arr[s0]) == 0) { arr[idx = ++s0]; }` generates `beql` with delay-slot index increments.
  - A void function call pattern `if (cond) { func(arg); } return arg;` generates `bnel` with `jal` delay-slot stack spilling (`sw v0, 0x18($sp)`) and restoration (`lw a0, 0x18($sp)`).
- **MIPS O32 Calling Convention for Floats**:
  Under MIPS O32, floating-point arguments that follow integer or pointer arguments occupy integer registers (`$a2`, `$a3`) and are loaded using `lw` rather than `lwc1`. Ensure full explicit prototypes are provided so IDO adheres to this convention.
- **Register Allocation Control & Chow-Hennessy Priority Coloring (`$s0` vs `$s1`)**:
  IDO 5.3's global optimizer (`uopt`) sorts register allocation candidates using Chow-Hennessy Priority Coloring:
  $$\text{Priority} = \frac{\text{Savings}}{\text{Live Range Length}}$$
  Callee-saved registers (`$s0`, `$s1`, `$s2`...) are assigned strictly descending by priority rank among live ranges that span function calls.
  - **Live-Range Dilution Across Calls**:
    If a local variable or pointer is used in a tight loop and subsequently re-assigned or reused after a function call (especially one with many stack arguments), `uopt` combines both uses into a single long live range. The increased denominator ($\text{Length}$) sharply degrades its priority score. Consequently, another variable with tight loop references (such as an index `i`) receives `$s0`, leaving `$s1` to the pointer.
  - **Remediation Techniques**:
    - *Scope Isolation*: Restrict variable declarations to inner blocks (`{ ... }`) to prevent `uopt` from coalescing disjoint webs across calls.
    - *Pointer Arithmetic vs. Array Indexing*: Using explicit pointer increments (`ptr++`) creates distinct induction webs compared to array indexing (`arr[i]`), which triggers strength reduction and induction variable creation.
    - *Priority Equalization*: Reusing or extending the live range of the competing variable after the loop can drop its priority and restore the desired register ordering.
    - In simpler functions where IDO swaps registers between incoming parameters and local variables, the `register` keyword (e.g. `register s32 s0 = arg1->unk4;`) or initialization order can also prioritize `$s0`.
- **Unmigrated Rodata Guard**:
  Functions containing jump tables (`switch`) whose tables reside in unmigrated `.rodata.s` (e.g. `A5CC0.rodata.s`) must be kept under `#if defined(NEEDS_RODATA) || defined(NON_MATCHING)` until the file's rodata is fully migrated into C to prevent linker collisions.

## Common Engine Architecture Patterns

- **Scene Exit & Transition Functions**:
  Across game and overlay segments (`ovl_i8`, `ovl_i9`, `ovl_i10`, `ovl_i13`), scene transitions share identical structure:
  ```c
  gPrevGameState = gGameState;
  D_801CE630 = arg0;
  gGameState = <target_state>;
  D_801CE638 = <target_substate>;
  D_801CE63C = 1;
  D_801CE640 = 0;
  D_801CE644 = 0;
  D_800DAB1C = 0;
  D_800D461C = 2; // or 3
  FadeTransition_SetProps(1, 4, 0);
  ```
- **Overlay Display List Rendering Pipeline**:
  Course overlays typically run display lists through standard graphics stages:
  ```c
  glistp = func_ovl_render(Draw_WaterEffects(func_800949B8(func_8008FB74(glistp), gCourseID)));
  ```


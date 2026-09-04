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
   - Or use the automated promotion script: `python3 tools/promote.py <func_name> <path/to/source.c>`
5. **`NON_MATCHING=1` Object File Hygiene**:
   Compiling a target with `make NON_MATCHING=1 build/src/<file>.o` leaves an unmatching object file in `build/`. A subsequent standard `make` may treat this `.o` as up-to-date and fail at the link stage with unresolved symbols. Always invalidate the object cache before running matching verification:
   ```bash
   touch src/<file>.c && make
   ```

### Token-Efficient Diffing & Testing Protocols

To prevent context saturation and token waste when iterating on functions:

1. **Compressed Assembly Diffs (`-U 2`)**:
   Always pass `-U 2` (`--compress-matching 2`) to collapse runs of identical instructions, displaying only the diff regions with 2 lines of context:
   ```bash
   .venv/bin/python3 tools/asm-differ/diff.py -m -o -s -U 2 <func_name>
   ```
2. **Terse Test Output**:
   Avoid running verbose `make test` which prints 700+ lines into context. Pipe through `tail`:
   ```bash
   make test 2>&1 | tail -n 5
   ```
3. **Quick Match Score Check**:
   Inspect whether a function matches without printing full disassembly:
   ```bash
   .venv/bin/python3 tools/asm-differ/diff.py -m -o -s <func_name> 2>/dev/null | head -n 3
   ```
   A matching function shows `TARGET ... CURRENT (0)` with no diff lines below.
   **WARNING**: For functions still under `#ifdef NON_MATCHING`, the standard `diff.py -m -o -s` will show `CURRENT (0)` because asm-processor substitutes the raw assembly from the `#pragma GLOBAL_ASM` path. This is a false positive — it's comparing the assembly against itself. To test the **C code**, either:
   - Use `make NON_MATCHING=1 build/src/<file>.o && diff.py -o -s <func>` (builds with C code), or
   - Use `tools/promote.py --dry-run <func> <file.c>` which temporarily removes the wrapper, rebuilds, diffs, and auto-reverts.
4. **Batch Promotion with `tools/promote.py`**:
   Automate the entire promotion sequence (wrapper removal → 0-diff verification → `.s` deletion → build → test → progress) in a single command:
   ```bash
   python3 tools/promote.py <func_name> <path/to/source.c>
   python3 tools/promote.py --dry-run <func_name> <path/to/source.c>  # check only, auto-revert
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
- **Loop Induction Variable Elimination Suppression (`blt` vs `li $reg, limit; bne`)**:
  - *Problem*: In small counted loops like `for (i = 0; i < 2; i++)`, IDO's global optimizer (`uopt`) frequently converts the inequality into `!= limit`, hoists the bound into a dedicated register before the loop (`li $a2, 2`), and branches with `bne $v0, $a2, .Lloop`. In target functions without a hoisted limit register, the assembly instead uses `slti $at, $v0, limit; bnez $at, .Lloop` (the pseudo-instruction `blt $v0, limit, .Lloop`).
  - *Heuristic*: If the induction variable `i` is dead after the loop, `uopt` eliminates it and hoists the bound. Reusing the same counter variable `i` across subsequent logic (e.g. an immediately following loop `for (i = 0; i < 4; i++)`) marks `i` as live across loop boundaries, suppressing bound hoisting and forcing `uopt` to emit the canonical `blt` (`slti` / `bnez`).
- **Single-Line Statement Binding for Assembler Store Ordering (`.loc` Directive Quirk)**:
  - *Problem*: When zeroing or initializing contiguous array elements (e.g., `s16 D_802C8C70[4]`), explicit indexed assignments (`arr[0] = 0; arr[1] = 0; ...`) cause IDO to load the base address into a temporary register (`$v0`) and emit relative stores. In contrast, an unrolled loop (`for (i = 0; i < 4; i++) arr[i] = 0;`) enables IDO to emit direct stores sharing a single `%hi` register (`sh $zero, %lo(arr)(at)`).
  - *Assembler Quirk*: When written across multiple lines, IDO attaches distinct `.loc` source line directives to the loop header and unrolled body iterations. The SGI assembler (`as1`) scheduler treats `.loc` transitions as instruction reordering boundaries, often emitting stores out of offset order (e.g. `2($at)`, `4($at)`, `6($at)`, `0($at)`).
  - *Solution*: Placing the entire unrolled loop on a **single line**:
    ```c
    for (i = 0; i < 4; i++) D_802C8C70[i] = 0;
    ```
    binds all unrolled stores to a single `.loc` directive, compelling `as1` to emit the stores in strictly sequential offset order (`0($at)`, `2($at)`, `4($at)`, `6($at)`).
- **Loop Body Statement Order & Negative-Offset Delay Slot Stores**:
  - In loops updating multiple arrays or pointers, the relative order of statements determines whether IDO emits strength-reduced pointer post-increments with negative offsets (`sw $zero, -4($reg)`).
  - Storing the induction variable last (e.g., `arr1[i] = 0; arr2[i] = 0; arr3[i] = i;`) causes IDO to emit the dependent store `sh $v0, 0($a1)` first, increment `$v0`, test the loop condition, increment the pointers (`addiu $v1, 4; addiu $a0, 4; addiu $a1, 2`), and schedule the final zero store into the branch delay slot with a `-4` offset (`bnez $at, .Lloop; sw $zero, -4($a0)`).
- **IDO 5.3 Stack Frame Layout & Local Variable Ordering**:
  - *High-to-Low Stack Order*: Local variables are allocated on the stack in descending address order based on their declaration sequence. The first declared locals occupy the highest stack addresses (directly below caller arguments); later declared variables sit closer to `$sp` (just above the callee-saved register save area).
  - *Alignment & Buffer Padding Management*: When large buffers (e.g., `MtxF`, `Mtx`) are shifted by 8 bytes due to alignment constraints, declare small scalar variables (such as loop index `i`) **after** the matrix structures. IDO absorbs scalars declared last into the bottom padding area above the saved registers, preventing an unwanted `+8` byte shift across all earlier stack buffers.
  - *Example (504-byte frame with five nested matrices)*:
    ```c
    s32 angle;      /* 0x1F0 - top of stack, declared first */
    s32 cond;       /* 0x1EC */
    s32 j;          /* 0x1E8 - intentionally above floats */
    f32 var_fs1;    /* 0x1E4 */
    f32 var_fs2;    /* 0x1E0 */
    MtxF sp1A4;     /* 0x1A4 */
    MtxF sp164;     /* 0x164 */
    MtxF sp124;     /* 0x124 */
    Mtx spE0;       /* 0xE0 */
    Mtx spA0;       /* 0xA0 */
    s32 i;          /* 0x88 - declared last, absorbs padding above saved regs */
    ```
- **Loop Counter Variable Reuse Across Scopes**:
  - *The Invariant*: If two or more loops in a function are disjoint, IDO reuses the same register and stack slot for their induction counters when the same variable is used.
  - *The Pitfall*: Introducing distinct variables (e.g., `i` for loop 1 and `j` for loop 2) forces `uopt` to allocate separate stack slots and distinct register webs, triggering cascade register spills across the entire function.
  - *Rule*: Always reuse `i` across consecutive, non-overlapping loops unless target assembly explicitly uses a second induction register.
- **Triggering Callee-Saved Float Registers (`$f20`, `$f22`)**:
  - In functions calling external subroutines, local `f32` variables whose values must survive across function calls force IDO to allocate callee-saved floating-point registers (`$f20`, `$f22`) and emit the corresponding `s.d` / `l.d` (or `swc1` / `lwc1`) save/restore sequence in the prologue and epilogue.
- **Loop Construct Selection (`for` vs `while` vs `do-while`)**:
  - Standard `for (i = 0; i < N; i++)` produces a test-at-bottom structure with an unconditional initial branch (`b .test; nop`), matching retail N64 assembly patterns.
  - `while` loops produce top-of-loop branch conditions, while `do-while` loops omit the entry branch entirely, producing branch misalignments.
  - *Diagnostic*: If a diff shows a leading unconditional `b` to a `blt`/`bne` at loop bottom → use `for`. If the loop starts with `blt`/`bne` directly → use `while`. If there is no entry guard → use `do-while`.

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


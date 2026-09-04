# Wave Race 64 Decompilation & Native macOS Port

An ongoing byte-matching decompilation of **Wave Race 64 (US Rev 1)** for the Nintendo 64, featuring a native Apple Silicon (macOS arm64) porting layer.

---

## Current Status

* **N64 ROM Target:** Byte-matching against retail US Rev 1 (`waverace64.us.rev1.z64: OK`).
* **Progress:** 1,040 / 1,367 matched functions (76.08%) | 329,200 / 834,152 matched bytes (39.47%).
* **Validation Suite:** 416 passing tests (`make test`) verifying integrity across physics, camera, HUD, and audio subroutines.
* **Native macOS Port:** Boots natively on Apple Silicon via Clang (`make mac`), featuring a POSIX Libultra abstraction layer and direct ROM asset streaming.

---

## Project Structure

```text
├── asm/             # Disassembled MIPS routines (non-matchings and data)
├── include/         # Engine headers, Libultra structs, and hardware defines
├── linker_scripts/  # Segment layout maps and symbol address definitions
├── port/            # Native macOS ARM64 hardware abstraction layer
├── src/             # Decompiled C game engine source files
│   ├── audio/       # Audio sequencing, synthesis, and voice playback
│   ├── codeseg/     # Front-end UI, menus, and text rendering
│   ├── game/        # Buoyant hull physics, wave simulation, AI rivals
│   ├── libultra/    # N64 OS primitives (threads, queues, PI/VI DMA)
│   └── sys/         # Core loop dispatch and matrix utilities
├── tests/           # Regression test suite (test_matching.py)
└── tools/           # IDO static recompilers, splat, and diffing tools
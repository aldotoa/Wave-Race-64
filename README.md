# Wave Race 64 Decompilation & Native macOS Port

An ongoing byte-matching decompilation of **Wave Race 64 (US Rev 1)** for the Nintendo 64, featuring a native Apple Silicon (macOS arm64) porting layer.

---

## Current Status

* **N64 ROM Target:** Byte-matching against retail US Rev 1 (`waverace64.us.rev1.z64: OK`).
* **Progress:** 1,095 / 1,367 matched functions (80.10%) | 356,936 / 834,104 matched bytes (42.79%).
* **Validation Suite:** 417 passing tests (`make test`) verifying integrity across physics, camera, HUD, and audio subroutines.
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
```

---

## Getting Started

### Prerequisites

* MIPS binutils (`mips-linux-gnu-ld` or compatible `MIPS_BINUTILS_PREFIX`)
* SGI IDO 5.3 compiler (N64 matching build)
* Python 3 with project venv (`.venv`) for `splat`, `GitPython`, `colour`
* Place the US Rev 1 base ROM as `baserom.us.rev1.z64` in the repo root

### Setup

```bash
make dependencies   # build tools, install splat + GitPython/colour/objdiff deps
make init           # clean + extract assets + build ROM (verifies SHA-1 match)
```

### Build & Verify

```bash
make                # build N64 ROM; must end with `waverace64.us.rev1.z64: OK`
make test           # run validation suite (python3 tests/test_matching.py)
make progress       # report matched functions / bytes (uses .venv python)
```

`make progress` prints aggregate totals only. It counts ELF function symbols that no longer have a corresponding nonmatching assembly stub; it does not list individual functions or update this README or the decompilation plan.

ROM integrity is byte-for-byte: SHA-1 `508dfc2d4caa42b6f6de5263d0aed5e44ac7966a`.
Never commit unless `make` reports `waverace64.us.rev1.z64: OK`.

### Native macOS Port (Apple Silicon)

```bash
make mac            # Clang ARM64 build via port/ Libultra abstraction layer
```

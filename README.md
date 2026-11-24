# Wave Race 64 Decompilation & Native macOS Port

An ongoing byte-matching decompilation of **Wave Race 64 (US Rev 1)** for the Nintendo 64, featuring a native Apple Silicon (macOS arm64) porting layer.

> **This repository does not contain the game.** You must supply your own legally obtained copy of the US Rev 1 ROM to build anything. No ROM, assets, or copyrighted game data are distributed here.

---

## Current Status

* **N64 ROM Target:** Byte-matching against retail US Rev 1 (`waverace64.us.rev1.z64: OK`).
* **Progress (2026-11-24):** 1,209 / 1,368 matched functions (88.38%) | 457,184 / 834,028 matched bytes (54.82%).
* **Validation Suite:** 449 passing tests (`make test`) verifying integrity across physics, camera, HUD, and audio subroutines.
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

---

## Contributing

The full remaining-work matrix (tiers, per-function status, and parked-draft floor notes) lives in [DECOMPILATION_PLAN.md](DECOMPILATION_PLAN.md). Matching workflow, compiler quirks, and promotion rules are in [AGENTS.md](AGENTS.md); every PR must keep `make` reporting `waverace64.us.rev1.z64: OK` and `make test` green.

Work-in-progress probes belong in `scratch/`, which is gitignored.

---

## Credits

Built on community decompilation tooling: [splat](https://github.com/ethteck/splat), [asm-differ](https://github.com/simonlindholm/asm-differ), [m2c](https://github.com/matt-kempster/m2c), [asm-processor](https://github.com/simonlindholm/asm-processor), [ido-static-recomp](https://github.com/decompals/ido-static-recomp), and [Torch](https://github.com/HarbourMasters/Torch). Much of the matching work was done with AI coding agents.

Wave Race 64 is a trademark of Nintendo. This project is not affiliated with or endorsed by Nintendo.


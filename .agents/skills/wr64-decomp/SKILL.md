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

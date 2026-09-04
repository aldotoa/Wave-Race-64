#!/usr/bin/env python3
"""
Automated Promotion Script for Wave Race 64 Decompilation
Usage: python3 tools/promote.py <function_name> <path/to/source.c>

Performs the full promotion sequence:
1. Verifies the function matches by temporarily removing the NON_MATCHING wrapper,
   rebuilding, and running diff.py. Reverts if the match fails.
2. Deletes the corresponding .s file in asm/us/rev1/nonmatchings/.
3. Runs `make` to verify retail ROM SHA-1 match.
4. Runs `make test` to verify all unit tests pass.
5. Runs `make progress` to print the updated progress.

IMPORTANT: This script modifies source files. If it fails mid-way, you may need to
manually revert with: git checkout -- <source_file>
"""

import argparse
import os
import re
import subprocess
import sys
import glob
import shutil

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
ROOT_DIR = os.path.join(SCRIPT_DIR, "..")
ASM_DIR = os.path.join(ROOT_DIR, "asm", "us", "rev1", "nonmatchings")
DIFF_SCRIPT = os.path.join(ROOT_DIR, ".venv", "bin", "python3")
DIFF_PY = os.path.join(ROOT_DIR, "tools", "asm-differ", "diff.py")


def run_cmd(cmd, cwd=None, capture=True):
    """Run a shell command and return (returncode, stdout, stderr)."""
    if cwd is None:
        cwd = ROOT_DIR
    result = subprocess.run(
        cmd, shell=True, cwd=cwd,
        stdout=subprocess.PIPE if capture else None,
        stderr=subprocess.PIPE if capture else None,
        text=True
    )
    return result.returncode, result.stdout or "", result.stderr or ""


def find_asm_stub(func_name):
    """Locate the .s assembly stub file for a function."""
    pattern = os.path.join(ASM_DIR, "**", f"{func_name}.s")
    matches = glob.glob(pattern, recursive=True)
    if not matches:
        print(f"  WARNING: No .s stub found for {func_name} (may already be promoted)")
        return None
    if len(matches) > 1:
        print(f"  WARNING: Multiple .s stubs found for {func_name}:")
        for m in matches:
            print(f"    {m}")
        print(f"  Using first match: {matches[0]}")
    return matches[0]


def find_wrapper_lines(lines, func_name):
    """
    Find the #ifdef NON_MATCHING / #pragma GLOBAL_ASM wrapper lines for a function.
    Returns (ifdef_idx, else_idx, pragma_idx, endif_idx) or None if not found.
    """
    pragma_pattern = re.compile(
        rf'^\s*#\s*pragma\s+GLOBAL_ASM\s*\(\s*"[^"]*{re.escape(func_name)}\.s"\s*\)',
        re.IGNORECASE
    )

    pragma_idx = None
    for i, line in enumerate(lines):
        if pragma_pattern.match(line):
            pragma_idx = i
            break

    if pragma_idx is None:
        return None

    # Search backwards from pragma to find #else
    else_idx = None
    for i in range(pragma_idx - 1, max(pragma_idx - 5, -1), -1):
        if re.match(r'^\s*#\s*else\s*$', lines[i]):
            else_idx = i
            break

    if else_idx is None:
        return None

    # Search backwards from #else to find #ifdef NON_MATCHING
    ifdef_idx = None
    for i in range(else_idx - 1, -1, -1):
        stripped = lines[i].strip()
        if re.match(r'#\s*if(?:def)?\s+NON_MATCHING', stripped):
            ifdef_idx = i
            break
        if 'NON_MATCHING' in stripped and stripped.startswith('#if'):
            ifdef_idx = i
            break

    if ifdef_idx is None:
        return None

    # Search forwards from pragma to find #endif
    endif_idx = None
    for i in range(pragma_idx + 1, min(pragma_idx + 5, len(lines))):
        if re.match(r'^\s*#\s*endif', lines[i]):
            endif_idx = i
            break

    if endif_idx is None:
        return None

    return (ifdef_idx, else_idx, pragma_idx, endif_idx)


def remove_wrapper(source_path, func_name):
    """
    Remove #ifdef NON_MATCHING / #pragma GLOBAL_ASM wrapper around a function.
    Returns True on success, False if no wrapper found.
    """
    with open(source_path, 'r') as f:
        lines = f.readlines()

    result = find_wrapper_lines(lines, func_name)
    if result is None:
        return False

    ifdef_idx, else_idx, pragma_idx, endif_idx = result
    lines_to_remove = {ifdef_idx, else_idx, pragma_idx, endif_idx}
    new_lines = [line for i, line in enumerate(lines) if i not in lines_to_remove]

    with open(source_path, 'w') as f:
        f.writelines(new_lines)

    return True


def check_and_promote(func_name, source_path, dry_run=False, force=False):
    """Full promotion pipeline."""

    print(f"=== Promoting {func_name} ===")
    print(f"Source: {os.path.relpath(source_path, ROOT_DIR)}")
    print()

    # Step 1: Verify match
    if not force:
        print(f"[1/5] Verifying {func_name} matches...")

        # Save a backup of the source file
        backup_path = source_path + ".promote_backup"
        shutil.copy2(source_path, backup_path)

        # Check if function has a wrapper
        with open(source_path, 'r') as f:
            lines = f.readlines()

        wrapper = find_wrapper_lines(lines, func_name)
        if wrapper is None:
            print(f"  No #ifdef NON_MATCHING wrapper found for {func_name}")
            print(f"  Function may already be promoted, or has no C implementation yet.")
            os.remove(backup_path)
            sys.exit(1)

        # Temporarily remove the wrapper to compile C code
        if not remove_wrapper(source_path, func_name):
            print(f"  ERROR: Failed to remove wrapper")
            shutil.copy2(backup_path, source_path)
            os.remove(backup_path)
            sys.exit(1)

        # Touch source and rebuild, then diff
        os.utime(source_path, None)
        cmd = f"{DIFF_SCRIPT} {DIFF_PY} -m -o -s {func_name}"
        rc, stdout, stderr = run_cmd(cmd)

        if rc != 0 or "CURRENT (0)" not in stdout:
            # Match failed — revert
            score_match = re.search(r"CURRENT\s*\((\d+)\)", stdout)
            if score_match:
                score = score_match.group(1)
                print(f"  FAIL: Function has diff score {score} (must be 0)")
            else:
                print(f"  FAIL: Could not parse diff output")
                if stderr:
                    print(f"  {stderr[:300]}")

            # Revert the source file
            shutil.copy2(backup_path, source_path)
            os.remove(backup_path)
            # Invalidate the .o cache so standard build works again
            os.utime(source_path, None)
            run_cmd(f"touch {source_path} && make")
            print(f"\nABORTED: {func_name} does not match. Source reverted.")
            sys.exit(1)

        print(f"  OK: {func_name} is a 100% byte-for-byte match (score 0)")
        os.remove(backup_path)

        if dry_run:
            # Revert changes since this was a dry run
            with open(source_path, 'r') as f:
                current = f.read()
            with open(source_path + ".promote_backup", 'w') as f:
                pass  # Already removed backup above
            # Need to re-add the wrapper... simplest: use git checkout
            # Actually, the wrapper is already removed. For dry-run, let's just
            # re-read from backup. But we already removed backup.
            # The cleanest approach: save original content before modifying.
            print(f"\n--dry-run: {func_name} matches! Would promote. Reverting...")
            # We need to restore. Use git:
            run_cmd(f"git checkout -- {source_path}")
            os.utime(source_path, None)
            run_cmd("make")
            sys.exit(0)
    else:
        print(f"[1/5] Skipping diff check (--force)")
        # Still need to remove the wrapper
        print(f"[2/5] Removing NON_MATCHING wrapper...")
        if remove_wrapper(source_path, func_name):
            print(f"  OK: Wrapper removed")
        else:
            print(f"  No wrapper found (may already be promoted)")

    # Step 2: Delete asm stub
    print(f"[2/5] Deleting assembly stub...")
    asm_path = find_asm_stub(func_name)
    if asm_path and os.path.exists(asm_path):
        os.remove(asm_path)
        print(f"  OK: Deleted {os.path.relpath(asm_path, ROOT_DIR)}")
    elif asm_path:
        print(f"  WARNING: File not found: {asm_path}")
    else:
        print(f"  No .s stub to delete")

    # Step 3: Verify build
    print(f"[3/5] Rebuilding and verifying ROM checksum...")
    os.utime(source_path, None)
    rc, stdout, stderr = run_cmd("make")
    if rc != 0:
        print(f"  ERROR: make failed (exit code {rc})")
        print((stderr + stdout)[-500:])
        print(f"\nERROR: Build failed after promotion!")
        print(f"Revert with: git checkout -- {os.path.relpath(source_path, ROOT_DIR)}")
        sys.exit(1)

    if "OK" in stdout:
        print(f"  OK: waverace64.us.rev1.z64: OK")
    else:
        print(f"  ERROR: ROM checksum verification failed")
        print(stdout[-300:])
        print(f"\nRevert with: git checkout -- {os.path.relpath(source_path, ROOT_DIR)}")
        sys.exit(1)

    # Step 4: Run tests
    print(f"[4/5] Running test suite...")
    rc, stdout, stderr = run_cmd("make test")
    combined = stdout + stderr
    if rc != 0 or "FAIL" in combined:
        print(f"  ERROR: Tests failed!")
        last_lines = combined.strip().split('\n')[-10:]
        for line in last_lines:
            print(f"    {line}")
        print(f"\nRevert with: git checkout -- {os.path.relpath(source_path, ROOT_DIR)}")
        sys.exit(1)

    test_match = re.search(r'Ran (\d+) tests? in', combined)
    if test_match:
        print(f"  OK: Ran {test_match.group(1)} tests - all passed")
    else:
        print(f"  OK: Tests completed")

    # Step 5: Show progress
    print(f"[5/5] Updating progress...")
    rc, stdout, stderr = run_cmd("make progress")
    if rc == 0:
        for line in stdout.strip().split('\n'):
            print(f"  {line}")

    print(f"\n=== SUCCESS: {func_name} promoted! ===")


def main():
    parser = argparse.ArgumentParser(
        description="Automated function promotion for Wave Race 64 decompilation"
    )
    parser.add_argument("func_name", help="Name of the function to promote")
    parser.add_argument("source_file", help="Path to the source .c file containing the function")
    parser.add_argument("--dry-run", action="store_true",
                        help="Only check if function matches, don't modify files permanently")
    parser.add_argument("--force", action="store_true",
                        help="Skip diff check (use when function is already verified)")

    args = parser.parse_args()
    source_path = os.path.abspath(args.source_file)

    if not os.path.exists(source_path):
        print(f"ERROR: Source file not found: {source_path}")
        sys.exit(1)

    check_and_promote(args.func_name, source_path, dry_run=args.dry_run, force=args.force)


if __name__ == "__main__":
    main()

#!/usr/bin/env python3

import argparse
import glob
import multiprocessing
import os
import shutil
import subprocess
import sys
from typing import List


# clang-format default version
# This specific version is used when available, for more consistency between contributors
CLANG_VER = 20

# Clang-Format options (see .clang-format for rules applied)
FORMAT_OPTS = "-i -style=file"


def get_clang_executable(allowed_executables: List[str]):
    for executable in allowed_executables:
        try:
            subprocess.check_call(
                [executable, "--version"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            return executable
        except (FileNotFoundError, subprocess.CalledProcessError):
            pass
    return None


CLANG_FORMAT = get_clang_executable([f"clang-format-{CLANG_VER}", "clang-format"])
if CLANG_FORMAT is None:
    sys.exit(f"Error: clang-format-{CLANG_VER} not found")


def list_chunks(list: List, chunk_length: int):
    for i in range(0, len(list), chunk_length):
        yield list[i: i + chunk_length]


def run_clang_format(files: List[str]):
    exec_str = f"{CLANG_FORMAT} {FORMAT_OPTS} {' '.join(files)}"
    subprocess.run(exec_str, shell=True)


def add_final_new_line(file: str):
    # https://backreference.org/2010/05/23/sanitizing-files-with-no-trailing-newline/index.html
    # "gets the last character of the file pipes it into read, which will exit with a nonzero exit
    # code if it encounters EOF before newline (so, if the last character of the file isn't a newline).
    # If read exits nonzero, then append a newline onto the file using echo (if read exits 0,
    # that satisfies the ||, so the echo command isn't run)." (https://stackoverflow.com/a/34865616)
    exec_str = f"tail -c1 {file} | read -r _ || echo >> {file}"
    subprocess.run(exec_str, shell=True)


def format_files(src_files: List[str], extra_files: List[str], nb_jobs: int):
    if nb_jobs != 1:
        print(f"Formatting files with {nb_jobs} jobs")
    else:
        print(f"Formatting files with a single job (consider using -j to make this faster)")

    # Format files in chunks to improve performance while still utilizing jobs
    file_chunks = list(list_chunks(src_files, (len(src_files) // nb_jobs) + 1))

    print("Running clang-format...")
    # clang-format only applies changes in the given files, so it's safe to run in parallel
    with multiprocessing.get_context("fork").Pool(nb_jobs) as pool:
        pool.map(run_clang_format, file_chunks)

    print("Adding missing final new lines...")
    # Adding final new lines is safe to do in parallel and can be applied to all types of files
    with multiprocessing.get_context("fork").Pool(nb_jobs) as pool:
        pool.map(add_final_new_line, src_files + extra_files)

    print("Done formatting files.")


def main():
    parser = argparse.ArgumentParser(
        description="Format files in the codebase to enforce most style rules")
    parser.add_argument("files", metavar="file", nargs="*")
    parser.add_argument(
        "--show-paths",
        dest="show_paths",
        action="store_true",
        help="Print the paths to the clang-* binaries used",
    )
    parser.add_argument(
        "-j",
        dest="jobs",
        type=int,
        nargs="?",
        default=1,
        help="number of jobs to run (default: 1 without -j, number of cpus with -j)",
    )
    args = parser.parse_args()

    if args.show_paths:
        import shutil

        print("CLANG_FORMAT             ->", shutil.which(CLANG_FORMAT))

    nb_jobs = args.jobs or multiprocessing.cpu_count()

    if args.files:
        files = args.files
        extra_files = []
    else:
        files = glob.glob("src*/**/*.c", recursive=True)
        files = [x for x in files if "assets" not in x]
        extra_files = glob.glob("assets/**/*.xml", recursive=True)

    format_files(files, extra_files, nb_jobs)


if __name__ == "__main__":
    main()

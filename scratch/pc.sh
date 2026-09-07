#!/bin/sh
# Probe compile: exact IDO flags from the Makefile C recipe (CC line only),
# with tools/ido cc invoked directly (plain C probe needs no asm-processor).
# Usage: sh scratch/pc.sh scratch/probe_6B38.c scratch/probe_6B38.o
set -e
IN="$1"
OUT="$2"
tools/ido-static-recomp/build/5.3/out/cc -c \
  -G 0 -non_shared -fullwarn -verbose -Xcpluscomm \
  -I include -I . -I include/libc -I include/PR -I include -I bin -I src/libultra \
  -nostdinc -Wab,-r4300_mul -woff 649,838,712,516 \
  -DVERSION_US=1 -DNON_MATCHING -DAVOID_UB \
  -I include -I . -I include/libc -I include/PR -I include -I bin -I src/libultra \
  -fullwarn -verbose -woff 624,649,838,712,516,513,596,564,594,709,807 \
  -mips2 -32 -EB \
  -D_MIPS_SZLONG=32 -DNDEBUG -DF3D_OLD \
  -D_FINALROM -DCOMPILING_LIBULTRA -DTARGET_N64 -DSSSV -DWIN32 -DLANGUAGE_C -D_LANGUAGE_C -DNDEBUG \
  -O2 -o "$OUT" "$IN"
mips-linux-gnu-objcopy --remove-section .mdebug "$OUT"

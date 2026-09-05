import subprocess
import re

with open("scratch/test_tmp.c") as f:
    template = f.read()

def compile_and_check(code):
    with open("scratch/test_search.c", "w") as f:
        f.write(code)
    cmd = ("tools/ido-static-recomp/build/5.3/out/cc -c -G 0 -non_shared -Xcpluscomm "
           "-I include -I . -I include/libc -I include/PR -I bin "
           "-nostdinc -Wab,-r4300_mul -woff 649,838,712,516 -DVERSION_US=1 "
           "-mips2 -32 -EB -D_MIPS_SZLONG=32 -DNDEBUG -DF3D_OLD -D_FINALROM "
           "-DTARGET_N64 -DLANGUAGE_C -D_LANGUAGE_C -O2 "
           "-o scratch/test_search.o scratch/test_search.c")
    ret = subprocess.run(cmd, shell=True, capture_output=True)
    if ret.returncode != 0:
        return None
    dump = subprocess.run("/opt/homebrew/bin/mips-linux-gnu-objdump -d -M reg-names=mips3 scratch/test_search.o",
                          shell=True, capture_output=True, text=True).stdout
    m_func = re.search(r'<func_i2_802C5E28>:\s*([\s\S]*?)(?:[0-9a-f]{8} <|\Z)', dump)
    if not m_func:
        return None
    lines = [l.strip() for l in m_func.group(1).splitlines() if l.strip()]
    blez_lines = [j for j, l in enumerate(lines) if 'blez' in l]
    if not blez_lines:
        return None
    idx = blez_lines[0]
    delay = lines[idx+1]
    after = lines[idx+2:idx+8]
    return delay, after


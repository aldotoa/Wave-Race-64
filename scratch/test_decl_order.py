import subprocess
import re

with open("scratch/test_tmp.c") as f:
    orig = f.read()

# find declaration block
decl_pattern = r"(u32 func_i2_802C5E28\(void\) \{)([\s\S]*?)(u16 pressed;)"
m = re.search(decl_pattern, orig)
if not m:
    print("Could not find declarations")
    exit(1)

header = m.group(1)
footer = m.group(3)

vars = [
    "s32 player;",
    "s32 offset;",
    "s32 can_select;",
    "s32 rider_idx;",
    "s32* s1;",
    "s32 sound_mode;",
    "s32* s2;",
    "s32* s5;",
    "UnkStruct_801CE658* s6;",
]

for i in range(len(vars)):
    reordered = vars.copy()
    s1_item = reordered.pop(4)
    reordered.insert(i, s1_item)
    decls = "\n    " + "\n    ".join(reordered) + "\n    "
    new_code = orig[:m.start(2)] + decls + orig[m.start(3):]
    with open("scratch/test_try_order.c", "w") as f:
        f.write(new_code)
    cmd = ("tools/ido-static-recomp/build/5.3/out/cc -c -G 0 -non_shared -Xcpluscomm "
           "-I include -I . -I include/libc -I include/PR -I bin "
           "-nostdinc -Wab,-r4300_mul -woff 649,838,712,516 -DVERSION_US=1 "
           "-mips2 -32 -EB -D_MIPS_SZLONG=32 -DNDEBUG -DF3D_OLD -D_FINALROM "
           "-DTARGET_N64 -DLANGUAGE_C -D_LANGUAGE_C -O2 "
           "-o scratch/test_try_order.o scratch/test_try_order.c")
    ret = subprocess.run(cmd, shell=True, capture_output=True)
    if ret.returncode != 0:
        print(f"compile failed for pos {i}")
        continue
    dump = subprocess.run("/opt/homebrew/bin/mips-linux-gnu-objdump -d -M reg-names=mips3 scratch/test_try_order.o",
                          shell=True, capture_output=True, text=True).stdout
    m_func = re.search(r'<func_i2_802C5E28>:\s*([\s\S]*?)(?:[0-9a-f]{8} <|\Z)', dump)
    if m_func:
        body = m_func.group(1)
        lines = [l.strip() for l in body.splitlines() if l.strip()]
        blez_lines = [j for j, l in enumerate(lines) if 'blez' in l]
        if blez_lines:
            idx = blez_lines[0]
            delay = lines[idx+1]
            sw18 = [l for l in lines[:idx] if '24(sp)' in l or '0x18(sp)' in l]
            # also find first 5 instructions after delay slot
            after = lines[idx+2:idx+7]
            print(f"pos {i} (s1 at {i}): delay = {delay} | sw24 = {sw18}")
            for a in after:
                print(f"   {a}")

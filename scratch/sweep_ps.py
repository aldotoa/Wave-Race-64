import re, subprocess, itertools, shutil, os

SRC = open('src/audio/audio_general.c').read()
start = SRC.find('/* Master sound effect dispatcher (m2c scaffold')
assert start > 0
end = SRC.find('#else\n#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/audio/audio_general/AudioGeneral_PlaySound.s")')
assert end > start
draft = SRC[start:end]
body = draft[draft.find('*/') + 2:].strip()
HEADER = '''#include "wr64audio.h"
u8 func_800C32A0(u32 arg0, s32 arg1, s32 arg2);
void func_800C1EB8(s32 arg0);
void func_800C15C8(s32 arg0, u32 arg1);
void func_800C3320(u32 arg0, s32 arg1, s32 arg2);
void func_800C33C8(s32 arg0, u32 arg1, s32 arg2, u32 arg3);
void func_800C3408(u32 arg0, s32 arg1, s32 arg2);
void AudioGeneral_DisableSeqPlayer2(u32 fade);
void AudioThread_QueueCmdS8(s32 opArgs, s8 val);
extern s32 D_800E7CD4;
extern s32 D_800E7CF0;
extern s32 D_800E7CF4;
extern s8 D_801D7DFC;
extern s8 D_801D7E04;
extern s32 D_800E7CA0;
extern s32 D_800E7CA8;
'''
BASE_DECLS = ['s32 sp30;', 's32 sp24;', 's32 temp_v0;', 's32 temp_v0_2;',
              's32 temp_v1;', 's32 var_a0;', 's32 var_a0_2;', 's32 var_v0;',
              's32 var_v1;', 'u32 var_a0_3;']

# verify body starts with the decl block
for d in BASE_DECLS:
    assert d in body, d

VARIANTS = {
    'V0_base': list(BASE_DECLS),
    'V1_usedfirst': ['s32 sp30;', 's32 var_v1;', 's32 sp24;', 's32 temp_v0;',
                     's32 temp_v1;', 's32 temp_v0_2;', 's32 var_a0;',
                     's32 var_a0_2;', 's32 var_v0;', 'u32 var_a0_3;'],
    'V2_reverse': list(reversed(BASE_DECLS)),
    'V3_casegroup': ['s32 sp30;', 's32 sp24;', 's32 var_v1;', 's32 temp_v0;',
                     's32 var_a0;', 's32 temp_v0_2;', 's32 temp_v1;',
                     's32 var_a0_2;', 's32 var_v0;', 'u32 var_a0_3;'],
    'V4_casegroup_rev': ['s32 sp30;', 's32 sp24;', 's32 var_v1;',
                         's32 var_v0;', 'u32 var_a0_3;', 's32 temp_v0_2;',
                         's32 temp_v1;', 's32 var_a0_2;', 's32 temp_v0;',
                         's32 var_a0;'],
    'V5_alpha': sorted(BASE_DECLS),
    'V6_u32first': ['u32 var_a0_3;', 's32 sp30;', 's32 sp24;',
                    's32 temp_v0;', 's32 temp_v0_2;', 's32 temp_v1;',
                    's32 var_a0;', 's32 var_a0_2;', 's32 var_v0;',
                    's32 var_v1;'],
}

# strip old decl block from body (up to first 'if (')
m = re.search(r'\n    if \(D_800E7C94', body)
assert m
tail = body[m.start():]


def build(decls, tag, typepatch=None):
    code = HEADER + 'void AudioGeneral_PlaySound(s32 arg0, s32 arg1) {\n'
    code += '\n'.join('    ' + d for d in decls) + '\n' + tail
    if typepatch:
        for old, new in typepatch:
            assert old in code, (tag, old)
            code = code.replace(old, new)
    p = f'scratch/sweep_{tag}.c'
    open(p, 'w').write(code)
    return p


# type variants use base order
VARIANTS['V7_a0_3_s32'] = list(BASE_DECLS)
VARIANTS['V8_sp24_u32'] = list(BASE_DECLS)
TYPEPATCH = {
    'V7_a0_3_s32': [('u32 var_a0_3;', 's32 var_a0_3;')],
    'V8_sp24_u32': [('s32 sp24;', 'u32 sp24;')],
}

os.makedirs('expected/scratch', exist_ok=True)
print(f"{'variant':<14} {'score':<10} frame")
for tag, decls in VARIANTS.items():
    assert sorted(d.split()[-1].rstrip(';') for d in decls) == \
        sorted(d.split()[-1].rstrip(';') for d in BASE_DECLS), tag
    p = build(decls, tag, TYPEPATCH.get(tag))
    o = p.replace('.c', '.o')
    import time
    time.sleep(1)
    os.utime(p, None)
    r = subprocess.run(['sh', 'scratch/pc.sh', p, o],
                       capture_output=True, text=True)
    if not os.path.exists(o) or r.returncode != 0:
        print(f"{tag:<14} BUILDFAIL")
        continue
    shutil.copy(o, 'expected/' + o)
    d = subprocess.run(
        ['.venv/bin/python3', 'tools/asm-differ/diff.py', '-o', '-f', o,
         '--base-asm', 'scratch/base_PS.slice', '--format', 'plain',
         '--no-pager', 'AudioGeneral_PlaySound'],
        capture_output=True, text=True)
    line0 = d.stdout.split('\n')[0] if d.stdout else ''
    mm = re.search(r'CURRENT \((\d+)\)', line0)
    score = mm.group(1) if mm else '?'
    od = subprocess.run(
        ['mips-linux-gnu-objdump', '--disassemble=AudioGeneral_PlaySound', o],
        capture_output=True, text=True)
    fm = re.search(r'addiu\s+sp,sp,-(\d+)', od.stdout)
    frame = fm.group(1) if fm else '?'
    print(f"{tag:<14} {score:<10} {frame}", flush=True)

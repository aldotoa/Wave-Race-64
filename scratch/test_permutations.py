import subprocess, itertools

decls_templates = [
    ("s32 cur_y, tex_offset, i, y2, height;", ["cur_y", "tex_offset", "i", "y2", "height"]),
    ("s32 tex_offset, cur_y, i, y2, height;", ["tex_offset", "cur_y", "i", "y2", "height"]),
    ("s32 i, cur_y, tex_offset, y2, height;", ["i", "cur_y", "tex_offset", "y2", "height"]),
    ("s32 i, tex_offset, cur_y, y2, height;", ["i", "tex_offset", "cur_y", "y2", "height"]),
    ("s32 tex_offset, i, cur_y, y2, height;", ["tex_offset", "i", "cur_y", "y2", "height"]),
    ("s32 cur_y, i, tex_offset, y2, height;", ["cur_y", "i", "tex_offset", "y2", "height"]),
    ("s32 y2, cur_y, tex_offset, i, height;", ["y2", "cur_y", "tex_offset", "i", "height"]),
]

inits = [
    "tex_offset = 0",
    "i = 0",
    "cur_y = y",
    "y2 = y + 20"
]

target_bytes = bytes.fromhex("00006025 00005025 00c05825 24cd0014")

template = """#include <ultra64.h>
extern u16 D_80B0008[];
Gfx* func_i2_802C86E4(Gfx* gdl, s32 x, s32 y) {{
    {decls}

    for ({init}; i != 105; i += 15, y2 += 15, cur_y += 15, tex_offset += 1950) {{
        if (i != 90) {{
            height = 15;
        }} else {{
            height = 2;
        }}

        gDPLoadTextureTile(gdl++, (u8*) D_80B0008 + (tex_offset << 1), G_IM_FMT_RGBA, G_IM_SIZ_16b, 130, 0, 0, 0, 130 - 1,
                           height - 1, 0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, (x + 8) << 2, y2 << 2, (x + 138) << 2, (cur_y + height + 20) << 2, G_TX_RENDERTILE,
                            0, 0, 1 << 10, 1 << 10);
    }}

    return gdl;
}}
"""

found = False
for d_code, _ in decls_templates:
    for perm in itertools.permutations(inits):
        init_str = ", ".join(perm)
        code = template.format(decls=d_code, init=init_str)
        with open("scratch/test.c", "w") as f:
            f.write(code)
        res = subprocess.run([
            "tools/ido-static-recomp/build/5.3/out/cc", "-c", "-G", "0", "-non_shared", "-Xcpluscomm",
            "-I", "include", "-I", ".", "-I", "include/libc", "-I", "include/PR", "-I", "bin",
            "-nostdinc", "-Wab,-r4300_mul", "-woff", "649,838,712,516", "-DVERSION_US=1",
            "-mips2", "-32", "-EB", "-D_MIPS_SZLONG=32", "-DNDEBUG", "-DF3D_OLD", "-D_FINALROM",
            "-DTARGET_N64", "-DLANGUAGE_C", "-D_LANGUAGE_C", "-O2",
            "-o", "scratch/test.o", "scratch/test.c"
        ], capture_output=True)
        if res.returncode != 0:
            continue
        with open("scratch/test.o", "rb") as f:
            data = f.read()
        if target_bytes in data:
            print(f"MATCH FOUND!")
            print(f"Decl: {d_code}")
            print(f"Init: {init_str}")
            found = True
            break
    if found:
        break

if not found:
    print("No exact match in standard permutations.")

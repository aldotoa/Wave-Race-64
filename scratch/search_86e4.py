import subprocess

target_bytes = bytes.fromhex("00006025 00005025 00c05825 24cd0014")

candidates = []

# Various for headers and before-loop statements
inits = [
    # comma variations
    ("s32 cur_y, tex_offset, i, y2, height;", "", "tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "", "cur_y = y, tex_offset = 0, i = 0, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "", "tex_offset = 0, cur_y = y, i = 0, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "", "i = 0, tex_offset = 0, cur_y = y, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "", "i = 0, cur_y = y, tex_offset = 0, y2 = y + 20"),
    # with cur_y referenced or cast
    ("s32 cur_y, tex_offset, i, y2, height;", "", "(cur_y), tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "", "cur_y, tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "", "(void)cur_y, tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "", "+cur_y, tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "", "!cur_y, tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    # assignment variations
    ("s32 cur_y, tex_offset, i, y2, height;", "", "tex_offset = i = 0, cur_y = y, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "", "i = tex_offset = 0, cur_y = y, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "", "tex_offset = 0, i = 0, y2 = (cur_y = y) + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "", "tex_offset = 0, i = 0, cur_y = y, y2 = cur_y + 20"),
    # declaration with different types / orders
    ("s32 tex_offset, cur_y, i, y2, height;", "", "tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    ("s32 i, cur_y, tex_offset, y2, height;", "", "tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    ("s32 height, cur_y, tex_offset, i, y2;", "", "tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    ("s32 y2, cur_y, tex_offset, i, height;", "", "tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    # volatile or register
    ("volatile s32 cur_y; s32 tex_offset, i, y2, height;", "", "tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    ("register s32 cur_y; s32 tex_offset, i, y2, height;", "", "tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    ("s32 cur_y; register s32 tex_offset; s32 i, y2, height;", "", "tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    ("register s32 i; s32 cur_y, tex_offset, y2, height;", "", "tex_offset = 0, i = 0, cur_y = y, y2 = y + 20"),
    # pre-loop statements
    ("s32 cur_y, tex_offset, i, y2, height;", "cur_y = y;", "tex_offset = 0, i = 0, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "cur_y = y; y2 = y + 20;", "tex_offset = 0, i = 0"),
    ("s32 cur_y, tex_offset, i, y2, height;", "tex_offset = 0; i = 0;", "cur_y = y, y2 = y + 20"),
    ("s32 cur_y, tex_offset, i, y2, height;", "y2 = y + 20;", "tex_offset = 0, i = 0, cur_y = y"),
]

for decl, pre, init in inits:
    code = f"""#include <ultra64.h>
extern u16 D_80B0008[];
Gfx* func_i2_802C86E4(Gfx* gdl, s32 x, s32 y) {{
    {decl}
    {pre}
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
        print(f"Decl: {decl}")
        print(f"Pre:  {pre}")
        print(f"Init: {init}")
        sys.exit(0)

print("No exact match found in tested candidates.")

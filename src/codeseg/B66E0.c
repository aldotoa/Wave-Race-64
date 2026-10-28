#include "common.h"

void func_801E9858(Gfx*, s32, s32, s32, s32);
extern f32 D_80226E24;
extern s16 D_80226E28;

Gfx* func_801E946C(Gfx*, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_801E8B24(Gfx* glistp, s32 a1, char* buf, s32 a3, s32 a4);

#ifdef NON_MATCHING
void func_801E80B0(void) {
    /* Font glyph metrics table and character bounds initializer */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E80B0.s")
#endif

#ifdef NON_MATCHING
void func_801E8800(void) {
    /* Character spacing and kerning metrics calculator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E8800.s")
#endif

void func_801E8A84(Gfx* arg0, s32 arg1, char* buf, s32 arg3, s32 arg4, s32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 arg10, u8 arg11, u8 arg12, u8 arg13, u8 arg14, u8 arg15, u8 arg16, u8 arg17) {
    arg0 = func_801E946C(arg0, arg5, (s32) arg6, (s32) arg7, (s32) arg8, (s32) arg9, (s32) arg10, (s32) arg11,
                         (s32) arg12, (s32) arg13, (s32) arg14, (s32) arg15, (s32) arg16, (s32) arg17);
    func_801E8B24(arg0, arg1, buf, arg3, arg4);
}

#ifdef NON_MATCHING
void func_801E8B24(Gfx* glistp, s32 a1, char* buf, s32 a3, s32 a4) {
    /* Text centering and string bounding box calculator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E8B24.s")
#endif

void func_801E92FC(Gfx* arg0, s32 arg1, char* buf, s32 arg3, s32 arg4, s32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 arg10, u8 arg11, u8 arg12, u8 arg13, u8 arg14, u8 arg15, u8 arg16, u8 arg17) {
    D_80226E24 = 1.0f;
    arg0 = func_801E946C(arg0, arg5, (s32) arg6, (s32) arg7, (s32) arg8, (s32) arg9, (s32) arg10, (s32) arg11,
                         (s32) arg12, (s32) arg13, (s32) arg14, (s32) arg15, (s32) arg16, (s32) arg17);
    D_80226E28 = 0;
    func_801E9858(arg0, arg1, buf, arg3, arg4);
}

extern s32 D_80226E2C;
extern s32 D_80228A44;
extern s32 D_80226E30[];

typedef struct UnkStruct_801EAF78_s {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
} UnkStruct_801EAF78;

extern UnkStruct_801EAF78 D_80228A78;

void func_801E93B4(Gfx* arg0, s32 arg1, char* buf, s32 arg3, s32 arg4, s32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 arg10, u8 arg11, u8 arg12, u8 arg13, u8 arg14, u8 arg15, u8 arg16, u8 arg17, f32 scale) {
    D_80226E24 = scale;
    arg0 = func_801E946C(arg0, arg5, (s32) arg6, (s32) arg7, (s32) arg8, (s32) arg9, (s32) arg10, (s32) arg11,
                         (s32) arg12, (s32) arg13, (s32) arg14, (s32) arg15, (s32) arg16, (s32) arg17);
    D_80226E28 = 1;
    func_801E9858(arg0, arg1, buf, arg3, arg4);
}

#ifdef NON_MATCHING
Gfx* func_801E946C(Gfx* glistp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10,
                   s32 a11, s32 a12, s32 a13) {
    D_80226E2C = 100;
    D_80228A44 = a1;
    D_80226E28 = 0;
    return glistp;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E946C.s")
#endif

#ifdef NON_MATCHING
void func_801E9858(Gfx* glistp, s32 a1, s32 a2, s32 a3, s32 a4) {
    /* Main string glyph display list generator */
    ((void) glistp);
    ((void) a1);
    ((void) a2);
    ((void) a3);
    ((void) a4);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E9858.s")
#endif

/*
 * Proportional-font glyph mapper: (mode, char) -> glyph index, 0 when the
 * mode has no glyph for it, 0xFF for a space (fixed-width 12 in caller
 * func_i8_802C6EB8's string-width accumulator).
 * Load-bearing: a single `return glyph;`. IDO copies that return block into
 * each arm (`jr ra; li v0,K`) and each switch default (`jr ra; move v0,v1`);
 * per-arm C returns turn the shared tail into `move; jr; nop` reached by
 * `bnel` likely-fills instead.
 */
s32 func_801E9B04(s32 fontMode, s8 character) {
    s32 glyph = 0;

    if ((character >= 0x30) && (character < 0x3A)) {
        glyph = character - 0x30;
    } else if ((character >= 0x41) && (character < 0x5B)) {
        if ((fontMode == 0) || (fontMode == 1) || (fontMode == 2)) {
            glyph = character - 0x37;
        }
    } else if (character == 0x2F) {
        if (fontMode != 2) {
            if (fontMode == 5) {
                glyph = 0xA;
            }
        } else {
            glyph = 0x28;
        }
    } else if (character == 0x2D) {
        switch (fontMode) {
            case 0:
            case 1:
                glyph = 0x24;
                break;
            case 2:
                glyph = 0x25;
                break;
        }
    } else if (character == 0x27) {
        switch (fontMode) {
            case 0:
            case 1:
                glyph = 0x25;
                break;
            case 2:
                glyph = 0x26;
                break;
            case 3:
                glyph = 0xA;
                break;
        }
    } else if (character == 0x40) {
        switch (fontMode) {
            case 0:
            case 1:
                glyph = 0x26;
                break;
            case 2:
                glyph = 0x27;
                break;
            case 3:
                glyph = 0xB;
                break;
        }
    } else if (character == 0x26) {
        if (fontMode == 2) {
            glyph = 0x24;
        }
    } else if (character == 0x2E) {
        switch (fontMode) {
            case 0:
                glyph = 0x27;
                break;
            case 2:
                glyph = 0x29;
                break;
            case 1:
                glyph = 0x29;
                break;
        }
    } else if (character == 0x7C) {
        if (fontMode == 2) {
            glyph = 0x2A;
        }
    } else if (character == 0x3C) {
        if (fontMode == 2) {
            glyph = 0x2B;
        }
    } else if (character == 0x3E) {
        if (fontMode == 2) {
            glyph = 0x2C;
        }
    } else if (character == 0xA) {
        if (fontMode == 1) {
            glyph = 0x28;
        }
    } else if (character == 0x2B) {
        if (fontMode == 2) {
            glyph = 0x2D;
        }
    } else if (character == 0x20) {
        glyph = 0xFF;
    }
    return glyph;
}

#ifdef NON_MATCHING
void func_801E9D6C(void) {
    /* Formatted lap timer display printer (mm:ss.ms) */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E9D6C.s")
#endif

#ifdef NON_MATCHING
void func_801EA0B0(void) {
    /* 2D text quad texture rectangle emitter */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EA0B0.s")
#endif

#ifdef NON_MATCHING
void func_801EA3EC(void) {
    /* Fast3D font texture tile loader */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EA3EC.s")
#endif

#ifdef NON_MATCHING
void func_801EA730(void) {
    /* Variable-width proportional font mapper */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EA730.s")
#endif

#ifdef NON_MATCHING
void func_801EAA6C(void) {
    /* Font tile cache and texture buffer manager */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EAA6C.s")
#endif

void func_801EADB0(void) {
    switch (D_80228A78.unk2) {
        case 0:
        case 2: {
            u32 val = (u32) (((f32) D_80228A78.unk4 * 127.0f) / (f32) D_80228A78.unk8);
            val += 128;
            D_80228A78.unkC = val;
            D_80228A78.unkE = 255;
            D_80228A78.unk10 = val;
            break;
        }
        case 1:
        case 3: {
            u32 val = (u32) (((f32) (D_80228A78.unk8 - D_80228A78.unk4) * 127.0f) / (f32) D_80228A78.unk8);
            val += 128;
            D_80228A78.unkC = val;
            D_80228A78.unkE = 255;
            D_80228A78.unk10 = val;
            break;
        }
    }
}

void func_801EAF78(void) {
    D_80228A78 = *(UnkStruct_801EAF78*) D_80226E30;
}

void func_801EAFB4(void) {
    if (D_80228A78.unk0 != 0) {
        D_80228A78.unk4++;
        if (D_80228A78.unk4 >= D_80228A78.unk8) {
            D_80228A78.unk4 = 0;
            D_80228A78.unk2++;
            if (D_80228A78.unk2 == 4) {
                D_80228A78.unk2 = 0;
            }
        }
    }
}

#ifdef NON_MATCHING
void func_801EB00C(void) {
    /* Formatted integer text formatter */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EB00C.s")
#endif

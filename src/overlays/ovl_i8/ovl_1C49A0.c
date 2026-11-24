#include "common.h"

#ifdef NON_MATCHING
Gfx* func_i8_802C5800(Gfx* arg0) {
    /* Stunt mode ramp and floating ring display list generator */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C5800.s")
#endif

extern s16 D_80228A16;
extern s32 D_800DAB2C;
extern s32 D_7000000;
extern s32 D_2000A40;
extern s32 D_106F550;
extern s32 D_8062290;
Gfx* Game_BuildRaceScene(Gfx*);
Gfx* func_i8_802C63E4(Gfx*);
void func_i8_802C5EB8(Gfx*);
void func_8007C31C(void);
void func_801EC304(void);

Gfx* func_i8_802C5D3C(Gfx* glistp) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x3E) {
            return Gfx_ClearFrameBuffers(glistp);
        }
    }

    D_800DAB2C = 0;
    gDPPipeSync(glistp++);
    gDPSetScissorFrac(glistp++, G_SC_NON_INTERLACE, 0x20, 0x50, 0x4DC, 0x36C);
    gSPMatrix(glistp++, &D_7000000, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(glistp++, &D_2000A40, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(glistp++, &D_106F550);

    glistp = Game_BuildRaceScene(glistp);

    gDPPipeSync(glistp++);
    gDPSetScissorFrac(glistp++, G_SC_NON_INTERLACE, 0x20, 0x50, 0x4DC, 0x36C);

    glistp = func_i8_802C63E4(glistp);

    gSPDisplayList(glistp++, &D_8062290);

    if (gGameState == 0x3E) {
        func_i8_802C5EB8(glistp);
    } else if (D_80228A16 == 1) {
        func_8007C31C();
        func_801EC304();
    }

    return glistp;
}

#ifdef NON_MATCHING
void func_i8_802C5EB8(void) {
    /* Stunt floating ring collision check and ring pass sound */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C5EB8.s")
#endif

#ifdef NON_MATCHING
void func_i8_802C63E4(void) {
    /* Stunt score multiplier and combo timer update */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C63E4.s")
#endif

#ifdef NON_MATCHING
typedef struct KeyboardKey {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ char pad2[0xA];
    /* 0x0C */ s8 unkC;
    /* 0x0D */ char padD[0xF];
} KeyboardKey; /* size = 0x1C */

extern s32 D_802C7538;
extern s32 D_802C753C;
extern s8 D_802C7558;
extern KeyboardKey D_i8_802C7054[];
void func_i8_802C6D58(void);
void func_i8_802C6DA8(void);
void func_i8_802C6E00(void);
void func_i8_802C6E68(void*);
s32 func_i8_802C6EB8(s8* str, s32 arg1);
void func_i8_802C6FD4(s8* src, s8* dest, s32 count);

/*
 * Draft, strict probe floor 35 rows (2026-11-16). Notes: scratch/goal agent NOTES.md / see PR.
 */
void func_i8_802C6ADC(void) {
    s32 idx;
    KeyboardKey* key;
    s32 n;
    s32 ok;
    s32 i;
    s8* p;
    idx = D_802C753C * 7 + D_802C7538;
    key = &D_i8_802C7054[idx];
    switch (key->unk1) {
        case 0:
        case 3:
            ok = 1;
            if (Strlen2(&D_802C7548) >= 10) {
                ok = 0;
            } else if (func_i8_802C6EB8(&D_802C7548, 2) >= 0x77) {
                ok = 0;
            }
            if (ok) {
                func_i8_802C6FD4(&D_802C7548, &D_802C7558, 11);
                n = D_802C7564;
                i = n + 1;
                if (i < 11) {
                    s8* dst = &D_802C7548 + i;
                    s8* src = &D_802C7558 + i;
                    do {
                        *dst = src[-1];
                        src++;
                        dst++;
                    } while (src < &D_802C7558 + 11);
                }
                p = &D_802C7548 + n;
                if (key->unk1 == 3) {
                    *p = ' ';
                } else {
                    *p = key->unkC;
                }
                if (func_i8_802C6EB8(&D_802C7548, 2) >= 0x7C) {
                    func_i8_802C6FD4(&D_802C7558, &D_802C7548, 11);
                } else if ((&D_802C7558)[D_802C7564] == 0) {
                    D_802C7564++;
                }
            }
            break;
        case 1:
            func_i8_802C6D58();
            break;
        case 2:
            func_i8_802C6DA8();
            break;
        case 5:
            if (((&D_802C7548)[D_802C7564] != 0) && (D_802C7564 < 10)) {
                D_802C7564++;
            }
            break;
        case 4:
            if (D_802C7564 > 0) {
                D_802C7564--;
            }
            break;
        case 6:
            func_i8_802C6E68(&D_800DA950[D_i8_802C74F8[D_i8_802C7040]]);
            break;
        case 7:
            func_i8_802C6E00();
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C6ADC.s")
#endif

void func_i8_802C6D58(void) {
    s32 i = 0;
    s8* ptr = &D_802C7548;

    D_802C7564 = 0;
    do {
        *ptr = 0;
        ptr++;
        i++;
    } while (i < 11);
}

void func_i8_802C6DA8(void) {
    if (D_802C7564 > 0) {
        s8* src = &D_802C7548 + D_802C7564;
        s8* dst;

        D_802C7564--;
        dst = &D_802C7548 + D_802C7564;

        while (*src != 0) {
            *dst++ = *src++;
        }
        *dst = 0;
    }
}

void func_i8_802C6E00(void) {
    if ((D_802C7548) != 0) {
        func_i8_802C6FD4(&D_802C7548, (s8*) &D_801CB298[D_i8_802C74F8[D_i8_802C7040]].unk_0, 11);
    }
    D_802C756C = 1;
}

void func_i8_802C6E68(void* arg0) {
    func_i8_802C6FD4(arg0, &D_802C7548, 0xB);
    D_802C7564 = Strlen2(&D_802C7548);
    if (D_802C7564 >= 9) {
        D_802C7564 = 9;
    }
}

extern u8 D_80226DC4[];
s32 func_801E9B04(s32, s8);

s32 func_i8_802C6EB8(s8* str, s32 arg1) {
    s32 total = 0;
    s32 i = 0;

    while (str[i] != 0) {
        s32 glyph = func_801E9B04(arg1, str[i]);
        s32 width;

        if (glyph == 0xFF) {
            width = 12;
        } else {
            width = D_80226DC4[glyph];
        }
        total += width;
        i++;
    }
    return total;
}

void func_i8_802C6F4C(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x3F;
    D_801CE638 = 0xA;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;
    FadeTransition_SetProps(1, 4, 0);
}

void func_i8_802C6FD4(s8* src, s8* dest, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        *dest++ = *src++;
    }
}

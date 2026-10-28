#include "global.h"

extern s32 D_800D461C;
extern s32 D_800DAB1C;
extern s32 D_801CE630;
extern s32 gPrevGameState;
extern s32 D_801CE638;
extern s32 D_801CE63C;
extern s32 D_801CE640;
extern s32 D_801CE644;

extern Mtx D_8011F820;
extern s32 D_801CB334;
extern s16 D_800EAC14[][8];
extern s32 D_801C2660[];
extern s32 D_801C2690[];

Gfx* Gfx_ClearCurrentBuffer(Gfx* glistp);
Gfx* func_8008FB74(Gfx* glistp);
Gfx* Gfx_DrawCoursePanel(Gfx* glistp, s32 course);
Gfx* Draw_WaterEffects(Gfx* glistp);
void func_801E2530(void);
Gfx* func_801E2058(Gfx* glistp);
Gfx* func_801E229C(Gfx* glistp);
void func_8007C204(s16 arg0);
void func_8007BEA4(s16 arg0);
void func_801EC500(void);

#ifdef NON_MATCHING
void func_801E1290(void) {
    /* Machine tuning interaction and controller input loop */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E1290.s")
#endif

#ifdef NON_MATCHING
void func_801E1BA8(void) {
    /* Machine tuning state initialization */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E1BA8.s")
#endif

Gfx* func_801E1E8C(Gfx* glistp) {
    s32 s0;
    s32 s1;
    s16 a0;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }
    D_800DAB2C = 0;
    glistp = Gfx_ClearCurrentBuffer(glistp);
    glistp = func_8008FB74(glistp);
    glistp = func_801E2058(glistp);
    gSPMatrix(glistp++, &D_8011F820, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    glistp = Gfx_DrawCoursePanel(glistp, gCourseID);
    glistp = Draw_WaterEffects(glistp);
    glistp = func_801E229C(glistp);

    if (gGameState == 100) {
        func_801E2530();
    } else if (D_80228A16 == 1) {
        if (D_801CE608.gameMode == 4) {
            for (s0 = 0, s1 = 0; s0 < D_801CB334 + 1; s0++, s1++) {
                a0 = D_800EAC14[gDifficulty][s1];
                if ((D_801C2660[a0] != 0) || (D_801C2690[a0] != 0)) {
                    if (D_800DAB68 != 0) {
                        func_8007C204(a0);
                    } else {
                        func_8007BEA4(a0);
                    }
                }
            }
        }
        func_801EC500();
    }

    return glistp;
}

extern Gfx D_106F6C0;
extern Gfx* D_80226040[];
extern s32 D_802261F8;
extern s32 D_802287E0;
extern s32 D_802287E4;
extern s32 D_802287E8[];
void func_8006DE24(Gfx** glistp);

/* Slider track renderer: draws the selected range of 16 slider segments.
 * The four empty `if (x) {}` statements are load-bearing: they raise the
 * allocation priority of i/isWrap/cond so the loop bound 16 is rematerialized
 * in $at each iteration instead of being cached in a callee-saved register. */
Gfx* func_801E2058(Gfx* glistp) {
    s32 cond;
    s32 isWrap;
    s32 i;

    glistp = Gfx_FillCourseColor(glistp, gCourseID);
    gSPDisplayList(glistp++, &D_106F6C0);

    if (D_802261F8 != 0) {
        func_8006DE24(&glistp);
    }

    isWrap = (D_802287E0 < D_802287E4) ? 0 : 1;

    for (i = 0; i < 16; i += 2) {
        cond = 0;
        if (isWrap == 0) {
            if (i >= D_802287E0 && D_802287E4 >= i) {
                cond = 1;
            }
        } else if (i >= D_802287E0 || D_802287E4 >= i) {
            cond = 1;
        }
        if (i) {}

        if (cond != 0) {
            gSPMatrix(glistp++, (u8*) D_801CE5F8 + (i << 6) + 0x1380, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
            gSPDisplayList(glistp++, D_80226040[D_802287E8[i]]);
            gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
        }
        if (isWrap) {}

        cond = 0;
        if (isWrap == 0) {
            if (i >= D_802287E0 - 1 && D_802287E4 > i) {
                cond = 1;
            }
        } else if (i >= D_802287E0 - 1 || D_802287E4 > i) {
            cond = 1;
        }

        if (cond) {
            gSPMatrix(glistp++, (u8*) D_801CE5F8 + (i << 6) + 0x13C0, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
            gSPDisplayList(glistp++, D_80226040[D_802287E8[i + 1]]);
            gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
        }
        if (cond) {}
    }
    if (i) {}

    return glistp;
}

#ifdef NON_MATCHING
Gfx* func_801E229C(Gfx* glistp) {
    /* Jet ski color customization palette selector */
    return glistp;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E229C.s")
#endif

#ifdef NON_MATCHING
const char D_80226210[] = "A";
const char D_80226214[] = "B";
const char D_80226218[] = "C";
const char D_8022621C[] = "D";
const char D_80226220[] = "E";
const char D_80226224[] = "F";
const char D_80226228[] = "G";
const char D_8022622C[] = "H";
const char D_80226230[] = "I";
const char D_80226234[] = "J";
const char D_80226238[] = "K";
const char D_8022623C[] = "L";
const char D_80226240[] = "M";
const char D_80226244[] = "N";
const char D_80226248[] = "O";
const char D_8022624C[] = "P";
const char D_80226250[] = "Q";
const char D_80226254[] = "R";
const char D_80226258[] = "S";
const char D_8022625C[] = "T";
const char D_80226260[] = "U";
const char D_80226264[] = "V";
const char D_80226268[] = "W";
const char D_8022626C[] = "X";
const char D_80226270[] = "Y";
const char D_80226274[] = "Z";
const char D_80226278[] = "-";
const char D_8022627C[] = ".";
const char D_80226280[] = " ";
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226210.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226214.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226218.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022621C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226220.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226224.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226228.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022622C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226230.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226234.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226238.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022623C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226240.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226244.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226248.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022624C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226250.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226254.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226258.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022625C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226260.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226264.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226268.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022626C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226270.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226274.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226278.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022627C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226280.s")
#endif

#ifdef NON_MATCHING
void func_801E2530(void) {
    /* Character select and machine tuning cursor display list renderer */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E2530.s")
#endif

void func_801E2B8C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = GAME_STATE_65;
    D_801CE638 = 6;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 0xE, 0x14);
}

#ifdef NON_MATCHING
void func_801E2C14(void) {
    /* Machine tuning exit and active rider stat commit */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E2C14.s")
#endif

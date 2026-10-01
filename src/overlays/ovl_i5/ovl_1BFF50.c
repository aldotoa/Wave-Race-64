#include "common.h"

/* Forward declarations and file-data externs for the 5A98 draft.
   Prototypes/externs emit no code, so the matching build is unaffected.
   NOTE: D_800EABBC is canonically const s16[] (cf. code_4C750.c:118);
   kept here in the probe-exact non-const spelling because the floor below
   was measured with it -- retyping re-rolls codegen. */
void func_i5_802C5A98(void);
void func_800C21F4(s32 arg0, int courseID);
extern s32 D_801CB334;
extern s32 D_801CB340[];
extern const s16 D_800EABBC[][8];
extern s32 D_i5_802C7A2C[];
extern s32 D_802C7B00;
extern s32 D_802C7B08;
extern RiderStruct D_801C2C70[];

void func_i5_802C5800(void) {
    if ((D_801CE63C != 0) && (gGameState == 52)) {
        Race_UpdateStandings();
        func_i5_802C5A98();
    }
    func_i5_802C5850();
}

#ifdef NON_MATCHING
void func_i5_802C5850(void) {
    /* Port Blue container ship wake disturbance simulation */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C5850.s")
#endif

void func_i5_802C5A98(void) {
    s32 need;
    s32 limp;
    s32 ride;

    limp = D_i5_802C7A2C[gDifficulty];
    need = D_800EABBC[gDifficulty][D_801CB334];
    ride = D_800D48DC;
    if (D_801CB340[ride] >= need) {
        if (D_801CB334 >= limp) {
            if (gDifficulty == DIFFICULTY_NORMAL) {
                D_801CB280 |= 1;
            } else if (gDifficulty == DIFFICULTY_HARD) {
                D_801CB280 |= 2;
            } else if (gDifficulty == DIFFICULTY_EXPERT) {
                D_801CB280 |= 4;
                if (D_801C2C70[ride].lapCount == 0) {
                    D_801CB280 |= 8;
                }
            }
            D_802C7B08 = 0x66;
            D_802C7B00 = 2;
        } else {
            D_802C7B08 = 0x1E;
            D_802C7B00 = 1;
        }
    } else {
        D_802C7B08 = 0x5A;
        D_802C7B00 = 0;
    }
    func_800C21F4(3, D_802C7B00 ? 0 : 1);
}

extern s32 D_801CB288[];
void func_8007C494(void);
Gfx* func_i5_802C5DC0(Gfx*);
void func_i5_802C6CC4(void);
void func_801ECB98(void);
void func_801EB91C(void);
void func_801EB180(void);

Gfx* func_i5_802C5C1C(Gfx* glistp) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x34) {
            osViBlack(0);
            return Gfx_ClearFrameBuffers(glistp);
        }
    }

    glistp = Gfx_ClearCurrentBuffer(glistp);
    D_800DAB2C = 0;
    glistp = Gfx_FillCourseColor(glistp, gCourseID);
    glistp = func_8008FB74(glistp);
    glistp = Draw_WaterEffects(glistp);
    glistp = func_i5_802C5DC0(glistp);

    if (gGameState == 0x34) {
        func_i5_802C6CC4();
    } else if (D_80228A16 == 1) {
        if (D_801CE630 == 0x66) {
            func_801ECB98();
        } else if (D_801CE630 == 0x1E) {
            D_801CB334++;
            if (D_800DAB68 != 0) {
                if (D_801CB288[3] < D_801CB334) {
                    D_801CB288[3] = D_801CB334;
                }
            } else {
                if (D_801CB288[gDifficulty] < D_801CB334) {
                    D_801CB288[gDifficulty] = D_801CB334;
                }
            }
            func_801EB91C();
        } else {
            func_801EB180();
        }
    }

    if (D_801CE638 != 9) {
        func_8007C494();
    }
    return glistp;
}

#ifdef NON_MATCHING
void func_i5_802C5DC0(void) {
    /* Port Blue moving container barge kinematic update */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C5DC0.s")
#endif

#ifdef NON_MATCHING
void func_i5_802C6CC4(void) {
    /* Port Blue canal lock water height adjust */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C6CC4.s")
#endif

/* Enters the Port Blue post-race state: latches subState, raises the frame
 * flag, then picks the fade and the follow-up audio cue for the 0x66
 * (champion) and 0x1E (runner-up) endings. */
void func_i5_802C6F84(s32 subState) {
    gPrevGameState = gGameState;
    D_801CE630 = subState;
    gGameState = 0x35;
    D_801CE638 = 9;
    D_801CE63C = 1;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;

    if (D_801CE630 == 0x66) {
        FadeTransition_SetProps(1, 4, 0);
    } else if (D_801CE630 == 0x1E) {
        FadeTransition_SetProps(5, 2, 0);
    } else {
        FadeTransition_SetProps(5, 1, 0);
    }

    if (D_801CE630 == 0x66) {
        func_800C1F60(0xB);
        return;
    }
    if (D_801CE630 == 0x1E) {
        func_800C1F60(2);
    }
}

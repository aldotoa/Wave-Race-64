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

extern s16 D_802C7B04;
extern u16 D_802C7B06;
extern s16 D_i5_802C7A00;
extern Vp D_i5_802C7A08;

void func_i5_802C5850(void) {
    s32 i;
    f32 x;
    f32 z;
    MtxF sp174;
    MtxF sp134;
    MtxF spF4;
    Mtx spB0;
    Mtx sp70;

    D_802C7B04 = 0x28 - D_i5_802C7A00;
    func_800481E0(D_801CE5F8->unkA40, &D_802C7B06, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&spB0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.04f);
    x = gSinTable[0x400] * 500.0f;
    z = gSinTable[0] * 500.0f;
    func_800484C8(&sp70, &sp134, x, 0, z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    SysUtils_MtxToMtxF(&spB0, &sp174);
    SysUtils_MatrixAffineMultiply(&sp134, &sp174, &spF4);

    for (i = 0; i < 4; i++) {
        SysUtils_MtxFToMtx(&spF4, &D_801CE5F8->unkA80[i]);
        D_801CE5F8->unk1280[i] = D_i5_802C7A08;
        if (i & 1) {
            D_801CE5F8->unk1280[i].vp.vtrans[0] = (D_802C7B04 + 0x42) << 2;
        } else {
            D_801CE5F8->unk1280[i].vp.vtrans[0] = (D_i5_802C7A00 + 0x42) << 2;
        }
        D_801CE5F8->unk1280[i].vp.vtrans[1] = (i * 0x20 + 0x58) << 2;
    }
}

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

extern s32 D_802C7B0C;
void func_800C3E4C(void);
void func_801EC944(void);
void func_i5_802C6F84(s32 subState);

void func_i5_802C6CC4(void) {
    s32 sound;

    sound = 0;
    switch (D_801CE640) {
        case 0:
            if (D_80228A16 == 1) {
                D_801CE640 = 1;
                sound = 1;
            }
            break;
        case 1:
            D_i5_802C7A00 -= 0x14;
            if (D_i5_802C7A00 < 0x14) {
                D_801CE640 = 2;
                D_i5_802C7A00 = 0x14;
                D_801CE644 = 0;
            }
            break;
        case 2:
            if (D_801CE644 < 0x3C) {
                D_801CE644++;
            }
            if ((D_801CE644 >= 0x1F) && (D_801CE65A[0].unk0 & 0xB000)) {
                D_801CE640 = 3;
                sound = 1;
            }
            break;
        case 3:
            D_i5_802C7A00 -= 0x14;
            if (D_i5_802C7A00 < -0x109) {
                D_801CE640 = 4;
                D_i5_802C7A00 = -0x109;
                sound = 1;
            }
            break;
        case 4:
            D_i5_802C7A00 += 0x14;
            if (D_i5_802C7A00 >= 0x15) {
                D_801CE640 = 5;
                D_i5_802C7A00 = 0x14;
                D_802C7B0C = 0;
            }
            break;
        case 5:
            if (D_802C7B0C < 0x10) {
                D_802C7B0C++;
            }
            if ((D_802C7B0C == 6) && (D_802C7B00 == 1)) {
                func_800C3E4C();
            }
            if ((D_802C7B0C >= 6) && (D_801CE65A[0].unk0 & 0xB000)) {
                D_801CE640 = 6;
                D_801CE644 = 0;
                AudioGeneral_PlaySound(0x11, 0);
            }
            break;
        case 6:
            D_801CE644++;
            if (D_801CE644 >= 0x1E) {
                if (D_802C7B08 != 0x5A) {
                    func_i5_802C6F84(D_802C7B08);
                } else {
                    D_801CE640 = 7;
                    sound = 1;
                    func_800C1F60(5);
                }
            }
            break;
        case 7:
            D_i5_802C7A00 += 0x14;
            if (D_i5_802C7A00 >= 0x141) {
                D_i5_802C7A00 = 0x140;
                func_801EC944();
            }
            break;
    }
    if (sound != 0) {
        AudioGeneral_PlaySound(0x31, 0);
    }
}

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

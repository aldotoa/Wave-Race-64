#include "global.h"

void func_i4_802C7344(void);

void func_i4_802C5800(void) {
    if ((D_801CE63C != 0) && (gGameState == 20)) {
        func_i4_802C58F8();
    }

    if (D_i4_802C7530 != 0) {
        D_i4_802C7530 = 0;
        func_80069740(&D_80198310, D_800DAAB4[D_800DAAD8[D_800DA9D0]]);
        func_8006977C(&D_80198350, D_i4_802C760C[D_800DAAD8[D_800DA9D0]]);
    }

    func_80069798(D_801CE5F8->unkA80, D_801CE5F8->unk1780, D_801CE5F8->unkA40, &D_802C76AC, &D_80198310, &D_80198350);
}

#ifdef NON_MATCHING
void func_i4_802C58F8(void) {
    /* Sunny Beach shallow reef water surface state reset */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i4/ovl_1BE0B0/func_i4_802C58F8.s")
#endif

Gfx* func_i4_802C5B78(Gfx* dList) {
    Gfx* temp_v0;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x14) {
            osViBlack(0);
            return Gfx_ClearFrameBuffers(dList);
        }
    }
    D_802C76A8 = D_800DA9D0;
    D_800DAB2C = 0;
    temp_v0 = func_i4_802C5CDC(Draw_WaterEffects(Gfx_FillCourseColor(func_8008FB74(dList), gCourseID)));

    dList = temp_v0 + 1;

    gSPDisplayList(temp_v0++, &D_106F168);

    if (gGameState == 20) {
        func_i4_802C6BAC();
    } else if (D_80228A16 == 1) {
        switch (D_801CE630) {
            case 0x28:
                gCourseID = D_800DAAD8[D_800DA9D0];
                if (D_800D8240 != 0) {
                    gCourseID = D_801C3A10;
                }
                Game_EnterGameplay();
                break;

            case 10:
                func_801EBD28();
                break;

            default:
                break;
        }
    }
    return dList;
}

#ifdef NON_MATCHING
Gfx* func_i4_802C5CDC(Gfx* dList) {
    /* Sunny Beach shoreline surf swell display list emitter */
    return dList;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i4/ovl_1BE0B0/func_i4_802C5CDC.s")
#endif

extern s32 D_i4_802C7534;
extern uintptr_t D_800DB5F8[];
extern uintptr_t D_800DB6D0[];
extern uintptr_t D_800DB5B0[];
extern Gfx D_80A6E00;
extern Mtx D_7000A40;
extern Vp D_106F738;
extern Gfx D_106F748;

/* Sunny Beach backdrop and scenery display list. Shares its template with
 * ovl_i3's course-overview scene: `t2` is always 1 here, but the two
 * `if (t2 != 0)` blocks are load-bearing -- their block boundaries decide
 * where IDO writes gdl back to its home register (a0) and how the long-lived
 * course/table values get registers. */
Gfx* func_i4_802C6778(Gfx* gdl) {
    s32 course;
    s32* var_a3;
    s32* temp_t1;
    u32 temp_v1;
    s32 t2;

    t2 = 1;
    course = D_800DAAD8[D_800DA9D0];
    if (D_i4_802C7534 == 0) {
        var_a3 = (s32*) ((u8*) D_800DB5F8 + course * 8);
    } else {
        var_a3 = (s32*) ((u8*) D_800DB6D0 + course * 8);
    }
    gSPDisplayList(gdl++, &D_80A6E00);
    gDPPipeSync(gdl++);
    gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_PHYSICAL_TO_K0(gFrameBuffers[gFramebuffersIdx]));
    gSPPerspNormalize(gdl++, *(u16*) &D_802C76AC);
    gSPMatrix(gdl++, &D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, D_801CE5F8->unkA80, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPViewport(gdl++, &D_106F738);
    gSPDisplayList(gdl++, &D_106F748);
    gDPSetEnvColor(gdl++, 255, 255, 255, 255);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 150, 53, 292, 159);
    temp_t1 = (s32*) ((u8*) D_800DB5B0 + course * 8);
    temp_v1 = (course << 15) + 0x10000;
    gSPDisplayList(gdl++, temp_t1[0] + temp_v1);
    if (t2 != 0) {
        gSPClearGeometryMode(gdl++, G_LIGHTING);
        gSPDisplayList(gdl++, var_a3[0] + temp_v1);
    }
    gSPSetGeometryMode(gdl++, G_LIGHTING);
    gDPPipeSync(gdl++);
    gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    gSPDisplayList(gdl++, temp_t1[1] + temp_v1);
    if (t2 != 0) {
        gSPClearGeometryMode(gdl++, G_LIGHTING);
        gSPDisplayList(gdl++, var_a3[1] + temp_v1);
    }
    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 319, 239);
    return gdl;
}

extern u16 D_80A0008[];

Gfx* func_i4_802C69C4(Gfx* gdl, s32 arg1, s32 arg2) {
    s32 outer;
    s32 cur_y;
    s32 tex_offset;
    s32 height;

    for (tex_offset = 0, outer = 0, cur_y = arg2; outer != 0x50; outer += 0x10, cur_y += 0x10, tex_offset += 0x760) {
        if (outer != 0x40) {
            height = 0x10;
        } else {
            height = 3;
        }

        gDPLoadTextureTile(gdl++, D_80A0008 + tex_offset, G_IM_FMT_RGBA, G_IM_SIZ_16b, 118, height, 0, 0, 117,
                           height - 1, 0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gdl++, arg1 << 2, cur_y << 2, (arg1 + 0x76) << 2, (cur_y + height) << 2, G_TX_RENDERTILE, 0,
                            0, 1 << 10, 1 << 10);
    }

    return gdl;
}

void func_i4_802C6BAC(void) {
    switch (D_i4_802C7538) {
        case 0:
            func_i4_802C6C2C();
            break;
        case 1:
            func_i4_802C6ED0();
            break;
        case 2:
            func_i4_802C70C0();
            break;
        case 3:
            func_i4_802C7344();
            break;
    }
}

#ifdef NON_MATCHING
void func_i4_802C6C2C(void) {
    /* Sunny Beach course setup phase 0 */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i4/ovl_1BE0B0/func_i4_802C6C2C.s")
#endif

extern s32 D_i4_802C7540;
extern s32 D_i4_802C7544;
extern s32 D_i4_802C7548;
extern s32 D_802C76B4;
extern s32 D_802C76B8;
extern s32 D_802C76BC;
extern s32 D_802C76C0;

/* Course preview panel open (state 1) / close (state 2) zoom over 6 frames.
 * Both arms compute the (5 - n) term first: that order decides which FP
 * temps IDO assigns in the close arm. */
void func_i4_802C6ED0(void) {
    f32 a;
    f32 b;

    switch (D_i4_802C7544) {
        case 1:
            D_i4_802C7540 = 1;
            a = (5 - D_i4_802C753C) / 5.0f;
            b = D_i4_802C753C / 5.0f;
            D_802C76B4 = (s32) (71.0f * a) + 142;
            D_802C76B8 = (s32) (53.0f * a) + 33;
            D_802C76BC = 142.0f * b;
            D_802C76C0 = 106.0f * b;
            if (++D_i4_802C753C >= 6) {
                D_i4_802C7538 = 2;
                D_i4_802C753C = 0;
                D_i4_802C7548 = 1;
            }
            break;
        case 2:
            a = (5 - D_i4_802C753C) / 5.0f;
            b = D_i4_802C753C / 5.0f;
            D_802C76B4 = (s32) (71.0f * b) + 142;
            D_802C76B8 = (s32) (53.0f * b) + 33;
            D_802C76BC = 142.0f * a;
            D_802C76C0 = 106.0f * a;
            if (++D_i4_802C753C >= 6) {
                D_i4_802C7538 = 0;
                D_i4_802C753C = 0;
            }
            break;
    }
}

extern s16 D_801CE60C;
extern s32 D_i4_802C754C;
extern s32 D_i4_802C757C[][4];
extern s32 D_802C76CC;
extern s32 D_802C76D0;

/* Difficulty select. The skip-unavailable-entry loops test at the head and
 * wrap via a back jump, i.e. `for (;;) { if (...) break; ... }` -- a plain
 * `while (tbl == 0)` gets rotated by IDO. */
void func_i4_802C70C0(void) {
    if (D_801CE65A[D_802C76B0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        if (D_i4_802C754C == 3) {
            gDifficulty = 2;
            D_800DAB68 = 1;
        } else {
            gDifficulty = D_i4_802C754C;
            D_800DAB68 = 0;
        }
        if (D_801CE60C == 1) {
            func_i4_802C7474(0x28);
            AudioGeneral_PlaySound(0x37, 0);
            return;
        }
        D_i4_802C7554 = 1;
        D_i4_802C7538 = 3;
        D_i4_802C753C = 0;
        AudioGeneral_PlaySound(0x11, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & B_BUTTON) {
        D_i4_802C7538 = 1;
        D_i4_802C753C = 0;
        D_i4_802C7544 = 2;
        D_i4_802C7548 = 0;
        AudioGeneral_PlaySound(0x16, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & U_JPAD) {
        if (--D_i4_802C754C < D_802C76CC) {
            D_i4_802C754C = D_802C76D0 - 1;
        }
        for (;;) {
            if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][D_i4_802C754C] != 0) {
                break;
            }
            if (--D_i4_802C754C < D_802C76CC) {
                D_i4_802C754C = D_802C76D0 - 1;
            }
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & D_JPAD) {
        if (++D_i4_802C754C >= D_802C76D0) {
            D_i4_802C754C = D_802C76CC;
        }
        for (;;) {
            if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][D_i4_802C754C] != 0) {
                break;
            }
            if (++D_i4_802C754C >= D_802C76D0) {
                D_i4_802C754C = D_802C76CC;
            }
        }
        AudioGeneral_PlaySound(0x10, 0);
    }
}

void func_i4_802C7344(void) {
    if (D_801CE65A[D_802C76B0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        if (D_800DAA04 == 0) {
            D_801CE61C = 1;
        } else {
            D_801CE61C = 0;
        }
        func_i4_802C7474(0x28);
        AudioGeneral_PlaySound(0x37, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & B_BUTTON) {
        D_i4_802C7554 = 0;
        D_i4_802C7538 = 2;
        D_i4_802C753C = 0;
        AudioGeneral_PlaySound(0x16, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & L_JPAD) {
        if (--D_800DAA04 < 0) {
            D_800DAA04 = 1;
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & R_JPAD) {
        if (++D_800DAA04 >= 2) {
            D_800DAA04 = 0;
        }
        AudioGeneral_PlaySound(0x10, 0);
    }
}

void func_i4_802C7474(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 21;
    D_801CE638 = 5;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 4, 0);
    func_801E6A4C(0, 0);
    if (D_801CE630 == 40) {
        func_800C1F60(7);
    }
}

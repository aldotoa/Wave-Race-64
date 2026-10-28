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

extern s32 D_801CB288[];
extern s16 D_800EAC14[][8];
extern s32 D_i4_802C7534;
extern s32 D_i4_802C7558[];
extern s32 D_i4_802C757C[][4];
extern s32 D_802C76A4;
extern s32 D_802C76C4;
extern s32 D_802C76C8;
extern s32 D_802C76D0;

/* Course/difficulty select setup: marks every (course, difficulty) pair the
 * player has unlocked in D_i4_802C757C, then flags courses with any unlocked
 * entry in D_i4_802C7558. Expert (i == 3) reuses the hard course list, and
 * writing that row as `i - 1` (not a literal 2) is what lets IDO walk both
 * rows with one pointer. */
void func_i4_802C58F8(void) {
    s32 i;
    s32 j;
    s32 found;
    s32 course;

    if (D_801CE608.gameMode == 11) {
        D_i4_802C7534 = 1;
    } else {
        D_i4_802C7534 = 0;
    }

    if (D_801CE608.player == 1) {
        D_802C76B0 = 0;
        if (D_801CB280 & 8) {
            D_802C76C8 = 1;
            D_802C76D0 = 4;
            D_802C76C4 = 1;
        } else {
            D_802C76C8 = 0;
            D_802C76D0 = 3;
            D_802C76C4 = 0;
        }
    } else {
        D_802C76B0 = 2;
        if (D_801CB280 & 8) {
            D_802C76C8 = 3;
            D_802C76D0 = 4;
            D_802C76C4 = 1;
        } else {
            D_802C76C8 = 2;
            D_802C76D0 = 3;
            D_802C76C4 = 0;
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_801CB288[i] + 1; j++) {
            if (i == 3) {
                course = D_800EAC14[i - 1][j];
            } else {
                course = D_800EAC14[i][j];
            }
            D_i4_802C757C[course][i] = 1;
        }
    }

    if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 1)) {
        if (!(D_801CB280 & 1)) {
            D_i4_802C757C[1][1] = 0;
        }
        if (!(D_801CB280 & 2)) {
            D_i4_802C757C[1][2] = 0;
        }
    }

    for (i = 0; i < 9; i++) {
        found = 0;
        for (j = 0; j < 4; j++) {
            if (D_i4_802C757C[i][j] != 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            D_i4_802C7558[i] = 1;
        }
    }

    if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 1)) {
        D_i4_802C7558[0] = 0;
    }

    if (D_801CE608.player == 1) {
        if (D_801CE608.gameMode == 0) {
            D_802C76A4 = 1;
        } else {
            D_802C76A4 = 0;
        }
    } else {
        D_802C76A4 = 1;
    }

    if (D_800DA9D0 < D_802C76A4) {
        D_800DA9D0 = D_802C76A4;
    }
}

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

extern s32 D_i4_802C7540;
extern s32 D_i4_802C754C;
extern s32 D_i4_802C7550;
extern s32 D_i4_802C7548;
extern s32 D_802C76B4;
extern s32 D_802C76B8;
extern s32 D_802C76BC;
extern s32 D_802C76C0;
extern s16 D_801CE60C;

typedef struct {
    s16 x;
    s16 y;
    s32 id;
} I4Label;
typedef struct {
    s32 w;
    s32 pad[11];
} I4Ent48;
typedef struct {
    s32 w;
    s32 pad[14];
} I4Ent60;
typedef struct {
    s32 w;
    s32 pad[4];
} I4Ent20;

extern Gfx D_80A6DB0[];
extern u16 D_80A3DD8[];
extern I4Label D_i4_802C7630[];
extern I4Label D_i4_802C7650[];
extern s32 D_i4_802C7660[];
extern s32 D_800DAA10[];
extern I4Ent48 D_801C26E8[];
extern I4Ent60 D_801C1FF0[];
extern I4Ent20 D_801C22C0[];
extern I4Ent20 D_801C23B0[];

Gfx* func_i4_802C6778(Gfx* gdl);
Gfx* func_i4_802C69C4(Gfx* gdl, s32 arg1, s32 arg2);
Gfx* func_801E9858(Gfx*, s32, char*, s32, s32);
Gfx* func_801E8B24(Gfx*, s32, s32, s32, s32);

/* Course select screen: preview scene, menu frames, course list, record time
 * and difficulty list. The pad[] reproduces the 0xD8 frame (off/base homes at
 * 0xCC/0xC8, y spill at 0x58). The nested `if (flag) { if (i == sel) ... }`
 * color picks and the I4Label cursors initialised in the for headers are what
 * give the target's branch skeleton and loop preheaders. */
Gfx* func_i4_802C5CDC(Gfx* gdl) {
    s32 i;
    s32 color;
    s32 off;
    s32 base;
    s32 pad[27];
    s32 y;
    s32 k;
    s32 tex;
    s32 h;
    I4Label* p;

    gSPDisplayList(gdl++, D_80A6DB0);
    gDPFillRectangle(gdl++, 150, 53, 291, 158);
    gdl = func_i4_802C6778(gdl);
    if (D_i4_802C7540 != 0) {
        gSPDisplayList(gdl++, D_80A6DB0);
        gDPFillRectangle(gdl++, D_802C76B4 + 8, D_802C76B8 + 0x14, D_802C76B4 + D_802C76BC + 7,
                         D_802C76B8 + D_802C76C0 + 0x13);
    }
    gSPDisplayList(gdl++, D_106F628);
    gdl = Menu_DrawFrame(gdl, 0, 0x1C, 0x18, 0x108, 0x18);
    if (D_801CE608.gameMode == 11) {
        gdl = Menu_DrawFrame(gdl, 0, 0xAB, 0xB9, 0x65, 0xA);
        gdl = Menu_DrawFrame(gdl, 0, 0xAB, 0xC5, 0x65, 0x10);
    } else {
        gdl = Menu_DrawFrame(gdl, 0, 0xAB, 0xA1, 0x65, 0xC);
        gdl = Menu_DrawFrame(gdl, 0, 0xAB, 0xAE, 0x65, 0xC);
        gdl = Menu_DrawFrame(gdl, 0, 0xAB, 0xBC, 0x65, 0xC);
        gdl = Menu_DrawFrame(gdl, 0, 0xAB, 0xC9, 0x65, 0xC);
    }
    for (y = 0x35; y < 0xD7; y += 0x12) {
        gdl = Menu_DrawFrame(gdl, 0, 0x1C, y, 0x76, 0x10);
    }

    if (D_i4_802C7548 != 0) {
        switch (D_802C76C8) {
            case 0:
            case 1:
                gdl = func_i4_802C69C4(gdl, 0xA2, 0x49);
                break;
            case 2:
            case 3:
                gdl = func_i4_802C69C4(gdl, 0xA2, 0x37);
                for (tex = 0, k = 0, y = 0x7C; y != 0x9E; y += 0x11, k += 0x11, tex += 0x7D6) {
                    if (y != 0x8D) {
                        h = 0x11;
                    } else {
                        h = 0x10;
                    }
                    gDPLoadTextureTile(gdl++, D_80A3DD8 + tex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 118, h, 0, 0, 117, h - 1,
                                       0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    gSPTextureRectangle(gdl++, 0xA2 << 2, y << 2, (0xA2 + 0x76) << 2, (k + h + 0x7C) << 2,
                                        G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                }
                break;
        }
    }

    gdl = func_801E946C(gdl, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    gdl = func_801E3EE0(gdl, 2, 4, 0x40, 0x1B, 0);
    if (D_801CE608.gameMode == 11) {
        gdl = func_801E3EE0(gdl, 0, 0x1E, 0xBF, 0xBA, 0);
        gdl = Font_DrawDecimal(gdl, 2, D_801C26E8[D_800DAAD8[D_800DA9D0]].w, 0xBF, 0xC8);
    } else {
        gdl = func_801E3EE0(gdl, 0, 0xE, 0xC3, 0xA3, 0);
        gdl = func_801E3EE0(gdl, 0, 0xD, 0xC5, 0xBE, 0);
        if ((D_i4_802C754C == 3) && (D_i4_802C7548 != 0)) {
            gdl = func_801E9858(func_801E8B24(gdl, 1, D_801C23B0[D_800DAAD8[D_800DA9D0]].w, 0xC3, 0xB0), 1,
                                "-'--@---", 0xC3, 0xCB);
        } else {
            gdl = func_801E8B24(func_801E8B24(gdl, 1, D_801C1FF0[D_800DAAD8[D_800DA9D0]].w, 0xC3, 0xB0), 1,
                                D_801C22C0[D_800DAAD8[D_800DA9D0]].w, 0xC3, 0xCB);
        }
    }

    for (i = 0; i < 9; i++) {
        if (i == D_800DA9D0) {
            color = 6;
        } else if (D_i4_802C7558[D_800DAAD8[i]] != 0) {
            color = 0;
        } else {
            color = 7;
        }
        gdl = func_801E946C(gdl, color, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gdl = func_801E3EE0(gdl, 1, D_800DAA10[D_800DAAD8[i]], D_i4_802C7660[D_800DAAD8[i]] + 0x30, i * 0x12 + 0x38,
                            0);
    }

    if (D_i4_802C7548 != 0) {
        off = 0;
        if (D_801CE60C == 1) {
            if (D_802C76C4 != 0) {
                off = -6;
            }
            base = 0x41;
        } else {
            if (D_802C76C4 != 0) {
                off = -8;
            }
            base = 0x2F;
            gdl = func_801E946C(gdl, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            gdl = func_801E3EE0(gdl, 0, 0x20, 0xC3, 0x80, 0);
            for (i = 0, p = D_i4_802C7650; i != 2; i++, p++) {
                if (D_i4_802C7554 != 0) {
                    if (i == D_800DAA04) {
                        color = 6;
                    } else {
                        color = 0;
                    }
                } else {
                    color = 0;
                }
                gdl = func_801E946C(gdl, color, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                gdl = func_801E3EE0(gdl, 1, p->id, p->x + 0xC1, 0x8F - i, 0);
            }
        }
        for (i = 0, p = D_i4_802C7630; i < D_802C76D0; i++, p++) {
            if (D_i4_802C7550 != 0) {
                if (i == D_i4_802C754C) {
                    color = 6;
                } else if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][i] == 0) {
                    color = 7;
                } else {
                    color = 0;
                }
            } else {
                if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][i] == 0) {
                    color = 7;
                } else {
                    color = 0;
                }
            }
            gdl = func_801E946C(gdl, color, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            gdl = func_801E3EE0(gdl, 1, p->id, p->x + 0xC2, base + off + 0x14 + i * 0xF,
                                0);
        }
    }
    return gdl;
}

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

extern s32 D_i4_802C7544;
extern s32 D_802C76CC;

/* Course select input. The chained `D_802C76CC = D_i4_802C754C = i` store is
 * load-bearing: its extra temp shifts ugen's t-register queue for the whole
 * function. The skip loops use the same `for (;;) { if (...) break; }` shape
 * as func_i4_802C70C0. */
void func_i4_802C6C2C(void) {
    s32 i;

    if (D_801CE65A[D_802C76B0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        D_800D8240 = 0;
        if (D_801CE608.gameMode == 11) {
            func_i4_802C7474(0x28);
            AudioGeneral_PlaySound(0x37, 0);
        } else {
            D_i4_802C7538 = 1;
            D_i4_802C753C = 0;
            D_i4_802C7540 = 0;
            D_i4_802C7544 = 1;
            D_i4_802C7550 = 1;
            for (i = 0; i < 4; i++) {
                if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][i] != 0) {
                    break;
                }
            }
            D_802C76CC = D_i4_802C754C = i;
            AudioGeneral_PlaySound(0x11, 0);
        }
    } else if (D_801CE65A[D_802C76B0].unk0 & B_BUTTON) {
        func_i4_802C7474(10);
        AudioGeneral_PlaySound(0x16, 0);
    } else if (D_801CE65A[D_802C76B0].unk0 & U_JPAD) {
        if (--D_800DA9D0 < D_802C76A4) {
            D_800DA9D0 = 8;
        }
        for (;;) {
            if (D_i4_802C7558[D_800DAAD8[D_800DA9D0]] != 0) {
                break;
            }
            if (--D_800DA9D0 < D_802C76A4) {
                D_800DA9D0 = 8;
            }
        }
        if (D_800DA9D0 != D_802C76A8) {
            D_i4_802C7530 = 1;
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A[D_802C76B0].unk0 & D_JPAD) {
        if (++D_800DA9D0 >= 9) {
            D_800DA9D0 = D_802C76A4;
        }
        for (;;) {
            if (D_i4_802C7558[D_800DAAD8[D_800DA9D0]] != 0) {
                break;
            }
            if (++D_800DA9D0 >= 9) {
                D_800DA9D0 = D_802C76A4;
            }
        }
        if (D_800DA9D0 != D_802C76A8) {
            D_i4_802C7530 = 1;
            AudioGeneral_PlaySound(0x10, 0);
        }
    }
    SysUtils_Rand();
}

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

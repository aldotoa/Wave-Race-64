#include "global.h"

extern s32 D_80223938;
extern s32 D_802C7028;
extern s32 D_i3_802C6F88;
extern s32 D_i3_802C6F84;
extern s32 D_802C702C;
extern enum Course D_801CB330;

void func_801EB91C(void);
void func_i3_802C5AE8(void);
void func_i3_802C5AF0(void);
Gfx* func_i3_802C5D54(Gfx*);
Gfx* func_i3_802C6344(Gfx*);
void func_i3_802C6E9C(void);

extern s32 D_801CE704;

/* Course-overview entry: resets the per-race score tables when re-entering
 * the same rank, picks the demo branch (D_802C7028) and computes the rank
 * thresholds into D_801CE708[], then dispatches to the 5AE8/5AF0 setup.
 * `need` is reloaded inside the rank loop; hoisting it out swaps a2/a3. */
extern s32 D_801CE704;
extern s32 D_801CE708[];
extern s32 D_801CB334;
extern s32 D_801CB340[];
extern s32 D_801CB350[][4];
extern s32 D_801CB3D0[];
extern s32 D_801CE718[];
extern s32 D_802C7020;
extern s32 D_i3_802C6F8C;
extern s32 D_i3_802C6FE4[];
extern const s16 D_800EABB0[];
extern const s16 D_800EABBC[][8];
extern u8 D_800E9AB0[];
extern void *D_800DAAB4[];
extern RiderStruct D_801C2C70[];

void func_i3_802C5800(void) {
    s32 i;
    s32 j;
    s32 need;

    if ((D_801CE63C != 0) && (gGameState == 0x1E)) {
        if (D_801CB334 == D_i3_802C6FE4[gDifficulty]) {
            for (i = 0; i < 8; i++) {
                j = 0;
                do {
                    D_801CB350[i][j] = 0;
                    j++;
                } while (j < 4);
                D_801CB3D0[i] = 0;
            }
            i = 0;
            do {
                D_801CB340[i] = 0;
                i++;
            } while (i < 4);
            i = 0;
            do {
                D_801C2C70[i].lapCount = 0;
                i++;
            } while (i < 4);
        }
        D_802C7028 = 1;
        D_i3_802C6F84 = 0;
        if (gDifficulty == DIFFICULTY_NORMAL) {
            if (D_801CB334 == 1) {
                D_802C7028 = 0;
                D_802C702C = 0xF0;
            } else {
                D_802C702C = 0xB4;
            }
        } else if (D_801CB334 == 0) {
            D_802C7028 = 0;
            D_802C702C = 0xF0;
        } else {
            D_802C702C = 0xB4;
        }
        if (D_801CB330 == 0) {
            D_802C7020 = 0;
            for (i = 0; i < 4; i++) {
                D_801CE708[i] = 4;
            }
            D_801CE704 = D_801CE708[D_800D48DC];
        } else {
            for (i = 0; i < 4; i++) {
                need = D_800EABBC[gDifficulty][D_801CB334];
                D_802C7020 = need - D_801CB340[i];
                for (j = 1; j < 5; j++) {
                    if (D_800EABB0[j] < D_802C7020) {
                        break;
                    }
                }
                D_801CE708[i] = j - 1;
            }
            D_801CE704 = D_801CE708[D_800D48DC];
        }
        func_80069740((UnkStruct_80069740 *) &D_80198310, (UnkStruct_80069740 *) D_800DAAB4[gCourseID]);
        func_8006977C(&D_80198350, (s32) D_800E9AB0);
        if (D_800DAB68 != 0) {
            D_i3_802C6F8C = 2;
        } else {
            D_i3_802C6F8C = 0;
        }
    }
    switch (D_802C7028) {
    case 0:
        func_i3_802C5AE8();
        break;
    case 1:
        func_i3_802C5AF0();
        break;
    }
}

void func_i3_802C5AE8(void) {
}

void func_i3_802C5AF0(void) {
    func_80069798(D_801CE5F8->unkA80, D_801CE5F8->unk1780, D_801CE5F8->unkA40, &D_802C7024, &D_80198310, &D_80198350);
}

Gfx* func_i3_802C5B40(Gfx* arg0) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 30) {
            return Gfx_ClearFrameBuffers(arg0);
        }
    }

    D_800DAB2C = 0;
    arg0 = Game_BuildRaceScene(arg0);

    if (D_80223938 != 0) {
        switch (D_802C7028) {
            case 0:
                arg0 = func_i3_802C5D54(arg0);
                break;
            case 1:
                arg0 = func_i3_802C6344(arg0);
                break;
        }
    }

    gSPDisplayList(arg0++, D_106F168);

    if (gGameState == 30) {
        if (D_i3_802C6F88 != 0) {
            D_i3_802C6F88 = 0;
            func_801EB91C();
        } else {
            if (D_801CE692->unk0 & 0xB000) {
                if (D_i3_802C6F84 != 0) {
                    func_i3_802C6E9C();
                }
            } else if ((D_80223938 != 0) && (D_801CE644 >= D_802C702C)) {
                func_i3_802C6E9C();
            }
            SysUtils_Rand();
        }
    } else {
        if (D_801CE644 >= 0) {
            D_801CE644--;
        }
        if (D_801CE644 == 0) {
            func_800C1F60(7);
        }
        if (D_80228A16 == 1) {
            gCourseID = D_801CB330;
            Game_EnterGameplay();
        }
    }

    if (D_801CE638 != 8) {
        func_800AD3C4();
    }

    if (gGameState == 30) {
        D_801CE644++;
    }

    return arg0;
}

/* Fade-in/out state machine for the two title frames (D_i3_802C6F64 0..3),
 * then draws the frames and the difficulty label. The chained stores and the
 * low-byte reads through &D_i3_802C6F6C/&D_i3_802C6F78 are load-bearing: they
 * decide which global addresses IDO keeps in registers. */
extern s32 D_i3_802C6F64;
extern s32 D_i3_802C6F68;
extern s32 D_i3_802C6F6C;
extern s32 D_i3_802C6F70;
extern s32 D_i3_802C6F74;
extern s32 D_i3_802C6F78;
extern s32 D_i3_802C6F7C;
extern s16 D_800DAB68;

typedef struct {
    s16 x;
    s16 pad2;
    s32 id;
} I3Entry;

extern I3Entry D_i3_802C6FB4[];
extern I3Entry D_i3_802C6FCC;

Gfx* func_i3_802C5D54(Gfx* gfx) {
    I3Entry* e;
    s32 t;
    s32 u;

    switch (D_i3_802C6F64) {
        case 0:
            if (++D_i3_802C6F68 >= 5) {
                D_i3_802C6F64 = 1;
                D_i3_802C6F68 = D_i3_802C6F74 = 0;
            }
            D_i3_802C6F6C = D_i3_802C6F78 = 0;
            D_i3_802C6F70 = D_i3_802C6F7C = 0;
            break;
        case 1:
            t = ++D_i3_802C6F68;
            if (t >= 20) {
                D_i3_802C6F74++;
            }
            if (t >= 10) {
                D_i3_802C6F6C = 255;
                D_i3_802C6F70 = 170;
            } else {
                D_i3_802C6F6C = (t * 255) / 10;
                D_i3_802C6F70 = (t * 170) / 10;
            }
            u = D_i3_802C6F74;
            if (u >= 10) {
                D_i3_802C6F78 = 255;
                D_i3_802C6F7C = 170;
            } else {
                D_i3_802C6F78 = (u * 255) / 10;
                D_i3_802C6F7C = (u * 170) / 10;
            }
            if ((t >= 10) && (u >= 10)) {
                D_i3_802C6F64 = 2;
                D_i3_802C6F6C = D_i3_802C6F78 = 255;
                D_i3_802C6F70 = D_i3_802C6F7C = 170;
                D_i3_802C6F68 = D_i3_802C6F74 = 0;
            }
            break;
        case 2:
            if (++D_i3_802C6F68 >= 25) {
                D_i3_802C6F64 = 3;
                D_i3_802C6F68 = D_i3_802C6F74 = 0;
            }
            D_i3_802C6F6C = D_i3_802C6F78 = 255;
            D_i3_802C6F70 = D_i3_802C6F7C = 170;
            break;
        case 3:
            t = ++D_i3_802C6F68;
            if (t >= 10) {
                D_i3_802C6F64 = 0;
                D_i3_802C6F68 = 0;
                D_i3_802C6F6C = 0;
                D_i3_802C6F70 = 0;
                D_802C7028 = 1;
            } else {
                u = 10 - t;
                D_i3_802C6F6C = (u * 255) / 10;
                D_i3_802C6F70 = (u * 170) / 10;
            }
            D_i3_802C6F78 = D_i3_802C6F6C;
            D_i3_802C6F7C = D_i3_802C6F70;
            break;
    }

    gSPDisplayList(gfx++, D_106F628);
    gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, D_i3_802C6F70);
    gfx = Menu_DrawFrame(gfx, 2, 0x20, 0x4B, 0x100, 0x20);
    gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, D_i3_802C6F7C);
    gfx = Menu_DrawFrame(gfx, 0, 0x20, 0x85, 0x100, 0x20);
    gfx = func_801E946C(gfx, 10, *((u8*)&D_i3_802C6F6C + 3), 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    gfx = func_801E3EE0(gfx, 2, 0x22, 0x48, 0x51, 0);
    gfx = func_801E946C(gfx, 10, *((u8*)&D_i3_802C6F78 + 3), 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    if (D_800DAB68 != 0) {
        e = &D_i3_802C6FCC;
    } else {
        e = &D_i3_802C6FB4[gDifficulty];
    }
    gfx = func_801E3EE0(gfx, 2, e->id, e->x + 0x32, 0x8B, 0);
    return gfx;
}

/* Course-select info panel: fade (D_i3_802C6F64 0..1), frames, course name,
 * difficulty/rank labels, preview texture and the course model.
 * PARKED at 390 rows (scratch/ovl_i3/probe.py; an earlier 325 used a wrong
 * flat D_800EABBC index). Load-bearing: high-level gbi
 * macros (gDPLoadTextureBlock IA/8b 64x22, gSPTextureRectangle) give the 0x68
 * frame; this local declaration order lands var_t4/sp48/sp50 at 0x40/0x48/0x50;
 * D_802C7024 read as u16 (lhu). Open puzzle: the target divides by 20 twice
 * with `li at,20; div` (no zero checks) but IDO always CSEs the 20 into a
 * register here (every spelling tried, incl. labels, casts, -O1). */
#ifdef NON_MATCHING
extern s32 D_i3_802C6F64;
extern s32 D_i3_802C6F68;
extern s32 D_i3_802C6F6C;
extern s32 D_i3_802C6F70;
extern s32 D_i3_802C6F80;
extern s32 D_i3_802C6F8C;
extern u8 D_i3_802C6F6F;
extern s32 D_i3_802C6FD4[];
extern s32 D_i3_802C6F50[];
extern s32 D_i3_802C6F90[];
extern s32 D_800DB5B0[];
extern s32 D_800DB5F8[];
extern s32 D_800DB640[];
extern s32 D_800DB688[];
extern s32 D_800DB718[];
extern s32 D_801CB340[];
extern s32 D_801C1FF0[];
extern s32 D_801C22C0[];
extern s32 D_801C23B0[];
extern s32 D_804E418[];
extern s32 D_804E4E0[];
extern s32 D_106F728[];
extern s32 D_106F748[];
extern s32 D_7000A40[];
extern s32 D_801CB334;
extern char D_i3_802C6FF0[];
extern char D_i3_802C6FFC[];
extern char D_i3_802C7008[];
Gfx* func_801E9858(Gfx*, s32, char*, s32, s32);
Gfx* func_801E8B24(Gfx*, s32, s32, s32, s32);
Gfx* func_801EB00C(Gfx*, s32, s32, s32, s32);

Gfx* func_i3_802C6344(Gfx* gfx) {
    s32 courseOff;
    s32 u2;
    s32 t2;
    s32 idx;
    s32 u0;
    s32 sp50;
    s32 u1;
    s32 sp48;
    s32* t5;
    s32* var_t4;

    sp50 = D_i3_802C6FD4[gDifficulty];
    switch (D_i3_802C6F64) {
    case 0:
        if ((D_i3_802C6F68 = D_i3_802C6F68 + 1) >= 0x14) {
            D_i3_802C6F64 = 1;
            D_i3_802C6F68 = 0;
        }
        D_i3_802C6F6C = 0;
        D_i3_802C6F70 = 0;
        break;
    case 1:
        if (++D_i3_802C6F68 >= 0x14) {
            D_i3_802C6F64 = 2;
            D_i3_802C6F68 = 0;
            D_i3_802C6F6C = 0xFF;
            D_i3_802C6F70 = 0xAA;
            D_i3_802C6F80 = 1;
            D_i3_802C6F84 = 1;
        } else {
            D_i3_802C6F6C = (D_i3_802C6F68 * 0xFF) / 20;
            D_i3_802C6F70 = (D_i3_802C6F68 * 0xAA) / 20;
        }
        break;
    }

    gSPDisplayList(gfx++, D_106F628);
    gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, D_i3_802C6F70);

    gfx = Menu_DrawFrame(gfx, 0, 0x1C, 0x1E, 0x108, 0x18);
    gfx = Menu_DrawFrame(gfx, 0, 0xBB, 0x3C, 0x69, 0xC);
    gfx = Menu_DrawFrame(gfx, 0, 0xBB, 0x56, 0x69, 0xC);
    gfx = Menu_DrawFrame(gfx, 0, 0xBB, 0x63, 0x69, 0x16);
    gfx = Menu_DrawFrame(gfx, 0, 0xBB, 0x86, 0x69, 0xC);
    gfx = Menu_DrawFrame(gfx, 0, 0xBB, 0x93, 0x69, 0x16);
    gfx = Menu_DrawFrame(gfx, 0, 0x1C, 0xB0, 0xBF, 0x22);
    gfx = Menu_DrawFrame(gfx, 0, 0xDE, 0xB0, 0x46, 0x22);

    gSPDisplayList(gfx++, D_804E4E0);
    gfx = func_801E946C(func_801E7C58(gfx, 0x1F, 0x3F, 0xB4, 0xA7, 0, 0, 0, (u32)D_i3_802C6F70), 0xA,
                        D_i3_802C6F6F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    idx = D_801CB334;
    if (gDifficulty == DIFFICULTY_NORMAL) {
        idx -= 1;
    }
    if (D_801CB330 == 0) {
        sp48 = -0x21;
    } else if (idx >= 0) {
        if (sp50 == D_801CB334) {
            idx = 8;
            sp48 = 0x16;
        } else {
            sp48 = 0;
        }
        gfx = func_801E3EE0(gfx, 1, D_i3_802C6F90[idx], 0x25, 0x25, 1);
    }
    gfx = func_801E3EE0(gfx, 2, D_800DAA34[D_801CB330], sp48 + 0x67, 0x21, 0);
    gfx = func_801E3EE0(gfx, 0, 0x16, 0xC3, 0x3E, 0);
    gfx = func_801E3EE0(gfx, 0, 0xE, 0xD4, 0x58, 0);
    gfx = func_801E3EE0(gfx, 0, 0xD, 0xD4, 0x88, 0);
    gfx = func_801E3EE0(gfx, 1, 6, 0x22, 0xB5, 0);
    gfx = func_801E3EE0(gfx, 1, 7, 0x22, 0xC2, 0);

    if (D_801CB330 == 0) {
        gfx = func_801E9858(func_801E9858(gfx, 2, D_i3_802C6FF0, 0xCB, 0x69), 2, D_i3_802C6FFC, 0xCB, 0x99);
    } else if (D_800DAB68 != 0) {
        gfx = func_801E9858(func_801E8B24(gfx, 2, D_801C23B0[D_801CB330 * 5], 0xCB, 0x69), 2, D_i3_802C7008, 0xCB, 0x99);
    } else {
        gfx = func_801E8B24(func_801E8B24(gfx, 2, D_801C1FF0[D_801CB330 * 15], 0xCB, 0x69), 2, D_801C22C0[D_801CB330 * 5], 0xCB, 0x99);
    }
    gfx = func_801EB00C(gfx, 2, D_801CB340[D_800D48DC], 0xCA, 0xC2);
    if (D_i3_802C6FE0 != 0) {
        gfx = func_801E946C(gfx, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    } else {
        gfx = func_801E946C(gfx, 0xA, D_i3_802C6F6F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    gfx = func_801EB00C(gfx, 2, D_800EABBC[gDifficulty][D_801CB334], 0xCA, 0xB5);

    gDPLoadTextureBlock(gfx++, D_i3_802C6F50[D_801CE704], G_IM_FMT_IA, G_IM_SIZ_8b, 64, 22, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gfx++, 900, 728, 1156, 816, G_TX_RENDERTILE, 0, 0, 1024, 1024);

    courseOff = gCourseID * 8;
    t5 = (s32*)((u8*)D_800DB5B0 + courseOff);
    t2 = 1;
    if (D_i3_802C6F8C == 0) {
        var_t4 = (s32*)((u8*)D_800DB5F8 + courseOff);
        if (gCourseID == DOLPHIN_PARK) {
            t2 = 0;
        } else if (gCourseID == PORT_BLUE) {
            if (gDifficulty == DIFFICULTY_EXPERT) {
                var_t4 = (s32*)((u8*)D_800DB640 + courseOff);
            } else if (gDifficulty == DIFFICULTY_HARD) {
                var_t4 = (s32*)((u8*)D_800DB688 + courseOff);
            }
        } else if (gCourseID == MARINE_FORTRESS && (gDifficulty == DIFFICULTY_HARD || gDifficulty == DIFFICULTY_EXPERT)) {
            var_t4 = (s32*)((u8*)D_800DB640 + courseOff);
        }
    } else if (D_i3_802C6F8C == 2) {
        var_t4 = (s32*)((u8*)D_800DB718 + courseOff);
        if (gCourseID == DOLPHIN_PARK) {
            t2 = 0;
        }
    }

    gSPDisplayList(gfx++, D_804E418);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_PHYSICAL_TO_K0(gFrameBuffers[gFramebuffersIdx]));
    gSPPerspNormalize(gfx++, *(u16*)&D_802C7024);
    gSPMatrix(gfx++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_801CE5F8->unkA80, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPViewport(gfx++, D_106F728);
    gSPDisplayList(gfx++, D_106F748);
    gDPSetEnvColor(gfx++, 0xFF, 0xFF, 0xFF, D_i3_802C6F6C);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 31, 63, 180, 167);
    if (D_i3_802C6F80 == 0) {
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    }
    if (t2 != 0) {
        gSPClearGeometryMode(gfx++, G_LIGHTING);
        gSPDisplayList(gfx++, var_t4[0] + 0x50000);
    }
    gSPSetGeometryMode(gfx++, G_LIGHTING);
    gSPDisplayList(gfx++, t5[0] + 0x50000);
    if (D_i3_802C6F80 != 0) {
        gDPPipeSync(gfx++);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    }
    if (t2 != 0) {
        gSPClearGeometryMode(gfx++, G_LIGHTING);
        gSPDisplayList(gfx++, var_t4[1] + 0x50000);
    }
    gSPSetGeometryMode(gfx++, G_LIGHTING);
    gSPDisplayList(gfx++, t5[1] + 0x50000);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, 319, 239);
    return gfx;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C6344.s")
#endif

void func_i3_802C6E9C(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 31;
    D_801CE638 = 8;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 20;
    D_800DAB1C = 0;
    D_800D461C = 3;

    D_i3_802C6FE0 = 1;

    FadeTransition_SetProps(5, 0, 20);
    func_801E6A4C(0, 0);
    AudioGeneral_PlaySound(58, 0);
}

#include "common.h"

extern s32 D_802C6B30;
extern s32 D_802C6B34;
extern s32 D_802C6B40[];
extern s32 D_i10_802C6B14;
extern s32 D_i10_802C6B10;
extern s32 D_802C6B38;
extern s32 D_801CB308[][3];
extern s32 D_800DA988[][3];
extern UnkStruct_801CE658 D_801CE658[];
extern Mtx D_7000000[];
extern Mtx D_2000A40[];
extern Gfx D_106F550[];

typedef struct {
    s16 x;
    s32 id;
} Label_802C6AA0;

typedef struct {
    s32 min;
    s32 max;
} Limit_802C6AF8;

extern Label_802C6AA0 D_i10_802C6AA0[];
extern s32 D_i10_802C6AC8[];
extern s32 D_i10_802C6AD4[];
extern s32 D_i10_802C6AE4[];
extern Limit_802C6AF8 D_i10_802C6AF8[];

Gfx* func_801E9858(Gfx*, s32, char*, s32, s32);
void func_i10_802C6A00(s32 arg0);

void func_i10_802C5800(void) {
    s32 i;

    if (D_801CE63C != 0) {
        if (gGameState == GAME_STATE_OPTIONS_CHANGE_CONDITIONS) {
            for (i = 0; i < 6; i++) {
                D_802C6B40[i] = 0;
            }
            /* The chained assignment preserves IDO's register allocation. */
            D_802C6B40[3] = D_802C6B40[4] = 1;
            if (D_801CB280 & 1) {
                D_802C6B40[0] = 1;
            }
            if (D_801CB280 & 2) {
                D_802C6B40[1] = 1;
            }
            if (D_801CB280 & 4) {
                D_802C6B40[2] = 1;
            }
            for (i = 0; i < 5; i++) {
                if (D_802C6B40[i]) {
                    break;
                }
            }
            if (i == 3) {
                D_802C6B30 = 1;
                D_802C6B34 = 1;
            } else {
                D_802C6B30 = i % 3;
                D_802C6B34 = i / 3;
            }
            D_i10_802C6B14 = 0;
            for (i = 0; i < 3; i++) {
                if (D_802C6B40[i]) {
                    D_i10_802C6B14++;
                }
            }
            if (!D_i10_802C6B14) {
                D_802C6B40[3] = 0;
            }
        }
    }
}

Gfx* func_i10_802C5968(Gfx* gfxP) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 68) {
            return Gfx_ClearFrameBuffers(gfxP);
        }
    }

    D_800DAB2C = 0;

    gfxP = func_i10_802C6200(gfxP);

    if (gGameState == 68) {
        func_i10_802C5A10();
    } else if (D_80228A16 == 1) {
        func_8007C50C();
        func_801EC304();
    }

    return gfxP;
}

void func_i10_802C5A10(void) {
    s32 i;
    s32 j;
    s32 sound = 0;
    s32* val;
    Limit_802C6AF8* lim;

    if (D_801CE658[2].unk_00.unk_2 & 0xB000) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                i = D_802C6B34 * 3 + D_802C6B30;
                if (i == 4) {
                    func_i10_802C6A00(0x3C);
                } else if (i == 3) {
                    for (i = 0; i < 3; i++) {
                        for (j = 0; j < 3; j++) {
                            D_801CB308[i][j] = D_800DA988[i][j];
                        }
                    }
                } else {
                    D_801CE640 = 1;
                    D_802C6B38 = 0;
                }
                break;
            case 1:
                D_801CE640 = 2;
                sound = 1;
                D_802C6B38 = 1;
                break;
            case 2:
                D_801CE640 = 3;
                sound = 1;
                D_802C6B38 = 2;
                break;
            case 3:
                sound = 1;
                D_801CE640 = 0;
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x11, 0);
        }
    } else if (D_801CE658[2].unk_00.unk_2 & 0x4000) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                func_i10_802C6A00(0x3C);
                break;
            case 1:
                D_801CE640 = 0;
                sound = 1;
                D_802C6B38 = 0;
                break;
            case 2:
                D_801CE640 = 1;
                sound = 1;
                D_802C6B38 = 0;
                break;
            case 3:
                D_801CE640 = 2;
                sound = 1;
                D_802C6B38 = 1;
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x16, 0);
        }
    } else if (D_801CE658[0].unk_00.unk_2 & 0x800) {
        if (D_801CE640 == 0) {
            sound = 1;
            if (D_802C6B34 == 1 && D_i10_802C6B10 != -1) {
                D_802C6B30 = D_i10_802C6B10;
            }
            if (D_i10_802C6B14 == 1 && D_802C6B34 == 1) {
                D_802C6B30 = 0;
            } else if (D_i10_802C6B14 == 3 && D_802C6B34 == 0 && D_802C6B30 == 2) {
                D_802C6B30 = 1;
            }
            D_802C6B34--;
            if (D_802C6B34 < 0) {
                D_802C6B34 = 1;
            }
            for (;;) {
                i = D_802C6B34 * 3 + D_802C6B30;
                if (D_802C6B40[i]) {
                    break;
                }
                D_802C6B34--;
                if (D_802C6B34 < 0) {
                    D_802C6B34 = 1;
                }
            }
            if (D_802C6B34 == 1) {
                if (D_i10_802C6B14 == 3) {
                    D_i10_802C6B10 = D_802C6B30;
                }
                if (D_i10_802C6B14 == 3 && D_802C6B30 == 2) {
                    D_802C6B30 = 1;
                }
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE658[0].unk_00.unk_2 & 0x400) {
        if (D_801CE640 == 0) {
            sound = 1;
            if (D_802C6B34 == 1 && D_i10_802C6B10 != -1) {
                D_802C6B30 = D_i10_802C6B10;
                D_i10_802C6B10 = -1;
            }
            if (D_i10_802C6B14 == 1 && D_802C6B34 == 1) {
                D_802C6B30 = 0;
            } else if (D_i10_802C6B14 == 3 && D_802C6B34 == 0 && D_802C6B30 == 2) {
                D_802C6B30 = 1;
            }
            D_802C6B34++;
            if (D_802C6B34 >= 2) {
                D_802C6B34 = 0;
            }
            for (;;) {
                i = D_802C6B34 * 3 + D_802C6B30;
                if (D_802C6B40[i]) {
                    break;
                }
                D_802C6B34++;
                if (D_802C6B34 >= 2) {
                    D_802C6B34 = 0;
                }
            }
            if (D_802C6B34 == 1) {
                if (D_i10_802C6B14 == 3) {
                    D_i10_802C6B10 = D_802C6B30;
                }
                if (D_i10_802C6B14 == 3 && D_802C6B30 == 2) {
                    D_802C6B30 = 1;
                }
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE658[0].unk_00.unk_2 & 0x200) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                D_802C6B30--;
                if (D_802C6B30 < 0) {
                    if (D_802C6B34 == 0) {
                        D_802C6B30 = 2;
                    } else {
                        D_802C6B30 = 1;
                    }
                }
                for (;;) {
                    i = D_802C6B34 * 3 + D_802C6B30;
                    if (D_802C6B40[i]) {
                        break;
                    }
                    D_802C6B30--;
                    if (D_802C6B30 < 0) {
                        if (D_802C6B34 == 0) {
                            D_802C6B30 = 2;
                        } else {
                            D_802C6B30 = 1;
                        }
                    }
                }
                D_i10_802C6B10 = -1;
                break;
            case 1:
            case 2:
            case 3:
                i = D_802C6B34 * 3 + D_802C6B30;
                lim = &D_i10_802C6AF8[D_802C6B38];
                val = &D_801CB308[i][D_802C6B38];
                sound = 1;
                if (--*val < lim->min) {
                    *val = lim->max;
                }
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE658[0].unk_00.unk_2 & 0x100) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                D_802C6B30++;
                if (D_802C6B34 == 0) {
                    if (D_802C6B30 >= 3) {
                        D_802C6B30 = 0;
                    }
                } else if (D_802C6B30 >= 2) {
                    D_802C6B30 = 0;
                }
                for (;;) {
                    i = D_802C6B34 * 3 + D_802C6B30;
                    if (D_802C6B40[i]) {
                        break;
                    }
                    D_802C6B30++;
                    if (D_802C6B34 == 0) {
                        if (D_802C6B30 >= 3) {
                            D_802C6B30 = 0;
                        }
                    } else if (D_802C6B30 >= 2) {
                        D_802C6B30 = 0;
                    }
                }
                D_i10_802C6B10 = -1;
                break;
            case 1:
            case 2:
            case 3:
                i = D_802C6B34 * 3 + D_802C6B30;
                lim = &D_i10_802C6AF8[D_802C6B38];
                val = &D_801CB308[i][D_802C6B38];
                sound = 1;
                if (lim->max < ++*val) {
                    *val = lim->min;
                }
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    }
}

Gfx* func_i10_802C6200(Gfx* gfxP) {
    /* Options "change conditions" menu display list: frames, title, the five
       toggle labels (cursor = D_802C6B34 * 3 + D_802C6B30), and for selections
       0-2 the three per-setting rows with their current values, plus a
       "changed from default" notice.
       Load-bearing: the 12 locals in this order (incl. the two unused words)
       fix the 0xD0 frame (sel@0xB0, id@0xB8, buf@0x94); the -1 fallbacks must
       be if/else into the named idx, not ?: (?: adds a hidden temp stack
       word); colour else-arms must be if/else, not `color = 0; if () 7`. */
    Label_802C6AA0* lab;
    s32* val;
    s32 i;
    s32 color;
    s32 useStr;
    s32 id;
    s32 changed;
    s32 sel;
    s32 unused1;
    s32 unused2;
    s32 idx;
    char buf[16];

    gSPMatrix(gfxP++, D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfxP++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfxP++, D_106F550);
    gSPDisplayList(gfxP++, D_106F628);

    for (i = 0; i < 3; i++) {
        gfxP = Menu_DrawFrame(gfxP, 0, i * 0x59 + 0x1C, 0x45, 0x56, 0x10);
    }
    gfxP = Menu_DrawFrame(gfxP, 0, 0xA4, 0x5A, 0x56, 0x10);
    gfxP = Menu_DrawFrame(gfxP, 0, 0x46, 0x5A, 0x56, 0x10);
    for (i = 0; i < 3; i++) {
        gfxP = Menu_DrawFrame(gfxP, 0, 0x1C, i * 0x14 + 0x7D, 0x9C, 0x10);
        gfxP = Menu_DrawFrame(gfxP, 0, 0xBB, i * 0x14 + 0x7C, 0x69, 0x10);
    }
    gfxP = func_801E946C(gfxP, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    gfxP = func_801E3EE0(gfxP, 2, 0x10, 0x26, 0x27, 0);

    sel = D_802C6B34 * 3 + D_802C6B30;
    for (i = 0, lab = D_i10_802C6AA0; i < 5; i++, lab++) {
        if (i == sel) {
            color = 6;
        } else {
            if (D_802C6B40[i] == 0) {
                color = 7;
            } else {
                color = 0;
            }
        }
        gfxP = func_801E946C(gfxP, color, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        if (i == 4) {
            gfxP = func_801E3EE0(gfxP, 1, lab->id, 0xC1, 0x5D, 0);
        } else if (i == 3) {
            gfxP = func_801E3EE0(gfxP, 1, lab->id, 0x50, 0x5D, 0);
        } else {
            gfxP = func_801E3EE0(gfxP, 1, lab->id, i * 0x61 + lab->x + 0x2C, 0x48, 0);
        }
    }

    if (sel != 4 && sel != 3) {
        val = D_801CB308[sel];
        for (i = 0; i < 3; i++, val++) {
            if (D_801CE640 != 0) {
                if (i == D_802C6B38) {
                    color = 6;
                } else if (*val == -1) {
                    color = 7;
                } else {
                    color = 0;
                }
            } else {
                if (*val == -1) {
                    color = 7;
                } else {
                    color = 0;
                }
            }
            gfxP = func_801E946C(gfxP, color, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            gfxP = func_801E3EE0(gfxP, 1, D_i10_802C6AC8[i], 0x29, i * 0x14 + 0x80, 0);
            gfxP = func_801E9858(gfxP, 2, ">", 0xA7, i * 0x14 + 0x7F);
            if (D_801CE640 != 0) {
                if (i == D_802C6B38) {
                    if (*val == D_800DA988[sel][i]) {
                        color = 6;
                    } else {
                        color = 4;
                    }
                } else if (*val == -1) {
                    color = 7;
                } else {
                    color = 0;
                }
            } else {
                if (*val == -1) {
                    color = 7;
                } else {
                    color = 0;
                }
            }
            if (i == 0) {
                useStr = 0;
                if (*val == -1) {
                    idx = 0;
                } else {
                    idx = *val;
                }
                id = D_i10_802C6AD4[idx];
            } else if (i == 1) {
                useStr = 1;
                if (*val == -1) {
                    idx = 1;
                } else {
                    idx = *val;
                }
                sprintf(buf, "%d", idx);
            } else if (i == 2) {
                useStr = 1;
                if (*val == -1) {
                    idx = 1;
                } else {
                    idx = *val;
                }
                sprintf(buf, "%d", idx);
            } else {
                useStr = 0;
                if (*val == -1) {
                    idx = 0;
                } else {
                    idx = *val;
                }
                id = D_i10_802C6AE4[idx];
            }
            gfxP = func_801E946C(gfxP, color, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            if (!useStr) {
                gfxP = func_801E3EE0(gfxP, 1, id, 0xC6, i * 0x14 + 0x7F, 0);
            } else {
                gfxP = func_801E9858(gfxP, 2, buf, 0xC6, i * 0x14 + 0x7F);
            }
        }
        /* gDifficulty sits directly after D_801CB308 (+0x30); re-assigning val
           here lets IDO CSE it into the existing spills. */
        val = D_801CB308[sel];
        changed = 0;
        if (val != (s32*) &gDifficulty && *val != D_800DA988[sel][0]) {
            changed = 1;
        }
        if (changed) {
            gfxP = func_801E946C(gfxP, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            gfxP = func_801E3EE0(gfxP, 1, 0x41, 0x1C, 0xCA, 0);
            gfxP = func_801E3EE0(gfxP, 1, 0x44, 0x62, 0xCA, 0);
        }
    }
    return gfxP;
}

void func_i10_802C6A00(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x45;
    D_801CE638 = 0xE;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 4, 0);
    func_801E6A4C(0, 0);
}

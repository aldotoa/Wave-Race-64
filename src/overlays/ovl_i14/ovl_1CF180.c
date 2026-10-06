#include "global.h"

void func_i14_802C5840(void);

void func_i14_802C5800(void) {
    if ((D_801CE63C != 0) && (gGameState == 0x50)) {
        func_i14_802C5840();
    }
}

void func_i14_802C5840(void) {
    s32 flag = 0;

    D_802C61EC = 4;

    if (D_801CE608.gameMode == 4) {
        if (gPrevGameState == 0x43) {
            flag = 1;
        }
    } else if ((gPrevGameState != 100) && (gPrevGameState != 0x32) && (gPrevGameState != 0x39)) {
        flag = 1;
    }

    if (D_801CE608.gameMode == 4) {
        D_802C61EC = 2;
    }

    if (flag != 0) {
        D_802C61E0 = 1;
        D_802C61E4 = D_802C61E8 = 0x4C;
        return;
    }

    D_802C61E0 = 0;
    D_802C61E4 = 0x140;
    D_802C61E8 = -0xA9;

    AudioGeneral_PlaySound(0x31, 0);
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} Struct_i14_802C60F4;

extern Struct_i14_802C60F4 D_i14_802C60F4[];
extern Struct_i14_802C60F4 D_i14_802C6114[];
extern s32 D_801C2650;
extern s32 D_801C2654;
extern s32 D_801CB334;

Gfx* Gfx_ClearFrameBuffers(Gfx*);
void func_8007BEA4(s32);
void func_8007C0B8(s32);
void func_8007C204(s32);
void func_801EB91C(void);
Gfx* func_i14_802C5B70(Gfx*);
void func_i14_802C5F60(void);

Gfx* func_i14_802C5924(Gfx* gfx) {
    s32 flag;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x50) {
            switch (gPrevGameState) {
                case 0x32:
                case 0x39:
                case 100:
                    break;
                default:
                    flag = 0;
                    if (D_801CE608.gameMode == 4) {
                        if (gPrevGameState == 0x43) {
                            flag = 1;
                        }
                    } else {
                        flag = 1;
                    }
                    if (flag) {
                        osViBlack(false);
                        return Gfx_ClearFrameBuffers(gfx);
                    }
            }
        }
    }

    D_800DAB2C = 0;
    gfx = func_i14_802C5B70(Draw_WaterEffects(Gfx_FillCourseColor(func_8008FB74(gfx), gCourseID)));

    if (gGameState == 0x50) {
        func_i14_802C5F60();
    } else if (D_80228A16 == 1) {
        if (D_801CE608.gameMode == 0) {
            if ((D_801C2650 != 0) || (D_801C2654 != 0)) {
                if (D_800DAB68 != 0) {
                    func_8007C204(gCourseID);
                } else {
                    func_8007BEA4(gCourseID);
                }
            }
        } else if (D_801CE608.gameMode == 0xB) {
            if (D_801C2928 != 0) {
                func_8007C0B8(gCourseID);
            }
        }
        switch (D_801CE630) {
            case 30:
                D_801CE6F8 = 1;
                D_801CB334 = 0;
                if (gDifficulty == 0) {
                    D_801CB334 = 1;
                }
                func_801EB91C();
                break;
            case 40:
                Game_EnterGameplay();
                break;
            case 10:
                func_801EBD28();
                break;
            case 20:
                func_801EBFE4();
                break;
            case 2:
                func_801EB180();
                break;
        }
    }
    return gfx;
}

Gfx* func_i14_802C5B70(Gfx* gfx) {
    s32 i;
    s32 x;
    Struct_i14_802C60F4* p;
    s32 y;

    gSPDisplayList(gfx++, D_106F628);

    for (i = 0, y = 0x61; i < D_802C61EC; i++, y += 0x12) {
        x = (i & 1) ? D_802C61E4 : D_802C61E8;
        gfx = Menu_DrawFrame(gfx, 0, x + 8, y, 0xA9, 0x10);
    }

    gfx = func_801E946C(gfx, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);

    if (D_801CE608.gameMode == 4) {
        p = D_i14_802C6114;
    } else {
        p = D_i14_802C60F4;
    }
    for (i = 0; i < D_802C61EC; i++, p++) {
        if (i == D_i14_802C60F0) {
            continue;
        }
        x = (i & 1) ? D_802C61E4 : D_802C61E8;
        gfx = func_801E3EE0(gfx, 1, p->unk4, x + 0x3C + p->unk0, i * 0x12 + 0x64, 0);
    }

    i = D_i14_802C60F0;
    x = (i & 1) ? D_802C61E4 : D_802C61E8;
    if (D_801CE608.gameMode == 4) {
        p = &D_i14_802C6114[i];
    } else {
        p = &D_i14_802C60F4[i];
    }
    gfx = func_801E946C(gfx, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    return func_801E3EE0(gfx, 1, p->unk4, x + 0x3C + p->unk0, i * 0x12 + 0x64, 0);
}

void func_i14_802C5E5C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x51;
    D_801CE638 = 0xD;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;

    FadeTransition_SetProps(5, 1, 0);
    func_801E6A4C(0, 0);

    if (D_801CE630 == 2) {
        func_800C1F60(0);
        return;
    }
    if (D_801CE630 == 0x14) {
        func_800C1F60(0xA);
        return;
    }
    if (D_801CE630 == 0xA) {
        func_800C1F60(1);
        return;
    }
    if (D_801CE630 == 0x28) {
        func_800C1F60(7);
    }
}

void func_i14_802C5F60(void) {
    if (D_802C61E0 == 0) {
        D_802C61E4 -= 0x14;
        if (D_802C61E4 < 0x4C) {
            D_802C61E0 = 1;
            D_802C61E4 = 0x4C;
        }
        D_802C61E8 = 0x98 - D_802C61E4;
        return;
    }

    if (D_i14_802C613C == 0) {
        D_i14_802C613C = 1;
        func_800C30F8();
    }

    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        if (D_801CE608.gameMode == 4) {
            func_i14_802C5E5C(D_i14_802C6134[D_i14_802C60F0]);
        } else {
            func_i14_802C5E5C(D_i14_802C6124[D_i14_802C60F0]);
        }
        AudioGeneral_PlaySound(0x11, 0);
        return;
    }

    if (D_801CE65A[0].unk0 & U_JPAD) {
        if (--D_i14_802C60F0 < 0) {
            D_i14_802C60F0 = D_802C61EC - 1;
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }

    if (D_801CE65A[0].unk0 & D_JPAD) {
        if (++D_i14_802C60F0 >= D_802C61EC) {
            D_i14_802C60F0 = 0;
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }
}

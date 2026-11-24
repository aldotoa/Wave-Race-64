#include "global.h"

extern Mtx D_7000000[];
extern Mtx D_2000A40[];
extern Gfx D_106F550[];
extern s32 D_i12_802C6460;
extern s32 D_i12_802C6464;
extern s32 D_i12_802C6468;
extern s32 D_i12_802C646C[];
extern s32 D_i12_802C6478[];
extern s32 D_i12_802C6480[];
extern s32 D_i12_802C648C[];
extern s32 D_800DAA10[];

s32 func_8007C604(s32 arg0);
s32 func_8007C9D4(s32 arg0);
void func_800C3E6C(s32);

Gfx* func_i12_802C5800(Gfx* dList) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x46) {
            return Gfx_ClearFrameBuffers(dList);
        }
    }

    D_800DAB2C = 0;

    dList = func_i12_802C58A0(dList);

    if (gGameState == 0x46) {
        func_i12_802C5F6C();
    } else if (D_80228A16 == 1) {
        func_801EC304();
    }

    return dList;
}

Gfx* func_i12_802C58A0(Gfx* dList) {
    s32 i;
    s32 color;

    gSPMatrix(dList++, D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dList++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(dList++, D_106F550);
    gSPDisplayList(dList++, D_106F628);

    for (i = 0; i < 3; i++) {
        dList = Menu_DrawFrame(dList, 0, i * 0x59 + 0x1C, 0x3A, 0x56, 0x10);
    }
    for (i = 0; i < 9; i++) {
        dList = Menu_DrawFrame(dList, 0, (i / 5) * 0x85 + 0x1C, (i % 5) * 0x12 + 0x55, 0x83, 0x10);
    }
    dList = Menu_DrawFrame(dList, 0, 0x42, 0xB5, 0x5A, 0x10);
    dList = Menu_DrawFrame(dList, 0, 0xA4, 0xB5, 0x5A, 0x10);
    dList = func_801E946C(dList, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    dList = func_801E3EE0(dList, 2, 0x11, 0x20, 0x1D, 0);
    dList = func_801E3EE0(dList, 4, 0xC, 0x57, 0xCE, 0);
    dList = func_801E3EE0(dList, 4, 0xD, 0xA9, 0xCE, 0);

    for (i = 0; i < 3; i++) {
        if (i == D_i12_802C6460) {
            color = 6;
        } else {
            color = 0;
        }
        dList = func_801E946C(dList, color, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        dList = func_801E3EE0(dList, 1, D_i12_802C646C[i], D_i12_802C6480[i] + i * 0x59 + 0x34, 0x3D, 0);
    }

    for (i = 0; i < 9; i++) {
        if (D_801CE640 == 0) {
            if (D_i12_802C6460 == 0) {
                if (i == 0) {
                    color = 7;
                } else {
                    color = 0;
                }
            } else {
                color = 0;
            }
        } else if (D_i12_802C6460 == 0) {
            if (i == 0) {
                color = 7;
            } else if (i == D_i12_802C6464) {
                color = 6;
            } else {
                color = 0;
            }
        } else if (i == D_i12_802C6464) {
            color = 6;
        } else {
            color = 0;
        }
        dList = func_801E946C(dList, color, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        dList = func_801E3EE0(dList, 1, D_800DAA10[D_800DAAD8[i]],
                              D_i12_802C648C[D_800DAAD8[i]] + (i / 5) * 0x85 + 0x37, (i % 5) * 0x12 + 0x58, 0);
    }

    for (i = 0; i < 2; i++) {
        if (D_801CE640 == 2) {
            if (i == D_i12_802C6468) {
                color = 6;
            } else {
                color = 0;
            }
        } else {
            color = 7;
        }
        dList = func_801E946C(dList, color, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        dList = func_801E3EE0(dList, 1, D_i12_802C6478[i], i * 0x61 + 0x52, 0xB8, 0);
    }
    return dList;
}

void func_i12_802C5EE4(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x47;
    D_801CE638 = 0x10;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 4, 0);
}

void func_i12_802C5F6C(void) {
    s32 sound = 0;

    if (D_801CE65A[0].unk0 & 0xB000) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                if (D_i12_802C6460 == 2) {
                    func_i12_802C5EE4(0x3C);
                } else if (D_i12_802C6460 == 0) {
                    D_i12_802C6464 = 1;
                    D_801CE640 = 1;
                } else {
                    D_i12_802C6464 = 0;
                    D_801CE640 = 1;
                }
                break;
            case 1:
                D_801CE640 = 2;
                D_i12_802C6468 = 1;
                func_800C3E6C(3);
                break;
            case 2:
                sound = 1;
                D_801CE640 = 1;
                if (D_i12_802C6468 == 0) {
                    sound = 2;
                    if (D_i12_802C6460 == 0) {
                        func_8007C604(D_800DAAD8[D_i12_802C6464]);
                    } else {
                        func_8007C9D4(D_800DAAD8[D_i12_802C6464]);
                    }
                }
                break;
        }
        if (sound == 1) {
            AudioGeneral_PlaySound(0x11, 0);
        } else if (sound == 2) {
            AudioGeneral_PlaySound(0x37, 0);
        }
    } else if (D_801CE65A[0].unk0 & 0x4000) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                func_i12_802C5EE4(0x3C);
                break;
            case 1:
                sound = 1;
                D_801CE640 = 0;
                break;
            case 2:
                sound = 1;
                D_801CE640 = 1;
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x16, 0);
        }
    } else if (D_801CE65A[0].unk0 & 0x800) {
        if (D_801CE640 == 1) {
            sound = 1;
            D_i12_802C6464--;
            if (D_i12_802C6460 == 0) {
                if (D_i12_802C6464 < 1) {
                    D_i12_802C6464 = 8;
                }
            } else if (D_i12_802C6464 < 0) {
                D_i12_802C6464 = 8;
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A[0].unk0 & 0x400) {
        if (D_801CE640 == 1) {
            sound = 1;
            D_i12_802C6464++;
            if (D_i12_802C6460 == 0) {
                if (D_i12_802C6464 >= 9) {
                    D_i12_802C6464 = 1;
                }
            } else if (D_i12_802C6464 >= 9) {
                D_i12_802C6464 = 0;
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A[0].unk0 & 0x200) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                D_i12_802C6460--;
                if (D_i12_802C6460 < 0) {
                    D_i12_802C6460 = 2;
                }
                break;
            case 1:
                sound = 1;
                if ((D_i12_802C6460 != 0) || (D_i12_802C6464 != 5)) {
                    if (D_i12_802C6464 != 4) {
                        D_i12_802C6464 -= 5;
                        if (D_i12_802C6464 < 0) {
                            D_i12_802C6464 += 10;
                        }
                    }
                }
                break;
            case 2:
                sound = 1;
                D_i12_802C6468--;
                if (D_i12_802C6468 < 0) {
                    D_i12_802C6468 = 1;
                }
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A[0].unk0 & 0x100) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                D_i12_802C6460++;
                if (D_i12_802C6460 == 3) {
                    D_i12_802C6460 = 0;
                }
                break;
            case 1:
                sound = 1;
                if ((D_i12_802C6460 != 0) || (D_i12_802C6464 != 5)) {
                    if (D_i12_802C6464 != 4) {
                        D_i12_802C6464 += 5;
                        if (D_i12_802C6464 >= 9) {
                            D_i12_802C6464 -= 10;
                        }
                    }
                }
                break;
            case 2:
                sound = 1;
                D_i12_802C6468++;
                if (D_i12_802C6468 >= 2) {
                    D_i12_802C6468 = 0;
                }
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    }
}

#include "global.h"

typedef struct {
    s16 x;
    s32 id;
} Label_802C6160;
extern Label_802C6160 D_i11_802C6160[];
extern s32 D_i11_802C6154[];
extern s32 D_i11_802C6178[];
extern s32 D_i11_802C6184[];
extern Mtx D_7000000[];
extern Mtx D_2000A40[];
extern Gfx D_106F550[];

Gfx* func_801E9858(Gfx*, s32, char*, s32, s32);
void func_8007C494(void);
void func_i11_802C5D48(void);

Gfx* func_i11_802C5800(Gfx* glistp) {
    /* Warmup options menu renderer. Load-bearing: declaration order and
       char buf[16] fix the 0xA8 frame (id spills to 0x9C); lab/val as
       explicit cursors initialised in the for header keep
       D_i11_802C6154[i] from being strength-reduced. */
    Label_802C6160* lab;
    s32* val;
    s32 id;
    s32 useStr;
    s32 i;
    char buf[16];
    s32 color;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x48) {
            return Gfx_ClearFrameBuffers(glistp);
        }
    }
    D_800DAB2C = 0;

    gSPMatrix(glistp++, D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(glistp++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(glistp++, D_106F550);
    gSPDisplayList(glistp++, D_106F628);

    for (i = 0; i < 3; i++) {
        glistp = Menu_DrawFrame(glistp, 0, 0x1C, i * 0x15 + 0x64, 0x94, 0x10);
        glistp = Menu_DrawFrame(glistp, 0, 0xB2, i * 0x15 + 0x64, 0x69, 0x10);
    }
    glistp = Menu_DrawFrame(glistp, 0, 0x6A, 0xA3, 0x6B, 0x10);
    glistp = func_801E946C(glistp, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    glistp = func_801E3EE0(glistp, 2, 0x13, 0x7A, 0x32, 0);

    for (i = 0, lab = D_i11_802C6160, val = D_800DA9EC; i < 3; i++, lab++, val++) {
        if (i == D_i11_802C6150) {
            color = 6;
        } else {
            color = 0;
        }
        glistp = func_801E946C(glistp, color, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        glistp = func_801E3EE0(glistp, 1, lab->id, lab->x + 0x26, i * 0x15 + 0x67, 0);
        glistp = func_801E9858(glistp, 2, ">", 0x9E, i * 0x15 + 0x66);
        if (i == D_i11_802C6150) {
            if (*val == D_i11_802C6154[i]) {
                color = 6;
            } else if (i == 2) {
                color = 6;
            } else {
                color = 4;
            }
        } else {
            color = 0;
        }
        glistp = func_801E946C(glistp, color, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        if (i == 0) {
            useStr = 0;
            id = D_i11_802C6178[*val];
        } else {
            useStr = 1;
            if (i == 1) {
                useStr = 0;
                id = D_i11_802C6184[*val];
            } else {
                sprintf(buf, "%d", *val);
            }
        }
        if (!useStr) {
            glistp = func_801E3EE0(glistp, 1, id, 0xBC, i * 0x15 + 0x67, 0);
        } else {
            glistp = func_801E9858(glistp, 2, buf, 0xBC, i * 0x15 + 0x66);
        }
    }

    if (D_i11_802C6150 == 3) {
        color = 6;
    } else {
        color = 0;
    }
    glistp = func_801E946C(glistp, color, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    glistp = func_801E3EE0(glistp, 1, 0x3F, 0x90, 0xA6, 0);

    if (gGameState == 0x48) {
        func_i11_802C5D48();
    } else if (D_80228A16 == 1) {
        func_801EC304();
        func_8007C494();
    }
    return glistp;
}

typedef struct {
    s32 min;
    s32 max;
} Limit_802C618C;
extern Limit_802C618C D_i11_802C618C[];

void func_800C3050(s32);
void func_i11_802C6098(s32);
void func_i11_802C5F7C(void);

extern UnkStruct_801CE658 D_801CE658[];

void func_i11_802C5D48(void) {
    s32 pad; /* puts sp18 at 0x18 */
    s32 sp18;
    s32* val;
    Limit_802C618C* lim;

    if (D_801CE658[2].unk_00.unk_2 & 0xB000) {
        if (D_i11_802C6150 == 2) {
            sp18 = 1;
            func_800C3050(D_800DA9EC[D_i11_802C6150]);
        } else if (D_i11_802C6150 == 3) {
            sp18 = 1;
            func_i11_802C6098(0x3C);
        }
        if (sp18 != 0) {
            AudioGeneral_PlaySound(0x11, 0);
        }
    } else if (D_801CE658[2].unk_00.unk_2 & 0x4000) {
        func_i11_802C6098(0x3C);
        AudioGeneral_PlaySound(0x16, 0);
    } else if (D_801CE658[0].unk_00.unk_2 & 0x800) {
        if (--D_i11_802C6150 < 0) {
            D_i11_802C6150 = 3;
        }
        AudioGeneral_PlaySound(0x10, 0);
    } else if (D_801CE658[0].unk_00.unk_2 & 0x400) {
        if (++D_i11_802C6150 >= 4) {
            D_i11_802C6150 = 0;
        }
        AudioGeneral_PlaySound(0x10, 0);
    } else if (D_801CE658[0].unk_00.unk_2 & 0x200) {
        if (D_i11_802C6150 != 3) {
            lim = &D_i11_802C618C[D_i11_802C6150];
            val = &D_800DA9EC[D_i11_802C6150];
            if (--*val < lim->min) {
                *val = lim->max;
            }
            func_i11_802C5F7C();
        }
        AudioGeneral_PlaySound(0x10, 0);
    } else if (D_801CE658[0].unk_00.unk_2 & 0x100) {
        if (D_i11_802C6150 != 3) {
            lim = &D_i11_802C618C[D_i11_802C6150];
            val = &D_800DA9EC[D_i11_802C6150];
            if (lim->max < ++*val) {
                *val = lim->min;
            }
            func_i11_802C5F7C();
        }
        AudioGeneral_PlaySound(0x10, 0);
    }
}

void func_i11_802C5F7C(void) {
    if (D_i11_802C6150 == 0) {
        if (D_800DA9EC[D_i11_802C6150] == 0) {
            func_800C2FDC(0);
            D_801CB280 &= 0x3F;
        } else if (D_800DA9EC[D_i11_802C6150] == 1) {
            func_800C2FDC(3);
            D_801CB280 &= 0x3F;
            D_801CB280 |= 0x40;
        } else {
            func_800C2FDC(1);
            D_801CB280 &= 0x3F;
            D_801CB280 |= 0x80;
        }
    } else if (D_i11_802C6150 == 1) {
        if (D_800DA9EC[D_i11_802C6150] == 1) {
            func_800C3034();
            D_801CB280 &= 0xDF;
        } else {
            func_800C3044();
            D_801CB280 |= 0x20;
        }
    }
}

void func_i11_802C6098(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 73;
    D_801CE638 = 20;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;

    FadeTransition_SetProps(1, 4, 0);
    func_801E6A4C(0, 0);

    if (D_801CE630 == 60) {
        func_800C1F60(9);
    }
}

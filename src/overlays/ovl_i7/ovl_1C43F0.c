#include "global.h"

void func_801EC3AC(void);
void func_801EC500(void);
void func_801EC5B4(void);
void func_801EC650(void);
void func_801EC6EC(void);
void func_801EC780(void);
typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} Struct_i7_802C5D3C;

extern Struct_i7_802C5D3C D_i7_802C5D3C[];
extern Mtx D_7000000;
extern Mtx D_2000A40;
extern Gfx D_106F550[];

Gfx* func_i7_802C5A18(Gfx*);
void func_i7_802C5C94(s32);
extern s32 gCurrentOptionsMenuItem;
extern s32 D_i7_802C5D20[];

Gfx* func_i7_802C5800(Gfx* arg0) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x3C) {
            if (gPrevGameState == 4) {
                gCurrentOptionsMenuItem = 0;
            }
            return Gfx_ClearFrameBuffers(arg0);
        }
    }
    D_800DAB2C = 0;
    arg0 = func_i7_802C5A18(arg0);
    if (gGameState == 0x3C) {
        if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
            func_i7_802C5C94(D_i7_802C5D20[gCurrentOptionsMenuItem]);
            AudioGeneral_PlaySound(0x11, 0);
        } else if (D_801CE65A->unk0 & CONT_B) {
            func_i7_802C5C94(2);
            AudioGeneral_PlaySound(0x16, 0);
        } else if (D_801CE65A->unk0 & CONT_UP) {
            if ((--gCurrentOptionsMenuItem) < 0) {
                gCurrentOptionsMenuItem = 6;
            }
            AudioGeneral_PlaySound(0x10, 0);
        } else if (D_801CE65A->unk0 & CONT_DOWN) {
            if ((++gCurrentOptionsMenuItem) == 7) {
                gCurrentOptionsMenuItem = 0;
            }
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_80228A16 == 1) {
        switch (D_801CE630) {
            case 0x3E:
                func_801EC3AC();
                break;
            case 0x42:
                func_801EC500();
                break;
            case 0x44:
                func_801EC5B4();
                break;
            case 0x46:
                func_801EC6EC();
                break;
            case 0x40:
                func_801EC780();
                break;
            case 0x48:
                func_801EC650();
                break;
            default:
                func_801EB180();
                break;
        }
    }
    return arg0;
}

Gfx* func_i7_802C5A18(Gfx* glistp) {
    /* Options menu renderer: frame boxes, then the 7 option labels with
       the selected one drawn last on its own color layer. Load-bearing:
       one s32 var serves as the frame-row counter (keeps loop 1's
       signed slti), the label-table cursor and the selected-label
       pointer, which puts it in s0 ahead of i; y computed before the
       selection test (hoists the i * 0x13 chain above the beq); the
       empty else {} keeps the branch skeleton. */
    s32 var;
    s32 i;
    s32 y;

    gSPMatrix(glistp++, &D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(glistp++, &D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(glistp++, D_106F550);
    gSPDisplayList(glistp++, D_106F628);

    for (var = 0x49; var < 0xCE; var += 0x13) {
        glistp = Menu_DrawFrame(glistp, 0, 0x3A, var, 0xCC, 0x10);
    }

    glistp = func_801E946C(glistp, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    glistp = func_801E3EE0(glistp, 2, 5, 0x6B, 0x22, 0);

    for (var = (s32) D_i7_802C5D3C, i = 0; i < 7; i++, var += sizeof(Struct_i7_802C5D3C)) {
        y = i * 0x13 + 0x4C;
        if (i == gCurrentOptionsMenuItem) {
            continue;
        } else {
        }
        glistp = func_801E3EE0(glistp, 1, ((Struct_i7_802C5D3C*) var)->unk4, ((Struct_i7_802C5D3C*) var)->unk0 + 0x6D, y, 0);
    }

    glistp = func_801E946C(glistp, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    var = (s32) &D_i7_802C5D3C[gCurrentOptionsMenuItem];
    return func_801E3EE0(glistp, 1, ((Struct_i7_802C5D3C*) var)->unk4, ((Struct_i7_802C5D3C*) var)->unk0 + 0x6D, gCurrentOptionsMenuItem * 0x13 + 0x4C, 0);
}

void func_i7_802C5C94(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x3D;
    D_801CE638 = 7;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 4, 0);
}

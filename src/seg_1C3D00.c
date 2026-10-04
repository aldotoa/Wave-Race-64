#include "course.h"
#include "common.h"

Gfx* func_1C3D00_802C58DC(Gfx*);
void func_1C3D00_802C5D44(void);
void func_1C3D00_802C5E10(void);
Gfx* Gfx_ClearFrameBuffers(Gfx*);

extern s16 D_80228A16;
extern s32 D_802C5EF0;

Gfx* func_1C3D00_802C5800(Gfx* gDisplayListHead) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x36) {
            D_802C5EF0 = 0;
            osViBlack(false);
            return Gfx_ClearFrameBuffers(gDisplayListHead);
        }
    }
    D_800DAB2C = 0;
    gDisplayListHead =
        func_1C3D00_802C58DC(Draw_WaterEffects(Gfx_FillCourseColor(func_8008FB74(gDisplayListHead), gCourseID)));
    if (gGameState == 0x36) {
        if (D_80228A16 == 1) {
            func_800C30F8();
        }
        func_1C3D00_802C5D44();
    } else {
        func_1C3D00_802C5E10();
    }
    return gDisplayListHead;
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} Struct_1C3D00_802C5EB0;

extern Struct_1C3D00_802C5EB0 D_1C3D00_802C5EB0[];
extern s32 D_801CB3F0[];
Gfx* func_801E9858(Gfx*, s32, char*, s32, s32);
Gfx* func_801EB00C(Gfx*, s32, s32, s32, s32);

Gfx* func_1C3D00_802C58DC(Gfx* gDisplayListHead) {
    /* Menu renderer: frame boxes, a 1P/2P header with two counters, then
       the 4 option labels with the selected one drawn last. Same shape as
       func_i7_802C5A18: one s32 var serves as the frame-row counter (keeps
       loop 1's signed slti), the label-table cursor and the selected-label
       pointer, which puts it in s0 ahead of i. */
    s32 var;
    s32 i;
    char sp60[0x20];

    gSPDisplayList(gDisplayListHead++, D_106F628);
    gDisplayListHead = Menu_DrawFrame(gDisplayListHead, 0, 0x35, 0x26, 0xD6, 0x1A);
    gDisplayListHead = Menu_DrawFrame(gDisplayListHead, 0, 0x49, 0x49, 0xAE, 0x10);
    gDisplayListHead = Menu_DrawFrame(gDisplayListHead, 0, 0x49, 0x5A, 0xAE, 0x19);

    for (var = 0x8C; var < 0xD4; var += 0x12) {
        gDisplayListHead = Menu_DrawFrame(gDisplayListHead, 0, 0x49, var, 0xAE, 0x10);
    }

    gDisplayListHead =
        func_801E946C(gDisplayListHead, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    gDisplayListHead = func_801E3EE0(gDisplayListHead, 2, 0x12, 0x46, 0x2A, 0);
    gDisplayListHead = func_801E9858(gDisplayListHead, 2, "1P", 0x63, 0x4B);
    gDisplayListHead = func_801E9858(gDisplayListHead, 2, "2P", 0xCA, 0x4B);
    gDisplayListHead = func_801E9858(gDisplayListHead, 2, "-", 0x99, 0x5F);
    gDisplayListHead = func_801E3EE0(gDisplayListHead, 0, 0x15, 0x90, 0x4D, 0);
    gDisplayListHead = func_801EB00C(gDisplayListHead, 0, D_801CB3F0[0], 0x63, 0x5C);

    sprintf(sp60, "%d", D_801CB3F0[1]);

    gDisplayListHead = func_801E9858(gDisplayListHead, 0, sp60, 0xC1, 0x5C);

    for (var = (s32) D_1C3D00_802C5EB0, i = 0; i < 4; i++, var += sizeof(Struct_1C3D00_802C5EB0)) {
        if (i != D_802C5EF0) {
            gDisplayListHead = func_801E3EE0(gDisplayListHead, 1, ((Struct_1C3D00_802C5EB0*) var)->unk4, ((Struct_1C3D00_802C5EB0*) var)->unk0 + 0x8A, i * 0x12 + 0x8F, 0);
        }
    }

    gDisplayListHead =
        func_801E946C(gDisplayListHead, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    var = (s32) &D_1C3D00_802C5EB0[D_802C5EF0];
    return func_801E3EE0(gDisplayListHead, 1, ((Struct_1C3D00_802C5EB0*) var)->unk4, ((Struct_1C3D00_802C5EB0*) var)->unk0 + 0x8A, D_802C5EF0 * 0x12 + 0x8F, 0);
}

void func_1C3D00_802C5C4C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x37;
    D_801CE638 = 0x12;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;

    FadeTransition_SetProps(5, 1, 0);

    if (D_801CE630 == 2) {
        func_800C1F60(0);
        return;
    }
    if (D_801CE630 == 0xA) {
        func_800C1F60(1);
        return;
    }
    if (D_801CE630 == 0x14) {
        func_800C1F60(0xA);
        return;
    }
    if (D_801CE630 == 0x28) {
        func_800C1F60(7);
    }
}

void func_1C3D00_802C5D44(void) {
    if (D_801CE692[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        func_1C3D00_802C5C4C(D_1C3D00_802C5ED0[D_802C5EF0]);
        AudioGeneral_PlaySound(0x11, 0);
        return;
    }

    if (D_801CE692[0].unk0 & U_JPAD) {
        D_802C5EF0--;
        if (D_802C5EF0 < 0) {
            D_802C5EF0 = 3;
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }

    if (D_801CE692[0].unk0 & D_JPAD) {
        D_802C5EF0++;
        if (D_802C5EF0 == 4) {
            D_802C5EF0 = 0;
        }
        AudioGeneral_PlaySound(0x10, 0);
    }
}

void func_1C3D00_802C5E10(void) {
    if (D_80228A16 == 1) {
        switch (D_801CE630) {
            case 2:
                func_801EB180();
                return;
            case 40:
                Game_EnterGameplay();
                return;
            case 10:
                func_801EBD28();
                return;
            case 20:
                func_801EBFE4();
                break;
        }
    }
}

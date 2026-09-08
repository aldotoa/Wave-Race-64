#include "global.h"

Gfx* Gfx_FillViewport(Gfx* gfxPtr, u16 red, u16 green, u16 blue);
void* func_80091DBC(Gfx* gdl);
Gfx* func_i15_802C602C(Gfx* arg0);
void func_i15_802C6C1C(void);

#ifdef NON_MATCHING
Gfx* func_i15_802C5800(Gfx* arg0) {
    /* Glacier Coast floating iceberg and mist particle display list renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i15/ovl_1CFB60/func_i15_802C5800.s")
#endif

#ifdef NON_MATCHING
void func_i15_802C5CE8(void) {
    /* Glacier Coast ice floe bobbing physics */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i15/ovl_1CFB60/func_i15_802C5CE8.s")
#endif

void func_i15_802C5EE4(s32 effectKind) {
    UnkStruct_D_802C6E80* slot;
    s32 slotIdx;

    for (slotIdx = 0, slot = &D_802C6E80[0]; slotIdx < 10; slotIdx++, slot++) {
        if (slot->unk0 == 0) {
            break;
        }
    }

    slot = &D_802C6E80[slotIdx];

    if (slotIdx != 10) {
        slot->unk0 = 1;
        slot->unk4 = effectKind;
        slot->unkC = 235;
        if (effectKind != 10) {
            slot->unk8 = 32;
        } else {
            slot->unk8 = 28;
        }
    }
}

Gfx* func_i15_802C5F50(Gfx* gfx) {
    /* Award-ceremony scene composer: state reset, then Gfx chain through
       race-scene builders with conditional fade/audio teardown. Calls
       that ignore their result (6C1C/EB180/EC9C8) still take the live
       Gfx pointer in a0 in the stub; the chain value is preserved across
       them via the outgoing-arg spill slot. */
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == GAME_STATE_CEREMONY) {
            return Gfx_FillViewport(gfx, 0xFF, 0xFF, 0xFF);
        }
    }
    D_800DAB2C = 0;
    gfx = func_80091DBC(gfx);
    gfx = Game_BuildRaceScene(gfx);
    gfx = func_i15_802C602C(gfx);
    if (gGameState == GAME_STATE_CEREMONY) {
        func_i15_802C6C1C();
    } else if (D_80228A16 == 1) {
        if (D_801CE630 == 2) {
            func_801EB180();
        } else {
            func_801EC9C8();
        }
    }
    return gfx;
}

#ifdef NON_MATCHING
Gfx* func_i15_802C602C(Gfx* arg0) {
    /* Glacier Coast iceberg rebound collision impulse handler. Signature
       proven by func_i15_802C5F50's stub (takes the live Gfx pointer,
       result feeds the next chain call). */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i15/ovl_1CFB60/func_i15_802C602C.s")
#endif

void func_i15_802C6C1C(void) {
    if (D_i15_802C6DF4) {
        D_i15_802C6DF8++;
        if ((D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) || (D_i15_802C6DF8 > 600)) {
            if ((D_802C6E74 != 0) || (D_802C6E78 != 0)) {
                func_i15_802C6CAC(100);
            } else {
                func_i15_802C6CAC(2);
            }
        }
    }
}

void func_i15_802C6CAC(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x67;
    D_801CE638 = 0x15;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;

    FadeTransition_SetProps(3, 0x14, 0);

    if (D_801CE630 == 2) {
        func_800C1F60(0);
    }
}

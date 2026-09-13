#include "global.h"

Gfx* Gfx_FillViewport(Gfx* gfxPtr, u16 red, u16 green, u16 blue);
void* func_80091DBC(Gfx* gdl);
Gfx* func_i15_802C602C(Gfx* arg0);
void func_i15_802C6C1C(void);

/* TU-local externs for the 5CE8 draft. Prototypes/externs emit no code.
   NOTE: D_801C2C70 is canonically RiderStruct[] (0x378 stride, cf.
   code_52CD0.c) and D_801CB350 is s32[][4] (cf. ovl_i0, code_4C750.c),
   D_800EABB0 is const s16[] (cf. code_4C750.c:118); they are kept here in
   the probe-exact scalar/u8 spelling because the floor below was measured
   with it -- retyping re-rolls codegen. */
extern s32 D_800DAA08;
extern s16 D_800EABB0;
extern u8 D_801C2C70;
extern s32 D_801CB350;
extern s32 D_802C6E7C;
extern s32 D_802C6F20;
extern s32 D_802C6F44;
extern s32 D_i15_802C6D54[];
extern s32 D_i15_802C6D68;
extern s32 D_i15_802C6D6C;
extern s32 D_i15_802C6D70[];
extern UnkStruct_D_802C6E80 D_i15_802C6D8C;

#ifdef NON_MATCHING
Gfx* func_i15_802C5800(Gfx* arg0) {
    /* Glacier Coast floating iceberg and mist particle display list renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i15/ovl_1CFB60/func_i15_802C5800.s")
#endif

#ifdef NON_MATCHING
/* Course-setup initializer: bulk-copies the default effect slot over the
   D_802C6E80 table (pre-increment do-while, (u32) bound), picks the rider
   count from 6D54[gDifficulty], derives the mode index 6F44 from the
   rider lap state with the expert/non-expert if-chain, latches
   6D6C = 6D70[6F44] and the normal-difficulty flag 6D68, then scans the
   6D70 table against EABB0 entries into 6F20.. (goto inner scan, single
   exit). Diff floor 183 probe-verified (128 vs 127 insn, 5 probes A-E):
   branch skeleton incl. beql inner scan and bnel non-expert path exact,
   insn-class multiset identical except one extra hoist `move` (draft
   hoists the table base to a reg + per-iter copy; retail recomputes
   lui+addiu in-loop). Proven no-ops: decl-order perm, array vs
   struct-member vs word-cursor source forms. Blocker: loop-1 wants
   (dst,src,end) in (v1,v0,a0); an explicit src local folds to per-use
   luis (worse). No sibling analog (other overlays' same-named fns are
   different functions). Parked. */
void func_i15_802C5CE8(void) {
    s32* var_a2;
    UnkStruct_D_802C6E80* var_v1;
    s16* var_v1_2;
    s32* var_a0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0;

    var_v1 = D_802C6E80;
    do {
        var_v1++;
        var_v1[-1].unk0 = D_i15_802C6D8C.unk0;
        var_v1[-1].unk4 = D_i15_802C6D8C.unk4;
        var_v1[-1].unk8 = D_i15_802C6D8C.unk8;
        var_v1[-1].unkC = D_i15_802C6D8C.unkC;
    } while ((u32) var_v1 < (u32) &D_802C6F20);
    D_802C6E7C = D_i15_802C6D54[gDifficulty];
    temp_v1 = *(s32*) (&D_801C2C70 + D_800D48DC * 0x378);
    if (temp_v1 == 3) {
        D_802C6F44 = 6;
    } else if (gDifficulty == DIFFICULTY_EXPERT) {
        if (temp_v1 == 0) {
            D_802C6F44 = 3;
        } else if (temp_v1 == 1) {
            D_802C6F44 = 4;
        } else {
            D_802C6F44 = 5;
        }
    } else if (temp_v1 == 0) {
        D_802C6F44 = 0;
    } else if (temp_v1 == 1) {
        D_802C6F44 = 1;
    } else {
        D_802C6F44 = 2;
    }
    D_i15_802C6D6C = D_i15_802C6D70[D_802C6F44];
    if (gDifficulty == DIFFICULTY_NORMAL) {
        D_i15_802C6D68 = 1;
    } else {
        D_i15_802C6D68 = 0;
    }
    temp_v1_2 = D_802C6E7C + 1;
    if (temp_v1_2 > 0) {
        var_a2 = &D_802C6F20;
        var_a0 = &D_801CB350;
        do {
            var_v1_2 = &D_800EABB0;
            var_v0 = 0;
        loop_22:
            if (*var_v1_2 != *var_a0) {
                var_v0 += 1;
                var_v1_2 += 1;
                if (var_v0 != 4) {
                    goto loop_22;
                }
            }
            var_a2 += 1;
            var_a0 += 4;
            var_a2[-1] = var_v0;
        } while ((u32) var_a2 < (u32) (&D_802C6F20 + temp_v1_2));
    }
    D_800DAA08 = 1;
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

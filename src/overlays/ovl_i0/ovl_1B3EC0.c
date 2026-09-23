#include "libc/stdio.h"
#include "global.h"
#include "rider.h"

void func_i0_802C6878(void);
Gfx* func_i0_802C6AE4(Gfx*);
Gfx* func_i0_802C6044(Gfx* arg0);
void func_i0_802C63AC(void);
// Draw text?
Gfx* func_801E9858(Gfx* arg0, u32 arg1, char* arg2, s32 arg3, s32 arg4);
void func_801EB4F4(void);
extern s32 D_801519D4;
extern s32 D_80154344;
extern s32 D_i0_802C6BC4;
extern s32 D_i0_802C6BC8;
extern s32 D_i0_802C6BEC;
extern s32 D_805AF88;
void func_i0_802C6A1C(s32 arg0);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} UnkStruct_802C6BF0;

UnkStruct_802C6BF0 D_i0_802C6BF0[2] = {
    { 0x137, 0x188, 0x1E },
    { 0x2BF, 0x1A8, 0x1F },
};

s32 D_i0_802C6C08[] = {
    0, 0x00020002, 0x00020001, 0x00010001,
    0x00080008, 0x00080008, 0x00080008, 0x00080000,
};

s32 D_i0_802C6C28[] = {
    0x00010000, -1, 0x12, 0xE, 0, 3,
    0xFFFF0000, 0, 0x13, 0x17, 0x00010001, 0,
    0xFFFF0000, 0xB, 0x3B, 0x16, 0x00010001, 0x00020000,
    0xFFFF0000, 1, 0x14, 0x2B, 0x00020002, 0,
    0xFFFF0000, 5, 0x15, 0x22, 0x00010001, 0,
};

#ifdef NON_MATCHING
/* Skeletal stand-in for the playable build. No asm exists in-repo (the
   matching stub never calls it; the draft in this TU reverse-engineered
   the call), so there is no GLOBAL_ASM leg by design. Caller passes Gfx*
   and uses the result as Gfx*; true body to be m2c'd from ROM later. */
Gfx* func_8009328C(Gfx* arg0);
Gfx* func_8009328C(Gfx* arg0) {
    return arg0;
}
#endif

/* Training stage entry (0x18 bytes) and its per-step data (0x18 bytes) */
typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
} TrainingStep; /* 0x18 */

typedef struct {
    TrainingStep* unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} TrainingStage; /* 0x18 */

extern TrainingStage D_i0_802C6E08[];
extern s32 D_802C6EE8[];
extern s32 D_802C6EF8[];
extern s32 D_802C6F08;
extern s32 D_802C6F0C;
extern s32 D_802C6F10;
extern s32 D_i0_802C6BCC;
extern s32 D_i0_802C6BD0;
extern s32 D_i0_802C6BD4[];
extern s32 D_i0_802C6BD8;
extern s32 D_i0_802C6BDC;
extern s32 D_i0_802C6BE4;
extern s32 D_i0_802C6BE8;

typedef struct {
    s32 unk0, unk4, unk8, unkC, unk10, unk14, unk18, unk1C;
    s32 unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    s32 unk40, unk44, unk48, unk4C;
} DLChunk;

extern Gfx D_805A6F8[];
extern Gfx D_803D610[];
extern s32 D_i0_802C6BC0;
extern s32 D_801CB308[3][3];
extern s32 D_801CB340[];
extern s32 D_801CB350[][4];
extern s32 D_801CB330;
extern s32 D_801CB334;
extern s16 D_800EAC14[];
extern s16 D_800DAA00;
extern u16 D_801CE658[];

Gfx* func_i0_802C5800(Gfx* arg0) {

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (D_80154344 == 0) {
            D_i0_802C6BEC = 1;
        }

        arg0 = Gfx_ClearFrameBuffers(arg0);
        return arg0;
    }
    arg0 = Game_BuildRaceScene(arg0);

    gSPDisplayList(arg0++, &D_805AF88);
    gSPDisplayList(arg0++, &D_106F168);

    if (D_i0_802C6BC4 != 0) {
        char buf[10];

        arg0 = func_801E946C(arg0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        sprintf(buf, "%8XH", D_801519D4);
        arg0 = func_801E9858(arg0, 1, buf, 0x1C, 0x28);
        sprintf(buf, "%dKB", (s32) D_801519D4 / 1024);
        arg0 = func_801E9858(arg0, 1, buf, 0x1C, 0x3C);
    }
    if (D_i0_802C6BEC != 0) {
        arg0 = func_i0_802C6AE4(
            func_801E946C(arg0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF));
    }
    if (D_i0_802C6BC8 < 0x14) {
        D_i0_802C6BC8 = D_i0_802C6BC8 + 1;
        if (D_i0_802C6BC8 == 0x14) {
            gRiderGameModes = AI_MODE;
        }
    }
    if ((D_801CE65A->unk0 & 0xB000) || (D_800DAB0C != 0)) {
        D_800DAB0C = 0;
        func_i0_802C6878();
    }
    SysUtils_Rand();
    return arg0;
}

void stub_func_i0_802C5800() {
}

#ifdef NON_MATCHING
/* Overlay 0 Display list and training mode state machine builder
 * PARKED at floor diff (score 1580):
 * - 370 of 370 instructions structurally match (prologue, delay slots, Game_BuildRaceScene,
 *   both func_801E946C calls, switch jump tables, Case 1 gDPFillRectangle loop,
 *   D_i0_802C6BE4 delay-slot store, D_i0_802C6BC8 mode switch, beqzl branch-likely
 *   and audio trigger, and function epilogue match byte-for-byte).
 * - Remaining gap: DAG scheduler instruction ordering for Case 0 Gfx packet stores.
 * - Load-bearing constructs:
 *   1) Declaration order `Gfx* temp_v0; s32 base; s32 x; s32 a1; s32 t3; s32 t7;` forces `base`
 *      to spill to 72($sp) / 0x48($sp) in the jal delay slot.
 *   2) Case 1 loop uses `gDPFillRectangle(arg0++, 89, (x + D_i0_802C6BD0 - 3) & 0x3FF, 231, (x + D_i0_802C6BD0 + 14) &
 * 0x3FF);` with `do { ... } while (a1 < D_802C6F0C);`. 3) `if (++D_i0_802C6BE4 >= 30) D_i0_802C6BE4 = 0;` retains
 * non-likely delay slot store. 4) Tail logic uses `if (++D_802C6F14 >= 600) func_i0_802C6A1C(7);` to emit `beqzl`.
 */
Gfx* func_i0_802C5A7C(Gfx* arg0) {
    Gfx* temp_v0;
    s32 base;
    s32 x;
    s32 a1;
    s32 t3;
    s32 t7;

    if (D_801CE63C) {
        D_801CE63C = 0;
        D_802C6F08 = 1;
        if (D_801CB280 & 1) {
            D_802C6F08++;
            D_i0_802C6BD8 = 1;
        }
        if (D_801CB280 & 2) {
            D_802C6F08++;
            D_i0_802C6BDC = 1;
        }
        if (D_801CB280 & 8) {
            D_i0_802C6BC0 = 1;
        }
    }

    arg0 = Game_BuildRaceScene(arg0);

    switch (D_i0_802C6BE0) {
        case 0:
            gSPDisplayList(arg0++, D_805A6F8);
            arg0 = func_801E946C(arg0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            arg0 = func_801E946C(arg0, 0, 0xFF, 0xFF, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            if (D_i0_802C6BEC == 0) {
                base = 0xA6;
            } else {
                base = 0x8C;
            }
            temp_v0 = func_801E3EE0(arg0, 1, 0x58, 0x5F, base + 0x14, 2);
            {
                Gfx* gdl = temp_v0;
                {
                    Gfx* _g = gdl++;
                    _g->words.w0 = 0xFD700000;
                    _g->words.w1 = (u32) (uintptr_t) &D_803D610;
                }
                {
                    Gfx* _g = gdl++;
                    _g->words.w0 = 0xF5700000;
                    _g->words.w1 = 0x07080200;
                }
                {
                    Gfx* _g = gdl++;
                    _g->words.w0 = 0xE6000000;
                    _g->words.w1 = 0;
                }
                {
                    Gfx* _g = gdl++;
                    _g->words.w0 = 0xF3000000;
                    _g->words.w1 = 0x072FF040;
                }
                {
                    Gfx* _g = gdl++;
                    _g->words.w0 = 0xE7000000;
                    _g->words.w1 = 0;
                }
                {
                    Gfx* _g = gdl++;
                    _g->words.w0 = 0xF5684000;
                    _g->words.w1 = 0x80200;
                }
                {
                    Gfx* _g = gdl++;
                    _g->words.w0 = 0xF2000000;
                    _g->words.w1 = 0x3FC014;
                }
                {
                    Gfx* _g = gdl++;
                    _g->words.w0 = ((((base + 0x32) << 2) & 0xFFF) | 0xE4480000);
                    _g->words.w1 = ((((base + 0x2C) << 2) & 0xFFF) | 0x80000);
                }
                {
                    Gfx* _g = gdl++;
                    _g->words.w0 = 0xB3000000;
                    _g->words.w1 = 0;
                }
                {
                    Gfx* _g = gdl++;
                    _g->words.w0 = 0xB2000000;
                    _g->words.w1 = 0x04000400;
                }
            }
            arg0 = (Gfx*) ((DLChunk*) temp_v0 + 1);
            if ((D_i0_802C6BEC == 0) && (D_i0_802C6BE8 == 0x14)) {
                if ((D_i0_802C6BE4 % 30) < 0x14) {
                    arg0 = func_801E3EE0(
                        func_801E946C(arg0, 7, 0xFF, 0xFF, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF), 1,
                        0x56, 0x5E, 0xA6, 2);
                }
                if (++D_i0_802C6BE4 >= 30) {
                    D_i0_802C6BE4 = 0;
                }
            }
            gSPDisplayList(arg0++, D_106F168);
            break;
        case 1:
            arg0 = func_i0_802C6044(arg0);
            gSPDisplayList(arg0++, D_106F168);
            a1 = 0;
            x = 0;
            if (D_802C6F0C > 0) {
                do {
                    gDPFillRectangle(arg0++, 89, (x + D_i0_802C6BD0 - 3) & 0x3FF, 231,
                                     (x + D_i0_802C6BD0 + 14) & 0x3FF);
                    x += 0x14;
                    a1 += 1;
                } while (a1 < D_802C6F0C);
            }
            break;
    }

    if (D_i0_802C6BEC != 0) {
        arg0 = func_i0_802C6AE4(
            func_801E946C(arg0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF));
    }

    if (D_i0_802C6BC8 < 0x14) {
        t7 = D_i0_802C6BC8 + 1;
        D_i0_802C6BC8 = t7;
        if (t7 == 0x14) {
            gRiderGameModes = 2;
        }
    }

    switch (D_i0_802C6BE0) {
        case 0:
            if (D_i0_802C6BE8 < 0x14) {
                D_i0_802C6BE8++;
            }
            if ((D_801CE65A->unk0 & 0xB000) && (D_i0_802C6BE8 == 0x14)) {
                D_i0_802C6BE0 = 1;
                D_802C6F14 = 0;
                AudioGeneral_PlaySound(0x11, 0);
            } else if (++D_802C6F14 >= 600) {
                func_i0_802C6A1C(7);
            }
            break;
        case 1:
            func_i0_802C63AC();
            break;
    }
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i0/ovl_1B3EC0/func_i0_802C5A7C.s")
#endif

#ifdef NON_MATCHING
Gfx* func_i0_802C6044(Gfx* arg0) {
    /* Training stage instruction step advance */
    TrainingStage* s6 = &D_i0_802C6E08[D_802C6EE0];
    TrainingStep* sp6C = s6->unk0;
    Gfx* s2 = arg0;
    s32 s5 = s6->unk10;
    s32 ybase = s6->unkC;
    s32 s0;
    s32 s1;
    TrainingStep* s3;

    D_802C6F0C = s6->unk4;
    D_802C6F10 = s6->unk8;
    if (s6->unk14 != 0) {
        D_802C6F10 = D_802C6F08;
    }
    D_i0_802C6BD0 = s5;
    s2->words.w1 = (uintptr_t) D_106F628;
    s2->words.w0 = 0x06000000;
    s2 += 1;
    s0 = 0;
    s1 = 0;
    if (D_802C6F0C > 0) {
        do {
            s32 x = (s5 + s1) - 2;

            s2 = Menu_DrawFrame(s2, 0, 0x5A, x, 0x8C, 0xF);
            s0 += 1;
            s1 += 0x14;
        } while (s0 < D_802C6F0C);
        s0 = 0;
    }
    s2 = func_801E946C(s2, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    s3 = sp6C;
    if (D_802C6F0C > 0) {
        do {
            if (s0 != D_802C6EE4) {
                s32 a1;
                s32 flag = s6->unk14;

                s1 = s0 * 5;
                if (flag != 0) {
                    if (D_i0_802C6BD4[s0] != 0) {
                        a1 = 0;
                    } else {
                        a1 = 7;
                    }
                    s2 = func_801E946C(s2, a1, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                }
                s2 = func_801E3EE0(s2, 1, s3->unk8, s3->unkC + ybase, s5 + s1 * 4 + 1, 0);
            }
            s0 += 1;
            s3 += 1;
        } while (s0 < D_802C6F0C);
    }
    s2 = func_801E946C(s2, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    s3 = &sp6C[D_802C6EE4];
    s2 = func_801E3EE0(s2, 1, s3->unk8, s3->unkC + ybase, s5 + D_802C6EE4 * 0x14 + 1, 0);
    return func_801E5554(s2);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i0/ovl_1B3EC0/func_i0_802C6044.s")
#endif

#ifdef NON_MATCHING
void func_i0_802C63AC(void) {
    /* Training tutorial state machine and announcer cue dispatcher */
    TrainingStage* entry = &D_i0_802C6E08[D_802C6EE0];
    TrainingStep* unk0val = entry->unk0;
    s32 flag = 1;
    s32 cue;

    if ((D_801CE65A->unk0 & 0xB000) != 0) {
        s32 cnt = D_i0_802C6BCC;
        s32 ee4 = D_802C6EE4;

        D_802C6EE8[cnt] = ee4;
        D_802C6EF8[cnt] = D_802C6EE0;
        flag = 0;
        if (cnt < 2) {
            D_i0_802C6BCC = cnt + 1;
        }
        if (D_802C6EE0 == 0) {
            D_800DA9D8 = ee4;
        }
        {
            s32 off = ee4 * 0x18;
            TrainingStep* sub = (TrainingStep*) (off + (char*) unk0val);
            s32 h = sub->unk0;

            if (h == -1) {
                TrainingStep* body = (TrainingStep*) ((char*) entry->unk0 + off);

                D_801CE608.gameMode = body->unk4;
                D_801CE608.player = body->unk10;
                D_801CE608.rider = body->unk12;
                gDifficulty = body->unk14;
                if (body->unk16 == 4) {
                    D_800DAB68 = 1;
                }
                switch (D_801CE608.gameMode) {
                    case 0:
                        cue = 10;
                        D_801CE608.waveLevel = 0;
                        D_801CE608.unk_14 = 0;
                        break;
                    case 1:
                        D_801CB350[10][0] = 0;
                        D_801CB350[10][1] = 0;
                        cue = 10;
                        D_801CE608.waveLevel = 0;
                        D_801CE608.unk_14 = 0;
                        break;
                    case 4: {
                        s32* p;
                        s32* end;
                        s32* r;
                        s32* q;

                        D_801CE608.waveLevel = 0;
                        D_801CE608.unk_14 = 0;
                        if (gDifficulty == DIFFICULTY_NORMAL) {
                            D_801CE608.powerMisses = D_801CB308[0][1];
                            D_801CE608.lapCount = D_801CB308[0][2];
                        } else if (gDifficulty == DIFFICULTY_HARD) {
                            D_801CE608.powerMisses = D_801CB308[1][1];
                            D_801CE608.lapCount = D_801CB308[1][2];
                        } else {
                            D_801CE608.powerMisses = D_801CB308[2][1];
                            D_801CE608.lapCount = D_801CB308[2][2];
                        }
                        cue = 10;
                        D_801CE6F8 = 1;
                        p = D_801CB340;
                        end = &D_801CB350[0][0];
                        do {
                            p++;
                            p[-1] = 0;
                        } while ((u32) p < (u32) end);
                        D_801CB334 = 0;
                        if (body->unk16 == 2) {
                            D_801CB334 = 1;
                        }
                        D_801CB330 = *(s16*) ((char*) D_800EAC14 + gDifficulty * 0x10 + D_801CB334 * 2);
                        r = &D_801CB350[0][0];
                        q = (s32*) ((char*) &D_801CB350[0][0] + 0x80);
                        do {
                            r += 4;
                            q++;
                            r[-4] = 0;
                            r[-3] = 0;
                            r[-2] = 0;
                            r[-1] = 0;
                            q[-1] = 0;
                        } while (r != (s32*) ((char*) &D_801CB350[0][0] + 0x80));
                        break;
                    }
                    case 5:
                        cue = 0x3C;
                        break;
                    case 11:
                        cue = 10;
                        D_801CE608.waveLevel = 0;
                        D_801CE608.powerMisses = 1;
                        D_801CE608.lapCount = 1;
                        D_801CE608.unk_14 = 0;
                        break;
                    default:
                        cue = 2;
                        break;
                }
                AudioGeneral_PlaySound(0x37, 0);
                func_i0_802C6A1C(cue);
            } else {
                s32 t;

                D_802C6EE0 = h;
                D_802C6EE4 = 0;
                switch (sub->unk16) {
                    case 1:
                        if (D_800DAA00 > 0) {
                            D_802C6EE4 = 1;
                        }
                        break;
                    case 3:
                        if (D_i0_802C6BC0 != 0) {
                            D_802C6EE0 = 5;
                        }
                        break;
                }
                t = D_802C6EE0;
                D_i0_802C6BD0 = D_i0_802C6E08[t].unk10;
                AudioGeneral_PlaySound(0x11, 0);
            }
        }
    } else if ((D_801CE65A->unk0 & 0x4000) != 0) {
        flag = 0;
        if (D_802C6EE0 != 0) {
            s32 u = D_i0_802C6BCC;
            s32 dec = u - 1;

            if (u > 0) {
                D_i0_802C6BCC = dec;
                u = dec;
            }
            D_802C6EE0 = D_802C6EF8[u];
            D_802C6EE4 = D_802C6EE8[u];
            D_i0_802C6BD0 = D_i0_802C6E08[D_802C6EE0].unk10;
            AudioGeneral_PlaySound(0x16, 0);
        }
    } else if ((D_801CE65A->unk0 & 0x800) != 0) {
        s32 dec = D_802C6EE4 - 1;

        D_802C6EE4 = dec;
        if (dec < 0) {
            D_802C6EE4 = D_802C6F10 - 1;
        }
        D_801CE644 = 0;
        AudioGeneral_PlaySound(0x10, 0);
    } else if ((D_801CE65A->unk0 & 0x400) != 0) {
        s32 inc = D_802C6EE4 + 1;

        D_802C6EE4 = inc;
        if (inc >= D_802C6F10) {
            D_802C6EE4 = 0;
        }
        D_801CE644 = 0;
        AudioGeneral_PlaySound(0x10, 0);
    }
    if (flag == 0) {
    } else {
        if (D_801CE65A->unk0 == 0) {
            if (D_801CE658[0] != 0) {
                D_802C6F14 = 0;
            } else {
                D_802C6F14++;
            }
        } else {
            D_802C6F14 = 0;
        }
        if (D_802C6F14 < 0x258) {
        } else {
            func_i0_802C6A1C(7);
        }
    }
    SysUtils_Rand();
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i0/ovl_1B3EC0/func_i0_802C63AC.s")
#endif

void func_i0_802C6878(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 3;
    D_801CE638 = 0;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;
    D_802C6EE4 = D_800DA9D8;
    D_802C6EE0 = 0;

    func_801EAF78();
    func_801E6A4C(0, 0);
    func_801E6A4C(3, 0);
    func_801E6A4C(3, 1);

    D_i0_802C6BE0 = 0;
    D_802C6F14 = 0;

    AudioGeneral_PlaySound(0x2D, 0);
}

Gfx* func_i0_802C6944(Gfx* arg0) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }
    arg0 = Game_BuildRaceScene(arg0);
    gSPDisplayList(arg0++, &D_106F168);

    if (D_80228A16 == 1) {
        switch (D_801CE630) { /* irregular */
            case 0xA:
                func_801EBD28();
                break;
            case 0x3C:
                func_801EC304();
                break;
            case 0x2:
                func_801EB180();
                break;
            case 0x7:
                func_801EB4F4();
                break;
        }
    }
    return arg0;
}

void func_i0_802C6A1C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 4;
    D_801CE638 = 0;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;

    FadeTransition_SetProps(1, 4, 0);
    func_801E6A4C(0, 0);

    if (D_801CE630 == 10) {
        func_800C1F60(1);
        return;
    }

    if (D_801CE630 == 60) {
        func_800C1F60(9);
    }
}

Gfx* func_i0_802C6AE4(Gfx* arg0) {
    s32 var_s1;
    s32 var_s2;
    UnkStruct_802C6BF0* var_s0;

    var_s2 = 0;

    for (var_s0 = D_i0_802C6BF0, var_s1 = 0; var_s1 < 2; var_s1++, var_s0++) {
        var_s0->unk0 -= 2;
        if (var_s0->unk0 >= (8 - var_s0->unk4)) {
            arg0 = func_801E3EE0(arg0, 3, var_s0->unk8, var_s0->unk0, 0xC4, 6);
        } else {
            var_s2++;
        }
    }
    if (var_s2 == 2) {
        D_i0_802C6BF0[0].unk0 = 0x137;
        D_i0_802C6BF0[1].unk0 = 0x2BF;
    }
    return arg0;
}

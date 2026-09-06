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
extern s32 D_i0_802C6BF0[];
extern s32 D_i0_802C6BFC[];
extern s32 D_805AF88;
void func_i0_802C6A1C(s32 arg0);

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
Gfx* func_i0_802C5A7C(Gfx* arg0) {
    Gfx* s0 = arg0;
    Gfx* g;
    s32 base;
    s32 a1;
    s32 x;
    s32 cue;
    s32 t3;
    s32 f14;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        D_802C6F08 = 1;
        if (D_801CB280 & 1) {
            D_802C6F08 = 2;
            D_i0_802C6BD8 = 1;
        }
        if (D_801CB280 & 2) {
            D_802C6F08 += 1;
            D_i0_802C6BDC = 1;
        }
        if (D_801CB280 & 8) {
            D_i0_802C6BC0 = 1;
        }
    }
    s0 = func_8009328C(s0);
    switch (D_i0_802C6BE0) {
    case 0:
        g = s0;
        g->words.w0 = 0x06000000;
        g->words.w1 = (u32)(uintptr_t)D_805A6F8;
        g = func_801E946C(s0 + 1, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        g = func_801E946C(g, 0, 0xFF, 0xFF, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        if (D_i0_802C6BEC == 0) {
            base = 0xA6;
        } else {
            base = 0x8C;
        }
        g = func_801E3EE0(g, 1, 0x58, 0x5F, base + 0x14, 2);
        ((DLChunk*)g)->unkC = 0x07080200;
        ((DLChunk*)g)->unk10 = 0xE6000000;
        ((DLChunk*)g)->unk0 = 0xFD700000;
        ((DLChunk*)g)->unk20 = 0xE7000000;
        ((DLChunk*)g)->unk18 = 0xF3000000;
        ((DLChunk*)g)->unk8 = 0xF5700000;
        ((DLChunk*)g)->unk4 = (s32)(uintptr_t)&D_803D610;
        ((DLChunk*)g)->unk1C = 0x072FF040;
        ((DLChunk*)g)->unk28 = 0xF5684000;
        ((DLChunk*)g)->unk2C = 0x80200;
        ((DLChunk*)g)->unk30 = 0xF2000000;
        ((DLChunk*)g)->unk34 = 0x3FC014;
        ((DLChunk*)g)->unk24 = 0;
        ((DLChunk*)g)->unk14 = 0;
        ((DLChunk*)g)->unk48 = 0xB2000000;
        ((DLChunk*)g)->unk40 = 0xB3000000;
        ((DLChunk*)g)->unk3C = (s32)((((base + 0x2C) * 4) & 0xFFF) | 0x80000);
        ((DLChunk*)g)->unk4C = 0x04000400;
        ((DLChunk*)g)->unk38 = (s32)((((base + 0x32) * 4) & 0xFFF) | 0xE4480000);
        ((DLChunk*)g)->unk44 = 0;
        s0 = (Gfx*)((DLChunk*)g + 1);
        if ((D_i0_802C6BEC == 0) && (D_i0_802C6BE8 == 0x14)) {
            if ((D_i0_802C6BE4 % 30) < 0x14) {
                s0 = func_801E3EE0(func_801E946C(s0, 7, 0xFF, 0xFF, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF), 1, 0x56, 0x5E, 0xA6, 2);
            }
            t3 = D_i0_802C6BE4 + 1;
            D_i0_802C6BE4 = t3;
            if (t3 >= 0x1E) {
                D_i0_802C6BE4 = 0;
            }
        }
        s0->words.w0 = 0x06000000;
        s0->words.w1 = (u32)(uintptr_t)D_106F168;
        s0 = s0 + 1;
        break;
    case 1:
        s0 = func_i0_802C6044(s0);
        s0->words.w0 = 0x06000000;
        s0->words.w1 = (u32)(uintptr_t)D_106F168;
        s0 = s0 + 1;
        a1 = 0;
        x = 0;
        if (D_802C6F0C > 0) {
            do {
                g = s0;
                a1 += 1;
                g->words.w0 = (s32)(((u32)(((x + D_i0_802C6BD0 + 0xE) & 0x3FF) * 4)) | 0xF639C000);
                s0 = s0 + 1;
                g->words.w1 = (s32)(((u32)((((x + D_i0_802C6BD0) - 3) & 0x3FF) * 4)) | 0x164000);
                x += 0x14;
            } while (a1 < D_802C6F0C);
        }
        break;
    }
    if (D_i0_802C6BEC != 0) {
        s0 = func_i0_802C6AE4(func_801E946C(s0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF));
    }
    cue = D_i0_802C6BC8 + 1;
    if (D_i0_802C6BC8 < 0x14) {
        D_i0_802C6BC8 = cue;
        if (cue == 0x14) {
            gRiderGameModes = AI_MODE;
        }
    }
    switch (D_i0_802C6BE0) {
    case 0:
        if (D_i0_802C6BE8 < 0x14) {
            D_i0_802C6BE8 += 1;
        }
        if ((D_801CE65A->unk0 & 0xB000) && (D_i0_802C6BE8 == 0x14)) {
            D_i0_802C6BE0 = 1;
            D_802C6F14 = 0;
            AudioGeneral_PlaySound(0x11, 0);
        } else {
            f14 = D_802C6F14 + 1;
            D_802C6F14 = f14;
            if (f14 >= 0x258) {
                func_i0_802C6A1C(7);
            }
        }
        break;
    case 1:
        func_i0_802C63AC();
        break;
    }
    return s0;
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

#ifdef NON_MATCHING
Gfx* func_i0_802C6AE4(Gfx* arg0) {
    /* Training text glyph scroller: advances two text rows leftward, draws
       visible glyphs, resets both when fully scrolled out */
    s32 count = 0;
    s32* ptr = D_i0_802C6BF0;
    s32 i = 0;

    do {
        ptr[0] -= 2;
        if (ptr[0] >= 8 - ptr[1]) {
            arg0 = func_801E3EE0(arg0, 3, ptr[2], ptr[0], 0xC4, 6);
        } else {
            count++;
        }
        i++;
        ptr += 3;
    } while (i != 2);

    if (count == 2) {
        D_i0_802C6BF0[0] = 0x137;
        D_i0_802C6BFC[0] = 0x2BF;
    }
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i0/ovl_1B3EC0/func_i0_802C6AE4.s")
#endif

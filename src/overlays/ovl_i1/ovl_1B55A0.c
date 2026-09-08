#include "global.h"

void func_i1_802C5800(void) {
    if ((D_801CE63C != 0) && (gGameState == 0x28)) {
        func_i1_802C587C();
    }
    if ((gCourseID == 0) && (D_801CE608.gameMode == 4) && (D_800DAB64 == 0)) {
        func_i1_802C5900();
    }
}

void func_i1_802C587C(void) {
    D_i1_802C9440 = 0;
    if (D_801CE608.gameMode == 4) {
        if (gCourseID == 0) {
            D_802C96A8 = D_i1_802C94C8;
        }
        D_802C96CC = D_i1_802C9514[gDifficulty];
    }
}

void func_i1_802C5900(void) {
    switch (D_i1_802C94EC) {
        case 0:
            if (--D_i1_802C94F0 <= 0) {
                D_i1_802C94EC = 1;
                D_i1_802C94F0 = 0;
            }
            break;

        case 1:
            D_i1_802C94EC = 2;
            func_i1_802C59E8(D_i1_802C94F4);
            if (++D_i1_802C94F4 >= 0xB) {
                D_i1_802C94F4 = 0;
            }
            break;

        case 2:
            if (D_802C96A8.unk_0 == 0) {
                D_i1_802C94EC = 0;
                if (D_i1_802C94F4 != 1) {
                    D_i1_802C94F0 = 0x64;
                } else {
                    D_i1_802C94F0 = 0;
                }
            }
            break;
    }
}

extern s32 D_802C96AC;
extern s32 D_802C96B0;
extern s32 D_802C96B4;
extern s32 D_i1_802C9444[];
extern s32 D_80226890[];
void func_800C37D4(s32 arg0);

#ifdef NON_MATCHING
void func_i1_802C59E8(s32 arg0) {
    /* Course table init: copies defaults, scans arg0's row, fires audio cue.
       Diff floor 2190 probe-verified (TU form scores higher from trailing-
       function leakage): memcpy loop exact, scan body nearly exact (row a2,
       dst v1, end t1 all match). Left: setup hoist cluster, counter/table
       addrs recomputed in-loop by retail (value-load clobbers addr-reg)
       vs hoisted once here, -1 const in a3 vs t2. Tried: key/val split
       (-110), assign reorder (-35), 4-arg call (+120, reverted -- retail
       jal slot reloads arg0), volatile (shuffled, reverted), explicit
       load/store rewrite (added pressure, reverted), val-reuse (+180).
       Parked. */
    s32* dst;
    s32 var_a1;
    s32* row;
    s32* end;
    s32 key;
    s32 val;

    D_802C96A8 = D_i1_802C94C8;
    D_802C96A8.unk_0 = 1;
    dst = (s32*) &D_802C96A8;
    var_a1 = 0x122;
    row = (s32*) ((u8*) D_i1_802C9444 + arg0 * 12);
    end = &D_802C96B4;
    do {
        key = *row;
        dst++;
        dst[2] = var_a1;
        dst[5] = key;
        if (key != -1) {
            D_802C96AC++;
            val = D_80226890[key * 2 + 1] + 1;
            D_802C96B0 += val;
            var_a1 += val;
        }
        row++;
    } while (dst != end);
    func_800C37D4(arg0);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C59E8.s")
#endif

#ifdef NON_MATCHING
void func_i1_802C5AE4(void) {
    /* Course buoy waypoint sequence update */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C5AE4.s")
#endif

#ifdef NON_MATCHING
void func_i1_802C5DF4(void) {
    /* Course obstacle spawn coordinator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C5DF4.s")
#endif

#ifdef NON_MATCHING
void func_i1_802C63B4(void) {
    /* Course buoy distance and penalty evaluator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C63B4.s")
#endif

#ifdef NON_MATCHING
void func_i1_802C6550(void) {
    /* Course finish line trigger volume evaluator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C6550.s")
#endif

void func_i1_802C6B00(void) {
    if (D_80228A16 == 1) {
        func_800AD3C4();
        func_801ECE50();
    }
}

extern s32 D_800D817C;
extern s32 D_802C96A0;
extern s32 D_802C96A4;

#ifdef NON_MATCHING
/* Race-timer tick for game states 0x29/0x2A: passes arg0 through while
 * advancing the D_802C96A4 frame counter (0..61) and latching D_802C96A0.
 * D_800D817C is flagged while the counter is below 30 frames. The
 * duplicated store below is load-bearing: it keeps the compiler's
 * branch skeleton (bne + delay-slot store) intact. Both empty elses are
 * likewise required for byte-match. Diff: 60 (single li/lui fill-order
 * row remains vs. the retail stub). */
s32 func_i1_802C6B38(s32 arg0) {
    if (gGameState == GAME_STATE_2A) {
        if (D_801CE6F0 == 1) {
        } else {
            goto end;
        }
    } else if (gGameState == GAME_STATE_29) {
        if (D_802C96A4 < 0x1E) {
            D_800D817C = 1;
            if (D_801CE6F0 == 1) {
                D_800D817C = 1;
            }
        } else {
        }
        D_802C96A4++;
        if (D_802C96A4 < 0x3D) {
            goto end;
        }
        if (D_802C96A0 != 0) {
            goto end;
        }
        D_802C96A0 = 1;
    }
end:
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C6B38.s")
#endif

#ifdef NON_MATCHING
void func_i1_802C6BD8(void) {
    /* Course retire and exit coordinator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C6BD8.s")
#endif

#ifdef NON_MATCHING
void func_i1_802C6DCC(void) {
    /* Course lap counter increment and split time recorder */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C6DCC.s")
#endif

#ifdef NON_MATCHING
void func_i1_802C6FE0(void) {
    /* Course final lap fanfare cue */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C6FE0.s")
#endif

void func_i1_802C7394(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 44;
    D_801CE638 = 1;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;

    FadeTransition_SetProps(1, 4, 100);
    func_801E6A4C(0, 0);

    D_801CE62A = 0;

    func_800C1F60(4);
    func_800C21F4(4, 0);
    func_800BFD34();
    func_800BFD68();
}

void func_i1_802C744C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 43;
    D_801CE638 = 1;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;

    FadeTransition_SetProps(1, 4, 0);

    D_801CE62A = 0;

    func_800BFD34();
    func_800BFD68();

    if (D_801CE630 == 2) {
        func_800C1F60(0);
        return;
    }

    if (D_801CE630 == 0x1E) {
        func_800C1F60(2);
        return;
    }

    if (D_801CE630 == 0x28) {
        func_800C1F60(7);
        return;
    }

    if (D_801CE630 == 0xA) {
        func_800C1F60(1);
        return;
    }

    if (D_801CE630 == 0x14) {
        func_800C1F60(0xA);
    }
}

void func_i1_802C7570(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x2D;
    D_801CE638 = 1;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;
    func_801E6A4C(0, 0);
    D_80228AA4 = 1;
    func_800C21F4(3, 0);
}

#ifdef NON_MATCHING
void func_i1_802C7608(void) {
    /* Primary course navigation display list dispatcher */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C7608.s")
#endif

#ifdef NON_MATCHING
void func_i1_802C7D00(void) {
    /* Primary course buoy pass checker */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C7D00.s")
#endif

#ifdef NON_MATCHING
void func_i1_802C7E48(void) {
    /* Primary course rider rank tracker */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C7E48.s")
#endif

// https://decomp.me/scratch/7qW05
#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C8E70.s")
#else
void func_i1_802C8E70(void) {
    s32 pad;
    s32 var_v0;
    s32 flag = 0;

    switch (D_i1_802C9520) {
        case 0:
            if ((++D_802C96D0) >= 60) {
                D_i1_802C9520 = 1;
                D_802C96D0 = 0;
                flag = 1;
            }
            break;

        case 1:
            if (D_i1_802C9524 == 20) {
                D_i1_802C9520 = 2;
                D_802C96D0 = 0;
            }
            break;

        case 2:
            if (D_802C96D0 < 0x258) {
                D_802C96D0++;
            }
            if (D_802C96D0 >= 0x15) {
                if (D_801CE65A[0].unk0 & 0xB000) {
                    D_i1_802C9520 = 3;
                    D_802C96D0 = 0;
                    AudioGeneral_PlaySound(0x11, 0);
                } else {
                    // if (1) {}
                    if (D_802C96D0 >= 0x258) {
                        D_i1_802C9520 = 3;
                        D_802C96D0 = 0;
                    }
                }
            }
            break;

        case 3:
            if (D_i1_802C9524 == (-0x109)) {
                D_i1_802C9520 = 4;
                D_i1_802C952C = 0;
                D_802C96D0 = 0;
            }
            break;

        case 4:
            if (D_802C96D0 == 0xA) {
                D_i1_802C9520 = 5;
                D_802C96D0 = 0;
                D_i1_802C952C = 0xAA;
                D_i1_802C9528 = 0xFF;
                D_i1_802C9530 = 3;
                AudioGeneral_PlaySound(0x31, 0);
            }
            break;

        case 5:
            var_v0 = 0;
            if (D_i1_802C9534 == 0x14) {
                var_v0++;
            }
            if (D_i1_802C9538 == 0x14) {
                var_v0++;
            }
            if (D_i1_802C953C == 0x14) {
                var_v0++;
            }
            if (D_i1_802C9540 == 0x14) {
                var_v0++;
            }
            if (var_v0 == 4) {
                D_i1_802C9520 = 6;
                D_802C96D0 = 0;
            }
            break;

        case 6:
            var_v0 = 0;
            D_802C96D0++;
            if (D_802C96D0 >= 0x190) {
                var_v0 = 1;
            }
            if ((D_802C96D0 >= 0x28) && (D_801CE65A[0].unk0 & 0xB000)) {
                AudioGeneral_PlaySound(0x11, 0);
                var_v0 = 1;
            }
            if (var_v0 != 0) {
                D_i1_802C9520 = 7;
                D_802C96D0 = 0;
                D_i1_802C9558 = 1;
                FadeTransition_SetProps(3, 0x14, 0x14);
                func_800C1F60(0xB);
            }
            break;

        case 7:
            break;
    }

    if (flag != 0) {
        AudioGeneral_PlaySound(0x31, 0);
    }
}
#endif

Gfx* func_i1_802C913C(Gfx* dList) {
    s32 var_v0;
    s32 flag;
    Gfx* gfxPtr = dList;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;

        if (gGameState == 7) {
            D_i1_802C9440 = 0;
            return Gfx_ClearFrameBuffers(gfxPtr);
        }
    }

    if ((D_80228A16 == 1) && (gGameState == 7)) {
        func_800BFDD0(&D_80192610);
        func_800BFEF8((u8*) &D_80192630);
    }

    if (D_i1_802C9440 >= 0) {
        D_i1_802C9440++;
        flag = 0;

        if (gPlayers == 1) {
            if ((gGameModes == GMODE_STUNT) || (gGameModes == GMODE_TIME_TRIALS)) {
                if (D_i1_802C9440 >= 0xA) {
                    flag = 1;
                }
            } else if (D_i1_802C9440 >= 0x32) {
                flag = 1;
            }
        } else if (D_i1_802C9440 >= 0x2E) {
            flag = 1;
        }
        if (flag != 0) {
            gGameModeState = 1;
            D_i1_802C9440 = -1;
        }
    }

    D_800DAB2C = 0;

    dList = Game_BuildRaceScene(dList);

    gDPPipeSync(dList++);

    if (gPlayers == 1) {
        gDPSetScissor(dList++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
    } else {
        gDPSetScissor(dList++, G_SC_NON_INTERLACE, 8, 12, 311, 229);
    }

    if (gGameState == 7) {
        D_i1_802C9570++;
        if (gGameModes == GMODE_STUNT) {
            var_v0 = 600;
        } else {
            var_v0 = 800;
        }
        if ((D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) || (var_v0 < D_i1_802C9570)) {
            func_i1_802C9380(2);
        }
    } else if (D_80228A16 == 1) {
        func_801EB180();
    }

    return dList;
}

void func_i1_802C9380(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 8;
    D_801CE638 = 0;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;

    FadeTransition_SetProps(1, 4, 0);
    func_801E6A4C(0, 0);
    func_800BFD34();
    func_800BFD68();

    if (D_801CE630 == 2) {
        func_800C1F60(0);
    }
}

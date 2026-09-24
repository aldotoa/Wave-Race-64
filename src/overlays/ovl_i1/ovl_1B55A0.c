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

extern s32 D_i1_802C9444[][3];
extern s32 D_80226890[];
void func_800C37D4(s32 arg0);

#ifdef NON_MATCHING
void func_i1_802C59E8(s32 arg0) {
    /* Course warm-up banner table initialization: copies defaults, scans arg0's
       row, updates banner positions and widths, and fires audio cue.
       Diff floor 1675 probe-verified (improved from previous floor 2190).
       Key discoveries:
       - D_802C96A8 is a 0x24-byte banner state struct:
         unk_0 (active), unk_4 (count), unk_8 (totalWidth), unk_C[3] (xPos), unk_18[3] (bannerId).
       - Loop is for (i = 0; i < 3; i++) with D_802C96A8.unk_C[i] and unk_18[i]
         which IDO's strength-reduction translates to addiu v1, 4 / sw 8(v1) / sw 0x14(v1).
       - Global register allocator reserves a1 (0x122), a2 (row), a3 (-1), v1 (dst),
         t0 (&D_80226890), t1 (&D_802C96B4), exhausting caller-saved registers.
       - Disassembly labels D_802C96AC, D_802C96B0, D_802C96B4 are fields of D_802C96A8.
       Parked at floor 1675. */
    s32 i;
    s32 val;
    s32 key;
    s32 a1;

    D_802C96A8 = D_i1_802C94C8;
    D_802C96A8.unk_0 = 1;
    a1 = 0x122;

    for (i = 0; i < 3; i++) {
        key = D_i1_802C9444[arg0][i];
        D_802C96A8.unk_C[i] = a1;
        D_802C96A8.unk_18[i] = key;
        if (key != -1) {
            D_802C96A8.unk_4++;
            val = D_80226890[key * 2 + 1] + 1;
            D_802C96A8.unk_8 += val;
            a1 += val;
        }
    }
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

extern s32 D_i1_802C9510;
extern s32 D_i1_802C950C;
extern s32 D_802C96A0;
extern s32 D_801CB330;
extern s32 D_801CB334;
extern s32 D_801CB350[][4];

void func_i1_802C7570(s32);
void func_801EB91C(void);
void func_80077F5C(void);
void func_801EC0D4(void);
void func_801EC830(void);
void func_801EB180(void);
void func_801ECE50(void);

void func_i1_802C63B4(void) {
    s32 i;

    if (gPlayers == ONE_PLAYER) {
        if (D_i1_802C9510 != 0) {
            if (D_i1_802C950C > 0) {
                D_i1_802C950C--;
            }
            if (D_i1_802C950C == 0) {
                func_i1_802C7570(0x66);
            }
        }
    } else {
        if (D_802C96A0 == 1) {
            D_802C96A0 = 2;
            FadeTransition_SetProps(1, 4, 0);
        }
    }

    if (D_80228A16 == 1) {
        if (gPlayers == ONE_PLAYER) {
            switch (D_801CE608.gameMode) {
                case 4:
                    if (D_801CB330 == 0) {
                        D_801CE608.rider = 4;
                        for (i = 0; i < D_801CE608.rider; i++) {
                            D_801CB350[D_801CB334][i] = 0;
                        }
                        D_801CB334++;
                        func_801EB91C();
                    } else {
                        func_80077F5C();
                        func_801EC0D4();
                    }
                    break;
                case 0:
                case 11:
                    func_801EC830();
                    break;
                default:
                    func_801EB180();
                    break;
            }
        } else {
            func_801ECE50();
        }
        func_800AD3C4();
    }
}

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

/* Race-timer tick for game states 0x29/0x2A: passes passThrough through while
 * advancing the D_802C96A4 frame counter (0..61) and latching D_802C96A0.
 * D_800D817C is flagged while the counter is below 30 frames. The
 * duplicated store below is load-bearing: it keeps the compiler's
 * branch skeleton (bne + delay-slot store) intact. Both empty elses are
 * likewise required for byte-match. The single-line store/if below is
 * load-bearing too: split across lines, as1 sees distinct .loc directives
 * as scheduling boundaries and emits lui/li in the wrong fill order
 * (probe-verified CURRENT 60 -> 0). */
s32 func_i1_802C6B38(s32 passThrough) {
    if (gGameState == GAME_STATE_2A) {
        if (D_801CE6F0 == 1) {
        } else {
            goto end;
        }
    } else if (gGameState == GAME_STATE_29) {
        /* clang-format off */
        if (D_802C96A4 < 0x1E) { D_800D817C = 1; if (D_801CE6F0 == 1) { D_800D817C = 1; } } else {
        }
        /* clang-format on */
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
    return passThrough;
}

#ifdef NON_MATCHING
void func_i1_802C6BD8(void) {
    /* Course retire and exit coordinator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C6BD8.s")
#endif

#ifdef NON_MATCHING
void func_i1_802C6DCC(void) {
    s32 temp_v0;
    u16 var_a1;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 41;
    D_801CE638 = 1;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;
    D_802C96A4 = 0;
    D_802C96A0 = 0;
    if (D_801CE608.gameMode == 4) {
        if (*(s32*) ((u8*) &D_801CE6FC + 0xC) >= D_801C293C) {
            D_801CB3F8[0] = 1;
        } else {
            D_801CB3F8[0] = 0;
        }
        if (*(s32*) ((u8*) &D_801CE6FC + 0x10) >= *(s32*) ((u8*) D_801C2C70 + 0x44)) {
            D_801CB3F8[1] = 1;
        } else {
            D_801CB3F8[1] = 0;
        }
        if (*(s32*) ((u8*) &D_801CE6FC + 0x14) >= *(s32*) ((u8*) D_801C2C70 + 0x3BC)) {
            D_801CB3F8[2] = 1;
        } else {
            D_801CB3F8[2] = 0;
        }
        if (*(s32*) ((u8*) &D_801CE6FC + 0x18) >= *(s32*) ((u8*) D_801C2C70 + 0x734)) {
            D_801CB3F8[3] = 1;
        } else {
            D_801CB3F8[3] = 0;
        }
    }
    if (gPlayers == ONE_PLAYER) {
        if (D_i1_802C9510 != 0) {
            D_i1_802C950C = 0x78;
        } else {
            FadeTransition_SetProps(1, 4, 0x78);
        }
    }
    func_801E6A4C(0, 0);
    if (gPlayers == ONE_PLAYER) {
        var_a1 = 0;
        temp_v0 = *(s32*) (D_801C2C24 + D_800D48DC * 0x378);
        if (temp_v0 == 1) {
            goto label;
        }
        if (temp_v0 == 2) {
            var_a1 = 1;
        }
    label:
        func_801E6A4C(4, var_a1);
    }
    D_801CE62A = 0;
    func_800BFD34();
    func_800BFD68();
    func_800C1F60(4);
    func_800C21F4(4, 0);
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

extern s32 D_801C2650;
extern s32 D_801C2654;
Gfx* Gfx_ClearWorkImages(Gfx*);
Gfx* func_i1_802C7E48(Gfx*);
void func_i1_802C8E70(void);
void func_8007C494(void);
void func_8007BEA4(s32);
void func_8007C204(s32);
void func_801ECB98(void);

Gfx* func_i1_802C7D00(Gfx* glistp) {
    /* Dolphin Park race frame: builds the 3D scene, clears work images, sets
     * the 320x200 viewport scissor, draws rider ranks, ticks the intro state
     * machine, then runs the attract-mode save/menu tail when enabled. */
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }

    glistp = Game_BuildRaceScene(glistp);
    glistp = Gfx_ClearWorkImages(glistp);

    gDPPipeSync(glistp++);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gFrameBuffers[gFramebuffersIdx]));
    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 8, 20, 311, 219);

    glistp = func_i1_802C7E48(glistp);

    if (gPlayers == 1) {
        gSPDisplayList(glistp++, D_106F168);
    }

    func_i1_802C8E70();

    if (D_80228A16 == 1) {
        func_8007C494();
        if (D_801C2650 != 0 || D_801C2654 != 0) {
            if (D_800DAB68 != 0) {
                func_8007C204(gCourseID);
            } else {
                func_8007BEA4(gCourseID);
            }
        }
        func_801ECB98();
    }

    return glistp;
}

#ifdef NON_MATCHING
Gfx* func_i1_802C7E48(Gfx* glistp) {
    /* Primary course rider rank tracker */
    return glistp;
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

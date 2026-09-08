#include <ultra64.h>
#include "variables.h"
#include "rider.h"
#include "camera.h"
#include "libc/math.h"

extern s16 D_800DAB60;
extern s32 D_800DA9F8;
extern s32 D_800DA9FC;
extern s32 D_800DAA08;
extern s32 D_801CB334;
extern s16 D_800EAC44[];
s32 func_8009684C(s32, s16, s16);
void func_8004A208(void);

#ifdef NON_MATCHING
void func_801EB180(void) {
    /* No-Controller-Pak boot transition to TITLE_SCREEN. Retail stub is
       0x374 bytes; the previous empty draft left pak-less boots stuck in
       state 0 (black screen) forever. The D_800DAB60 store sits in a
       non-likely branch delay slot in the stub (executes on both paths);
       spelled here as straight-line code before the if. */
    s32 i;
    s32 sp24;
    s16 temp_a2;
    s32 var_v1;
    s32 temp_v0;
    s32 courseId;
    UnkStruct_800D96A4* tableRow;
    UnkStruct_800DB568* courseTable;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_TITLE_SCREEN;
    D_801CE638 = 0;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;
    gGameModes = GMODE_TIME_TRIALS;
    gPlayers = ONE_PLAYER;
    gRiders = 2;
    D_800D49B0 = 0x14;
    gBuoyMisses = 5;
    D_801CE728[0] = 3;
    D_800D8178 = 1;
    D_801CE600 = 0;
    D_801CE6F8 = 0;
    D_801CB334 = 0;
    if (D_800D8240 == 0) {
        gCourseID = DOLPHIN_PARK;
    }
    D_801CE6F0 = 0;
    D_800DAB68 = 0;
    D_800DAB0C = 0;
    if (D_801CB280 & 0x10) {
        D_800DAB60 = 1;
    } else {
        D_800DAB60 = 0;
    }
    D_800DAB64 = 0;
    D_800DAA08 = 0;
    temp_v0 = D_800DA9F8 + 1;
    D_800DA9F8 = temp_v0;
    if (temp_v0 >= 3) {
        D_800DA9F8 = 0;
    }
    var_v1 = D_800DA9FC + 1;
    D_800DA9FC = var_v1;
    if (var_v1 >= 4) {
        D_800DA9FC = 0;
        var_v1 = 0;
    }
    sp24 = D_800EAC44[var_v1 * 4];
    temp_a2 = D_800EAC44[var_v1 * 4 + 1];
    if (gRiders > 0) {
        tableRow = &D_800D96A4[gCourseID][temp_a2];
        for (i = 0; i < gRiders; i++) {
            D_80192690[i].unkB68 = temp_a2;
            D_80192690[i].unkB6C = tableRow->unk0;
            D_80192690[i].unkB70 = tableRow->unk4;
            D_80192690[i].unkB74 = tableRow->unk8;
        }
    }
    D_80192690[D_800D48DC].unkB68 = sp24;
    tableRow = &D_800D96A4[gCourseID][sp24];
    D_801CE6F4[1] = 0;
    D_80192690[D_800D48DC].unkB6C = tableRow->unk0;
    D_80192690[D_800D48DC].unkB70 = tableRow->unk4;
    D_80192690[D_800D48DC].unkB74 = tableRow->unk8;
    D_801CE6F4[0] = D_801CE6F4[1];
    gRiderGameModes = UNACTIVE_MODE;
    D_801CE64C = 0;
    gGameModeState = GMODE_STATE_STARTED;
    func_80096960(1, sp24, temp_a2, 0, 0);
    courseId = gCourseID;
    if (courseId < DOLPHIN_PARK) {
        courseId = DOLPHIN_PARK;
    }
    if (courseId >= RIDER_SELECTION) {
        courseId = SOUTHERN_ISLAND;
    }
    courseTable = &D_800DB568[courseId];
    func_8009684C(0x08060000, courseTable->unk0, courseTable->unk2);
    func_8004A208();
    FadeTransition_SetProps(0, 0, 0);
    func_801E6A4C(0, 0);
    gCameraPerspective->viewMode = 5;
    D_800DA9AC = 1;
    func_800C21F4(0, 0);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EB180.s")
#endif

#ifdef NON_MATCHING
void func_801EB4F4(void) {
    /* Time Attack mode state initialization */
    extern s32 D_801CE64C;

    void func_801EB4F4(void) {
        s32 sp40[4];
        s16* courseData;
        s32 course;

        gPrevGameState = gGameState;
        D_801CE630 = 0;
        gGameState = 7;
        D_801CE638 = 1;
        D_801CE63C = 1;
        D_801CE640 = 0;
        D_801CE644 = 0;
        D_800DAB1C = 0;
        D_800D461C = 3;
        gDifficulty = 2;

        switch (D_800DA9F8) {
            case 0:
                gGameModes = 4;
                gPlayers = 1;
                gRiders = 4;
                D_801CB330 = 2;
                gCourseID = 2;
                courseData = (s16*) ((u8*) D_800EAC44 + (D_800DA9FC * 8));
                sp40[0] = courseData[0];
                sp40[1] = courseData[1];
                sp40[2] = courseData[2];
                sp40[3] = courseData[3];
                func_80096960(0, sp40[0], sp40[1], sp40[2], sp40[3]);
                D_801CE728 = 3;
                D_801CE6F8 = 1;
                *(s32*) ((u8*) &D_801CE6FC + 8) = 4;
                func_800C4998(0, gCourseID);
                break;

            case 1:
                gGameModes = 11;
                gPlayers = 1;
                gRiders = 1;
                D_801CB330 = 1;
                courseData = (s16*) ((u8*) D_800EAC44 + (D_800DA9FC * 8));
                gCourseID = 1;
                sp40[1] = 0;
                sp40[2] = 0;
                sp40[3] = 0;
                sp40[0] = courseData[0];
                func_80096960(0, sp40[0], 0, 0, 0);
                D_801CE728 = 1;
                D_801CE6F8 = 0;
                func_800C4998(3, gCourseID);
                break;

            default:
                gGameModes = 1;
                gPlayers = 2;
                gRiders = 2;
                D_801CB330 = 1;
                courseData = (s16*) ((u8*) D_800EAC44 + (D_800DA9FC * 8));
                gCourseID = 1;
                sp40[2] = 0;
                sp40[3] = 0;
                sp40[0] = courseData[0];
                sp40[1] = courseData[1];
                func_80096960(4, sp40[0], sp40[1], sp40[0], sp40[1]);
                D_801CE728 = 3;
                D_800D4970 = 0;
                D_801CE6F8 = 0;
                func_800C4998(1, gCourseID);
                break;
        }

        D_800D49B0 = 0x14;
        gBuoyMisses = 5;
        D_801CE608[0] = gGameModes;
        *(s16*) ((u8*) D_801CE608 + 0x4) = gPlayers;
        D_801CE608[2] = 0x14;
        D_801CE608[3] = 5;
        *(s16*) ((u8*) D_801CE608 + 0x6) = gRiders;
        D_801CE608[5] = 0;
        D_801CE608[4] = D_801CE728;
        D_800D8178 = 0;
        D_801CE600 = 1;
        D_801CB334 = 0;
        D_801CE6F0 = 0;
        D_800DAB68 = 0;

        if (gRiders > 0) {
            s32* var_a1 = sp40;
            s32* end = var_a1 + gRiders;
            u8* var_v1 = (u8*) D_80192690;
            u8* courseParams = (u8*) D_800D96A4 + (gCourseID * 0x30);

            do {
                s32 val = *var_a1++;
                s32* entry = (s32*) (courseParams + (val * 12));

                var_v1 += 0x1718;
                *(s32*) (var_v1 - 0xBB0) = val;
                *(s32*) (var_v1 - 0xBAC) = entry[0];
                *(s32*) (var_v1 - 0xBA8) = entry[1];
                *(s32*) (var_v1 - 0xBA4) = entry[2];
            } while (var_a1 < end);
        }

        D_801CE6F4[1] = 0;
        D_801CE6F4[0] = D_801CE6F4[1];
        gRiderGameModes = 2;
        course = gCourseID;
        D_801CE64C = 0;
        gGameModeState = 0;

        if (course < 0) {
            course = 0;
        }
        if (course >= 9) {
            course = 8;
        }

        func_8009684C(0x08060000, *(s16*) ((u8*) D_800DB568 + (course * 4) + 0),
                      *(s16*) ((u8*) D_800DB568 + (course * 4) + 2));
        FadeTransition_SetProps(2, 4, 0);
        func_801E6A4C(0, 0);

        gCameraPerspective[0] = 3;
        if (gPlayers == 2) {
            gCameraPerspective[0x10C / 4] = 3;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EB4F4.s")
#endif

#ifdef NON_MATCHING
void func_801EB91C(void) {
    /* Stunt Mode state initialization */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EB91C.s")
#endif

#ifdef NON_MATCHING
void func_801EBD28(void) {
    /* 2-Player Versus mode state initialization */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EBD28.s")
#endif

#ifdef NON_MATCHING
void func_801EBFE4(void) {
    /* Mode select cleanup and state reset */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EBFE4.s")
#endif

#ifdef NON_MATCHING
/* Race-setup init: default game-state globals, conditional counter bump
   through D_800DA9B0, then the 96960/transition/VI-black call sequence.
   Diff floor 410 probe-verified: calls/structure/stack exact; remainder is
   register rotation (h/lh in v0 vs t0, consts in t0/t1 vs a3/v0, chain shift).
   Tried: v1 decl-last (+37), drop t3 index temp (-40, kept: fixed v1 home),
   early named h (+25), s16 h (neutral). Next: h-to-t0 lever. */
void func_801EC0D4(void) {
    s32 v1 = 1;
    s32 args[4];
    s32 h;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_RACE_RESULTS;
    D_801CE638 = 9;
    D_801CE63C = v1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = ONE_PLAYER;
    gRiderGameModes = UNACTIVE_MODE;
    h = D_801CE6F4[0];
    D_801CE64C = v1;
    gGameModeState = 0;
    args[2] = 2;
    args[3] = 3;
    args[0] = 0;
    args[1] = v1;
    if (h != 0) {
        args[D_800DA9B0[D_800D48DC]] += 4;
    }
    func_80096960(2, args[0], args[1], args[2], args[3]);
    FadeTransition_SetProps(4, 1, 0);
    func_801E6A4C(0, 0);
    gCameraPerspective[0].viewMode = 1;
    osViBlack(1);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EC0D4.s")
#endif

#ifdef NON_MATCHING
void func_801EC20C(void) {
    /* Title screen attract demo timer and transition */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EC20C.s")
#endif

void func_801EC304(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x3C;
    D_801CE638 = 7;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(2, 4, 0);
    func_801E6A4C(0, 0);
    D_800E5134 = 0;
    func_800C21F4(9, 0);
}

#ifdef NON_MATCHING
void func_801EC3AC(void) {
    /* Options change-names init (GAME_STATE 0x3E): default globals,
       rider-table entry setup from option bytes, then fade/audio
       teardown. FLOOR 26/85 (all pure temp-coloring: same opcodes,
       order, immediates, frame; stub uses t2/t3/t5/t0/t1/t6 where the
       probe uses t4/t5/v1/t3/t2/t0). Load-bearing: idx var (separate
       load statement pins the x5912 chain late + t6 accum; fusing it
       into the rider expression hoists the chain early), half var
       (keeps the lh; inline also keeps it but costs an auto slot),
       rider computed before the mode stores (scheduler weave).
       First-temp follows auto count (1->t2, 2->t3, 3->t4) while a
       late chain needs the idx temp: t2-first + late-chain is
       unreachable (decl order, s16/s32, register hint all inert).
       Expression-nesting sweep (~15 probes: ptr-add/split chain forms,
       u32 idx, char* rider, named three/optbytes consts, store-order
       shuffles incl. B68-last and nine/modestate swaps) either
       reproduces this exact 26 or adds rows; failed variants fix
       nothing vs this floor. T4 confirms nine-before-modestate.
       The D_801CE6F4[0] store sits in the func_80096960 delay slot
       (both paths); spelled as straight-line code before the call. */
    UnkStruct_80192690* rider;
    s16 half;
    s32 idx;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_OPTIONS_CHANGE_NAMES;
    D_801CE638 = 0xA;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;
    gPlayers = ONE_PLAYER;
    gRiders = 1;
    idx = D_800D48DC;
    rider = &D_80192690[idx];
    gCourseID = RIDER_SELECTION;
    gRiderGameModes = AI_MODE;
    D_801CE64C = 2;
    gGameModeState = GMODE_STATE_STARTED;
    D_801CE6F4[1] = 0;
    rider->unkB68 = 0;
    rider->unkB6C = D_800DA950[0].unk_B[0];
    rider->unkB70 = D_800DA950[0].unk_B[1];
    rider->unkB74 = D_800DA950[0].unk_B[2];
    half = D_801CE6F4[1];
    D_801CE6F4[0] = half;
    func_80096960(2, 0, 1, 2, 3);
    FadeTransition_SetProps(2, 4, 0);
    func_801E6A4C(0, 0);
    gCameraPerspective->viewMode = 2;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EC3AC.s")
#endif

void func_801EC500(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x42;
    D_801CE638 = 0xC;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = ONE_PLAYER;
    func_80096960(2, 0, 1, 2, 3);
    FadeTransition_SetProps(2, 4, 0);
    func_801E6A4C(0, 0);
}

void func_801EC5B4(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x44;
    D_801CE638 = 0xE;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = ONE_PLAYER;
    FadeTransition_SetProps(2, 4, 0);
    func_801E6A4C(0, 0);
}

void func_801EC650(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x48;
    D_801CE638 = 0x14;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = ONE_PLAYER;
    FadeTransition_SetProps(2, 4, 0);
    func_801E6A4C(0, 0);
}

void func_801EC6EC(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x46;
    D_801CE638 = 0x10;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(2, 4, 0);
    func_801E6A4C(0, 0);
}

void func_801EC780(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x40;
    D_801CE638 = 0xB;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    func_80096960(2, 0, 1, 2, 3);
    FadeTransition_SetProps(2, 4, 0);
    func_801E6A4C(0, 0);
}

void func_801EC830(void) {
    s32 var_v1;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x50;
    D_801CE638 = 0xD;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = ONE_PLAYER;
    gRiderGameModes = 1;
    D_801CE64C = 1;
    gGameModeState = GMODE_STATE_0;

    var_v1 = false;

    if (D_801CE608.gameMode == 4) {
        if (gPrevGameState == 0x43) {
            var_v1 = true;
        }
    } else if ((gPrevGameState != 0x32) && (gPrevGameState != 0x39)) {
        var_v1 = true;
    }
    if (var_v1) {
        FadeTransition_SetProps(4, 1, 0);
        osViBlack(true);
    }
    func_801E6A4C(0, 0);
    gCameraPerspective->viewMode = 1;
}

void func_801EC944(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x5A;
    D_801CE638 = 0xF;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    func_800C21F4(5, 0);
}

void func_801EC9C8(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x64;
    D_801CE638 = 6;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = 1;
    gRiderGameModes = 1;
    D_801CE64C = 1;
    gGameModeState = 0;
    if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 0xB)) {
        func_80096960(2, 0, 1, 2, 3);
    }
    if (gPrevGameState == 0x67) {
        FadeTransition_SetProps(7, 0x14, 0);
    } else if (gPrevGameState == 0x2A) {
        FadeTransition_SetProps(4, 1, 0);
    }
    func_801E6A4C(0, 0);
    gCameraPerspective->viewMode = 1;
    func_800C21F4(0xC, 0);
}

void func_801ECAF4(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 5;
    D_801CE638 = 0x13;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 3;
    D_800D461C = 2;
    FadeTransition_SetProps(0, 0, 0);
    func_801E6A4C(0, 0);
    func_800C21F4(8, 0);
}

#ifdef NON_MATCHING
void func_801ECB98(void) {
    /* Pause menu unpause and game resume sequence */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801ECB98.s")
#endif

void func_801ECE50(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x36;
    D_801CE638 = 0x12;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = ONE_PLAYER;
    FadeTransition_SetProps(4, 1, 0);
    func_801E6A4C(0, 0);
    gRiderGameModes = 1;
    D_801CE64C = 1;
    gGameModeState = 0;
    gCameraPerspective->viewMode = 1;
    osViBlack(true);
}

void func_801ECF18(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x38;
    D_801CE638 = 0x16;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = ONE_PLAYER;
    gRiderGameModes = 1;
    D_801CE64C = 1;
    gGameModeState = 0;
    func_80096960(2, 0, 1, 2, 3);
    FadeTransition_SetProps(4, 1, 0);
    func_801E6A4C(0, 0);
    gCameraPerspective->viewMode = 1;
    func_800C21F4(3, 0);
    osViBlack(true);
}

void func_801ED004(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x39;
    D_801CE638 = 0x17;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = ONE_PLAYER;
    gRiderGameModes = 1;
    D_801CE64C = 1;
    gGameModeState = 0;
    gCameraPerspective->viewMode = 1;
}

f32 func_801ED090(f32 arg0) {
    if ((arg0 < -1.0f) || (arg0 > 1.0f)) {
        return 0.0f;
    }
    if (arg0 >= 0.0f) {
        return D_80226F08[(s32) (arg0 * 511.0f)];
    }
    return 180.0f - D_80226F08[(s32) (-arg0 * 511.0f)];
}

f32 func_801ED154(f32 arg0, f32 arg1) {
    s32 sp24 = 0;
    s32 sp20 = 0;
    f32 temp_f0;
    f32 var_f2;

    if ((arg1 == 0.0f) && (arg0 == 0.0f)) {
        return 0.0f;
    }

    if (arg1 < 0.0f) {
        arg1 = -arg1;
        sp24 = 1;
    }
    if (arg0 < 0.0f) {
        arg0 = -arg0;
        sp20 = 1;
    }

    var_f2 = sqrtf(SQ(arg1) + SQ(arg0));

    if (arg0 >= arg1) {
        temp_f0 = D_80226F08[(s32) (arg1 / var_f2 * 511)];
    } else {
        temp_f0 = 90.0f - D_80226F08[(s32) (arg0 / var_f2 * 511)];
    }

    if ((sp24 != 0) && (sp20 == 0)) {
        temp_f0 = 180.0 - temp_f0;
    } else if (sp24 && sp20) {
        temp_f0 += 180.0;
    } else if (!sp24 && sp20) {
        temp_f0 = 360.0 - temp_f0;
    }

    return temp_f0;
}

void Math_srand(void) {
    sRandSeed = osGetTime();
}

s32 Math_Rand(s32 arg0) {
    sRandSeed = (sRandSeed << 2) + sRandSeed + 1;

    return (sRandSeed * arg0) >> 16;
}

f32 Math_FloatRand(f32 arg0) {
    sRandSeed = (sRandSeed << 2) + sRandSeed + 1;

    return (arg0 * sRandSeed / 65536.0f);
}

s32 func_801ED388(s32 arg0, s32 arg1) {
    arg0 = ABS_DEG(arg0);
    arg1 = ABS_DEG(arg1);
    arg0 = arg0 - arg1;
    arg0 = ABS(arg0);

    return (arg0 <= 180 ? arg0 : 360 - arg0);
}

s32 func_801ED43C(s32 arg0, s32 arg1) {
    arg0 = ABS_DEG(arg0);
    arg1 = ABS_DEG(arg1);
    arg0 = arg0 - arg1;

    return (arg0 >= 0 ? arg0 : arg0 + 360);
}

s32 func_801ED4E0(s32 arg0, s32 arg1) {
    arg0 = ABS_DEG(arg0);
    arg1 = ABS_DEG(arg1);

    if (arg0 == arg1) {
        return 0;
    }

    arg0 -= arg1;
    arg0 = (arg0 >= 0) ? arg0 : arg0 + 360;

    return (arg0 < 180 ? 1 : -1);
}

s32 func_801ED5A8(s32 arg0) {
    arg0 = ABS_DEG(arg0);

    if (arg0 > 270) {
        arg0 -= 360;
    } else if (arg0 > 90) {
        arg0 = 180 - arg0;
    }
    return arg0;
}

s32 func_801ED5F8(s32 arg0, s32 arg1) {
    arg0 = func_801ED5A8(arg0);
    arg1 = func_801ED5A8(arg1);
    arg0 = arg0 - arg1;

    return ABS(arg0);
}

s32 func_801ED63C(s32 arg0, s32 arg1) {
    arg0 = func_801ED5A8(arg0);
    arg1 = func_801ED5A8(arg1);
    arg0 = arg0 - arg1;

    return SIGNUM(arg0);
}

f32 func_801ED694(f32 arg0) {
    s32 temp_f12 = arg0 / 360;
    arg0 -= temp_f12 * 360;

    return (arg0 >= 0 ? arg0 : arg0 + 360);
}

f32 func_801ED704(f32 arg0, f32 arg1) {
    arg0 = func_801ED694(arg0);
    arg1 = func_801ED694(arg1);
    arg0 -= arg1;
    arg0 = ABS(arg0);

    return (arg0 <= 180 ? arg0 : 360 - arg0);
}

f32 func_801ED780(f32 arg0, f32 arg1) {
    arg0 = func_801ED694(arg0);
    arg1 = func_801ED694(arg1);
    arg0 -= arg1;

    return (arg0 >= 0 ? arg0 : arg0 + 360);
}

s32 func_801ED7E4(f32 arg0, f32 arg1) {
    arg0 = func_801ED694(arg0);
    arg1 = func_801ED694(arg1);

    if (arg0 == arg1) {
        return 0;
    }

    arg0 -= arg1;
    arg0 = arg0 >= 0 ? arg0 : arg0 + 360;

    return (arg0 < 180 ? 1 : -1);
}

f32 func_801ED87C(f32 arg0) {
    arg0 = func_801ED694(arg0);
    if (arg0 > 270) {
        arg0 -= 360;
    } else if (arg0 > 90) {
        arg0 = 180 - arg0;
    }
    return arg0;
}

f32 func_801ED8EC(f32 arg0, f32 arg1) {
    arg0 = func_801ED87C(arg0);
    arg1 = func_801ED87C(arg1);
    arg0 = arg0 - arg1;

    return ABS(arg0);
}

s32 func_801ED944(f32 arg0, f32 arg1) {
    arg0 = func_801ED87C(arg0);
    arg1 = func_801ED87C(arg1);
    arg0 = arg0 - arg1;

    return SIGNUM(arg0);
}

f32 func_801ED9B4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 sp1C = sqrtf(SQ(arg0) + SQ(arg1) + SQ(arg2));
    f32 temp_f0 = sqrtf(SQ(arg3) + SQ(arg4) + SQ(arg5));

    if ((sp1C > 0.0f) && (temp_f0 > 0.0f)) {
        return (((arg0 * arg3) + (arg1 * arg4) + (arg2 * arg5)) / sp1C) / temp_f0;
    } else {
        return 0.0f;
    }
}

void func_801EDA80(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32* arg6, f32* arg7, f32* arg8) {
    *arg6 = (arg1 * arg5) - (arg2 * arg4);
    *arg7 = (arg2 * arg3) - (arg0 * arg5);
    *arg8 = (arg0 * arg4) - (arg1 * arg3);
}

void func_801EDAE0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32* arg6, f32* arg7, f32* arg8) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f16;
    f32 temp_f2;

    *arg6 = (arg1 * arg5) - (arg2 * arg4);
    *arg7 = (arg2 * arg3) - (arg0 * arg5);
    *arg8 = temp_f0 = (arg0 * arg4) - (arg1 * arg3);
    temp_f2 = *arg6;
    temp_f16 = *arg7;
    temp_f0_2 = sqrtf(SQ(temp_f0) + (SQ(temp_f2) + SQ(temp_f16)));

    if (temp_f0_2 > 0.0f) {
        *arg6 /= temp_f0_2;
        *arg7 /= temp_f0_2;
        *arg8 /= temp_f0_2;
    }
}

void func_801EDBD4(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5) {
    f32 temp_f0 = sqrtf((arg0 * arg0) + (arg1 * arg1) + (arg2 * arg2));

    if (temp_f0 > 0.0f) {
        *arg3 = arg0 / temp_f0;
        *arg4 = arg1 / temp_f0;
        *arg5 = arg2 / temp_f0;
    }
}

void func_801EDC60(MtxF_t arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4, f32* arg5, f32* arg6) {
    *arg4 = (arg0[0][0] * arg1) + arg0[1][0] * arg2 + (arg0[2][0] * arg3) + arg0[3][0];
    *arg5 = (arg0[0][1] * arg1) + arg0[1][1] * arg2 + (arg0[2][1] * arg3) + arg0[3][1];
    *arg6 = (arg0[0][2] * arg1) + arg0[1][2] * arg2 + (arg0[2][2] * arg3) + arg0[3][2];
}

void func_801EDD04(MtxF_t arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4, f32* arg5, f32* arg6) {
    *arg4 = (arg0[0][0] * arg1) + (arg0[1][0] * arg2) + (arg0[2][0] * arg3);
    *arg5 = (arg0[0][1] * arg1) + (arg0[1][1] * arg2) + (arg0[2][1] * arg3);
    *arg6 = (arg0[0][2] * arg1) + (arg0[1][2] * arg2) + (arg0[2][2] * arg3);
}

#define INTPART(x, y) dest->mu.intPart[x][y] = ((u32) fixedPoint >> 0x10)
#define FRACPART(x, y) dest->mu.fracPart[x][y] = fixedPoint & 0xFFFF

void _MtxF_to_Mtx(MtxF* src, Mtx* dest) {
    s32 fixedPoint;

    fixedPoint = src->mf[3][3] * 0x10000;
    INTPART(3, 3);
    FRACPART(3, 3);

    fixedPoint = src->mf[3][2] * 0x10000;
    INTPART(3, 2);
    FRACPART(3, 2);

    fixedPoint = src->mf[3][1] * 0x10000;
    INTPART(3, 1);
    FRACPART(3, 1);

    fixedPoint = src->mf[3][0] * 0x10000;
    INTPART(3, 0);
    FRACPART(3, 0);

    fixedPoint = src->mf[2][3] * 0x10000;
    INTPART(2, 3);
    FRACPART(2, 3);

    fixedPoint = src->mf[2][2] * 0x10000;
    INTPART(2, 2);
    FRACPART(2, 2);

    fixedPoint = src->mf[2][1] * 0x10000;
    INTPART(2, 1);
    FRACPART(2, 1);

    fixedPoint = src->mf[2][0] * 0x10000;
    INTPART(2, 0);
    FRACPART(2, 0);

    fixedPoint = src->mf[1][3] * 0x10000;
    INTPART(1, 3);
    FRACPART(1, 3);

    fixedPoint = src->mf[1][2] * 0x10000;
    INTPART(1, 2);
    FRACPART(1, 2);

    fixedPoint = src->mf[1][1] * 0x10000;
    INTPART(1, 1);
    FRACPART(1, 1);

    fixedPoint = src->mf[1][0] * 0x10000;
    INTPART(1, 0);
    FRACPART(1, 0);

    fixedPoint = src->mf[0][3] * 0x10000;
    INTPART(0, 3);
    FRACPART(0, 3);

    fixedPoint = src->mf[0][2] * 0x10000;
    INTPART(0, 2);
    FRACPART(0, 2);

    fixedPoint = src->mf[0][1] * 0x10000;
    INTPART(0, 1);
    FRACPART(0, 1);

    fixedPoint = src->mf[0][0] * 0x10000;
    INTPART(0, 0);
    FRACPART(0, 0);
}

void func_801EDF9C(MtxF_t arg0, f32 x, f32 y, f32 z) {
    arg0[3][3] = 1.0f;
    arg0[2][2] = 1.0f;
    arg0[1][1] = 1.0f;
    arg0[0][0] = 1.0f;

    arg0[2][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[0][3] = 0.0f;
    arg0[1][2] = 0.0f;
    arg0[0][2] = 0.0f;
    arg0[2][1] = 0.0f;
    arg0[0][1] = 0.0f;
    arg0[2][0] = 0.0f;
    arg0[1][0] = 0.0f;

    arg0[3][0] = x;
    arg0[3][1] = y;
    arg0[3][2] = z;
}

void func_801EDFFC(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3) {
    MtxF mtx;

    func_801EDF9C((float(*)[4]) & mtx, arg1, arg2, arg3);

    _MtxF_to_Mtx(&mtx, arg0);
}

#ifdef NON_MATCHING
void func_801EE040(float (*arg0)[4], f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    ((void) arg0);
    ((void) arg1);
    ((void) arg2);
    ((void) arg3);
    ((void) arg4);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EE040.s")
#endif

void func_801EE040(float (*)[4], f32, f32, f32, f32);

void func_801EE228(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    MtxF mtx;

    func_801EE040((float(*)[4]) & mtx, arg1, arg2, arg3, arg4);

    _MtxF_to_Mtx(&mtx, arg0);
}

#ifdef NON_MATCHING
void func_801EE274(float (*arg0)[4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    ((void) arg0);
    ((void) arg1);
    ((void) arg2);
    ((void) arg3);
    ((void) arg4);
    ((void) arg5);
    ((void) arg6);
    ((void) arg7);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EE274.s")
#endif

void func_801EE274(float (*)[4], f32, f32, f32, f32, f32, f32, f32);

void func_801EE46C(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    MtxF mtx;

    func_801EE274((float(*)[4]) & mtx, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    _MtxF_to_Mtx(&mtx, arg0);
}

#ifdef NON_MATCHING
void func_801EE4D0(float (*arg0)[4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    ((void) arg0);
    ((void) arg1);
    ((void) arg2);
    ((void) arg3);
    ((void) arg4);
    ((void) arg5);
    ((void) arg6);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EE4D0.s")
#endif

void func_801EE4D0(float (*)[4], f32, f32, f32, f32, f32, f32);

void func_801EE698(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    MtxF mtx;

    func_801EE4D0((float(*)[4]) & mtx, arg1, arg2, arg3, arg4, arg5, arg6);
    _MtxF_to_Mtx(&mtx, arg0);
}

#ifdef NON_MATCHING
void func_801EE6F4(float (*arg0)[4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    ((void) arg0);
    ((void) arg1);
    ((void) arg2);
    ((void) arg3);
    ((void) arg4);
    ((void) arg5);
    ((void) arg6);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EE6F4.s")
#endif

void func_801EE6F4(float (*)[4], f32, f32, f32, f32, f32, f32);

void func_801EE8C0(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    MtxF mtx;

    func_801EE6F4((float(*)[4]) & mtx, arg1, arg2, arg3, arg4, arg5, arg6);
    _MtxF_to_Mtx(&mtx, arg0);
}

void func_801EE91C(MtxF_t mf, f32 x, f32 y, f32 z) {
    mf[0][0] = x;
    mf[1][1] = y;
    mf[2][2] = z;

    mf[1][0] = 0.0f;
    mf[2][0] = 0.0f;

    mf[0][1] = 0.0f;
    mf[2][1] = 0.0f;

    mf[0][2] = 0.0f;
    mf[1][2] = 0.0f;

    mf[0][3] = 0.0f;
    mf[1][3] = 0.0f;
    mf[2][3] = 0.0f;

    mf[3][0] = 0.0f;
    mf[3][1] = 0.0f;
    mf[3][2] = 0.0f;

    mf[3][3] = 1.0f;
}

void func_801EE97C(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3) {
    MtxF sp18;

    func_801EE91C((float(*)[4]) & sp18, arg1, arg2, arg3);
    _MtxF_to_Mtx(&sp18, arg0);
}

#ifdef NON_MATCHING
void func_801EE9C0(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EE9C0.s")
#endif

#ifdef NON_MATCHING
void func_801EED70(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EED70.s")
#endif

#ifdef NON_MATCHING
void func_801EF3C4(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EF3C4.s")
#endif

#ifdef NON_MATCHING
void func_801EF504(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EF504.s")
#endif

#ifdef NON_MATCHING
void func_801EFFD8(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EFFD8.s")
#endif

#ifdef NON_MATCHING
void func_801F03E0(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F03E0.s")
#endif

#ifdef NON_MATCHING
void func_801F06A0(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F06A0.s")
#endif

#ifdef NON_MATCHING
void func_801F0E7C(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F0E7C.s")
#endif

#ifdef NON_MATCHING
void func_801F14B4(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F14B4.s")
#endif

#ifdef NON_MATCHING
void func_801F1CFC(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F1CFC.s")
#endif

#ifdef NON_MATCHING
void func_801F2060(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F2060.s")
#endif

#ifdef NON_MATCHING
void func_801F23A0(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F23A0.s")
#endif

#ifdef NON_MATCHING
void func_801F25E0(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F25E0.s")
#endif

#ifdef NON_MATCHING
void func_801F4120(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F4120.s")
#endif

#ifdef NON_MATCHING
void func_801F8DD0(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F8DD0.s")
#endif

#ifdef NON_MATCHING
void func_801F9520(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F9520.s")
#endif

#ifdef NON_MATCHING
void func_801F9EA0(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F9EA0.s")
#endif

#ifdef NON_MATCHING
void func_801FA3C0(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801FA3C0.s")
#endif

#ifdef NON_MATCHING
/* Bresenham line enumerator: fills xs/ys point arrays plus count.
   Diff floor 2097 probe-verified (TU has 16 pre-existing NON_MATCHING
   errors in unrelated drafts, so TU-wide build is impossible; probe only).
   Tried: decl computation-order (neutral), sign if/else (+210, bgtz wrong),
   sign goto (X-sign exact incl. delay-filled li's, Y lateral at bgtz).
   Remaining: dx/dy home rotation, ys-ptr s1 vs temp, sll+addu vs folded
   addiu for arg5/6+s0 (micro-proven fold; non-const s0 needs zero-cost
   mechanism), Y-sign bgtz. */
void func_801FAD68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32* arg4, s32* arg5, s32* arg6) {
    s32 var_v1;
    s32 var_t1;
    s32 var_v0;
    s32 var_t0;
    s32 var_t2;
    s32 sign;
    s32 var_t4;
    s32 err;
    s32 var_s0;
    s32* var_a1;
    s32* var_s1;

    var_v1 = arg2 - arg0;
    var_t1 = arg3 - arg1;
    var_v0 = var_v1;
    var_t0 = var_t1;
    if (var_v1 == 0) {
        var_t2 = 0;
    } else {
        if (var_v1 <= 0) {
            goto sign_neg_x;
        }
        sign = 1;
        goto sign_join_x;
    sign_neg_x:;
        sign = -1;
    sign_join_x:;
        var_t2 = sign;
    }
    if (var_t1 == 0) {
        var_t4 = 0;
    } else {
        if (var_t1 <= 0) {
            goto sign_neg_y;
        }
        sign = 1;
        goto sign_join_y;
    sign_neg_y:;
        sign = -1;
    sign_join_y:;
        var_t4 = sign;
    }
    err = 0;
    if (var_v1 < 0) {
        var_v0 = -var_v1;
    }
    var_v1 = arg0;
    if (var_t1 < 0) {
        var_t0 = -var_t1;
    }
    *arg5 = arg0;
    var_t1 = arg1;
    var_s0 = 1;
    *arg6 = arg1;
    if (var_v0 >= var_t0) {
        if (arg0 != arg2) {
            var_a1 = arg5 + var_s0;
            var_s1 = arg6 + var_s0;
            do {
                err += var_t0;
                var_v1 += var_t2;
                if ((err * 2) >= var_v0) {
                    err -= var_v0;
                    var_t1 += var_t4;
                }
                *var_a1 = var_v1;
                *var_s1 = var_t1;
                var_s0 += 1;
                var_a1 += 1;
                var_s1 += 1;
            } while (var_v1 != arg2);
        }
    } else if (arg1 != arg3) {
        var_a1 = arg5 + var_s0;
        var_s1 = arg6 + var_s0;
        do {
            err += var_v0;
            var_t1 += var_t4;
            if ((err * 2) >= var_t0) {
                err -= var_t0;
                var_v1 += var_t2;
            }
            *var_a1 = var_v1;
            *var_s1 = var_t1;
            var_s0 += 1;
            var_a1 += 1;
            var_s1 += 1;
        } while (var_t1 != arg3);
    }
    *arg4 = var_s0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801FAD68.s")
#endif

void func_801FAEA8(void) {
}

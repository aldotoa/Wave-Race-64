#include <ultra64.h>
#include "variables.h"
#include "rider.h"
#include "camera.h"
#include "libc/math.h"
#include "macros.h"

extern s16 D_800DAB60;
extern s32 D_800DA9F8;
extern s32 D_800DA9FC;
extern s32 D_800DAA08;
extern s32 D_801CB334;
extern s16 D_800EAC44[][4];
extern s16 D_800DA9AC;
extern s16 D_801CE60C;
extern s32 D_800DA9C8[];
extern s32 D_80226EF0[];
extern s32 D_801C293C;
extern RiderStruct D_801C2C70[];
s32 func_8009684C(s32, s16, s16);
void func_8004A208(void);

void func_801EB180(void) {
    s32 pad[2];
    s32 playerStartParam;
    s16 rivalStartParam;
    s32 i;
    s32 course;

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
    if (++D_800DA9F8 >= 3) {
        D_800DA9F8 = 0;
    }
    if (++D_800DA9FC >= 4) {
        D_800DA9FC = 0;
    }
    playerStartParam = D_800EAC44[D_800DA9FC][0];
    rivalStartParam = D_800EAC44[D_800DA9FC][1];
    for (i = 0; i < gRiders; i++) {
        D_80192690[i].unkB68 = rivalStartParam;
        D_80192690[i].unkB6C = D_800D96A4[gCourseID][rivalStartParam].unk0;
        D_80192690[i].unkB70 = D_800D96A4[gCourseID][rivalStartParam].unk4;
        D_80192690[i].unkB74 = D_800D96A4[gCourseID][rivalStartParam].unk8;
    }
    D_80192690[D_800D48DC].unkB68 = playerStartParam;
    D_80192690[D_800D48DC].unkB6C = D_800D96A4[gCourseID][playerStartParam].unk0;
    D_801CE6F4[1] = 0;
    D_80192690[D_800D48DC].unkB70 = D_800D96A4[gCourseID][playerStartParam].unk4;
    D_80192690[D_800D48DC].unkB74 = D_800D96A4[gCourseID][playerStartParam].unk8;
    D_801CE6F4[0] = D_801CE6F4[1];
    gRiderGameModes = 1;
    D_801CE64C = 0;
    gGameModeState = 3;
    func_80096960(1, playerStartParam, rivalStartParam, 0, 0);
    course = gCourseID;
    if (course < 0) {
        course = 0;
    }
    if (course >= 9) {
        course = 8;
    }
    func_8009684C(0x08060000, D_800DB568[course].unk0, D_800DB568[course].unk2);
    func_8004A208();
    FadeTransition_SetProps(0, 0, 0);
    func_801E6A4C(0, 0);
    gCameraPerspective->viewMode = 5;
    D_800DA9AC = 1;
    func_800C21F4(0, 0);
}

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

void func_801EBD28(void) {
    /* 2-Player Versus mode state init (GAME_STATE 10). The chained
       D_800DA9C8 store and the case-body order 4/0/11/1 are load-bearing. */
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 10;
    D_801CE638 = 4;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;
    gGameModes = 0;
    if (D_801CE60C == 1) {
        gPlayers = 1;
        gRiders = 1;
    } else {
        gPlayers = 2;
        gRiders = 2;
    }
    D_800D49B0 = 10;
    gBuoyMisses = 5;
    D_801CE728[0] = 3;
    gCourseID = 9;
    if (D_800DA9AC != 0) {
        D_800DA9C0[0] = 0;
        D_800DA9C0[1] = 3;
        D_800DA9C8[0] = D_800DA9C8[1] = 0;
    }
    D_80192690[D_800D48DC].unkB68 = D_80226EF0[D_800DA9C0[0]];
    D_80192690[D_800D48DC].unkB6C = D_800DA950[D_80192690[D_800D48DC].unkB68].unk_B[0];
    D_80192690[D_800D48DC].unkB70 = D_800DA950[D_80192690[D_800D48DC].unkB68].unk_B[1];
    D_80192690[D_800D48DC].unkB74 = D_800DA950[D_80192690[D_800D48DC].unkB68].unk_B[2];
    if (gPlayers == 2) {
        D_80192690[D_800D48E0].unkB68 = D_80226EF0[D_800DA9C0[1]];
        D_80192690[D_800D48E0].unkB6C = D_800DA950[D_80192690[D_800D48E0].unkB68].unk_B[0];
        D_80192690[D_800D48E0].unkB70 = D_800DA950[D_80192690[D_800D48E0].unkB68].unk_B[1];
        D_80192690[D_800D48E0].unkB74 = D_800DA950[D_80192690[D_800D48E0].unkB68].unk_B[2];
    }
    gRiderGameModes = 2;
    D_801CE64C = 2;
    gGameModeState = 3;
    D_800DAB64 = 0;
    func_80096960(3, 0, 1, 2, 3);
    FadeTransition_SetProps(2, 4, 0);
    func_801E6A4C(0, 0);
    gCameraPerspective[0].viewMode = 2;
    gCameraPerspective[1].viewMode = 2;
    switch (D_801CE608.gameMode) {
        case 4:
            func_800C21F4(1, 0);
            break;
        case 0:
            func_800C21F4(1, 2);
            break;
        case 11:
            func_800C21F4(1, 3);
            break;
        case 1:
            func_800C21F4(1, 1);
            break;
    }
}

void func_801EBFE4(void) {
    /* Course-select state init: default globals, fade transition, then
       camera + audio + VI-black tail. The gCameraPerspective store sits in
       the beqz delay slot (executes on both paths); spelled here as
       straight-line code before the if. */
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_COURSE_SELECT;
    D_801CE638 = 5;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = ONE_PLAYER;
    gCourseID = SUNNY_BEACH;
    gRiderGameModes = UNACTIVE_MODE;
    D_801CE64C = 1;
    gGameModeState = GMODE_STATE_0;
    FadeTransition_SetProps(2, 4, 0);
    func_801E6A4C(0, 0);
    gCameraPerspective[0].viewMode = 1;
    if (D_800DA9AC != 0) {
        D_800DA9D0 = 0;
    }
    func_800C21F4(0xA, 0);
    osViBlack(1);
}

void func_801EC0D4(void) {
    s32 i;
    s32 packedArgs[4];

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_RACE_RESULTS;
    D_801CE638 = 9;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = ONE_PLAYER;
    gRiderGameModes = UNACTIVE_MODE;
    D_801CE64C = 1;
    gGameModeState = 0;
    for (i = 0; i < 4; i++) {
        packedArgs[i] = i;
    }
    if (D_801CE6F4[0] != 0) {
        packedArgs[D_800DA9B0[D_800D48DC]] += 4;
    }
    func_80096960(2, packedArgs[0], packedArgs[1], packedArgs[2], packedArgs[3]);
    FadeTransition_SetProps(4, 1, 0);
    func_801E6A4C(0, 0);
    gCameraPerspective[0].viewMode = 1;
    osViBlack(1);
}

void func_801EC20C(void) {
    /* Time-trial results init: default globals, then (unless coming from
       GAME_STATE_64) rider table setup + fade/audio teardown. The 5th arg
       to func_80096960 goes in the 0x10(sp) outgoing slot. */
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_TIME_TRIALS_RESULTS;
    D_801CE638 = 3;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    gPlayers = ONE_PLAYER;
    gRiderGameModes = UNACTIVE_MODE;
    D_801CE64C = 1;
    gGameModeState = GMODE_STATE_0;
    if (gPrevGameState != GAME_STATE_64) {
        func_80096960(2, 0, 1, 2, 3);
        FadeTransition_SetProps(4, 1, 0);
        func_801E6A4C(0, 0);
    }
    gCameraPerspective[0].viewMode = 1;
    func_800C21F4(3, 0);
}

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

void func_801EC3AC(void) {
    /* Options change-names init (GAME_STATE 0x3E): default globals,
       rider-table entry setup from option bytes, then fade/audio
       teardown. The chained D_801CE6F4 store (sh 0 to [1], lh reload,
       sh to [0]) and inline D_80192690[D_800D48DC] indexing (no locals)
       are load-bearing for the register coloring. */
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
    gCourseID = RIDER_SELECTION;
    gRiderGameModes = AI_MODE;
    D_801CE64C = 2;
    gGameModeState = GMODE_STATE_STARTED;
    D_80192690[D_800D48DC].unkB68 = 0;
    D_80192690[D_800D48DC].unkB6C = D_800DA950[0].unk_B[0];
    D_80192690[D_800D48DC].unkB70 = D_800DA950[0].unk_B[1];
    D_80192690[D_800D48DC].unkB74 = D_800DA950[0].unk_B[2];
    D_801CE6F4[0] = D_801CE6F4[1] = 0;
    func_80096960(2, 0, 1, 2, 3);
    FadeTransition_SetProps(2, 4, 0);
    func_801E6A4C(0, 0);
    gCameraPerspective->viewMode = 2;
}

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
    s32 needsFade;

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

    needsFade = false;

    if (D_801CE608.gameMode == 4) {
        if (gPrevGameState == 0x43) {
            needsFade = true;
        }
    } else if ((gPrevGameState != 0x32) && (gPrevGameState != 0x39)) {
        needsFade = true;
    }
    if (needsFade) {
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

void func_801ECB98(void) {
    /* Award ceremony init: default globals, four AI riders placed on the
       Glacier Coast podium grid from their finishing order, then
       audio/fade/camera setup. The 4-rider loop is fully unrolled by IDO. */
    s32 i;
    s32 arg;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_CEREMONY;
    D_801CE638 = 0x15;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;
    gGameModes = GMODE_TIME_TRIALS;
    gPlayers = ONE_PLAYER;
    gRiders = 4;
    D_800D49B0 = 0xA;
    gBuoyMisses = 5;
    D_801CE728[0] = 3;
    gCourseID = GLACIER_COAST;
    D_800D8178 = 1;
    gRiderGameModes = AI_MODE;
    D_801CE64C = 0;
    gGameModeState = GMODE_STATE_STARTED;
    for (i = 0; i < 4; i++) {
        D_80192690[i].unkB68 = D_800DA9B0[i];
        D_80192690[i].unkB6C = D_800D96A4[gCourseID][D_800DA9B0[i]].unk0;
        D_80192690[i].unkB70 = D_800D96A4[gCourseID][D_800DA9B0[i]].unk4;
        D_80192690[i].unkB74 = D_800D96A4[gCourseID][D_800DA9B0[i]].unk8;
    }
    arg = D_800DA9B0[D_800D48DC];
    if (D_801CE6F4[0] != 0) {
        arg += 4;
    }
    func_80096960(2, arg, D_800DA9B0[1], D_800DA9B0[2], D_800DA9B0[3]);
    func_8009684C(0x08060000, 3, -1);
    FadeTransition_SetProps(7, 10, 0);
    func_801E6A4C(0, 0);
    gCameraPerspective[0].viewMode = 8;
    func_800C21F4(0xB, D_801C2C70[D_800D48DC].lapCount + 1);
}

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

    func_801EDF9C((float (*)[4]) & mtx, arg1, arg2, arg3);

    _MtxF_to_Mtx(&mtx, arg0);
}

#ifdef NON_MATCHING
/*
 * Axis-angle rotation matrix: libultra guRotateF with an inlined normalize and the gSinTable lookups.
 * Floor: 68 diff rows (probe); the 0x70 frame, the s/t stack slots and the 1.0f register already match.
 * Load-bearing: `one` used only by [3][3] and (one - xx), plus the empty `if (c) {}` right after the
 * [0][0] store. That splits the block, so retail's pre-branch `lui/mtc1 $f12` 1.0f survives while the
 * other 1.0f literals are rematerialized. Remaining: register choice only (target xx $f2, yy $f18 with
 * call spills, c $f24, zz $f26). The target looks like it has one extra hidden FPR live range holding $f16.
 */
void func_801EE040(float (*arg0)[4], f32 a, f32 x, f32 y, f32 z) {
    f32 s;
    f32 one;
    f32 yy;
    s32 idx;
    f32 mag;
    f32 xx;
    f32 zz;
    f32 bc;
    f32 c;
    f32 ca;
    f32 ab;
    f32 t;
    xx = x * x;
    yy = y * y;
    zz = z * z;
    mag = sqrtf(xx + yy + zz);
    if (mag > 0.0f) {
        x /= mag;
        y /= mag;
        xx = x * x;
        z /= mag;
        yy = y * y;
        zz = z * z;
    }
    one = 1.0f;
    s = gSinTable[(s32) ((a / 360.0f) * 4096.0f) & 0xFFF];
    c = gSinTable[((s32) ((a / 360.0f) * 4096.0f) + 0x400) & 0xFFF];
    arg0[3][0] = 0.0f;
    arg0[3][1] = 0.0f;
    arg0[3][2] = 0.0f;
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][3] = one;
    arg0[0][0] = ((one - xx) * c) + xx;
    if (c) {}
    t = 1.0f - c;
    if (mag) {}
    bc = y * z * t;
    arg0[2][1] = bc - (x * s);
    arg0[1][2] = (x * s) + bc;
    arg0[1][1] = ((1.0f - yy) * c) + yy;
    ca = z * x * t;
    arg0[2][0] = (y * s) + ca;
    arg0[0][2] = ca - (y * s);
    arg0[2][2] = ((1.0f - zz) * c) + zz;
    ab = x * y * t;
    arg0[1][0] = ab - (z * s);
    arg0[0][1] = (z * s) + ab;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EE040.s")
#endif

void func_801EE040(float (*)[4], f32, f32, f32, f32);

void func_801EE228(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    MtxF mtx;

    func_801EE040((float (*)[4]) & mtx, arg1, arg2, arg3, arg4);

    _MtxF_to_Mtx(&mtx, arg0);
}

#ifdef NON_MATCHING
/*
 * func_801EE040 plus translation (tx, ty, tz in row 3). Floor: 32 diff rows (probe), register choice only;
 * the instruction count, the 0x68 frame and the s/t/ca/ys slots match. Load-bearing: `one` for [3][3]/(one - xx), the
 * empty ifs after [0][0] and [2][2], and zz squared first. Remaining: IDO hands out caller-saved FPRs as
 * $f2, $f16, $f18 in priority order. Retail has xx $f16, yy $f18 and zz callee-saved $f24, as if a
 * hidden range already holds $f2. No tested construct reproduces that: register keyword, decl order,
 * PRE/inline squares, uninitialized-read empty ifs, constant vars, decomp-permuter runs.
 */
void func_801EE274(float (*arg0)[4], f32 a, f32 x, f32 y, f32 z, f32 tx, f32 ty, f32 tz) {
    f32 s;
    f32 yy;
    f32 mag;
    s32 idx;
    f32 one;
    f32 c;
    f32 ab;
    f32 zz;
    f32 xx;
    zz = z * z;
    xx = x * x;
    yy = y * y;
    mag = sqrtf(xx + yy + zz);
    if (mag > 0.0f) {
        x /= mag;
        y /= mag;
        xx = x * x;
        z /= mag;
        yy = y * y;
        zz = z * z;
    }
    one = 1.0f;
    idx = (a / 360.0f) * 4096.0f;
    s = gSinTable[idx & 0xFFF];
    c = gSinTable[(idx + 0x400) & 0xFFF];
    arg0[3][0] = tx;
    arg0[3][1] = ty;
    arg0[3][2] = tz;
    arg0[0][3] = arg0[1][3] = arg0[2][3] = 0.0f;
    arg0[3][3] = one;
    arg0[0][0] = ((one - xx) * c) + xx;
    if (yy) {}
    arg0[2][1] = (y * z * (1.0f - c)) - (x * s);
    arg0[1][2] = (x * s) + (y * z * (1.0f - c));
    arg0[1][1] = ((1.0f - yy) * c) + yy;
    arg0[2][0] = (y * s) + (z * x * (1.0f - c));
    arg0[0][2] = (z * x * (1.0f - c)) - (y * s);
    arg0[2][2] = ((1.0f - zz) * c) + zz;
    if (zz) {}
    ab = x * y * (1.0f - c);
    arg0[1][0] = ab - (z * s);
    arg0[0][1] = (z * s) + ab;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EE274.s")
#endif

void func_801EE274(float (*)[4], f32, f32, f32, f32, f32, f32, f32);

void func_801EE46C(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    MtxF mtx;

    func_801EE274((float (*)[4]) & mtx, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    _MtxF_to_Mtx(&mtx, arg0);
}

void func_801EE4D0(float (*arg0)[4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 s1, s2, s3, c1, c2, c3;
    f32 temp;

    s1 = gSinTable[(s32) ((arg1 / 360.0f) * 4096.0f) & 0xFFF];
    s2 = gSinTable[(s32) ((arg2 / 360.0f) * 4096.0f) & 0xFFF];
    s3 = gSinTable[(s32) ((arg3 / 360.0f) * 4096.0f) & 0xFFF];
    c1 = gSinTable[((s32) ((arg1 / 360.0f) * 4096.0f) + 0x400) & 0xFFF];
    c2 = gSinTable[((s32) ((arg2 / 360.0f) * 4096.0f) + 0x400) & 0xFFF];
    c3 = gSinTable[((s32) ((arg3 / 360.0f) * 4096.0f) + 0x400) & 0xFFF];

    temp = s1 * s2;
    arg0[0][0] = c2 * c3;
    arg0[1][0] = (-c1 * s3) + (temp * c3);
    arg0[2][0] = (s1 * s3) + (c1 * s2 * c3);
    arg0[3][0] = arg4;

    arg0[0][1] = c2 * s3;
    arg0[1][1] = (c1 * c3) + (temp * s3);
    arg0[2][1] = (-s1 * c3) + (c1 * s2 * s3);
    arg0[3][1] = arg5;

    arg0[0][2] = -s2;
    arg0[1][2] = s1 * c2;
    arg0[2][2] = c1 * c2;
    arg0[3][2] = arg6;

    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][3] = 1.0f;
}

void func_801EE4D0(float (*)[4], f32, f32, f32, f32, f32, f32);

void func_801EE698(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    MtxF mtx;

    func_801EE4D0((float (*)[4]) & mtx, arg1, arg2, arg3, arg4, arg5, arg6);
    _MtxF_to_Mtx(&mtx, arg0);
}

void func_801EE6F4(float (*arg0)[4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 s1, s2, s3, c1, c2, c3;
    f32 temp;

    s1 = gSinTable[(s32) ((arg1 / 360.0f) * 4096.0f) & 0xFFF];
    s2 = gSinTable[(s32) ((arg2 / 360.0f) * 4096.0f) & 0xFFF];
    s3 = gSinTable[(s32) ((arg3 / 360.0f) * 4096.0f) & 0xFFF];
    c1 = gSinTable[((s32) ((arg1 / 360.0f) * 4096.0f) + 0x400) & 0xFFF];
    c2 = gSinTable[((s32) ((arg2 / 360.0f) * 4096.0f) + 0x400) & 0xFFF];
    c3 = gSinTable[((s32) ((arg3 / 360.0f) * 4096.0f) + 0x400) & 0xFFF];

    temp = s1 * s2;
    arg0[0][0] = (temp * s3) + (c2 * c3);
    arg0[1][0] = (temp * c3) - (c2 * s3);

    arg0[2][0] = c1 * s2;
    temp = s1 * c2;
    arg0[3][0] = arg4;
    arg0[0][1] = c1 * s3;
    arg0[1][1] = c1 * c3;
    arg0[2][1] = -s1;

    arg0[3][1] = arg5;
    arg0[0][2] = (temp * s3) - (s2 * c3);
    arg0[1][2] = (temp * c3) + (s2 * s3);
    arg0[2][2] = c1 * c2;
    arg0[3][2] = arg6;
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][3] = 1.0f;
}

void func_801EE6F4(float (*)[4], f32, f32, f32, f32, f32, f32);

void func_801EE8C0(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    MtxF mtx;

    func_801EE6F4((float (*)[4]) & mtx, arg1, arg2, arg3, arg4, arg5, arg6);
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

    func_801EE91C((float (*)[4]) & sp18, arg1, arg2, arg3);
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

extern u16 D_80228D24;
extern f32 D_80227A24;
void func_800481E0(Mtx*, u16*, f32, f32, f32, f32, f32, f32);
void func_800484C8(Mtx*, MtxF*, f32, f32, f32, f32, f32, f32, f32, f32, f32);

/* Builds the four static projection matrices: perspective, look-at, and two
 * orthographic views (race viewport plus full-screen panel). viewMtxF is the
 * float scratch passed to the look-at builder. */
void func_801EF3C4(void) {
    MtxF viewMtxF;

    func_800481E0((Mtx*) ((u8*) D_801AE948 + 0x4080), &D_80228D24, 24.0f, 4.0f / 3.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_800484C8((Mtx*) ((u8*) D_801AE948 + 0x40C0), &viewMtxF, 0.0f, 512.0f, D_80227A24, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                  0.0f);
    guOrtho((Mtx*) ((u8*) D_801AE948 + 0x4000), -160.0f, 160.0f, -120.0f, 120.0f, -1024.0f, 1024.0f, 1.0f);
    guOrtho((Mtx*) ((u8*) D_801AE948 + 0x4040), 0.0f, 320.0f, 240.0f, 0.0f, -1024.0f, 1024.0f, 1.0f);
}

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

extern s32 D_80228D08;
extern s32 D_80228D0C;
extern s32 D_80228D10;
extern s8 D_80228B58[];
extern RiderStruct D_801C2938[];
extern s32 D_800D817C;

/*
 * Start-countdown driver. D_80228A90 is read directly everywhere (no local):
 * IDO CSEs it into a spilled stack temp, and the abs() result is coalesced
 * with that temp's reload. A named local leaves an extra v0->a2 move.
 */
void func_801F03E0(void) {
    s32 i;
    s32 d;

    if (gGameModeState == 1 || gGameModeState == 2) {
        if (D_80228D08 == 0) {
            D_80228D0C -= 3;
            if (D_80228D0C <= 0) {
                D_80228D0C = 0;
                D_80228D08 = 1;
            }
        } else {
            if (D_80228A90 % 15 == 0) {
                if (gGameModeState != 2) {
                    AudioGeneral_PlaySound(0x22, D_80228A90 / 15 - 1);
                } else {
                    AudioGeneral_PlaySound(0x23, 0);
                }
            }
            d = D_80228A90 - 15;
            if (d < 0) {
                d = -d;
            }
            if (d < 15) {
                for (i = 0; i < gRiders; i++) {
                    if ((D_80192690[i].unkB58 & 0xA000) && (D_80228B58[i] == 0)) {
                        if (d < 1) {
                            D_801C2938[i].unk12C = 5;
                        } else if (d < 2) {
                            D_801C2938[i].unk12C = 4;
                        } else if (d < 3) {
                            D_801C2938[i].unk12C = 3;
                        } else if (d < 4) {
                            D_801C2938[i].unk12C = 2;
                        } else if (d < 5) {
                            D_801C2938[i].unk12C = 1;
                        }
                        if (d < 5) {
                            D_801C2938[i].unk314 = 1;
                            D_801C2938[i].unk28 = 1;
                        }
                        D_80228B58[i] = 1;
                    }
                }
            }
            D_80228A90--;
            if (D_80228A90 == 15) {
                gGameModeState = 2;
                D_800D817C = 0;
            } else if (D_80228A90 <= 0) {
                gGameModeState = 3;
                D_80228D08 = 2;
            }
        }
    } else if (D_80228D08 == 2) {
        if (gCurrentPauseMenuOption == -1) {
            D_80228D0C += 6;
            if (D_80228D0C >= D_80228D10) {
                D_80228D08 = 0;
            }
        }
    }
}

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

void func_801F23A0(void) {
    f32 range;
    f32 lo;
    s32 i;
    f32 t;
    RiderStruct* rs;
    s32 step;
    s32 absDiff;
    UnkStruct_80192690* r;

    for (i = 0; i < gRiders; i++) {
        r = &D_80192690[i];
        rs = &D_801C2938[i];
        t = r->unkBBC - r->unkBC0;
        lo = r->unkBC0 - t / 5.0f;
        range = (t * 6.0f) / 5.0f;
        t = r->unkB98;
        if (lo <= r->unkB98) {
            if (0.0f < range) {
                t = (r->unkB98 - lo) / range;
            }
            if (0.0f > t) {
                t = 0.0f;
            }
            if (1.0f < t) {
                t = 1.0f;
            }
            rs->unk2CC = t * 180.0f;
            rs->unk2CC += (Math_Rand(3) * 2) - 2;
            if (rs->unk2CC >= 181) {
                rs->unk2CC = 180;
            }
        } else {
            rs->unk2CC = (r->unkB98 / lo) * 36.0f;
        }
        absDiff = ABS(rs->unk2CC - rs->unk2C8);
        step = absDiff / 4;
        if (step < 2) {
            step = 2;
        }
        if (rs->unk2CC > rs->unk2C8) {
            if (step >= 5) {
                step = 4;
            }
        }
        if (step >= absDiff) {
            rs->unk2C8 = rs->unk2CC;
        } else {
            rs->unk2C8 += SIGNUM(rs->unk2CC - rs->unk2C8) * step;
        }
    }
}

#ifdef NON_MATCHING
void func_801F25E0(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801F25E0.s")
#endif

#ifdef NON_MATCHING
/*
 * HUD overlay (lap list, race/split times, position, lap counter, speed, buoys, boost meter,
 * stunt score, time-trial best times). Draft parked at 1797 diff rows (266 register-blind)
 * against a 4908-insn target; instruction count, frame (0x700) and control flow match.
 * Load-bearing:
 *  - 15 named locals in this declaration order (homes 0x6FC i, 0x6F4 j, 0x6CC/0x6C8 x2/y2,
 *    0x6C4 gfx) plus one f32; every extra local grows the frame.
 *  - RGBA32 textures typed u32[] (element strides) and ternary / empty-else shapes where the
 *    target emits a branch to the next label.
 *  - `scale` is the target's 1.8f literal (rodata 0x80227A4C, which lives in the next TU's
 *    .rodata), loaded in the loop preheader via the explicit gPlayers guard.
 * Remaining rows are register allocation: IDO hoists &D_80228B50/&D_80228B54 and some large
 * GBI constants into s-regs that the target rematerializes. The empty-if / self-assign fakes
 * came from an annealing search and only shift allocation priorities.
 */
typedef struct UnkStruct_80228D28 {
    s32 unk0;
    s32 unk4;
    char pad8[0xC];
} UnkStruct_80228D28; /* size = 0x14 */

typedef struct UnkStruct_80228C30 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x38];
} UnkStruct_80228C30; /* size = 0x54 */

extern Gfx D_1014708[];
extern u8 D_102DF50[];
extern u8 D_102E3D8[];
extern u8 D_102E620[];
extern u8 D_102E868[];
extern u32 D_102EE70[];
extern u8 D_1032078[];
extern u8 D_1032500[];
extern u8 D_1032B08[];
extern u8 D_10331D0[];
extern u8 D_10337D8[];
extern u8 D_1033C60[];
extern u8 D_1039248[];
extern u32 D_103B4D0[];
extern u8 D_103D5D0[];
extern u32 D_103D8D8[];
extern u8 D_10416A8[];
extern u8 D_1042780[];
extern u8 D_8024008[];
extern u32 D_8024BC8[];
extern u32 D_80273D8[];
extern u8 D_802A5E0[];
extern u32 D_802C3E8[];
extern s32 D_801C1FDC;
extern char* D_801C1FE4;
extern char* D_801C1FE8;
extern s32 D_800D4B00;
extern s32 D_801CE704;
extern u8* D_80227978[];
extern char D_802279E0[];
extern char D_802279EC[];
extern f32 D_80227A4C;
extern s32 D_80228A9C;
extern s32 D_80228AAC;
extern s32 D_80228AB0;
extern s32 D_80228AB4;
extern s32 D_80228B50;
extern s32 D_80228B54;
extern UnkStruct_80228C30 D_80228C30[];
extern s8 D_80228CF8[];
extern UnkStruct_80228D28 D_80228D28[];
extern s32 D_80228DF8;

void func_801F25E0(Gfx**, s32, s32, s32, s32, s32, s32);
Gfx* func_801E8A84(Gfx*, s32, char*, s32, s32, s32, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8);
Gfx* func_801E92FC(Gfx*, s32, char*, s32, s32, s32, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8);

#define RECT(xl, yl, xh, yh) gSPTextureRectangle(gfx++, (xl) << 2, (yl) << 2, (xh) << 2, (yh) << 2, 0, 0, 0, 1 << 10, 1 << 10)
#define SCISRECT(xl, yl, xh, yh) \
    gSPScisTextureRectangle(gfx++, (xl) << 2, (yl) << 2, (xh) << 2, (yh) << 2, 0, 0, 0, 1 << 10, 1 << 10)

void func_801F4120(Gfx** gfxP) {
    s32 i;
    s32 x;
    s32 j;
    s32 val;
    s8* p;
    RiderStruct* rs;
    s32 k;
    s32 y;
    UnkStruct_80228C30* pc;
    s32 m;
    s32 f;
    f32 scale;
    s32 x2;
    s32 y2;
    Gfx* gfx;
    s32 n;

    gfx = *gfxP;
    gSPDisplayList(gfx++, D_1014708);
    if ((gGameModes == GMODE_CHAMPIONSHIP || gGameModes == GMODE_TIME_TRIALS) && gCourseID != DOLPHIN_PARK) {
        rs = &D_801C2938[D_800D48DC];
        if (p) {}
        if (rs->lapCount >= 2 || D_800D8178 != 0) {
            n = rs->lapCount - 1;
            y = 0x34;
            if (n >= 10) {
                k = n - 9;
                n = 9;
            } else {
                k = 0;
            }
            if (rs->unk2F4 != 0 || D_800D8178 != 0) {
                n++;
            }
            j = 0;
            if (n > 0) {
                do {
                    func_801F25E0(&gfx, D_80228B54 + 0x18, y, rs->unk178[j], 0, (k + j + 1) % 10, 0);
                    if (y) {}
                    if (val) {}
                    j++;
                    if (n) {}
                    y += 10;
                } while (j != n);
            }
        }
        if (rs->unk2F4 != 0 || rs->unk2EC == 2) {
            if (pc) {}
            i = 0;
        } else {
            i = 1;
        }
        func_801F25E0(&gfx, D_80228B50 + 0x18, 0x22, rs->unk19C, 1, i, rs->unk16C);
    } else if (gGameModes == GMODE_2P_VS) {
        rs = &D_801C2938[D_800D48DC];
        if (rs->unk2F4 != 0) {
            i = 0;
        } else {
            i = 1;
        }
        func_801F25E0(&gfx, 0x18, 0xE, rs->unk19C, 1, i, rs->unk16C);
        rs = &D_801C2938[D_800D48E0];
        if (rs->unk2F4 != 0) {
            i = 0;
        } else {
            i = 1;
        }
        func_801F25E0(&gfx, 0x18, 0x7C, rs->unk19C, 1, i, rs->unk16C);
    }
    if (gGameModes == GMODE_CHAMPIONSHIP && gCourseID != DOLPHIN_PARK && D_801C1FDC >= 40) {
        for (j = 0; j < gRiders; j++) {
            if (D_801C2938[j].unk2F4 != 0 && D_801C2938[j].racePosition == 0) {
                break;
            }
        }
        if (j >= gRiders) {
            j = 0;
        }
        k = D_801C2938[j].unk19C;
        for (i = 0; i < gRiders; i++) {
            rs = &D_801C2938[i];
            if (D_801C1FDC >= rs->racePosition * 10 + 40) {
                x = D_80228D28[i].unk0 + 0xB0;
                y = D_80228D28[i].unk4 + 0x3F;
                m = (i == D_800D48DC) ? 2 : 1;
                if (i == j) {
                    func_801F25E0(&gfx, x + D_80228B50, y, rs->unk19C, 3, 3, m);
                } else if (rs->unk2F4 != 0) {
                    func_801F25E0(&gfx, x + D_80228B50, y, rs->unk19C - k, 3, 1, m);
                }
            }
        }
    }
    if (gGameModes == GMODE_2P_VS) {
        for (i = 0; i < gPlayers; i++) {
            y = 0xB2;
            if (i == 0) {
                y = 0x44;
                rs = &D_801C2938[D_800D48DC];
            } else {
                rs = &D_801C2938[D_800D48E0];
            }
            if (rs->unk300 != 0) {
                if (rs->unk2F8 < 10000) {
                    x = -15;
                } else if (rs->unk2F8 < 60000) {
                    x = -10;
                } else {
                    x = 0;
                }
                m = (rs->unk2FC == 1) ? 1 : 2;
                func_801F25E0(&gfx, x + 0x80, y, rs->unk2F8, 3, rs->unk2FC, m);
            }
        }
    }
    if (gGameModes == GMODE_CHAMPIONSHIP && gCourseID != DOLPHIN_PARK) {
        for (i = 0; i < gRiders; i++) {
            if (i != D_800D48DC) {
                rs = &D_801C2938[i];
                x = D_80228D28[i].unk0 + 0xBA;
                y = D_80228D28[i].unk4 + 0x3F;
                if (rs->unk300 != 0) {
                    func_801F25E0(&gfx, x, y, rs->unk2F8, 3, rs->unk2FC, 1);
                }
            }
        }
    }
    if (gGameModes == GMODE_CHAMPIONSHIP || gGameModes == GMODE_TIME_TRIALS) {
        rs = &D_801C2938[D_800D48DC];
        if (rs->unk300 != 0) {
            m = 2;
            if (rs->unk2F8 < 10000) {
                j = 2;
            } else if (rs->unk2F8 < 60000) {
                j = 1;
            } else {
                j = 0;
            }
            x = 0x8C;
            if (j == 1) {
                x = 0x85;
            } else if (j == 2) {
                x = 0x7F;
            }
            if (gGameModes == GMODE_TIME_TRIALS && rs->unk2FC == 1) {
                m = 1;
            } else {
            }
            if (p) {}
            func_801F25E0(&gfx, x, 0x7E, rs->unk2F8, 3, rs->unk2FC, m);
            gDPPipeSync(gfx++);
            gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            x -= 40;
            y = 122;
            if (j == 1) {
                x += 15;
            } else if (j == 2) {
                x += 26;
            }
            if (gGameModes == GMODE_CHAMPIONSHIP) {
                if (val) {}
                gDPLoadTextureBlock(gfx++, D_10416A8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                RECT(x, y, x + 32, y + 20);
                x += 9;
                y += 2;
                gDPLoadTextureBlock(gfx++, D_80227978[D_80192690[rs->unk33C].unkB68], G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 16) << 2, (y + 16) << 2, 0, 0, 0, 0x500, 0x500);
            } else {
                if (p) {}
                gDPLoadTextureBlock(gfx++, D_1042780, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                x -= 6;
                RECT(x, y, x + 32, y + 20);
            }
        }
    }
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    if ((gGameModes == GMODE_CHAMPIONSHIP || gGameModes == GMODE_TIME_TRIALS) && gCourseID != DOLPHIN_PARK) {
        gDPLoadTextureBlock(gfx++, D_1032500, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        RECT(D_80228B50 + 0x38, 21, D_80228B50 + 0x58, 33);
    }
    if (gGameModes != GMODE_STUNT && gCourseID != DOLPHIN_PARK) {
        if (gPlayers == ONE_PLAYER) {
            y = 0x15;
            if (gGameModes == GMODE_CHAMPIONSHIP) {
                x = D_80228B50 + 0xBC;
            } else {
                x = 0x84;
            }
        } else {
            x = 0xCA;
            y = 0xD;
            x2 = 0xCA;
            y2 = 0x7B;
        }
        gDPLoadTextureBlock(gfx++, D_1032078, G_IM_FMT_RGBA, G_IM_SIZ_32b, 24, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        RECT(x, y, x + 24, y + 12);
        if (gPlayers == TWO_PLAYERS) {
            RECT(x2, y2, x2 + 24, y2 + 12);
        }
        for (i = 0; i < gPlayers; i++) {
            if (f) {}
            if (gPlayers == ONE_PLAYER) {
                y = 0x22;
                if (y) {}
                if (gGameModes == GMODE_CHAMPIONSHIP) {
                    x = D_80228B50 + 0xC0;
                } else {
                    x = 0x88;
                }
                val = D_801C2938[D_800D48DC].lapCount;
            } else {
                x = 0xD0;
                if (i == 0) {
                    y = 0x19;
                    val = D_801C2938[D_800D48DC].lapCount;
                } else {
                    y = 0x87;
                    val = D_801C2938[D_800D48E0].lapCount;
                }
            if (y) {}
            }
            if (D_801CE728[0] < val) {
                val = D_801CE728[0];
            }
            if (gPlayers == ONE_PLAYER) {
                gDPLoadTextureBlock(gfx++, D_103D8D8 + (val % 10) * 0x140, G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                RECT(x, y, x + 16, y + 20);
            } else {
                gDPLoadTextureBlock(gfx++, D_103B4D0 + (val % 10) * 0xC0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                if (val) {}
                if (y2) {}
                RECT(x, y, x + 12, y + 16);
            }
        }
    }
    if (gGameModes == GMODE_CHAMPIONSHIP) {
        if (gCourseID != DOLPHIN_PARK) {
            gDPLoadTextureBlock(gfx++, D_1032B08, G_IM_FMT_RGBA, G_IM_SIZ_32b, 36, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            RECT(D_80228B50 + 0x84, 21, D_80228B50 + 0xA8, 33);
            gDPLoadTextureBlock(gfx++, D_103D8D8 + (D_801C2938[D_800D48DC].racePosition + 1) * 0x140, G_IM_FMT_RGBA, G_IM_SIZ_32b, 16,
                    20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            x = D_80228B50 + 0x88;
            if (D_80228A9C == 0) {
                RECT(x, 34, x + 16, 54);
            } else {
                if (p) {}
                k = D_80228DF8 * 6;
                gDPPipeSync(gfx++);
                gDPSetTextureFilter(gfx++, G_TF_BILERP);
                gSPTextureRectangle(gfx++, (x - k) << 2, 34 << 2, (x + 16) << 2, (k + 54) << 2, 0, 0, 0,
                                    0x4000 / (k + 16), 0x5000 / (k + 20));
                gDPPipeSync(gfx++);
                gDPSetTextureFilter(gfx++, G_TF_POINT);
            }
            gDPPipeSync(gfx++);
            if (f) {}
            gDPSetCombine(gfx++, 0x129A25, 0xFF37FFFF);
            if (D_801CE704 < D_801C2938[D_800D48DC].racePosition) {
                gDPSetEnvColor(gfx++, D_80228AAC, D_80228AB0, D_80228AB4, 255);
            if (x2) {}
            } else {
                gDPSetEnvColor(gfx++, 255, 255, 255, 255);
            }
            gDPLoadTextureBlock(gfx++, D_1033C60, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 10, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            RECT(D_80228B50 + 0x9B, 32, D_80228B50 + 0xA3, 42);
            if (D_801CE704 < 4) {
                n = D_801CE704 + 1;
            } else {
                n = 0x25;
            }
            gDPLoadTextureBlock(gfx++, D_1039248 + n * 0xC0, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            RECT(D_80228B50 + 0x9A, 42, D_80228B50 + 0xAA, 54);
            gDPPipeSync(gfx++);
            gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        }
    }
    gDPLoadTextureBlock(gfx++, D_10331D0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    if (gGameModes == GMODE_STUNT) {
        RECT(236, 22, 268, 34);
    } else if (gPlayers == ONE_PLAYER) {
        if (gCourseID == DOLPHIN_PARK) {
            n = 0xD9;
        } else if (gGameModes == GMODE_TIME_TRIALS) {
            n = 0x97;
        } else {
            n = 0xD9;
        }
        RECT(n + D_80228B50 + 0x18, 21, n + D_80228B50 + 0x38, 33);
    } else {
        RECT(242, 13, 274, 25);
        RECT(242, 123, 274, 135);
    }
    if (gPlayers > 0) {
        scale = D_80227A4C;
        i = 0;
        do {
            if (gPlayers == ONE_PLAYER) {
                y = 0x22;
                x = D_80228B50 + 0xE1;
                val = D_80192690[D_800D48DC].unkB90;
            } else if (i == 0) {
                x = 0xEC;
                y = 0x19;
                val = D_80192690[D_800D48DC].unkB90;
            } else {
                x = 0xEC;
                y = 0x87;
                val = D_80192690[D_800D48E0].unkB90;
            }
            if (gCourseID == DOLPHIN_PARK) {
                x = 0xE1;
            } else if (gGameModes == GMODE_TIME_TRIALS) {
                x = 0x9F;
            if (p) {}
            }
            val = val * scale;
            if (val >= 1000) {
                j = j;
                val = 999;
            }
            if (gGameModes == GMODE_STUNT) {
                x = 0xE4;
                if (i) {}
                y = 0x26;
                y = y;
                if (val >= 100) {
                    pc = pc;
                    gDPLoadTextureBlock(gfx++, D_802C3E8 + (val / 100) * 0xC0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    RECT(x, y, x + 12, y + 16);
                if (val) {}
                }
                x += 14;
                if (val) {}
                if (val >= 10) {
                    gDPLoadTextureBlock(gfx++, D_802C3E8 + ((val % 100) / 10) * 0xC0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    RECT(x, y, x + 12, y + 16);
                }
                x += 14;
                gDPLoadTextureBlock(gfx++, D_802C3E8 + (val % 10) * 0xC0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                RECT(x, y, x + 12, y + 16);
            } else if (gPlayers == ONE_PLAYER) {
                if (val >= 100) {
                    gDPLoadTextureBlock(gfx++, D_103D8D8 + (val / 100) * 0x140, G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    if (pc) {}
                    RECT(x, y, x + 16, y + 20);
                }
                x += 16;
                if (val >= 10) {
                    gDPLoadTextureBlock(gfx++, D_103D8D8 + ((val % 100) / 10) * 0x140, G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    RECT(x, y, x + 16, y + 20);
                }
                x += 16;
                gDPLoadTextureBlock(gfx++, D_103D8D8 + (val % 10) * 0x140, G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                RECT(x, y, x + 16, y + 20);
            y = y;
            } else {
                val = val;
                if (val >= 100) {
                    if (i) {}
                    gDPLoadTextureBlock(gfx++, D_103B4D0 + (val / 100) * 0xC0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    f = f;
                    RECT(x, y, x + 12, y + 16);
                }
                p = p;
                x = x;
                x += 13;
                if (val >= 10) {
                    gDPLoadTextureBlock(gfx++, D_103B4D0 + ((val % 100) / 10) * 0xC0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    if (pc) {}
                    y = y;
                    RECT(x, y, x + 12, y + 16);
                }
                x += 13;
                gDPLoadTextureBlock(gfx++, D_103B4D0 + (val % 10) * 0xC0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                RECT(x, y, x + 12, y + 16);
            }
            i++;
        } while (i < gPlayers);
    }
    gDPLoadTextureBlock(gfx++, D_10337D8, G_IM_FMT_RGBA, G_IM_SIZ_32b, 24, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    if (gGameModes == GMODE_STUNT) {
        RECT(0x10E, 0x2B, 0x126, 0x37);
    } else if (gPlayers == ONE_PLAYER) {
        if (p) {}
        if (gCourseID == DOLPHIN_PARK) {
            n = 0xD9;
        } else if (gGameModes == GMODE_TIME_TRIALS) {
            n = 0x97;
        } else {
            k = k;
            n = 0xD9;
        }
        RECT(n + D_80228B50 + 0x39, 42, n + D_80228B50 + 0x51, 54);
    } else {
        RECT(0x114, 0x1E, 0x12C, 0x2A);
        RECT(0x114, 0x8C, 0x12C, 0x98);
    }
    n = n;
    if (gGameModes != GMODE_STUNT && gCourseID != DOLPHIN_PARK) {
        if (gPlayers == ONE_PLAYER) {
            x = D_80228B54 + 0x18;
            y = 0xCD;
            gDPLoadTextureBlock(gfx++, D_102DF50, G_IM_FMT_RGBA, G_IM_SIZ_32b, 24, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            SCISRECT(x, y, x + 24, y + 12);
        }
        gDPLoadTextureBlock(gfx++, D_102E3D8, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        n = gBuoyMisses;
        if (n >= 29) {
            n = 28;
        }
        for (i = 0; i < gPlayers; i++) {
            if (gPlayers == ONE_PLAYER) {
                y = 0xCD;
                x = D_80228B54 + 0x38;
            } else {
                x = 0x18;
                y = (i == 0) ? 0x68 : 0xD6;
            }
            for (j = 0; j < n; j++) {
                SCISRECT(x, y, x + 12, y + 12);
                x += 14;
            }
        if (x2) {}
        }
        pc = D_80228C30;
        gDPLoadTextureBlock(gfx++, D_102E620, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        for (i = 0; i < gPlayers; i++, pc++) {
            if (gPlayers == ONE_PLAYER) {
                p = p;
                y = 0xCD;
                m = D_801C2938[D_800D48DC].unk134;
                x = D_80228B54 + 0x38;
            } else {
                x = 0x18;
                n = n;
                if (i == 0) {
                    y = 0x68;
                    m = D_801C2938[D_800D48DC].unk134;
                } else {
                    y = 0xD6;
                    m = D_801C2938[D_800D48E0].unk134;
                if (i) {}
                if (y) {}
                }
            j = j;
            }
            if (pc->unk18 == 1) {
                m--;
            }
            if (x) {}
            k = n - m;
            if (k < 0) {
                x = x;
                if (x2) {}
                k = 0;
            p = p;
            }
            x += k * 14;
            for (j = k; j < n; j++) {
                SCISRECT(x, y, x + 12, y + 12);
                x += 14;
            }
        y2 = y2;
        }
    }
    if (gCourseID != DOLPHIN_PARK && gGameModes != GMODE_STUNT) {
        x = x;
        if (gPlayers == ONE_PLAYER) {
            x = D_80228B54 + 0x94;
            y = 0xCD;
            gDPLoadTextureBlock(gfx++, D_102E868, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            SCISRECT(x, y, x + 32, y + 12);
        }
        for (i = 0; i < gPlayers; i++) {
            if (i) {}
            if (gPlayers == ONE_PLAYER) {
                y = 0xCF;
                m = D_801C2938[D_800D48DC].unk138;
                x = D_80228B54 + 0xBC;
            } else {
                y = 0x6A;
                j = j;
                x = 0xBC;
                if (i == 0) {
                    x = x;
                    j = j;
                    x = 0xBC;
                    m = D_801C2938[D_800D48DC].unk138;
                } else {
                    y = 0xD8;
                    m = D_801C2938[D_800D48E0].unk138;
                p = p;
                x = x;
                }
            }
            for (j = 0; j < 5; j++) {
                k = j + 1;
                if (m == k) {
                    f = D_800D4B00 % 6;
                    if (f >= 4) {
                        y = y;
                        f = 6 - f;
                    }
                if (pc) {}
                } else {
                    pc = pc;
                    f = (j < m) ? 3 : 0;
                }
                gDPLoadTextureBlock(gfx++, D_102EE70 + (f + j * 4) * 0xA0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 20, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                SCISRECT(x, y, x + 20, y + 8);
                x += 22;
            }
        }
    j = j;
    }
    if (gGameModes == GMODE_STUNT) {
        gDPLoadTextureBlock(gfx++, D_8024008, G_IM_FMT_RGBA, G_IM_SIZ_32b, 36, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        RECT(0x2D, 0x16, 0x51, 0x22);
        val = D_801C26D0;
        x = 0x1C;
        if (val >= 100000) {
            if (f) {}
            val = 99999;
        i = i;
        }
        for (k = 4; k > -1; k--) {
            f = f;
            if (val) {}
            D_80228CF8[k] = val % 10;
            k = k;
            val /= 10;
        }
        for (p = D_80228CF8; p < &D_80228CF8[5]; p++) {
            gDPLoadTextureBlock(gfx++, D_8024BC8 + *p * 0xC0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            RECT(x, 0x26, x + 12, 0x36);
            x += 14;
        x = x;
        if (x) {}
        }
    }
    if (gGameModes == GMODE_STUNT) {
        gDPLoadTextureBlock(gfx++, D_1032500, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        m = m;
        RECT(0x8D, 0x16, 0xAD, 0x22);
        val = D_801C2938[D_800D48DC].unk2C4;
        y = val % 1000;
        gDPLoadTextureBlock(gfx++, D_103B4D0 + (y / 100) * 0xC0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        RECT(0xAA, 0x26, 0xB6, 0x36);
        gDPLoadTextureBlock(gfx++, D_103D5D0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 12, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        rs = rs;
        RECT(0xA2, 0x23, 0xAE, 0x33);
        f = val / 1000;
        if (f >= 6 || D_801C2938[D_800D48DC].unk2F4 != 0 || D_801C2938[D_800D48DC].unk2EC != 0) {
            x = 0x84;
            if (val) {}
            if (f >= 10) {
                gDPLoadTextureBlock(gfx++, D_80273D8 + (f / 10) * 0x140, G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                RECT(x, 0x26, x + 16, 0x3A);
            }
            x += 16;
            x2 = x2;
            gDPLoadTextureBlock(gfx++, D_80273D8 + (f % 10) * 0x140, G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            RECT(x, 0x26, x + 16, 0x3A);
        } else {
            m = y - 700;
            if (m < 0) {
                m = 0;
            }
            k = (m * 16) / 300;
            k = k;
            val = 32 - k * 2;
            x = 40 - k * 2;
            if (val > 0 && x > 0) {
                gDPPipeSync(gfx++);
                gDPSetTextureFilter(gfx++, G_TF_BILERP);
                gDPSetCombine(gfx++, 0x129A25, 0xFF37FFFF);
                gDPSetEnvColor(gfx++, D_80228AAC, D_80228AB0, D_80228AB4, 255);
                gDPLoadTextureBlock(gfx++, D_802A5E0 + f * 0x500, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 40, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gfx++, (k + 0x84) << 2, (k + 0x26) << 2, (0xA4 - k) << 2, (0x4E - k) << 2, 0, 0, 0,
                                    0x8000 / val, 0xA000 / x);
            if (m) {}
            }
        }
    }
    if (gGameModes == GMODE_TIME_TRIALS && gCourseID != DOLPHIN_PARK) {
        y = 0x16;
        k = k;
        gfx = func_801E92FC(gfx, 1, D_802279E0, 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        y += 9;
        gfx = func_801E8A84(gfx, 1, D_801C1FE4, 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        if (D_800DAB68 == 0) {
            x = x;
            y += 11;
            gfx = func_801E92FC(gfx, 1, D_802279EC, 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            y += 9;
            p = p;
            gfx = func_801E8A84(gfx, 1, D_801C1FE8, 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        }
    y2 = y2;
    val = val;
    }
    rs = rs;
    i = i;
    *gfxP = gfx;
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

void func_801FAD68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32* arg4, s32* arg5, s32* arg6) {
    s32 dx, dy, abs_dx, abs_dy, sx, sy, err, count;

    abs_dx = arg2 - arg0;
    abs_dy = arg3 - arg1;
    dx = abs_dx;
    dy = abs_dy;

    if (dx == 0) {
        sx = 0;
    } else {
        if (dx > 0)
            err = 1;
        else
            err = -1;
        sx = err;
    }

    if (dy == 0) {
        sy = 0;
    } else {
        if (dy > 0)
            err = 1;
        else
            err = -1;
        sy = err;
    }

    err = 0;
    if (dx < 0)
        abs_dx = -dx;
    dx = arg0;
    if (dy < 0)
        abs_dy = -dy;
    *arg5 = arg0;
    dy = arg1;
    count = 1;
    *arg6 = arg1;

    if (abs_dx >= abs_dy) {
        if (arg0 != arg2) {
            do {
                err += abs_dy;
                dx += sx;
                if ((err * 2) >= abs_dx) {
                    err -= abs_dx;
                    dy += sy;
                }
                arg5[count] = dx;
                arg6[count] = dy;
                count++;
            } while (dx != arg2);
        }
    } else {
        if (arg1 != arg3) {
            do {
                err += abs_dx;
                dy += sy;
                if ((err * 2) >= abs_dy) {
                    err -= abs_dy;
                    dx += sx;
                }
                arg5[count] = dx;
                arg6[count] = dy;
                count++;
            } while (dy != arg3);
        }
    }
    *arg4 = count;
}

void func_801FAEA8(void) {
}

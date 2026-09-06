#include "global.h"

typedef struct UnkStruct_801CB6C8 {
    Mtx unk0[1];
    char pad[0x1758];
} UnkStruct_801CB6C8;

void func_8004BA18(void);
void Splash_Init(void);
void func_8007BD70(void);
s32 func_8007BE00(void);
void func_80088EA0(void);
void func_801DD85C(void);
void Game_EnterBootState(void);
s32 func_8009684C(s32, s16, s16);

extern s16 D_800DAB74;
extern s16 D_800DAB78;
extern s32 D_801CE5FC;
extern s16 gCurrentPauseMenuOption;
extern s16 D_801CE62A;
extern s16 D_801CE62E;
extern u16 D_801CE690;
extern s16 D_80228A36;
extern s32 D_80228A40;
extern u8 D_1008290[];
extern s32 D_800DA940[];
extern s32 D_800DA988[][3];
extern ControllerBase D_800DAB10;
extern s32 D_800DCE90;

extern f32 D_800EAC78;
extern s32 D_801519AC;
extern s32 D_801CB288[];
extern s32 D_801CB308[3][3];
extern Mtx D_801CCE60;
extern s32 D_801CE600;
extern s16 D_801CE60C;
extern s16 D_801CE628;
extern s16 D_801CE62C;
extern UnkStruct_801CE658 D_801CE658[];
extern s32 D_801CE6AC;
extern s16 D_801CE72E;
extern struct UnkStruct_801CB6C8 D_801CB6C8[];
extern s32 D_800DAB60[];
extern s32 D_800DC4F0[];
extern s32 D_800DC514[];
extern s32 D_800DC698[];
extern s32 D_800DC6BC[];
extern s8 D_801CB400;
extern s8 D_801CB401;
extern s32 D_80154344;
extern s32 D_800DA9DC[];
extern RiderStruct D_801C2938[];
extern s32 D_801CB340[];
extern s32 D_801CB350[][4];
extern s16 D_801CE60E;
extern s32 D_801CE718[];
extern s32 D_801CB334;

s32 D_800DA940[] = { 1, 0, 0, 0 };

UnkStruct_func_i8_802C6E00 D_800DA950[] = {
    { "R.HAYAMI", 5, 5, 5 },
    { "D.MARINER", 5, 5, 5 },
    { "A.STEWART", 5, 5, 5 },
    { "M.JETER", 5, 5, 5 },
};

s32 D_800DA988[][3] = {
    { 0, 5, 3 },
    { 0, 5, 3 },
    { 0, 5, 3 },
};

s16 D_800DA9AC = 1;

s32 D_800DA9B0[4] = { 0, 1, 2, 3 };
s32 D_800DA9C0[2] = { 0, 3 };
s32 D_800DA9C8[2] = { 0, 0 };

s32 D_800DA9D0 = 0;
s32 gCurrentOptionsMenuItem = 0;
s32 D_800DA9D8 = 0;

s32 D_800DA9DC[] = { 3, 2, 1, 0 };

s32 D_800DA9EC[] = { 0, 1, 0 };

s32 D_800DA9F8 = 2;
s32 D_800DA9FC = 3;
s16 D_800DAA00 = 0;
s32 D_800DAA04 = 1;
s32 D_800DAA08 = 0;
s32 D_800DAA0C = 0;

s32 D_800DAA10[] = { 0x00000008, 0x00000009, 0x0000000A, 0x0000000B, 0x0000000C,
                     0x0000000D, 0x0000000E, 0x0000000F, 0x00000010 };
s32 D_800DAA34[] = { 0x00000008, 0x00000009, 0x0000000A, 0x0000000B, 0x0000000C,
                     0x0000000D, 0x0000000E, 0x0000000F, 0x00000016 };

RGB short_RGB[] = {
    { 0, 242, 228 }, { 0, 242, 228 }, { 227, 112, 129 }, { 43, 135, 146 },  { 137, 180, 189 },
    { 80, 117, 85 }, { 12, 58, 117 }, { 28, 90, 221 },   { 137, 180, 189 },
};

// These are real segmented addressed symbols:
Vtx* D_800DAA90[] = { (Vtx*) 0x0106F930, (Vtx*) 0x0106F930, (Vtx*) 0x0106F970, (Vtx*) 0x0106F9B0, (Vtx*) 0x0106F9F0,
                      (Vtx*) 0x0106FA30, (Vtx*) 0x0106FA70, (Vtx*) 0x0106FAB0, (Vtx*) 0x0106F9F0 };

// These are real symbols:
void* D_800DAAB4[] = { (void*) 0x800E9870, (void*) 0x800E98B0, (void*) 0x800E98F0,
                       (void*) 0x800E9930, (void*) 0x800E9970, (void*) 0x800E99B0,
                       (void*) 0x800E99F0, (void*) 0x800E9A30, (void*) 0x800E9A70 };

Course D_800DAAD8[] = { 0, 1, 2, 4, 3, 5, 6, 8, 7 };

const s16 D_800EABB0[] = { 7, 4, 2, 1, 0, 0 };
const s16 D_800EABBC[] = { 0x0000, 0x0001, 0x0002, 0x0004, 0x0008, 0x000C, 0x0010, 0x0000,
                           0x0002, 0x0004, 0x0006, 0x000A, 0x000E, 0x0015, 0x001C, 0x0000,
                           0x0002, 0x0004, 0x0008, 0x000C, 0x0010, 0x0017, 0x001E, 0x0025 };
const s16 D_800EABEC[] = { 0x0014, 0x0014, 0x0014, 0x0028, 0x000A, 0x001E, 0x0014, 0x0019, 0x0019, 0x0000 };
const s16 D_800EAC00[] = { 0x000F, 0x000F, 0x000F, 0x0023, 0x0005, 0x0014, 0x000F, 0x0014, 0x0014, 0x0000 };

const s16 D_800EAC14[] = { 0x0000, 0x0001, 0x0002, 0x0004, 0x0003, 0x0005, 0x0007, 0xFFFF,
                           0x0001, 0x0002, 0x0004, 0x0003, 0x0005, 0x0006, 0x0007, 0xFFFF,
                           0x0001, 0x0002, 0x0004, 0x0003, 0x0005, 0x0006, 0x0008, 0x0007 };
const s16 D_800EAC44[] = { 0x0000, 0x0002, 0x0001, 0x0003, 0x0002, 0x0003, 0x0000, 0x0001,
                           0x0001, 0x0002, 0x0003, 0x0000, 0x0003, 0x0000, 0x0002, 0x0001 };
s8* sRidersInitials[] = { "R.H", "D.M", "A.S", "M.J" };
s16 D_800DAB0C = 0;

/* One-time boot initialization: display-list buffer descriptors, ortho
 * matrices, subsystem inits, and default controller/pause state. Runs
 * once before the main loop. */
void Main_InitGameState(void) {
    s8 modeBits;
    s32 i;
    s32 j;
    s32 one = 1;

    D_801CE6B0[0] = 0;
    D_801CE6B0[2] = 0;
    D_801CE6B0[3] = 0;
    D_801CE6B0[1] = D_80151984;
    D_801CE6B0[4] = D_801519AC;
    D_801CE6B0[5] = 0;
    D_801CE6B0[6] = 0;
    D_801CE6B0[7] = 0;
    D_801CE6B0[8] = osVirtualToPhysical(D_800D45F0);
    D_801CE6B0[9] = 0;
    D_801CE6B0[13] = osVirtualToPhysical((void*) D_800D45E4);
    D_801CE6B0[14] = osVirtualToPhysical(D_800D45E8);

    D_800DCE90 = (u8*) osPhysicalToVirtual(D_80151984) + (ALIGN16(D_1008290 - (u8*) D_1000000));

    D_801CE5F8 = &D_801CB6C8[D_8011F8E0];
    D_801CE5FC = 0;
    gCurrentPauseMenuOption = -1;
    D_801CE628 = 0;
    D_801CE62C = 0;
    D_802C6EE4 = 0;
    D_801CE72E = one;
    D_801CB280 = 0;

    for (i = 0; i < 4; i++) {
        D_801CB288[i] = D_800DA940[i];
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            D_801CB308[i][j] = D_800DA988[i][j];
        }
    }

    guOrtho(D_801CB6C8->unk0, 0.0f, 319.0f, 239.0f, 0.0f, 100.0f, -100.0f, 1.0f);
    guOrtho(&D_801CCE60, 0.0f, 319.0f, 239.0f, 0.0f, 100.0f, -100.0f, 1.0f);
    func_8004BA18();
    Splash_Init();
    func_80088EA0();
    func_801DD85C();
    Game_EnterBootState();
    func_8007BD70();
    func_8007BE00();

    modeBits = D_801CB280 & 0xC0;
    if (modeBits & 0x40) {
        D_800DA9EC[0] = 1;
        func_800C2FDC(3);
    } else if (modeBits & 0x80) {
        D_800DA9EC[0] = 2;
        func_800C2FDC(1);
    } else {
        D_800DA9EC[0] = 0;
        func_800C2FDC(0);
    }
    if (D_801CB280 & 0x20) {
        D_800DA9EC[1] = 0;
        func_800C3044();
    } else {
        D_800DA9EC[1] = 1;
        func_800C3034();
    }

    for (i = 0; i < 3; i++) {
        D_801CE658[i].unk_00 = D_800DAB10;
        D_801CE658[i].unk_14 = D_801CE658[i].unk_18 = 0;
    }
}

void func_80051238(void);
void func_800665B0(void);
void Game_AdvanceFrameState(void);
void func_8006E3A8(void);
void func_8008E794(void);
void Game_SetupState(void);
void Controller_AssignPlayers(void);
void func_800AD418(void);
void func_800B2ABC(void);
void func_801DDE48(void);
void func_801E1290(void);
void func_801E3250(void);
void func_801E71A8(void);
void func_801EAFB4(void);
void func_802C7090(void);
void func_802C7608(void);
void func_i3_802C5800(void);
extern s32 D_800D47E0;
extern s8 D_801CB400;
extern s8 D_801CB401;

/* Per-frame update dispatcher: polls controllers, advances frame state,
 * runs state-entry setup on state changes, then ticks the subsystems for
 * the current game state. Runs once per main-loop iteration. */
void Game_UpdateFrame(void) {
    SysUtils_UpdateControllers();
    Game_AdvanceFrameState();
    D_801CE5F8 = (u8*) &D_801CB6C8[D_8011F8E0];
    if (D_801CE63C != 0) {
        D_800D47E0 = 0;
        D_801CB400 = 0x23;
        D_801CB401 = 0x23;
        if (gGameState == 0x64) {
            D_801CB400 = 0x32;
        } else if (gGameState == 0xA) {
            D_801CB400 = 0x3C;
        }
        Game_SetupState();
    }
    Controller_AssignPlayers();
    switch (gGameState) {
        case GAME_STATE_TITLE_SCREEN:
        case GAME_STATE_MAIN_MENU:
        case GAME_STATE_4:
        case GAME_STATE_DEMO:
        case GAME_STATE_8:
        case GAME_SATE_COURSE_OVERVIEW:
        case GAME_SATE_1F:
        case GAME_STATE_TIME_TRIAL:
        case GAME_STATE_29:
        case GAME_STATE_2A:
        case GAME_STATE_2B:
        case GAME_STATE_2C:
        case GAME_STATE_2D:
        case GAME_STATE_CEREMONY:
        case GAME_STATE_67:
            func_80086148();
            func_800665B0();
            func_801DDE48();
            func_80051238();
            func_8008E794();
            if (D_801CE638 != 0x15) {
                func_8006E3A8();
            }
            func_800B2ABC();
            func_800AD418();
            if (D_801CE638 == 1) {
                if (gGameState == 0x2D) {
                    func_802C7608();
                } else {
                    func_i3_802C5800();
                }
            } else if (D_801CE638 == 8) {
                func_i3_802C5800();
            } else if (D_801CE638 == 0x15) {
                func_i3_802C5800();
            }
            break;
        case GAME_STATE_TIME_TRIALS_RESULTS:
        case GAME_STATE_33:
            func_801DDE48();
            func_80051238();
            func_8008E794();
            func_i3_802C5800();
            break;
        case GAME_STATE_50:
        case GAME_STATE_51:
            func_801DDE48();
            func_80051238();
            func_8008E794();
            func_i3_802C5800();
            break;
        case GAME_STATE_RIDER_SELECT:
        case GAME_STATE_B:
            func_80086148();
            func_800665B0();
            func_801DDE48();
            func_80051238();
            func_8008E794();
            func_8006E3A8();
            func_800B2ABC();
            func_i3_802C5800();
            break;
        case GAME_STATE_COURSE_SELECT:
        case GAME_STATE_15:
            func_801DDE48();
            func_80051238();
            func_8008E794();
            func_i3_802C5800();
            break;
        case 0x34:
        case 0x35:
            func_801DDE48();
            func_80051238();
            func_8008E794();
            func_i3_802C5800();
            break;
        case 0x3E:
        case 0x3F:
            func_80086148();
            func_800665B0();
            func_801DDE48();
            func_80051238();
            func_8008E794();
            func_8006E3A8();
            func_800B2ABC();
            func_i3_802C5800();
            break;
        case 0x42:
        case 0x43:
            func_i3_802C5800();
            break;
        case 0x44:
        case 0x45:
            func_i3_802C5800();
            break;
        case 0x40:
        case 0x41:
            func_i3_802C5800();
            break;
        case 0x5A:
        case 0x5B:
            func_801DDE48();
            func_80051238();
            func_8008E794();
            func_802C7090();
            break;
        case 0x64:
        case 0x65:
            func_801DDE48();
            func_80051238();
            func_8008E794();
            func_801E1290();
            break;
        case 0x5:
        case 0x6:
            func_i3_802C5800();
            break;
        case 0x36:
        case 0x37:
            func_801DDE48();
            func_80051238();
            func_8008E794();
            break;
        case 0x38:
            func_801DDE48();
            func_80051238();
            func_8008E794();
            func_i3_802C5800();
            break;
        case 0x39:
            func_801DDE48();
            func_80051238();
            func_8008E794();
            func_801E3250();
            break;
    }
    func_801E5470();
    func_801EAFB4();
    func_801E71A8();
}

extern s32 D_800D49B0;
extern s32 gPrevGameState;
extern s32 D_801CE6F8;

/* State-entry setup: initializes wave, buoy, rider and HUD subsystems for
 * game states that need them, with extra conditions on state transitions. */
void Game_SetupState(void) {
    s32 frameKeep; /* unused; preserves the original stack frame */
    s32 shouldSetup;

    switch (gGameState) {
        case 40:
        case 2:
        case 10:
        case 62:
        case 30:
        case 102:
        case 7:
            func_8006AACC(gCourseID);
            func_80067E40();

            if (gGameState == 102) {
                func_8004F9E0(-150, D_800D49B0);
            } else {
                func_8004F9E0(0, D_800D49B0);
            }

            func_8008E4B0();
            func_801DDA24();
            func_800AC184();
            func_800AE7C4();
            func_800893A8();
            func_8009C968();

            if (gPlayers == 1) {
                func_8007FD80();
            }

            if (gGameState == 40) {
                D_801CE6F8 = 0;
            }
            break;

        case 20:
        case 52:
        case 54:
        case 56:
            func_8004F9E0(0, D_800D49B0);
            func_8008E4B0();
            func_801DDA24();
            break;

        case 50:
            if (gPrevGameState != 100) {
                func_8004F9E0(0, D_800D49B0);
                func_8008E4B0();
                func_801DDA24();
            }
            break;

        case 100:
            if (gPrevGameState == 103) {
                func_8004F9E0(0, D_800D49B0);
                func_8008E4B0();
                func_801DDA24();
            } else if (D_801CE608.gameMode == 0) {
                func_8004F9E0(0, D_800D49B0);
                func_8008E4B0();
                func_801DDA24();
            }
            break;

        case 80:
            shouldSetup = 1;

            if (D_801CE608.gameMode == 4) {
                if (gPrevGameState != 67) {
                    shouldSetup = 0;
                }
            } else {
                if ((gPrevGameState == 100) || (gPrevGameState == 50) || (gPrevGameState == 57)) {
                    shouldSetup = 0;
                }
            }

            if (shouldSetup != 0) {
                func_8004F9E0(0, D_800D49B0);
                func_8008E4B0();
                func_801DDA24();
            }
            break;
    }
}

/* Maps the connected physical controllers onto the three logical player
 * slots, then synthesizes L/R/U/D pad presses from stick deflection past
 * the per-axis thresholds (edge triggers pressed + resets the hold
 * counter, holding keeps held and counts up). Slot 2 also merges slot 1's
 * buttons when two controllers are connected. */
void Controller_AssignPlayers(void) {
    UnkStruct_801CE658* slot;
    s32 i;

    for (i = 0, slot = &D_801CE658[i]; i < 3; i++, slot++) {
        slot->unk_0A = slot->unk_00;

        switch (i) {
            case 0:
                if (D_80154344 < 1) {
                    slot->unk_00 = D_800DAB10;
                } else {
                    slot->unk_00 = gControllerOne[D_80154330[0]];
                }
                break;

            case 1:
                if (D_80154344 == 0) {
                    slot->unk_00 = D_800DAB10;
                } else if (D_80154344 == 1) {
                    slot->unk_00 = gControllerOne[D_80154330[0]];
                } else {
                    slot->unk_00 = gControllerOne[D_80154330[1]];
                }
                break;

            case 2:
                if (D_80154344 < 1) {
                    slot->unk_00 = D_800DAB10;
                } else {
                    slot->unk_00 = gControllerOne[D_80154330[0]];
                }
                if (D_80154344 >= 2) {
                    slot->unk_00.unk_0 |= D_801CE658[1].unk_00.unk_0;
                    slot->unk_00.unk_2 |= D_801CE658[1].unk_00.unk_2;
                }
                break;
        }

        if (slot->unk_00.unk_8 >= D_801CB400) {
            if (slot->unk_0A.unk_8 < D_801CB400) {
                slot->unk_00.unk_2 |= R_JPAD;
                slot->unk_14 = 0;
            } else {
                slot->unk_00.unk_0 |= R_JPAD;
                slot->unk_14++;
            }
        } else if (slot->unk_00.unk_8 <= -D_801CB400) {
            if (slot->unk_0A.unk_8 > -D_801CB400) {
                slot->unk_00.unk_2 |= L_JPAD;
                slot->unk_14 = 0;
            } else {
                slot->unk_00.unk_0 |= L_JPAD;
                slot->unk_14++;
            }
        }

        if (slot->unk_00.unk_9 >= D_801CB401) {
            if (slot->unk_0A.unk_9 < D_801CB401) {
                slot->unk_00.unk_2 |= U_JPAD;
                slot->unk_18 = 0;
            } else {
                slot->unk_00.unk_0 |= U_JPAD;
                slot->unk_18++;
            }
        } else if (slot->unk_00.unk_9 <= -D_801CB401) {
            if (slot->unk_0A.unk_9 > -D_801CB401) {
                slot->unk_00.unk_2 |= D_JPAD;
                slot->unk_18 = 0;
            } else {
                slot->unk_00.unk_0 |= D_JPAD;
                slot->unk_18++;
            }
        }
    }
}

/* Master display-list builder: dispatches to the current game state's
 * screen builder overlay, then appends the pause menu and the fade/wave
 * post effects. Runs once per frame from the main loop. */
Gfx* Game_BuildDisplayList(Gfx* dList) {
    s32 frameKeep; /* unused; preserves the original stack frame */

    D_801CE62E = 0;
    D_801CE62A = 1;
    D_80228A36 = 0;
    D_80228A40 = 0;

    //! FAKE:
    switch (gGameState) {
        case 1:
            break;
    }

    gSPSegment(dList++, 0x05, osVirtualToPhysical(D_801AE948));

    switch (gGameState) {
        case 0x0:
            D_801CE62A = 0;

            dList = Gfx_ClearCurrentBuffer(dList);

            if (MemPak_Probe() != 0) {
                func_801ECAF4();
            } else {
                func_801EB180();
            }
            break;

        case 0x5:
        case 0x6:
            D_801CE62A = 0;
            dList = func_802C5BA4(dList);
            break;

        case 0x2:
            D_801CE62A = 0;
            dList = func_1C3D00_802C5800(
                dList); // These are likely pointing to the wrong overlay function right now, VERIFY
            break;

        case 0x3:
            D_801CE62A = 0;
            dList = func_802C5A7C(dList);
            break;

        case 0x7:
        case 0x8:
            D_801CE62A = 0;
            dList = func_802C913C(dList);
            break;

        case 0x4:
            D_801CE62A = 0;
            dList = func_802C6944(dList);
            break;

        case 0x28:
            if (((D_801CE608.gameMode == 4) || (D_801CE608.gameMode == 1)) && (gGameModeState != 3)) {
                D_801CE62A = 0;
            }
            dList = func_802C5AE4(dList);
            break;

        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x2C:
            D_801CE62A = 0;
            dList = func_802C5AE4(dList);
            break;

        case 0x2D:
            D_801CE62A = 0;
            dList = func_802C7D00(dList);
            break;

        case 0x36:
        case 0x37:
            D_801CE62A = 0;
            dList = func_1C3D00_802C5800(dList);
            break;

        case 0x32:
        case 0x33:
            D_801CE62A = 0;
            dList = func_802C5B74(dList);
            break;

        case 0x50:
        case 0x51:
            D_801CE62A = 0;
            dList = func_802C5924(dList);
            break;

        case 0xA:
        case 0xB:
            D_801CE62A = 0;
            dList = func_802C5B4C(dList);
            break;

        case 0x14:
        case 0x15:
            D_801CE62A = 0;
            dList = func_802C5B78(dList);
            break;

        case 0x1E:
        case 0x1F:
            D_801CE62A = 0;
            dList = func_802C5B40(dList);
            break;

        case 0x34:
        case 0x35:
            D_801CE62A = 0;
            dList = func_802C5C1C(dList);
            break;

        case 0x3C:
        case 0x3D:
            D_801CE62A = 0;
            dList = func_1C3D00_802C5800(
                dList); // These are likely pointing to the wrong overlay function right now, VERIFY
            break;

        case 0x3E:
        case 0x3F:
            D_801CE62A = 0;
            dList = func_802C5D3C(dList);
            break;

        case 0x42:
        case 0x43:
            D_801CE62A = 0;
            dList = func_802C5D24(dList);
            break;

        case 0x44:
        case 0x45:
            D_801CE62A = 0;
            dList = func_802C5968(dList);
            break;

        case 0x48:
        case 0x49:
            D_801CE62A = 0;
            dList = func_1C3D00_802C5800(
                dList); // These are likely pointing to the wrong overlay function right now, VERIFY
            break;

        case 0x46:
        case 0x47:
            D_801CE62A = 0;
            dList = func_1C3D00_802C5800(
                dList); // These are likely pointing to the wrong overlay function right now, VERIFY
            break;

        case 0x40:
        case 0x41:
            D_801CE62A = 0;
            dList = func_802C5F6C(dList);
            break;

        case 0x5A:
        case 0x5B:
            D_801CE62A = 0;
            dList = func_802C7484(dList);
            break;

        case 0x64:
        case 0x65:
            D_801CE62A = 0;
            dList = func_801E1E8C(dList);
            break;

        case 0x66:
        case 0x67:
            D_801CE62A = 0;
            dList = func_802C5F50(dList);
            break;

        case 0x38:
            D_801CE62A = 0;
            dList = func_802C583C(dList);
            break;

        case 0x39:
            D_801CE62A = 0;
            dList = func_801E34F8(dList);
            break;
    }

    if ((((D_801CE690 & 0xF000) != 0xF000) || (gCurrentPauseMenuOption != -1)) && (D_800DAB78 == 0)) {
        dList = PauseMenu_Update(dList);
    } else {
        // necessary to match
    }

    switch (D_800DAB74) {
        case 1:
            D_800DAB74 = 0;
            D_800DAB78 = 1;
            PauseMenu_Open();
            break;

        case 2:
            D_800DAB74 = 0;
            D_800DAB78 = 0;
            PauseMenu_Close();
            break;

        default:
            break;
    }

    D_80228A36 = 1;

    dList = func_801E7908(dList);

    if (D_801CE62E != 0) {
        D_801CE62E = 0;
        func_801EB180();
    }

    if (++D_801CE5FC >= 30000) {
        D_801CE5FC = 0;
    }

    return dList;
}

/* Probes the Controller Pak in the first connected controller and reads
 * its file table. Returns 1 when a usable pak is present, 0 otherwise. */
s32 MemPak_Probe(void) {
    s32 i;
    s32 result;

    if (D_80154340 == 0) {
        return 0;
    }

    D_801CB404 = D_80154330[0];

    if ((D_801542E2[D_801CB404][0] & 1) == 0) {
        return 0;
    }

    if ((gControllerOne[D_801CB404].unk_0 & 0x1000) == 0) {
        return 0;
    }

    if (osPfsIsPlug(&D_801540D0, (u8*) &D_801CB6C0) != 0) {
        return 0;
    }

    if (osPfsInit(&D_801540D0, (OSPfs*) &D_801CB658, D_801CB404) != 0) {
        return 0;
    }

    if (osPfsNumFiles((OSPfs*) &D_801CB658, (s32*) &D_801CB40C, (s32*) &D_801CB408) != 0) {
        return 0;
    }

    for (i = 0; i < 0x10; i++) {
        result = osPfsFileState((OSPfs*) &D_801CB658, i, (OSPfsState*) &D_801CB418[i << 5]);
        D_801CB618[i] = result;
    }

    if (osPfsFreeBlocks((OSPfs*) &D_801CB658, &D_801CB410) != 0) {
        return 0;
    }

    D_801CB410 >>= 8;

    return 1;
}

/* Builds the full race-scene display list: one viewport in 1P mode,
 * two stacked viewports in 2P mode, then the splash overlay. */
Gfx* Game_BuildRaceScene(Gfx* gdl) {
    if (gPlayers == ONE_PLAYER) {
        D_800DAB2C = 0;
        gdl = func_8008FB74(gdl);
        func_8006E674(&gdl);
        gdl = func_800687A4(gdl);
        gdl = func_8007FFA8(gdl);
        if ((D_801CE638 != 4) && (D_801CE638 != 0xA)) {
            gdl = func_800ADF90(gdl);
        }
        gdl = Draw_WaterEffects(gdl);
        gdl = func_80069594(gdl);
        gdl = func_80068538(gdl);
        configSignalRectangle(&gdl);
        func_800B305C(&gdl);
        gdl = func_8008BD2C(gdl);
    } else {
        D_800DAB2C = 0;
        gdl = Game_BuildRaceViewport(gdl);
        D_800DAB2C = 1;
        gdl = Game_BuildRaceViewport(gdl);
        D_800DAB2C = 0;
    }
    gdl = Splash_Draw(gdl);
    if ((gGameState != 0x2D) || (D_80228AA4 != 2)) {
        func_801FC4D4(&gdl);
    }
    return gdl;
}

/* Builds one split-screen viewport of the race scene (world, water, HUD). */
Gfx* Game_BuildRaceViewport(Gfx* gdl) {

    Gfx* frameKeep; /* unused; preserves the original stack frame */

    gdl = func_8008FB74(gdl);
    func_8006E674(&gdl);
    gdl = func_800687A4(gdl);
    if ((D_801CE638 != 4) && (D_801CE638 != 10)) {
        gdl = func_800ADF90(gdl);
    }
    gdl = Draw_WaterEffects(gdl);
    gdl = func_80069594(gdl);
    gdl = func_80068538(gdl);
    configSignalRectangle(&gdl);
    func_800B305C(&gdl);
    return gdl;
}

/* Applies the selected game options and transitions into gameplay:
 * difficulty, laps, riders, camera and fade state. */
void Game_EnterGameplay(void) {
    UnkStruct_func_i8_802C6E00* initials;
    s32 riderSelA;
    s32 riderSelB;
    s32 courseId;
    s32 frameKeep; /* unused; preserves the original stack frame */

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_TIME_TRIAL;
    D_801CE638 = 1;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;
    D_801CE600 = 0;

    if (gDifficulty == DIFFICULTY_NORMAL) {
        D_801CE608.waveLevel = Game_GetWaveLevel(0, gCourseID);
        D_801CE608.powerMisses = D_801CB308[0][1];
        D_801CE608.lapCount = D_801CB308[0][2];
        D_801CE72C = (s16) D_801CB308[0][0];
    } else if (gDifficulty == DIFFICULTY_HARD) {
        D_801CE608.waveLevel = Game_GetWaveLevel(1, gCourseID);
        D_801CE608.powerMisses = D_801CB308[1][1];
        D_801CE608.lapCount = D_801CB308[1][2];
        D_801CE72C = (s16) D_801CB308[1][0];
    } else if (D_800DAB68 != 0) {
        D_801CE608.waveLevel = D_800EABEC[gCourseID];
        D_801CE608.powerMisses = 5;
        D_801CE608.lapCount = 3;
        D_801CE72C = 0;
    } else {
        D_801CE608.waveLevel = Game_GetWaveLevel(2, gCourseID);
        D_801CE608.powerMisses = D_801CB308[2][1];
        D_801CE608.lapCount = D_801CB308[2][2];
        D_801CE72C = (s16) D_801CB308[2][0];
    }

    gGameModes = D_801CE608.gameMode;
    gPlayers = D_801CE608.player;
    gRiders = (s32) D_801CE608.rider;
    gBuoyMisses = D_801CE608.powerMisses;
    D_800D4970 = (s16) D_801CE608.unk_14;
    D_800D49B0 = D_801CE608.waveLevel;

    if (D_801CE608.gameMode == GMODE_CHAMPIONSHIP) {
        if (D_801CE6F8 != 0) {
            D_801CE728[0] = D_801CE608.lapCount;
        }
    } else if (D_801CE608.gameMode == GMODE_STUNT) {
        D_801CE600 = 0;
        D_801CE608.waveLevel = (D_800D49B0 = D_800EABEC[gCourseID]);
        D_801CE608.lapCount = (D_801CE728[0] = 1);
        D_801CE72C = 0;
    } else {
        D_801CE728[0] = D_801CE608.lapCount;
    }

    D_800D8178 = 0;
    D_801CE64C = 0;
    D_801CE6FC = 0;

    if ((gCourseID == DOLPHIN_PARK) && (gGameModes == GMODE_STUNT)) {
        D_801CE6FC = 1;
    }
    if ((gCourseID == DOLPHIN_PARK) && (D_801CE6FC == 0)) {
        gGameModeState = 3;
        gRiderGameModes = 3;
    } else {
        gGameModeState = 0;
        gRiderGameModes = 1;
    }

    D_801CE6F0 = 0;

    switch (D_801CE608.gameMode) {
        case GMODE_CHAMPIONSHIP:
            if (D_800DAB68 != 0) {
                gDifficulty = DIFFICULTY_EXPERT;
            }
            D_800D8240 = 0;
            for (riderSelB = 0; riderSelB < 4; riderSelB++) {
                D_801CB3F8[riderSelB] = 0;
                D_80192690[riderSelB].unkB68 = D_800DA9B0[riderSelB];
                if (riderSelB == D_800D48DC) {
                    if (D_801CB32C == 0) {
                        initials = &D_800DA950[D_80192690[riderSelB].unkB68];
                    } else {
                        initials = &D_801CB298[D_80192690[riderSelB].unkB68];
                    }

                    D_80192690[riderSelB].unkB6C = (s32) initials->unk_B[0];
                    D_80192690[riderSelB].unkB70 = (s32) initials->unk_B[1];
                    D_80192690[riderSelB].unkB74 = (s32) initials->unk_B[2];
                } else {
                    D_80192690[riderSelB].unkB6C = D_800D96A4[gCourseID][D_80192690[riderSelB].unkB68].unk0;
                    D_80192690[riderSelB].unkB70 = D_800D96A4[gCourseID][D_80192690[riderSelB].unkB68].unk4;
                    D_80192690[riderSelB].unkB74 = D_800D96A4[gCourseID][D_80192690[riderSelB].unkB68].unk8;
                }
            }

            riderSelA = D_800DA9B0[D_800D48DC];
            if (D_801CE6F4[0] != 0) {
                riderSelA += 4;
            }
            func_80096960(0, riderSelA, D_800DA9B0[1], D_800DA9B0[2], D_800DA9B0[3]);

            break;

        case GMODE_TIME_TRIALS:
            if (D_800DAB68 != 0) {
                gDifficulty = DIFFICULTY_EXPERT;
            }
            riderSelA = D_800DA9B0[D_800D48DC];
            if (D_801CE6F4[0] != 0) {
                riderSelA += 4;
            }
            func_80096960(0, riderSelA, D_800DA9B0[1], D_800DA9B0[2], D_800DA9B0[3]);
            break;

        case GMODE_STUNT:
            if (gCourseID == PORT_BLUE) {
                gDifficulty = DIFFICULTY_NORMAL;
            } else {
                gDifficulty = DIFFICULTY_EXPERT;
            }
            riderSelA = D_800DA9B0[D_800D48DC];
            if (D_801CE6F4[0] != 0) {
                riderSelA += 4;
            }
            func_80096960(0, riderSelA, D_800DA9B0[1], D_800DA9B0[2], D_800DA9B0[3]);
            break;

        case GMODE_2P_VS:
            riderSelA = D_800DA9B0[D_800D48DC];
            if (D_801CE6F4[0] != 0) {
                riderSelA += 4;
            }
            riderSelB = D_800DA9B0[D_800D48E0];
            if (D_801CE6F4[1] != 0) {
                riderSelB += 4;
            }
            func_80096960(4, riderSelA, riderSelB, riderSelA, riderSelB);
            break;

        default:
            func_80096960(0, 0, 1, 1, 1);
            break;
    }

    courseId = gCourseID;
    if (courseId < DOLPHIN_PARK) {
        courseId = DOLPHIN_PARK;
    }
    if (courseId >= RIDER_SELECTION) {
        courseId = SOUTHERN_ISLAND;
    }

    func_8009684C(0x08060000, D_800DB568[courseId].unk0, D_800DB568[courseId].unk2);
    FadeTransition_SetProps(2, 4, 0);
    func_801E6A4C(0, 0);

    gCameraPerspective->viewMode = 3;
    if (gPlayers == TWO_PLAYERS) {
        gCameraPerspective[1].viewMode = gCameraPerspective->viewMode;
    }

    D_800DA9AC = 0;

    func_800C21F4(7, gCourseID);
}

/* Clears the fixed work color/depth images at 0x802A0000 to near-white. */
Gfx* Gfx_ClearWorkImages(Gfx* gdl) {
    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                       G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);

    gSPSetGeometryMode(gdl++, G_ZBUFFER | G_SHADE);
    gSPTexture(gdl++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_FILL);
    gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gdl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetDepthImage(gdl++, osVirtualToPhysical((void*) 0x802A0000));
    gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical((void*) 0x802A0000));
    gDPSetFillColor(gdl++, 0xFFFCFFFC);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 319, 239);
    gDPFillRectangle(gdl++, 0, 0, 319, 239);

    return gdl;
}

/* Clears all three framebuffers to near-black (NOOP render, keeps the
 * current color/depth images). */
Gfx* Gfx_ClearFrameBuffers(Gfx* gdl) {
    size_t i;

    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                    G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);

    gSPSetGeometryMode(gdl++, 4);
    gSPTexture(gdl++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE | 0x300000);
    gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gdl++, G_AC_NONE);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 319, 239);

    for (i = 0; i < 3; i++) {
        gDPPipeSync(gdl++);
        gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gFrameBuffers[i]));

        gDPSetFillColor(gdl++, 0x10001);
        gDPFillRectangle(gdl++, 0, 0, 319, 239);
    }

    return gdl;
}

/* Fills the viewport rectangle on all three framebuffers with the given
 * RGB color. */
Gfx* Gfx_FillViewport(Gfx* gfxPtr, u16 red, u16 green, u16 blue) {
    s32 i;

    gSPClearGeometryMode(gfxPtr++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                       G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);
    gSPTexture(gfxPtr++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(gfxPtr++);
    gDPSetCycleType(gfxPtr++, G_CYC_FILL);
    gDPSetCombineMode(gfxPtr++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gfxPtr++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gfxPtr++, G_AC_NONE);
    gDPSetScissor(gfxPtr++, G_SC_NON_INTERLACE, 8, 20, 310, 218);

    for (i = 0; i < 3; i++) {
        gDPPipeSync(gfxPtr++);
        gDPSetColorImage(gfxPtr++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gFrameBuffers[i]));
        gDPSetFillColor(gfxPtr++, (GPACK_RGBA5551(red, green, blue, 1) << 0x10) | GPACK_RGBA5551(red, green, blue, 1));
        gDPFillRectangle(gfxPtr++, 8, 20, 310, 219);
    }

    return gfxPtr;
}

/* Clears the current framebuffer to near-black. */
Gfx* Gfx_ClearCurrentBuffer(Gfx* gfxPtr) {
    gSPClearGeometryMode(gfxPtr++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                       G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);
    gSPTexture(gfxPtr++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(gfxPtr++);
    gDPSetCycleType(gfxPtr++, G_CYC_FILL);
    gDPSetCombineMode(gfxPtr++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gfxPtr++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gfxPtr++, G_AC_NONE);
    gDPSetScissor(gfxPtr++, G_SC_NON_INTERLACE, 0, 0, 319, 239);
    gDPSetColorImage(gfxPtr++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gFrameBuffers[gFramebuffersIdx]));
    gDPSetFillColor(gfxPtr++, 0x00010001);
    gDPFillRectangle(gfxPtr++, 0, 0, 319, 239);

    return gfxPtr;
}

s32 SegmentedToVirtual(u32 addr) {
    s32 segment;
    s32 var;

    segment = addr >> 0x18;
    if (segment >= 16) {
        segment = 0;
    }

    var = D_801CE6B0[segment] + (addr & 0xFFFFFF) + 0x80000000;

    return var;
}

/* Queues a DMA table entry for transfer. The entry comes from one of two
 * tables selected by arg1; a second chained entry follows from the
 * matching low table. (No callers in this revision; kept for byte-match.) */
void Dma_QueueEntry(s32 arg0, s32 arg1) {
    s32 frameKeep; /* unused; preserves the original stack frame */
    DmaTransfer* req;
    s32 idx;

    req = D_800DAB38;

    for (idx = 0; idx < 5; req++, idx++) {
        if (req->flag == 0) {
            break;
        }
    }

    if (idx != 5) {
        req->flag = 1;
        if (arg1 == 1) {
            req->entry = (DmaEntry*) D_800DC698[arg0];
        } else {
            req->entry = (DmaEntry*) D_800DC6BC[arg0];
        }
        func_80097E68();

        for (idx = 0; idx < 5; idx++) {
            if (D_800DAB38[idx].flag == 0) {
                break;
            }
        }

        if (idx != 5) {
            D_800DAB38[idx].flag = 1;
            if (arg1 == 1) {
                D_800DAB38[idx].entry = D_800DC4F0[arg0];
            } else {
                D_800DAB38[idx].entry = D_800DC514[arg0];
            }
            func_80097E68();
        }
    }
}

s32 Strlen2(s8* str) {
    s32 len;

    len = 0;

    while (*str++) {
        len++;
    }

    return len;
}

Gfx* func_801E9858(Gfx*, s32, s8*, s32, s32);

/* Draws a 5-digit decimal value with the font glyphs, right-aligned at x. */
Gfx* Font_DrawDecimal(Gfx* gdl, s32 font, s32 value, s32 x, s32 y) {
    s32 digitVal;
    s32 digitIdx;
    s32 xPos;
    u8 buf[4];
    s32 glyphStep;

    glyphStep = 0xC;
    if (font == 0) {
        glyphStep = 0x12;
    }
    digitVal = value;

    for (digitIdx = 0, xPos = x + glyphStep * 4; digitIdx < 5; digitIdx++, xPos += -glyphStep, digitVal /= 10) {
        sprintf(buf, "%d", digitVal % 10);
        gdl = func_801E9858(gdl, font, buf, xPos, y);
    }

    return gdl;
}

// Draws the textured menu-entry frames, sliced into strips and skipped
// entirely when off-screen.
Gfx* Menu_DrawFrame(Gfx* gdl, s32 style, s32 x, s32 y, s32 w, s32 h) {
    s32 i;
    s32 slices;
    s32 drawTexRect;
    s32 texWidth;
    s32 texHeight;
    s32 dsdx;
    s32 dsdy;
    s32 uly;
    s32 lry;
    u16* timg;

    switch (style) {
        case 0:
            slices = 4;
            timg = D_10515A8;
            texWidth = 256;
            texHeight = 8;
            dsdx = 0x40000 / w;
            dsdy = 0x8000 / h;
            break;

        case 2:
            slices = 4;
            timg = D_10565B8;
            texWidth = 256;
            texHeight = 8;
            dsdx = 0x40000 / w;
            dsdy = 0x8000 / h;
            break;

        case 1:
            slices = 1;
            timg = D_10555B0;
            texWidth = 64;
            texHeight = 32;
            dsdx = 0x10000 / w;
            dsdy = 0x8000 / h;
            break;
    }

    drawTexRect = true;
    if (x >= SCREEN_WIDTH) {
        drawTexRect = false;
    } else if ((x + w) < 0) {
        drawTexRect = false;
    } else if (y >= SCREEN_HEIGHT) {
        drawTexRect = false;
    } else if ((y + h) < 0) {
        drawTexRect = false;
    }

    if (!drawTexRect) {
        return gdl;
    }

    for (i = 0; i < slices; i++) {
        uly = (y + (f32) h / (f32) slices * i) * 4.0f;
        lry = (y + (f32) h / (f32) slices * i + (f32) h / (f32) slices) * 4.0f;
        gDPLoadTextureBlock(gdl++, timg + texWidth * texHeight * i, G_IM_FMT_RGBA, G_IM_SIZ_16b, texWidth, texHeight,
                            0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gdl++, x << 2, uly, (x + w) << 2, lry, G_TX_RENDERTILE, 0, 0, dsdx, dsdy);
    }

    return gdl;
}

/* Looks up the wave level for a course from a settings-table row: fixed
 * presets or a random value in the squall range. */
s32 Game_GetWaveLevel(s32 row, s32 courseId) {
    s32 level;

    switch (D_801CB308[row][0]) {
        case 0:
            D_801CE600 = 0;
            if (D_801CE608.player == 1) {
                level = D_800EABEC[courseId];
            } else {
                level = D_800EAC00[courseId];
            }
            break;

        case 1:
            D_801CE600 = 1;
            level = 10;
            break;

        case 2:
            D_801CE600 = 1;
            level = 40;
            break;

        case 3:
            D_801CE600 = 1;
            level = (SysUtils_Rand() % 31) + 10;
            break;
    }

    return level;
}

/* Fills the viewport rectangle with the course's menu color. */
Gfx* Gfx_FillCourseColor(Gfx* gdl, s32 courseId) {
    RGB* courseColor = &short_RGB[courseId];

    gSPDisplayList(gdl++, D_106F8A0);
    gDPSetPrimColor(gdl++, 0, 0, courseColor->r, courseColor->g, courseColor->b, 255);
    gDPFillRectangle(gdl++, 8, 20, 311, 219);

    return gdl;
}

extern Gfx D_106F8E8[];
extern Vtx* D_800DAA90[];

/* Draws the course-select course panel quad from the course vertex table. */
Gfx* Gfx_DrawCoursePanel(Gfx* gdl, s32 courseId) {
    if ((courseId < 0) || (courseId >= 9)) {
        courseId = 0;
    }
    gSPDisplayList(gdl++, D_106F8E8);
    gSPVertex(gdl++, D_800DAA90[courseId], 4, 0);
    gSP1Triangle(gdl++, 0, 3, 1, 0);
    gSP1Triangle(gdl++, 0, 2, 3, 0);
    return gdl;
}

void func_80094ABC(void) {
    D_800DAB0C = 1;
}

/* Accumulates championship points per rider, sorts the standings twice
 * (by round points, then by total, breaking ties by race position), and
 * writes each rider's championship rank. */
void Race_UpdateStandings(void) {
    s32 i;
    s32 j;
    s32 idxA;
    s32 idxB;
    s32 swap;
    s32 doSwap;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_801CE60E; j++) {
            if (i == D_801C2938[j].racePosition) {
                if (D_801C2938[j].unk2EC) {
                    D_801CB350[D_801CB334][j] = 0;
                } else {
                    D_801CB350[D_801CB334][j] = D_800EABB0[i];
                }
                D_801CB340[j] += D_801CB350[D_801CB334][j];
            }
        }
    }

    for (i = 0; i < 4; i++) {
        D_801CE718[i] = i;
    }

    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            doSwap = 0;

            idxA = D_801CE718[i];
            idxB = D_801CE718[j];

            if (D_801CB350[D_801CB334][idxA] < D_801CB350[D_801CB334][idxB]) {
                doSwap = 1;
            }

            if (doSwap != 0) {
                swap = D_801CE718[i];
                D_801CE718[i] = D_801CE718[j];
                D_801CE718[j] = swap;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        D_800DA9DC[i] = i;
    }

    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            doSwap = 0;

            idxA = D_800DA9DC[i];
            idxB = D_800DA9DC[j];

            if (D_801CB340[idxA] == D_801CB340[idxB]) {
                if (D_801C2938[idxA].racePosition > D_801C2938[idxB].racePosition) {
                    doSwap = 1;
                }
            } else if (D_801CB340[idxA] < D_801CB340[idxB]) {
                doSwap = 1;
            }

            if (doSwap != 0) {
                swap = D_800DA9DC[i];
                D_800DA9DC[i] = D_800DA9DC[j];
                D_800DA9DC[j] = swap;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (D_800DA9DC[j] == i) {
                break;
            }
        }
        D_801C2938[i].unk338 = j;
    }
}

/* Enters the boot state: resets to game state 0 for the logo/init screens. */
void Game_EnterBootState(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0;
    D_801CE638 = 0x11;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 1;
}

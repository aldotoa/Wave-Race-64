#include "common.h"

/* Per-frame menu/stick input consumed by MenuInput_UpdateRepeatState.
 * Field roles inferred from use: heldButton/pressedButton select the
 * effective button output, stickX/stickY hold the normalized
 * -1.0f..1.0f stick axes. */
typedef struct MenuRepeatInput {
    s32 heldButton;
    s32 pressedButton;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    f32 stickX;
    f32 stickY;
    s32 unk1C;
} MenuRepeatInput;

/* Snapshot of a player's controller state (buttons + raw stick),
 * filled by Controller_SnapshotPlayerInput. Field roles follow
 * SysUtils_UpdateControllers in sys_utils.c. */
typedef struct ControllerSnapshot {
    s32 buttons;        /* current buttons (ControllerBase unk_0) */
    s32 pressedButtons; /* buttons pressed this frame (unk_2) */
    s32 prevButtons;    /* previous frame buttons (unk_6) */
    s32 rawStickX;      /* raw stick X (unk_8) */
    s32 rawStickY;      /* raw stick Y (unk_9) */
} ControllerSnapshot;

/* Stick processing limits (same values as the original literals). */
#define STICK_DEADZONE 12
#define STICK_MAX_DEFLECTION 49
#define STICK_FULL_SCALE 49.0f
/* Button auto-repeat tuning in MenuInput_UpdateRepeatState. */
#define REPEAT_START_DELAY 0x18
#define REPEAT_INTERVAL 8
#define REPEAT_HOLD_CLAMP 0x258
#define STICK_DIR_THRESHOLD 0.5f

extern s32 D_800D4B00;
extern s32 D_800D4B04;
extern s32 D_800D4B08;
extern s32 D_800D4B0C;
extern UnkStruct_80198368 D_80198368[];
extern void* D_801AE94C;
extern s32 D_801AE950;
extern s32 D_801AE9D8;
extern s32 D_801AE9DC;
extern s32 D_801AE9E0;
extern s32 D_801AE9E4;
extern s32 D_801AE9E8;
extern s32 D_801AE9EC;
extern s32 D_801AE9F0;
extern s32 D_801AE9F4;
extern s32 D_801AE9F8;
extern s32 D_801AEA04;
extern s32 D_801AEA08;
extern s32 D_801AEA0C;
extern s32 D_801AEA10;
extern s32 D_801AEA00;
extern s32 D_801AE9FC;
extern ControllerSnapshot D_801AE958;
extern f32 D_801AE96C;
extern f32 D_801AE970;
extern f32 D_801AE974;
extern ControllerBase gControllerOne[];

/* Stick deadzone + range normalization.
 * Raw deflection spans +/-STICK_MAX_DEFLECTION. Each stage clamps to a
 * square: when one axis exceeds the bound, the other axis is scaled down
 * proportionally so direction is preserved. Deflections inside the
 * deadzone on both axes snap to center. Output is normalized to
 * -1.0f..1.0f. Statement order and duplicate structure match the
 * original for byte-exact codegen. */
void Controller_NormalizeStick(s32 rawX, s32 rawY, f32* outX, f32* outY) {
    s32 clampedX;
    s32 clampedY;
    s32 x;
    s32 y;

    x = *outX;
    y = *outY;

    clampedX = rawX;
    clampedY = rawY;

    if (clampedX > STICK_DEADZONE) {
        clampedY = (clampedY * STICK_DEADZONE) / clampedX;
        clampedX = STICK_DEADZONE;
    }
    if (clampedX < -STICK_DEADZONE) {
        clampedY = (clampedY * STICK_DEADZONE) / (-clampedX);
        clampedX = -STICK_DEADZONE;
    }
    if (clampedY > STICK_DEADZONE) {
        clampedX = (clampedX * STICK_DEADZONE) / clampedY;
        clampedY = STICK_DEADZONE;
    }
    if (clampedY < -STICK_DEADZONE) {
        clampedX = (clampedX * STICK_DEADZONE) / (-clampedY);
        clampedY = -STICK_DEADZONE;
    }

    if ((((rawX >= -STICK_DEADZONE) && (rawX <= STICK_DEADZONE)) && (rawY >= -STICK_DEADZONE)) &&
        (rawY <= STICK_DEADZONE)) {
        x = 0;
        y = 0;
    } else {
        x = rawX - clampedX;
        y = rawY - clampedY;
    }

    if (x > STICK_MAX_DEFLECTION) {
        y = (y * STICK_MAX_DEFLECTION) / x;
        x = STICK_MAX_DEFLECTION;
    }
    if (x < -STICK_MAX_DEFLECTION) {
        y = (y * STICK_MAX_DEFLECTION) / (-x);
        x = -STICK_MAX_DEFLECTION;
    }
    if (y > STICK_MAX_DEFLECTION) {
        x = (x * STICK_MAX_DEFLECTION) / y;
        y = STICK_MAX_DEFLECTION;
    }
    if (y < -STICK_MAX_DEFLECTION) {
        x = (x * STICK_MAX_DEFLECTION) / (-y);
        y = -STICK_MAX_DEFLECTION;
    }
    *outX = x / STICK_FULL_SCALE;
    *outY = y / STICK_FULL_SCALE;
}

/* Snapshots one player's controller into the shared menu-input state:
 * buttons go to D_801AE958, the normalized stick (via
 * Controller_NormalizeStick) to D_801AE96C/D_801AE970, and the stick
 * magnitude to D_801AE974. */
UNUSED void Controller_SnapshotPlayerInput(s32 playerIndex) {
    struct ControllerBase* ctrl;

    ctrl = &gControllerOne[playerIndex];

    D_801AE958.buttons = ctrl->unk_0;
    D_801AE958.pressedButtons = ctrl->unk_2;
    D_801AE958.prevButtons = ctrl->unk_6;
    D_801AE958.rawStickX = ctrl->unk_8;
    D_801AE958.rawStickY = ctrl->unk_9;

    Controller_NormalizeStick(ctrl->unk_8, ctrl->unk_9, &D_801AE96C, &D_801AE970);
    D_801AE974 = sqrtf(SQ(D_801AE96C) + SQ(D_801AE970));
}

UNUSED void MenuInput_ResetRepeatState(void) {
    /* Re-arm the repeat state machine (see MenuInput_UpdateRepeatState):
     * enable flags on, all hold/repeat counters and edges cleared. */
    D_801AE9FC = D_801AEA00 = 1;
    D_801AE9E0 = D_801AE9DC = 0;
    D_801AEA04 = D_801AEA08 = D_801AEA0C = D_801AEA10 = 0;
}

/* Menu/stick input repeat state machine (runs once per frame).
 * Tracks the held button (D_801AE9E0/D_801AE9DC) and the X/Y stick
 * directions (D_801AE9E4/D_801AE9E8) derived from the normalized stick
 * axes, and produces edge outputs (D_801AE9EC/D_801AE9F0) plus
 * auto-repeat outputs (D_801AE9F4/D_801AE9F8/D_801AE9D8) that start after
 * REPEAT_START_DELAY frames and re-fire every REPEAT_INTERVAL frames.
 * The four named locals below are unused; they only preserve the
 * original function's stack frame, so they must stay declared. */
UNUSED void MenuInput_UpdateRepeatState(struct MenuRepeatInput* input) {
    s32 frameKeep0;
    s32 frameKeep1;
    s32 frameKeep2;
    s32 frameKeep3;

    /* Held-button tracking: count how long the same button stays held. */
    if ((input->heldButton != 0) && (D_801AE9E0 == input->heldButton)) {
        D_801AE9DC = D_801AE9DC + 1;
        if (D_801AE9DC >= 0x259) {
            /* Duplicate store matches the original binary. */
            D_801AE9DC = REPEAT_HOLD_CLAMP;
            D_801AE9DC = REPEAT_HOLD_CLAMP;
        }
    } else {
        /* Duplicate store matches the original binary. */
        D_801AE9DC = 0;
        D_801AE9DC = 0;
    }
    /* Effective button: held button once auto-repeat kicks in, else the fresh press. */
    if ((D_801AE9DC >= REPEAT_START_DELAY) && (!(D_801AE9DC % REPEAT_INTERVAL))) {
        D_801AE9D8 = input->heldButton;
    } else {
        D_801AE9D8 = input->pressedButton;
    }
    D_801AE9E0 = input->heldButton;
    /* Stick X direction with a small centered deadzone. */
    if (input->stickX <= -STICK_DIR_THRESHOLD) {
        D_801AE9E4 = -1;
    } else if (input->stickX >= STICK_DIR_THRESHOLD) {
        D_801AE9E4 = 1;
    } else {
        D_801AE9E4 = 0;
    }
    /* Stick Y direction with a small centered deadzone. */
    if (input->stickY <= -STICK_DIR_THRESHOLD) {
        D_801AE9E8 = -1;
    } else if (input->stickY >= STICK_DIR_THRESHOLD) {
        D_801AE9E8 = 1;
    } else {
        D_801AE9E8 = 0;
    }

    /* Direction edges: report the direction only on the frame it changes. */
    if (D_801AE9E4 != D_801AEA04) {
        D_801AE9EC = D_801AE9E4;
    } else {
        D_801AE9EC = 0;
    }
    if (D_801AE9E8 != D_801AEA08) {
        D_801AE9F0 = D_801AE9E8;
    } else {
        D_801AE9F0 = 0;
    }
    /* X auto-repeat while the stick is held in the same direction. */
    if ((D_801AE9E4 != 0) && (D_801AE9E4 == D_801AEA04)) {
        if ((++D_801AEA0C) >= 0x258) {
            /* Duplicate store matches the original binary. */
            D_801AEA0C = REPEAT_HOLD_CLAMP;
            D_801AEA0C = REPEAT_HOLD_CLAMP;
        }
    } else {
        D_801AEA0C = 0;
    }
    if ((D_801AEA0C >= REPEAT_START_DELAY) && (!(D_801AEA0C % REPEAT_INTERVAL))) {
        D_801AE9F4 = D_801AE9E4;
    } else {
        D_801AE9F4 = D_801AE9EC;
    }
    /* Y auto-repeat while the stick is held in the same direction. */
    if ((D_801AE9E8 != 0) && (D_801AE9E8 == D_801AEA08)) {
        if ((++D_801AEA10) >= 0x258) {
            D_801AEA10 = REPEAT_HOLD_CLAMP;
        }
    } else {
        /* Duplicate store matches the original binary. */
        D_801AEA10 = 0;
        D_801AEA10 = 0;
    }
    if ((D_801AEA10 >= REPEAT_START_DELAY) && (!(D_801AEA10 % REPEAT_INTERVAL))) {
        D_801AE9F8 = D_801AE9E8;
    } else {
        D_801AE9F8 = D_801AE9F0;
    }
    D_801AEA04 = D_801AE9E4;
    D_801AEA08 = D_801AE9E8;
}

void Libc_strcpy(s8* dest, s8* src) {
    while ((*dest++ = *src++) != '\0') {}
}

void Libc_strncpy(s8* s1, s8* s2, s32 n) {
    while ((n-- > 0) && (*s1++ = *s2++) != '\0') {}
}

int Libc_strcmp(s8* s, s8* t) {
    while (*s == *t) {
        *s++;
        *t++;
        if (*s == '\0') {
            return 0;
        }
    }

    return *s - *t;
}

s32 Libc_strncmp(s8* str1, s8* str2, s32 n) {
    s32 charDifference;

    while (n != 0 && *str1 != '\0' && *str2 != '\0') {
        charDifference = *str1 - *str2;
        if (charDifference != 0) {
            return charDifference;
        }
        *str1++;
        *str2++;
        n--;
    }

    if (n == 0) {
        return 0;
    }

    if (*str1 != 0) {
        return 1;
    }

    if (*str2 != 0) {
        return -1;
    }

    // Dead code if the string is equal!
    return 0;
}

/* Per-frame housekeeping, called after SysUtils_UpdateControllers.
 * Clears the pending flag, advances the frame counters, and swaps the
 * ping-pong work buffer (D_801AE948 / D_801AE94C) each frame. */
void Game_AdvanceFrameState(void) {
    if (D_800D4B08 != 0) {
        D_800D4B08 = 0;
    }
    if (gCurrentPauseMenuOption == -1) {
        D_800D4B00++;
    }

    D_800D4B04++;

    D_801AE948 = &D_80198368[D_800D4B0C];
    D_800D4B0C ^= 1;
    D_801AE94C = D_801AE948;

    D_801AE950 = 0;
}

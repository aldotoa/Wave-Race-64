
#include "ctx.c"

u32 func_i2_802C5E28(void) {
    s32 player;
    s32 can_select;
    s32 rider_idx;
    s32* s1;
    s32 sound_mode;
    s32* s2;
    s32* s5;
    UnkStruct_801CE658* s6;
    u16 pressed;

    player = 0;
    if (D_801CE60C > 0) {
        s2 = D_802C8C58.as_array;
        do {
            s32 is_p2_same;
            s32 v0;
            if (player == 0) {
                rider_idx = D_800D48DC;
                v0 = 0;
            } else {
                rider_idx = D_800D48E0;
                v0 = 1;
            }

            s6 = &D_801CE658[v0];
            pressed = s6->unk_00.unk_2;

            if ((pressed & 0xB000) && (D_i2_802C8BC0 != 0)) {
                sound_mode = 1;
                switch (*s2) {
                    case 0:
                        *s2 = 1;
                        if ((D_800DAB64 != 0) && (pressed & 0x2000)) {
                            D_801CE6F4[player] = 1;
                        }
                        if (D_801CE6F4[player] != 0) {
                            D_802C8C70[D_800DA9C0[player]] |= 2;
                        } else {
                            D_802C8C70[D_800DA9C0[player]] |= 1;
                        }
                        break;
                    case 1:
                        if (D_800DA9C8[player] == 0) {
                            if (player == 0) {
                                D_801CB32C = 0;
                            }
                            if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 11)) {
                                func_i2_802C6864(player);
                                sound_mode = 2;
                            } else {
                                *s2 = 5;
                            }
                        } else {
                            if (player == 0) {
                                D_801CB32C = 1;
                            }
                            *s2 = 2;
                        }
                        break;
                    case 2:
                        *s2 = 3;
                        break;
                    case 3:
                        *s2 = 4;
                        break;
                    case 4:
                        if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 11)) {
                            func_i2_802C6864(player);
                            sound_mode = 2;
                        } else {
                            *s2 = 5;
                        }
                        break;
                    case 5:
                        func_i2_802C6864(player);
                        break;
                }
            }
            player++;
            s2++;
        } while (player < D_801CE60C);
    }
    return SysUtils_Rand();
}

#include "ctx.c"

#define ARR_VAL(arr) (*(s32*)((u8*)(arr) + offset))

u32 func_i2_802C5E28(void) {
    s32 player;
    s32 offset;
    s32 can_select;
    s32 rider_idx;
    s32* s1;
    s32 sound_mode;
    s32* s2;
    s32* s5;
    UnkStruct_801CE658* s6;
    u16 pressed;
    s32 is_p2_same;
    s32 v0;
    player = 0;
    if (D_801CE60C > 0) {
        offset = 0;
        s2 = D_802C8C58.as_array;
        do {
            if (player == 0) {
                rider_idx = D_800D48DC;
                v0 = 0;
            } else {
                rider_idx = D_800D48E0;
                v0 = 1;
            }
            s6 = &D_801CE658[v0];
            pressed = s6->unk_00.unk_2;
            is_p2_same = 1;
            s1 = &D_i2_802C8BB0[player];
            s5 = &D_i2_802C8BB8[player];
            player++;
            offset += 4;
            s2++;
        } while (player < D_801CE60C);
    }
    return SysUtils_Rand();
}

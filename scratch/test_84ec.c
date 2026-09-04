#include "common.h"

extern s32 D_801CE630;
extern s32 D_801CE638;
extern s32 D_801CE63C;
extern s32 D_801CE640;
extern s32 D_801CE644;
extern s16 D_801CE60C;
extern s32 D_800DAB1C;
extern s32 D_800D461C;
extern s32 D_800DA9C8[];
extern s32 D_800DA9C0[];
extern s32 D_800D48E0;
extern s32 D_800D48DC;
extern s32 D_i2_802C8BD8[];

void func_800C1F60(s32);

void func_i2_802C84EC(s32 arg0) {
    s32 i;
    UnkStruct_func_i8_802C6E00* ptr;
    struct UnkStruct_80192690* rider;
    s32 rider_idx;
    s32 idx;

    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0xB;
    D_801CE638 = 4;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;

    for (i = 0; i < D_801CE60C; i++) {
        if (D_800DA9C8[i] != 0) {
            idx = D_i2_802C8BD8[D_800DA9C0[i]];
            ptr = &((UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298)[i][idx];
        } else {
            idx = D_i2_802C8BD8[D_800DA9C0[i]];
            ptr = &D_800DA950[idx];
        }

        rider_idx = (i != 0) ? D_800D48E0 : D_800D48DC;
        rider = &D_80192690[rider_idx];
        rider->unkB6C = ptr->unk_B[0];
        rider->unkB70 = ptr->unk_B[1];
        rider->unkB74 = ptr->unk_B[2];
    }

    if (D_801CE608.gameMode == 4 && D_801CE630 == 30) {
        FadeTransition_SetProps(5, 0, 0);
    } else {
        FadeTransition_SetProps(0, 4, 0);
    }

    func_801E6A4C(0, 0);

    if (D_801CE630 == 30) {
        func_800C1F60(2);
    }
}

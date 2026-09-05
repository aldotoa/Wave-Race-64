extern int D_i2_802C8BB0[];
extern int D_i2_802C8BB8[];
extern int gPlayers;
extern int D_800DA9C0[];
extern short D_801CE6F4[];
void call(int);

void test(int offset, int player, int s2_val, int pressed) {
    int* s1 = (int*)((char*)D_i2_802C8BB0 + offset);
    int* s5 = (int*)((char*)D_i2_802C8BB8 + offset);
    int can_select = 0;
    int is_p2_same = 1;

    if (gPlayers != 1 && D_800DA9C0[0] == D_800DA9C0[1]) {
        is_p2_same = 0;
    }

    if (s2_val == 0) {
        if (is_p2_same != 0) {
            can_select = 1;
        } else {
            D_801CE6F4[player] = 0;
        }
    }

    *s1 = 0;
    if (pressed & 0x200) {
        call(can_select);
    }
    if (*s1 != 0) {
        *s5 = -3;
    }
}

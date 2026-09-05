
extern int D_800DA9C0[];
extern int D_800DA9C8[];
extern int D_802C8C60[];
extern int D_i2_802C8BB0[];
extern int D_i2_802C8BB8[];
extern short D_801CE60C;
extern int D_802C8C58[];
void func(int, int);

void test1(void) {
    int player;
    int* s2 = D_802C8C58;
    for (player = 0; player < D_801CE60C; player++) {
        if (*s2 == 0) {
            func(player, D_800DA9C0[0] == D_800DA9C0[1]);
        }
        func(player, D_800DA9C0[player]);
        func(player, D_800DA9C8[player]);
        func(player, D_802C8C60[player]);
        func(player, D_i2_802C8BB0[player]);
        func(player, D_i2_802C8BB8[player]);
        s2++;
    }
}

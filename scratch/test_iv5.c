extern int D_800DA9C0[];
extern int D_800DA9C8[];
extern int D_802C8C60[];
extern int D_i2_802C8BB0[];
extern int D_i2_802C8BB8[];
extern short D_801CE6F4[];
extern short count;
extern int D_800D48DC, D_800D48E0;
void bar(int);
void func(int, int);

void test(int cond) {
    int player;
    for (player = 0; player < count; player++) {
        int rider_idx = (player == 0) ? D_800D48DC : D_800D48E0;
        D_801CE6F4[player] = 1;
        if (cond == 0) {
            bar(D_800DA9C0[player]);
            bar(D_800DA9C8[player]);
            func(player, rider_idx);
        } else if (cond == 1) {
            D_800DA9C0[player]--;
            D_802C8C60[player] = 0x200;
        } else {
            bar(D_i2_802C8BB0[player]);
            bar(D_i2_802C8BB8[player]);
        }
    }
}

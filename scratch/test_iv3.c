extern int D_800DA9C0[];
extern int D_800DA9C8[];
extern int D_802C8C60[];
extern int D_i2_802C8BB0[];
extern int D_i2_802C8BB8[];
extern short count;
void bar(int);

void test(int cond) {
    int player;
    for (player = 0; player < count; player++) {
        if (cond == 0) {
            bar(D_800DA9C0[player]);
            bar(D_800DA9C8[player]);
        } else if (cond == 1) {
            D_800DA9C0[player]--;
            D_802C8C60[player] = 0x200;
        } else {
            bar(D_i2_802C8BB0[player]);
            bar(D_i2_802C8BB8[player]);
        }
    }
}

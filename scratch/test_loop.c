
extern int D_800DA9C0[];
extern int D_800DA9C8[];
extern int D_802C8C60[];
extern int D_i2_802C8BB0[];
extern int D_i2_802C8BB8[];
extern short D_801CE60C;
extern int* s2;
void func(int, int);

void test(void) {
    int player;
    int offset;
    for (player = 0, offset = 0; player < D_801CE60C; player++, offset += 4, s2++) {
        func(player, *(int*)((char*)D_800DA9C0 + offset));
        func(player, *(int*)((char*)D_800DA9C8 + offset));
    }
}

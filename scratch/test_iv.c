
extern int D_800DA9C0[];
extern int D_800DA9C8[];
extern int D_802C8C60[];
extern int D_i2_802C8BB0[];
extern int D_i2_802C8BB8[];
extern short count;
void bar(int);
void func(int);

void test(int n) {
    int player;
    int offset;
    for (player = 0; player < count; player++) {
        offset = player * 4;
        bar(*(int*)((char*)D_800DA9C0 + offset));
        bar(*(int*)((char*)D_800DA9C8 + offset));
        func(player);
        bar(*(int*)((char*)D_i2_802C8BB0 + offset));
        bar(*(int*)((char*)D_i2_802C8BB8 + offset));
    }
}

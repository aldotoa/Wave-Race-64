
extern int D_i2_802C8BB0[];
extern int D_i2_802C8BB8[];
void call(int);

void test_loop(int n) {
    int player;
    for (player = 0; player < n; player++) {
        int* p1 = &D_i2_802C8BB0[player];
        int* p2 = &D_i2_802C8BB8[player];

        *p1 = 0;
        call(1);
        if (*p1 != 0) {
            *p2 = -3;
        } else {
            (*p2)++;
            if (*p2 >= 4) {
                *p2 = 0;
                call(2);
            }
        }
    }
}

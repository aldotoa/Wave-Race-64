
typedef struct { int a; short b; } St;
extern St D_801CE658[];
extern int D_800D48DC, D_800D48E0;
void use(int, St*);

void test1(int player, int s3) {
    int rider_idx;
    St* s6;
    if (player == 0) {
        rider_idx = D_800D48DC;
    } else {
        rider_idx = D_800D48E0;
    }
    s6 = &D_801CE658[(player == 0) ? 0 : 1];
    use(rider_idx, s6);
}

void test2(int player, int s3) {
    int rider_idx;
    int v0;
    St* s6;
    if (player == 0) {
        rider_idx = D_800D48DC;
        v0 = 0;
    } else {
        rider_idx = D_800D48E0;
        v0 = 1;
    }
    s6 = &D_801CE658[v0];
    use(rider_idx, s6);
}

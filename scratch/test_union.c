
typedef int s32;
extern union {
    struct {
        s32 player_1_ready;
        s32 player_2_ready;
    };
    s32 as_array[2];
} D_802C8C58;

s32 get1(int i) {
    return D_802C8C58.as_array[i];
}

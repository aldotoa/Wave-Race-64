#include "common.h"
extern s16 D_802C8C68;
extern s16 D_802C8C6A;
void test(u8 *out) {
    u32 alpha;
    if (D_802C8C6A == 0) {
        alpha = (u32)((D_802C8C68 * 255.0f) / 4);
    } else {
        alpha = (u32)(((4 - D_802C8C68) * 255.0f) / 4);
    }
    *out = alpha;
}

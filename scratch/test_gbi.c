
#include <ultra64.h>
extern u16 D_80B6518[];
void test(Gfx** gdl) {
    gDPLoadTextureTile((*gdl)++, D_80B6518, G_IM_FMT_RGBA, G_IM_SIZ_16b, 9, 6, 0, 0, 8, 5, 0,
                       G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

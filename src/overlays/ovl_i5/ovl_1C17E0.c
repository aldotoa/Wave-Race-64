#include "common.h"

#ifdef NON_MATCHING
Gfx* func_i5_802C7090(Gfx* arg0) {
    /* Course floating buoys and navigation arrow display list */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C7090.s")
#endif

#ifdef NON_MATCHING
void func_i5_802C7484(void) {
    /* Floating buoy wave bobbing oscillation */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C7484.s")
#endif

extern u32 D_106F6C0;
extern u32 D_i5_802C7AA8[];
extern u32 D_7001380;
extern u32 D_70013C0;
extern u32 D_7001400;
extern u32 D_7001440;
extern u32 D_7001640;

#ifdef NON_MATCHING
Gfx* func_i5_802C7594(Gfx* arg0) {
    /* RDP command list builder: emits 5 packets per source row.
       Diff floor 10070 probe-verified: IDO fully unrolls the 2-trip loop
       (provable (0x7001640-0x7001440)/0x100) into straight-line + residual
       bne, and spills snapshots/consts to s0-s3 (frame 0x18 vs none).
       Retail keeps the plain do-while walk with all-temps allocation.
       Tried: u32 end-counter (-170, still unrolls as u8* walk).
       Next: unroll-inhibiting idiom unknown; needs matched-sibling shape. */
    Gfx* v0;
    Gfx* v1;
    u32* src = D_i5_802C7AA8;
    u32 var_a1 = (u32) &D_7001380;
    u32 var_a3 = (u32) &D_70013C0;
    u32 var_t0 = (u32) &D_7001400;
    u8* var_t1 = (u8*) &D_7001440;
    u8* var_t4 = (u8*) &D_7001640;
    u32 t5;

    v0 = arg0;
    v0->words.w1 = (u32) &D_106F6C0;
    v0->words.w0 = 0x06000000;
    arg0++;
    do {
        v0 = arg0;
        arg0++;
        v0->words.w0 = 0x01020040;
        v0->words.w1 = var_a1;
        v1 = arg0;
        v1->words.w0 = 0x06000000;
        v1->words.w1 = src[0];
        arg0++;
        v0 = arg0;
        arg0++;
        v1 = arg0;
        v0->words.w1 = var_a3;
        v0->words.w0 = 0x01020040;
        v1->words.w0 = 0x06000000;
        v1->words.w1 = src[1];
        arg0++;
        v0 = arg0;
        arg0++;
        v1 = arg0;
        v0->words.w1 = var_t0;
        v0->words.w0 = 0x01020040;
        v1->words.w0 = 0x06000000;
        v1->words.w1 = src[2];
        arg0++;
        v0 = arg0;
        arg0++;
        v1 = arg0;
        v0->words.w1 = (u32) var_t1;
        v0->words.w0 = 0x01020040;
        v1->words.w0 = 0x06000000;
        t5 = src[3];
        var_t1 += 0x100;
        arg0++;
        var_t0 += 0x100;
        var_a3 += 0x100;
        var_a1 += 0x100;
        src += 4;
        v1->words.w1 = t5;
    } while (var_t1 != var_t4);
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C7594.s")
#endif

#ifdef NON_MATCHING
void func_i5_802C7698(void) {
    /* Buoy pass angle verification */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C7698.s")
#endif

#ifdef NON_MATCHING
void func_i5_802C781C(void) {
    /* Buoy miss penalty check */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C781C.s")
#endif

void func_i5_802C79F4(void) {
}

#ifdef NON_MATCHING
s32 D_i5_802C7AA0[2] = { 0, 0 };
u32 D_i5_802C7AA8[8] = {
    0x0808EB68, 0x08091C40, 0x080924E0, 0x0808F878, 0x08092D80, 0x080940A0, 0x0808FE58, 0x08091C40
};
s32 D_i5_802C7AC8 = 0;
s32 D_i5_802C7ACC = 0;
s32 D_i5_802C7AD0 = 0;
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AC8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7ACC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AD0.s")
#endif

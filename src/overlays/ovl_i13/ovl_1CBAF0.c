#include "global.h"

#ifdef NON_MATCHING
Gfx* func_i13_802C5800(Gfx* arg0) {
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C5800.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C5F6C(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C5F6C.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C6068(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6068.s")
#endif

#ifdef NON_MATCHING
/* Flag chain over D_801CE65A; 0xB000 arm compares the loaded 8D50 word
   (==0 / !=1 / ==1 three-way) and always returns 1 there.
   Diff floor 305 probe-verified: branch layout exact ONLY via explicit
   goto (if/else reorders blocks: beqz/beq vs retail bnez/bne); remainder
   is the family allocator wall (loaded var_v1 homes a0, never v1).
   Tried: inner-block swap (correct semantics, +525 before goto), goto pins.
   Next: v1-homing lever unknown. */
s32 func_i13_802C61E0(void) {
    s32 var_v1 = 0;
    s32 temp1;
    s32 temp2;

    if (D_801CE65A->unk0 & 0xB000) {
        var_v1 = D_i13_802C8D50;
        if (var_v1 != 0) {
            goto inner;
        }
        D_801CE640 = 1;
        D_i13_802C8D54 = 0;
        var_v1 = 1;
        goto func_end;
    inner:
        if (var_v1 != 1) {
            goto docall;
        }
        D_801CE640 = 2;
        D_i13_802C8D54 = 0;
        var_v1 = 1;
        goto func_end;
    docall:
        func_i13_802C8CBC();
        var_v1 = 1;
        goto func_end;
    } else if (D_801CE65A->unk0 & 0x4000) {
        var_v1 = 2;
        func_i13_802C8CBC();
    } else if (D_801CE65A->unk0 & 0x200) {
        var_v1 = 3;
        temp1 = D_i13_802C8D50 - 1;
        D_i13_802C8D50 = temp1;
        if (temp1 < 0) {
            D_i13_802C8D50 = 2;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        var_v1 = 4;
        temp2 = D_i13_802C8D50 + 1;
        D_i13_802C8D50 = temp2;
        if (temp2 >= 3) {
            D_i13_802C8D50 = 0;
        }
    }
func_end:;
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C61E0.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C62EC(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C62EC.s")
#endif

#ifdef NON_MATCHING
/* Flag chain; 0xB000 arm returns 1 with a nested 82A4(2)/3E6C(3) call join,
   0x4000 arm returns 2 with mode 1.
   Diff floor 320 probe-verified: call-join structure exact with plain if;
   remainder is the family register wall. Tried: 0x4000-arm order swap to
   var_v1-first (-390, kept). */
s32 func_i13_802C64AC(void) {
    s32 var_v1 = 0;
    s32 temp1;
    s32 temp2;

    if (D_801CE65A->unk0 & 0xB000) {
        var_v1 = 1;
        if (D_i13_802C8D58 == 0) {
            D_801CE640 = 4;
            D_i13_802C8D5C = 0;
            D_i13_802C8D98 = 0x200;
        } else {
            D_801CE640 = 6;
            D_i13_802C8D70 = 1;
            if (D_i13_802C8D54 == 0) {
                func_i13_802C82A4(2);
            }
            func_800C3E6C(3);
        }
    } else if (D_801CE65A->unk0 & 0x4000) {
        var_v1 = 2;
        D_801CE640 = 1;
    } else if (D_801CE65A->unk0 & 0x200) {
        var_v1 = 3;
        temp1 = D_i13_802C8D58 - 1;
        D_i13_802C8D58 = temp1;
        if (temp1 < 0) {
            D_i13_802C8D58 = 1;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        var_v1 = 4;
        temp2 = D_i13_802C8D58 + 1;
        D_i13_802C8D58 = temp2;
        if (temp2 >= 2) {
            D_i13_802C8D58 = 0;
        }
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C64AC.s")
#endif

#ifdef NON_MATCHING
/* Flag chain; 0xB000 arm returns 1 with mode 8/7 and four zeroed words,
   0x4000 arm returns 2 with mode 3; 0x200/0x100 arms run the 8D5C counter
   with a 0x200 side-store to 8D98.
   Diff floor 325 probe-verified: remainder is the family register wall.
   Tried: 0x4000-arm order swap to var_v1-first (-390, kept). */
s32 func_i13_802C65D4(void) {
    s32 var_v1 = 0;
    s32 temp1;
    s32 temp2;

    if (D_801CE65A->unk0 & 0xB000) {
        var_v1 = 1;
        if (D_i13_802C8D54 == 0) {
            D_801CE640 = 8;
            D_i13_802C8DC4 = 0;
            D_i13_802C8DC8 = 0;
            D_i13_802C8DCC = 0;
            D_i13_802C8DD0 = 0;
        } else {
            D_801CE640 = 7;
            D_i13_802C8D70 = 1;
            func_800C3E6C(3);
        }
    } else if (D_801CE65A->unk0 & 0x4000) {
        var_v1 = 2;
        D_801CE640 = 3;
    } else if (D_801CE65A->unk0 & 0x200) {
        var_v1 = 3;
        D_i13_802C8D98 = 0x200;
        temp1 = D_i13_802C8D5C - 1;
        D_i13_802C8D5C = temp1;
        if (temp1 < 0) {
            D_i13_802C8D5C = 3;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        var_v1 = 4;
        D_i13_802C8D98 = 0x200;
        temp2 = D_i13_802C8D5C + 1;
        D_i13_802C8D5C = temp2;
        if (temp2 >= 4) {
            D_i13_802C8D5C = 0;
        }
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C65D4.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C6700(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6700.s")
#endif

extern s32 D_i13_802C8D70;
extern s32 D_i13_802C8D80;
extern s32 D_i13_802C8D84;
extern s32 D_i13_802C8DC4;
extern s32 D_i13_802C8DC8;
extern s32 D_i13_802C8DCC;
extern s32 D_i13_802C8DD0;
extern s32 D_i13_802C8DD4;
void func_i13_802C82A4(s32 arg0);
void func_i13_802C8CBC(void);

#ifdef NON_MATCHING
/* Controller-flag state machine: returns 1/5/2/3/4 by flag priority, else 0.
   Diff floor 18270 (includes trailing-function leakage in this -o form):
   structure/branches/stack all exact, remainder is pure register coloring
   (var_v1 in a1 vs v1, temps/addr shifted one class). Tried: decl order,
   initializer vs statement init, 1-vs-2 temps, named flags local, arm
   statement order -- all neutral/negative. The a1-homing trigger is
   unknown. Parked. */
s32 func_i13_802C69CC(void) {
    s32 var_v1 = 0;
    s32 temp1;
    s32 temp2;

    if (D_801CE65A->unk0 & 0xB000) {
        var_v1 = 1;
        if (D_i13_802C8D70 == 0) {
            var_v1 = 5;
            D_801CE640 = 9;
            func_i13_802C82A4(4);
        } else {
            D_801CE640 = 2;
        }
    } else if (D_801CE65A->unk0 & 0x4000) {
        var_v1 = 2;
        D_801CE640 = 2;
    } else if (D_801CE65A->unk0 & 0x200) {
        var_v1 = 3;
        temp1 = D_i13_802C8D70 - 1;
        D_i13_802C8D70 = temp1;
        if (temp1 < 0) {
            D_i13_802C8D70 = 1;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        var_v1 = 4;
        temp2 = D_i13_802C8D70 + 1;
        D_i13_802C8D70 = temp2;
        if (temp2 >= 2) {
            D_i13_802C8D70 = 0;
        }
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C69CC.s")
#endif

#ifdef NON_MATCHING
/* Twin of 69CC flag chain + D_801CE640 mode values; zeroes 8D80 always
   (branch-delay store) and 8D84 in the taken arms; cue arg 3.
   Diff floor 300 probe-verified: structure/branches/stack exact; remainder
   is pure register rotation (var_v1 a1 vs v1 + cascading addr/temp homes),
   the same allocator wall as parked 69CC. Tried: 0x4000-arm statement order
   to retail textual order (-390, kept). Next: v1-homing lever unknown. */
s32 func_i13_802C6ABC(void) {
    s32 var_v1 = 0;
    s32 temp1;
    s32 temp2;

    D_i13_802C8D80 = 0;
    if (D_801CE65A->unk0 & 0xB000) {
        var_v1 = 1;
        D_i13_802C8D84 = 0;
        if (D_i13_802C8D70 == 0) {
            var_v1 = 5;
            D_801CE640 = 0xA;
            func_i13_802C82A4(3);
        } else {
            D_801CE640 = 1;
        }
    } else if (D_801CE65A->unk0 & 0x4000) {
        D_801CE640 = 3;
        var_v1 = 2;
        D_i13_802C8D84 = 0;
    } else if (D_801CE65A->unk0 & 0x200) {
        var_v1 = 3;
        temp1 = D_i13_802C8D70 - 1;
        D_i13_802C8D70 = temp1;
        if (temp1 < 0) {
            D_i13_802C8D70 = 1;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        var_v1 = 4;
        temp2 = D_i13_802C8D70 + 1;
        D_i13_802C8D70 = temp2;
        if (temp2 >= 2) {
            D_i13_802C8D70 = 0;
        }
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6ABC.s")
#endif

#ifdef NON_MATCHING
/* Flag chain; 0xB000 arm returns 1/5 with mode 0xB/4, zeroes 8DC8/8DD4/8DD0
   in the nonzero and 0x4000 paths; cue arg 3.
   Diff floor 330 probe-verified: structure/branches/stack exact; remainder
   is the family register wall (var_v1 a1 vs v1 + cascade), same as parked
   69CC/6ABC/61E0. */
s32 func_i13_802C6BC4(void) {
    s32 var_v1 = 0;
    s32 temp1;
    s32 temp2;

    if (D_801CE65A->unk0 & 0xB000) {
        var_v1 = 1;
        if (D_i13_802C8D70 == 0) {
            var_v1 = 5;
            D_801CE640 = 0xB;
            func_i13_802C82A4(3);
        } else {
            D_801CE640 = 4;
            D_i13_802C8DC8 = 0;
            D_i13_802C8DD4 = 0;
            D_i13_802C8DD0 = 0;
        }
    } else if (D_801CE65A->unk0 & 0x4000) {
        D_801CE640 = 4;
        D_i13_802C8DC8 = 0;
        D_i13_802C8DD4 = 0;
        var_v1 = 2;
        D_i13_802C8DD0 = 0;
    } else if (D_801CE65A->unk0 & 0x200) {
        var_v1 = 3;
        temp1 = D_i13_802C8D70 - 1;
        D_i13_802C8D70 = temp1;
        if (temp1 < 0) {
            D_i13_802C8D70 = 1;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        var_v1 = 4;
        temp2 = D_i13_802C8D70 + 1;
        D_i13_802C8D70 = temp2;
        if (temp2 >= 2) {
            D_i13_802C8D70 = 0;
        }
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6BC4.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C6CE4(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6CE4.s")
#endif

extern s32 D_i13_802C8D50;
extern s32 D_i13_802C8D54;
extern s32 D_i13_802C8D58;
extern s32 D_i13_802C8D5C;
extern s32 D_i13_802C8D98;
extern s32 D_i13_802C8D74;
extern s32 D_i13_802C8D80;
extern s32 D_i13_802C8D84;
s32 func_8007D2D4(s32);
s32 func_8007D614(s32);
void func_800C3E6C(s32);

s32 func_i13_802C6E48(void) {
    s32 temp = 0;

    if (D_i13_802C8D80 == 0) {
        return 0;
    }

    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 0;

    if (D_i13_802C8D54 == 0) {
        D_i13_802C8D74 = func_8007D2D4(5);
    } else {
        D_i13_802C8D74 = func_8007D614(5);
    }

    if (D_i13_802C8D74 == 0) {
        D_801CE640 = 1;
        temp = 1;
    } else {
        D_801CE640 = 3;
    }

    if (temp != 0) {
        func_800C3E6C(1);
    }

    return 0;
}

#ifdef NON_MATCHING
void func_i13_802C6F0C(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6F0C.s")
#endif

void func_i13_802C7060(void) {
    switch (D_i13_802C8D78) {
        case 1:
            if (D_802C8E98 >= 5) {
                D_i13_802C8D78 = 2;
                D_802C8E98 = 0;
            }
            break;

        case 2:
            if (++D_802C8E98 >= 0xA) {
                D_i13_802C8D78 = 3;
                D_802C8E98 = 0;
            }
            break;

        case 3:
            if (++D_i13_802C8DC0 >= 0x5B) {
                D_i13_802C8D78 = 0;
                D_802C8E98 = 0;
                D_i13_802C8DC0 = 0;
            }
            break;
    }
}

#ifdef NON_MATCHING
void func_i13_802C711C(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C711C.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C81AC(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C81AC.s")
#endif

extern s32 D_i13_802C8D80;
extern s32 D_i13_802C8D84;
extern s32 D_802C8E90;
extern s32 D_802C8E94;
extern s32 D_802C8E98;
extern s32 D_802C8E9C;

void func_i13_802C82A4(s32 arg0) {
    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 1;
    D_802C8E90 = 0x1C;
    D_802C8E94 = 0x44;
    D_802C8E98 = 0;
    switch (arg0) {
        case 2:
            D_802C8E9C = 5;
            break;
        case 3:
            D_802C8E9C = 7;
            break;
        case 4:
            D_802C8E9C = 8;
            break;
    }
}

#ifdef NON_MATCHING
void func_i13_802C832C(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C832C.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C8484(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C8484.s")
#endif

void func_i13_802C8CBC(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x41;
    D_801CE638 = 0xB;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 4, 0);
}

#include "global.h"

/* Forward declarations (verbatim copies of the same-file draft definitions)
   and file-data externs. Prototypes/externs emit no code, so the matching
   build is unaffected; they only cure implicit declarations in this TU. */
void func_i13_802C82A4(s32 arg0);
void func_i13_802C8CBC(void);
void func_800C3E6C(s32);
s32 func_8007BDB8(void);
void func_800C3010(u32 arg0);
s32 Save_PfsDeleteFile(void);
s32 func_8007D2D4(s32 arg0);
s32 func_8007D614(s32 arg0);
Gfx* func_801E7E74(Gfx* glistp, s32 a1, s32 a2, s32 a3, s32 a4);
Gfx* func_801E7FD8(Gfx* glistp, s32 a1, s32 a2, s32 a3, s32 a4);
Gfx* func_i13_802C8484(Gfx* arg0, s32 arg1);
Gfx* func_i13_802C711C(Gfx*);
void func_i13_802C81AC(s32);
Gfx* func_i13_802C832C(Gfx*);
void func_i13_802C6068(void);
void func_i13_802C7060(void);
extern s32 D_i13_802C8D50;
extern s32 D_i13_802C8D54;
extern s32 D_i13_802C8D58;
extern s32 D_i13_802C8D5C;
extern s32 D_i13_802C8D60[];
extern s32 D_i13_802C8D70;
extern s32 D_i13_802C8D74;
extern s32 D_i13_802C8D78;
extern s32 D_i13_802C8D7C;
extern s32 D_i13_802C8D80;
extern s32 D_i13_802C8D84;
extern s32 D_i13_802C8D98;
extern s32 D_i13_802C8DC0;
extern s32 D_i13_802C8DC4;
extern s32 D_i13_802C8DC8;
extern s32 D_i13_802C8DCC;
extern s32 D_i13_802C8DD0;
extern s32 D_i13_802C8DD4;
extern s32 D_i13_802C8DE0[];

#ifdef NON_MATCHING
Gfx* func_i13_802C5800(Gfx* arg0) {
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C5800.s")
#endif

Gfx* func_i13_802C5F6C(Gfx* dList) {
    /* Twilight City race frame: clears the frame on reset, builds the course
     * scene, flushes the pending 8D74 command, appends the water surface,
     * then runs either the 0x40 results branch or the attract tail. */
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x40) {
            return Gfx_ClearFrameBuffers(dList);
        }
    }

    D_800DAB2C = 0;

    dList = func_i13_802C711C(dList);

    if (D_i13_802C8D74 != 0) {
        func_i13_802C81AC(D_i13_802C8D74);
        D_i13_802C8D74 = 0;
    }

    dList = func_i13_802C832C(dList);

    if (gGameState == 0x40) {
        if (D_i13_802C8D78 == 0) {
            func_i13_802C6068();
        } else {
            func_i13_802C7060();
        }
    } else if (D_80228A16 == 1) {
        func_801EC304();
    }

    return dList;
}

#ifdef NON_MATCHING
void func_i13_802C6068(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6068.s")
#endif

s32 func_i13_802C61E0(void) {
    s32 var_v1 = 0;

    if (D_801CE65A->unk0 & 0xB000) {
        var_v1 = D_i13_802C8D50;
        if (var_v1 == 0) {
            D_801CE640 = 1;
            D_i13_802C8D54 = 0;
        } else if (var_v1 == 1) {
            D_801CE640 = 2;
            D_i13_802C8D54 = 0;
        } else {
            func_i13_802C8CBC();
        }
        var_v1 = 1;
    } else if (D_801CE65A->unk0 & 0x4000) {
        var_v1 = 2;
        func_i13_802C8CBC();
    } else if (D_801CE65A->unk0 & 0x200) {
        var_v1 = 3;
        D_i13_802C8D50--;
        if (D_i13_802C8D50 < 0) {
            D_i13_802C8D50 = 2;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        var_v1 = 4;
        D_i13_802C8D50++;
        if (D_i13_802C8D50 >= 3) {
            D_i13_802C8D50 = 0;
        }
    }
    return var_v1;
}

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
/* Twin of 6F0C entry/flag shape (8D80 gate, 8D80/8D84 clear, 8D54 split,
   800C3E6C tail cue, returns 0) selecting a course index out of the
   8D60 table via 8DE0[8D5C], probing it with 8007D2D4 (8D54 == 0 arm,
   +0x80 when 8DC4 set) or 8007D614, and latching 8D74/CE640/8D7C.
   SIGNATURE WORKAROUND: the stub is arg-less (a1 is zeroed in the first
   branch's delay slot, so no incoming value survives) and returns 0, but
   the flag local homes in a1 in retail (beql a1 tail, a1 spills) -- the
   same allocator wall as parked 69CC/6ABC. Reusing dead incoming regs as
   the flag (`s32 f(s32 var_a0, s32 arg1)` + `arg1 = 0`) reproduces the
   a1-homing exactly, and assignment-in-condition (`if ((D_8D74 =
   f(...)) == 0)`) fixes store order and the whole t-rotation (57 -> 5).
   No callers exist anywhere in tree, so the invented params break
   nothing; true prototype is almost certainly s32 (void). Revisit with
   the 69CC-family a1-homing lever if it is ever found.
   Diff floor 5 probe-verified (3 ordered rows, 90 vs 89 insn, 5 variants):
   only deltas are frame 0x18 vs 0x20 and one dead `sw a0,24(sp)`
   prologue row. */
s32 func_i13_802C6CE4(s32 var_a0, s32 arg1) {
    arg1 = 0;

    if (D_i13_802C8D80 == 0) {
        return 0;
    }
    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 0;
    if (D_i13_802C8D54 == 0) {
        var_a0 = D_i13_802C8D60[D_i13_802C8DE0[D_i13_802C8D5C]];
        if (D_i13_802C8DC4 != 0) {
            var_a0 += 0x80;
        }
        if ((D_i13_802C8D74 = func_8007D2D4(var_a0)) == 0) {
            D_801CE640 = 0;
            D_i13_802C8D7C = 3;
            arg1 = 1;
        } else {
            D_801CE640 = 4;
        }
        D_i13_802C8DC8 = 0;
        D_i13_802C8DD4 = 0;
        D_i13_802C8DD0 = 0;
    } else {
        if ((D_i13_802C8D74 = func_8007D614(D_i13_802C8D60[D_i13_802C8DE0[D_i13_802C8D5C]])) == 0) {
            D_801CE640 = 0;
            D_i13_802C8D7C = 3;
            arg1 = 1;
        } else {
            D_801CE640 = 4;
        }
    }
    if (arg1 != 0) {
        func_800C3E6C(1);
    }
    return 0;
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
/* Save-slot menu handler: early-returns 0 while 8D80 is clear (branch-delay
   stack flag store); else zeroes 8D80/8D84 and either rebuilds the mode
   defaults (8D54 == 0 arm: BDB8 + D_801CB280 mask bits select 800C3010 cue
   3/1/0 and 3034/3044 for bit 0x20) or records Save_PfsDeleteFile status.
   Tail cues 800C3E6C(2) unless both arms left the flag clear; returns 0.
   Diff floor 26 probe-verified (16 ordered rows, 84 vs 85 insn): frame
   0x20 + ra/home slots exact, all 8 jals with correct args, branch layout
   exact. Remainder is pure t-register rotation + one lui-v1/addiu vs
   lui-at row. Dead axes (13 variants, all neutral): decl order (6 orders),
   init-vs-assign, block scope, volatile, extra temp, operand commutation,
   array-homed flag. Load-bearing: early-return entry shape, s8 masked
   temp (sll/sra sign-extend shape from the stub's lb load). */
s32 func_i13_802C6F0C(void) {
    s32 sp1C = 0;
    s32 temp_v0;
    s8 temp;

    if (D_i13_802C8D80 == 0) {
        return 0;
    }
    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 0;
    if (D_i13_802C8D54 == 0) {
        func_8007BDB8();
        temp = D_801CB280 & 0xC0;
        sp1C = 1;
        D_801CE640 = 0;
        if (temp & 0x40) {
            D_800DA9EC[0] = 1;
            func_800C3010(3);
        } else if (temp & 0x80) {
            D_800DA9EC[0] = 2;
            func_800C3010(1);
        } else {
            D_800DA9EC[0] = 0;
            func_800C3010(0);
        }
        if (D_801CB280 & 0x20) {
            D_800DA9EC[1] = 0;
            func_800C3044();
        } else {
            D_800DA9EC[1] = 1;
            func_800C3034();
        }
    } else {
        temp_v0 = Save_PfsDeleteFile();
        D_i13_802C8D74 = temp_v0;
        if (temp_v0 == 0) {
            sp1C = 1;
        }
        D_801CE640 = 0;
    }
    if (sp1C != 0) {
        func_800C3E6C(2);
    }
    return 0;
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
Gfx* func_i13_802C711C(Gfx* arg0) {
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C711C.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C81AC(s32 arg0) {
    (void) arg0;
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
/* Course-select panel renderer: switch on 8D78. Case 1 advances the 8E98
   counter, derives the panel height as (t*0x14)/5, resets 8E90/8E94 at
   t >= 5, and chains 7E74 + 7FD8 with the sliding rect; cases 2/3/5 draw
   the static rect and chain 8484. Returns the Gfx cursor.
   Diff floor 73 probe-verified (82 vs 86 insn, 4 variants): switch header,
   call skeleton (7E74/7FD8/8484), and return sequence exact. Remainder is
   div-before-compare scheduling in the case-1 body plus 8E90/94 homing
   (retail: t-regs+v1; draft: direct to a1/a2) and frame 0x30 vs 0x28.
   Dead axes: nested vs sequential calls, decl order, block scope.
   Load-bearing: `case 2/3/5` shared arm, `(t*0x14)/5` div shape,
   `>= 5` compare direction. */
Gfx* func_i13_802C832C(Gfx* arg0) {

    switch (D_i13_802C8D78) {
        case 1: {
            s32 temp_t7;
            s32 temp_lo;

            temp_t7 = D_802C8E98 + 1;
            temp_lo = (temp_t7 * 0x14) / 5;
            D_802C8E98 = temp_t7;
            if (temp_t7 >= 5) {
                D_802C8E90 = 0x1C;
                D_802C8E94 = 0x44;
            }
            D_802C8E94 = 0x58 - temp_lo;
            arg0 = func_801E7E74(arg0, 0, 0, 0, 0xFF);
            arg0 = func_801E7FD8(arg0, D_802C8E90, D_802C8E94, D_802C8E90 + 0x108, (temp_lo * 2) + D_802C8E94);
            break;
        }
        case 2:
        case 3:
        case 5:
            arg0 = func_801E7E74(arg0, 0, 0, 0, 0xFF);
            arg0 = func_801E7FD8(arg0, D_802C8E90, D_802C8E94, D_802C8E90 + 0x108, D_802C8E94 + 0x28);
            arg0 = func_i13_802C8484(arg0, 0);
            break;
    }
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C832C.s")
#endif

#ifdef NON_MATCHING
/* Placeholder signature follows the 832C call-site evidence
   (Gfx cursor in a0, 0 in a1); body still to be decompiled (jump-table
   switch: parked until whole-file table migration). */
Gfx* func_i13_802C8484(Gfx* arg0, s32 arg1) {
    ((void) arg1);
    return arg0;
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

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
s32 Save_PfsFindFile(void);
s32 Save_PfsCheckFree(void);
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

s32 func_i13_802C61E0(void);
s32 func_i13_802C62EC(void);
s32 func_i13_802C64AC(void);
s32 func_i13_802C65D4(void);
s32 func_i13_802C6700(void);
s32 func_i13_802C69CC(void);
s32 func_i13_802C6ABC(void);
s32 func_i13_802C6BC4(void);
s32 func_i13_802C6CE4(void);
s32 func_i13_802C6E48(void);
s32 func_i13_802C6F0C(void);

void func_i13_802C6068(void) {
    s32 pad;
    s32 sound;

    switch (D_801CE640) {
        case 0:
            sound = func_i13_802C61E0();
            break;
        case 1:
        case 2:
            sound = func_i13_802C62EC();
            break;
        case 3:
            sound = func_i13_802C64AC();
            break;
        case 4:
            sound = func_i13_802C65D4();
            break;
        case 8:
            sound = func_i13_802C6700();
            break;
        case 5:
            sound = func_i13_802C69CC();
            break;
        case 6:
            sound = func_i13_802C6ABC();
            break;
        case 7:
            sound = func_i13_802C6BC4();
            break;
        case 11:
            sound = func_i13_802C6CE4();
            break;
        case 10:
            sound = func_i13_802C6E48();
            break;
        case 9:
            sound = func_i13_802C6F0C();
            break;
    }
    if (sound == 1) {
        AudioGeneral_PlaySound(0x11, 0);
    } else if (sound == 2) {
        AudioGeneral_PlaySound(0x16, 0);
    } else if (sound == 3) {
        AudioGeneral_PlaySound(0x10, 0);
    } else if (sound == 4) {
        AudioGeneral_PlaySound(0x10, 0);
    } else if (sound == 5) {
        AudioGeneral_PlaySound(0x37, 0);
    }
}

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

/* Controller-flag state machine for file search & validation:
   returns 1/2/3/4 by flag priority, else 0. */
s32 func_i13_802C62EC(void) {
    s32 ret = 0;
    s32 result;

    if (D_801CE65A->unk0 & 0xB000) {
        ret = 1;
        if (D_801CE640 == 1) {
            if (D_i13_802C8D54 == 0) {
                result = D_i13_802C8D74 = Save_PfsFindFile();
            } else {
                result = D_i13_802C8D74 = Save_PfsFindFile();
                if (result == 4) {
                    result = D_i13_802C8D74 = Save_PfsCheckFree();
                }
            }
            if (result == 0) {
                D_801CE640 = 3;
                D_i13_802C8D58 = 0;
            }
        } else {
            if (D_i13_802C8D54 == 1) {
                D_i13_802C8D74 = Save_PfsFindFile();
            }
            if (D_i13_802C8D74 == 0) {
                D_801CE640 = 5;
                D_i13_802C8D70 = 1;
                func_800C3E6C(3);
            }
        }
    } else if (D_801CE65A->unk0 & 0x4000) {
        D_801CE640 = 0;
        ret = 2;
        D_i13_802C8D54 = 0;
    } else if (D_801CE65A->unk0 & 0x200) {
        ret = 3;
        if (--D_i13_802C8D54 < 0) {
            D_i13_802C8D54 = 1;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        ret = 4;
        if (++D_i13_802C8D54 >= 2) {
            D_i13_802C8D54 = 0;
        }
    }
    return ret;
}

s32 func_i13_802C64AC(void) {
    s32 var_v1 = 0;

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
        D_i13_802C8D58--;
        if (D_i13_802C8D58 < 0) {
            D_i13_802C8D58 = 1;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        var_v1 = 4;
        D_i13_802C8D58++;
        if (D_i13_802C8D58 >= 2) {
            D_i13_802C8D58 = 0;
        }
    }
    return var_v1;
}

s32 func_i13_802C65D4(void) {
    s32 var_v1 = 0;

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
        D_i13_802C8D5C--;
        if (D_i13_802C8D5C < 0) {
            D_i13_802C8D5C = 3;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        var_v1 = 4;
        D_i13_802C8D98 = 0x200;
        D_i13_802C8D5C++;
        if (D_i13_802C8D5C >= 4) {
            D_i13_802C8D5C = 0;
        }
    }
    return var_v1;
}

extern s32 D_802C8EB0;
extern s32 D_802C8EB4;
extern s32 D_802C8EB8;
extern s32 D_802C8EBC;

s32 func_i13_802C6700(void) {
    s32 ret = 0;
    f32 a;
    f32 b;

    switch (D_i13_802C8DD0) {
        case 0:
            D_i13_802C8DC8 = 1;
            D_i13_802C8DCC++;
            a = (5 - D_i13_802C8DCC) / 5.0f;
            b = D_i13_802C8DCC / 5.0f;
            D_802C8EB0 = (s32) (129.0f * a) + 0x1F;
            D_802C8EB4 = (s32) (20.0f * a) + 0x89;
            D_802C8EB8 = (s32) (258.0f * b);
            D_802C8EBC = (s32) (40.0f * b);
            if (D_i13_802C8DCC >= 5) {
                D_i13_802C8DD0 = 1;
                D_i13_802C8DD4 = 1;
            }
            break;
        case 1:
            if (D_801CE65A->unk0 & 0xB000) {
                D_801CE640 = 7;
                D_i13_802C8D70 = 1;
                ret = 1;
                func_800C3E6C(3);
            } else if (D_801CE65A->unk0 & 0x4000) {
                D_i13_802C8DD0 = 2;
                D_i13_802C8DCC = 0;
                ret = 2;
                D_i13_802C8DD4 = 0;
            } else if (D_801CE65A->unk0 & 0x200) {
                ret = 3;
                D_i13_802C8DC4 ^= 1;
            } else if (D_801CE65A->unk0 & 0x100) {
                ret = 4;
                D_i13_802C8DC4 ^= 1;
            }
            break;
        case 2:
            D_i13_802C8DC8 = 1;
            D_i13_802C8DCC++;
            b = (5 - D_i13_802C8DCC) / 5.0f;
            a = D_i13_802C8DCC / 5.0f;
            D_802C8EB0 = (s32) (129.0f * a) + 0x1F;
            D_802C8EB4 = (s32) (20.0f * a) + 0x89;
            D_802C8EB8 = (s32) (258.0f * b);
            D_802C8EBC = (s32) (40.0f * b);
            if (D_i13_802C8DCC >= 5) {
                D_i13_802C8DD0 = 0;
                D_801CE640 = 4;
            }
            break;
    }
    return ret;
}

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

s32 func_i13_802C69CC(void) {
    s32 ret = 0;

    if (D_801CE65A->unk0 & 0xB000) {
        ret = 1;
        if (D_i13_802C8D70 == 0) {
            ret = 5;
            D_801CE640 = 9;
            func_i13_802C82A4(4);
        } else {
            D_801CE640 = 2;
        }
    } else if (D_801CE65A->unk0 & 0x4000) {
        ret = 2;
        D_801CE640 = 2;
    } else if (D_801CE65A->unk0 & 0x200) {
        ret = 3;
        if (--D_i13_802C8D70 < 0) {
            D_i13_802C8D70 = 1;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        ret = 4;
        if (++D_i13_802C8D70 >= 2) {
            D_i13_802C8D70 = 0;
        }
    }
    return ret;
}

s32 func_i13_802C6ABC(void) {
    s32 var_v1 = 0;

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
        D_i13_802C8D70--;
        if (D_i13_802C8D70 < 0) {
            D_i13_802C8D70 = 1;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        var_v1 = 4;
        D_i13_802C8D70++;
        if (D_i13_802C8D70 >= 2) {
            D_i13_802C8D70 = 0;
        }
    }
    return var_v1;
}

s32 func_i13_802C6BC4(void) {
    s32 var_v1 = 0;

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
        D_i13_802C8D70--;
        if (D_i13_802C8D70 < 0) {
            D_i13_802C8D70 = 1;
        }
    } else if (D_801CE65A->unk0 & 0x100) {
        var_v1 = 4;
        D_i13_802C8D70++;
        if (D_i13_802C8D70 >= 2) {
            D_i13_802C8D70 = 0;
        }
    }
    return var_v1;
}

s32 func_i13_802C6CE4(void) {
    s32 sp1C = 0;
    s32 course;

    if (D_i13_802C8D80 == 0) {
        return 0;
    }
    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 0;
    if (D_i13_802C8D54 == 0) {
        course = D_i13_802C8D60[D_i13_802C8DE0[D_i13_802C8D5C]];
        if (D_i13_802C8DC4 != 0) {
            course += 0x80;
        }
        if ((D_i13_802C8D74 = func_8007D2D4(course)) == 0) {
            D_801CE640 = 0;
            D_i13_802C8D7C = 3;
            sp1C = 1;
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
            sp1C = 1;
        } else {
            D_801CE640 = 4;
        }
    }
    if (sp1C != 0) {
        func_800C3E6C(1);
    }
    return 0;
}

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

s32 func_i13_802C6F0C(void) {
    s32 sp1C = 0;
    s8 temp;

    if (D_i13_802C8D80 == 0) {
        return 0;
    }
    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 0;
    if (D_i13_802C8D54 == 0) {
        func_8007BDB8();
        sp1C = 1;
        temp = D_801CB280 & 0xC0;
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
        if ((D_i13_802C8D74 = Save_PfsDeleteFile()) == 0) {
            sp1C = 1;
        }
        D_801CE640 = 0;
    }
    if (sp1C != 0) {
        func_800C3E6C(2);
    }
    return 0;
}

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

extern u32 D_802C8E90;
extern u32 D_802C8E94;
extern s32 D_802C8E9C;

void func_i13_802C81AC(s32 arg0) {
    s32 var_v0;

    D_i13_802C8D84 = 0;
    D_i13_802C8D78 = 1;
    D_802C8E90 = 0x1C;
    D_802C8E94 = 0x44;
    D_802C8E98 = 0;
    var_v0 = 0;
    switch (arg0) {
        case 1:
            var_v0 = 1;
            D_802C8E9C = 4;
            break;
        case 6:
            var_v0 = 1;
            D_802C8E9C = 6;
            break;
        case 3:
            var_v0 = 1;
            D_802C8E9C = 0;
            break;
        case 4:
            var_v0 = 1;
            D_802C8E9C = 2;
            break;
        case 2:
        case 5:
            var_v0 = 1;
            if (D_i13_802C8D50 == 0) {
                D_802C8E9C = 1;
            } else {
                D_802C8E9C = 3;
            }
            break;
    }
    if (var_v0 != 0) {
        func_800C3E6C(0);
    }
}

extern s32 D_i13_802C8D80;
extern s32 D_i13_802C8D84;
extern u32 D_802C8E90;
extern u32 D_802C8E94;
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

Gfx* func_i13_802C832C(Gfx* arg0) {
    switch (D_i13_802C8D78) {
        case 1: {
            s32 temp_lo;

            D_802C8E98++;
            temp_lo = (D_802C8E98 * 0x14) / 5;
            if (D_802C8E98 >= 5) {
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

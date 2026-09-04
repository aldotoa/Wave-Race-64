nonmatching func_1B1FB0_802C5BA4, 0x250

glabel func_1B1FB0_802C5BA4
    /* 1B2354 802C5BA4 3C02801D */  lui        $v0, %hi(D_801CE63C)
    /* 1B2358 802C5BA8 2442E63C */  addiu      $v0, $v0, %lo(D_801CE63C)
    /* 1B235C 802C5BAC 8C4E0000 */  lw         $t6, 0x0($v0)
    /* 1B2360 802C5BB0 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* 1B2364 802C5BB4 AFB00020 */  sw         $s0, 0x20($sp)
    /* 1B2368 802C5BB8 00808025 */  or         $s0, $a0, $zero
    /* 1B236C 802C5BBC 11C0000B */  beqz       $t6, .L1B1FB0_802C5BEC
    /* 1B2370 802C5BC0 AFBF0024 */   sw        $ra, 0x24($sp)
    /* 1B2374 802C5BC4 AC400000 */  sw         $zero, 0x0($v0)
    /* 1B2378 802C5BC8 3C0F800E */  lui        $t7, %hi(gGameState)
    /* 1B237C 802C5BCC 8DEFAB24 */  lw         $t7, %lo(gGameState)($t7)
    /* 1B2380 802C5BD0 24010005 */  addiu      $at, $zero, 0x5
    /* 1B2384 802C5BD4 15E10005 */  bne        $t7, $at, .L1B1FB0_802C5BEC
    /* 1B2388 802C5BD8 00000000 */   nop
    /* 1B238C 802C5BDC 0C0B1CEC */  jal        func_1B1FB0_802C73B0
    /* 1B2390 802C5BE0 00000000 */   nop
    /* 1B2394 802C5BE4 1000007F */  b          .L1B1FB0_802C5DE4
    /* 1B2398 802C5BE8 8FBF0024 */   lw        $ra, 0x24($sp)
  .L1B1FB0_802C5BEC:
    /* 1B239C 802C5BEC 3C01800E */  lui        $at, %hi(D_800DAB2C)
    /* 1B23A0 802C5BF0 AC20AB2C */  sw         $zero, %lo(D_800DAB2C)($at)
    /* 1B23A4 802C5BF4 02001025 */  or         $v0, $s0, $zero
    /* 1B23A8 802C5BF8 3C180806 */  lui        $t8, %hi(D_8066180)
    /* 1B23AC 802C5BFC 3C070600 */  lui        $a3, (0x6000000 >> 16)
    /* 1B23B0 802C5C00 27186180 */  addiu      $t8, $t8, %lo(D_8066180)
    /* 1B23B4 802C5C04 26030008 */  addiu      $v1, $s0, 0x8
    /* 1B23B8 802C5C08 AC580004 */  sw         $t8, 0x4($v0)
    /* 1B23BC 802C5C0C AC470000 */  sw         $a3, 0x0($v0)
    /* 1B23C0 802C5C10 24650008 */  addiu      $a1, $v1, 0x8
    /* 1B23C4 802C5C14 3C19E700 */  lui        $t9, (0xE7000000 >> 16)
    /* 1B23C8 802C5C18 AC790000 */  sw         $t9, 0x0($v1)
    /* 1B23CC 802C5C1C AC600004 */  sw         $zero, 0x4($v1)
    /* 1B23D0 802C5C20 3C09009F */  lui        $t1, (0x9FC77C >> 16)
    /* 1B23D4 802C5C24 3529C77C */  ori        $t1, $t1, (0x9FC77C & 0xFFFF)
    /* 1B23D8 802C5C28 24A60008 */  addiu      $a2, $a1, 0x8
    /* 1B23DC 802C5C2C 3C08ED00 */  lui        $t0, (0xED000000 >> 16)
    /* 1B23E0 802C5C30 3C0A0806 */  lui        $t2, %hi(D_80661F8)
    /* 1B23E4 802C5C34 ACA80000 */  sw         $t0, 0x0($a1)
    /* 1B23E8 802C5C38 ACA90004 */  sw         $t1, 0x4($a1)
    /* 1B23EC 802C5C3C 254A61F8 */  addiu      $t2, $t2, %lo(D_80661F8)
    /* 1B23F0 802C5C40 ACCA0004 */  sw         $t2, 0x4($a2)
    /* 1B23F4 802C5C44 ACC70000 */  sw         $a3, 0x0($a2)
    /* 1B23F8 802C5C48 0C0B18B9 */  jal        func_1B1FB0_802C62E4
    /* 1B23FC 802C5C4C 24C40008 */   addiu     $a0, $a2, 0x8
    /* 1B2400 802C5C50 3C0B0806 */  lui        $t3, %hi(D_8066A80)
    /* 1B2404 802C5C54 3C0C0806 */  lui        $t4, %hi(D_80671B8)
    /* 1B2408 802C5C58 3C070600 */  lui        $a3, (0x6000000 >> 16)
    /* 1B240C 802C5C5C 256B6A80 */  addiu      $t3, $t3, %lo(D_8066A80)
    /* 1B2410 802C5C60 258C71B8 */  addiu      $t4, $t4, %lo(D_80671B8)
    /* 1B2414 802C5C64 AC4B0004 */  sw         $t3, 0x4($v0)
    /* 1B2418 802C5C68 AC470000 */  sw         $a3, 0x0($v0)
    /* 1B241C 802C5C6C AC4C000C */  sw         $t4, 0xC($v0)
    /* 1B2420 802C5C70 AC470008 */  sw         $a3, 0x8($v0)
    /* 1B2424 802C5C74 0C0B1A5C */  jal        func_1B1FB0_802C6970
    /* 1B2428 802C5C78 24440010 */   addiu     $a0, $v0, 0x10
    /* 1B242C 802C5C7C 0C0B1B07 */  jal        func_1B1FB0_802C6C1C
    /* 1B2430 802C5C80 00402025 */   or        $a0, $v0, $zero
    /* 1B2434 802C5C84 3C0DFA00 */  lui        $t5, (0xFA000000 >> 16)
    /* 1B2438 802C5C88 AC4D0000 */  sw         $t5, 0x0($v0)
    /* 1B243C 802C5C8C 3C0E802C */  lui        $t6, %hi(D_802C7710)
    /* 1B2440 802C5C90 8DCE7710 */  lw         $t6, %lo(D_802C7710)($t6)
    /* 1B2444 802C5C94 3C01FF00 */  lui        $at, (0xFF0000FF >> 16)
    /* 1B2448 802C5C98 3C09802C */  lui        $t1, %hi(D_1B1FB0_802C76A8)
    /* 1B244C 802C5C9C 31CF00FF */  andi       $t7, $t6, 0xFF
    /* 1B2450 802C5CA0 000FC400 */  sll        $t8, $t7, 16
    /* 1B2454 802C5CA4 0301C825 */  or         $t9, $t8, $at
    /* 1B2458 802C5CA8 372800FF */  ori        $t0, $t9, (0xFF0000FF & 0xFFFF)
    /* 1B245C 802C5CAC AC480004 */  sw         $t0, 0x4($v0)
    /* 1B2460 802C5CB0 8D2976A8 */  lw         $t1, %lo(D_1B1FB0_802C76A8)($t1)
    /* 1B2464 802C5CB4 3C05802C */  lui        $a1, %hi(D_1B1FB0_802C76B4)
    /* 1B2468 802C5CB8 24440008 */  addiu      $a0, $v0, 0x8
    /* 1B246C 802C5CBC 00095080 */  sll        $t2, $t1, 2
    /* 1B2470 802C5CC0 00AA2821 */  addu       $a1, $a1, $t2
    /* 1B2474 802C5CC4 8CA576B4 */  lw         $a1, %lo(D_1B1FB0_802C76B4)($a1)
    /* 1B2478 802C5CC8 0C0B1B90 */  jal        func_1B1FB0_802C6E40
    /* 1B247C 802C5CCC 24060086 */   addiu     $a2, $zero, 0x86
    /* 1B2480 802C5CD0 3C0B802C */  lui        $t3, %hi(D_1B1FB0_802C76A4)
    /* 1B2484 802C5CD4 8D6B76A4 */  lw         $t3, %lo(D_1B1FB0_802C76A4)($t3)
    /* 1B2488 802C5CD8 24010002 */  addiu      $at, $zero, 0x2
    /* 1B248C 802C5CDC 00408025 */  or         $s0, $v0, $zero
    /* 1B2490 802C5CE0 1561000A */  bne        $t3, $at, .L1B1FB0_802C5D0C
    /* 1B2494 802C5CE4 00402025 */   or        $a0, $v0, $zero
    /* 1B2498 802C5CE8 3C0C802C */  lui        $t4, %hi(D_1B1FB0_802C76AC)
    /* 1B249C 802C5CEC 8D8C76AC */  lw         $t4, %lo(D_1B1FB0_802C76AC)($t4)
    /* 1B24A0 802C5CF0 3C05802C */  lui        $a1, %hi(D_1B1FB0_802C76B4)
    /* 1B24A4 802C5CF4 2406018A */  addiu      $a2, $zero, 0x18A
    /* 1B24A8 802C5CF8 000C6880 */  sll        $t5, $t4, 2
    /* 1B24AC 802C5CFC 00AD2821 */  addu       $a1, $a1, $t5
    /* 1B24B0 802C5D00 0C0B1B90 */  jal        func_1B1FB0_802C6E40
    /* 1B24B4 802C5D04 8CA576B4 */   lw        $a1, %lo(D_1B1FB0_802C76B4)($a1)
    /* 1B24B8 802C5D08 00408025 */  or         $s0, $v0, $zero
  .L1B1FB0_802C5D0C:
    /* 1B24BC 802C5D0C 3C03800E */  lui        $v1, %hi(gGameState)
    /* 1B24C0 802C5D10 8C63AB24 */  lw         $v1, %lo(gGameState)($v1)
    /* 1B24C4 802C5D14 24010006 */  addiu      $at, $zero, 0x6
    /* 1B24C8 802C5D18 02002025 */  or         $a0, $s0, $zero
    /* 1B24CC 802C5D1C 1461000C */  bne        $v1, $at, .L1B1FB0_802C5D50
    /* 1B24D0 802C5D20 24050040 */   addiu     $a1, $zero, 0x40
    /* 1B24D4 802C5D24 3C0F802C */  lui        $t7, %hi(D_1B1FB0_802C76F0)
    /* 1B24D8 802C5D28 8DEF76F0 */  lw         $t7, %lo(D_1B1FB0_802C76F0)($t7)
    /* 1B24DC 802C5D2C 240E01B0 */  addiu      $t6, $zero, 0x1B0
    /* 1B24E0 802C5D30 AFAE0010 */  sw         $t6, 0x10($sp)
    /* 1B24E4 802C5D34 24060032 */  addiu      $a2, $zero, 0x32
    /* 1B24E8 802C5D38 24070240 */  addiu      $a3, $zero, 0x240
    /* 1B24EC 802C5D3C 0C0B1D5E */  jal        func_1B1FB0_802C7578
    /* 1B24F0 802C5D40 AFAF0014 */   sw        $t7, 0x14($sp)
    /* 1B24F4 802C5D44 3C03800E */  lui        $v1, %hi(gGameState)
    /* 1B24F8 802C5D48 8C63AB24 */  lw         $v1, %lo(gGameState)($v1)
    /* 1B24FC 802C5D4C 00408025 */  or         $s0, $v0, $zero
  .L1B1FB0_802C5D50:
    /* 1B2500 802C5D50 3C04802C */  lui        $a0, %hi(D_1B1FB0_802C76F0)
    /* 1B2504 802C5D54 24010005 */  addiu      $at, $zero, 0x5
    /* 1B2508 802C5D58 14610005 */  bne        $v1, $at, .L1B1FB0_802C5D70
    /* 1B250C 802C5D5C 248476F0 */   addiu     $a0, $a0, %lo(D_1B1FB0_802C76F0)
    /* 1B2510 802C5D60 0C0B177D */  jal        func_1B1FB0_802C5DF4
    /* 1B2514 802C5D64 00000000 */   nop
    /* 1B2518 802C5D68 1000001D */  b          .L1B1FB0_802C5DE0
    /* 1B251C 802C5D6C 02001025 */   or        $v0, $s0, $zero
  .L1B1FB0_802C5D70:
    /* 1B2520 802C5D70 3C05802C */  lui        $a1, %hi(D_1B1FB0_802C76F4)
    /* 1B2524 802C5D74 24A576F4 */  addiu      $a1, $a1, %lo(D_1B1FB0_802C76F4)
    /* 1B2528 802C5D78 8CA30000 */  lw         $v1, 0x0($a1)
    /* 1B252C 802C5D7C 2401000A */  addiu      $at, $zero, 0xA
    /* 1B2530 802C5D80 0003C200 */  sll        $t8, $v1, 8
    /* 1B2534 802C5D84 0303C023 */  subu       $t8, $t8, $v1
    /* 1B2538 802C5D88 0301001A */  div        $zero, $t8, $at
    /* 1B253C 802C5D8C 00001012 */  mflo       $v0
    /* 1B2540 802C5D90 2C410100 */  sltiu      $at, $v0, 0x100
    /* 1B2544 802C5D94 14200003 */  bnez       $at, .L1B1FB0_802C5DA4
    /* 1B2548 802C5D98 AC820000 */   sw        $v0, 0x0($a0)
    /* 1B254C 802C5D9C 240200FF */  addiu      $v0, $zero, 0xFF
    /* 1B2550 802C5DA0 AC820000 */  sw         $v0, 0x0($a0)
  .L1B1FB0_802C5DA4:
    /* 1B2554 802C5DA4 24690001 */  addiu      $t1, $v1, 0x1
    /* 1B2558 802C5DA8 240100FF */  addiu      $at, $zero, 0xFF
    /* 1B255C 802C5DAC 14410005 */  bne        $v0, $at, .L1B1FB0_802C5DC4
    /* 1B2560 802C5DB0 ACA90000 */   sw        $t1, 0x0($a1)
    /* 1B2564 802C5DB4 0C031AB4 */  jal        osViBlack
    /* 1B2568 802C5DB8 24040001 */   addiu     $a0, $zero, 0x1
    /* 1B256C 802C5DBC 3C05802C */  lui        $a1, %hi(D_1B1FB0_802C76F4)
    /* 1B2570 802C5DC0 24A576F4 */  addiu      $a1, $a1, %lo(D_1B1FB0_802C76F4)
  .L1B1FB0_802C5DC4:
    /* 1B2574 802C5DC4 8CAA0000 */  lw         $t2, 0x0($a1)
    /* 1B2578 802C5DC8 2941000E */  slti       $at, $t2, 0xE
    /* 1B257C 802C5DCC 54200004 */  bnel       $at, $zero, .L1B1FB0_802C5DE0
    /* 1B2580 802C5DD0 02001025 */   or        $v0, $s0, $zero
    /* 1B2584 802C5DD4 0C07AC60 */  jal        func_801EB180
    /* 1B2588 802C5DD8 00000000 */   nop
    /* 1B258C 802C5DDC 02001025 */  or         $v0, $s0, $zero
  .L1B1FB0_802C5DE0:
    /* 1B2590 802C5DE0 8FBF0024 */  lw         $ra, 0x24($sp)
  .L1B1FB0_802C5DE4:
    /* 1B2594 802C5DE4 8FB00020 */  lw         $s0, 0x20($sp)
    /* 1B2598 802C5DE8 27BD0028 */  addiu      $sp, $sp, 0x28
    /* 1B259C 802C5DEC 03E00008 */  jr         $ra
    /* 1B25A0 802C5DF0 00000000 */   nop
endlabel func_1B1FB0_802C5BA4
.size func_1B1FB0_802C5BA4, . - func_1B1FB0_802C5BA4

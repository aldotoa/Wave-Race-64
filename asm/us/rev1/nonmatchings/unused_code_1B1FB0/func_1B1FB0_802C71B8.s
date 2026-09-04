nonmatching func_1B1FB0_802C71B8, 0x14C

glabel func_1B1FB0_802C71B8
    /* 1B3968 802C71B8 30A200FF */  andi       $v0, $a1, 0xFF
    /* 1B396C 802C71BC 28410010 */  slti       $at, $v0, 0x10
    /* 1B3970 802C71C0 10200003 */  beqz       $at, .L1B1FB0_802C71D0
    /* 1B3974 802C71C4 AFA50004 */   sw        $a1, 0x4($sp)
    /* 1B3978 802C71C8 03E00008 */  jr         $ra
    /* 1B397C 802C71CC 00801025 */   or        $v0, $a0, $zero
  .L1B1FB0_802C71D0:
    /* 1B3980 802C71D0 28410042 */  slti       $at, $v0, 0x42
    /* 1B3984 802C71D4 14200002 */  bnez       $at, .L1B1FB0_802C71E0
    /* 1B3988 802C71D8 24880008 */   addiu     $t0, $a0, 0x8
    /* 1B398C 802C71DC 2402003B */  addiu      $v0, $zero, 0x3B
  .L1B1FB0_802C71E0:
    /* 1B3990 802C71E0 2445FFF0 */  addiu      $a1, $v0, -0x10
    /* 1B3994 802C71E4 30AF00FF */  andi       $t7, $a1, 0xFF
    /* 1B3998 802C71E8 3C0B0800 */  lui        $t3, %hi(D_8000008)
    /* 1B399C 802C71EC 256B0008 */  addiu      $t3, $t3, %lo(D_8000008)
    /* 1B39A0 802C71F0 000FCA00 */  sll        $t9, $t7, 8
    /* 1B39A4 802C71F4 032B6021 */  addu       $t4, $t9, $t3
    /* 1B39A8 802C71F8 3C18FD70 */  lui        $t8, (0xFD700000 >> 16)
    /* 1B39AC 802C71FC AC980000 */  sw         $t8, 0x0($a0)
    /* 1B39B0 802C7200 AC8C0004 */  sw         $t4, 0x4($a0)
    /* 1B39B4 802C7204 3C0E0708 */  lui        $t6, (0x7080200 >> 16)
    /* 1B39B8 802C7208 35CE0200 */  ori        $t6, $t6, (0x7080200 & 0xFFFF)
    /* 1B39BC 802C720C 25090008 */  addiu      $t1, $t0, 0x8
    /* 1B39C0 802C7210 3C0DF570 */  lui        $t5, (0xF5700000 >> 16)
    /* 1B39C4 802C7214 AD0D0000 */  sw         $t5, 0x0($t0)
    /* 1B39C8 802C7218 AD0E0004 */  sw         $t6, 0x4($t0)
    /* 1B39CC 802C721C 252A0008 */  addiu      $t2, $t1, 0x8
    /* 1B39D0 802C7220 3C0FE600 */  lui        $t7, (0xE6000000 >> 16)
    /* 1B39D4 802C7224 AD2F0000 */  sw         $t7, 0x0($t1)
    /* 1B39D8 802C7228 AD200004 */  sw         $zero, 0x4($t1)
    /* 1B39DC 802C722C 3C190707 */  lui        $t9, (0x707F400 >> 16)
    /* 1B39E0 802C7230 3739F400 */  ori        $t9, $t9, (0x707F400 & 0xFFFF)
    /* 1B39E4 802C7234 3C18F300 */  lui        $t8, (0xF3000000 >> 16)
    /* 1B39E8 802C7238 AD580000 */  sw         $t8, 0x0($t2)
    /* 1B39EC 802C723C AD590004 */  sw         $t9, 0x4($t2)
    /* 1B39F0 802C7240 25420008 */  addiu      $v0, $t2, 0x8
    /* 1B39F4 802C7244 3C0BE700 */  lui        $t3, (0xE7000000 >> 16)
    /* 1B39F8 802C7248 AC4B0000 */  sw         $t3, 0x0($v0)
    /* 1B39FC 802C724C 24430008 */  addiu      $v1, $v0, 0x8
    /* 1B3A00 802C7250 AC400004 */  sw         $zero, 0x4($v0)
    /* 1B3A04 802C7254 3C0D0008 */  lui        $t5, (0x80200 >> 16)
    /* 1B3A08 802C7258 3C0CF568 */  lui        $t4, (0xF5680400 >> 16)
    /* 1B3A0C 802C725C 358C0400 */  ori        $t4, $t4, (0xF5680400 & 0xFFFF)
    /* 1B3A10 802C7260 35AD0200 */  ori        $t5, $t5, (0x80200 & 0xFFFF)
    /* 1B3A14 802C7264 AC6D0004 */  sw         $t5, 0x4($v1)
    /* 1B3A18 802C7268 AC6C0000 */  sw         $t4, 0x0($v1)
    /* 1B3A1C 802C726C 24640008 */  addiu      $a0, $v1, 0x8
    /* 1B3A20 802C7270 3C0F0003 */  lui        $t7, (0x3C03C >> 16)
    /* 1B3A24 802C7274 3C0EF200 */  lui        $t6, (0xF2000000 >> 16)
    /* 1B3A28 802C7278 24D80010 */  addiu      $t8, $a2, 0x10
    /* 1B3A2C 802C727C AC8E0000 */  sw         $t6, 0x0($a0)
    /* 1B3A30 802C7280 35EFC03C */  ori        $t7, $t7, (0x3C03C & 0xFFFF)
    /* 1B3A34 802C7284 0018C880 */  sll        $t9, $t8, 2
    /* 1B3A38 802C7288 AC8F0004 */  sw         $t7, 0x4($a0)
    /* 1B3A3C 802C728C 332B0FFF */  andi       $t3, $t9, 0xFFF
    /* 1B3A40 802C7290 24EE0010 */  addiu      $t6, $a3, 0x10
    /* 1B3A44 802C7294 000E7880 */  sll        $t7, $t6, 2
    /* 1B3A48 802C7298 000B6300 */  sll        $t4, $t3, 12
    /* 1B3A4C 802C729C 3C01E400 */  lui        $at, (0xE4000000 >> 16)
    /* 1B3A50 802C72A0 01816825 */  or         $t5, $t4, $at
    /* 1B3A54 802C72A4 31F80FFF */  andi       $t8, $t7, 0xFFF
    /* 1B3A58 802C72A8 01B8C825 */  or         $t9, $t5, $t8
    /* 1B3A5C 802C72AC 00065880 */  sll        $t3, $a2, 2
    /* 1B3A60 802C72B0 24880008 */  addiu      $t0, $a0, 0x8
    /* 1B3A64 802C72B4 316C0FFF */  andi       $t4, $t3, 0xFFF
    /* 1B3A68 802C72B8 00077880 */  sll        $t7, $a3, 2
    /* 1B3A6C 802C72BC 31ED0FFF */  andi       $t5, $t7, 0xFFF
    /* 1B3A70 802C72C0 000C7300 */  sll        $t6, $t4, 12
    /* 1B3A74 802C72C4 01CDC025 */  or         $t8, $t6, $t5
    /* 1B3A78 802C72C8 25030008 */  addiu      $v1, $t0, 0x8
    /* 1B3A7C 802C72CC AD190000 */  sw         $t9, 0x0($t0)
    /* 1B3A80 802C72D0 AD180004 */  sw         $t8, 0x4($t0)
    /* 1B3A84 802C72D4 3C19B300 */  lui        $t9, (0xB3000000 >> 16)
    /* 1B3A88 802C72D8 24650008 */  addiu      $a1, $v1, 0x8
    /* 1B3A8C 802C72DC AC790000 */  sw         $t9, 0x0($v1)
    /* 1B3A90 802C72E0 AC600004 */  sw         $zero, 0x4($v1)
    /* 1B3A94 802C72E4 3C0C0400 */  lui        $t4, (0x4000400 >> 16)
    /* 1B3A98 802C72E8 358C0400 */  ori        $t4, $t4, (0x4000400 & 0xFFFF)
    /* 1B3A9C 802C72EC 3C0BB200 */  lui        $t3, (0xB2000000 >> 16)
    /* 1B3AA0 802C72F0 ACAB0000 */  sw         $t3, 0x0($a1)
    /* 1B3AA4 802C72F4 ACAC0004 */  sw         $t4, 0x4($a1)
    /* 1B3AA8 802C72F8 24A20008 */  addiu      $v0, $a1, 0x8
    /* 1B3AAC 802C72FC 03E00008 */  jr         $ra
    /* 1B3AB0 802C7300 00000000 */   nop
endlabel func_1B1FB0_802C71B8
.size func_1B1FB0_802C71B8, . - func_1B1FB0_802C71B8

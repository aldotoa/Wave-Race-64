nonmatching func_1B1FB0_802C5DF4, 0x4F0

glabel func_1B1FB0_802C5DF4
    /* 1B25A4 802C5DF4 3C09802C */  lui        $t1, %hi(D_1B1FB0_802C76A4)
    /* 1B25A8 802C5DF8 252976A4 */  addiu      $t1, $t1, %lo(D_1B1FB0_802C76A4)
    /* 1B25AC 802C5DFC 8D2E0000 */  lw         $t6, 0x0($t1)
    /* 1B25B0 802C5E00 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* 1B25B4 802C5E04 240A0004 */  addiu      $t2, $zero, 0x4
    /* 1B25B8 802C5E08 154E004B */  bne        $t2, $t6, .L1B1FB0_802C5F38
    /* 1B25BC 802C5E0C AFBF001C */   sw        $ra, 0x1C($sp)
    /* 1B25C0 802C5E10 3C0B802C */  lui        $t3, %hi(D_802C7724)
    /* 1B25C4 802C5E14 256B7724 */  addiu      $t3, $t3, %lo(D_802C7724)
    /* 1B25C8 802C5E18 8D6F0000 */  lw         $t7, 0x0($t3)
    /* 1B25CC 802C5E1C 3C01802C */  lui        $at, %hi(D_802C771C)
    /* 1B25D0 802C5E20 3C18802C */  lui        $t8, %hi(D_802C7720)
    /* 1B25D4 802C5E24 15E00004 */  bnez       $t7, .L1B1FB0_802C5E38
    /* 1B25D8 802C5E28 3C0C801D */   lui       $t4, %hi(D_801CB418)
    /* 1B25DC 802C5E2C 24060001 */  addiu      $a2, $zero, 0x1
    /* 1B25E0 802C5E30 10000041 */  b          .L1B1FB0_802C5F38
    /* 1B25E4 802C5E34 AD660000 */   sw        $a2, 0x0($t3)
  .L1B1FB0_802C5E38:
    /* 1B25E8 802C5E38 8F187720 */  lw         $t8, %lo(D_802C7720)($t8)
    /* 1B25EC 802C5E3C 258CB418 */  addiu      $t4, $t4, %lo(D_801CB418)
    /* 1B25F0 802C5E40 AC20771C */  sw         $zero, %lo(D_802C771C)($at)
    /* 1B25F4 802C5E44 0018C940 */  sll        $t9, $t8, 5
    /* 1B25F8 802C5E48 032C4021 */  addu       $t0, $t9, $t4
    /* 1B25FC 802C5E4C 95050008 */  lhu        $a1, 0x8($t0)
    /* 1B2600 802C5E50 8D060004 */  lw         $a2, 0x4($t0)
    /* 1B2604 802C5E54 250D000A */  addiu      $t5, $t0, 0xA
    /* 1B2608 802C5E58 3C04801D */  lui        $a0, %hi(D_801CB658)
    /* 1B260C 802C5E5C 2484B658 */  addiu      $a0, $a0, %lo(D_801CB658)
    /* 1B2610 802C5E60 AFAD0010 */  sw         $t5, 0x10($sp)
    /* 1B2614 802C5E64 AFA80020 */  sw         $t0, 0x20($sp)
    /* 1B2618 802C5E68 0C03262C */  jal        osPfsDeleteFile
    /* 1B261C 802C5E6C 2507000E */   addiu     $a3, $t0, 0xE
    /* 1B2620 802C5E70 3C04802C */  lui        $a0, %hi(D_802C771C)
    /* 1B2624 802C5E74 2484771C */  addiu      $a0, $a0, %lo(D_802C771C)
    /* 1B2628 802C5E78 3C09802C */  lui        $t1, %hi(D_1B1FB0_802C76A4)
    /* 1B262C 802C5E7C 252976A4 */  addiu      $t1, $t1, %lo(D_1B1FB0_802C76A4)
    /* 1B2630 802C5E80 AC820000 */  sw         $v0, 0x0($a0)
    /* 1B2634 802C5E84 8FA80020 */  lw         $t0, 0x20($sp)
    /* 1B2638 802C5E88 1040000C */  beqz       $v0, .L1B1FB0_802C5EBC
    /* 1B263C 802C5E8C 240A0004 */   addiu     $t2, $zero, 0x4
    /* 1B2640 802C5E90 24060001 */  addiu      $a2, $zero, 0x1
    /* 1B2644 802C5E94 1046001E */  beq        $v0, $a2, .L1B1FB0_802C5F10
    /* 1B2648 802C5E98 24070002 */   addiu     $a3, $zero, 0x2
    /* 1B264C 802C5E9C 10470022 */  beq        $v0, $a3, .L1B1FB0_802C5F28
    /* 1B2650 802C5EA0 3C04802C */   lui       $a0, %hi(D_1B1FB0_802C7660)
    /* 1B2654 802C5EA4 3C04802C */  lui        $a0, %hi(D_1B1FB0_802C7660)
    /* 1B2658 802C5EA8 24847660 */  addiu      $a0, $a0, %lo(D_1B1FB0_802C7660)
    /* 1B265C 802C5EAC 24050003 */  addiu      $a1, $zero, 0x3
    /* 1B2660 802C5EB0 AD250000 */  sw         $a1, 0x0($t1)
    /* 1B2664 802C5EB4 10000020 */  b          .L1B1FB0_802C5F38
    /* 1B2668 802C5EB8 AC870000 */   sw        $a3, 0x0($a0)
  .L1B1FB0_802C5EBC:
    /* 1B266C 802C5EBC 3C0F802C */  lui        $t7, %hi(D_802C7720)
    /* 1B2670 802C5EC0 8DEF7720 */  lw         $t7, %lo(D_802C7720)($t7)
    /* 1B2674 802C5EC4 3C01801D */  lui        $at, %hi(D_801CB618)
    /* 1B2678 802C5EC8 240EFFFF */  addiu      $t6, $zero, -0x1
    /* 1B267C 802C5ECC 000FC080 */  sll        $t8, $t7, 2
    /* 1B2680 802C5ED0 00380821 */  addu       $at, $at, $t8
    /* 1B2684 802C5ED4 AC2EB618 */  sw         $t6, %lo(D_801CB618)($at)
    /* 1B2688 802C5ED8 8D0C0000 */  lw         $t4, 0x0($t0)
    /* 1B268C 802C5EDC 3C02801D */  lui        $v0, %hi(D_801CB410)
    /* 1B2690 802C5EE0 2442B410 */  addiu      $v0, $v0, %lo(D_801CB410)
    /* 1B2694 802C5EE4 8C590000 */  lw         $t9, 0x0($v0)
    /* 1B2698 802C5EE8 258D00FF */  addiu      $t5, $t4, 0xFF
    /* 1B269C 802C5EEC 000D7A02 */  srl        $t7, $t5, 8
    /* 1B26A0 802C5EF0 3C04802C */  lui        $a0, %hi(D_1B1FB0_802C7660)
    /* 1B26A4 802C5EF4 31EE00FF */  andi       $t6, $t7, 0xFF
    /* 1B26A8 802C5EF8 24847660 */  addiu      $a0, $a0, %lo(D_1B1FB0_802C7660)
    /* 1B26AC 802C5EFC 032EC021 */  addu       $t8, $t9, $t6
    /* 1B26B0 802C5F00 AC580000 */  sw         $t8, 0x0($v0)
    /* 1B26B4 802C5F04 AD200000 */  sw         $zero, 0x0($t1)
    /* 1B26B8 802C5F08 1000000B */  b          .L1B1FB0_802C5F38
    /* 1B26BC 802C5F0C AC800000 */   sw        $zero, 0x0($a0)
  .L1B1FB0_802C5F10:
    /* 1B26C0 802C5F10 3C04802C */  lui        $a0, %hi(D_1B1FB0_802C7660)
    /* 1B26C4 802C5F14 24847660 */  addiu      $a0, $a0, %lo(D_1B1FB0_802C7660)
    /* 1B26C8 802C5F18 24050003 */  addiu      $a1, $zero, 0x3
    /* 1B26CC 802C5F1C AD250000 */  sw         $a1, 0x0($t1)
    /* 1B26D0 802C5F20 10000005 */  b          .L1B1FB0_802C5F38
    /* 1B26D4 802C5F24 AC850000 */   sw        $a1, 0x0($a0)
  .L1B1FB0_802C5F28:
    /* 1B26D8 802C5F28 24847660 */  addiu      $a0, $a0, %lo(D_1B1FB0_802C7660)
    /* 1B26DC 802C5F2C 24050003 */  addiu      $a1, $zero, 0x3
    /* 1B26E0 802C5F30 AD250000 */  sw         $a1, 0x0($t1)
    /* 1B26E4 802C5F34 AC8A0000 */  sw         $t2, 0x0($a0)
  .L1B1FB0_802C5F38:
    /* 1B26E8 802C5F38 3C02801D */  lui        $v0, %hi(D_801CE65A)
    /* 1B26EC 802C5F3C 9442E65A */  lhu        $v0, %lo(D_801CE65A)($v0)
    /* 1B26F0 802C5F40 3C04802C */  lui        $a0, %hi(D_1B1FB0_802C7660)
    /* 1B26F4 802C5F44 3C0B802C */  lui        $t3, %hi(D_802C7724)
    /* 1B26F8 802C5F48 304CB000 */  andi       $t4, $v0, 0xB000
    /* 1B26FC 802C5F4C 256B7724 */  addiu      $t3, $t3, %lo(D_802C7724)
    /* 1B2700 802C5F50 24847660 */  addiu      $a0, $a0, %lo(D_1B1FB0_802C7660)
    /* 1B2704 802C5F54 24050003 */  addiu      $a1, $zero, 0x3
    /* 1B2708 802C5F58 24060001 */  addiu      $a2, $zero, 0x1
    /* 1B270C 802C5F5C 11800041 */  beqz       $t4, .L1B1FB0_802C6064
    /* 1B2710 802C5F60 24070002 */   addiu     $a3, $zero, 0x2
    /* 1B2714 802C5F64 8D230000 */  lw         $v1, 0x0($t1)
    /* 1B2718 802C5F68 3C02802C */  lui        $v0, %hi(D_1B1FB0_802C76A8)
    /* 1B271C 802C5F6C 244276A8 */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76A8)
    /* 1B2720 802C5F70 5060000A */  beql       $v1, $zero, .L1B1FB0_802C5F9C
    /* 1B2724 802C5F74 8C4D0000 */   lw        $t5, 0x0($v0)
    /* 1B2728 802C5F78 10660013 */  beq        $v1, $a2, .L1B1FB0_802C5FC8
    /* 1B272C 802C5F7C 3C02802C */   lui       $v0, %hi(D_1B1FB0_802C76B0)
    /* 1B2730 802C5F80 10670027 */  beq        $v1, $a3, .L1B1FB0_802C6020
    /* 1B2734 802C5F84 3C02802C */   lui       $v0, %hi(D_1B1FB0_802C76AC)
    /* 1B2738 802C5F88 50650030 */  beql       $v1, $a1, .L1B1FB0_802C604C
    /* 1B273C 802C5F8C AD200000 */   sw        $zero, 0x0($t1)
    /* 1B2740 802C5F90 10000030 */  b          .L1B1FB0_802C6054
    /* 1B2744 802C5F94 24040011 */   addiu     $a0, $zero, 0x11
    /* 1B2748 802C5F98 8C4D0000 */  lw         $t5, 0x0($v0)
  .L1B1FB0_802C5F9C:
    /* 1B274C 802C5F9C 3C02802C */  lui        $v0, %hi(D_1B1FB0_802C76B0)
    /* 1B2750 802C5FA0 244276B0 */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76B0)
    /* 1B2754 802C5FA4 15A00004 */  bnez       $t5, .L1B1FB0_802C5FB8
    /* 1B2758 802C5FA8 00000000 */   nop
    /* 1B275C 802C5FAC AD260000 */  sw         $a2, 0x0($t1)
    /* 1B2760 802C5FB0 10000027 */  b          .L1B1FB0_802C6050
    /* 1B2764 802C5FB4 AC400000 */   sw        $zero, 0x0($v0)
  .L1B1FB0_802C5FB8:
    /* 1B2768 802C5FB8 0C0B1D44 */  jal        func_1B1FB0_802C7510
    /* 1B276C 802C5FBC 00000000 */   nop
    /* 1B2770 802C5FC0 10000024 */  b          .L1B1FB0_802C6054
    /* 1B2774 802C5FC4 24040011 */   addiu     $a0, $zero, 0x11
  .L1B1FB0_802C5FC8:
    /* 1B2778 802C5FC8 244276B0 */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76B0)
    /* 1B277C 802C5FCC 8C4F0000 */  lw         $t7, 0x0($v0)
    /* 1B2780 802C5FD0 3C0E802C */  lui        $t6, %hi(D_1B1FB0_802C76CC)
    /* 1B2784 802C5FD4 3C03802C */  lui        $v1, %hi(D_802C7720)
    /* 1B2788 802C5FD8 000FC880 */  sll        $t9, $t7, 2
    /* 1B278C 802C5FDC 01D97021 */  addu       $t6, $t6, $t9
    /* 1B2790 802C5FE0 8DCE76CC */  lw         $t6, %lo(D_1B1FB0_802C76CC)($t6)
    /* 1B2794 802C5FE4 24637720 */  addiu      $v1, $v1, %lo(D_802C7720)
    /* 1B2798 802C5FE8 3C0F801D */  lui        $t7, %hi(D_801CB618)
    /* 1B279C 802C5FEC 25D8FFFF */  addiu      $t8, $t6, -0x1
    /* 1B27A0 802C5FF0 00186880 */  sll        $t5, $t8, 2
    /* 1B27A4 802C5FF4 AC780000 */  sw         $t8, 0x0($v1)
    /* 1B27A8 802C5FF8 01ED7821 */  addu       $t7, $t7, $t5
    /* 1B27AC 802C5FFC 8DEFB618 */  lw         $t7, %lo(D_801CB618)($t7)
    /* 1B27B0 802C6000 3C02802C */  lui        $v0, %hi(D_1B1FB0_802C76AC)
    /* 1B27B4 802C6004 244276AC */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76AC)
    /* 1B27B8 802C6008 55E00012 */  bnel       $t7, $zero, .L1B1FB0_802C6054
    /* 1B27BC 802C600C 24040011 */   addiu     $a0, $zero, 0x11
    /* 1B27C0 802C6010 AD270000 */  sw         $a3, 0x0($t1)
    /* 1B27C4 802C6014 AC460000 */  sw         $a2, 0x0($v0)
    /* 1B27C8 802C6018 1000000D */  b          .L1B1FB0_802C6050
    /* 1B27CC 802C601C AC860000 */   sw        $a2, 0x0($a0)
  .L1B1FB0_802C6020:
    /* 1B27D0 802C6020 244276AC */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76AC)
    /* 1B27D4 802C6024 8C590000 */  lw         $t9, 0x0($v0)
    /* 1B27D8 802C6028 AD260000 */  sw         $a2, 0x0($t1)
    /* 1B27DC 802C602C AC800000 */  sw         $zero, 0x0($a0)
    /* 1B27E0 802C6030 17200007 */  bnez       $t9, .L1B1FB0_802C6050
    /* 1B27E4 802C6034 240E0005 */   addiu     $t6, $zero, 0x5
    /* 1B27E8 802C6038 AD2A0000 */  sw         $t2, 0x0($t1)
    /* 1B27EC 802C603C AC8E0000 */  sw         $t6, 0x0($a0)
    /* 1B27F0 802C6040 10000003 */  b          .L1B1FB0_802C6050
    /* 1B27F4 802C6044 AD600000 */   sw        $zero, 0x0($t3)
    /* 1B27F8 802C6048 AD200000 */  sw         $zero, 0x0($t1)
  .L1B1FB0_802C604C:
    /* 1B27FC 802C604C AC800000 */  sw         $zero, 0x0($a0)
  .L1B1FB0_802C6050:
    /* 1B2800 802C6050 24040011 */  addiu      $a0, $zero, 0x11
  .L1B1FB0_802C6054:
    /* 1B2804 802C6054 0C030DFD */  jal        AudioGeneral_PlaySound
    /* 1B2808 802C6058 00002825 */   or        $a1, $zero, $zero
    /* 1B280C 802C605C 1000009E */  b          .L1B1FB0_802C62D8
    /* 1B2810 802C6060 8FBF001C */   lw        $ra, 0x1C($sp)
  .L1B1FB0_802C6064:
    /* 1B2814 802C6064 30584000 */  andi       $t8, $v0, 0x4000
    /* 1B2818 802C6068 13000016 */  beqz       $t8, .L1B1FB0_802C60C4
    /* 1B281C 802C606C 304D0200 */   andi      $t5, $v0, 0x200
    /* 1B2820 802C6070 8D230000 */  lw         $v1, 0x0($t1)
    /* 1B2824 802C6074 3C0C802C */  lui        $t4, %hi(D_1B1FB0_802C76E8)
    /* 1B2828 802C6078 00002825 */  or         $a1, $zero, $zero
    /* 1B282C 802C607C 10660005 */  beq        $v1, $a2, .L1B1FB0_802C6094
    /* 1B2830 802C6080 00000000 */   nop
    /* 1B2834 802C6084 5067000A */  beql       $v1, $a3, .L1B1FB0_802C60B0
    /* 1B2838 802C6088 AD260000 */   sw        $a2, 0x0($t1)
    /* 1B283C 802C608C 10000009 */  b          .L1B1FB0_802C60B4
    /* 1B2840 802C6090 00000000 */   nop
  .L1B1FB0_802C6094:
    /* 1B2844 802C6094 8D8C76E8 */  lw         $t4, %lo(D_1B1FB0_802C76E8)($t4)
    /* 1B2848 802C6098 15800006 */  bnez       $t4, .L1B1FB0_802C60B4
    /* 1B284C 802C609C 00000000 */   nop
    /* 1B2850 802C60A0 AD200000 */  sw         $zero, 0x0($t1)
    /* 1B2854 802C60A4 10000003 */  b          .L1B1FB0_802C60B4
    /* 1B2858 802C60A8 AC800000 */   sw        $zero, 0x0($a0)
    /* 1B285C 802C60AC AD260000 */  sw         $a2, 0x0($t1)
  .L1B1FB0_802C60B0:
    /* 1B2860 802C60B0 AC800000 */  sw         $zero, 0x0($a0)
  .L1B1FB0_802C60B4:
    /* 1B2864 802C60B4 0C030DFD */  jal        AudioGeneral_PlaySound
    /* 1B2868 802C60B8 24040016 */   addiu     $a0, $zero, 0x16
    /* 1B286C 802C60BC 10000086 */  b          .L1B1FB0_802C62D8
    /* 1B2870 802C60C0 8FBF001C */   lw        $ra, 0x1C($sp)
  .L1B1FB0_802C60C4:
    /* 1B2874 802C60C4 51A0001D */  beql       $t5, $zero, .L1B1FB0_802C613C
    /* 1B2878 802C60C8 304D0100 */   andi      $t5, $v0, 0x100
    /* 1B287C 802C60CC 8D230000 */  lw         $v1, 0x0($t1)
    /* 1B2880 802C60D0 3C02802C */  lui        $v0, %hi(D_1B1FB0_802C76A8)
    /* 1B2884 802C60D4 244276A8 */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76A8)
    /* 1B2888 802C60D8 10600005 */  beqz       $v1, .L1B1FB0_802C60F0
    /* 1B288C 802C60DC 24040010 */   addiu     $a0, $zero, 0x10
    /* 1B2890 802C60E0 1067000C */  beq        $v1, $a3, .L1B1FB0_802C6114
    /* 1B2894 802C60E4 3C02802C */   lui       $v0, %hi(D_1B1FB0_802C76AC)
    /* 1B2898 802C60E8 1000007B */  b          .L1B1FB0_802C62D8
    /* 1B289C 802C60EC 8FBF001C */   lw        $ra, 0x1C($sp)
  .L1B1FB0_802C60F0:
    /* 1B28A0 802C60F0 8C4F0000 */  lw         $t7, 0x0($v0)
    /* 1B28A4 802C60F4 25F90001 */  addiu      $t9, $t7, 0x1
    /* 1B28A8 802C60F8 14F90002 */  bne        $a3, $t9, .L1B1FB0_802C6104
    /* 1B28AC 802C60FC AC590000 */   sw        $t9, 0x0($v0)
    /* 1B28B0 802C6100 AC400000 */  sw         $zero, 0x0($v0)
  .L1B1FB0_802C6104:
    /* 1B28B4 802C6104 0C030DFD */  jal        AudioGeneral_PlaySound
    /* 1B28B8 802C6108 00002825 */   or        $a1, $zero, $zero
    /* 1B28BC 802C610C 10000072 */  b          .L1B1FB0_802C62D8
    /* 1B28C0 802C6110 8FBF001C */   lw        $ra, 0x1C($sp)
  .L1B1FB0_802C6114:
    /* 1B28C4 802C6114 244276AC */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76AC)
    /* 1B28C8 802C6118 8C580000 */  lw         $t8, 0x0($v0)
    /* 1B28CC 802C611C 24040010 */  addiu      $a0, $zero, 0x10
    /* 1B28D0 802C6120 00002825 */  or         $a1, $zero, $zero
    /* 1B28D4 802C6124 3B0C0001 */  xori       $t4, $t8, 0x1
    /* 1B28D8 802C6128 0C030DFD */  jal        AudioGeneral_PlaySound
    /* 1B28DC 802C612C AC4C0000 */   sw        $t4, 0x0($v0)
    /* 1B28E0 802C6130 10000069 */  b          .L1B1FB0_802C62D8
    /* 1B28E4 802C6134 8FBF001C */   lw        $ra, 0x1C($sp)
    /* 1B28E8 802C6138 304D0100 */  andi       $t5, $v0, 0x100
  .L1B1FB0_802C613C:
    /* 1B28EC 802C613C 51A0001D */  beql       $t5, $zero, .L1B1FB0_802C61B4
    /* 1B28F0 802C6140 304D0800 */   andi      $t5, $v0, 0x800
    /* 1B28F4 802C6144 8D230000 */  lw         $v1, 0x0($t1)
    /* 1B28F8 802C6148 3C02802C */  lui        $v0, %hi(D_1B1FB0_802C76A8)
    /* 1B28FC 802C614C 244276A8 */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76A8)
    /* 1B2900 802C6150 10600005 */  beqz       $v1, .L1B1FB0_802C6168
    /* 1B2904 802C6154 24040010 */   addiu     $a0, $zero, 0x10
    /* 1B2908 802C6158 1067000C */  beq        $v1, $a3, .L1B1FB0_802C618C
    /* 1B290C 802C615C 3C02802C */   lui       $v0, %hi(D_1B1FB0_802C76AC)
    /* 1B2910 802C6160 1000005D */  b          .L1B1FB0_802C62D8
    /* 1B2914 802C6164 8FBF001C */   lw        $ra, 0x1C($sp)
  .L1B1FB0_802C6168:
    /* 1B2918 802C6168 8C4F0000 */  lw         $t7, 0x0($v0)
    /* 1B291C 802C616C 25F9FFFF */  addiu      $t9, $t7, -0x1
    /* 1B2920 802C6170 07210002 */  bgez       $t9, .L1B1FB0_802C617C
    /* 1B2924 802C6174 AC590000 */   sw        $t9, 0x0($v0)
    /* 1B2928 802C6178 AC460000 */  sw         $a2, 0x0($v0)
  .L1B1FB0_802C617C:
    /* 1B292C 802C617C 0C030DFD */  jal        AudioGeneral_PlaySound
    /* 1B2930 802C6180 00002825 */   or        $a1, $zero, $zero
    /* 1B2934 802C6184 10000054 */  b          .L1B1FB0_802C62D8
    /* 1B2938 802C6188 8FBF001C */   lw        $ra, 0x1C($sp)
  .L1B1FB0_802C618C:
    /* 1B293C 802C618C 244276AC */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76AC)
    /* 1B2940 802C6190 8C580000 */  lw         $t8, 0x0($v0)
    /* 1B2944 802C6194 24040010 */  addiu      $a0, $zero, 0x10
    /* 1B2948 802C6198 00002825 */  or         $a1, $zero, $zero
    /* 1B294C 802C619C 3B0C0001 */  xori       $t4, $t8, 0x1
    /* 1B2950 802C61A0 0C030DFD */  jal        AudioGeneral_PlaySound
    /* 1B2954 802C61A4 AC4C0000 */   sw        $t4, 0x0($v0)
    /* 1B2958 802C61A8 1000004B */  b          .L1B1FB0_802C62D8
    /* 1B295C 802C61AC 8FBF001C */   lw        $ra, 0x1C($sp)
    /* 1B2960 802C61B0 304D0800 */  andi       $t5, $v0, 0x800
  .L1B1FB0_802C61B4:
    /* 1B2964 802C61B4 11A00023 */  beqz       $t5, .L1B1FB0_802C6244
    /* 1B2968 802C61B8 304E0400 */   andi      $t6, $v0, 0x400
    /* 1B296C 802C61BC 8D2F0000 */  lw         $t7, 0x0($t1)
    /* 1B2970 802C61C0 3C19802C */  lui        $t9, %hi(D_1B1FB0_802C76E8)
    /* 1B2974 802C61C4 54CF0044 */  bnel       $a2, $t7, .L1B1FB0_802C62D8
    /* 1B2978 802C61C8 8FBF001C */   lw        $ra, 0x1C($sp)
    /* 1B297C 802C61CC 8F3976E8 */  lw         $t9, %lo(D_1B1FB0_802C76E8)($t9)
    /* 1B2980 802C61D0 3C02802C */  lui        $v0, %hi(D_1B1FB0_802C76B0)
    /* 1B2984 802C61D4 244276B0 */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76B0)
    /* 1B2988 802C61D8 5720003F */  bnel       $t9, $zero, .L1B1FB0_802C62D8
    /* 1B298C 802C61DC 8FBF001C */   lw        $ra, 0x1C($sp)
    /* 1B2990 802C61E0 8C4E0000 */  lw         $t6, 0x0($v0)
    /* 1B2994 802C61E4 24040010 */  addiu      $a0, $zero, 0x10
    /* 1B2998 802C61E8 00002825 */  or         $a1, $zero, $zero
    /* 1B299C 802C61EC 25D8FFFF */  addiu      $t8, $t6, -0x1
    /* 1B29A0 802C61F0 0C030DFD */  jal        AudioGeneral_PlaySound
    /* 1B29A4 802C61F4 AC580000 */   sw        $t8, 0x0($v0)
    /* 1B29A8 802C61F8 3C02802C */  lui        $v0, %hi(D_1B1FB0_802C76B0)
    /* 1B29AC 802C61FC 244276B0 */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76B0)
    /* 1B29B0 802C6200 8C4C0000 */  lw         $t4, 0x0($v0)
    /* 1B29B4 802C6204 24060001 */  addiu      $a2, $zero, 0x1
    /* 1B29B8 802C6208 24070002 */  addiu      $a3, $zero, 0x2
    /* 1B29BC 802C620C 05810031 */  bgez       $t4, .L1B1FB0_802C62D4
    /* 1B29C0 802C6210 00007880 */   sll       $t7, $zero, 2
    /* 1B29C4 802C6214 3C19802C */  lui        $t9, %hi(D_1B1FB0_802C76CC)
    /* 1B29C8 802C6218 AC400000 */  sw         $zero, 0x0($v0)
    /* 1B29CC 802C621C 032FC821 */  addu       $t9, $t9, $t7
    /* 1B29D0 802C6220 8F3976CC */  lw         $t9, %lo(D_1B1FB0_802C76CC)($t9)
    /* 1B29D4 802C6224 3C01802C */  lui        $at, %hi(D_1B1FB0_802C76E8)
    /* 1B29D8 802C6228 2404001D */  addiu      $a0, $zero, 0x1D
    /* 1B29DC 802C622C 10D90029 */  beq        $a2, $t9, .L1B1FB0_802C62D4
    /* 1B29E0 802C6230 00002825 */   or        $a1, $zero, $zero
    /* 1B29E4 802C6234 0C030DFD */  jal        AudioGeneral_PlaySound
    /* 1B29E8 802C6238 AC2776E8 */   sw        $a3, %lo(D_1B1FB0_802C76E8)($at)
    /* 1B29EC 802C623C 10000026 */  b          .L1B1FB0_802C62D8
    /* 1B29F0 802C6240 8FBF001C */   lw        $ra, 0x1C($sp)
  .L1B1FB0_802C6244:
    /* 1B29F4 802C6244 51C00024 */  beql       $t6, $zero, .L1B1FB0_802C62D8
    /* 1B29F8 802C6248 8FBF001C */   lw        $ra, 0x1C($sp)
    /* 1B29FC 802C624C 8D380000 */  lw         $t8, 0x0($t1)
    /* 1B2A00 802C6250 3C0C802C */  lui        $t4, %hi(D_1B1FB0_802C76E8)
    /* 1B2A04 802C6254 54D80020 */  bnel       $a2, $t8, .L1B1FB0_802C62D8
    /* 1B2A08 802C6258 8FBF001C */   lw        $ra, 0x1C($sp)
    /* 1B2A0C 802C625C 8D8C76E8 */  lw         $t4, %lo(D_1B1FB0_802C76E8)($t4)
    /* 1B2A10 802C6260 3C02802C */  lui        $v0, %hi(D_1B1FB0_802C76B0)
    /* 1B2A14 802C6264 244276B0 */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76B0)
    /* 1B2A18 802C6268 5580001B */  bnel       $t4, $zero, .L1B1FB0_802C62D8
    /* 1B2A1C 802C626C 8FBF001C */   lw        $ra, 0x1C($sp)
    /* 1B2A20 802C6270 8C4D0000 */  lw         $t5, 0x0($v0)
    /* 1B2A24 802C6274 24040010 */  addiu      $a0, $zero, 0x10
    /* 1B2A28 802C6278 00002825 */  or         $a1, $zero, $zero
    /* 1B2A2C 802C627C 25AF0001 */  addiu      $t7, $t5, 0x1
    /* 1B2A30 802C6280 0C030DFD */  jal        AudioGeneral_PlaySound
    /* 1B2A34 802C6284 AC4F0000 */   sw        $t7, 0x0($v0)
    /* 1B2A38 802C6288 3C02802C */  lui        $v0, %hi(D_1B1FB0_802C76B0)
    /* 1B2A3C 802C628C 244276B0 */  addiu      $v0, $v0, %lo(D_1B1FB0_802C76B0)
    /* 1B2A40 802C6290 8C590000 */  lw         $t9, 0x0($v0)
    /* 1B2A44 802C6294 240A0004 */  addiu      $t2, $zero, 0x4
    /* 1B2A48 802C6298 24060001 */  addiu      $a2, $zero, 0x1
    /* 1B2A4C 802C629C 2B210005 */  slti       $at, $t9, 0x5
    /* 1B2A50 802C62A0 1420000C */  bnez       $at, .L1B1FB0_802C62D4
    /* 1B2A54 802C62A4 000AC080 */   sll       $t8, $t2, 2
    /* 1B2A58 802C62A8 3C0C802C */  lui        $t4, %hi(D_1B1FB0_802C76CC)
    /* 1B2A5C 802C62AC AC4A0000 */  sw         $t2, 0x0($v0)
    /* 1B2A60 802C62B0 01986021 */  addu       $t4, $t4, $t8
    /* 1B2A64 802C62B4 8D8C76CC */  lw         $t4, %lo(D_1B1FB0_802C76CC)($t4)
    /* 1B2A68 802C62B8 24010010 */  addiu      $at, $zero, 0x10
    /* 1B2A6C 802C62BC 2404001D */  addiu      $a0, $zero, 0x1D
    /* 1B2A70 802C62C0 11810004 */  beq        $t4, $at, .L1B1FB0_802C62D4
    /* 1B2A74 802C62C4 00002825 */   or        $a1, $zero, $zero
    /* 1B2A78 802C62C8 3C01802C */  lui        $at, %hi(D_1B1FB0_802C76E8)
    /* 1B2A7C 802C62CC 0C030DFD */  jal        AudioGeneral_PlaySound
    /* 1B2A80 802C62D0 AC2676E8 */   sw        $a2, %lo(D_1B1FB0_802C76E8)($at)
  .L1B1FB0_802C62D4:
    /* 1B2A84 802C62D4 8FBF001C */  lw         $ra, 0x1C($sp)
  .L1B1FB0_802C62D8:
    /* 1B2A88 802C62D8 27BD0028 */  addiu      $sp, $sp, 0x28
    /* 1B2A8C 802C62DC 03E00008 */  jr         $ra
    /* 1B2A90 802C62E0 00000000 */   nop
endlabel func_1B1FB0_802C5DF4
.size func_1B1FB0_802C5DF4, . - func_1B1FB0_802C5DF4

nonmatching func_1B1FB0_802C6E40, 0x1B8

glabel func_1B1FB0_802C6E40
    /* 1B35F0 802C6E40 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* 1B35F4 802C6E44 24AD00C0 */  addiu      $t5, $a1, 0xC0
    /* 1B35F8 802C6E48 000D7080 */  sll        $t6, $t5, 2
    /* 1B35FC 802C6E4C AFB00008 */  sw         $s0, 0x8($sp)
    /* 1B3600 802C6E50 31CF0FFF */  andi       $t7, $t6, 0xFFF
    /* 1B3604 802C6E54 AFBF002C */  sw         $ra, 0x2C($sp)
    /* 1B3608 802C6E58 AFB70024 */  sw         $s7, 0x24($sp)
    /* 1B360C 802C6E5C AFB5001C */  sw         $s5, 0x1C($sp)
    /* 1B3610 802C6E60 AFB20010 */  sw         $s2, 0x10($sp)
    /* 1B3614 802C6E64 AFB1000C */  sw         $s1, 0xC($sp)
    /* 1B3618 802C6E68 00058080 */  sll        $s0, $a1, 2
    /* 1B361C 802C6E6C AFBE0028 */  sw         $fp, 0x28($sp)
    /* 1B3620 802C6E70 AFB60020 */  sw         $s6, 0x20($sp)
    /* 1B3624 802C6E74 AFB40018 */  sw         $s4, 0x18($sp)
    /* 1B3628 802C6E78 AFB30014 */  sw         $s3, 0x14($sp)
    /* 1B362C 802C6E7C 320E0FFF */  andi       $t6, $s0, 0xFFF
    /* 1B3630 802C6E80 3C11FD68 */  lui        $s1, (0xFD6800BF >> 16)
    /* 1B3634 802C6E84 3C120708 */  lui        $s2, (0x7080200 >> 16)
    /* 1B3638 802C6E88 3C15072F */  lui        $s5, (0x72FC028 >> 16)
    /* 1B363C 802C6E8C 3C170008 */  lui        $s7, (0x80200 >> 16)
    /* 1B3640 802C6E90 3C1F002F */  lui        $ra, (0x2FC028 >> 16)
    /* 1B3644 802C6E94 000FC300 */  sll        $t8, $t7, 12
    /* 1B3648 802C6E98 3C080801 */  lui        $t0, %hi(D_8008510)
    /* 1B364C 802C6E9C 3C01E400 */  lui        $at, (0xE4000000 >> 16)
    /* 1B3650 802C6EA0 3C0CF568 */  lui        $t4, (0xF5683000 >> 16)
    /* 1B3654 802C6EA4 358C3000 */  ori        $t4, $t4, (0xF5683000 & 0xFFFF)
    /* 1B3658 802C6EA8 03016825 */  or         $t5, $t8, $at
    /* 1B365C 802C6EAC 25088510 */  addiu      $t0, $t0, %lo(D_8008510)
    /* 1B3660 802C6EB0 37FFC028 */  ori        $ra, $ra, (0x2FC028 & 0xFFFF)
    /* 1B3664 802C6EB4 36F70200 */  ori        $s7, $s7, (0x80200 & 0xFFFF)
    /* 1B3668 802C6EB8 36B5C028 */  ori        $s5, $s5, (0x72FC028 & 0xFFFF)
    /* 1B366C 802C6EBC 36520200 */  ori        $s2, $s2, (0x7080200 & 0xFFFF)
    /* 1B3670 802C6EC0 363100BF */  ori        $s1, $s1, (0xFD6800BF & 0xFFFF)
    /* 1B3674 802C6EC4 000E8300 */  sll        $s0, $t6, 12
    /* 1B3678 802C6EC8 3C13E600 */  lui        $s3, (0xE6000000 >> 16)
    /* 1B367C 802C6ECC 3C14F400 */  lui        $s4, (0xF4000000 >> 16)
    /* 1B3680 802C6ED0 3C16E700 */  lui        $s6, (0xE7000000 >> 16)
    /* 1B3684 802C6ED4 3C1EF200 */  lui        $fp, (0xF2000000 >> 16)
    /* 1B3688 802C6ED8 00004825 */  or         $t1, $zero, $zero
    /* 1B368C 802C6EDC 00C03825 */  or         $a3, $a2, $zero
    /* 1B3690 802C6EE0 24CA000B */  addiu      $t2, $a2, 0xB
  .L1B1FB0_802C6EE4:
    /* 1B3694 802C6EE4 00801025 */  or         $v0, $a0, $zero
    /* 1B3698 802C6EE8 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B369C 802C6EEC 00801825 */  or         $v1, $a0, $zero
    /* 1B36A0 802C6EF0 AC510000 */  sw         $s1, 0x0($v0)
    /* 1B36A4 802C6EF4 AC480004 */  sw         $t0, 0x4($v0)
    /* 1B36A8 802C6EF8 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B36AC 802C6EFC 00802825 */  or         $a1, $a0, $zero
    /* 1B36B0 802C6F00 AC720004 */  sw         $s2, 0x4($v1)
    /* 1B36B4 802C6F04 AC6C0000 */  sw         $t4, 0x0($v1)
    /* 1B36B8 802C6F08 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B36BC 802C6F0C 00803025 */  or         $a2, $a0, $zero
    /* 1B36C0 802C6F10 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B36C4 802C6F14 ACA00004 */  sw         $zero, 0x4($a1)
    /* 1B36C8 802C6F18 ACB30000 */  sw         $s3, 0x0($a1)
    /* 1B36CC 802C6F1C 00805825 */  or         $t3, $a0, $zero
    /* 1B36D0 802C6F20 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B36D4 802C6F24 ACD50004 */  sw         $s5, 0x4($a2)
    /* 1B36D8 802C6F28 ACD40000 */  sw         $s4, 0x0($a2)
    /* 1B36DC 802C6F2C 00801025 */  or         $v0, $a0, $zero
    /* 1B36E0 802C6F30 AD600004 */  sw         $zero, 0x4($t3)
    /* 1B36E4 802C6F34 AD760000 */  sw         $s6, 0x0($t3)
    /* 1B36E8 802C6F38 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B36EC 802C6F3C 00801825 */  or         $v1, $a0, $zero
    /* 1B36F0 802C6F40 AC570004 */  sw         $s7, 0x4($v0)
    /* 1B36F4 802C6F44 AC4C0000 */  sw         $t4, 0x0($v0)
    /* 1B36F8 802C6F48 000AC080 */  sll        $t8, $t2, 2
    /* 1B36FC 802C6F4C 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3700 802C6F50 33190FFF */  andi       $t9, $t8, 0xFFF
    /* 1B3704 802C6F54 01B97025 */  or         $t6, $t5, $t9
    /* 1B3708 802C6F58 00802825 */  or         $a1, $a0, $zero
    /* 1B370C 802C6F5C 00077880 */  sll        $t7, $a3, 2
    /* 1B3710 802C6F60 AC7F0004 */  sw         $ra, 0x4($v1)
    /* 1B3714 802C6F64 AC7E0000 */  sw         $fp, 0x0($v1)
    /* 1B3718 802C6F68 31F80FFF */  andi       $t8, $t7, 0xFFF
    /* 1B371C 802C6F6C 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3720 802C6F70 00803025 */  or         $a2, $a0, $zero
    /* 1B3724 802C6F74 0218C825 */  or         $t9, $s0, $t8
    /* 1B3728 802C6F78 ACAE0000 */  sw         $t6, 0x0($a1)
    /* 1B372C 802C6F7C ACB90004 */  sw         $t9, 0x4($a1)
    /* 1B3730 802C6F80 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3734 802C6F84 00801025 */  or         $v0, $a0, $zero
    /* 1B3738 802C6F88 3C0EB300 */  lui        $t6, (0xB3000000 >> 16)
    /* 1B373C 802C6F8C 3C180400 */  lui        $t8, (0x4000400 >> 16)
    /* 1B3740 802C6F90 2529000B */  addiu      $t1, $t1, 0xB
    /* 1B3744 802C6F94 2401002C */  addiu      $at, $zero, 0x2C
    /* 1B3748 802C6F98 37180400 */  ori        $t8, $t8, (0x4000400 & 0xFFFF)
    /* 1B374C 802C6F9C ACCE0000 */  sw         $t6, 0x0($a2)
    /* 1B3750 802C6FA0 ACC00004 */  sw         $zero, 0x4($a2)
    /* 1B3754 802C6FA4 3C0FB200 */  lui        $t7, (0xB2000000 >> 16)
    /* 1B3758 802C6FA8 24E7000B */  addiu      $a3, $a3, 0xB
    /* 1B375C 802C6FAC 254A000B */  addiu      $t2, $t2, 0xB
    /* 1B3760 802C6FB0 25080840 */  addiu      $t0, $t0, 0x840
    /* 1B3764 802C6FB4 AC4F0000 */  sw         $t7, 0x0($v0)
    /* 1B3768 802C6FB8 AC580004 */  sw         $t8, 0x4($v0)
    /* 1B376C 802C6FBC 1521FFC9 */  bne        $t1, $at, .L1B1FB0_802C6EE4
    /* 1B3770 802C6FC0 24840008 */   addiu     $a0, $a0, 0x8
    /* 1B3774 802C6FC4 8FBF002C */  lw         $ra, 0x2C($sp)
    /* 1B3778 802C6FC8 8FB00008 */  lw         $s0, 0x8($sp)
    /* 1B377C 802C6FCC 8FB1000C */  lw         $s1, 0xC($sp)
    /* 1B3780 802C6FD0 8FB20010 */  lw         $s2, 0x10($sp)
    /* 1B3784 802C6FD4 8FB30014 */  lw         $s3, 0x14($sp)
    /* 1B3788 802C6FD8 8FB40018 */  lw         $s4, 0x18($sp)
    /* 1B378C 802C6FDC 8FB5001C */  lw         $s5, 0x1C($sp)
    /* 1B3790 802C6FE0 8FB60020 */  lw         $s6, 0x20($sp)
    /* 1B3794 802C6FE4 8FB70024 */  lw         $s7, 0x24($sp)
    /* 1B3798 802C6FE8 8FBE0028 */  lw         $fp, 0x28($sp)
    /* 1B379C 802C6FEC 27BD0030 */  addiu      $sp, $sp, 0x30
    /* 1B37A0 802C6FF0 03E00008 */  jr         $ra
    /* 1B37A4 802C6FF4 00801025 */   or        $v0, $a0, $zero
endlabel func_1B1FB0_802C6E40
.size func_1B1FB0_802C6E40, . - func_1B1FB0_802C6E40

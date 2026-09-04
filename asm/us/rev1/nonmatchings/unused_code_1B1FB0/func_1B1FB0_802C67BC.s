nonmatching func_1B1FB0_802C67BC, 0x1B4

glabel func_1B1FB0_802C67BC
    /* 1B2F6C 802C67BC 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* 1B2F70 802C67C0 24AC01FF */  addiu      $t4, $a1, 0x1FF
    /* 1B2F74 802C67C4 000C7080 */  sll        $t6, $t4, 2
    /* 1B2F78 802C67C8 31CF0FFF */  andi       $t7, $t6, 0xFFF
    /* 1B2F7C 802C67CC AFBE0028 */  sw         $fp, 0x28($sp)
    /* 1B2F80 802C67D0 AFB5001C */  sw         $s5, 0x1C($sp)
    /* 1B2F84 802C67D4 AFB20010 */  sw         $s2, 0x10($sp)
    /* 1B2F88 802C67D8 00056880 */  sll        $t5, $a1, 2
    /* 1B2F8C 802C67DC AFBF002C */  sw         $ra, 0x2C($sp)
    /* 1B2F90 802C67E0 AFB70024 */  sw         $s7, 0x24($sp)
    /* 1B2F94 802C67E4 AFB60020 */  sw         $s6, 0x20($sp)
    /* 1B2F98 802C67E8 AFB40018 */  sw         $s4, 0x18($sp)
    /* 1B2F9C 802C67EC AFB30014 */  sw         $s3, 0x14($sp)
    /* 1B2FA0 802C67F0 AFB1000C */  sw         $s1, 0xC($sp)
    /* 1B2FA4 802C67F4 AFB00008 */  sw         $s0, 0x8($sp)
    /* 1B2FA8 802C67F8 31AE0FFF */  andi       $t6, $t5, 0xFFF
    /* 1B2FAC 802C67FC 3C120708 */  lui        $s2, (0x7080200 >> 16)
    /* 1B2FB0 802C6800 3C15077F */  lui        $s5, (0x77FF010 >> 16)
    /* 1B2FB4 802C6804 3C1E0008 */  lui        $fp, (0x80200 >> 16)
    /* 1B2FB8 802C6808 000FC300 */  sll        $t8, $t7, 12
    /* 1B2FBC 802C680C 3C080805 */  lui        $t0, %hi(D_804A460)
    /* 1B2FC0 802C6810 3C01E400 */  lui        $at, (0xE4000000 >> 16)
    /* 1B2FC4 802C6814 03016025 */  or         $t4, $t8, $at
    /* 1B2FC8 802C6818 2508A460 */  addiu      $t0, $t0, %lo(D_804A460)
    /* 1B2FCC 802C681C 37DE0200 */  ori        $fp, $fp, (0x80200 & 0xFFFF)
    /* 1B2FD0 802C6820 36B5F010 */  ori        $s5, $s5, (0x77FF010 & 0xFFFF)
    /* 1B2FD4 802C6824 36520200 */  ori        $s2, $s2, (0x7080200 & 0xFFFF)
    /* 1B2FD8 802C6828 000E6B00 */  sll        $t5, $t6, 12
    /* 1B2FDC 802C682C 3C10FD10 */  lui        $s0, (0xFD100000 >> 16)
    /* 1B2FE0 802C6830 3C11F510 */  lui        $s1, (0xF5100000 >> 16)
    /* 1B2FE4 802C6834 3C13E600 */  lui        $s3, (0xE6000000 >> 16)
    /* 1B2FE8 802C6838 3C14F300 */  lui        $s4, (0xF3000000 >> 16)
    /* 1B2FEC 802C683C 3C16E700 */  lui        $s6, (0xE7000000 >> 16)
    /* 1B2FF0 802C6840 3C17F511 */  lui        $s7, (0xF5110000 >> 16)
    /* 1B2FF4 802C6844 3C1FF200 */  lui        $ra, (0xF2000000 >> 16)
    /* 1B2FF8 802C6848 00004825 */  or         $t1, $zero, $zero
    /* 1B2FFC 802C684C 00C03825 */  or         $a3, $a2, $zero
    /* 1B3000 802C6850 24CA0003 */  addiu      $t2, $a2, 0x3
  .L1B1FB0_802C6854:
    /* 1B3004 802C6854 00801025 */  or         $v0, $a0, $zero
    /* 1B3008 802C6858 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B300C 802C685C 00801825 */  or         $v1, $a0, $zero
    /* 1B3010 802C6860 AC500000 */  sw         $s0, 0x0($v0)
    /* 1B3014 802C6864 AC480004 */  sw         $t0, 0x4($v0)
    /* 1B3018 802C6868 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B301C 802C686C 00802825 */  or         $a1, $a0, $zero
    /* 1B3020 802C6870 AC720004 */  sw         $s2, 0x4($v1)
    /* 1B3024 802C6874 AC710000 */  sw         $s1, 0x0($v1)
    /* 1B3028 802C6878 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B302C 802C687C 00803025 */  or         $a2, $a0, $zero
    /* 1B3030 802C6880 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3034 802C6884 ACA00004 */  sw         $zero, 0x4($a1)
    /* 1B3038 802C6888 ACB30000 */  sw         $s3, 0x0($a1)
    /* 1B303C 802C688C 00805825 */  or         $t3, $a0, $zero
    /* 1B3040 802C6890 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3044 802C6894 ACD50004 */  sw         $s5, 0x4($a2)
    /* 1B3048 802C6898 ACD40000 */  sw         $s4, 0x0($a2)
    /* 1B304C 802C689C 00801025 */  or         $v0, $a0, $zero
    /* 1B3050 802C68A0 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3054 802C68A4 AD600004 */  sw         $zero, 0x4($t3)
    /* 1B3058 802C68A8 AD760000 */  sw         $s6, 0x0($t3)
    /* 1B305C 802C68AC 00801825 */  or         $v1, $a0, $zero
    /* 1B3060 802C68B0 3C18007F */  lui        $t8, (0x7FC00C >> 16)
    /* 1B3064 802C68B4 3718C00C */  ori        $t8, $t8, (0x7FC00C & 0xFFFF)
    /* 1B3068 802C68B8 AC5E0004 */  sw         $fp, 0x4($v0)
    /* 1B306C 802C68BC AC570000 */  sw         $s7, 0x0($v0)
    /* 1B3070 802C68C0 000AC880 */  sll        $t9, $t2, 2
    /* 1B3074 802C68C4 AC780004 */  sw         $t8, 0x4($v1)
    /* 1B3078 802C68C8 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B307C 802C68CC 332E0FFF */  andi       $t6, $t9, 0xFFF
    /* 1B3080 802C68D0 018E7825 */  or         $t7, $t4, $t6
    /* 1B3084 802C68D4 00802825 */  or         $a1, $a0, $zero
    /* 1B3088 802C68D8 0007C080 */  sll        $t8, $a3, 2
    /* 1B308C 802C68DC AC7F0000 */  sw         $ra, 0x0($v1)
    /* 1B3090 802C68E0 33190FFF */  andi       $t9, $t8, 0xFFF
    /* 1B3094 802C68E4 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3098 802C68E8 00803025 */  or         $a2, $a0, $zero
    /* 1B309C 802C68EC 01B97025 */  or         $t6, $t5, $t9
    /* 1B30A0 802C68F0 ACAF0000 */  sw         $t7, 0x0($a1)
    /* 1B30A4 802C68F4 ACAE0004 */  sw         $t6, 0x4($a1)
    /* 1B30A8 802C68F8 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B30AC 802C68FC 00801025 */  or         $v0, $a0, $zero
    /* 1B30B0 802C6900 3C0FB300 */  lui        $t7, (0xB3000000 >> 16)
    /* 1B30B4 802C6904 3C191000 */  lui        $t9, (0x10000400 >> 16)
    /* 1B30B8 802C6908 25290004 */  addiu      $t1, $t1, 0x4
    /* 1B30BC 802C690C 24010014 */  addiu      $at, $zero, 0x14
    /* 1B30C0 802C6910 37390400 */  ori        $t9, $t9, (0x10000400 & 0xFFFF)
    /* 1B30C4 802C6914 ACCF0000 */  sw         $t7, 0x0($a2)
    /* 1B30C8 802C6918 ACC00004 */  sw         $zero, 0x4($a2)
    /* 1B30CC 802C691C 3C18B200 */  lui        $t8, (0xB2000000 >> 16)
    /* 1B30D0 802C6920 24E70004 */  addiu      $a3, $a3, 0x4
    /* 1B30D4 802C6924 254A0004 */  addiu      $t2, $t2, 0x4
    /* 1B30D8 802C6928 25081000 */  addiu      $t0, $t0, 0x1000
    /* 1B30DC 802C692C AC580000 */  sw         $t8, 0x0($v0)
    /* 1B30E0 802C6930 AC590004 */  sw         $t9, 0x4($v0)
    /* 1B30E4 802C6934 1521FFC7 */  bne        $t1, $at, .L1B1FB0_802C6854
    /* 1B30E8 802C6938 24840008 */   addiu     $a0, $a0, 0x8
    /* 1B30EC 802C693C 8FBF002C */  lw         $ra, 0x2C($sp)
    /* 1B30F0 802C6940 8FB00008 */  lw         $s0, 0x8($sp)
    /* 1B30F4 802C6944 8FB1000C */  lw         $s1, 0xC($sp)
    /* 1B30F8 802C6948 8FB20010 */  lw         $s2, 0x10($sp)
    /* 1B30FC 802C694C 8FB30014 */  lw         $s3, 0x14($sp)
    /* 1B3100 802C6950 8FB40018 */  lw         $s4, 0x18($sp)
    /* 1B3104 802C6954 8FB5001C */  lw         $s5, 0x1C($sp)
    /* 1B3108 802C6958 8FB60020 */  lw         $s6, 0x20($sp)
    /* 1B310C 802C695C 8FB70024 */  lw         $s7, 0x24($sp)
    /* 1B3110 802C6960 8FBE0028 */  lw         $fp, 0x28($sp)
    /* 1B3114 802C6964 27BD0030 */  addiu      $sp, $sp, 0x30
    /* 1B3118 802C6968 03E00008 */  jr         $ra
    /* 1B311C 802C696C 00801025 */   or        $v0, $a0, $zero
endlabel func_1B1FB0_802C67BC
.size func_1B1FB0_802C67BC, . - func_1B1FB0_802C67BC

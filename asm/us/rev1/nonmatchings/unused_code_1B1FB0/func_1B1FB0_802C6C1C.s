nonmatching func_1B1FB0_802C6C1C, 0x224

glabel func_1B1FB0_802C6C1C
    /* 1B33CC 802C6C1C 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* 1B33D0 802C6C20 3C0D801D */  lui        $t5, %hi(D_801CB410)
    /* 1B33D4 802C6C24 8DADB410 */  lw         $t5, %lo(D_801CB410)($t5)
    /* 1B33D8 802C6C28 AFBF002C */  sw         $ra, 0x2C($sp)
    /* 1B33DC 802C6C2C AFBE0028 */  sw         $fp, 0x28($sp)
    /* 1B33E0 802C6C30 29A1000A */  slti       $at, $t5, 0xA
    /* 1B33E4 802C6C34 AFB70024 */  sw         $s7, 0x24($sp)
    /* 1B33E8 802C6C38 AFB60020 */  sw         $s6, 0x20($sp)
    /* 1B33EC 802C6C3C AFB5001C */  sw         $s5, 0x1C($sp)
    /* 1B33F0 802C6C40 AFB40018 */  sw         $s4, 0x18($sp)
    /* 1B33F4 802C6C44 AFB30014 */  sw         $s3, 0x14($sp)
    /* 1B33F8 802C6C48 AFB20010 */  sw         $s2, 0x10($sp)
    /* 1B33FC 802C6C4C AFB1000C */  sw         $s1, 0xC($sp)
    /* 1B3400 802C6C50 10200004 */  beqz       $at, .L1B1FB0_802C6C64
    /* 1B3404 802C6C54 AFB00008 */   sw        $s0, 0x8($sp)
    /* 1B3408 802C6C58 240E0001 */  addiu      $t6, $zero, 0x1
    /* 1B340C 802C6C5C 10000009 */  b          .L1B1FB0_802C6C84
    /* 1B3410 802C6C60 AFAE0030 */   sw        $t6, 0x30($sp)
  .L1B1FB0_802C6C64:
    /* 1B3414 802C6C64 29A10064 */  slti       $at, $t5, 0x64
    /* 1B3418 802C6C68 50200005 */  beql       $at, $zero, .L1B1FB0_802C6C80
    /* 1B341C 802C6C6C 24180003 */   addiu     $t8, $zero, 0x3
    /* 1B3420 802C6C70 240F0002 */  addiu      $t7, $zero, 0x2
    /* 1B3424 802C6C74 10000003 */  b          .L1B1FB0_802C6C84
    /* 1B3428 802C6C78 AFAF0030 */   sw        $t7, 0x30($sp)
    /* 1B342C 802C6C7C 24180003 */  addiu      $t8, $zero, 0x3
  .L1B1FB0_802C6C80:
    /* 1B3430 802C6C80 AFB80030 */  sw         $t8, 0x30($sp)
  .L1B1FB0_802C6C84:
    /* 1B3434 802C6C84 8FB90030 */  lw         $t9, 0x30($sp)
    /* 1B3438 802C6C88 00004025 */  or         $t0, $zero, $zero
    /* 1B343C 802C6C8C 24090230 */  addiu      $t1, $zero, 0x230
    /* 1B3440 802C6C90 1B20005E */  blez       $t9, .L1B1FB0_802C6E0C
    /* 1B3444 802C6C94 240A0220 */   addiu     $t2, $zero, 0x220
    /* 1B3448 802C6C98 3C1F0008 */  lui        $ra, (0x80200 >> 16)
    /* 1B344C 802C6C9C 3C1EF568 */  lui        $fp, (0xF5680400 >> 16)
    /* 1B3450 802C6CA0 3C160708 */  lui        $s6, (0x708F400 >> 16)
    /* 1B3454 802C6CA4 3C130708 */  lui        $s3, (0x7080200 >> 16)
    /* 1B3458 802C6CA8 3C11802C */  lui        $s1, %hi(D_1B1FB0_802C767C)
    /* 1B345C 802C6CAC 2631767C */  addiu      $s1, $s1, %lo(D_1B1FB0_802C767C)
    /* 1B3460 802C6CB0 36730200 */  ori        $s3, $s3, (0x7080200 & 0xFFFF)
    /* 1B3464 802C6CB4 36D6F400 */  ori        $s6, $s6, (0x708F400 & 0xFFFF)
    /* 1B3468 802C6CB8 37DE0400 */  ori        $fp, $fp, (0xF5680400 & 0xFFFF)
    /* 1B346C 802C6CBC 37FF0200 */  ori        $ra, $ra, (0x80200 & 0xFFFF)
    /* 1B3470 802C6CC0 3C17E700 */  lui        $s7, (0xE7000000 >> 16)
    /* 1B3474 802C6CC4 3C15F300 */  lui        $s5, (0xF3000000 >> 16)
    /* 1B3478 802C6CC8 3C14E600 */  lui        $s4, (0xE6000000 >> 16)
    /* 1B347C 802C6CCC 3C12F570 */  lui        $s2, (0xF5700000 >> 16)
    /* 1B3480 802C6CD0 3C10FD70 */  lui        $s0, (0xFD700000 >> 16)
    /* 1B3484 802C6CD4 240C000A */  addiu      $t4, $zero, 0xA
  .L1B1FB0_802C6CD8:
    /* 1B3488 802C6CD8 01AC001A */  div        $zero, $t5, $t4
    /* 1B348C 802C6CDC 00003810 */  mfhi       $a3
    /* 1B3490 802C6CE0 00077080 */  sll        $t6, $a3, 2
    /* 1B3494 802C6CE4 00801025 */  or         $v0, $a0, $zero
    /* 1B3498 802C6CE8 AC500000 */  sw         $s0, 0x0($v0)
    /* 1B349C 802C6CEC 022E7821 */  addu       $t7, $s1, $t6
    /* 1B34A0 802C6CF0 8DF80000 */  lw         $t8, 0x0($t7)
    /* 1B34A4 802C6CF4 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B34A8 802C6CF8 00801825 */  or         $v1, $a0, $zero
    /* 1B34AC 802C6CFC AC580004 */  sw         $t8, 0x4($v0)
    /* 1B34B0 802C6D00 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B34B4 802C6D04 00802825 */  or         $a1, $a0, $zero
    /* 1B34B8 802C6D08 AC730004 */  sw         $s3, 0x4($v1)
    /* 1B34BC 802C6D0C AC720000 */  sw         $s2, 0x0($v1)
    /* 1B34C0 802C6D10 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B34C4 802C6D14 00803025 */  or         $a2, $a0, $zero
    /* 1B34C8 802C6D18 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B34CC 802C6D1C ACA00004 */  sw         $zero, 0x4($a1)
    /* 1B34D0 802C6D20 ACB40000 */  sw         $s4, 0x0($a1)
    /* 1B34D4 802C6D24 00805825 */  or         $t3, $a0, $zero
    /* 1B34D8 802C6D28 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B34DC 802C6D2C ACD60004 */  sw         $s6, 0x4($a2)
    /* 1B34E0 802C6D30 ACD50000 */  sw         $s5, 0x0($a2)
    /* 1B34E4 802C6D34 00801025 */  or         $v0, $a0, $zero
    /* 1B34E8 802C6D38 15800002 */  bnez       $t4, .L1B1FB0_802C6D44
    /* 1B34EC 802C6D3C 00000000 */   nop
    /* 1B34F0 802C6D40 0007000D */  break      7
  .L1B1FB0_802C6D44:
    /* 1B34F4 802C6D44 2401FFFF */  addiu      $at, $zero, -0x1
    /* 1B34F8 802C6D48 15810004 */  bne        $t4, $at, .L1B1FB0_802C6D5C
    /* 1B34FC 802C6D4C 3C018000 */   lui       $at, (0x80000000 >> 16)
    /* 1B3500 802C6D50 15A10002 */  bne        $t5, $at, .L1B1FB0_802C6D5C
    /* 1B3504 802C6D54 00000000 */   nop
    /* 1B3508 802C6D58 0006000D */  break      6
  .L1B1FB0_802C6D5C:
    /* 1B350C 802C6D5C AD600004 */  sw         $zero, 0x4($t3)
    /* 1B3510 802C6D60 AD770000 */  sw         $s7, 0x0($t3)
    /* 1B3514 802C6D64 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3518 802C6D68 00801825 */  or         $v1, $a0, $zero
    /* 1B351C 802C6D6C AC5F0004 */  sw         $ra, 0x4($v0)
    /* 1B3520 802C6D70 AC5E0000 */  sw         $fp, 0x0($v0)
    /* 1B3524 802C6D74 3C0E0003 */  lui        $t6, (0x3C044 >> 16)
    /* 1B3528 802C6D78 3C19F200 */  lui        $t9, (0xF2000000 >> 16)
    /* 1B352C 802C6D7C 00097880 */  sll        $t7, $t1, 2
    /* 1B3530 802C6D80 AC790000 */  sw         $t9, 0x0($v1)
    /* 1B3534 802C6D84 35CEC044 */  ori        $t6, $t6, (0x3C044 & 0xFFFF)
    /* 1B3538 802C6D88 31F80FFF */  andi       $t8, $t7, 0xFFF
    /* 1B353C 802C6D8C AC6E0004 */  sw         $t6, 0x4($v1)
    /* 1B3540 802C6D90 0018CB00 */  sll        $t9, $t8, 12
    /* 1B3544 802C6D94 3C01E400 */  lui        $at, (0xE4000608 >> 16)
    /* 1B3548 802C6D98 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B354C 802C6D9C 03217025 */  or         $t6, $t9, $at
    /* 1B3550 802C6DA0 35CF0608 */  ori        $t7, $t6, (0xE4000608 & 0xFFFF)
    /* 1B3554 802C6DA4 00802825 */  or         $a1, $a0, $zero
    /* 1B3558 802C6DA8 000AC080 */  sll        $t8, $t2, 2
    /* 1B355C 802C6DAC 33190FFF */  andi       $t9, $t8, 0xFFF
    /* 1B3560 802C6DB0 00197300 */  sll        $t6, $t9, 12
    /* 1B3564 802C6DB4 ACAF0000 */  sw         $t7, 0x0($a1)
    /* 1B3568 802C6DB8 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B356C 802C6DBC 00803025 */  or         $a2, $a0, $zero
    /* 1B3570 802C6DC0 35CF05C0 */  ori        $t7, $t6, 0x5C0
    /* 1B3574 802C6DC4 ACAF0004 */  sw         $t7, 0x4($a1)
    /* 1B3578 802C6DC8 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B357C 802C6DCC 3C18B300 */  lui        $t8, (0xB3000000 >> 16)
    /* 1B3580 802C6DD0 ACD80000 */  sw         $t8, 0x0($a2)
    /* 1B3584 802C6DD4 00801025 */  or         $v0, $a0, $zero
    /* 1B3588 802C6DD8 ACC00004 */  sw         $zero, 0x4($a2)
    /* 1B358C 802C6DDC 3C0E0400 */  lui        $t6, (0x4000400 >> 16)
    /* 1B3590 802C6DE0 35CE0400 */  ori        $t6, $t6, (0x4000400 & 0xFFFF)
    /* 1B3594 802C6DE4 3C19B200 */  lui        $t9, (0xB2000000 >> 16)
    /* 1B3598 802C6DE8 AC590000 */  sw         $t9, 0x0($v0)
    /* 1B359C 802C6DEC AC4E0004 */  sw         $t6, 0x4($v0)
    /* 1B35A0 802C6DF0 8FAF0030 */  lw         $t7, 0x30($sp)
    /* 1B35A4 802C6DF4 25080001 */  addiu      $t0, $t0, 0x1
    /* 1B35A8 802C6DF8 00006812 */  mflo       $t5
    /* 1B35AC 802C6DFC 254AFFEE */  addiu      $t2, $t2, -0x12
    /* 1B35B0 802C6E00 2529FFEE */  addiu      $t1, $t1, -0x12
    /* 1B35B4 802C6E04 150FFFB4 */  bne        $t0, $t7, .L1B1FB0_802C6CD8
    /* 1B35B8 802C6E08 24840008 */   addiu     $a0, $a0, 0x8
  .L1B1FB0_802C6E0C:
    /* 1B35BC 802C6E0C 8FBF002C */  lw         $ra, 0x2C($sp)
    /* 1B35C0 802C6E10 8FB00008 */  lw         $s0, 0x8($sp)
    /* 1B35C4 802C6E14 8FB1000C */  lw         $s1, 0xC($sp)
    /* 1B35C8 802C6E18 8FB20010 */  lw         $s2, 0x10($sp)
    /* 1B35CC 802C6E1C 8FB30014 */  lw         $s3, 0x14($sp)
    /* 1B35D0 802C6E20 8FB40018 */  lw         $s4, 0x18($sp)
    /* 1B35D4 802C6E24 8FB5001C */  lw         $s5, 0x1C($sp)
    /* 1B35D8 802C6E28 8FB60020 */  lw         $s6, 0x20($sp)
    /* 1B35DC 802C6E2C 8FB70024 */  lw         $s7, 0x24($sp)
    /* 1B35E0 802C6E30 8FBE0028 */  lw         $fp, 0x28($sp)
    /* 1B35E4 802C6E34 27BD0038 */  addiu      $sp, $sp, 0x38
    /* 1B35E8 802C6E38 03E00008 */  jr         $ra
    /* 1B35EC 802C6E3C 00801025 */   or        $v0, $a0, $zero
endlabel func_1B1FB0_802C6C1C
.size func_1B1FB0_802C6C1C, . - func_1B1FB0_802C6C1C

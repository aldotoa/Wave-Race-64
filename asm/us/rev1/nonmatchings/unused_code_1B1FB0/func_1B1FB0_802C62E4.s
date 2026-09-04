nonmatching func_1B1FB0_802C62E4, 0x4D8

glabel func_1B1FB0_802C62E4
    /* 1B2A94 802C62E4 27BDFFA8 */  addiu      $sp, $sp, -0x58
    /* 1B2A98 802C62E8 AFB60038 */  sw         $s6, 0x38($sp)
    /* 1B2A9C 802C62EC AFB50034 */  sw         $s5, 0x34($sp)
    /* 1B2AA0 802C62F0 AFB40030 */  sw         $s4, 0x30($sp)
    /* 1B2AA4 802C62F4 AFB3002C */  sw         $s3, 0x2C($sp)
    /* 1B2AA8 802C62F8 AFB20028 */  sw         $s2, 0x28($sp)
    /* 1B2AAC 802C62FC AFB10024 */  sw         $s1, 0x24($sp)
    /* 1B2AB0 802C6300 AFB00020 */  sw         $s0, 0x20($sp)
    /* 1B2AB4 802C6304 AFBF0044 */  sw         $ra, 0x44($sp)
    /* 1B2AB8 802C6308 AFBE0040 */  sw         $fp, 0x40($sp)
    /* 1B2ABC 802C630C AFB7003C */  sw         $s7, 0x3C($sp)
    /* 1B2AC0 802C6310 24910008 */  addiu      $s1, $a0, 0x8
    /* 1B2AC4 802C6314 3C16E700 */  lui        $s6, (0xE7000000 >> 16)
    /* 1B2AC8 802C6318 02201825 */  or         $v1, $s1, $zero
    /* 1B2ACC 802C631C AC960000 */  sw         $s6, 0x0($a0)
    /* 1B2AD0 802C6320 AC800004 */  sw         $zero, 0x4($a0)
    /* 1B2AD4 802C6324 3C0F009F */  lui        $t7, (0x9FC614 >> 16)
    /* 1B2AD8 802C6328 35EFC614 */  ori        $t7, $t7, (0x9FC614 & 0xFFFF)
    /* 1B2ADC 802C632C 3C0EED00 */  lui        $t6, (0xED000000 >> 16)
    /* 1B2AE0 802C6330 3C10802C */  lui        $s0, %hi(D_1B1FB0_802C76E8)
    /* 1B2AE4 802C6334 3C15802C */  lui        $s5, %hi(D_1B1FB0_802C76EC)
    /* 1B2AE8 802C6338 AC6E0000 */  sw         $t6, 0x0($v1)
    /* 1B2AEC 802C633C AC6F0004 */  sw         $t7, 0x4($v1)
    /* 1B2AF0 802C6340 26310008 */  addiu      $s1, $s1, 0x8
    /* 1B2AF4 802C6344 26B576EC */  addiu      $s5, $s5, %lo(D_1B1FB0_802C76EC)
    /* 1B2AF8 802C6348 261076E8 */  addiu      $s0, $s0, %lo(D_1B1FB0_802C76E8)
    /* 1B2AFC 802C634C 24120008 */  addiu      $s2, $zero, 0x8
    /* 1B2B00 802C6350 24130014 */  addiu      $s3, $zero, 0x14
    /* 1B2B04 802C6354 0000A025 */  or         $s4, $zero, $zero
    /* 1B2B08 802C6358 8E180000 */  lw         $t8, 0x0($s0)
  .L1B1FB0_802C635C:
    /* 1B2B0C 802C635C 17000005 */  bnez       $t8, .L1B1FB0_802C6374
    /* 1B2B10 802C6360 00000000 */   nop
    /* 1B2B14 802C6364 5280000D */  beql       $s4, $zero, .L1B1FB0_802C639C
    /* 1B2B18 802C6368 26940001 */   addiu     $s4, $s4, 0x1
    /* 1B2B1C 802C636C 5292000B */  beql       $s4, $s2, .L1B1FB0_802C639C
    /* 1B2B20 802C6370 26940001 */   addiu     $s4, $s4, 0x1
  .L1B1FB0_802C6374:
    /* 1B2B24 802C6374 02930019 */  multu      $s4, $s3
    /* 1B2B28 802C6378 8EA80000 */  lw         $t0, 0x0($s5)
    /* 1B2B2C 802C637C 02202025 */  or         $a0, $s1, $zero
    /* 1B2B30 802C6380 24050040 */  addiu      $a1, $zero, 0x40
    /* 1B2B34 802C6384 0000C812 */  mflo       $t9
    /* 1B2B38 802C6388 03283021 */  addu       $a2, $t9, $t0
    /* 1B2B3C 802C638C 0C0B19EF */  jal        func_1B1FB0_802C67BC
    /* 1B2B40 802C6390 00000000 */   nop
    /* 1B2B44 802C6394 00408825 */  or         $s1, $v0, $zero
    /* 1B2B48 802C6398 26940001 */  addiu      $s4, $s4, 0x1
  .L1B1FB0_802C639C:
    /* 1B2B4C 802C639C 2A810009 */  slti       $at, $s4, 0x9
    /* 1B2B50 802C63A0 5420FFEE */  bnel       $at, $zero, .L1B1FB0_802C635C
    /* 1B2B54 802C63A4 8E180000 */   lw        $t8, 0x0($s0)
    /* 1B2B58 802C63A8 02201025 */  or         $v0, $s1, $zero
    /* 1B2B5C 802C63AC 3C0A0806 */  lui        $t2, %hi(D_80675E8)
    /* 1B2B60 802C63B0 254A75E8 */  addiu      $t2, $t2, %lo(D_80675E8)
    /* 1B2B64 802C63B4 26310008 */  addiu      $s1, $s1, 0x8
    /* 1B2B68 802C63B8 3C090600 */  lui        $t1, (0x6000000 >> 16)
    /* 1B2B6C 802C63BC 3C10FA00 */  lui        $s0, (0xFA000000 >> 16)
    /* 1B2B70 802C63C0 AC490000 */  sw         $t1, 0x0($v0)
    /* 1B2B74 802C63C4 AC4A0004 */  sw         $t2, 0x4($v0)
    /* 1B2B78 802C63C8 02201825 */  or         $v1, $s1, $zero
    /* 1B2B7C 802C63CC AC700000 */  sw         $s0, 0x0($v1)
    /* 1B2B80 802C63D0 3C0B802C */  lui        $t3, %hi(D_802C7710)
    /* 1B2B84 802C63D4 8D6B7710 */  lw         $t3, %lo(D_802C7710)($t3)
    /* 1B2B88 802C63D8 3C01FF00 */  lui        $at, (0xFF0000FF >> 16)
    /* 1B2B8C 802C63DC 3C18802C */  lui        $t8, %hi(D_1B1FB0_802C76A4)
    /* 1B2B90 802C63E0 316C00FF */  andi       $t4, $t3, 0xFF
    /* 1B2B94 802C63E4 000C6C00 */  sll        $t5, $t4, 16
    /* 1B2B98 802C63E8 01A17025 */  or         $t6, $t5, $at
    /* 1B2B9C 802C63EC 35CF00FF */  ori        $t7, $t6, (0xFF0000FF & 0xFFFF)
    /* 1B2BA0 802C63F0 AC6F0004 */  sw         $t7, 0x4($v1)
    /* 1B2BA4 802C63F4 8F1876A4 */  lw         $t8, %lo(D_1B1FB0_802C76A4)($t8)
    /* 1B2BA8 802C63F8 26310008 */  addiu      $s1, $s1, 0x8
    /* 1B2BAC 802C63FC 53000005 */  beql       $t8, $zero, .L1B1FB0_802C6414
    /* 1B2BB0 802C6400 02201025 */   or        $v0, $s1, $zero
    /* 1B2BB4 802C6404 0C0B1BFE */  jal        func_1B1FB0_802C6FF8
    /* 1B2BB8 802C6408 02202025 */   or        $a0, $s1, $zero
    /* 1B2BBC 802C640C 00408825 */  or         $s1, $v0, $zero
    /* 1B2BC0 802C6410 02201025 */  or         $v0, $s1, $zero
  .L1B1FB0_802C6414:
    /* 1B2BC4 802C6414 AC560000 */  sw         $s6, 0x0($v0)
    /* 1B2BC8 802C6418 26310008 */  addiu      $s1, $s1, 0x8
    /* 1B2BCC 802C641C AC400004 */  sw         $zero, 0x4($v0)
    /* 1B2BD0 802C6420 02201825 */  or         $v1, $s1, $zero
    /* 1B2BD4 802C6424 241932FF */  addiu      $t9, $zero, 0x32FF
    /* 1B2BD8 802C6428 AC790004 */  sw         $t9, 0x4($v1)
    /* 1B2BDC 802C642C AC700000 */  sw         $s0, 0x0($v1)
    /* 1B2BE0 802C6430 3C1E802C */  lui        $fp, %hi(D_1B1FB0_802C76C4)
    /* 1B2BE4 802C6434 26310008 */  addiu      $s1, $s1, 0x8
    /* 1B2BE8 802C6438 27DE76C4 */  addiu      $fp, $fp, %lo(D_1B1FB0_802C76C4)
    /* 1B2BEC 802C643C 8FB7004C */  lw         $s7, 0x4C($sp)
    /* 1B2BF0 802C6440 2416000A */  addiu      $s6, $zero, 0xA
    /* 1B2BF4 802C6444 0000A025 */  or         $s4, $zero, $zero
  .L1B1FB0_802C6448:
    /* 1B2BF8 802C6448 8FC20000 */  lw         $v0, 0x0($fp)
    /* 1B2BFC 802C644C 00149080 */  sll        $s2, $s4, 2
    /* 1B2C00 802C6450 02549021 */  addu       $s2, $s2, $s4
    /* 1B2C04 802C6454 104000BA */  beqz       $v0, .L1B1FB0_802C6740
    /* 1B2C08 802C6458 2841000A */   slti      $at, $v0, 0xA
    /* 1B2C0C 802C645C 1020000D */  beqz       $at, .L1B1FB0_802C6494
    /* 1B2C10 802C6460 00129080 */   sll       $s2, $s2, 2
    /* 1B2C14 802C6464 8EA90000 */  lw         $t1, 0x0($s5)
    /* 1B2C18 802C6468 00402825 */  or         $a1, $v0, $zero
    /* 1B2C1C 802C646C 24A50010 */  addiu      $a1, $a1, 0x10
    /* 1B2C20 802C6470 30A800FF */  andi       $t0, $a1, 0xFF
    /* 1B2C24 802C6474 02493821 */  addu       $a3, $s2, $t1
    /* 1B2C28 802C6478 24E70002 */  addiu      $a3, $a3, 0x2
    /* 1B2C2C 802C647C 01002825 */  or         $a1, $t0, $zero
    /* 1B2C30 802C6480 02202025 */  or         $a0, $s1, $zero
    /* 1B2C34 802C6484 0C0B1C6E */  jal        func_1B1FB0_802C71B8
    /* 1B2C38 802C6488 24060065 */   addiu     $a2, $zero, 0x65
    /* 1B2C3C 802C648C 1000001E */  b          .L1B1FB0_802C6508
    /* 1B2C40 802C6490 00408825 */   or        $s1, $v0, $zero
  .L1B1FB0_802C6494:
    /* 1B2C44 802C6494 0056001A */  div        $zero, $v0, $s6
    /* 1B2C48 802C6498 8EAB0000 */  lw         $t3, 0x0($s5)
    /* 1B2C4C 802C649C 0000B810 */  mfhi       $s7
    /* 1B2C50 802C64A0 02E02825 */  or         $a1, $s7, $zero
    /* 1B2C54 802C64A4 24A50010 */  addiu      $a1, $a1, 0x10
    /* 1B2C58 802C64A8 16C00002 */  bnez       $s6, .L1B1FB0_802C64B4
    /* 1B2C5C 802C64AC 00000000 */   nop
    /* 1B2C60 802C64B0 0007000D */  break      7
  .L1B1FB0_802C64B4:
    /* 1B2C64 802C64B4 2401FFFF */  addiu      $at, $zero, -0x1
    /* 1B2C68 802C64B8 16C10004 */  bne        $s6, $at, .L1B1FB0_802C64CC
    /* 1B2C6C 802C64BC 3C018000 */   lui       $at, (0x80000000 >> 16)
    /* 1B2C70 802C64C0 14410002 */  bne        $v0, $at, .L1B1FB0_802C64CC
    /* 1B2C74 802C64C4 00000000 */   nop
    /* 1B2C78 802C64C8 0006000D */  break      6
  .L1B1FB0_802C64CC:
    /* 1B2C7C 802C64CC 30AA00FF */  andi       $t2, $a1, 0xFF
    /* 1B2C80 802C64D0 024B3821 */  addu       $a3, $s2, $t3
    /* 1B2C84 802C64D4 24E70002 */  addiu      $a3, $a3, 0x2
    /* 1B2C88 802C64D8 01402825 */  or         $a1, $t2, $zero
    /* 1B2C8C 802C64DC 02202025 */  or         $a0, $s1, $zero
    /* 1B2C90 802C64E0 0C0B1C6E */  jal        func_1B1FB0_802C71B8
    /* 1B2C94 802C64E4 2406006A */   addiu     $a2, $zero, 0x6A
    /* 1B2C98 802C64E8 8EAC0000 */  lw         $t4, 0x0($s5)
    /* 1B2C9C 802C64EC 00402025 */  or         $a0, $v0, $zero
    /* 1B2CA0 802C64F0 24050011 */  addiu      $a1, $zero, 0x11
    /* 1B2CA4 802C64F4 024C3821 */  addu       $a3, $s2, $t4
    /* 1B2CA8 802C64F8 24E70002 */  addiu      $a3, $a3, 0x2
    /* 1B2CAC 802C64FC 0C0B1C6E */  jal        func_1B1FB0_802C71B8
    /* 1B2CB0 802C6500 24060060 */   addiu     $a2, $zero, 0x60
    /* 1B2CB4 802C6504 00408825 */  or         $s1, $v0, $zero
  .L1B1FB0_802C6508:
    /* 1B2CB8 802C6508 8FC20000 */  lw         $v0, 0x0($fp)
    /* 1B2CBC 802C650C 3C0E801D */  lui        $t6, %hi(D_801CB418 + 0x1FC)
    /* 1B2CC0 802C6510 00026880 */  sll        $t5, $v0, 2
    /* 1B2CC4 802C6514 01CD7021 */  addu       $t6, $t6, $t5
    /* 1B2CC8 802C6518 8DCEB614 */  lw         $t6, %lo(D_801CB418 + 0x1FC)($t6)
    /* 1B2CCC 802C651C 55C00089 */  bnel       $t6, $zero, .L1B1FB0_802C6744
    /* 1B2CD0 802C6520 26940001 */   addiu     $s4, $s4, 0x1
    /* 1B2CD4 802C6524 8EA80000 */  lw         $t0, 0x0($s5)
    /* 1B2CD8 802C6528 00027940 */  sll        $t7, $v0, 5
    /* 1B2CDC 802C652C 3C19801D */  lui        $t9, %hi(D_801CB418)
    /* 1B2CE0 802C6530 2739B418 */  addiu      $t9, $t9, %lo(D_801CB418)
    /* 1B2CE4 802C6534 25F8FFE0 */  addiu      $t8, $t7, -0x20
    /* 1B2CE8 802C6538 02484821 */  addu       $t1, $s2, $t0
    /* 1B2CEC 802C653C 03199821 */  addu       $s3, $t8, $t9
    /* 1B2CF0 802C6540 252A0002 */  addiu      $t2, $t1, 0x2
    /* 1B2CF4 802C6544 AFAA0010 */  sw         $t2, 0x10($sp)
    /* 1B2CF8 802C6548 2665000E */  addiu      $a1, $s3, 0xE
    /* 1B2CFC 802C654C 02202025 */  or         $a0, $s1, $zero
    /* 1B2D00 802C6550 24060010 */  addiu      $a2, $zero, 0x10
    /* 1B2D04 802C6554 0C0B1CC1 */  jal        func_1B1FB0_802C7304
    /* 1B2D08 802C6558 2407009F */   addiu     $a3, $zero, 0x9F
    /* 1B2D0C 802C655C 826B000A */  lb         $t3, 0xA($s3)
    /* 1B2D10 802C6560 00408825 */  or         $s1, $v0, $zero
    /* 1B2D14 802C6564 02202025 */  or         $a0, $s1, $zero
    /* 1B2D18 802C6568 51600016 */  beql       $t3, $zero, .L1B1FB0_802C65C4
    /* 1B2D1C 802C656C 8E700000 */   lw        $s0, 0x0($s3)
    /* 1B2D20 802C6570 3C06802C */  lui        $a2, %hi(D_802C7718)
    /* 1B2D24 802C6574 8CC67718 */  lw         $a2, %lo(D_802C7718)($a2)
    /* 1B2D28 802C6578 8EAD0000 */  lw         $t5, 0x0($s5)
    /* 1B2D2C 802C657C 2405003C */  addiu      $a1, $zero, 0x3C
    /* 1B2D30 802C6580 00066100 */  sll        $t4, $a2, 4
    /* 1B2D34 802C6584 024D3821 */  addu       $a3, $s2, $t5
    /* 1B2D38 802C6588 24E70002 */  addiu      $a3, $a3, 0x2
    /* 1B2D3C 802C658C 0C0B1C6E */  jal        func_1B1FB0_802C71B8
    /* 1B2D40 802C6590 2586009F */   addiu     $a2, $t4, 0x9F
    /* 1B2D44 802C6594 3C06802C */  lui        $a2, %hi(D_802C7718)
    /* 1B2D48 802C6598 8CC67718 */  lw         $a2, %lo(D_802C7718)($a2)
    /* 1B2D4C 802C659C 8EAF0000 */  lw         $t7, 0x0($s5)
    /* 1B2D50 802C65A0 00402025 */  or         $a0, $v0, $zero
    /* 1B2D54 802C65A4 00067100 */  sll        $t6, $a2, 4
    /* 1B2D58 802C65A8 024F3821 */  addu       $a3, $s2, $t7
    /* 1B2D5C 802C65AC 24E70002 */  addiu      $a3, $a3, 0x2
    /* 1B2D60 802C65B0 25C600AF */  addiu      $a2, $t6, 0xAF
    /* 1B2D64 802C65B4 0C0B1C6E */  jal        func_1B1FB0_802C71B8
    /* 1B2D68 802C65B8 9265000A */   lbu       $a1, 0xA($s3)
    /* 1B2D6C 802C65BC 00408825 */  or         $s1, $v0, $zero
    /* 1B2D70 802C65C0 8E700000 */  lw         $s0, 0x0($s3)
  .L1B1FB0_802C65C4:
    /* 1B2D74 802C65C4 8EA90000 */  lw         $t1, 0x0($s5)
    /* 1B2D78 802C65C8 02202025 */  or         $a0, $s1, $zero
    /* 1B2D7C 802C65CC 261000FF */  addiu      $s0, $s0, 0xFF
    /* 1B2D80 802C65D0 0010C202 */  srl        $t8, $s0, 8
    /* 1B2D84 802C65D4 0316001A */  div        $zero, $t8, $s6
    /* 1B2D88 802C65D8 03008025 */  or         $s0, $t8, $zero
    /* 1B2D8C 802C65DC 0000C810 */  mfhi       $t9
    /* 1B2D90 802C65E0 27250010 */  addiu      $a1, $t9, 0x10
    /* 1B2D94 802C65E4 30A800FF */  andi       $t0, $a1, 0xFF
    /* 1B2D98 802C65E8 16C00002 */  bnez       $s6, .L1B1FB0_802C65F4
    /* 1B2D9C 802C65EC 00000000 */   nop
    /* 1B2DA0 802C65F0 0007000D */  break      7
  .L1B1FB0_802C65F4:
    /* 1B2DA4 802C65F4 2401FFFF */  addiu      $at, $zero, -0x1
    /* 1B2DA8 802C65F8 16C10004 */  bne        $s6, $at, .L1B1FB0_802C660C
    /* 1B2DAC 802C65FC 3C018000 */   lui       $at, (0x80000000 >> 16)
    /* 1B2DB0 802C6600 16010002 */  bne        $s0, $at, .L1B1FB0_802C660C
    /* 1B2DB4 802C6604 00000000 */   nop
    /* 1B2DB8 802C6608 0006000D */  break      6
  .L1B1FB0_802C660C:
    /* 1B2DBC 802C660C 02493821 */  addu       $a3, $s2, $t1
    /* 1B2DC0 802C6610 24E70002 */  addiu      $a3, $a3, 0x2
    /* 1B2DC4 802C6614 01002825 */  or         $a1, $t0, $zero
    /* 1B2DC8 802C6618 0C0B1C6E */  jal        func_1B1FB0_802C71B8
    /* 1B2DCC 802C661C 2406021A */   addiu     $a2, $zero, 0x21A
    /* 1B2DD0 802C6620 2A01000A */  slti       $at, $s0, 0xA
    /* 1B2DD4 802C6624 14200023 */  bnez       $at, .L1B1FB0_802C66B4
    /* 1B2DD8 802C6628 00408825 */   or        $s1, $v0, $zero
    /* 1B2DDC 802C662C 0216001A */  div        $zero, $s0, $s6
    /* 1B2DE0 802C6630 00001012 */  mflo       $v0
    /* 1B2DE4 802C6634 8EAC0000 */  lw         $t4, 0x0($s5)
    /* 1B2DE8 802C6638 16C00002 */  bnez       $s6, .L1B1FB0_802C6644
    /* 1B2DEC 802C663C 00000000 */   nop
    /* 1B2DF0 802C6640 0007000D */  break      7
  .L1B1FB0_802C6644:
    /* 1B2DF4 802C6644 2401FFFF */  addiu      $at, $zero, -0x1
    /* 1B2DF8 802C6648 16C10004 */  bne        $s6, $at, .L1B1FB0_802C665C
    /* 1B2DFC 802C664C 3C018000 */   lui       $at, (0x80000000 >> 16)
    /* 1B2E00 802C6650 16010002 */  bne        $s0, $at, .L1B1FB0_802C665C
    /* 1B2E04 802C6654 00000000 */   nop
    /* 1B2E08 802C6658 0006000D */  break      6
  .L1B1FB0_802C665C:
    /* 1B2E0C 802C665C 0056001A */  div        $zero, $v0, $s6
    /* 1B2E10 802C6660 00005010 */  mfhi       $t2
    /* 1B2E14 802C6664 25450010 */  addiu      $a1, $t2, 0x10
    /* 1B2E18 802C6668 30AB00FF */  andi       $t3, $a1, 0xFF
    /* 1B2E1C 802C666C 024C3821 */  addu       $a3, $s2, $t4
    /* 1B2E20 802C6670 0040B825 */  or         $s7, $v0, $zero
    /* 1B2E24 802C6674 24E70002 */  addiu      $a3, $a3, 0x2
    /* 1B2E28 802C6678 01602825 */  or         $a1, $t3, $zero
    /* 1B2E2C 802C667C 02202025 */  or         $a0, $s1, $zero
    /* 1B2E30 802C6680 16C00002 */  bnez       $s6, .L1B1FB0_802C668C
    /* 1B2E34 802C6684 00000000 */   nop
    /* 1B2E38 802C6688 0007000D */  break      7
  .L1B1FB0_802C668C:
    /* 1B2E3C 802C668C 2401FFFF */  addiu      $at, $zero, -0x1
    /* 1B2E40 802C6690 16C10004 */  bne        $s6, $at, .L1B1FB0_802C66A4
    /* 1B2E44 802C6694 3C018000 */   lui       $at, (0x80000000 >> 16)
    /* 1B2E48 802C6698 14410002 */  bne        $v0, $at, .L1B1FB0_802C66A4
    /* 1B2E4C 802C669C 00000000 */   nop
    /* 1B2E50 802C66A0 0006000D */  break      6
  .L1B1FB0_802C66A4:
    /* 1B2E54 802C66A4 2406020A */  addiu      $a2, $zero, 0x20A
    /* 1B2E58 802C66A8 0C0B1C6E */  jal        func_1B1FB0_802C71B8
    /* 1B2E5C 802C66AC 00000000 */   nop
    /* 1B2E60 802C66B0 00408825 */  or         $s1, $v0, $zero
  .L1B1FB0_802C66B4:
    /* 1B2E64 802C66B4 2A010064 */  slti       $at, $s0, 0x64
    /* 1B2E68 802C66B8 54200022 */  bnel       $at, $zero, .L1B1FB0_802C6744
    /* 1B2E6C 802C66BC 26940001 */   addiu     $s4, $s4, 0x1
    /* 1B2E70 802C66C0 02F6001A */  div        $zero, $s7, $s6
    /* 1B2E74 802C66C4 16C00002 */  bnez       $s6, .L1B1FB0_802C66D0
    /* 1B2E78 802C66C8 00000000 */   nop
    /* 1B2E7C 802C66CC 0007000D */  break      7
  .L1B1FB0_802C66D0:
    /* 1B2E80 802C66D0 2401FFFF */  addiu      $at, $zero, -0x1
    /* 1B2E84 802C66D4 16C10004 */  bne        $s6, $at, .L1B1FB0_802C66E8
    /* 1B2E88 802C66D8 3C018000 */   lui       $at, (0x80000000 >> 16)
    /* 1B2E8C 802C66DC 16E10002 */  bne        $s7, $at, .L1B1FB0_802C66E8
    /* 1B2E90 802C66E0 00000000 */   nop
    /* 1B2E94 802C66E4 0006000D */  break      6
  .L1B1FB0_802C66E8:
    /* 1B2E98 802C66E8 0000B812 */  mflo       $s7
    /* 1B2E9C 802C66EC 8EAF0000 */  lw         $t7, 0x0($s5)
    /* 1B2EA0 802C66F0 02202025 */  or         $a0, $s1, $zero
    /* 1B2EA4 802C66F4 02F6001A */  div        $zero, $s7, $s6
    /* 1B2EA8 802C66F8 00006810 */  mfhi       $t5
    /* 1B2EAC 802C66FC 25A50010 */  addiu      $a1, $t5, 0x10
    /* 1B2EB0 802C6700 30AE00FF */  andi       $t6, $a1, 0xFF
    /* 1B2EB4 802C6704 16C00002 */  bnez       $s6, .L1B1FB0_802C6710
    /* 1B2EB8 802C6708 00000000 */   nop
    /* 1B2EBC 802C670C 0007000D */  break      7
  .L1B1FB0_802C6710:
    /* 1B2EC0 802C6710 2401FFFF */  addiu      $at, $zero, -0x1
    /* 1B2EC4 802C6714 16C10004 */  bne        $s6, $at, .L1B1FB0_802C6728
    /* 1B2EC8 802C6718 3C018000 */   lui       $at, (0x80000000 >> 16)
    /* 1B2ECC 802C671C 16E10002 */  bne        $s7, $at, .L1B1FB0_802C6728
    /* 1B2ED0 802C6720 00000000 */   nop
    /* 1B2ED4 802C6724 0006000D */  break      6
  .L1B1FB0_802C6728:
    /* 1B2ED8 802C6728 024F3821 */  addu       $a3, $s2, $t7
    /* 1B2EDC 802C672C 24E70002 */  addiu      $a3, $a3, 0x2
    /* 1B2EE0 802C6730 01C02825 */  or         $a1, $t6, $zero
    /* 1B2EE4 802C6734 0C0B1C6E */  jal        func_1B1FB0_802C71B8
    /* 1B2EE8 802C6738 240601FA */   addiu     $a2, $zero, 0x1FA
    /* 1B2EEC 802C673C 00408825 */  or         $s1, $v0, $zero
  .L1B1FB0_802C6740:
    /* 1B2EF0 802C6740 26940001 */  addiu      $s4, $s4, 0x1
  .L1B1FB0_802C6744:
    /* 1B2EF4 802C6744 24010009 */  addiu      $at, $zero, 0x9
    /* 1B2EF8 802C6748 1681FF3F */  bne        $s4, $at, .L1B1FB0_802C6448
    /* 1B2EFC 802C674C 27DE0004 */   addiu     $fp, $fp, 0x4
    /* 1B2F00 802C6750 02201825 */  or         $v1, $s1, $zero
    /* 1B2F04 802C6754 AFB7004C */  sw         $s7, 0x4C($sp)
    /* 1B2F08 802C6758 3C190806 */  lui        $t9, %hi(D_80675B8)
    /* 1B2F0C 802C675C 273975B8 */  addiu      $t9, $t9, %lo(D_80675B8)
    /* 1B2F10 802C6760 26310008 */  addiu      $s1, $s1, 0x8
    /* 1B2F14 802C6764 3C180600 */  lui        $t8, (0x6000000 >> 16)
    /* 1B2F18 802C6768 AC780000 */  sw         $t8, 0x0($v1)
    /* 1B2F1C 802C676C AC790004 */  sw         $t9, 0x4($v1)
    /* 1B2F20 802C6770 02202025 */  or         $a0, $s1, $zero
    /* 1B2F24 802C6774 3C09009F */  lui        $t1, (0x9FC77C >> 16)
    /* 1B2F28 802C6778 3529C77C */  ori        $t1, $t1, (0x9FC77C & 0xFFFF)
    /* 1B2F2C 802C677C 3C08ED00 */  lui        $t0, (0xED000000 >> 16)
    /* 1B2F30 802C6780 AC880000 */  sw         $t0, 0x0($a0)
    /* 1B2F34 802C6784 AC890004 */  sw         $t1, 0x4($a0)
    /* 1B2F38 802C6788 8FBF0044 */  lw         $ra, 0x44($sp)
    /* 1B2F3C 802C678C 26220008 */  addiu      $v0, $s1, 0x8
    /* 1B2F40 802C6790 8FB10024 */  lw         $s1, 0x24($sp)
    /* 1B2F44 802C6794 8FBE0040 */  lw         $fp, 0x40($sp)
    /* 1B2F48 802C6798 8FB7003C */  lw         $s7, 0x3C($sp)
    /* 1B2F4C 802C679C 8FB60038 */  lw         $s6, 0x38($sp)
    /* 1B2F50 802C67A0 8FB50034 */  lw         $s5, 0x34($sp)
    /* 1B2F54 802C67A4 8FB40030 */  lw         $s4, 0x30($sp)
    /* 1B2F58 802C67A8 8FB3002C */  lw         $s3, 0x2C($sp)
    /* 1B2F5C 802C67AC 8FB20028 */  lw         $s2, 0x28($sp)
    /* 1B2F60 802C67B0 8FB00020 */  lw         $s0, 0x20($sp)
    /* 1B2F64 802C67B4 03E00008 */  jr         $ra
    /* 1B2F68 802C67B8 27BD0058 */   addiu     $sp, $sp, 0x58
endlabel func_1B1FB0_802C62E4
.size func_1B1FB0_802C62E4, . - func_1B1FB0_802C62E4

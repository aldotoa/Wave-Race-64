nonmatching func_801EE040, 0x1E8

glabel func_801EE040
    /* BC670 801EE040 44867000 */  mtc1       $a2, $fa1
    /* BC674 801EE044 27BDFF90 */  addiu      $sp, $sp, -0x70
    /* BC678 801EE048 F7B40010 */  sdc1       $fs0, 0x10($sp)
    /* BC67C 801EE04C 460E7082 */  mul.s      $fv1, $fa1, $fa1
    /* BC680 801EE050 4487A000 */  mtc1       $a3, $fs0
    /* BC684 801EE054 F7B60018 */  sdc1       $fs1, 0x18($sp)
    /* BC688 801EE058 C7B60080 */  lwc1       $fs1, 0x80($sp)
    /* BC68C 801EE05C 4614A482 */  mul.s      $ft5, $fs0, $fs0
    /* BC690 801EE060 F7BA0028 */  sdc1       $fs3, 0x28($sp)
    /* BC694 801EE064 AFBF0034 */  sw         $ra, 0x34($sp)
    /* BC698 801EE068 4616B682 */  mul.s      $fs3, $fs1, $fs1
    /* BC69C 801EE06C F7B80020 */  sdc1       $fs2, 0x20($sp)
    /* BC6A0 801EE070 AFA50074 */  sw         $a1, 0x74($sp)
    /* BC6A4 801EE074 E7A20040 */  swc1       $fv1, 0x40($sp)
    /* BC6A8 801EE078 E7B2003C */  swc1       $ft5, 0x3C($sp)
    /* BC6AC 801EE07C 46121100 */  add.s      $ft0, $fv1, $ft5
    /* BC6B0 801EE080 AFA40070 */  sw         $a0, 0x70($sp)
    /* BC6B4 801EE084 E7AE0078 */  swc1       $fa1, 0x78($sp)
    /* BC6B8 801EE088 0C031C04 */  jal        sqrtf
    /* BC6BC 801EE08C 461A2300 */   add.s     $fa0, $ft0, $fs3
    /* BC6C0 801EE090 44803000 */  mtc1       $zero, $ft1
    /* BC6C4 801EE094 3C013F80 */  lui        $at, (0x3F800000 >> 16)
    /* BC6C8 801EE098 44816000 */  mtc1       $at, $fa0
    /* BC6CC 801EE09C 4600303C */  c.lt.s     $ft1, $fv0
    /* BC6D0 801EE0A0 8FA40070 */  lw         $a0, 0x70($sp)
    /* BC6D4 801EE0A4 C7A20040 */  lwc1       $fv1, 0x40($sp)
    /* BC6D8 801EE0A8 C7AE0078 */  lwc1       $fa1, 0x78($sp)
    /* BC6DC 801EE0AC 45000009 */  bc1f       .L801EE0D4
    /* BC6E0 801EE0B0 C7B2003C */   lwc1      $ft5, 0x3C($sp)
    /* BC6E4 801EE0B4 46007383 */  div.s      $fa1, $fa1, $fv0
    /* BC6E8 801EE0B8 4600A503 */  div.s      $fs0, $fs0, $fv0
    /* BC6EC 801EE0BC 460E7082 */  mul.s      $fv1, $fa1, $fa1
    /* BC6F0 801EE0C0 4600B583 */  div.s      $fs1, $fs1, $fv0
    /* BC6F4 801EE0C4 4614A482 */  mul.s      $ft5, $fs0, $fs0
    /* BC6F8 801EE0C8 00000000 */  nop
    /* BC6FC 801EE0CC 4616B682 */  mul.s      $fs3, $fs1, $fs1
    /* BC700 801EE0D0 00000000 */  nop
  .L801EE0D4:
    /* BC704 801EE0D4 3C0143B4 */  lui        $at, (0x43B40000 >> 16)
    /* BC708 801EE0D8 44815000 */  mtc1       $at, $ft3
    /* BC70C 801EE0DC C7A80074 */  lwc1       $ft2, 0x74($sp)
    /* BC710 801EE0E0 3C014580 */  lui        $at, (0x45800000 >> 16)
    /* BC714 801EE0E4 44813000 */  mtc1       $at, $ft1
    /* BC718 801EE0E8 460A4103 */  div.s      $ft0, $ft2, $ft3
    /* BC71C 801EE0EC 3C038015 */  lui        $v1, %hi(gSinTable)
    /* BC720 801EE0F0 24634350 */  addiu      $v1, $v1, %lo(gSinTable)
    /* BC724 801EE0F4 44800000 */  mtc1       $zero, $fv0
    /* BC728 801EE0F8 3C013F80 */  lui        $at, (0x3F800000 >> 16)
    /* BC72C 801EE0FC 46062202 */  mul.s      $ft2, $ft0, $ft1
    /* BC730 801EE100 46026181 */  sub.s      $ft1, $fa0, $fv1
    /* BC734 801EE104 4600428D */  trunc.w.s  $ft3, $ft2
    /* BC738 801EE108 44025000 */  mfc1       $v0, $ft3
    /* BC73C 801EE10C 00000000 */  nop
    /* BC740 801EE110 24480400 */  addiu      $t0, $v0, 0x400
    /* BC744 801EE114 31090FFF */  andi       $t1, $t0, 0xFFF
    /* BC748 801EE118 00095080 */  sll        $t2, $t1, 2
    /* BC74C 801EE11C 006A5821 */  addu       $t3, $v1, $t2
    /* BC750 801EE120 C5780000 */  lwc1       $fs2, 0x0($t3)
    /* BC754 801EE124 304F0FFF */  andi       $t7, $v0, 0xFFF
    /* BC758 801EE128 000FC080 */  sll        $t8, $t7, 2
    /* BC75C 801EE12C 46183202 */  mul.s      $ft2, $ft1, $fs2
    /* BC760 801EE130 0078C821 */  addu       $t9, $v1, $t8
    /* BC764 801EE134 C7240000 */  lwc1       $ft0, 0x0($t9)
    /* BC768 801EE138 E7A4006C */  swc1       $ft0, 0x6C($sp)
    /* BC76C 801EE13C 44812000 */  mtc1       $at, $ft0
    /* BC770 801EE140 46024280 */  add.s      $ft3, $ft2, $fv1
    /* BC774 801EE144 4616A202 */  mul.s      $ft2, $fs0, $fs1
    /* BC778 801EE148 E4800030 */  swc1       $fv0, 0x30($a0)
    /* BC77C 801EE14C 46182181 */  sub.s      $ft1, $ft0, $fs2
    /* BC780 801EE150 E4800034 */  swc1       $fv0, 0x34($a0)
    /* BC784 801EE154 E4800038 */  swc1       $fv0, 0x38($a0)
    /* BC788 801EE158 E480000C */  swc1       $fv0, 0xC($a0)
    /* BC78C 801EE15C E480001C */  swc1       $fv0, 0x1C($a0)
    /* BC790 801EE160 E480002C */  swc1       $fv0, 0x2C($a0)
    /* BC794 801EE164 E48C003C */  swc1       $fa0, 0x3C($a0)
    /* BC798 801EE168 E48A0000 */  swc1       $ft3, 0x0($a0)
    /* BC79C 801EE16C 46064002 */  mul.s      $fv0, $ft2, $ft1
    /* BC7A0 801EE170 C7AA006C */  lwc1       $ft3, 0x6C($sp)
    /* BC7A4 801EE174 E7A60040 */  swc1       $ft1, 0x40($sp)
    /* BC7A8 801EE178 44813000 */  mtc1       $at, $ft1
    /* BC7AC 801EE17C 460A7302 */  mul.s      $fa0, $fa1, $ft3
    /* BC7B0 801EE180 46123281 */  sub.s      $ft3, $ft1, $ft5
    /* BC7B4 801EE184 460C0101 */  sub.s      $ft0, $fv0, $fa0
    /* BC7B8 801EE188 46006200 */  add.s      $ft2, $fa0, $fv0
    /* BC7BC 801EE18C E4840024 */  swc1       $ft0, 0x24($a0)
    /* BC7C0 801EE190 46185102 */  mul.s      $ft0, $ft3, $fs2
    /* BC7C4 801EE194 E4880018 */  swc1       $ft2, 0x18($a0)
    /* BC7C8 801EE198 46122200 */  add.s      $ft2, $ft0, $ft5
    /* BC7CC 801EE19C E4880014 */  swc1       $ft2, 0x14($a0)
    /* BC7D0 801EE1A0 C7A6006C */  lwc1       $ft1, 0x6C($sp)
    /* BC7D4 801EE1A4 C7A40040 */  lwc1       $ft0, 0x40($sp)
    /* BC7D8 801EE1A8 4606A402 */  mul.s      $ft4, $fs0, $ft1
    /* BC7DC 801EE1AC 00000000 */  nop
    /* BC7E0 801EE1B0 460EB282 */  mul.s      $ft3, $fs1, $fa1
    /* BC7E4 801EE1B4 00000000 */  nop
    /* BC7E8 801EE1B8 46045082 */  mul.s      $fv1, $ft3, $ft0
    /* BC7EC 801EE1BC 44815000 */  mtc1       $at, $ft3
    /* BC7F0 801EE1C0 00000000 */  nop
    /* BC7F4 801EE1C4 461A5101 */  sub.s      $ft0, $ft3, $fs3
    /* BC7F8 801EE1C8 46028200 */  add.s      $ft2, $ft4, $fv1
    /* BC7FC 801EE1CC 46101181 */  sub.s      $ft1, $fv1, $ft4
    /* BC800 801EE1D0 E4880020 */  swc1       $ft2, 0x20($a0)
    /* BC804 801EE1D4 46182202 */  mul.s      $ft2, $ft0, $fs2
    /* BC808 801EE1D8 E4860008 */  swc1       $ft1, 0x8($a0)
    /* BC80C 801EE1DC 46147282 */  mul.s      $ft3, $fa1, $fs0
    /* BC810 801EE1E0 461A4180 */  add.s      $ft1, $ft2, $fs3
    /* BC814 801EE1E4 E4860028 */  swc1       $ft1, 0x28($a0)
    /* BC818 801EE1E8 C7A40040 */  lwc1       $ft0, 0x40($sp)
    /* BC81C 801EE1EC C7A8006C */  lwc1       $ft2, 0x6C($sp)
    /* BC820 801EE1F0 46045002 */  mul.s      $fv0, $ft3, $ft0
    /* BC824 801EE1F4 00000000 */  nop
    /* BC828 801EE1F8 4608B082 */  mul.s      $fv1, $fs1, $ft2
    /* BC82C 801EE1FC 46020181 */  sub.s      $ft1, $fv0, $fv1
    /* BC830 801EE200 46001280 */  add.s      $ft3, $fv1, $fv0
    /* BC834 801EE204 E4860010 */  swc1       $ft1, 0x10($a0)
    /* BC838 801EE208 E48A0004 */  swc1       $ft3, 0x4($a0)
    /* BC83C 801EE20C 8FBF0034 */  lw         $ra, 0x34($sp)
    /* BC840 801EE210 D7BA0028 */  ldc1       $fs3, 0x28($sp)
    /* BC844 801EE214 D7B80020 */  ldc1       $fs2, 0x20($sp)
    /* BC848 801EE218 D7B60018 */  ldc1       $fs1, 0x18($sp)
    /* BC84C 801EE21C D7B40010 */  ldc1       $fs0, 0x10($sp)
    /* BC850 801EE220 03E00008 */  jr         $ra
    /* BC854 801EE224 27BD0070 */   addiu     $sp, $sp, 0x70
endlabel func_801EE040
.size func_801EE040, . - func_801EE040

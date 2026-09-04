nonmatching func_801EA0B0, 0x33C

glabel func_801EA0B0
    /* B86E0 801EA0B0 3C038023 */  lui        $v1, %hi(D_80228A78)
    /* B86E4 801EA0B4 24638A78 */  addiu      $v1, $v1, %lo(D_80228A78)
    /* B86E8 801EA0B8 84620002 */  lh         $v0, 0x2($v1)
    /* B86EC 801EA0BC 24010001 */  addiu      $at, $zero, 0x1
    /* B86F0 801EA0C0 5040000A */  beql       $v0, $zero, .L801EA0EC
    /* B86F4 801EA0C4 8C6E0004 */   lw        $t6, 0x4($v1)
    /* B86F8 801EA0C8 10410036 */  beq        $v0, $at, .L801EA1A4
    /* B86FC 801EA0CC 24010002 */   addiu     $at, $zero, 0x2
    /* B8700 801EA0D0 10410064 */  beq        $v0, $at, .L801EA264
    /* B8704 801EA0D4 24010003 */   addiu     $at, $zero, 0x3
    /* B8708 801EA0D8 50410094 */  beql       $v0, $at, .L801EA32C
    /* B870C 801EA0DC 8C620008 */   lw        $v0, 0x8($v1)
    /* B8710 801EA0E0 03E00008 */  jr         $ra
    /* B8714 801EA0E4 00000000 */   nop
    /* B8718 801EA0E8 8C6E0004 */  lw         $t6, 0x4($v1)
  .L801EA0EC:
    /* B871C 801EA0EC 8C6F0008 */  lw         $t7, 0x8($v1)
    /* B8720 801EA0F0 3C01437F */  lui        $at, (0x437F0000 >> 16)
    /* B8724 801EA0F4 448E2000 */  mtc1       $t6, $ft0
    /* B8728 801EA0F8 44814000 */  mtc1       $at, $ft2
    /* B872C 801EA0FC 448F8000 */  mtc1       $t7, $ft4
    /* B8730 801EA100 468021A0 */  cvt.s.w    $ft1, $ft0
    /* B8734 801EA104 24190001 */  addiu      $t9, $zero, 0x1
    /* B8738 801EA108 3C014F00 */  lui        $at, (0x4F000000 >> 16)
    /* B873C 801EA10C 468084A0 */  cvt.s.w    $ft5, $ft4
    /* B8740 801EA110 46083282 */  mul.s      $ft3, $ft1, $ft2
    /* B8744 801EA114 46125103 */  div.s      $ft0, $ft3, $ft5
    /* B8748 801EA118 4458F800 */  cfc1       $t8, $31
    /* B874C 801EA11C 44D9F800 */  ctc1       $t9, $31
    /* B8750 801EA120 00000000 */  nop
    /* B8754 801EA124 460021A4 */  cvt.w.s    $ft1, $ft0
    /* B8758 801EA128 4459F800 */  cfc1       $t9, $31
    /* B875C 801EA12C 00000000 */  nop
    /* B8760 801EA130 33390078 */  andi       $t9, $t9, 0x78
    /* B8764 801EA134 53200013 */  beql       $t9, $zero, .L801EA184
    /* B8768 801EA138 44193000 */   mfc1      $t9, $ft1
    /* B876C 801EA13C 44813000 */  mtc1       $at, $ft1
    /* B8770 801EA140 24190001 */  addiu      $t9, $zero, 0x1
    /* B8774 801EA144 46062181 */  sub.s      $ft1, $ft0, $ft1
    /* B8778 801EA148 44D9F800 */  ctc1       $t9, $31
    /* B877C 801EA14C 00000000 */  nop
    /* B8780 801EA150 460031A4 */  cvt.w.s    $ft1, $ft1
    /* B8784 801EA154 4459F800 */  cfc1       $t9, $31
    /* B8788 801EA158 00000000 */  nop
    /* B878C 801EA15C 33390078 */  andi       $t9, $t9, 0x78
    /* B8790 801EA160 17200005 */  bnez       $t9, .L801EA178
    /* B8794 801EA164 00000000 */   nop
    /* B8798 801EA168 44193000 */  mfc1       $t9, $ft1
    /* B879C 801EA16C 3C018000 */  lui        $at, (0x80000000 >> 16)
    /* B87A0 801EA170 10000007 */  b          .L801EA190
    /* B87A4 801EA174 0321C825 */   or        $t9, $t9, $at
  .L801EA178:
    /* B87A8 801EA178 10000005 */  b          .L801EA190
    /* B87AC 801EA17C 2419FFFF */   addiu     $t9, $zero, -0x1
    /* B87B0 801EA180 44193000 */  mfc1       $t9, $ft1
  .L801EA184:
    /* B87B4 801EA184 00000000 */  nop
    /* B87B8 801EA188 0720FFFB */  bltz       $t9, .L801EA178
    /* B87BC 801EA18C 00000000 */   nop
  .L801EA190:
    /* B87C0 801EA190 44D8F800 */  ctc1       $t8, $31
    /* B87C4 801EA194 A479000C */  sh         $t9, 0xC($v1)
    /* B87C8 801EA198 A460000E */  sh         $zero, 0xE($v1)
    /* B87CC 801EA19C 03E00008 */  jr         $ra
    /* B87D0 801EA1A0 A4600010 */   sh        $zero, 0x10($v1)
  .L801EA1A4:
    /* B87D4 801EA1A4 8C690004 */  lw         $t1, 0x4($v1)
    /* B87D8 801EA1A8 8C6A0008 */  lw         $t2, 0x8($v1)
    /* B87DC 801EA1AC 3C01437F */  lui        $at, (0x437F0000 >> 16)
    /* B87E0 801EA1B0 44894000 */  mtc1       $t1, $ft2
    /* B87E4 801EA1B4 44815000 */  mtc1       $at, $ft3
    /* B87E8 801EA1B8 448A2000 */  mtc1       $t2, $ft0
    /* B87EC 801EA1BC 46804420 */  cvt.s.w    $ft4, $ft2
    /* B87F0 801EA1C0 240C0001 */  addiu      $t4, $zero, 0x1
    /* B87F4 801EA1C4 240800FF */  addiu      $t0, $zero, 0xFF
    /* B87F8 801EA1C8 A468000C */  sh         $t0, 0xC($v1)
    /* B87FC 801EA1CC 3C014F00 */  lui        $at, (0x4F000000 >> 16)
    /* B8800 801EA1D0 468021A0 */  cvt.s.w    $ft1, $ft0
    /* B8804 801EA1D4 460A8482 */  mul.s      $ft5, $ft4, $ft3
    /* B8808 801EA1D8 46069203 */  div.s      $ft2, $ft5, $ft1
    /* B880C 801EA1DC 444BF800 */  cfc1       $t3, $31
    /* B8810 801EA1E0 44CCF800 */  ctc1       $t4, $31
    /* B8814 801EA1E4 00000000 */  nop
    /* B8818 801EA1E8 46004424 */  cvt.w.s    $ft4, $ft2
    /* B881C 801EA1EC 444CF800 */  cfc1       $t4, $31
    /* B8820 801EA1F0 00000000 */  nop
    /* B8824 801EA1F4 318C0078 */  andi       $t4, $t4, 0x78
    /* B8828 801EA1F8 51800013 */  beql       $t4, $zero, .L801EA248
    /* B882C 801EA1FC 440C8000 */   mfc1      $t4, $ft4
    /* B8830 801EA200 44818000 */  mtc1       $at, $ft4
    /* B8834 801EA204 240C0001 */  addiu      $t4, $zero, 0x1
    /* B8838 801EA208 46104401 */  sub.s      $ft4, $ft2, $ft4
    /* B883C 801EA20C 44CCF800 */  ctc1       $t4, $31
    /* B8840 801EA210 00000000 */  nop
    /* B8844 801EA214 46008424 */  cvt.w.s    $ft4, $ft4
    /* B8848 801EA218 444CF800 */  cfc1       $t4, $31
    /* B884C 801EA21C 00000000 */  nop
    /* B8850 801EA220 318C0078 */  andi       $t4, $t4, 0x78
    /* B8854 801EA224 15800005 */  bnez       $t4, .L801EA23C
    /* B8858 801EA228 00000000 */   nop
    /* B885C 801EA22C 440C8000 */  mfc1       $t4, $ft4
    /* B8860 801EA230 3C018000 */  lui        $at, (0x80000000 >> 16)
    /* B8864 801EA234 10000007 */  b          .L801EA254
    /* B8868 801EA238 01816025 */   or        $t4, $t4, $at
  .L801EA23C:
    /* B886C 801EA23C 10000005 */  b          .L801EA254
    /* B8870 801EA240 240CFFFF */   addiu     $t4, $zero, -0x1
    /* B8874 801EA244 440C8000 */  mfc1       $t4, $ft4
  .L801EA248:
    /* B8878 801EA248 00000000 */  nop
    /* B887C 801EA24C 0580FFFB */  bltz       $t4, .L801EA23C
    /* B8880 801EA250 00000000 */   nop
  .L801EA254:
    /* B8884 801EA254 44CBF800 */  ctc1       $t3, $31
    /* B8888 801EA258 A46C000E */  sh         $t4, 0xE($v1)
    /* B888C 801EA25C 03E00008 */  jr         $ra
    /* B8890 801EA260 A4600010 */   sh        $zero, 0x10($v1)
  .L801EA264:
    /* B8894 801EA264 8C620008 */  lw         $v0, 0x8($v1)
    /* B8898 801EA268 8C6E0004 */  lw         $t6, 0x4($v1)
    /* B889C 801EA26C 3C01437F */  lui        $at, (0x437F0000 >> 16)
    /* B88A0 801EA270 44819000 */  mtc1       $at, $ft5
    /* B88A4 801EA274 004E7823 */  subu       $t7, $v0, $t6
    /* B88A8 801EA278 448F5000 */  mtc1       $t7, $ft3
    /* B88AC 801EA27C 44824000 */  mtc1       $v0, $ft2
    /* B88B0 801EA280 24190001 */  addiu      $t9, $zero, 0x1
    /* B88B4 801EA284 46805120 */  cvt.s.w    $ft0, $ft3
    /* B88B8 801EA288 240D00FF */  addiu      $t5, $zero, 0xFF
    /* B88BC 801EA28C A46D000C */  sh         $t5, 0xC($v1)
    /* B88C0 801EA290 3C014F00 */  lui        $at, (0x4F000000 >> 16)
    /* B88C4 801EA294 46804420 */  cvt.s.w    $ft4, $ft2
    /* B88C8 801EA298 46122182 */  mul.s      $ft1, $ft0, $ft5
    /* B88CC 801EA29C 46103283 */  div.s      $ft3, $ft1, $ft4
    /* B88D0 801EA2A0 4458F800 */  cfc1       $t8, $31
    /* B88D4 801EA2A4 44D9F800 */  ctc1       $t9, $31
    /* B88D8 801EA2A8 00000000 */  nop
    /* B88DC 801EA2AC 46005124 */  cvt.w.s    $ft0, $ft3
    /* B88E0 801EA2B0 4459F800 */  cfc1       $t9, $31
    /* B88E4 801EA2B4 00000000 */  nop
    /* B88E8 801EA2B8 33390078 */  andi       $t9, $t9, 0x78
    /* B88EC 801EA2BC 53200013 */  beql       $t9, $zero, .L801EA30C
    /* B88F0 801EA2C0 44192000 */   mfc1      $t9, $ft0
    /* B88F4 801EA2C4 44812000 */  mtc1       $at, $ft0
    /* B88F8 801EA2C8 24190001 */  addiu      $t9, $zero, 0x1
    /* B88FC 801EA2CC 46045101 */  sub.s      $ft0, $ft3, $ft0
    /* B8900 801EA2D0 44D9F800 */  ctc1       $t9, $31
    /* B8904 801EA2D4 00000000 */  nop
    /* B8908 801EA2D8 46002124 */  cvt.w.s    $ft0, $ft0
    /* B890C 801EA2DC 4459F800 */  cfc1       $t9, $31
    /* B8910 801EA2E0 00000000 */  nop
    /* B8914 801EA2E4 33390078 */  andi       $t9, $t9, 0x78
    /* B8918 801EA2E8 17200005 */  bnez       $t9, .L801EA300
    /* B891C 801EA2EC 00000000 */   nop
    /* B8920 801EA2F0 44192000 */  mfc1       $t9, $ft0
    /* B8924 801EA2F4 3C018000 */  lui        $at, (0x80000000 >> 16)
    /* B8928 801EA2F8 10000007 */  b          .L801EA318
    /* B892C 801EA2FC 0321C825 */   or        $t9, $t9, $at
  .L801EA300:
    /* B8930 801EA300 10000005 */  b          .L801EA318
    /* B8934 801EA304 2419FFFF */   addiu     $t9, $zero, -0x1
    /* B8938 801EA308 44192000 */  mfc1       $t9, $ft0
  .L801EA30C:
    /* B893C 801EA30C 00000000 */  nop
    /* B8940 801EA310 0720FFFB */  bltz       $t9, .L801EA300
    /* B8944 801EA314 00000000 */   nop
  .L801EA318:
    /* B8948 801EA318 44D8F800 */  ctc1       $t8, $31
    /* B894C 801EA31C A479000E */  sh         $t9, 0xE($v1)
    /* B8950 801EA320 03E00008 */  jr         $ra
    /* B8954 801EA324 A4600010 */   sh        $zero, 0x10($v1)
    /* B8958 801EA328 8C620008 */  lw         $v0, 0x8($v1)
  .L801EA32C:
    /* B895C 801EA32C 8C680004 */  lw         $t0, 0x4($v1)
    /* B8960 801EA330 3C01437F */  lui        $at, (0x437F0000 >> 16)
    /* B8964 801EA334 44813000 */  mtc1       $at, $ft1
    /* B8968 801EA338 00484823 */  subu       $t1, $v0, $t0
    /* B896C 801EA33C 44899000 */  mtc1       $t1, $ft5
    /* B8970 801EA340 44825000 */  mtc1       $v0, $ft3
    /* B8974 801EA344 240B0001 */  addiu      $t3, $zero, 0x1
    /* B8978 801EA348 46809220 */  cvt.s.w    $ft2, $ft5
    /* B897C 801EA34C 3C014F00 */  lui        $at, (0x4F000000 >> 16)
    /* B8980 801EA350 46805120 */  cvt.s.w    $ft0, $ft3
    /* B8984 801EA354 46064402 */  mul.s      $ft4, $ft2, $ft1
    /* B8988 801EA358 46048483 */  div.s      $ft5, $ft4, $ft0
    /* B898C 801EA35C 444AF800 */  cfc1       $t2, $31
    /* B8990 801EA360 44CBF800 */  ctc1       $t3, $31
    /* B8994 801EA364 00000000 */  nop
    /* B8998 801EA368 46009224 */  cvt.w.s    $ft2, $ft5
    /* B899C 801EA36C 444BF800 */  cfc1       $t3, $31
    /* B89A0 801EA370 00000000 */  nop
    /* B89A4 801EA374 316B0078 */  andi       $t3, $t3, 0x78
    /* B89A8 801EA378 51600013 */  beql       $t3, $zero, .L801EA3C8
    /* B89AC 801EA37C 440B4000 */   mfc1      $t3, $ft2
    /* B89B0 801EA380 44814000 */  mtc1       $at, $ft2
    /* B89B4 801EA384 240B0001 */  addiu      $t3, $zero, 0x1
    /* B89B8 801EA388 46089201 */  sub.s      $ft2, $ft5, $ft2
    /* B89BC 801EA38C 44CBF800 */  ctc1       $t3, $31
    /* B89C0 801EA390 00000000 */  nop
    /* B89C4 801EA394 46004224 */  cvt.w.s    $ft2, $ft2
    /* B89C8 801EA398 444BF800 */  cfc1       $t3, $31
    /* B89CC 801EA39C 00000000 */  nop
    /* B89D0 801EA3A0 316B0078 */  andi       $t3, $t3, 0x78
    /* B89D4 801EA3A4 15600005 */  bnez       $t3, .L801EA3BC
    /* B89D8 801EA3A8 00000000 */   nop
    /* B89DC 801EA3AC 440B4000 */  mfc1       $t3, $ft2
    /* B89E0 801EA3B0 3C018000 */  lui        $at, (0x80000000 >> 16)
    /* B89E4 801EA3B4 10000007 */  b          .L801EA3D4
    /* B89E8 801EA3B8 01615825 */   or        $t3, $t3, $at
  .L801EA3BC:
    /* B89EC 801EA3BC 10000005 */  b          .L801EA3D4
    /* B89F0 801EA3C0 240BFFFF */   addiu     $t3, $zero, -0x1
    /* B89F4 801EA3C4 440B4000 */  mfc1       $t3, $ft2
  .L801EA3C8:
    /* B89F8 801EA3C8 00000000 */  nop
    /* B89FC 801EA3CC 0560FFFB */  bltz       $t3, .L801EA3BC
    /* B8A00 801EA3D0 00000000 */   nop
  .L801EA3D4:
    /* B8A04 801EA3D4 44CAF800 */  ctc1       $t2, $31
    /* B8A08 801EA3D8 A46B000C */  sh         $t3, 0xC($v1)
    /* B8A0C 801EA3DC A460000E */  sh         $zero, 0xE($v1)
    /* B8A10 801EA3E0 A4600010 */  sh         $zero, 0x10($v1)
    /* B8A14 801EA3E4 03E00008 */  jr         $ra
    /* B8A18 801EA3E8 00000000 */   nop
endlabel func_801EA0B0
.size func_801EA0B0, . - func_801EA0B0

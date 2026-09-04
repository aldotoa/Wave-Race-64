nonmatching func_801E0FF0, 0x1C4

glabel func_801E0FF0
    /* AF620 801E0FF0 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* AF624 801E0FF4 AFBF0034 */  sw         $ra, 0x34($sp)
    /* AF628 801E0FF8 AFB00030 */  sw         $s0, 0x30($sp)
    /* AF62C 801E0FFC F7B80028 */  sdc1       $fs2, 0x28($sp)
    /* AF630 801E1000 F7B60020 */  sdc1       $fs1, 0x20($sp)
    /* AF634 801E1004 F7B40018 */  sdc1       $fs0, 0x18($sp)
    /* AF638 801E1008 C486004C */  lwc1       $ft1, 0x4C($a0)
    /* AF63C 801E100C C484007C */  lwc1       $ft0, 0x7C($a0)
    /* AF640 801E1010 C48A0050 */  lwc1       $ft3, 0x50($a0)
    /* AF644 801E1014 C4880080 */  lwc1       $ft2, 0x80($a0)
    /* AF648 801E1018 46062001 */  sub.s      $fv0, $ft0, $ft1
    /* AF64C 801E101C C4860054 */  lwc1       $ft1, 0x54($a0)
    /* AF650 801E1020 C4840084 */  lwc1       $ft0, 0x84($a0)
    /* AF654 801E1024 460A4081 */  sub.s      $fv1, $ft2, $ft3
    /* AF658 801E1028 46000202 */  mul.s      $ft2, $fv0, $fv0
    /* AF65C 801E102C 00808025 */  or         $s0, $a0, $zero
    /* AF660 801E1030 46062381 */  sub.s      $fa1, $ft0, $ft1
    /* AF664 801E1034 46021282 */  mul.s      $ft3, $fv1, $fv1
    /* AF668 801E1038 E4800064 */  swc1       $fv0, 0x64($a0)
    /* AF66C 801E103C E4820068 */  swc1       $fv1, 0x68($a0)
    /* AF670 801E1040 460E7182 */  mul.s      $ft1, $fa1, $fa1
    /* AF674 801E1044 E48E006C */  swc1       $fa1, 0x6C($a0)
    /* AF678 801E1048 460A4100 */  add.s      $ft0, $ft2, $ft3
    /* AF67C 801E104C 0C031C04 */  jal        sqrtf
    /* AF680 801E1050 46062300 */   add.s     $fa0, $ft0, $ft1
    /* AF684 801E1054 C6080064 */  lwc1       $ft2, 0x64($s0)
    /* AF688 801E1058 C6040068 */  lwc1       $ft0, 0x68($s0)
    /* AF68C 801E105C 46004283 */  div.s      $ft3, $ft2, $fv0
    /* AF690 801E1060 C608006C */  lwc1       $ft2, 0x6C($s0)
    /* AF694 801E1064 46002183 */  div.s      $ft1, $ft0, $fv0
    /* AF698 801E1068 E60A0064 */  swc1       $ft3, 0x64($s0)
    /* AF69C 801E106C C6020064 */  lwc1       $fv1, 0x64($s0)
    /* AF6A0 801E1070 46021102 */  mul.s      $ft0, $fv1, $fv1
    /* AF6A4 801E1074 46004283 */  div.s      $ft3, $ft2, $fv0
    /* AF6A8 801E1078 E6060068 */  swc1       $ft1, 0x68($s0)
    /* AF6AC 801E107C E60A006C */  swc1       $ft3, 0x6C($s0)
    /* AF6B0 801E1080 C60E006C */  lwc1       $fa1, 0x6C($s0)
    /* AF6B4 801E1084 460E7182 */  mul.s      $ft1, $fa1, $fa1
    /* AF6B8 801E1088 0C031C04 */  jal        sqrtf
    /* AF6BC 801E108C 46062300 */   add.s     $fa0, $ft0, $ft1
    /* AF6C0 801E1090 C60E006C */  lwc1       $fa1, 0x6C($s0)
    /* AF6C4 801E1094 C6020064 */  lwc1       $fv1, 0x64($s0)
    /* AF6C8 801E1098 C6180068 */  lwc1       $fs2, 0x68($s0)
    /* AF6CC 801E109C 46007283 */  div.s      $ft3, $fa1, $fv0
    /* AF6D0 801E10A0 C6120070 */  lwc1       $ft5, 0x70($s0)
    /* AF6D4 801E10A4 C6140074 */  lwc1       $fs0, 0x74($s0)
    /* AF6D8 801E10A8 C6160078 */  lwc1       $fs1, 0x78($s0)
    /* AF6DC 801E10AC 46021102 */  mul.s      $ft0, $fv1, $fv1
    /* AF6E0 801E10B0 00000000 */  nop
    /* AF6E4 801E10B4 4618C182 */  mul.s      $ft1, $fs2, $fs2
    /* AF6E8 801E10B8 46001203 */  div.s      $ft2, $fv1, $fv0
    /* AF6EC 801E10BC E60A00F4 */  swc1       $ft3, 0xF4($s0)
    /* AF6F0 801E10C0 460E7282 */  mul.s      $ft3, $fa1, $fa1
    /* AF6F4 801E10C4 E60800F0 */  swc1       $ft2, 0xF0($s0)
    /* AF6F8 801E10C8 46062200 */  add.s      $ft2, $ft0, $ft1
    /* AF6FC 801E10CC 46121102 */  mul.s      $ft0, $fv1, $ft5
    /* AF700 801E10D0 00000000 */  nop
    /* AF704 801E10D4 4614C182 */  mul.s      $ft1, $fs2, $fs0
    /* AF708 801E10D8 460A4400 */  add.s      $ft4, $ft2, $ft3
    /* AF70C 801E10DC 46167282 */  mul.s      $ft3, $fa1, $fs1
    /* AF710 801E10E0 46062200 */  add.s      $ft2, $ft0, $ft1
    /* AF714 801E10E4 460A4100 */  add.s      $ft0, $ft2, $ft3
    /* AF718 801E10E8 46002187 */  neg.s      $ft1, $ft0
    /* AF71C 801E10EC 46103403 */  div.s      $ft4, $ft1, $ft4
    /* AF720 801E10F0 46101202 */  mul.s      $ft2, $fv1, $ft4
    /* AF724 801E10F4 46089280 */  add.s      $ft3, $ft5, $ft2
    /* AF728 801E10F8 4610C102 */  mul.s      $ft0, $fs2, $ft4
    /* AF72C 801E10FC E60A0070 */  swc1       $ft3, 0x70($s0)
    /* AF730 801E1100 46107202 */  mul.s      $ft2, $fa1, $ft4
    /* AF734 801E1104 C6120070 */  lwc1       $ft5, 0x70($s0)
    /* AF738 801E1108 4604A180 */  add.s      $ft1, $fs0, $ft0
    /* AF73C 801E110C 46129102 */  mul.s      $ft0, $ft5, $ft5
    /* AF740 801E1110 4608B280 */  add.s      $ft3, $fs1, $ft2
    /* AF744 801E1114 E6060074 */  swc1       $ft1, 0x74($s0)
    /* AF748 801E1118 C6140074 */  lwc1       $fs0, 0x74($s0)
    /* AF74C 801E111C E60A0078 */  swc1       $ft3, 0x78($s0)
    /* AF750 801E1120 4614A182 */  mul.s      $ft1, $fs0, $fs0
    /* AF754 801E1124 C6160078 */  lwc1       $fs1, 0x78($s0)
    /* AF758 801E1128 4616B282 */  mul.s      $ft3, $fs1, $fs1
    /* AF75C 801E112C 46062200 */  add.s      $ft2, $ft0, $ft1
    /* AF760 801E1130 0C031C04 */  jal        sqrtf
    /* AF764 801E1134 460A4300 */   add.s     $fa0, $ft2, $ft3
    /* AF768 801E1138 C6040070 */  lwc1       $ft0, 0x70($s0)
    /* AF76C 801E113C C6080074 */  lwc1       $ft2, 0x74($s0)
    /* AF770 801E1140 46002183 */  div.s      $ft1, $ft0, $fv0
    /* AF774 801E1144 C6040078 */  lwc1       $ft0, 0x78($s0)
    /* AF778 801E1148 46004283 */  div.s      $ft3, $ft2, $fv0
    /* AF77C 801E114C E6060070 */  swc1       $ft1, 0x70($s0)
    /* AF780 801E1150 C608004C */  lwc1       $ft2, 0x4C($s0)
    /* AF784 801E1154 46002183 */  div.s      $ft1, $ft0, $fv0
    /* AF788 801E1158 E60A0074 */  swc1       $ft3, 0x74($s0)
    /* AF78C 801E115C C60A007C */  lwc1       $ft3, 0x7C($s0)
    /* AF790 801E1160 C6040054 */  lwc1       $ft0, 0x54($s0)
    /* AF794 801E1164 460A4081 */  sub.s      $fv1, $ft2, $ft3
    /* AF798 801E1168 46021202 */  mul.s      $ft2, $fv1, $fv1
    /* AF79C 801E116C E6060078 */  swc1       $ft1, 0x78($s0)
    /* AF7A0 801E1170 C6060084 */  lwc1       $ft1, 0x84($s0)
    /* AF7A4 801E1174 46062381 */  sub.s      $fa1, $ft0, $ft1
    /* AF7A8 801E1178 460E7282 */  mul.s      $ft3, $fa1, $fa1
    /* AF7AC 801E117C 0C031C04 */  jal        sqrtf
    /* AF7B0 801E1180 460A4300 */   add.s     $fa0, $ft2, $ft3
    /* AF7B4 801E1184 C6040050 */  lwc1       $ft0, 0x50($s0)
    /* AF7B8 801E1188 C6060080 */  lwc1       $ft1, 0x80($s0)
    /* AF7BC 801E118C E600008C */  swc1       $fv0, 0x8C($s0)
    /* AF7C0 801E1190 46062201 */  sub.s      $ft2, $ft0, $ft1
    /* AF7C4 801E1194 E6080090 */  swc1       $ft2, 0x90($s0)
    /* AF7C8 801E1198 8FBF0034 */  lw         $ra, 0x34($sp)
    /* AF7CC 801E119C 8FB00030 */  lw         $s0, 0x30($sp)
    /* AF7D0 801E11A0 D7B80028 */  ldc1       $fs2, 0x28($sp)
    /* AF7D4 801E11A4 D7B60020 */  ldc1       $fs1, 0x20($sp)
    /* AF7D8 801E11A8 D7B40018 */  ldc1       $fs0, 0x18($sp)
    /* AF7DC 801E11AC 03E00008 */  jr         $ra
    /* AF7E0 801E11B0 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel func_801E0FF0
.size func_801E0FF0, . - func_801E0FF0

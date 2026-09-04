nonmatching func_1B1FB0_802C6970, 0x2AC

glabel func_1B1FB0_802C6970
    /* 1B3120 802C6970 27BDFF98 */  addiu      $sp, $sp, -0x68
    /* 1B3124 802C6974 3C0E802C */  lui        $t6, %hi(D_1B1FB0_802C7660)
    /* 1B3128 802C6978 8DCE7660 */  lw         $t6, %lo(D_1B1FB0_802C7660)($t6)
    /* 1B312C 802C697C AFB00008 */  sw         $s0, 0x8($sp)
    /* 1B3130 802C6980 AFBF002C */  sw         $ra, 0x2C($sp)
    /* 1B3134 802C6984 AFB70024 */  sw         $s7, 0x24($sp)
    /* 1B3138 802C6988 AFB40018 */  sw         $s4, 0x18($sp)
    /* 1B313C 802C698C AFB30014 */  sw         $s3, 0x14($sp)
    /* 1B3140 802C6990 3C10802C */  lui        $s0, %hi(D_1B1FB0_802C7664)
    /* 1B3144 802C6994 000E7880 */  sll        $t7, $t6, 2
    /* 1B3148 802C6998 AFBE0028 */  sw         $fp, 0x28($sp)
    /* 1B314C 802C699C AFB60020 */  sw         $s6, 0x20($sp)
    /* 1B3150 802C69A0 AFB5001C */  sw         $s5, 0x1C($sp)
    /* 1B3154 802C69A4 AFB20010 */  sw         $s2, 0x10($sp)
    /* 1B3158 802C69A8 020F8021 */  addu       $s0, $s0, $t7
    /* 1B315C 802C69AC 3C13FD68 */  lui        $s3, (0xFD680167 >> 16)
    /* 1B3160 802C69B0 3C140708 */  lui        $s4, (0x7080200 >> 16)
    /* 1B3164 802C69B4 3C170759 */  lui        $s7, (0x759C01C >> 16)
    /* 1B3168 802C69B8 3C1F0008 */  lui        $ra, (0x80200 >> 16)
    /* 1B316C 802C69BC 24180043 */  addiu      $t8, $zero, 0x43
    /* 1B3170 802C69C0 2419003B */  addiu      $t9, $zero, 0x3B
    /* 1B3174 802C69C4 3C0DF568 */  lui        $t5, (0xF5685A00 >> 16)
    /* 1B3178 802C69C8 AFB1000C */  sw         $s1, 0xC($sp)
    /* 1B317C 802C69CC 35AD5A00 */  ori        $t5, $t5, (0xF5685A00 & 0xFFFF)
    /* 1B3180 802C69D0 AFB90030 */  sw         $t9, 0x30($sp)
    /* 1B3184 802C69D4 AFB80034 */  sw         $t8, 0x34($sp)
    /* 1B3188 802C69D8 37FF0200 */  ori        $ra, $ra, (0x80200 & 0xFFFF)
    /* 1B318C 802C69DC 36F7C01C */  ori        $s7, $s7, (0x759C01C & 0xFFFF)
    /* 1B3190 802C69E0 36940200 */  ori        $s4, $s4, (0x7080200 & 0xFFFF)
    /* 1B3194 802C69E4 36730167 */  ori        $s3, $s3, (0xFD680167 & 0xFFFF)
    /* 1B3198 802C69E8 8E107664 */  lw         $s0, %lo(D_1B1FB0_802C7664)($s0)
    /* 1B319C 802C69EC 2412004B */  addiu      $s2, $zero, 0x4B
    /* 1B31A0 802C69F0 3C15E600 */  lui        $s5, (0xE6000000 >> 16)
    /* 1B31A4 802C69F4 3C16F400 */  lui        $s6, (0xF4000000 >> 16)
    /* 1B31A8 802C69F8 3C1EE700 */  lui        $fp, (0xE7000000 >> 16)
  .L1B1FB0_802C69FC:
    /* 1B31AC 802C69FC 00801025 */  or         $v0, $a0, $zero
    /* 1B31B0 802C6A00 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B31B4 802C6A04 00801825 */  or         $v1, $a0, $zero
    /* 1B31B8 802C6A08 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B31BC 802C6A0C AC530000 */  sw         $s3, 0x0($v0)
    /* 1B31C0 802C6A10 AC500004 */  sw         $s0, 0x4($v0)
    /* 1B31C4 802C6A14 00802825 */  or         $a1, $a0, $zero
    /* 1B31C8 802C6A18 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B31CC 802C6A1C AC740004 */  sw         $s4, 0x4($v1)
    /* 1B31D0 802C6A20 AC6D0000 */  sw         $t5, 0x0($v1)
    /* 1B31D4 802C6A24 00803025 */  or         $a2, $a0, $zero
    /* 1B31D8 802C6A28 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B31DC 802C6A2C ACA00004 */  sw         $zero, 0x4($a1)
    /* 1B31E0 802C6A30 ACB50000 */  sw         $s5, 0x0($a1)
    /* 1B31E4 802C6A34 00803825 */  or         $a3, $a0, $zero
    /* 1B31E8 802C6A38 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B31EC 802C6A3C ACD70004 */  sw         $s7, 0x4($a2)
    /* 1B31F0 802C6A40 ACD60000 */  sw         $s6, 0x0($a2)
    /* 1B31F4 802C6A44 00804025 */  or         $t0, $a0, $zero
    /* 1B31F8 802C6A48 ACE00004 */  sw         $zero, 0x4($a3)
    /* 1B31FC 802C6A4C ACFE0000 */  sw         $fp, 0x0($a3)
    /* 1B3200 802C6A50 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3204 802C6A54 00804825 */  or         $t1, $a0, $zero
    /* 1B3208 802C6A58 AD1F0004 */  sw         $ra, 0x4($t0)
    /* 1B320C 802C6A5C AD0D0000 */  sw         $t5, 0x0($t0)
    /* 1B3210 802C6A60 3C0F0059 */  lui        $t7, (0x59C01C >> 16)
    /* 1B3214 802C6A64 35EFC01C */  ori        $t7, $t7, (0x59C01C & 0xFFFF)
    /* 1B3218 802C6A68 3C0EF200 */  lui        $t6, (0xF2000000 >> 16)
    /* 1B321C 802C6A6C AD2E0000 */  sw         $t6, 0x0($t1)
    /* 1B3220 802C6A70 AD2F0004 */  sw         $t7, 0x4($t1)
    /* 1B3224 802C6A74 8FB10034 */  lw         $s1, 0x34($sp)
    /* 1B3228 802C6A78 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B322C 802C6A7C 3C01E47D */  lui        $at, (0xE47D0000 >> 16)
    /* 1B3230 802C6A80 0011C080 */  sll        $t8, $s1, 2
    /* 1B3234 802C6A84 33190FFF */  andi       $t9, $t8, 0xFFF
    /* 1B3238 802C6A88 03217025 */  or         $t6, $t9, $at
    /* 1B323C 802C6A8C 00805025 */  or         $t2, $a0, $zero
    /* 1B3240 802C6A90 AD4E0000 */  sw         $t6, 0x0($t2)
    /* 1B3244 802C6A94 8FAF0030 */  lw         $t7, 0x30($sp)
    /* 1B3248 802C6A98 03008825 */  or         $s1, $t8, $zero
    /* 1B324C 802C6A9C 3C010023 */  lui        $at, (0x230000 >> 16)
    /* 1B3250 802C6AA0 000FC080 */  sll        $t8, $t7, 2
    /* 1B3254 802C6AA4 33190FFF */  andi       $t9, $t8, 0xFFF
    /* 1B3258 802C6AA8 03217025 */  or         $t6, $t9, $at
    /* 1B325C 802C6AAC 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3260 802C6AB0 00805825 */  or         $t3, $a0, $zero
    /* 1B3264 802C6AB4 AD4E0004 */  sw         $t6, 0x4($t2)
    /* 1B3268 802C6AB8 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B326C 802C6ABC 00806025 */  or         $t4, $a0, $zero
    /* 1B3270 802C6AC0 3C0FB300 */  lui        $t7, (0xB3000000 >> 16)
    /* 1B3274 802C6AC4 AD6F0000 */  sw         $t7, 0x0($t3)
    /* 1B3278 802C6AC8 AD600004 */  sw         $zero, 0x4($t3)
    /* 1B327C 802C6ACC 3C190400 */  lui        $t9, (0x4000400 >> 16)
    /* 1B3280 802C6AD0 37390400 */  ori        $t9, $t9, (0x4000400 & 0xFFFF)
    /* 1B3284 802C6AD4 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3288 802C6AD8 3C18B200 */  lui        $t8, (0xB2000000 >> 16)
    /* 1B328C 802C6ADC 00801025 */  or         $v0, $a0, $zero
    /* 1B3290 802C6AE0 AD980000 */  sw         $t8, 0x0($t4)
    /* 1B3294 802C6AE4 AD990004 */  sw         $t9, 0x4($t4)
    /* 1B3298 802C6AE8 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B329C 802C6AEC 00801825 */  or         $v1, $a0, $zero
    /* 1B32A0 802C6AF0 26100B40 */  addiu      $s0, $s0, 0xB40
    /* 1B32A4 802C6AF4 AC500004 */  sw         $s0, 0x4($v0)
    /* 1B32A8 802C6AF8 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B32AC 802C6AFC AC530000 */  sw         $s3, 0x0($v0)
    /* 1B32B0 802C6B00 00802825 */  or         $a1, $a0, $zero
    /* 1B32B4 802C6B04 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B32B8 802C6B08 AC740004 */  sw         $s4, 0x4($v1)
    /* 1B32BC 802C6B0C AC6D0000 */  sw         $t5, 0x0($v1)
    /* 1B32C0 802C6B10 00803025 */  or         $a2, $a0, $zero
    /* 1B32C4 802C6B14 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B32C8 802C6B18 ACA00004 */  sw         $zero, 0x4($a1)
    /* 1B32CC 802C6B1C ACB50000 */  sw         $s5, 0x0($a1)
    /* 1B32D0 802C6B20 00803825 */  or         $a3, $a0, $zero
    /* 1B32D4 802C6B24 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B32D8 802C6B28 ACD70004 */  sw         $s7, 0x4($a2)
    /* 1B32DC 802C6B2C ACD60000 */  sw         $s6, 0x0($a2)
    /* 1B32E0 802C6B30 00804025 */  or         $t0, $a0, $zero
    /* 1B32E4 802C6B34 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B32E8 802C6B38 ACE00004 */  sw         $zero, 0x4($a3)
    /* 1B32EC 802C6B3C ACFE0000 */  sw         $fp, 0x0($a3)
    /* 1B32F0 802C6B40 00804825 */  or         $t1, $a0, $zero
    /* 1B32F4 802C6B44 AD1F0004 */  sw         $ra, 0x4($t0)
    /* 1B32F8 802C6B48 AD0D0000 */  sw         $t5, 0x0($t0)
    /* 1B32FC 802C6B4C 0012C080 */  sll        $t8, $s2, 2
    /* 1B3300 802C6B50 3C0F0059 */  lui        $t7, (0x59C01C >> 16)
    /* 1B3304 802C6B54 3C0EF200 */  lui        $t6, (0xF2000000 >> 16)
    /* 1B3308 802C6B58 AD2E0000 */  sw         $t6, 0x0($t1)
    /* 1B330C 802C6B5C 35EFC01C */  ori        $t7, $t7, (0x59C01C & 0xFFFF)
    /* 1B3310 802C6B60 33190FFF */  andi       $t9, $t8, 0xFFF
    /* 1B3314 802C6B64 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3318 802C6B68 3C01E47D */  lui        $at, (0xE47D0000 >> 16)
    /* 1B331C 802C6B6C 03217025 */  or         $t6, $t9, $at
    /* 1B3320 802C6B70 00805025 */  or         $t2, $a0, $zero
    /* 1B3324 802C6B74 AD2F0004 */  sw         $t7, 0x4($t1)
    /* 1B3328 802C6B78 322F0FFF */  andi       $t7, $s1, 0xFFF
    /* 1B332C 802C6B7C 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3330 802C6B80 3C010023 */  lui        $at, (0x230000 >> 16)
    /* 1B3334 802C6B84 01E1C025 */  or         $t8, $t7, $at
    /* 1B3338 802C6B88 00805825 */  or         $t3, $a0, $zero
    /* 1B333C 802C6B8C AD4E0000 */  sw         $t6, 0x0($t2)
    /* 1B3340 802C6B90 AD580004 */  sw         $t8, 0x4($t2)
    /* 1B3344 802C6B94 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3348 802C6B98 3C19B300 */  lui        $t9, (0xB3000000 >> 16)
    /* 1B334C 802C6B9C AD790000 */  sw         $t9, 0x0($t3)
    /* 1B3350 802C6BA0 00806025 */  or         $t4, $a0, $zero
    /* 1B3354 802C6BA4 AD600004 */  sw         $zero, 0x4($t3)
    /* 1B3358 802C6BA8 3C0F0400 */  lui        $t7, (0x4000400 >> 16)
    /* 1B335C 802C6BAC 35EF0400 */  ori        $t7, $t7, (0x4000400 & 0xFFFF)
    /* 1B3360 802C6BB0 3C0EB200 */  lui        $t6, (0xB2000000 >> 16)
    /* 1B3364 802C6BB4 AD8E0000 */  sw         $t6, 0x0($t4)
    /* 1B3368 802C6BB8 AD8F0004 */  sw         $t7, 0x4($t4)
    /* 1B336C 802C6BBC 8FAE0030 */  lw         $t6, 0x30($sp)
    /* 1B3370 802C6BC0 8FB80034 */  lw         $t8, 0x34($sp)
    /* 1B3374 802C6BC4 2401008B */  addiu      $at, $zero, 0x8B
    /* 1B3378 802C6BC8 26520010 */  addiu      $s2, $s2, 0x10
    /* 1B337C 802C6BCC 25CF0010 */  addiu      $t7, $t6, 0x10
    /* 1B3380 802C6BD0 27190010 */  addiu      $t9, $t8, 0x10
    /* 1B3384 802C6BD4 AFB90034 */  sw         $t9, 0x34($sp)
    /* 1B3388 802C6BD8 AFAF0030 */  sw         $t7, 0x30($sp)
    /* 1B338C 802C6BDC 24840008 */  addiu      $a0, $a0, 0x8
    /* 1B3390 802C6BE0 1641FF86 */  bne        $s2, $at, .L1B1FB0_802C69FC
    /* 1B3394 802C6BE4 26100B40 */   addiu     $s0, $s0, 0xB40
    /* 1B3398 802C6BE8 8FBF002C */  lw         $ra, 0x2C($sp)
    /* 1B339C 802C6BEC 8FB00008 */  lw         $s0, 0x8($sp)
    /* 1B33A0 802C6BF0 8FB1000C */  lw         $s1, 0xC($sp)
    /* 1B33A4 802C6BF4 8FB20010 */  lw         $s2, 0x10($sp)
    /* 1B33A8 802C6BF8 8FB30014 */  lw         $s3, 0x14($sp)
    /* 1B33AC 802C6BFC 8FB40018 */  lw         $s4, 0x18($sp)
    /* 1B33B0 802C6C00 8FB5001C */  lw         $s5, 0x1C($sp)
    /* 1B33B4 802C6C04 8FB60020 */  lw         $s6, 0x20($sp)
    /* 1B33B8 802C6C08 8FB70024 */  lw         $s7, 0x24($sp)
    /* 1B33BC 802C6C0C 8FBE0028 */  lw         $fp, 0x28($sp)
    /* 1B33C0 802C6C10 27BD0068 */  addiu      $sp, $sp, 0x68
    /* 1B33C4 802C6C14 03E00008 */  jr         $ra
    /* 1B33C8 802C6C18 00801025 */   or        $v0, $a0, $zero
endlabel func_1B1FB0_802C6970
.size func_1B1FB0_802C6970, . - func_1B1FB0_802C6970

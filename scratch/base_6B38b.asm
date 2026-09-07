00000000 <func_i1_802C6B38>:
   0:	3c020000 	lui	v0,0x0
			0: R_MIPS_HI16	gGameState
   4:	8c420000 	lw	v0,0(v0)
			4: R_MIPS_LO16	gGameState
   8:	2401002a 	li	at,42
   c:	3c0e0000 	lui	t6,0x0
			c: R_MIPS_HI16	D_801CE6F0
  10:	54410008 	bnel	v0,at,34 <func_i1_802C6B38+0x34>
  14:	24010029 	li	at,41
  18:	85ce0000 	lh	t6,0(t6)
			18: R_MIPS_LO16	D_801CE6F0
  1c:	24030001 	li	v1,1
  20:	146e001d 	bne	v1,t6,98 <func_i1_802C6B38+0x98>
  24:	00000000 	nop
  28:	03e00008 	jr	ra
  2c:	00801025 	move	v0,a0
  30:	24010029 	li	at,41
  34:	14410018 	bne	v0,at,98 <func_i1_802C6B38+0x98>
  38:	3c050000 	lui	a1,0x0
			38: R_MIPS_HI16	D_802C96A4
  3c:	24a50000 	addiu	a1,a1,0
			3c: R_MIPS_LO16	D_802C96A4
  40:	8ca20000 	lw	v0,0(a1)
  44:	24030001 	li	v1,1
  48:	3c0f0000 	lui	t7,0x0
			48: R_MIPS_HI16	D_801CE6F0
  4c:	2841001e 	slti	at,v0,30
  50:	10200008 	beqz	at,74 <func_i1_802C6B38+0x74>
  54:	24580001 	addiu	t8,v0,1
  58:	85ef0000 	lh	t7,0(t7)
			58: R_MIPS_LO16	D_801CE6F0
  5c:	24030001 	li	v1,1
  60:	3c010000 	lui	at,0x0
			60: R_MIPS_HI16	D_800D817C
  64:	146f0003 	bne	v1,t7,74 <func_i1_802C6B38+0x74>
  68:	ac230000 	sw	v1,0(at)
			68: R_MIPS_LO16	D_800D817C
  6c:	10000002 	b	78 <func_i1_802C6B38+0x78>
  70:	2b01003d 	slti	at,t8,61
  74:	2b01003d 	slti	at,t8,61
  78:	14200007 	bnez	at,98 <func_i1_802C6B38+0x98>
  7c:	acb80000 	sw	t8,0(a1)
  80:	3c020000 	lui	v0,0x0
			80: R_MIPS_HI16	D_802C96A0
  84:	24420000 	addiu	v0,v0,0
			84: R_MIPS_LO16	D_802C96A0
  88:	8c480000 	lw	t0,0(v0)
  8c:	15000002 	bnez	t0,98 <func_i1_802C6B38+0x98>
  90:	00000000 	nop
  94:	ac430000 	sw	v1,0(v0)
  98:	03e00008 	jr	ra

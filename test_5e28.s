	.verstamp	3 19
	.option	pic0
	.globl	D_i2_802C8BE0
	.rdata	
	.align	2
	.align	0
D_i2_802C8BE0:
	.word	3 : 1
	.word	1 : 1
	.extern	D_801CE63C 4
	.extern	gGameState 4
	.extern	D_801CE5F8 4
	.extern	D_802C8C50 2
	.extern	D_801CE608 24
	.extern	gSinTable 16384
	.globl	D_802C8C70
	.lcomm	D_802C8C70 8
	.extern	D_802C8C58 8
	.extern	D_802C8C68 2
	.extern	D_802C8C6A 2
	.extern	D_800DAB2C 4
	.extern	D_7000000 4
	.extern	D_2000A40 4
	.extern	D_106F808 4
	.extern	D_801CE60C 2
	.extern	D_802C8C5C 4
	.extern	D_80228A16 2
	.extern	D_i2_802C8BC0 4
	.extern	D_801CE630 4
	.extern	D_800D48DC 4
	.extern	D_800DA9B0 16
	.extern	D_800D96A4 336
	.extern	gCourseID 4
	.extern	D_7000A40 64
	.extern	D_7000A80 64
	.extern	D_7000AC0 64
	.extern	D_7000B00 64
	.extern	D_7000B40 64
	.extern	gPrevGameState 4
	.extern	D_801CE638 4
	.extern	D_801CE640 4
	.extern	D_801CE644 4
	.extern	D_800DAB1C 4
	.extern	D_800D461C 4
	.extern	D_800D48E0 4
	.extern	D_800DAB64 2
	.extern	D_801CB32C 4
	.extern	D_80228A32 2
	.extern	gPlayers 4
	.extern	D_800DAB60 2
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C5800
	.loc	3 4128
 #4128	void func_i2_802C5800(void) {
	.ent	func_i2_802C5800 2
func_i2_802C5800:
	.option	O2
	subu	$sp, 504
	sw	$31, 132($sp)
	sw	$30, 128($sp)
	sw	$23, 124($sp)
	sw	$22, 120($sp)
	sw	$21, 116($sp)
	sw	$20, 112($sp)
	sw	$19, 108($sp)
	sw	$18, 104($sp)
	sw	$17, 100($sp)
	sw	$16, 96($sp)
	s.d	$f28, 88($sp)
	s.d	$f26, 80($sp)
	s.d	$f24, 72($sp)
	s.d	$f22, 64($sp)
	s.d	$f20, 56($sp)
	.mask	0xC0FF0000, -372
	.fmask	0x3FF00000, -416
	.frame	$sp, 504, $31
	.loc	3 4128
	.loc	3 4140
 #4140	    if (D_801CE63C != 0) {
	lw	$14, D_801CE63C
	beq	$14, 0, $32
	.loc	3 4140
	.loc	3 4141
 #4141	        if (gGameState == GAME_STATE_RIDER_SELECT) {
	lw	$15, gGameState
	bne	$15, 10, $32
	.loc	3 4141
	.loc	3 4142
 #4142	            func_i2_802C5AE4();
	.livereg	0x0000000E,0x00000000
	jal	func_i2_802C5AE4
$32:
	li.s	$f26, 0.0
	li.s	$f28, 1.0
	.loc	3 4145
 #4143	        }
 #4144	    }
 #4145	    func_800481E0(D_801CE5F8->unkA40, &D_802C8C50, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
	lw	$4, D_801CE5F8
	addu	$4, $4, 2624
	la	$5, D_802C8C50
	li.s	$6, 33.0
	mfc1	$7, $f28
	li.s	$f4, 16.0
	s.s	$f4, 16($sp)
	li.s	$f6, 4096.0
	s.s	$f6, 20($sp)
	s.s	$f26, 24($sp)
	s.s	$f26, 28($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_800481E0
	.loc	3 4146
 #4146	    func_80048A88(&spE0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.07f);
	addu	$4, $sp, 224
	mfc1	$5, $f26
	mfc1	$6, $f26
	mfc1	$7, $f28
	s.s	$f26, 16($sp)
	s.s	$f28, 20($sp)
	s.s	$f26, 24($sp)
	s.s	$f26, 28($sp)
	s.s	$f26, 32($sp)
	s.s	$f26, 36($sp)
	li.s	$f8, 0.07
	s.s	$f8, 40($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80048A88
	.loc	3 4147
 #4147	    for (i = 0; i < 4; i++) {
	move	$17, $0
	move	$19, $0
	l.s	$f24, 484($sp)
	l.s	$f22, 488($sp)
	li.s	$f20, 500.0
	addu	$30, $sp, 160
	la	$23, D_801CE608
	addu	$22, $sp, 292
	addu	$21, $sp, 420
	addu	$20, $sp, 356
	la	$18, D_802C8C60
	la	$16, gSinTable
$33:
	.loc	3 4147
	.loc	3 4148
 #4148	        for (j = 0; j < D_801CE608.player; j++) {
	move	$4, $0
	.noalias	$23,$sp
	lh	$7, 4($23)
	ble	$7, 0, $38
	move	$5, $0
	la	$6, D_800DA9C0
$34:
	.loc	3 4148
	.loc	3 4149
 #4149	            cond = 0;
	move	$3, $0
	.loc	3 4150
 #4150	            if (i == D_800DA9C0[j]) {
	.noalias	$6,$23
	.noalias	$6,$sp
	lw	$24, 0($6)
	bne	$17, $24, $35
	.loc	3 4150
	.loc	3 4151
 #4151	                cond = 1;
	li	$3, 1
$35:
	.loc	3 4153
 #4152	            }
 #4153	            if (cond) {
	beq	$3, 0, $36
	.loc	3 4153
	.loc	3 4154
 #4154	                angle = D_802C8C60[j] % 0x1000;
	.noalias	$18,$6
	.noalias	$18,$23
	.noalias	$18,$sp
	addu	$25, $18, $5
	.noalias	$25,$6
	.noalias	$25,$23
	.noalias	$25,$sp
	lw	$2, 0($25)
	.alias	$25,$6
	.alias	$25,$23
	.alias	$25,$sp
	rem	$8, $2, 4096
	move	$2, $8
	.loc	3 4155
 #4155	                var_fs1 = gSinTable[(angle + 0x400) & 0xFFF] * 500.0f;
	.noalias	$16,$6
	.noalias	$16,$18
	.noalias	$16,$23
	.noalias	$16,$sp
	addu	$9, $2, 1024
	and	$10, $9, 4095
	mul	$11, $10, 4
	addu	$12, $16, $11
	.noalias	$12,$6
	.noalias	$12,$18
	.noalias	$12,$23
	.noalias	$12,$sp
	l.s	$f10, 0($12)
	.alias	$12,$6
	.alias	$12,$18
	.alias	$12,$23
	.alias	$12,$sp
	mul.s	$f22, $f10, $f20
	.loc	3 4156
 #4156	                var_fs2 = gSinTable[angle & 0xFFF] * 500.0f;
	and	$13, $2, 4095
	mul	$14, $13, 4
	addu	$15, $16, $14
	.noalias	$15,$6
	.noalias	$15,$18
	.noalias	$15,$23
	.noalias	$15,$sp
	l.s	$f16, 0($15)
	.alias	$15,$6
	.alias	$15,$18
	.alias	$15,$23
	.alias	$15,$sp
	mul.s	$f24, $f16, $f20
	b	$37
$36:
	.loc	3 4157
 #4157	            } else {
	.loc	3 4158
 #4158	                var_fs1 = gSinTable[0x600] * 500.0f;
	l.s	$f18, 6144($16)
	mul.s	$f22, $f18, $f20
	.loc	3 4159
 #4159	                var_fs2 = gSinTable[0x200] * 500.0f;
	l.s	$f4, 2048($16)
	mul.s	$f24, $f4, $f20
$37:
	.loc	3 4161
 #4160	            }
 #4161	            if (cond) {
	bne	$3, 0, $38
	.alias	$6,$16
	.alias	$6,$18
	.alias	$6,$23
	.alias	$6,$sp
	.loc	3 4161
	.loc	3 4162
 #4162	                break;
	.loc	3 4148
 #4148	        for (j = 0; j < D_801CE608.player; j++) {
	addu	$4, $4, 1
	addu	$5, $5, 4
	addu	$6, $6, 4
	blt	$4, $7, $34
$38:
	.loc	3 4165
 #4165	        func_800484C8(&spA0, &sp164, var_fs1, 500.0f, var_fs2, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	move	$4, $30
	move	$5, $20
	mfc1	$6, $f22
	mfc1	$7, $f20
	s.s	$f24, 16($sp)
	s.s	$f26, 20($sp)
	s.s	$f26, 24($sp)
	s.s	$f26, 28($sp)
	s.s	$f26, 32($sp)
	s.s	$f28, 36($sp)
	s.s	$f26, 40($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_800484C8
	.loc	3 4166
 #4166	        SysUtils_MtxToMtxF(&spE0, &sp1A4);
	addu	$4, $sp, 224
	move	$5, $21
	.livereg	0x0C00000E,0x00000000
	jal	SysUtils_MtxToMtxF
	.loc	3 4167
 #4167	        SysUtils_MatrixAffineMultiply(&sp164, &sp1A4, &sp124);
	move	$4, $20
	move	$5, $21
	move	$6, $22
	.livereg	0x0E00000E,0x00000000
	jal	SysUtils_MatrixAffineMultiply
	.loc	3 4168
 #4168	        SysUtils_MtxFToMtx(&sp124, &D_801CE5F8->unkA80[i]);
	move	$4, $22
	lw	$24, D_801CE5F8
	addu	$5, $24, $19
	addu	$5, $5, 2688
	.livereg	0x0C00000E,0x00000000
	jal	SysUtils_MtxFToMtx
	.loc	3 4147
 #4147	    for (i = 0; i < 4; i++) {
	addu	$17, $17, 1
	addu	$19, $19, 64
	blt	$17, 4, $33
	.alias	$16,$18
	.alias	$16,$23
	.alias	$16,$sp
	.alias	$18,$23
	.alias	$18,$sp
	s.s	$f24, 484($sp)
	s.s	$f22, 488($sp)
	.loc	3 4170
 #4170	    for (i = 0; i < D_801CE608.player; i++) {
	move	$17, $0
	lh	$7, 4($23)
	ble	$7, 0, $41
	.alias	$23,$sp
	la	$25, D_802C8C60
	move	$2, $25
	mul	$8, $7, 4
	addu	$4, $8, $25
$39:
	.loc	3 4170
	.loc	3 4171
 #4171	        D_802C8C60[i] += 0x30;
	.noalias	$2,$sp
	lw	$9, 0($2)
	addu	$10, $9, 48
	sw	$10, 0($2)
	.loc	3 4172
 #4172	        if (D_802C8C60[i] >= 0x1000) {
	lw	$3, 0($2)
	blt	$3, 4096, $40
	.loc	3 4172
	.loc	3 4173
 #4173	            D_802C8C60[i] -= 0x1000;
	addu	$11, $3, -4096
	sw	$11, 0($2)
$40:
	.loc	3 4170
 #4170	    for (i = 0; i < D_801CE608.player; i++) {
	addu	$2, $2, 4
	bltu	$2, $4, $39
	.alias	$2,$sp
	.loc	3 4176
 #4171	        D_802C8C60[i] += 0x30;
 #4172	        if (D_802C8C60[i] >= 0x1000) {
 #4173	            D_802C8C60[i] -= 0x1000;
 #4174	        }
 #4175	    }
 #4176	}
$41:
	.livereg	0x0000FF0E,0x00000FFF
	l.d	$f20, 56($sp)
	l.d	$f22, 64($sp)
	l.d	$f24, 72($sp)
	l.d	$f26, 80($sp)
	l.d	$f28, 88($sp)
	lw	$16, 96($sp)
	lw	$17, 100($sp)
	lw	$18, 104($sp)
	lw	$19, 108($sp)
	lw	$20, 112($sp)
	lw	$21, 116($sp)
	lw	$22, 120($sp)
	lw	$23, 124($sp)
	lw	$31, 132($sp)
	lw	$30, 128($sp)
	addu	$sp, 504
	j	$31
	.end	func_i2_802C5800
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C5AE4
	.loc	3 4192
 #4192	void func_i2_802C5AE4(void) {
	.ent	func_i2_802C5AE4 2
func_i2_802C5AE4:
	.option	O2
	.frame	$sp, 0, $31
	.loc	3 4192
	.loc	3 4194
 #4193	    s32 i;
 #4194	    for (i = 0; i < 2; i++) {
	move	$2, $0
	la	$3, D_802C8C58
	la	$4, D_802C8C60
	la	$5, D_801CE6F4
$42:
	.loc	3 4194
	.loc	3 4195
 #4195	        ((s32*) &D_802C8C58)[i] = 0;
	.noalias	$3,$sp
	sw	$0, 0($3)
	.loc	3 4196
 #4196	        D_802C8C60[i] = 0;
	.noalias	$4,$3
	.noalias	$4,$sp
	sw	$0, 0($4)
	.loc	3 4197
 #4197	        D_801CE6F4[i] = i;
	.noalias	$5,$3
	.noalias	$5,$4
	.noalias	$5,$sp
	sh	$2, 0($5)
	.loc	3 4194
 #4194	    for (i = 0; i < 2; i++) {
	addu	$2, $2, 1
	addu	$3, $3, 4
	addu	$4, $4, 4
	addu	$5, $5, 2
	blt	$2, 2, $42
	.alias	$3,$4
	.alias	$3,$5
	.alias	$3,$sp
	.alias	$4,$5
	.alias	$4,$sp
	.alias	$5,$sp
	.loc	3 4199
 #4195	        ((s32*) &D_802C8C58)[i] = 0;
 #4196	        D_802C8C60[i] = 0;
 #4197	        D_801CE6F4[i] = i;
 #4198	    }
 #4199	    for (i = 0; i < 4; i++) D_802C8C70[i] = 0;
	.loc	3 4199
	sh	$0, D_802C8C70
	.loc	3 4199
	sh	$0, D_802C8C70+2
	sh	$0, D_802C8C70+4
	sh	$0, D_802C8C70+6
	.loc	3 4200
 #4200	    D_802C8C68 = 0;
	sh	$0, D_802C8C68
	.loc	3 4201
 #4201	    D_802C8C6A = 0;
	sh	$0, D_802C8C6A
	.loc	3 4202
 #4202	}
	.livereg	0x0000FF0E,0x00000FFF
	j	$31
	.end	func_i2_802C5AE4
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C5B4C
	.loc	3 4262
 #4262	Gfx* func_i2_802C5B4C(Gfx* gdl) {
	.ent	func_i2_802C5B4C 2
func_i2_802C5B4C:
	.option	O2
	subu	$sp, 32
	sw	$31, 28($sp)
	sw	$16, 24($sp)
	.mask	0x80010000, -4
	.frame	$sp, 32, $31
	move	$16, $4
	la	$2, D_801CE63C
	.loc	3 4262
	.loc	3 4263
 #4263	    if (D_801CE63C != 0) {
	.noalias	$2,$sp
	lw	$14, 0($2)
	beq	$14, 0, $43
	.loc	3 4263
	.loc	3 4264
 #4264	        D_801CE63C = 0;
	sw	$0, 0($2)
	.loc	3 4265
 #4265	        if (gGameState == GAME_STATE_RIDER_SELECT) {
	lw	$15, gGameState
	bne	$15, 10, $43
	.alias	$2,$sp
	.loc	3 4265
	.loc	3 4266
 #4266	            return func_80093C44(gdl);
	move	$4, $16
	.livereg	0x0800000E,0x00000000
	jal	func_80093C44
	b	$56
$43:
	.loc	3 4269
 #4267	        }
 #4268	    }
 #4269	    D_800DAB2C = 0;
	sw	$0, D_800DAB2C
	.loc	3 4270
 #4270	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; };
	.loc	3 4270
	move	$2, $16
	addu	$16, $16, 8
	.loc	3 4270
	li	$24, -419430400
	sw	$24, 0($2)
	.loc	3 4270
	sw	$0, 4($2)
	.loc	3 4270
	.loc	3 4271
 #4271	    { Gfx *_g = (Gfx *)gdl++; _g->words.w0 = ((unsigned int) (((unsigned int)(0xed) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((int)((float)(8)*4.0F)) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((int)((float)(20)*4.0F)) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((int)((float)(311)*4.0F)) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((int)((float)(219)*4.0F)) & ((0x01 << (12)) - 1)) << (0))); };
	.loc	3 4271
	move	$3, $16
	addu	$16, $16, 8
	.loc	3 4271
	li	$25, -318635952
	sw	$25, 0($3)
	.loc	3 4271
	li	$8, 5096300
	sw	$8, 4($3)
	.loc	3 4271
	.loc	3 4272
 #4272	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_106FAF0); };
	.loc	3 4272
	move	$5, $16
	addu	$16, $16, 8
	.loc	3 4272
	li	$9, 100663296
	sw	$9, 0($5)
	.loc	3 4272
	la	$10, D_106FAF0
	sw	$10, 4($5)
	.loc	3 4272
	.loc	3 4273
 #4273	    gdl = func_i2_802C88DC(gdl);
	move	$4, $16
	.livereg	0x0800000E,0x00000000
	jal	func_i2_802C88DC
	.loc	3 4274
 #4274	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x01)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_7000000); };
	.loc	3 4274
	.loc	3 4274
	li	$11, 16973888
	sw	$11, 0($2)
	.loc	3 4274
	la	$12, D_7000000
	sw	$12, 4($2)
	.loc	3 4274
	.loc	3 4275
 #4275	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_2000A40); };
	.loc	3 4275
	.loc	3 4275
	li	$13, 16908352
	sw	$13, 8($2)
	.loc	3 4275
	la	$14, D_2000A40
	sw	$14, 12($2)
	.loc	3 4275
	.loc	3 4276
 #4276	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_106F808); };
	.loc	3 4276
	addu	$16, $2, 24
	.loc	3 4276
	li	$15, 100663296
	sw	$15, 16($2)
	.loc	3 4276
	la	$24, D_106F808
	sw	$24, 20($2)
	.loc	3 4276
	.loc	3 4277
 #4277	    if (D_801CE60C == 1) {
	lh	$25, D_801CE60C
	bne	$25, 1, $44
	.loc	3 4277
	.loc	3 4278
 #4278	        gdl = func_8009328C(gdl);
	move	$4, $16
	.livereg	0x0800000E,0x00000000
	jal	func_8009328C
	move	$16, $2
	b	$47
$44:
	.loc	3 4279
 #4279	    } else {
	.loc	3 4280
 #4280	        if (D_802C8C58.player_1_ready == 0) {
	lw	$8, D_802C8C58
	bne	$8, 0, $45
	.loc	3 4280
	.loc	3 4281
 #4281	            D_800DAB2C = 0;
	sw	$0, D_800DAB2C
	.loc	3 4282
 #4282	            gdl = func_800933C4(gdl);
	move	$4, $16
	.livereg	0x0800000E,0x00000000
	jal	func_800933C4
	move	$16, $2
$45:
	.loc	3 4284
 #4283	        }
 #4284	        if (D_802C8C5C == 0) {
	lw	$9, D_802C8C5C
	bne	$9, 0, $46
	.loc	3 4284
	.loc	3 4285
 #4285	            D_800DAB2C = 1;
	li	$10, 1
	sw	$10, D_800DAB2C
	.loc	3 4286
 #4286	            gdl = func_800933C4(gdl);
	move	$4, $16
	.livereg	0x0800000E,0x00000000
	jal	func_800933C4
	move	$16, $2
$46:
	.loc	3 4288
 #4287	        }
 #4288	        D_800DAB2C = 0;
	sw	$0, D_800DAB2C
$47:
	.loc	3 4290
 #4289	    }
 #4290	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; };
	.loc	3 4290
	move	$2, $16
	addu	$16, $16, 8
	.loc	3 4290
	li	$11, -419430400
	sw	$11, 0($2)
	.loc	3 4290
	sw	$0, 4($2)
	.loc	3 4290
	.loc	3 4291
 #4291	    { Gfx *_g = (Gfx *)gdl++; _g->words.w0 = ((unsigned int) (((unsigned int)(0xed) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((int)((float)(8)*4.0F)) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((int)((float)(20)*4.0F)) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((int)((float)(311)*4.0F)) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((int)((float)(219)*4.0F)) & ((0x01 << (12)) - 1)) << (0))); };
	.loc	3 4291
	move	$3, $16
	addu	$16, $16, 8
	.loc	3 4291
	li	$12, -318635952
	sw	$12, 0($3)
	.loc	3 4291
	li	$13, 5096300
	sw	$13, 4($3)
	.loc	3 4291
	.loc	3 4292
 #4292	    if (D_801CE60C == 1) {
	lh	$14, D_801CE60C
	bne	$14, 1, $48
	.loc	3 4292
	.loc	3 4293
 #4293	        gdl = func_i2_802C6ADC(gdl);
	move	$4, $16
	.livereg	0x0800000E,0x00000000
	jal	func_i2_802C6ADC
	.loc	3 4294
 #4294	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE500); };
	.loc	3 4294
	addu	$16, $2, 8
	.loc	3 4294
	li	$15, 100663296
	sw	$15, 0($2)
	.loc	3 4294
	la	$24, D_80BE500
	sw	$24, 4($2)
	.loc	3 4294
	b	$50
$48:
	.loc	3 4295
 #4295	    } else {
	.loc	3 4296
 #4296	        gdl = func_i2_802C7C50(gdl);
	move	$4, $16
	.livereg	0x0800000E,0x00000000
	jal	func_i2_802C7C50
	la	$4, D_802C8C58
	move	$16, $2
	.loc	3 4297
 #4297	        if (D_802C8C58.player_1_ready == 0) {
	.noalias	$4,$sp
	lw	$25, 0($4)
	bne	$25, 0, $49
	.loc	3 4297
	.loc	3 4298
 #4298	            { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE4A8); };
	.loc	3 4298
	move	$3, $2
	addu	$16, $2, 8
	.loc	3 4298
	li	$8, 100663296
	sw	$8, 0($3)
	.loc	3 4298
	la	$9, D_80BE4A8
	sw	$9, 4($3)
	.loc	3 4298
$49:
	.loc	3 4300
 #4299	        }
 #4300	        if (D_802C8C58.player_2_ready == 0) {
	lw	$10, 4($4)
	bne	$10, 0, $50
	.alias	$4,$sp
	.loc	3 4300
	.loc	3 4301
 #4301	            { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE500); };
	.loc	3 4301
	move	$2, $16
	addu	$16, $16, 8
	.loc	3 4301
	li	$11, 100663296
	sw	$11, 0($2)
	.loc	3 4301
	la	$12, D_80BE500
	sw	$12, 4($2)
	.loc	3 4301
$50:
	.loc	3 4304
 #4302	        }
 #4303	    }
 #4304	    if (gGameState == GAME_STATE_RIDER_SELECT) {
	lw	$13, gGameState
	bne	$13, 10, $51
	.loc	3 4304
	.loc	3 4305
 #4305	        func_i2_802C5E28();
	.livereg	0x0000000E,0x00000000
	jal	func_i2_802C5E28
	.loc	3 4306
 #4306	        if (D_80228A16 == 1) {
	lh	$14, D_80228A16
	bne	$14, 1, $55
	.loc	3 4306
	.loc	3 4307
 #4307	            D_i2_802C8BC0 = 1;
	li	$15, 1
	sw	$15, D_i2_802C8BC0
	b	$55
$51:
	.loc	3 4309
 #4308	        }
 #4309	    } else if (D_80228A16 == 1) {
	lh	$24, D_80228A16
	bne	$24, 1, $55
	.loc	3 4309
	.loc	3 4310
 #4310	        func_8007C31C();
	.livereg	0x0000000E,0x00000000
	jal	func_8007C31C
	.loc	3 4311
 #4311	        switch (D_801CE630) {
	lw	$3, D_801CE630
	beq	$3, 2, $52
	beq	$3, 20, $54
	beq	$3, 30, $53
	b	$55
$52:
	.loc	3 4313
 #4312	            case 2:
 #4313	                func_801EB180();
	.livereg	0x0000000E,0x00000000
	jal	func_801EB180
	.loc	3 4314
 #4314	                break;
	b	$55
$53:
	.loc	3 4316
 #4315	            case 30:
 #4316	                func_801EB91C();
	.livereg	0x0000000E,0x00000000
	jal	func_801EB91C
	.loc	3 4317
 #4317	                break;
	b	$55
$54:
	.loc	3 4319
 #4318	            case 20:
 #4319	                func_801EBFE4();
	.livereg	0x0000000E,0x00000000
	jal	func_801EBFE4
	.loc	3 4320
 #4320	                break;
$55:
	.loc	3 4323
 #4321	        }
 #4322	    }
 #4323	    return gdl;
	move	$2, $16
$56:
	.livereg	0x2000FF0E,0x00000FFF
	lw	$16, 24($sp)
	lw	$31, 28($sp)
	addu	$sp, 32
	j	$31
	.end	func_i2_802C5B4C
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C676C
	.loc	3 4326
 #4324	}
 #4325	#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C5E28.s")
 #4326	s32 func_i2_802C676C(s32 player, s32 param) {
	.ent	func_i2_802C676C 2
func_i2_802C676C:
	.option	O2
	.frame	$sp, 0, $31
	.loc	3 4326
	.loc	3 4327
 #4327	    s32 ret = 1;
	li	$3, 1
	.loc	3 4328
 #4328	    UnkStruct_func_i8_802C6E00(*arr)[4] = (UnkStruct_func_i8_802C6E00(*)[4]) D_801CB298;
	.loc	3 4329
 #4329	    s32 idx = D_i2_802C8BD8[D_800DA9C0[player]];
	mul	$14, $4, 4
	lw	$15, D_800DA9C0($14)
	mul	$24, $15, 4
	lw	$2, D_i2_802C8BD8($24)
	.loc	3 4330
 #4330	    arr[player][idx].unk_B[param]--;
	.noalias	$6,$sp
	mul	$25, $4, 56
	mul	$8, $2, 14
	addu	$9, $25, $8
	addu	$10, $9, $5
	la	$11, D_801CB298
	addu	$6, $10, $11
	lb	$12, 11($6)
	addu	$13, $12, -1
	sb	$13, 11($6)
	.loc	3 4331
 #4331	    if (arr[player][idx].unk_B[param] < 0) {
	lb	$14, 11($6)
	bge	$14, 0, $57
	.loc	3 4331
	.loc	3 4332
 #4332	        ret = 0;
	move	$3, $0
	.loc	3 4333
 #4333	        arr[player][idx].unk_B[param] = 0;
	sb	$0, 11($6)
	.alias	$6,$sp
$57:
	.loc	3 4335
 #4334	    }
 #4335	    return ret;
	move	$2, $3
	.livereg	0x2000FF0E,0x00000FFF
	j	$31
	.end	func_i2_802C676C
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C67E4
	.loc	3 4337
 #4336	}
 #4337	s32 func_i2_802C67E4(s32 player, s32 param) {
	.ent	func_i2_802C67E4 2
func_i2_802C67E4:
	.option	O2
	.frame	$sp, 0, $31
	.loc	3 4337
	.loc	3 4338
 #4338	    s32 ret = 1;
	li	$3, 1
	.loc	3 4339
 #4339	    UnkStruct_func_i8_802C6E00(*arr)[4] = (UnkStruct_func_i8_802C6E00(*)[4]) D_801CB298;
	.loc	3 4340
 #4340	    s32 idx = D_i2_802C8BD8[D_800DA9C0[player]];
	mul	$14, $4, 4
	lw	$15, D_800DA9C0($14)
	mul	$24, $15, 4
	lw	$2, D_i2_802C8BD8($24)
	.loc	3 4341
 #4341	    arr[player][idx].unk_B[param]++;
	.noalias	$6,$sp
	mul	$25, $4, 56
	mul	$8, $2, 14
	addu	$9, $25, $8
	addu	$10, $9, $5
	la	$11, D_801CB298
	addu	$6, $10, $11
	lb	$12, 11($6)
	addu	$13, $12, 1
	sb	$13, 11($6)
	.loc	3 4342
 #4342	    if (arr[player][idx].unk_B[param] == 12) {
	lb	$14, 11($6)
	bne	$14, 12, $58
	.loc	3 4342
	.loc	3 4343
 #4343	        ret = 0;
	move	$3, $0
	.loc	3 4344
 #4344	        arr[player][idx].unk_B[param] = 11;
	li	$15, 11
	sb	$15, 11($6)
	.alias	$6,$sp
$58:
	.loc	3 4346
 #4345	    }
 #4346	    return ret;
	move	$2, $3
	.livereg	0x2000FF0E,0x00000FFF
	j	$31
	.end	func_i2_802C67E4
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C6864
	.loc	3 4348
 #4347	}
 #4348	void func_i2_802C6864(s32 arg0) {
	.ent	func_i2_802C6864 2
func_i2_802C6864:
	.option	O2
	subu	$sp, 72
	sw	$31, 20($sp)
	.mask	0x80000000, -52
	.frame	$sp, 72, $31
	move	$5, $4
	la	$6, D_801CE608
	li	$31, 1
	.loc	3 4348
	.loc	3 4351
 #4349	    s32 i;
 #4350	    s32 j;
 #4351	    s32 cond = 0;
	move	$2, $0
	.loc	3 4354
 #4352	    s32 sp38;
 #4353	    s8 sp34[4];
 #4354	    if (D_801CE608.player == 1) {
	.noalias	$6,$sp
	lh	$14, 4($6)
	bne	$31, $14, $59
	.loc	3 4354
	.loc	3 4355
 #4355	        cond = 1;
	move	$2, $31
	b	$60
$59:
	la	$3, D_802C8C58
	li	$4, 6
	.loc	3 4356
 #4356	    } else {
	.loc	3 4357
 #4357	        ((s32*) &D_802C8C58)[arg0] = 6;
	.noalias	$3,$6
	.noalias	$3,$sp
	mul	$15, $5, 4
	addu	$24, $3, $15
	.noalias	$24,$6
	.noalias	$24,$sp
	sw	$4, 0($24)
	.alias	$24,$6
	.alias	$24,$sp
	.loc	3 4358
 #4358	        if (D_802C8C58.player_1_ready == 6 && D_802C8C58.player_2_ready == 6) {
	lw	$25, 0($3)
	bne	$4, $25, $60
	lw	$14, 4($3)
	bne	$4, $14, $60
	.alias	$3,$6
	.alias	$3,$sp
	.loc	3 4358
	.loc	3 4359
 #4359	            cond = 1;
	move	$2, $31
$60:
	.loc	3 4362
 #4360	        }
 #4361	    }
 #4362	    if (cond) {
	beq	$2, 0, $73
	.loc	3 4362
	.loc	3 4363
 #4363	        cond = D_801CE608.gameMode;
	lw	$2, 0($6)
	.loc	3 4364
 #4364	        switch (cond) {
	beq	$2, 0, $70
	.alias	$6,$sp
	beq	$2, $31, $71
	li	$10, 4
	beq	$2, $10, $61
	beq	$2, 11, $70
	b	$72
$61:
	.loc	3 4366
 #4365	            case 4:
 #4366	                for (i = 0; i < 4; i++) {
	move	$6, $0
	addu	$2, $sp, 52
	addu	$3, $sp, 56
$62:
	.loc	3 4366
	.loc	3 4367
 #4367	                    sp34[i] = 0;
	.noalias	$2,$gp
	sb	$0, 0($2)
	.loc	3 4366
 #4366	                for (i = 0; i < 4; i++) {
	addu	$2, $2, 1
	bltu	$2, $3, $62
	.alias	$2,$gp
	la	$3, D_800DA9C0
	.loc	3 4369
 #4367	                    sp34[i] = 0;
 #4368	                }
 #4369	                sp34[D_800DA9C0[0]] = 1;
	.noalias	$3,$sp
	lw	$11, 0($3)
	addu	$15, $sp, $11
	sb	$31, 52($15)
	.loc	3 4370
 #4370	                for (i = 0; i < 4; i++) {
	move	$6, $0
	lw	$12, D_800D48DC
	la	$7, D_800DA9B0
	li	$13, 12
	la	$9, D_i2_802C8BD8
	.alias	$3,$sp
$63:
	.loc	3 4370
	.loc	3 4371
 #4371	                    if (i != D_800D48DC) {
	beq	$6, $12, $68
	.loc	3 4371
	.loc	3 4372
 #4372	                        for (j = 0; j < 4; j++) {
	move	$3, $0
	addu	$2, $sp, 52
	mul	$24, $6, 5912
	la	$25, D_80192690
	addu	$5, $24, $25
	lw	$14, gCourseID
	mul	$15, $14, 48
	la	$24, D_800D96A4
	addu	$8, $15, $24
$64:
	.loc	3 4372
	.loc	3 4373
 #4373	                            if (sp34[j] == 0) {
	.noalias	$2,$gp
	lb	$25, 0($2)
	bne	$25, 0, $65
	.loc	3 4373
	.loc	3 4374
 #4374	                                sp34[j] = 1;
	sb	$31, 0($2)
	.loc	3 4375
 #4375	                                break;
	b	$66
$65:
	.loc	3 4372
 #4372	                        for (j = 0; j < 4; j++) {
	addu	$3, $3, 1
	addu	$2, $2, 1
	blt	$3, 4, $64
	.alias	$2,$gp
$66:
	.loc	3 4378
 #4373	                            if (sp34[j] == 0) {
 #4374	                                sp34[j] = 1;
 #4375	                                break;
 #4376	                            }
 #4377	                        }
 #4378	                        if (j == 4) {
	bne	$3, $10, $67
	.loc	3 4378
	.loc	3 4379
 #4379	                            j--;
	addu	$3, $3, -1
$67:
	.loc	3 4381
 #4380	                        }
 #4381	                        D_80192690[i].unkB68 = D_800DA9B0[i] = D_i2_802C8BD8[j];
	.noalias	$9,$sp
	mul	$14, $3, 4
	addu	$15, $9, $14
	.noalias	$15,$sp
	lw	$2, 0($15)
	.alias	$15,$sp
	.noalias	$7,$9
	.noalias	$7,$sp
	sw	$2, 0($7)
	.noalias	$5,$7
	.noalias	$5,$9
	.noalias	$5,$sp
	sw	$2, 2920($5)
	.loc	3 4382
 #4382	                        D_80192690[i].unkB6C = D_800D96A4[gCourseID][D_800DA9B0[i]].unk0;
	.noalias	$8,$5
	.noalias	$8,$7
	.noalias	$8,$9
	.noalias	$8,$sp
	.noalias	$4,$5
	.noalias	$4,$7
	.noalias	$4,$9
	.noalias	$4,$sp
	mul	$24, $2, $13
	addu	$4, $8, $24
	lw	$25, 0($4)
	sw	$25, 2924($5)
	.loc	3 4383
 #4383	                        D_80192690[i].unkB70 = D_800D96A4[gCourseID][D_800DA9B0[i]].unk4;
	lw	$14, 4($4)
	sw	$14, 2928($5)
	.loc	3 4384
 #4384	                        D_80192690[i].unkB74 = D_800D96A4[gCourseID][D_800DA9B0[i]].unk8;
	lw	$15, 8($4)
	sw	$15, 2932($5)
	b	$69
	.alias	$4,$5
	.alias	$4,$7
	.alias	$4,$9
	.alias	$4,$sp
	.alias	$5,$7
	.alias	$5,$8
	.alias	$5,$9
	.alias	$5,$sp
	.alias	$8,$7
	.alias	$8,$9
	.alias	$8,$sp
$68:
	.loc	3 4385
 #4385	                    } else {
	.loc	3 4386
 #4386	                        D_800DA9B0[i] = D_i2_802C8BD8[D_800DA9C0[0]];
	mul	$24, $11, 4
	addu	$25, $9, $24
	.noalias	$25,$7
	.noalias	$25,$sp
	lw	$14, 0($25)
	.alias	$25,$7
	.alias	$25,$sp
	sw	$14, 0($7)
$69:
	.loc	3 4370
 #4370	                for (i = 0; i < 4; i++) {
	addu	$6, $6, 1
	addu	$7, $7, 4
	bne	$6, $10, $63
	.alias	$7,$9
	.alias	$7,$sp
	.alias	$9,$sp
	.loc	3 4389
 #4389	                sp38 = 30;
	li	$15, 30
	sw	$15, 56($sp)
	.loc	3 4390
 #4390	                break;
	b	$72
$70:
	la	$2, D_800DA9B0
	la	$3, D_800DA9C0
	la	$9, D_i2_802C8BD8
	.loc	3 4393
 #4391	            case 0:
 #4392	            case 11:
 #4393	                D_800DA9B0[0] = D_i2_802C8BD8[D_800DA9C0[0]];
	.noalias	$2,$sp
	.noalias	$9,$2
	.noalias	$9,$sp
	.noalias	$3,$2
	.noalias	$3,$9
	.noalias	$3,$sp
	lw	$24, 0($3)
	mul	$25, $24, 4
	addu	$14, $9, $25
	.noalias	$14,$2
	.noalias	$14,$3
	.noalias	$14,$sp
	lw	$15, 0($14)
	.alias	$14,$2
	.alias	$14,$3
	.alias	$14,$sp
	sw	$15, 0($2)
	.loc	3 4394
 #4394	                D_800DA9B0[1] = 0;
	sw	$0, 4($2)
	.loc	3 4395
 #4395	                D_800DA9B0[2] = 0;
	sw	$0, 8($2)
	.loc	3 4396
 #4396	                D_800DA9B0[3] = 0;
	sw	$0, 12($2)
	.loc	3 4397
 #4397	                sp38 = 20;
	li	$24, 20
	sw	$24, 56($sp)
	.loc	3 4398
 #4398	                break;
	b	$72
$71:
	la	$2, D_800DA9B0
	la	$3, D_800DA9C0
	la	$9, D_i2_802C8BD8
	.loc	3 4400
 #4399	            case 1:
 #4400	                D_800DA9B0[0] = D_i2_802C8BD8[D_800DA9C0[0]];
	lw	$25, 0($3)
	mul	$14, $25, 4
	addu	$15, $9, $14
	.noalias	$15,$2
	.noalias	$15,$3
	.noalias	$15,$sp
	lw	$24, 0($15)
	.alias	$15,$2
	.alias	$15,$3
	.alias	$15,$sp
	sw	$24, 0($2)
	.loc	3 4401
 #4401	                D_800DA9B0[1] = D_i2_802C8BD8[D_800DA9C0[1]];
	lw	$25, 4($3)
	mul	$14, $25, 4
	addu	$15, $9, $14
	.noalias	$15,$2
	.noalias	$15,$3
	.noalias	$15,$sp
	lw	$24, 0($15)
	.alias	$15,$2
	.alias	$15,$3
	.alias	$15,$sp
	sw	$24, 4($2)
	.loc	3 4402
 #4402	                D_800DA9B0[2] = 0;
	sw	$0, 8($2)
	.loc	3 4403
 #4403	                D_800DA9B0[3] = 0;
	sw	$0, 12($2)
	.loc	3 4404
 #4404	                sp38 = 20;
	li	$25, 20
	sw	$25, 56($sp)
	.loc	3 4405
 #4405	                break;
	.alias	$2,$3
	.alias	$2,$9
	.alias	$2,$sp
	.alias	$3,$9
	.alias	$3,$sp
	.alias	$9,$sp
$72:
	.loc	3 4407
 #4406	        }
 #4407	        func_i2_802C84EC(sp38);
	lw	$4, 56($sp)
	.livereg	0x0800000E,0x00000000
	jal	func_i2_802C84EC
	.loc	3 4409
 #4408	    }
 #4409	}
$73:
	.livereg	0x0000FF0E,0x00000FFF
	lw	$31, 20($sp)
	addu	$sp, 72
	j	$31
	.end	func_i2_802C6864
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C6ADC
	.loc	3 4410
 #4410	Gfx* func_i2_802C6ADC(Gfx* gdl) {
	.ent	func_i2_802C6ADC 2
func_i2_802C6ADC:
	.option	O2
	subu	$sp, 40
	sw	$31, 36($sp)
	sw	$16, 32($sp)
	.mask	0x80010000, -4
	.frame	$sp, 40, $31
	li	$16, 100663296
	.loc	3 4410
	.loc	3 4412
 #4411	    u32 alpha;
 #4412	    f32 f4 = 4.0f;
	.loc	3 4413
 #4413	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE248); };
	.loc	3 4413
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4413
	sw	$16, 0($2)
	.loc	3 4413
	la	$14, D_80BE248
	sw	$14, 4($2)
	.loc	3 4413
	.loc	3 4414
 #4414	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(D_106F628); };
	.loc	3 4414
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4414
	sw	$16, 0($3)
	.loc	3 4414
	la	$15, D_106F628
	sw	$15, 4($3)
	.loc	3 4414
	.loc	3 4415
 #4415	    gdl = func_80094338(gdl, 0, 0x1C, 0x16, 0x108, 0x1E);
	move	$5, $0
	li	$6, 28
	li	$7, 22
	li	$24, 264
	sw	$24, 16($sp)
	li	$25, 30
	sw	$25, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80094338
	.loc	3 4416
 #4416	    gdl = func_80094338(gdl, 0, 0x1C, 0x60, 0x82, 0xD);
	move	$4, $2
	move	$5, $0
	li	$6, 28
	li	$7, 96
	li	$13, 130
	sw	$13, 16($sp)
	li	$14, 13
	sw	$14, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80094338
	.loc	3 4417
 #4417	    gdl = func_80094338(gdl, 0, 0x20, 0x6E, 0x3B, 0xD);
	move	$4, $2
	move	$5, $0
	li	$6, 32
	li	$7, 110
	li	$15, 59
	sw	$15, 16($sp)
	li	$24, 13
	sw	$24, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80094338
	.loc	3 4418
 #4418	    gdl = func_80094338(gdl, 0, 0x5F, 0x6E, 0x3B, 0xD);
	move	$4, $2
	move	$5, $0
	li	$6, 95
	li	$7, 110
	li	$25, 59
	sw	$25, 16($sp)
	li	$13, 13
	sw	$13, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80094338
	.loc	3 4419
 #4419	    gdl = func_i2_802C86E4(gdl, 0x13, 0x68);
	move	$4, $2
	li	$5, 19
	li	$6, 104
	.livereg	0x0E00000E,0x00000000
	jal	func_i2_802C86E4
	move	$4, $2
	.loc	3 4420
 #4420	    if (D_802C8C58.player_1_ready != 5) {
	lw	$14, D_802C8C58
	beq	$14, 5, $74
	.loc	3 4420
	.loc	3 4421
 #4421	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE2B8); };
	.loc	3 4421
	move	$3, $2
	addu	$4, $2, 8
	.loc	3 4421
	sw	$16, 0($3)
	.loc	3 4421
	la	$15, D_80BE2B8
	sw	$15, 4($3)
	.loc	3 4421
$74:
	la	$7, D_802C8C6A
	li	$12, -419430400
	.loc	3 4423
 #4422	    }
 #4423	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; };
	.loc	3 4423
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4423
	sw	$12, 0($2)
	.loc	3 4423
	sw	$0, 4($2)
	.loc	3 4423
	.loc	3 4424
 #4424	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((-65 -6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(29) & ((0x01 << (8)) - 1)) << (0)))); _g->words.w1 = (unsigned int)((0x40 | 0x200 | 0x4000 | 0 | (0) << 30 | (0) << 26 | (1) << 22 | (0) << 18) | (0x40 | 0x200 | 0x4000 | 0 | (0) << 28 | (0) << 24 | (1) << 20 | (0) << 16)); };
	.loc	3 4424
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4424
	li	$24, -1191181539
	sw	$24, 0($3)
	.loc	3 4424
	li	$25, 5259840
	sw	$25, 4($3)
	.loc	3 4424
	.loc	3 4425
 #4425	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfc) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((((unsigned int) (((unsigned int)((1)) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)((3)) & ((0x01 << (5)) - 1)) << (15))) | ((unsigned int) (((unsigned int)((1)) & ((0x01 << (3)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((3)) & ((0x01 << (3)) - 1)) << (9)))) | (((unsigned int) (((unsigned int)((1)) & ((0x01 << (4)) - 1)) << (5))) | ((unsigned int) (((unsigned int)((3)) & ((0x01 << (5)) - 1)) << (0))))) & ((0x01 << (24)) - 1)) << (0))); _g->words.w1 = (unsigned int)((((unsigned int) (((unsigned int)((31)) & ((0x01 << (4)) - 1)) << (28))) | ((unsigned int) (((unsigned int)((31)) & ((0x01 << (3)) - 1)) << (15))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (9)))) | (((unsigned int) (((unsigned int)((31)) & ((0x01 << (4)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((1)) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)((3)) & ((0x01 << (3)) - 1)) << (18))) | ((unsigned int) (((unsigned int)((31)) & ((0x01 << (3)) - 1)) << (6))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (3))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (0))))); };
	.loc	3 4425
	move	$5, $4
	addu	$4, $4, 8
	.loc	3 4425
	li	$13, -65956317
	sw	$13, 0($5)
	.loc	3 4425
	li	$14, -13631489
	sw	$14, 4($5)
	.loc	3 4425
	.loc	3 4426
 #4426	    if (D_802C8C6A == 0) {
	.noalias	$7,$sp
	lh	$6, 0($7)
	bne	$6, 0, $75
	la	$3, D_802C8C68
	li.s	$f0, 4.0
	.loc	3 4426
	.loc	3 4427
 #4427	        alpha = (u32) ((D_802C8C68 * 255.0f) / f4);
	.noalias	$3,$7
	.noalias	$3,$sp
	lh	$2, 0($3)
	mtc1	$2, $f4
	cvt.s.w	$f6, $f4
	li.s	$f8, 255.0
	mul.s	$f10, $f6, $f8
	div.s	$f16, $f10, $f0
	cfc1	$15, $31
	li	$8, 1
	ctc1	$8, $31
	cvt.w.s	$f18, $f16
	cfc1	$8, $31
	.set	 noat
	and	$1, $8, 4
	and	$8, $8, 120
	.set	 at
	beq	$8, 0, $79
	li.s	$f18, 2147483648.0
	sub.s	$f18, $f16, $f18
	li	$8, 1
	ctc1	$8, $31
	cvt.w.s	$f18, $f18
	cfc1	$8, $31
	.set	 noat
	and	$1, $8, 4
	and	$8, $8, 120
	.set	 at
	bne	$8, 0, $80
	.set	 noat
	mfc1	$8, $f18
	li	$1, -2147483648
	or	$8, $8, $1
	.set	 at
	b	$78
$80:
	li	$8, -1
	b	$78
$79:
	mfc1	$8, $f18
	blt	$8, 0, $80
$78:
	ctc1	$15, $31
	b	$76
$75:
	la	$3, D_802C8C68
	li.s	$f0, 4.0
	.loc	3 4428
 #4428	    } else {
	.loc	3 4429
 #4429	        alpha = (u32) (((f4 - D_802C8C68) * 255.0f) / f4);
	lh	$2, 0($3)
	mtc1	$2, $f4
	cvt.s.w	$f6, $f4
	sub.s	$f8, $f0, $f6
	li.s	$f10, 255.0
	mul.s	$f16, $f8, $f10
	div.s	$f18, $f16, $f0
	cfc1	$24, $31
	li	$8, 1
	ctc1	$8, $31
	cvt.w.s	$f4, $f18
	cfc1	$8, $31
	.set	 noat
	and	$1, $8, 4
	and	$8, $8, 120
	.set	 at
	beq	$8, 0, $82
	li.s	$f4, 2147483648.0
	sub.s	$f4, $f18, $f4
	li	$8, 1
	ctc1	$8, $31
	cvt.w.s	$f4, $f4
	cfc1	$8, $31
	.set	 noat
	and	$1, $8, 4
	and	$8, $8, 120
	.set	 at
	bne	$8, 0, $83
	.set	 noat
	mfc1	$8, $f4
	li	$1, -2147483648
	or	$8, $8, $1
	.set	 at
	b	$81
$83:
	li	$8, -1
	b	$81
$82:
	mfc1	$8, $f4
	blt	$8, 0, $83
$81:
	ctc1	$24, $31
$76:
	.loc	3 4431
 #4430	    }
 #4431	    D_802C8C68++;
	addu	$25, $2, 1
	sh	$25, 0($3)
	.loc	3 4432
 #4432	    if (D_802C8C68 >= 4) {
	lh	$13, 0($3)
	blt	$13, 4, $77
	.loc	3 4432
	.loc	3 4433
 #4433	        D_802C8C68 = 0;
	sh	$0, 0($3)
	.loc	3 4434
 #4434	        D_802C8C6A ^= 1;
	xor	$14, $6, 1
	sh	$14, 0($7)
	.alias	$3,$7
	.alias	$3,$sp
	.alias	$7,$sp
$77:
	li	$11, -177729536
	.loc	3 4436
 #4435	    }
 #4436	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xfa) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (8)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(alpha) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(255) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(alpha) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(255) & ((0x01 << (8)) - 1)) << (0)))); };
	.loc	3 4436
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4436
	li	$15, -100663296
	sw	$15, 0($2)
	.loc	3 4436
	and	$3, $8, 255
	sll	$24, $3, 24
	or	$25, $24, 16711680
	sll	$13, $3, 8
	or	$14, $25, $13
	or	$15, $14, 255
	sw	$15, 4($2)
	.loc	3 4436
	.loc	3 4437
 #4437	    { { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfd) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((64)-1) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = (uintptr_t)(D_80B6590); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((64 - 1)-(0)+1) * 1)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe6) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((64 - 1)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((36 - 1)<<2) & ((0x01 << (12)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((64 - 1)-(0)+1) * 1)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf2) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((64 - 1)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((36 - 1)<<2) & ((0x01 << (12)) - 1)) << (0))); } };
	.loc	3 4437
	.loc	3 4437
	move	$5, $4
	addu	$4, $4, 8
	.loc	3 4437
	li	$24, -43515841
	sw	$24, 0($5)
	.loc	3 4437
	la	$25, D_80B6590
	sw	$25, 4($5)
	.loc	3 4437
	.loc	3 4437
	.loc	3 4437
	move	$6, $4
	addu	$4, $4, 8
	.loc	3 4437
	sw	$11, 0($6)
	.loc	3 4437
	li	$13, 117965312
	sw	$13, 4($6)
	.loc	3 4437
	.loc	3 4437
	.loc	3 4437
	move	$7, $4
	addu	$4, $4, 8
	.loc	3 4437
	li	$14, -436207616
	sw	$14, 0($7)
	.loc	3 4437
	sw	$0, 4($7)
	.loc	3 4437
	.loc	3 4437
	.loc	3 4437
	move	$9, $4
	addu	$4, $4, 8
	la	$8, D_i2_802C8BD0
	la	$10, D_800DA9C0
	.loc	3 4437
	li	$15, -201326592
	sw	$15, 0($9)
	.loc	3 4437
	li	$24, 118472844
	sw	$24, 4($9)
	.loc	3 4437
	.loc	3 4437
	.loc	3 4437
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4437
	sw	$12, 0($2)
	.loc	3 4437
	sw	$0, 4($2)
	.loc	3 4437
	.loc	3 4437
	.loc	3 4437
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4437
	sw	$11, 0($3)
	.loc	3 4437
	li	$25, 524800
	sw	$25, 4($3)
	.loc	3 4437
	.loc	3 4437
	.loc	3 4437
	move	$5, $4
	addu	$4, $4, 8
	.loc	3 4437
	li	$13, -234881024
	sw	$13, 0($5)
	.loc	3 4437
	li	$14, 1032332
	sw	$14, 4($5)
	.loc	3 4437
	.loc	3 4438
 #4438	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xe4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((D_i2_802C8BD0[D_800DA9C0[0]] + 72) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(91 << 2) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((D_i2_802C8BD0[D_800DA9C0[0]] + 8) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(55 << 2) & ((0x01 << (12)) - 1)) << (0)))); { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -12))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (0))))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -13))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (0))))); };};
	.loc	3 4438
	move	$6, $4
	addu	$4, $4, 8
	.loc	3 4438
	.noalias	$8,$sp
	.noalias	$10,$8
	.noalias	$10,$sp
	lw	$15, 0($10)
	mul	$24, $15, 2
	addu	$25, $8, $24
	.noalias	$25,$10
	.noalias	$25,$sp
	lh	$13, 0($25)
	.alias	$25,$10
	.alias	$25,$sp
	addu	$14, $13, 72
	sll	$15, $14, 2
	and	$24, $15, 4095
	sll	$25, $24, 12
	or	$13, $25, -469762048
	or	$14, $13, 364
	sw	$14, 0($6)
	.loc	3 4438
	lw	$15, 0($10)
	mul	$24, $15, 2
	addu	$25, $8, $24
	.noalias	$25,$10
	.noalias	$25,$sp
	lh	$13, 0($25)
	.alias	$25,$10
	.alias	$25,$sp
	addu	$14, $13, 8
	sll	$15, $14, 2
	and	$24, $15, 4095
	sll	$25, $24, 12
	or	$13, $25, 220
	sw	$13, 4($6)
	.loc	3 4438
	.loc	3 4438
	move	$7, $4
	addu	$4, $4, 8
	.alias	$8,$10
	.alias	$8,$sp
	.alias	$10,$sp
	.loc	3 4438
	li	$14, -1291845632
	sw	$14, 0($7)
	.loc	3 4438
	sw	$0, 4($7)
	.loc	3 4438
	.loc	3 4438
	.loc	3 4438
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4438
	li	$15, -1308622848
	sw	$15, 0($2)
	.loc	3 4438
	li	$24, 67109888
	sw	$24, 4($2)
	.loc	3 4438
	.loc	3 4438
	.loc	3 4439
 #4439	    gdl = func_i2_802C70EC(gdl, 0);
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C70EC
	.loc	3 4440
 #4440	    gdl->words.w0 = 0xB4000000;
	li	$25, -1275068416
	sw	$25, 0($2)
	.loc	3 4441
 #4441	    gdl->words.w1 = D_802C8C50;
	lhu	$13, D_802C8C50
	sw	$13, 4($2)
	.loc	3 4442
 #4442	    gdl++;
	.loc	3 4443
 #4443	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x01)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_7000A40); };
	.loc	3 4443
	.loc	3 4443
	li	$14, 16973888
	sw	$14, 8($2)
	.loc	3 4443
	la	$15, D_7000A40
	sw	$15, 12($2)
	.loc	3 4443
	.loc	3 4444
 #4444	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_106F488); };
	.loc	3 4444
	.loc	3 4444
	sw	$16, 16($2)
	.loc	3 4444
	la	$24, D_106F488
	sw	$24, 20($2)
	.loc	3 4444
	.loc	3 4445
 #4445	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE468); };
	.loc	3 4445
	.loc	3 4445
	sw	$16, 24($2)
	.loc	3 4445
	la	$25, D_80BE468
	sw	$25, 28($2)
	.loc	3 4445
	.loc	3 4446
 #4446	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_7000A80); };
	.loc	3 4446
	.loc	3 4446
	li	$13, 16908352
	sw	$13, 32($2)
	.loc	3 4446
	la	$14, D_7000A80
	sw	$14, 36($2)
	.loc	3 4446
	.loc	3 4447
 #4447	    gdl = func_801E4FE8(gdl, 0, 0, 0, (u8*) D_801CE5F8 + 0xC80);
	addu	$4, $2, 40
	move	$5, $0
	move	$6, $0
	move	$7, $0
	lw	$15, D_801CE5F8
	addu	$24, $15, 3200
	sw	$24, 16($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E4FE8
	.loc	3 4448
 #4448	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE478); };
	.loc	3 4448
	.loc	3 4448
	sw	$16, 0($2)
	.loc	3 4448
	la	$25, D_80BE478
	sw	$25, 4($2)
	.loc	3 4448
	.loc	3 4449
 #4449	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_7000AC0); };
	.loc	3 4449
	.loc	3 4449
	li	$13, 16908352
	sw	$13, 8($2)
	.loc	3 4449
	la	$14, D_7000AC0
	sw	$14, 12($2)
	.loc	3 4449
	.loc	3 4450
 #4450	    gdl = func_801E4FE8(gdl, 2, 0, 0, (u8*) D_801CE5F8 + 0xD40);
	addu	$4, $2, 16
	li	$5, 2
	move	$6, $0
	move	$7, $0
	lw	$15, D_801CE5F8
	addu	$24, $15, 3392
	sw	$24, 16($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E4FE8
	.loc	3 4451
 #4451	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE488); };
	.loc	3 4451
	.loc	3 4451
	sw	$16, 0($2)
	.loc	3 4451
	la	$25, D_80BE488
	sw	$25, 4($2)
	.loc	3 4451
	.loc	3 4452
 #4452	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_7000B00); };
	.loc	3 4452
	.loc	3 4452
	li	$13, 16908352
	sw	$13, 8($2)
	.loc	3 4452
	la	$14, D_7000B00
	sw	$14, 12($2)
	.loc	3 4452
	.loc	3 4453
 #4453	    gdl = func_801E4FE8(gdl, 3, 0, 0, (u8*) D_801CE5F8 + 0xE00);
	addu	$4, $2, 16
	li	$5, 3
	move	$6, $0
	move	$7, $0
	lw	$15, D_801CE5F8
	addu	$24, $15, 3584
	sw	$24, 16($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E4FE8
	.loc	3 4454
 #4454	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE498); };
	.loc	3 4454
	.loc	3 4454
	sw	$16, 0($2)
	.loc	3 4454
	la	$25, D_80BE498
	sw	$25, 4($2)
	.loc	3 4454
	.loc	3 4455
 #4455	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_7000B40); };
	.loc	3 4455
	.loc	3 4455
	li	$13, 16908352
	sw	$13, 8($2)
	.loc	3 4455
	la	$14, D_7000B40
	sw	$14, 12($2)
	.loc	3 4455
	.loc	3 4456
 #4456	    return func_801E4FE8(gdl, 1, 0, 0, (u8*) D_801CE5F8 + 0xEC0);
	addu	$4, $2, 16
	li	$5, 1
	move	$6, $0
	move	$7, $0
	lw	$15, D_801CE5F8
	addu	$24, $15, 3776
	sw	$24, 16($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E4FE8
	.livereg	0x2000FF0E,0x00000FFF
	lw	$16, 32($sp)
	lw	$31, 36($sp)
	addu	$sp, 40
	j	$31
	.end	func_i2_802C6ADC
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C70EC
	.loc	3 4458
 #4457	}
 #4458	Gfx* func_i2_802C70EC(Gfx* gdl, s32 player) {
	.ent	func_i2_802C70EC 2
func_i2_802C70EC:
	.option	O2
	subu	$sp, 248
	sw	$31, 68($sp)
	sw	$16, 64($sp)
	.mask	0x80010000, -180
	.frame	$sp, 248, $31
	move	$16, $4
	.loc	3 4458
	.loc	3 4467
 #4467	    if (player == 0) {
	bne	$5, 0, $84
	.loc	3 4467
	.loc	3 4468
 #4468	        x_pos = 0x13;
	li	$14, 19
	sw	$14, 220($sp)
	b	$85
$84:
	.loc	3 4469
 #4469	    } else {
	.loc	3 4470
 #4470	        x_pos = 0x99;
	li	$15, 153
	sw	$15, 220($sp)
$85:
	.loc	3 4472
 #4471	    }
 #4472	    if ((D_800DA9C8[player] == 0) || (D_802C8C58.as_array[player] == 0)) {
	mul	$2, $5, 4
	la	$24, D_800DA9C8
	addu	$25, $2, $24
	sw	$25, 88($sp)
	lw	$12, 88($sp)
	lw	$13, 0($12)
	beq	$13, 0, $86
	la	$14, D_802C8C58
	addu	$15, $2, $14
	sw	$15, 84($sp)
	lw	$24, 84($sp)
	lw	$3, 0($24)
	bne	$3, 0, $87
$86:
	.loc	3 4472
	.loc	3 4473
 #4473	        ptr = &D_800DA950[D_i2_802C8BD8[D_800DA9C0[player]]];
	la	$25, D_800DA9C0
	addu	$12, $2, $25
	sw	$12, 76($sp)
	lw	$13, 76($sp)
	lw	$14, 0($13)
	mul	$15, $14, 4
	lw	$24, D_i2_802C8BD8($15)
	mul	$25, $24, 14
	la	$12, D_800DA950
	addu	$8, $25, $12
	la	$13, D_802C8C58
	addu	$4, $2, $13
	.noalias	$4,$sp
	lw	$3, 0($4)
	sw	$4, 84($sp)
	b	$88
	.alias	$4,$sp
$87:
	.loc	3 4474
 #4474	    } else {
	.loc	3 4475
 #4475	        ptr = &((UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298)[player][D_i2_802C8BD8[D_800DA9C0[player]]];
	.noalias	$4,$sp
	la	$14, D_800DA9C0
	addu	$4, $2, $14
	mul	$15, $5, 56
	lw	$24, 0($4)
	mul	$25, $24, 4
	lw	$12, D_i2_802C8BD8($25)
	mul	$13, $12, 14
	addu	$14, $15, $13
	la	$24, D_801CB298
	addu	$8, $14, $24
	sw	$4, 76($sp)
	.alias	$4,$sp
$88:
	.loc	3 4477
 #4476	    }
 #4477	    show_stats = 0;
	move	$9, $0
	.loc	3 4478
 #4478	    show_banner = 0;
	sw	$0, 240($sp)
	.loc	3 4479
 #4479	    show_name = 0;
	sw	$0, 236($sp)
	.loc	3 4480
 #4480	    spE8 = 0;
	sw	$0, 232($sp)
	.loc	3 4481
 #4481	    spE4 = 0;
	sw	$0, 228($sp)
	.loc	3 4482
 #4482	    if (D_802C8C58.as_array[player] >= 2) {
	blt	$3, 2, $89
	.loc	3 4482
	.loc	3 4483
 #4483	        spE8 = 1;
	li	$25, 1
	sw	$25, 232($sp)
$89:
	.loc	3 4485
 #4484	    }
 #4485	    if ((D_802C8C58.as_array[player] > 0) && (D_802C8C58.as_array[player] != 6)) {
	ble	$3, 0, $90
	beq	$3, 6, $90
	.loc	3 4485
	.loc	3 4486
 #4486	        spE4 = 1;
	li	$12, 1
	sw	$12, 228($sp)
$90:
	.loc	3 4488
 #4487	    }
 #4488	    if (D_801CE60C == 1) {
	lh	$15, D_801CE60C
	bne	$15, 1, $92
	.loc	3 4488
	.loc	3 4489
 #4489	        if (D_802C8C58.as_array[player] != 5) {
	beq	$3, 5, $91
	.loc	3 4489
	.loc	3 4490
 #4490	            show_stats = 1;
	li	$9, 1
$91:
	.loc	3 4492
 #4491	        }
 #4492	        show_banner = 1;
	li	$13, 1
	sw	$13, 240($sp)
	.loc	3 4493
 #4493	        show_name = 1;
	li	$14, 1
	sw	$14, 236($sp)
	.loc	3 4494
 #4494	        x_name = x_pos + 0xA1;
	lw	$24, 220($sp)
	addu	$25, $24, 161
	sw	$25, 216($sp)
	b	$96
$92:
	.loc	3 4495
 #4495	    } else {
	.loc	3 4496
 #4496	        if ((D_802C8C58.as_array[player] > 0) && (D_802C8C58.as_array[player] < 5)) {
	ble	$3, 0, $93
	bge	$3, 5, $93
	.loc	3 4496
	.loc	3 4497
 #4497	            show_stats = 1;
	li	$9, 1
$93:
	.loc	3 4499
 #4498	        }
 #4499	        if (D_802C8C58.as_array[player] > 0) {
	ble	$3, 0, $94
	.loc	3 4499
	.loc	3 4500
 #4500	            show_banner = 1;
	li	$12, 1
	sw	$12, 240($sp)
$94:
	.loc	3 4502
 #4501	        }
 #4502	        if (D_802C8C58.as_array[player] == 0) {
	bne	$3, 0, $95
	.loc	3 4502
	.loc	3 4503
 #4503	            show_name = 1;
	li	$15, 1
	sw	$15, 236($sp)
$95:
	.loc	3 4505
 #4504	        }
 #4505	        x_name = x_pos + 0x1B;
	lw	$13, 220($sp)
	addu	$14, $13, 27
	sw	$14, 216($sp)
$96:
	.loc	3 4507
 #4506	    }
 #4507	    if (show_stats != 0) {
	sw	$9, 244($sp)
	beq	$9, 0, $97
	li	$7, -183499264
	li	$10, -419430400
	.loc	3 4507
	.loc	3 4508
 #4508	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; };
	.loc	3 4508
	move	$2, $16
	addu	$16, $16, 8
	.loc	3 4508
	sw	$10, 0($2)
	.loc	3 4508
	sw	$0, 4($2)
	.loc	3 4508
	.loc	3 4509
 #4509	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((-65 -6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(29) & ((0x01 << (8)) - 1)) << (0)))); _g->words.w1 = (unsigned int)((0 | 0x4000 | 0 | (0) << 30 | (3) << 26 | (0) << 22 | (2) << 18) | (0 | 0x4000 | 0 | (0) << 28 | (3) << 24 | (0) << 20 | (2) << 16)); };
	.loc	3 4509
	move	$3, $16
	addu	$16, $16, 8
	.loc	3 4509
	li	$24, -1191181539
	sw	$24, 0($3)
	.loc	3 4509
	li	$25, 252329984
	sw	$25, 4($3)
	.loc	3 4509
	.loc	3 4510
 #4510	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfc) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((((unsigned int) (((unsigned int)((31)) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)((31)) & ((0x01 << (5)) - 1)) << (15))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (9)))) | (((unsigned int) (((unsigned int)((31)) & ((0x01 << (4)) - 1)) << (5))) | ((unsigned int) (((unsigned int)((31)) & ((0x01 << (5)) - 1)) << (0))))) & ((0x01 << (24)) - 1)) << (0))); _g->words.w1 = (unsigned int)((((unsigned int) (((unsigned int)((31)) & ((0x01 << (4)) - 1)) << (28))) | ((unsigned int) (((unsigned int)((1)) & ((0x01 << (3)) - 1)) << (15))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((1)) & ((0x01 << (3)) - 1)) << (9)))) | (((unsigned int) (((unsigned int)((31)) & ((0x01 << (4)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (18))) | ((unsigned int) (((unsigned int)((1)) & ((0x01 << (3)) - 1)) << (6))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (3))) | ((unsigned int) (((unsigned int)((1)) & ((0x01 << (3)) - 1)) << (0))))); };
	.loc	3 4510
	move	$4, $16
	addu	$16, $16, 8
	.loc	3 4510
	li	$12, -50331649
	sw	$12, 0($4)
	.loc	3 4510
	li	$15, -200071
	sw	$15, 4($4)
	.loc	3 4510
	.loc	3 4511
 #4511	        { { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfd) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((9)-1) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = (uintptr_t)(D_80B6518); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((8)-(0)+1) * 2)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe6) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((8)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((5)<<2) & ((0x01 << (12)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((8)-(0)+1) * 2)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf2) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((8)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((5)<<2) & ((0x01 << (12)) - 1)) << (0))); } };
	.loc	3 4511
	.loc	3 4511
	move	$5, $16
	addu	$16, $16, 8
	.loc	3 4511
	li	$13, -49283064
	sw	$13, 0($5)
	.loc	3 4511
	la	$14, D_80B6518
	sw	$14, 4($5)
	.loc	3 4511
	.loc	3 4511
	.loc	3 4511
	move	$6, $16
	addu	$16, $16, 8
	.loc	3 4511
	sw	$7, 0($6)
	.loc	3 4511
	li	$24, 117965312
	sw	$24, 4($6)
	sw	$9, 244($sp)
	.loc	3 4511
	.loc	3 4511
	.loc	3 4511
	move	$2, $16
	addu	$16, $16, 8
	.loc	3 4511
	li	$25, -436207616
	sw	$25, 0($2)
	.loc	3 4511
	sw	$0, 4($2)
	.loc	3 4511
	.loc	3 4511
	.loc	3 4511
	move	$3, $16
	addu	$16, $16, 8
	.loc	3 4511
	li	$12, -201326592
	sw	$12, 0($3)
	.loc	3 4511
	li	$15, 117571604
	sw	$15, 4($3)
	.loc	3 4511
	.loc	3 4511
	.loc	3 4511
	move	$4, $16
	addu	$16, $16, 8
	.loc	3 4511
	sw	$10, 0($4)
	.loc	3 4511
	sw	$0, 4($4)
	.loc	3 4511
	.loc	3 4511
	.loc	3 4511
	move	$5, $16
	addu	$16, $16, 8
	.loc	3 4511
	sw	$7, 0($5)
	.loc	3 4511
	li	$13, 524800
	sw	$13, 4($5)
	.loc	3 4511
	.loc	3 4511
	.loc	3 4511
	move	$6, $16
	addu	$16, $16, 8
	.loc	3 4511
	li	$14, -234881024
	sw	$14, 0($6)
	.loc	3 4511
	li	$24, 131092
	sw	$24, 4($6)
	li	$5, 10
	lw	$9, 220($sp)
	li	$10, -469762048
	li	$11, -1291845632
	.loc	3 4511
	.loc	3 4512
 #4512	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xe4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((ptr->unk_B[0] * 10) + x_pos + 0x17) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0x99 << 2) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((ptr->unk_B[0] * 10) + x_pos + 0xE) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0x93 << 2) & ((0x01 << (12)) - 1)) << (0)))); { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -12))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (0))))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -13))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (0))))); };};
	.loc	3 4512
	move	$2, $16
	addu	$16, $16, 8
	.loc	3 4512
	lb	$25, 11($8)
	mul	$12, $25, $5
	addu	$15, $12, $9
	addu	$13, $15, 23
	sll	$14, $13, 2
	and	$24, $14, 4095
	sll	$25, $24, 12
	or	$12, $25, $10
	or	$15, $12, 612
	sw	$15, 0($2)
	.loc	3 4512
	lb	$13, 11($8)
	mul	$14, $13, $5
	addu	$24, $14, $9
	addu	$25, $24, 14
	sll	$12, $25, 2
	and	$15, $12, 4095
	sll	$13, $15, 12
	or	$14, $13, 588
	sw	$14, 4($2)
	.loc	3 4512
	.loc	3 4512
	move	$3, $16
	addu	$16, $16, 8
	.loc	3 4512
	sw	$11, 0($3)
	.loc	3 4512
	sw	$0, 4($3)
	.loc	3 4512
	.loc	3 4512
	.loc	3 4512
	move	$4, $16
	addu	$16, $16, 8
	.loc	3 4512
	li	$24, -1308622848
	sw	$24, 0($4)
	.loc	3 4512
	li	$25, 67109888
	sw	$25, 4($4)
	.loc	3 4512
	.loc	3 4512
	.loc	3 4513
 #4513	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xe4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((ptr->unk_B[1] * 10) + x_pos + 0x17) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0xB6 << 2) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((ptr->unk_B[1] * 10) + x_pos + 0xE) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0xB0 << 2) & ((0x01 << (12)) - 1)) << (0)))); { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -12))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (0))))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -13))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (0))))); };};
	.loc	3 4513
	move	$6, $16
	addu	$16, $16, 8
	.loc	3 4513
	lb	$12, 12($8)
	mul	$15, $12, $5
	addu	$13, $15, $9
	addu	$14, $13, 23
	sll	$24, $14, 2
	and	$25, $24, 4095
	sll	$12, $25, 12
	or	$15, $12, $10
	or	$13, $15, 728
	sw	$13, 0($6)
	.loc	3 4513
	lb	$14, 12($8)
	mul	$24, $14, $5
	addu	$25, $24, $9
	addu	$12, $25, 14
	sll	$15, $12, 2
	and	$13, $15, 4095
	sll	$14, $13, 12
	or	$24, $14, 704
	sw	$24, 4($6)
	.loc	3 4513
	.loc	3 4513
	move	$2, $16
	addu	$16, $16, 8
	.loc	3 4513
	sw	$11, 0($2)
	.loc	3 4513
	sw	$0, 4($2)
	.loc	3 4513
	.loc	3 4513
	.loc	3 4513
	move	$3, $16
	addu	$16, $16, 8
	.loc	3 4513
	li	$25, -1308622848
	sw	$25, 0($3)
	.loc	3 4513
	li	$12, 67109888
	sw	$12, 4($3)
	.loc	3 4513
	.loc	3 4513
	.loc	3 4514
 #4514	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xe4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((ptr->unk_B[2] * 10) + x_pos + 0x17) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0xD3 << 2) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((ptr->unk_B[2] * 10) + x_pos + 0xE) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0xCD << 2) & ((0x01 << (12)) - 1)) << (0)))); { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -12))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (0))))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -13))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (0))))); };};
	.loc	3 4514
	move	$4, $16
	addu	$16, $16, 8
	.loc	3 4514
	lb	$15, 13($8)
	mul	$13, $15, $5
	addu	$14, $13, $9
	addu	$24, $14, 23
	sll	$25, $24, 2
	and	$12, $25, 4095
	sll	$15, $12, 12
	or	$13, $15, $10
	or	$14, $13, 844
	sw	$14, 0($4)
	.loc	3 4514
	lb	$24, 13($8)
	mul	$25, $24, $5
	addu	$12, $25, $9
	addu	$15, $12, 14
	sll	$13, $15, 2
	and	$14, $13, 4095
	sll	$24, $14, 12
	or	$25, $24, 820
	sw	$25, 4($4)
	.loc	3 4514
	.loc	3 4514
	move	$7, $16
	addu	$16, $16, 8
	.loc	3 4514
	li	$12, -1291845632
	sw	$12, 0($7)
	.loc	3 4514
	sw	$0, 4($7)
	.loc	3 4514
	.loc	3 4514
	.loc	3 4514
	move	$2, $16
	addu	$16, $16, 8
	.loc	3 4514
	li	$15, -1308622848
	sw	$15, 0($2)
	.loc	3 4514
	li	$13, 67109888
	sw	$13, 4($2)
	.loc	3 4514
	.loc	3 4514
$97:
	lw	$9, 244($sp)
	li	$10, -469762048
	.loc	3 4516
 #4515	    }
 #4516	    gdl = func_801E946C(gdl, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
	move	$4, $16
	move	$5, $0
	li	$6, 255
	li	$7, 255
	li	$14, 255
	sw	$14, 16($sp)
	li	$24, 255
	sw	$24, 20($sp)
	li	$25, 255
	sw	$25, 24($sp)
	li	$12, 255
	sw	$12, 28($sp)
	li	$15, 255
	sw	$15, 32($sp)
	li	$13, 255
	sw	$13, 36($sp)
	li	$14, 255
	sw	$14, 40($sp)
	li	$24, 255
	sw	$24, 44($sp)
	li	$25, 255
	sw	$25, 48($sp)
	li	$12, 255
	sw	$12, 52($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E946C
	move	$16, $2
	.loc	3 4517
 #4517	    if (player == 0) {
	lw	$15, 76($sp)
	la	$13, D_800DA9C0
	bne	$15, $13, $98
	.loc	3 4517
	.loc	3 4518
 #4518	        gdl = func_801E3EE0(gdl, 2, 3, 0x26, 0x1C, 0);
	move	$4, $16
	li	$5, 2
	li	$6, 3
	li	$7, 38
	li	$14, 28
	sw	$14, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	.loc	3 4519
 #4519	        gdl = func_801E3EE0(gdl, 4, 0xC, 0xDE, 0x1A, 0);
	move	$4, $2
	li	$5, 4
	li	$6, 12
	li	$7, 222
	li	$24, 26
	sw	$24, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	.loc	3 4520
 #4520	        gdl = func_801E3EE0(gdl, 4, 0xD, 0xDE, 0x25, 0);
	move	$4, $2
	li	$5, 4
	li	$6, 13
	li	$7, 222
	li	$25, 37
	sw	$25, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
$98:
	.loc	3 4522
 #4521	    }
 #4522	    if (show_stats != 0) {
	lw	$12, 244($sp)
	beq	$12, 0, $105
	.loc	3 4522
	.loc	3 4523
 #4523	        if ((D_802C8C58.as_array[player] != 2) || (spE8 == 0)) {
	lw	$15, 84($sp)
	lw	$13, 0($15)
	bne	$13, 2, $99
	lw	$14, 232($sp)
	bne	$14, 0, $100
$99:
	.loc	3 4523
	.loc	3 4524
 #4524	            gdl = func_801E3EE0(gdl, 4, 9, x_pos + 0xD, 0x80, 0);
	move	$4, $16
	li	$5, 4
	li	$6, 9
	lw	$7, 220($sp)
	addu	$7, $7, 13
	li	$24, 128
	sw	$24, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
$100:
	.loc	3 4526
 #4525	        }
 #4526	        gdl = func_801E3EE0(gdl, 0, 6, x_pos + 0xD, 0x8A, 0);
	move	$4, $16
	move	$5, $0
	li	$6, 6
	lw	$7, 220($sp)
	addu	$7, $7, 13
	li	$25, 138
	sw	$25, 16($sp)
	sw	$0, 20($sp)
	sw	$7, 92($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	.loc	3 4527
 #4527	        gdl = func_801E3EE0(gdl, 0, 7, x_pos + 0x62, 0x8A, 0);
	move	$4, $2
	move	$5, $0
	li	$6, 7
	lw	$7, 220($sp)
	addu	$7, $7, 98
	li	$12, 138
	sw	$12, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
	.loc	3 4528
 #4528	        if ((D_802C8C58.as_array[player] != 3) || (spE8 == 0)) {
	lw	$15, 84($sp)
	lw	$13, 0($15)
	bne	$13, 3, $101
	lw	$14, 232($sp)
	bne	$14, 0, $102
$101:
	.loc	3 4528
	.loc	3 4529
 #4529	            gdl = func_801E3EE0(gdl, 4, 0xB, x_pos + 0xD, 0x9C, 0);
	move	$4, $16
	li	$5, 4
	li	$6, 11
	lw	$7, 92($sp)
	li	$24, 156
	sw	$24, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
$102:
	.loc	3 4531
 #4530	        }
 #4531	        gdl = func_801E3EE0(gdl, 0, 9, x_pos + 0xD, 0xA7, 0);
	move	$4, $16
	move	$5, $0
	li	$6, 9
	lw	$7, 92($sp)
	li	$25, 167
	sw	$25, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	.loc	3 4532
 #4532	        gdl = func_801E3EE0(gdl, 0, 0xA, x_pos + 0x59, 0xA7, 0);
	move	$4, $2
	move	$5, $0
	li	$6, 10
	lw	$7, 220($sp)
	addu	$7, $7, 89
	li	$12, 167
	sw	$12, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
	.loc	3 4533
 #4533	        if ((D_802C8C58.as_array[player] != 4) || (spE8 == 0)) {
	lw	$15, 84($sp)
	lw	$13, 0($15)
	bne	$13, 4, $103
	lw	$14, 232($sp)
	bne	$14, 0, $104
$103:
	.loc	3 4533
	.loc	3 4534
 #4534	            gdl = func_801E3EE0(gdl, 4, 0xA, x_pos + 0xD, 0xB9, 0);
	move	$4, $16
	li	$5, 4
	li	$6, 10
	lw	$7, 92($sp)
	li	$24, 185
	sw	$24, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
$104:
	.loc	3 4536
 #4535	        }
 #4536	        gdl = func_801E3EE0(gdl, 0, 0xC, x_pos + 0xD, 0xC4, 0);
	move	$4, $16
	move	$5, $0
	li	$6, 12
	lw	$7, 92($sp)
	li	$25, 196
	sw	$25, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	.loc	3 4537
 #4537	        gdl = func_801E3EE0(gdl, 0, 0xB, x_pos + 0x67, 0xC4, 0);
	move	$4, $2
	move	$5, $0
	li	$6, 11
	lw	$7, 220($sp)
	addu	$7, $7, 103
	li	$12, 196
	sw	$12, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
$105:
	.loc	3 4539
 #4538	    }
 #4539	    if (show_name != 0) {
	lw	$15, 236($sp)
	beq	$15, 0, $107
	.loc	3 4539
	.loc	3 4540
 #4540	        if (player == 0) {
	lw	$13, 76($sp)
	la	$14, D_800DA9C0
	bne	$13, $14, $106
	.loc	3 4540
	.loc	3 4541
 #4541	            gdl = func_801E9858(gdl, 1, ((UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298)[0][D_i2_802C8BD8[D_800DA9C0[player]]].unk_0, x_name, 0xCB);
	move	$4, $16
	li	$5, 1
	lw	$24, 0($13)
	mul	$25, $24, 4
	lw	$12, D_i2_802C8BD8($25)
	mul	$15, $12, 14
	la	$14, D_801CB298
	addu	$6, $15, $14
	lw	$7, 216($sp)
	li	$13, 203
	sw	$13, 16($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E9858
	move	$16, $2
	b	$107
$106:
	.loc	3 4542
 #4542	        } else {
	.loc	3 4543
 #4543	            gdl = func_801E9858(gdl, 1, D_800DA950[D_i2_802C8BD8[D_800DA9C0[player]]].unk_0, x_name, 0xCB);
	move	$4, $16
	li	$5, 1
	lw	$24, 76($sp)
	lw	$25, 0($24)
	mul	$12, $25, 4
	lw	$15, D_i2_802C8BD8($12)
	mul	$14, $15, 14
	la	$13, D_800DA950
	addu	$6, $14, $13
	lw	$7, 216($sp)
	li	$24, 203
	sw	$24, 16($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E9858
	move	$16, $2
$107:
	.loc	3 4546
 #4544	        }
 #4545	    }
 #4546	    if (show_banner != 0) {
	lw	$25, 240($sp)
	beq	$25, 0, $111
	.loc	3 4546
	.loc	3 4547
 #4547	        gdl = func_801E3EE0(gdl, 0, 0x25, x_pos + 0xC, 0x62, 0);
	move	$4, $16
	move	$5, $0
	li	$6, 37
	lw	$7, 220($sp)
	addu	$7, $7, 12
	li	$12, 98
	sw	$12, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
	.loc	3 4548
 #4548	        if ((D_800DA9C8[player] != 0) || (spE4 == 0)) {
	lw	$15, 88($sp)
	lw	$3, 0($15)
	bne	$3, 0, $108
	lw	$14, 228($sp)
	bne	$14, 0, $109
$108:
	.loc	3 4548
	.loc	3 4549
 #4549	            gdl = func_801E3EE0(gdl, 0, 3, x_pos + 0x15, 0x70, 0);
	move	$4, $16
	move	$5, $0
	li	$6, 3
	lw	$7, 220($sp)
	addu	$7, $7, 21
	li	$13, 112
	sw	$13, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
	lw	$24, 88($sp)
	lw	$3, 0($24)
$109:
	.loc	3 4551
 #4550	        }
 #4551	        if ((D_800DA9C8[player] != 1) || (spE4 == 0)) {
	bne	$3, 1, $110
	lw	$25, 228($sp)
	bne	$25, 0, $111
$110:
	.loc	3 4551
	.loc	3 4552
 #4552	            gdl = func_801E3EE0(gdl, 0, 0x26, x_pos + 0x54, 0x70, 0);
	move	$4, $16
	move	$5, $0
	li	$6, 38
	lw	$7, 220($sp)
	addu	$7, $7, 84
	li	$12, 112
	sw	$12, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
$111:
	.loc	3 4555
 #4553	        }
 #4554	    }
 #4555	    if (D_802C8C58.as_array[player] >= 5) {
	lw	$15, 84($sp)
	lw	$3, 0($15)
	blt	$3, 5, $114
	.loc	3 4555
	.loc	3 4556
 #4556	        gdl = func_801E946C(gdl, (D_802C8C58.as_array[player] == 5) ? 6 : 7, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
	bne	$3, 5, $112
	li	$5, 6
	b	$113
$112:
	li	$5, 7
$113:
	move	$4, $16
	li	$6, 128
	li	$7, 128
	li	$14, 128
	sw	$14, 16($sp)
	li	$13, 255
	sw	$13, 20($sp)
	li	$24, 255
	sw	$24, 24($sp)
	li	$25, 255
	sw	$25, 28($sp)
	li	$12, 255
	sw	$12, 32($sp)
	li	$15, 255
	sw	$15, 36($sp)
	li	$14, 255
	sw	$14, 40($sp)
	li	$13, 255
	sw	$13, 44($sp)
	li	$24, 255
	sw	$24, 48($sp)
	li	$25, 255
	sw	$25, 52($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E946C
	li	$3, -177728000
	.loc	3 4557
 #4557	        { { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfd) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((88)-1) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = (uintptr_t)(D_80BBFA8); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((87)-(0)+1) * 1)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe6) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((87)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((9)<<2) & ((0x01 << (12)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((87)-(0)+1) * 1)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf2) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((87)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((9)<<2) & ((0x01 << (12)) - 1)) << (0))); } };
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	li	$12, -43515817
	sw	$12, 0($2)
	.loc	3 4557
	la	$15, D_80BBFA8
	sw	$15, 4($2)
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	sw	$3, 8($2)
	.loc	3 4557
	li	$14, 117965312
	sw	$14, 12($2)
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	li	$13, -436207616
	sw	$13, 16($2)
	.loc	3 4557
	sw	$0, 20($2)
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	li	$24, -201326592
	sw	$24, 24($2)
	.loc	3 4557
	li	$25, 118865956
	sw	$25, 28($2)
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	li	$12, -419430400
	sw	$12, 32($2)
	.loc	3 4557
	sw	$0, 36($2)
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	sw	$3, 40($2)
	.loc	3 4557
	li	$15, 524800
	sw	$15, 44($2)
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	.loc	3 4557
	li	$14, -234881024
	sw	$14, 48($2)
	.loc	3 4557
	li	$13, 1425444
	sw	$13, 52($2)
	.loc	3 4557
	.loc	3 4558
 #4558	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xe4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((x_pos + 0x75) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0xAC << 2) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((x_pos + 0x1D) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0xA2 << 2) & ((0x01 << (12)) - 1)) << (0)))); { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -12))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (0))))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -13))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (0))))); };};
	.loc	3 4558
	.loc	3 4558
	lw	$24, 220($sp)
	addu	$25, $24, 117
	sll	$12, $25, 2
	and	$15, $12, 4095
	sll	$14, $15, 12
	or	$13, $14, -469762048
	or	$24, $13, 688
	sw	$24, 56($2)
	.loc	3 4558
	lw	$25, 220($sp)
	addu	$12, $25, 29
	sll	$15, $12, 2
	and	$14, $15, 4095
	sll	$13, $14, 12
	or	$24, $13, 648
	sw	$24, 60($2)
	.loc	3 4558
	.loc	3 4558
	.loc	3 4558
	li	$25, -1291845632
	sw	$25, 64($2)
	.loc	3 4558
	sw	$0, 68($2)
	.loc	3 4558
	.loc	3 4558
	.loc	3 4558
	addu	$16, $2, 80
	.loc	3 4558
	li	$12, -1308622848
	sw	$12, 72($2)
	.loc	3 4558
	li	$15, 67109888
	sw	$15, 76($2)
	.loc	3 4558
	.loc	3 4558
$114:
	.loc	3 4560
 #4559	    }
 #4560	    gdl = func_801E946C(gdl, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
	move	$4, $16
	li	$5, 6
	li	$6, 255
	li	$7, 255
	li	$14, 255
	sw	$14, 16($sp)
	li	$13, 255
	sw	$13, 20($sp)
	li	$24, 255
	sw	$24, 24($sp)
	li	$25, 255
	sw	$25, 28($sp)
	li	$12, 255
	sw	$12, 32($sp)
	li	$15, 255
	sw	$15, 36($sp)
	li	$14, 255
	sw	$14, 40($sp)
	li	$13, 255
	sw	$13, 44($sp)
	li	$24, 255
	sw	$24, 48($sp)
	li	$25, 255
	sw	$25, 52($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E946C
	move	$16, $2
	.loc	3 4561
 #4561	    if (show_stats != 0) {
	lw	$12, 244($sp)
	beq	$12, 0, $117
	.loc	3 4561
	.loc	3 4562
 #4562	        if ((D_802C8C58.as_array[player] == 2) && (spE8 != 0)) {
	lw	$15, 84($sp)
	lw	$3, 0($15)
	bne	$3, 2, $115
	lw	$14, 232($sp)
	beq	$14, 0, $115
	.loc	3 4562
	.loc	3 4563
 #4563	            gdl = func_801E3EE0(gdl, 4, 9, x_pos + 0xD, 0x80, 0);
	move	$4, $16
	li	$5, 4
	li	$6, 9
	lw	$7, 220($sp)
	addu	$7, $7, 13
	li	$13, 128
	sw	$13, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
	lw	$24, 84($sp)
	lw	$3, 0($24)
$115:
	.loc	3 4565
 #4564	        }
 #4565	        if ((D_802C8C58.as_array[player] == 3) && (spE8 != 0)) {
	bne	$3, 3, $116
	lw	$25, 232($sp)
	beq	$25, 0, $116
	.loc	3 4565
	.loc	3 4566
 #4566	            gdl = func_801E3EE0(gdl, 4, 0xB, x_pos + 0xD, 0x9C, 0);
	move	$4, $16
	li	$5, 4
	li	$6, 11
	lw	$7, 220($sp)
	addu	$7, $7, 13
	li	$12, 156
	sw	$12, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
	lw	$15, 84($sp)
	lw	$3, 0($15)
$116:
	.loc	3 4568
 #4567	        }
 #4568	        if ((D_802C8C58.as_array[player] == 4) && (spE8 != 0)) {
	bne	$3, 4, $117
	lw	$14, 232($sp)
	beq	$14, 0, $117
	.loc	3 4568
	.loc	3 4569
 #4569	            gdl = func_801E3EE0(gdl, 4, 0xA, x_pos + 0xD, 0xB9, 0);
	move	$4, $16
	li	$5, 4
	li	$6, 10
	lw	$7, 220($sp)
	addu	$7, $7, 13
	li	$13, 185
	sw	$13, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
$117:
	.loc	3 4572
 #4570	        }
 #4571	    }
 #4572	    if (show_banner != 0) {
	lw	$24, 240($sp)
	beq	$24, 0, $119
	.loc	3 4572
	.loc	3 4573
 #4573	        if ((D_800DA9C8[player] == 0) && (spE4 != 0)) {
	lw	$25, 88($sp)
	lw	$3, 0($25)
	bne	$3, 0, $118
	lw	$12, 228($sp)
	beq	$12, 0, $118
	.loc	3 4573
	.loc	3 4574
 #4574	            gdl = func_801E3EE0(gdl, 0, 3, x_pos + 0x15, 0x70, 0);
	move	$4, $16
	move	$5, $0
	li	$6, 3
	lw	$7, 220($sp)
	addu	$7, $7, 21
	li	$15, 112
	sw	$15, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
	lw	$14, 88($sp)
	lw	$3, 0($14)
$118:
	.loc	3 4576
 #4575	        }
 #4576	        if ((D_800DA9C8[player] == 1) && (spE4 != 0)) {
	bne	$3, 1, $119
	lw	$13, 228($sp)
	beq	$13, 0, $119
	.loc	3 4576
	.loc	3 4577
 #4577	            gdl = func_801E3EE0(gdl, 0, 0x26, x_pos + 0x54, 0x70, 0);
	move	$4, $16
	move	$5, $0
	li	$6, 38
	lw	$7, 220($sp)
	addu	$7, $7, 84
	li	$24, 112
	sw	$24, 16($sp)
	sw	$0, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E3EE0
	move	$16, $2
$119:
	.loc	3 4580
 #4578	        }
 #4579	    }
 #4580	    return gdl;
	move	$2, $16
	.livereg	0x2000FF0E,0x00000FFF
	lw	$16, 64($sp)
	lw	$31, 68($sp)
	addu	$sp, 248
	j	$31
	.end	func_i2_802C70EC
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C7C50
	.loc	3 4582
 #4581	}
 #4582	Gfx* func_i2_802C7C50(Gfx* gdl) {
	.ent	func_i2_802C7C50 2
func_i2_802C7C50:
	.option	O2
	subu	$sp, 32
	sw	$31, 28($sp)
	.mask	0x80000000, -4
	.frame	$sp, 32, $31
	li	$8, 100663296
	.loc	3 4582
	.loc	3 4585
 #4583	    u32 alpha;
 #4584	    s32 offset;
 #4585	    f32 f4 = 4.0f;
	.loc	3 4586
 #4586	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE358); };
	.loc	3 4586
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4586
	sw	$8, 0($2)
	.loc	3 4586
	la	$14, D_80BE358
	sw	$14, 4($2)
	.loc	3 4586
	.loc	3 4587
 #4587	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(D_106F628); };
	.loc	3 4587
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4587
	sw	$8, 0($3)
	.loc	3 4587
	la	$15, D_106F628
	sw	$15, 4($3)
	.loc	3 4587
	.loc	3 4588
 #4588	    gdl = func_80094338(gdl, 0, 0x1C, 0x16, 0x108, 0x1E);
	move	$5, $0
	li	$6, 28
	li	$7, 22
	li	$24, 264
	sw	$24, 16($sp)
	li	$25, 30
	sw	$25, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80094338
	la	$8, D_802C8C58
	move	$4, $2
	.loc	3 4589
 #4589	    if (D_802C8C58.player_1_ready != 0) {
	.noalias	$8,$sp
	lw	$14, 0($8)
	beq	$14, 0, $120
	.loc	3 4589
	.loc	3 4590
 #4590	        gdl = func_80094338(gdl, 0, 0x1C, 0x60, 0x82, 0xD);
	move	$5, $0
	li	$6, 28
	li	$7, 96
	li	$15, 130
	sw	$15, 16($sp)
	li	$24, 13
	sw	$24, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80094338
	.alias	$8,$sp
	.loc	3 4591
 #4591	        gdl = func_80094338(gdl, 0, 0x20, 0x6E, 0x3B, 0xD);
	move	$4, $2
	move	$5, $0
	li	$6, 32
	li	$7, 110
	li	$25, 59
	sw	$25, 16($sp)
	li	$14, 13
	sw	$14, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80094338
	.loc	3 4592
 #4592	        gdl = func_80094338(gdl, 0, 0x5F, 0x6E, 0x3B, 0xD);
	move	$4, $2
	move	$5, $0
	li	$6, 95
	li	$7, 110
	li	$15, 59
	sw	$15, 16($sp)
	li	$24, 13
	sw	$24, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80094338
	move	$4, $2
	la	$8, D_802C8C58
$120:
	.loc	3 4594
 #4593	    }
 #4594	    if (D_802C8C58.player_2_ready != 0) {
	.noalias	$8,$sp
	lw	$25, 4($8)
	beq	$25, 0, $121
	.loc	3 4594
	.loc	3 4595
 #4595	        gdl = func_80094338(gdl, 0, 0xA1, 0x60, 0x82, 0xD);
	move	$5, $0
	li	$6, 161
	li	$7, 96
	li	$14, 130
	sw	$14, 16($sp)
	li	$15, 13
	sw	$15, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80094338
	.alias	$8,$sp
	.loc	3 4596
 #4596	        gdl = func_80094338(gdl, 0, 0xA5, 0x6E, 0x3B, 0xD);
	move	$4, $2
	move	$5, $0
	li	$6, 165
	li	$7, 110
	li	$24, 59
	sw	$24, 16($sp)
	li	$25, 13
	sw	$25, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80094338
	.loc	3 4597
 #4597	        gdl = func_80094338(gdl, 0, 0xE4, 0x6E, 0x3B, 0xD);
	move	$4, $2
	move	$5, $0
	li	$6, 228
	li	$7, 110
	li	$14, 59
	sw	$14, 16($sp)
	li	$15, 13
	sw	$15, 20($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_80094338
	move	$4, $2
	la	$8, D_802C8C58
$121:
	.loc	3 4599
 #4598	    }
 #4599	    if (D_802C8C58.player_1_ready != 0) {
	.noalias	$8,$sp
	lw	$24, 0($8)
	beq	$24, 0, $122
	.loc	3 4599
	.loc	3 4600
 #4600	        gdl = func_i2_802C86E4(gdl, 0x13, 0x68);
	li	$5, 19
	li	$6, 104
	.livereg	0x0E00000E,0x00000000
	jal	func_i2_802C86E4
	.alias	$8,$sp
	move	$4, $2
	la	$8, D_802C8C58
$122:
	.loc	3 4602
 #4601	    }
 #4602	    if (D_802C8C58.player_2_ready != 0) {
	.noalias	$8,$sp
	lw	$25, 4($8)
	beq	$25, 0, $123
	.loc	3 4602
	.loc	3 4603
 #4603	        gdl = func_i2_802C86E4(gdl, 0x99, 0x68);
	li	$5, 153
	li	$6, 104
	.livereg	0x0E00000E,0x00000000
	jal	func_i2_802C86E4
	.alias	$8,$sp
	move	$4, $2
	la	$8, D_802C8C58
$123:
	.loc	3 4605
 #4604	    }
 #4605	    if ((D_802C8C58.player_1_ready != 0) && (D_802C8C58.player_1_ready < 5)) {
	.noalias	$8,$sp
	lw	$3, 0($8)
	beq	$3, 0, $124
	bge	$3, 5, $124
	.loc	3 4605
	.loc	3 4606
 #4606	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE2B8); };
	.loc	3 4606
	move	$3, $2
	addu	$4, $2, 8
	.loc	3 4606
	li	$14, 100663296
	sw	$14, 0($3)
	.loc	3 4606
	la	$15, D_80BE2B8
	sw	$15, 4($3)
	.loc	3 4606
$124:
	.loc	3 4608
 #4607	    }
 #4608	    if ((D_802C8C58.player_2_ready != 0) && (D_802C8C58.player_2_ready < 5)) {
	lw	$2, 4($8)
	beq	$2, 0, $125
	.alias	$8,$sp
	bge	$2, 5, $125
	.loc	3 4608
	.loc	3 4609
 #4609	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE3C8); };
	.loc	3 4609
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4609
	li	$24, 100663296
	sw	$24, 0($2)
	.loc	3 4609
	la	$25, D_80BE3C8
	sw	$25, 4($2)
	.loc	3 4609
$125:
	la	$7, D_802C8C6A
	.loc	3 4611
 #4610	    }
 #4611	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; };
	.loc	3 4611
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4611
	li	$14, -419430400
	sw	$14, 0($2)
	.loc	3 4611
	sw	$0, 4($2)
	.loc	3 4611
	.loc	3 4612
 #4612	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((-65 -6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(29) & ((0x01 << (8)) - 1)) << (0)))); _g->words.w1 = (unsigned int)((0x40 | 0x200 | 0x4000 | 0 | (0) << 30 | (0) << 26 | (1) << 22 | (0) << 18) | (0x40 | 0x200 | 0x4000 | 0 | (0) << 28 | (0) << 24 | (1) << 20 | (0) << 16)); };
	.loc	3 4612
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4612
	li	$15, -1191181539
	sw	$15, 0($3)
	.loc	3 4612
	li	$24, 5259840
	sw	$24, 4($3)
	.loc	3 4612
	.loc	3 4613
 #4613	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfc) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((((unsigned int) (((unsigned int)((1)) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)((3)) & ((0x01 << (5)) - 1)) << (15))) | ((unsigned int) (((unsigned int)((1)) & ((0x01 << (3)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((3)) & ((0x01 << (3)) - 1)) << (9)))) | (((unsigned int) (((unsigned int)((1)) & ((0x01 << (4)) - 1)) << (5))) | ((unsigned int) (((unsigned int)((3)) & ((0x01 << (5)) - 1)) << (0))))) & ((0x01 << (24)) - 1)) << (0))); _g->words.w1 = (unsigned int)((((unsigned int) (((unsigned int)((31)) & ((0x01 << (4)) - 1)) << (28))) | ((unsigned int) (((unsigned int)((31)) & ((0x01 << (3)) - 1)) << (15))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (9)))) | (((unsigned int) (((unsigned int)((31)) & ((0x01 << (4)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((1)) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)((3)) & ((0x01 << (3)) - 1)) << (18))) | ((unsigned int) (((unsigned int)((31)) & ((0x01 << (3)) - 1)) << (6))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (3))) | ((unsigned int) (((unsigned int)((7)) & ((0x01 << (3)) - 1)) << (0))))); };
	.loc	3 4613
	move	$5, $4
	addu	$4, $4, 8
	.loc	3 4613
	li	$25, -65956317
	sw	$25, 0($5)
	.loc	3 4613
	li	$14, -13631489
	sw	$14, 4($5)
	.loc	3 4613
	.loc	3 4614
 #4614	    if (D_802C8C6A == 0) {
	.noalias	$7,$sp
	lh	$6, 0($7)
	bne	$6, 0, $126
	la	$3, D_802C8C68
	li.s	$f0, 4.0
	.loc	3 4614
	.loc	3 4615
 #4615	        alpha = (u32) ((D_802C8C68 * 255.0f) / f4);
	.noalias	$3,$7
	.noalias	$3,$sp
	lh	$2, 0($3)
	mtc1	$2, $f4
	cvt.s.w	$f6, $f4
	li.s	$f8, 255.0
	mul.s	$f10, $f6, $f8
	div.s	$f16, $f10, $f0
	cfc1	$15, $31
	li	$11, 1
	ctc1	$11, $31
	cvt.w.s	$f18, $f16
	cfc1	$11, $31
	.set	 noat
	and	$1, $11, 4
	and	$11, $11, 120
	.set	 at
	beq	$11, 0, $132
	li.s	$f18, 2147483648.0
	sub.s	$f18, $f16, $f18
	li	$11, 1
	ctc1	$11, $31
	cvt.w.s	$f18, $f18
	cfc1	$11, $31
	.set	 noat
	and	$1, $11, 4
	and	$11, $11, 120
	.set	 at
	bne	$11, 0, $133
	.set	 noat
	mfc1	$11, $f18
	li	$1, -2147483648
	or	$11, $11, $1
	.set	 at
	b	$131
$133:
	li	$11, -1
	b	$131
$132:
	mfc1	$11, $f18
	blt	$11, 0, $133
$131:
	ctc1	$15, $31
	b	$127
$126:
	la	$3, D_802C8C68
	li.s	$f0, 4.0
	.loc	3 4616
 #4616	    } else {
	.loc	3 4617
 #4617	        alpha = (u32) (((f4 - D_802C8C68) * 255.0f) / f4);
	lh	$2, 0($3)
	mtc1	$2, $f4
	cvt.s.w	$f6, $f4
	sub.s	$f8, $f0, $f6
	li.s	$f10, 255.0
	mul.s	$f16, $f8, $f10
	div.s	$f18, $f16, $f0
	cfc1	$24, $31
	li	$11, 1
	ctc1	$11, $31
	cvt.w.s	$f4, $f18
	cfc1	$11, $31
	.set	 noat
	and	$1, $11, 4
	and	$11, $11, 120
	.set	 at
	beq	$11, 0, $135
	li.s	$f4, 2147483648.0
	sub.s	$f4, $f18, $f4
	li	$11, 1
	ctc1	$11, $31
	cvt.w.s	$f4, $f4
	cfc1	$11, $31
	.set	 noat
	and	$1, $11, 4
	and	$11, $11, 120
	.set	 at
	bne	$11, 0, $136
	.set	 noat
	mfc1	$11, $f4
	li	$1, -2147483648
	or	$11, $11, $1
	.set	 at
	b	$134
$136:
	li	$11, -1
	b	$134
$135:
	mfc1	$11, $f4
	blt	$11, 0, $136
$134:
	ctc1	$24, $31
$127:
	.loc	3 4619
 #4618	    }
 #4619	    D_802C8C68++;
	addu	$25, $2, 1
	sh	$25, 0($3)
	.loc	3 4620
 #4620	    if (D_802C8C68 >= 4) {
	lh	$14, 0($3)
	blt	$14, 4, $128
	.loc	3 4620
	.loc	3 4621
 #4621	        D_802C8C68 = 0;
	sh	$0, 0($3)
	.loc	3 4622
 #4622	        D_802C8C6A ^= 1;
	xor	$15, $6, 1
	sh	$15, 0($7)
	.alias	$3,$7
	.alias	$3,$sp
	.alias	$7,$sp
$128:
	la	$8, D_800DA9C0
	.loc	3 4624
 #4623	    }
 #4624	    if (D_800DA9C0[0] == D_800DA9C0[1]) {
	.noalias	$8,$sp
	lw	$24, 0($8)
	lw	$25, 4($8)
	bne	$24, $25, $129
	.loc	3 4624
	.loc	3 4625
 #4625	        offset = 0x20;
	li	$31, 32
	b	$130
$129:
	.loc	3 4626
 #4626	    } else {
	.loc	3 4627
 #4627	        offset = 0x40;
	li	$31, 64
$130:
	li	$12, -177729536
	.loc	3 4629
 #4628	    }
 #4629	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xfa) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (8)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(255) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(alpha) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(alpha) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(255) & ((0x01 << (8)) - 1)) << (0)))); };
	.loc	3 4629
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4629
	li	$14, -100663296
	sw	$14, 0($2)
	.loc	3 4629
	and	$7, $11, 255
	sll	$9, $7, 8
	sll	$15, $7, 16
	or	$24, $15, -16777216
	or	$25, $24, $9
	or	$14, $25, 255
	sw	$14, 4($2)
	.loc	3 4629
	.loc	3 4630
 #4630	    { { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfd) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((64)-1) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = (uintptr_t)(D_80B6E98); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((64 - 1)-(0)+1) * 1)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe6) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((64 - 1)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((36 - 1)<<2) & ((0x01 << (12)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((64 - 1)-(0)+1) * 1)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf2) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((64 - 1)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((36 - 1)<<2) & ((0x01 << (12)) - 1)) << (0))); } };
	.loc	3 4630
	.loc	3 4630
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4630
	li	$15, -43515841
	sw	$15, 0($3)
	.loc	3 4630
	la	$24, D_80B6E98
	sw	$24, 4($3)
	.loc	3 4630
	.loc	3 4630
	.loc	3 4630
	move	$5, $4
	addu	$4, $4, 8
	.loc	3 4630
	sw	$12, 0($5)
	.loc	3 4630
	li	$25, 117965312
	sw	$25, 4($5)
	.loc	3 4630
	.loc	3 4630
	.loc	3 4630
	move	$6, $4
	addu	$4, $4, 8
	.loc	3 4630
	li	$14, -436207616
	sw	$14, 0($6)
	.loc	3 4630
	sw	$0, 4($6)
	.loc	3 4630
	.loc	3 4630
	.loc	3 4630
	move	$10, $4
	addu	$4, $4, 8
	la	$13, D_i2_802C8BD0
	.loc	3 4630
	li	$15, -201326592
	sw	$15, 0($10)
	.loc	3 4630
	li	$24, 118472844
	sw	$24, 4($10)
	.loc	3 4630
	.loc	3 4630
	.loc	3 4630
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4630
	li	$25, -419430400
	sw	$25, 0($2)
	.loc	3 4630
	sw	$0, 4($2)
	.loc	3 4630
	.loc	3 4630
	.loc	3 4630
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4630
	sw	$12, 0($3)
	.loc	3 4630
	li	$14, 524800
	sw	$14, 4($3)
	.loc	3 4630
	.loc	3 4630
	.loc	3 4630
	move	$5, $4
	addu	$4, $4, 8
	.loc	3 4630
	li	$15, -234881024
	sw	$15, 0($5)
	.loc	3 4630
	li	$24, 1032332
	sw	$24, 4($5)
	.loc	3 4630
	.loc	3 4631
 #4631	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xe4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((D_i2_802C8BD0[D_800DA9C0[1]] + 72) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(91 << 2) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((D_i2_802C8BD0[D_800DA9C0[1]] + 8) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(55 << 2) & ((0x01 << (12)) - 1)) << (0)))); { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -12))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (0))))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -13))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (0))))); };};
	.loc	3 4631
	move	$6, $4
	addu	$4, $4, 8
	.loc	3 4631
	.noalias	$13,$8
	.noalias	$13,$sp
	lw	$25, 4($8)
	mul	$14, $25, 2
	addu	$15, $13, $14
	.noalias	$15,$8
	.noalias	$15,$sp
	lh	$24, 0($15)
	.alias	$15,$8
	.alias	$15,$sp
	addu	$25, $24, 72
	sll	$14, $25, 2
	and	$15, $14, 4095
	sll	$24, $15, 12
	or	$25, $24, -469762048
	or	$14, $25, 364
	sw	$14, 0($6)
	.loc	3 4631
	lw	$15, 4($8)
	mul	$24, $15, 2
	addu	$25, $13, $24
	.noalias	$25,$8
	.noalias	$25,$sp
	lh	$14, 0($25)
	.alias	$25,$8
	.alias	$25,$sp
	addu	$15, $14, 8
	sll	$24, $15, 2
	and	$25, $24, 4095
	sll	$14, $25, 12
	or	$15, $14, 220
	sw	$15, 4($6)
	.loc	3 4631
	.loc	3 4631
	move	$11, $4
	addu	$4, $4, 8
	li	$10, -1291845632
	.loc	3 4631
	sw	$10, 0($11)
	.loc	3 4631
	sw	$0, 4($11)
	.loc	3 4631
	.loc	3 4631
	.loc	3 4631
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4631
	li	$24, -1308622848
	sw	$24, 0($2)
	.loc	3 4631
	li	$25, 67109888
	sw	$25, 4($2)
	.loc	3 4631
	.loc	3 4631
	.loc	3 4632
 #4632	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xfa) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (8)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(alpha) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(255) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(alpha) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(255) & ((0x01 << (8)) - 1)) << (0)))); };
	.loc	3 4632
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4632
	li	$14, -100663296
	sw	$14, 0($3)
	.loc	3 4632
	sll	$15, $7, 24
	or	$24, $15, 16711680
	or	$25, $24, $9
	or	$14, $25, 255
	sw	$14, 4($3)
	.loc	3 4632
	.loc	3 4633
 #4633	    { { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfd) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((64)-1) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = (uintptr_t)(D_80B6590); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((64 - 1)-(0)+1) * 1)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe6) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((64 - 1)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((36 - 1)<<2) & ((0x01 << (12)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(3) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(1) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((64 - 1)-(0)+1) * 1)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf2) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((64 - 1)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((36 - 1)<<2) & ((0x01 << (12)) - 1)) << (0))); } };
	.loc	3 4633
	.loc	3 4633
	move	$5, $4
	addu	$4, $4, 8
	.loc	3 4633
	li	$15, -43515841
	sw	$15, 0($5)
	.loc	3 4633
	la	$24, D_80B6590
	sw	$24, 4($5)
	.loc	3 4633
	.loc	3 4633
	.loc	3 4633
	move	$6, $4
	addu	$4, $4, 8
	.loc	3 4633
	sw	$12, 0($6)
	.loc	3 4633
	li	$25, 117965312
	sw	$25, 4($6)
	.loc	3 4633
	.loc	3 4633
	.loc	3 4633
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4633
	li	$14, -436207616
	sw	$14, 0($2)
	.loc	3 4633
	sw	$0, 4($2)
	.loc	3 4633
	.loc	3 4633
	.loc	3 4633
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4633
	li	$15, -201326592
	sw	$15, 0($3)
	.loc	3 4633
	li	$24, 118472844
	sw	$24, 4($3)
	.loc	3 4633
	.loc	3 4633
	.loc	3 4633
	move	$5, $4
	addu	$4, $4, 8
	.loc	3 4633
	li	$25, -419430400
	sw	$25, 0($5)
	.loc	3 4633
	sw	$0, 4($5)
	.loc	3 4633
	.loc	3 4633
	.loc	3 4633
	move	$6, $4
	addu	$4, $4, 8
	.loc	3 4633
	sw	$12, 0($6)
	.loc	3 4633
	li	$14, 524800
	sw	$14, 4($6)
	.loc	3 4633
	.loc	3 4633
	.loc	3 4633
	move	$7, $4
	addu	$4, $4, 8
	.loc	3 4633
	li	$15, -234881024
	sw	$15, 0($7)
	.loc	3 4633
	li	$24, 1032332
	sw	$24, 4($7)
	.loc	3 4633
	.loc	3 4634
 #4634	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xe4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((D_i2_802C8BD0[D_800DA9C0[0]] + offset + 8) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(91 << 2) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((D_i2_802C8BD0[D_800DA9C0[0]] + 8) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(55 << 2) & ((0x01 << (12)) - 1)) << (0)))); { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -12))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (0))))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -13))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (0))))); };};
	.loc	3 4634
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4634
	lw	$25, 0($8)
	mul	$14, $25, 2
	addu	$15, $13, $14
	.noalias	$15,$8
	.noalias	$15,$sp
	lh	$24, 0($15)
	.alias	$15,$8
	.alias	$15,$sp
	addu	$25, $24, $31
	addu	$14, $25, 8
	sll	$15, $14, 2
	and	$24, $15, 4095
	sll	$25, $24, 12
	or	$14, $25, -469762048
	or	$15, $14, 364
	sw	$15, 0($2)
	.loc	3 4634
	lw	$24, 0($8)
	mul	$25, $24, 2
	addu	$14, $13, $25
	.noalias	$14,$8
	.noalias	$14,$sp
	lh	$15, 0($14)
	.alias	$14,$8
	.alias	$14,$sp
	addu	$24, $15, 8
	sll	$25, $24, 2
	and	$14, $25, 4095
	sll	$15, $14, 12
	or	$24, $15, 220
	sw	$24, 4($2)
	.loc	3 4634
	.loc	3 4634
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4634
	sw	$10, 0($3)
	.loc	3 4634
	sw	$0, 4($3)
	.loc	3 4634
	.loc	3 4634
	.loc	3 4634
	move	$6, $4
	addu	$4, $4, 8
	.loc	3 4634
	li	$25, -1308622848
	sw	$25, 0($6)
	.loc	3 4634
	li	$14, 67109888
	sw	$14, 4($6)
	.loc	3 4634
	.loc	3 4634
	.loc	3 4635
 #4635	    gdl = func_i2_802C70EC(gdl, 0);
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C70EC
	.alias	$8,$13
	.alias	$8,$sp
	.alias	$13,$sp
	.loc	3 4636
 #4636	    gdl = func_i2_802C70EC(gdl, 1);
	move	$4, $2
	li	$5, 1
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C70EC
	li	$3, 100663296
	.loc	3 4637
 #4637	    gdl->words.w0 = 0xB4000000;
	li	$15, -1275068416
	sw	$15, 0($2)
	.loc	3 4638
 #4638	    gdl->words.w1 = D_802C8C50;
	lhu	$24, D_802C8C50
	sw	$24, 4($2)
	.loc	3 4639
 #4639	    gdl++;
	.loc	3 4640
 #4640	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x01)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_7000A40); };
	.loc	3 4640
	.loc	3 4640
	li	$25, 16973888
	sw	$25, 8($2)
	.loc	3 4640
	la	$14, D_7000A40
	sw	$14, 12($2)
	.loc	3 4640
	.loc	3 4641
 #4641	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_106F488); };
	.loc	3 4641
	.loc	3 4641
	sw	$3, 16($2)
	.loc	3 4641
	la	$15, D_106F488
	sw	$15, 20($2)
	.loc	3 4641
	.loc	3 4642
 #4642	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE468); };
	.loc	3 4642
	.loc	3 4642
	sw	$3, 24($2)
	.loc	3 4642
	la	$24, D_80BE468
	sw	$24, 28($2)
	.loc	3 4642
	.loc	3 4643
 #4643	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_7000A80); };
	.loc	3 4643
	.loc	3 4643
	li	$25, 16908352
	sw	$25, 32($2)
	.loc	3 4643
	la	$14, D_7000A80
	sw	$14, 36($2)
	.loc	3 4643
	.loc	3 4644
 #4644	    gdl = func_801E4FE8(gdl, 0, 0, 0, (u8*) D_801CE5F8 + 0xC80);
	addu	$4, $2, 40
	move	$5, $0
	move	$6, $0
	move	$7, $0
	lw	$15, D_801CE5F8
	addu	$24, $15, 3200
	sw	$24, 16($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E4FE8
	.loc	3 4645
 #4645	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE478); };
	.loc	3 4645
	.loc	3 4645
	li	$25, 100663296
	sw	$25, 0($2)
	.loc	3 4645
	la	$14, D_80BE478
	sw	$14, 4($2)
	.loc	3 4645
	.loc	3 4646
 #4646	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_7000AC0); };
	.loc	3 4646
	.loc	3 4646
	li	$15, 16908352
	sw	$15, 8($2)
	.loc	3 4646
	la	$24, D_7000AC0
	sw	$24, 12($2)
	.loc	3 4646
	.loc	3 4647
 #4647	    gdl = func_801E4FE8(gdl, 2, 0, 0, (u8*) D_801CE5F8 + 0xD40);
	addu	$4, $2, 16
	li	$5, 2
	move	$6, $0
	move	$7, $0
	lw	$25, D_801CE5F8
	addu	$14, $25, 3392
	sw	$14, 16($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E4FE8
	.loc	3 4648
 #4648	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE488); };
	.loc	3 4648
	.loc	3 4648
	li	$15, 100663296
	sw	$15, 0($2)
	.loc	3 4648
	la	$24, D_80BE488
	sw	$24, 4($2)
	.loc	3 4648
	.loc	3 4649
 #4649	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_7000B00); };
	.loc	3 4649
	.loc	3 4649
	li	$25, 16908352
	sw	$25, 8($2)
	.loc	3 4649
	la	$14, D_7000B00
	sw	$14, 12($2)
	.loc	3 4649
	.loc	3 4650
 #4650	    gdl = func_801E4FE8(gdl, 3, 0, 0, (u8*) D_801CE5F8 + 0xE00);
	addu	$4, $2, 16
	li	$5, 3
	move	$6, $0
	move	$7, $0
	lw	$15, D_801CE5F8
	addu	$24, $15, 3584
	sw	$24, 16($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E4FE8
	.loc	3 4651
 #4651	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((6)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((0)) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_80BE498); };
	.loc	3 4651
	.loc	3 4651
	li	$25, 100663296
	sw	$25, 0($2)
	.loc	3 4651
	la	$14, D_80BE498
	sw	$14, 4($2)
	.loc	3 4651
	.loc	3 4652
 #4652	    { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)((1)) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0x00 | 0x02 | 0x00)) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((sizeof(Mtx))) & ((0x01 << (16)) - 1)) << (0)))); _g->words.w1 = (uintptr_t)(&D_7000B40); };
	.loc	3 4652
	.loc	3 4652
	li	$15, 16908352
	sw	$15, 8($2)
	.loc	3 4652
	la	$24, D_7000B40
	sw	$24, 12($2)
	.loc	3 4652
	.loc	3 4653
 #4653	    return func_801E4FE8(gdl, 1, 0, 0, (u8*) D_801CE5F8 + 0xEC0);
	addu	$4, $2, 16
	li	$5, 1
	move	$6, $0
	move	$7, $0
	lw	$25, D_801CE5F8
	addu	$14, $25, 3776
	sw	$14, 16($sp)
	.livereg	0x0F00000E,0x00000000
	jal	func_801E4FE8
	.livereg	0x2000FF0E,0x00000FFF
	lw	$31, 28($sp)
	addu	$sp, 32
	j	$31
	.end	func_i2_802C7C50
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C84EC
	.loc	3 4655
 #4654	}
 #4655	void func_i2_802C84EC(s32 arg0) {
	.ent	func_i2_802C84EC 2
func_i2_802C84EC:
	.option	O2
	subu	$sp, 32
	sw	$31, 28($sp)
	sw	$17, 24($sp)
	sw	$16, 20($sp)
	.mask	0x80030000, -4
	.frame	$sp, 32, $31
	la	$2, gGameState
	.loc	3 4655
	.loc	3 4660
 #4656	    s32 i;
 #4657	    UnkStruct_func_i8_802C6E00* ptr;
 #4658	    struct UnkStruct_80192690* rider;
 #4659	    s32 rider_idx;
 #4660	    gPrevGameState = gGameState;
	.noalias	$2,$sp
	lw	$14, 0($2)
	sw	$14, gPrevGameState
	.loc	3 4661
 #4661	    D_801CE630 = arg0;
	sw	$4, D_801CE630
	.loc	3 4662
 #4662	    gGameState = 0xB;
	li	$15, 11
	sw	$15, 0($2)
	.loc	3 4663
 #4663	    D_801CE638 = 4;
	li	$24, 4
	sw	$24, D_801CE638
	.loc	3 4664
 #4664	    D_801CE63C = 1;
	li	$25, 1
	sw	$25, D_801CE63C
	.loc	3 4665
 #4665	    D_801CE640 = 0;
	sw	$0, D_801CE640
	.loc	3 4666
 #4666	    D_801CE644 = 0;
	sw	$0, D_801CE644
	.loc	3 4667
 #4667	    D_800DAB1C = 0;
	sw	$0, D_800DAB1C
	.loc	3 4668
 #4668	    D_800D461C = 3;
	li	$14, 3
	sw	$14, D_800D461C
	.loc	3 4669
 #4669	    for (i = 0; i < D_801CE60C; i++) {
	move	$3, $0
	lh	$10, D_801CE60C
	ble	$10, 0, $142
	.alias	$2,$sp
	la	$7, D_800DA9C8
	la	$6, D_800DA9C0
	la	$17, D_801CB298
	la	$16, D_800D48E0
	li	$31, 5912
	la	$13, D_80192690
	la	$12, D_800D48DC
	la	$11, D_800DA950
	li	$9, 14
	la	$8, D_i2_802C8BD8
$137:
	.loc	3 4669
	.loc	3 4670
 #4670	        if (D_800DA9C8[i] == 0) {
	.noalias	$7,$sp
	lw	$15, 0($7)
	bne	$15, 0, $138
	.loc	3 4670
	.loc	3 4671
 #4671	            ptr = &D_800DA950[D_i2_802C8BD8[D_800DA9C0[i]]];
	.noalias	$8,$7
	.noalias	$8,$sp
	.noalias	$6,$7
	.noalias	$6,$8
	.noalias	$6,$sp
	lw	$24, 0($6)
	mul	$25, $24, 4
	addu	$14, $8, $25
	.noalias	$14,$6
	.noalias	$14,$7
	.noalias	$14,$sp
	lw	$15, 0($14)
	.alias	$14,$6
	.alias	$14,$7
	.alias	$14,$sp
	mul	$24, $15, $9
	addu	$4, $11, $24
	b	$139
$138:
	.loc	3 4672
 #4672	        } else {
	.loc	3 4673
 #4673	            ptr = &((UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298)[i][D_i2_802C8BD8[D_800DA9C0[i]]];
	mul	$25, $3, 56
	addu	$14, $17, $25
	lw	$15, 0($6)
	mul	$24, $15, 4
	addu	$25, $8, $24
	.noalias	$25,$6
	.noalias	$25,$7
	.noalias	$25,$sp
	lw	$15, 0($25)
	.alias	$25,$6
	.alias	$25,$7
	.alias	$25,$sp
	mul	$24, $15, $9
	addu	$4, $14, $24
$139:
	.loc	3 4675
 #4674	        }
 #4675	        rider_idx = (i == 0) ? D_800D48DC : D_800D48E0;
	bne	$3, 0, $140
	.noalias	$12,$6
	.noalias	$12,$7
	.noalias	$12,$8
	.noalias	$12,$sp
	lw	$5, 0($12)
	b	$141
$140:
	.noalias	$16,$6
	.noalias	$16,$7
	.noalias	$16,$8
	.noalias	$16,$12
	.noalias	$16,$sp
	lw	$5, 0($16)
$141:
	.loc	3 4676
 #4676	        rider = &D_80192690[rider_idx];
	.loc	3 4677
 #4677	        rider->unkB6C = ptr->unk_B[0];
	.noalias	$13,$6
	.noalias	$13,$7
	.noalias	$13,$8
	.noalias	$13,$12
	.noalias	$13,$16
	.noalias	$13,$sp
	.noalias	$2,$6
	.noalias	$2,$7
	.noalias	$2,$8
	.noalias	$2,$12
	.noalias	$2,$16
	.noalias	$2,$sp
	mul	$25, $5, $31
	addu	$2, $13, $25
	lb	$15, 11($4)
	sw	$15, 2924($2)
	.loc	3 4678
 #4678	        rider->unkB70 = ptr->unk_B[1];
	lb	$14, 12($4)
	sw	$14, 2928($2)
	.loc	3 4679
 #4679	        rider->unkB74 = ptr->unk_B[2];
	lb	$24, 13($4)
	sw	$24, 2932($2)
	.loc	3 4669
 #4669	    for (i = 0; i < D_801CE60C; i++) {
	addu	$3, $3, 1
	addu	$7, $7, 4
	addu	$6, $6, 4
	blt	$3, $10, $137
	.alias	$2,$6
	.alias	$2,$7
	.alias	$2,$8
	.alias	$2,$12
	.alias	$2,$16
	.alias	$2,$sp
	.alias	$6,$7
	.alias	$6,$8
	.alias	$6,$12
	.alias	$6,$13
	.alias	$6,$16
	.alias	$6,$sp
	.alias	$7,$8
	.alias	$7,$12
	.alias	$7,$13
	.alias	$7,$16
	.alias	$7,$sp
	.alias	$8,$12
	.alias	$8,$13
	.alias	$8,$16
	.alias	$8,$sp
	.alias	$12,$13
	.alias	$12,$16
	.alias	$12,$sp
	.alias	$13,$16
	.alias	$13,$sp
	.alias	$16,$sp
$142:
	.loc	3 4681
 #4681	    if (D_801CE608.gameMode == 4 && D_801CE630 == 30) {
	lw	$25, D_801CE608
	bne	$25, 4, $143
	lw	$15, D_801CE630
	bne	$15, 30, $143
	.loc	3 4681
	.loc	3 4682
 #4682	        FadeTransition_SetProps(5, 0, 0);
	li	$4, 5
	move	$5, $0
	move	$6, $0
	.livereg	0x0E00000E,0x00000000
	jal	FadeTransition_SetProps
	b	$144
$143:
	.loc	3 4683
 #4683	    } else {
	.loc	3 4684
 #4684	        FadeTransition_SetProps(1, 4, 0);
	li	$4, 1
	li	$5, 4
	move	$6, $0
	.livereg	0x0E00000E,0x00000000
	jal	FadeTransition_SetProps
$144:
	.loc	3 4686
 #4685	    }
 #4686	    func_801E6A4C(0, 0);
	move	$4, $0
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	func_801E6A4C
	.loc	3 4687
 #4687	    if (D_801CE630 == 30) {
	lw	$14, D_801CE630
	bne	$14, 30, $145
	.loc	3 4687
	.loc	3 4688
 #4688	        func_800C1F60(2);
	li	$4, 2
	.livereg	0x0800000E,0x00000000
	jal	func_800C1F60
	.loc	3 4690
 #4689	    }
 #4690	}
$145:
	.livereg	0x0000FF0E,0x00000FFF
	lw	$16, 20($sp)
	lw	$17, 24($sp)
	lw	$31, 28($sp)
	addu	$sp, 32
	j	$31
	.end	func_i2_802C84EC
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C86E4
	.loc	3 4691
 #4691	Gfx* func_i2_802C86E4(Gfx* gdl, s32 x, s32 y) {
	.ent	func_i2_802C86E4 2
func_i2_802C86E4:
	.option	O2
	subu	$sp, 48
	sw	$31, 44($sp)
	sw	$30, 40($sp)
	sw	$23, 36($sp)
	sw	$22, 32($sp)
	sw	$21, 28($sp)
	sw	$20, 24($sp)
	sw	$19, 20($sp)
	sw	$18, 16($sp)
	sw	$17, 12($sp)
	sw	$16, 8($sp)
	.mask	0xC0FF0000, -4
	.frame	$sp, 48, $31
	.loc	3 4691
	.loc	3 4697
 #4692	    s32 cur_y;
 #4693	    s32 tex_offset;
 #4694	    s32 i;
 #4695	    s32 y2;
 #4696	    s32 height;
 #4697	    while (0) {
	.loc	3 4700
 #4698	        cur_y = 0;
 #4699	    }
 #4700	    for (tex_offset = 0, i = 0, cur_y = y, y2 = y + 20; i != 105; i += 15, y2 += 15, cur_y += 15, tex_offset += 1950) {
	move	$12, $0
	move	$10, $0
	move	$11, $6
	addu	$13, $6, 20
	addu	$17, $5, 138
	sll	$14, $17, 2
	move	$17, $14
	and	$15, $17, 4095
	move	$17, $15
	sll	$24, $17, 12
	move	$17, $24
	or	$25, $17, -469762048
	move	$17, $25
	addu	$18, $5, 8
	sll	$14, $18, 2
	move	$18, $14
	and	$15, $18, 4095
	move	$18, $15
	sll	$24, $18, 12
	move	$18, $24
	li	$31, 119554048
	li	$30, -201326592
	li	$23, -436207616
	li	$22, 117965312
	la	$21, D_80B0008
	li	$20, -49282943
	li	$19, 90
	li	$16, -183483904
$146:
	.loc	3 4700
	.loc	3 4701
 #4701	        if (i != 90) {
	beq	$10, $19, $147
	.loc	3 4701
	.loc	3 4702
 #4702	            height = 15;
	li	$7, 15
	b	$148
$147:
	.loc	3 4703
 #4703	        } else {
	.loc	3 4704
 #4704	            height = 2;
	li	$7, 2
$148:
	.loc	3 4706
 #4705	        }
 #4706	        { { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfd) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((130)-1) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = (uintptr_t)((u8*) D_80B0008 + (tex_offset << 1)); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((130 - 1)-(0)+1) * 2)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe6) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((130 - 1)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((height - 1)<<2) & ((0x01 << (12)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((((130 - 1)-(0)+1) * 2)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf2) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((0)<<2) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((130 - 1)<<2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((height - 1)<<2) & ((0x01 << (12)) - 1)) << (0))); } };
	.loc	3 4706
	.loc	3 4706
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4706
	sw	$20, 0($2)
	.loc	3 4706
	sll	$25, $12, 1
	addu	$14, $21, $25
	sw	$14, 4($2)
	.loc	3 4706
	.loc	3 4706
	.loc	3 4706
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4706
	sw	$16, 0($3)
	.loc	3 4706
	sw	$22, 4($3)
	.loc	3 4706
	.loc	3 4706
	.loc	3 4706
	move	$5, $4
	addu	$4, $4, 8
	.loc	3 4706
	sw	$23, 0($5)
	.loc	3 4706
	sw	$0, 4($5)
	.loc	3 4706
	.loc	3 4706
	.loc	3 4706
	move	$6, $4
	addu	$4, $4, 8
	.loc	3 4706
	sw	$30, 0($6)
	.loc	3 4706
	addu	$8, $7, -1
	sll	$15, $8, 2
	move	$8, $15
	and	$24, $8, 4095
	move	$8, $24
	or	$25, $8, $31
	sw	$25, 4($6)
	.loc	3 4706
	.loc	3 4706
	.loc	3 4706
	move	$9, $4
	addu	$4, $4, 8
	.loc	3 4706
	li	$14, -419430400
	sw	$14, 0($9)
	.loc	3 4706
	sw	$0, 4($9)
	.loc	3 4706
	.loc	3 4706
	.loc	3 4706
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4706
	sw	$16, 0($2)
	.loc	3 4706
	li	$15, 524800
	sw	$15, 4($2)
	.loc	3 4706
	.loc	3 4706
	.loc	3 4706
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4706
	li	$24, -234881024
	sw	$24, 0($3)
	.loc	3 4706
	or	$25, $8, 2113536
	sw	$25, 4($3)
	.loc	3 4706
	.loc	3 4707
 #4707	        { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xe4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((x + 138) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((cur_y + height + 20) << 2) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((x + 8) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(y2 << 2) & ((0x01 << (12)) - 1)) << (0)))); { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -12))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (0))))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -13))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (0))))); };};
	.loc	3 4707
	move	$5, $4
	addu	$4, $4, 8
	.loc	3 4707
	addu	$14, $11, $7
	addu	$15, $14, 20
	sll	$24, $15, 2
	and	$25, $24, 4095
	or	$14, $17, $25
	sw	$14, 0($5)
	.loc	3 4707
	sll	$15, $13, 2
	and	$24, $15, 4095
	or	$25, $18, $24
	sw	$25, 4($5)
	.loc	3 4707
	.loc	3 4707
	move	$2, $4
	addu	$4, $4, 8
	.loc	3 4707
	li	$14, -1291845632
	sw	$14, 0($2)
	.loc	3 4707
	sw	$0, 4($2)
	.loc	3 4707
	.loc	3 4707
	.loc	3 4707
	move	$3, $4
	addu	$4, $4, 8
	.loc	3 4707
	li	$15, -1308622848
	sw	$15, 0($3)
	.loc	3 4707
	li	$24, 67109888
	sw	$24, 4($3)
	.loc	3 4707
	.loc	3 4707
	.loc	3 4700
 #4700	    for (tex_offset = 0, i = 0, cur_y = y, y2 = y + 20; i != 105; i += 15, y2 += 15, cur_y += 15, tex_offset += 1950) {
	addu	$10, $10, 15
	addu	$13, $13, 15
	addu	$11, $11, 15
	addu	$12, $12, 1950
	bne	$10, 105, $146
	.loc	3 4709
 #4709	    return gdl;
	move	$2, $4
	.livereg	0x2000FF0E,0x00000FFF
	lw	$16, 8($sp)
	lw	$17, 12($sp)
	lw	$18, 16($sp)
	lw	$19, 20($sp)
	lw	$20, 24($sp)
	lw	$21, 28($sp)
	lw	$22, 32($sp)
	lw	$23, 36($sp)
	lw	$31, 44($sp)
	lw	$30, 40($sp)
	addu	$sp, 48
	j	$31
	.end	func_i2_802C86E4
	.text	
	.align	2
	.file	3 "./ctx.c"
	.globl	func_i2_802C88DC
	.loc	3 4711
 #4710	}
 #4711	Gfx* func_i2_802C88DC(Gfx* gdl) {
	.ent	func_i2_802C88DC 2
func_i2_802C88DC:
	.option	O2
	subu	$sp, 120
	sw	$31, 44($sp)
	sw	$30, 40($sp)
	sw	$23, 36($sp)
	sw	$22, 32($sp)
	sw	$21, 28($sp)
	sw	$20, 24($sp)
	sw	$19, 20($sp)
	sw	$18, 16($sp)
	sw	$17, 12($sp)
	sw	$16, 8($sp)
	.mask	0xC0FF0000, -76
	.frame	$sp, 120, $31
	move	$7, $4
	.loc	3 4711
	.loc	3 4717
 #4712	    s32 pad[15];
 #4713	    s32 outer;
 #4714	    s32 tex_offset;
 #4715	    s32 height;
 #4716	    s32 row;
 #4717	    s32 cur_y = 0;
	.loc	3 4721
 #4718	    s32 next_y;
 #4719	    s32 col;
 #4720	    s32 cur_x;
 #4721	    for (outer = 0, tex_offset = 0; outer != 100; outer += 5, tex_offset += 480) {
	move	$31, $0
	sw	$0, 52($sp)
	li	$30, 288
	li	$20, 480
	li	$19, 67109888
	li	$18, -1308622848
	li	$17, -1291845632
	li	$16, -469762048
$149:
	.loc	3 4721
	.loc	3 4722
 #4722	        if (outer == 95) {
	bne	$31, 95, $150
	.loc	3 4722
	.loc	3 4723
 #4723	            height = 1;
	li	$6, 1
	b	$151
$150:
	.loc	3 4724
 #4724	        } else {
	.loc	3 4725
 #4725	            height = 5;
	li	$6, 5
$151:
	.loc	3 4727
 #4726	        }
 #4727	        { { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfd) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((1)-1) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = (uintptr_t)(D_80B77A0 + tex_offset); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe6) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xf3) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((((((96)*(height) + 0) >> 0) -1) < (2047) ? ((((96)*(height) + 0) >> 0) -1) : (2047)))) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((((1 << 11) + ((1) > (((96)*(2)/8)) ? (1) : (((96)*(2)/8))) - 1) / ((1) > (((96)*(2)/8)) ? (1) : (((96)*(2)/8))))) & ((0x01 << (12)) - 1)) << (0)))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((96) * 2)+7)>>3) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0x2) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf2) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((96)-1) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(((height)-1) << 2) & ((0x01 << (12)) - 1)) << (0))); } };
	.loc	3 4727
	.loc	3 4727
	move	$2, $7
	addu	$7, $7, 8
	.loc	3 4727
	li	$14, -49283072
	sw	$14, 0($2)
	.loc	3 4727
	lw	$15, 52($sp)
	sll	$24, $15, 1
	la	$25, D_80B77A0
	addu	$14, $24, $25
	sw	$14, 4($2)
	.loc	3 4727
	.loc	3 4727
	.loc	3 4727
	move	$3, $7
	addu	$7, $7, 8
	.loc	3 4727
	li	$15, -183500800
	sw	$15, 0($3)
	.loc	3 4727
	li	$24, 117965312
	sw	$24, 4($3)
	.loc	3 4727
	.loc	3 4727
	.loc	3 4727
	move	$4, $7
	addu	$7, $7, 8
	.loc	3 4727
	li	$25, -436207616
	sw	$25, 0($4)
	.loc	3 4727
	sw	$0, 4($4)
	.loc	3 4727
	.loc	3 4727
	.loc	3 4727
	move	$8, $7
	addu	$7, $7, 8
	.loc	3 4727
	li	$14, -218103808
	sw	$14, 0($8)
	.loc	3 4727
	mul	$5, $6, 96
	addu	$5, $5, -1
	bge	$5, 2047, $152
	move	$3, $5
	b	$153
$152:
	li	$3, 2047
$153:
	and	$15, $3, 4095
	sll	$24, $15, 12
	or	$25, $24, 117440512
	or	$14, $25, 86
	sw	$14, 4($8)
	.loc	3 4727
	.loc	3 4727
	.loc	3 4727
	move	$2, $7
	addu	$7, $7, 8
	.loc	3 4727
	li	$15, -419430400
	sw	$15, 0($2)
	.loc	3 4727
	sw	$0, 4($2)
	.loc	3 4727
	.loc	3 4727
	.loc	3 4727
	move	$4, $7
	addu	$7, $7, 8
	.loc	3 4727
	li	$24, -183488512
	sw	$24, 0($4)
	.loc	3 4727
	li	$25, 524800
	sw	$25, 4($4)
	.loc	3 4727
	.loc	3 4727
	.loc	3 4727
	move	$5, $7
	addu	$7, $7, 8
	.loc	3 4727
	li	$14, -234881024
	sw	$14, 0($5)
	.loc	3 4727
	addu	$15, $6, -1
	sll	$24, $15, 2
	and	$25, $24, 4095
	or	$14, $25, 1556480
	sw	$14, 4($5)
	.loc	3 4727
	.loc	3 4728
 #4728	        for (row = 0, cur_y = outer, next_y = outer + height; row != 288; row += 96, cur_y += 96, next_y += 96) {
	move	$22, $0
	move	$21, $31
	addu	$23, $31, $6
$154:
	.loc	3 4728
	.loc	3 4729
 #4729	            for (cur_x = 0, col = 96; col != 480; cur_x += 96, col += 96) {
	move	$10, $0
	li	$9, 96
	sll	$12, $23, 2
	sll	$11, $21, 2
	sll	$13, $11, 10
	sra	$15, $13, 7
	move	$13, $15
$155:
	.loc	3 4729
	.loc	3 4730
 #4730	                { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xe4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((col << 2) > (0) ? (col << 2) : (0))) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(((next_y << 2) > (0) ? (next_y << 2) : (0))) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((cur_x << 2) > (0) ? (cur_x << 2) : (0))) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(((cur_y << 2) > (0) ? (cur_y << 2) : (0))) & ((0x01 << (12)) - 1)) << (0)))); { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -12))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(((0) - (((((cur_x << 2*1 << 10)>>7)) < (0) ? (((cur_x << 2*1 << 10)>>7)) : (0))))) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(((0) - (((((cur_y << 2*1 << 10)>>7)) < (0) ? (((cur_y << 2*1 << 10)>>7)) : (0))))) & ((0x01 << (16)) - 1)) << (0))))); }; { Gfx *_g = (Gfx *)(gdl++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 - 13))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (uintptr_t)((((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(1 << 10) & ((0x01 << (16)) - 1)) << (0))))); }; };
	.loc	3 4730
	move	$8, $7
	addu	$7, $7, 8
	.loc	3 4730
	sll	$2, $9, 2
	ble	$2, 0, $156
	move	$4, $2
	b	$157
$156:
	move	$4, $0
$157:
	ble	$12, 0, $158
	move	$3, $12
	b	$159
$158:
	move	$3, $0
$159:
	and	$24, $3, 4095
	or	$25, $24, $16
	and	$14, $4, 4095
	sll	$15, $14, 12
	or	$24, $25, $15
	sw	$24, 0($8)
	.loc	3 4730
	sll	$5, $10, 2
	ble	$5, 0, $160
	move	$4, $5
	b	$161
$160:
	move	$4, $0
$161:
	ble	$11, 0, $162
	move	$3, $11
	b	$163
$162:
	move	$3, $0
$163:
	and	$14, $3, 4095
	and	$25, $4, 4095
	sll	$15, $25, 12
	or	$24, $14, $15
	sw	$24, 4($8)
	.loc	3 4730
	.loc	3 4730
	move	$6, $7
	addu	$7, $7, 8
	.loc	3 4730
	sw	$17, 0($6)
	.loc	3 4730
	sll	$2, $5, 10
	sra	$25, $2, 7
	move	$2, $25
	bge	$2, 0, $164
	move	$4, $2
	b	$165
$164:
	move	$4, $0
$165:
	bge	$13, 0, $166
	move	$3, $13
	b	$167
$166:
	move	$3, $0
$167:
	negu	$14, $3
	and	$15, $14, 65535
	negu	$24, $4
	and	$25, $24, 65535
	sll	$14, $25, 16
	or	$24, $15, $14
	sw	$24, 4($6)
	.loc	3 4730
	.loc	3 4730
	.loc	3 4730
	move	$2, $7
	addu	$7, $7, 8
	.loc	3 4730
	sw	$18, 0($2)
	.loc	3 4730
	sw	$19, 4($2)
	.loc	3 4730
	.loc	3 4730
	.loc	3 4729
 #4729	            for (cur_x = 0, col = 96; col != 480; cur_x += 96, col += 96) {
	addu	$10, $10, 96
	addu	$9, $9, 96
	bne	$9, $20, $155
	.loc	3 4728
 #4728	        for (row = 0, cur_y = outer, next_y = outer + height; row != 288; row += 96, cur_y += 96, next_y += 96) {
	addu	$22, $22, 96
	addu	$21, $21, 96
	addu	$23, $23, 96
	bne	$22, $30, $154
	.loc	3 4721
 #4721	    for (outer = 0, tex_offset = 0; outer != 100; outer += 5, tex_offset += 480) {
	addu	$31, $31, 5
	lw	$25, 52($sp)
	addu	$15, $25, 480
	sw	$15, 52($sp)
	bne	$31, 100, $149
	.loc	3 4734
 #4734	    return gdl;
	move	$2, $7
	.livereg	0x2000FF0E,0x00000FFF
	lw	$16, 8($sp)
	lw	$17, 12($sp)
	lw	$18, 16($sp)
	lw	$19, 20($sp)
	lw	$20, 24($sp)
	lw	$21, 28($sp)
	lw	$22, 32($sp)
	lw	$23, 36($sp)
	lw	$31, 44($sp)
	lw	$30, 40($sp)
	addu	$sp, 120
	j	$31
	.end	func_i2_802C88DC
	.text	
	.align	2
	.file	2 "scratch/test_5e28.c"
 #  92	            } else if (pressed & 0x4000) {
	.globl	func_i2_802C5E28
	.loc	2 2
 #   1	#include "ctx.c"
 #   2	u32 func_i2_802C5E28(void) {
	.ent	func_i2_802C5E28 2
func_i2_802C5E28:
	.option	O2
	subu	$sp, 80
	sw	$31, 60($sp)
	sw	$30, 56($sp)
	sw	$23, 52($sp)
	sw	$22, 48($sp)
	sw	$21, 44($sp)
	sw	$20, 40($sp)
	sw	$19, 36($sp)
	sw	$18, 32($sp)
	sw	$17, 28($sp)
	sw	$16, 24($sp)
	.mask	0xC0FF0000, -20
	.frame	$sp, 80, $31
	.loc	2 2
	.loc	2 14
 #  14	    if (D_801CE60C > 0) {
	lh	$5, D_801CE60C
	ble	$5, 0, $253
	.loc	2 14
	.loc	2 15
 #  15	        player = 0;
	move	$16, $0
	.loc	2 16
 #  16	        offset = 0;
	.loc	2 17
 #  17	        s2 = D_802C8C58.as_array;
	la	$18, D_802C8C58
	.loc	2 18
 #  18	        do {
	li	$30, 3
	li	$23, 4
	la	$22, D_800DA9C0
	li	$19, 1
$168:
	.loc	2 18
	.loc	2 21
 #  19	            s32 is_p2_same;
 #  20	            s32 v0;
 #  21	            if (player == 0) {
	bne	$16, 0, $169
	.loc	2 21
	.loc	2 22
 #  22	                rider_idx = D_800D48DC;
	lw	$14, D_800D48DC
	sw	$14, 68($sp)
	.loc	2 23
 #  23	                v0 = 0;
	move	$3, $0
	b	$170
$169:
	.loc	2 24
 #  24	            } else {
	.loc	2 25
 #  25	                rider_idx = D_800D48E0;
	lw	$15, D_800D48E0
	sw	$15, 68($sp)
	.loc	2 26
 #  26	                v0 = 1;
	move	$3, $19
$170:
	.loc	2 29
 #  27	            }
 #  28	
 #  29	            s6 = &D_801CE658[v0];
	.loc	2 30
 #  30	            pressed = s6->unk_00.unk_2;
	.noalias	$21,$sp
	mul	$24, $3, 28
	la	$25, D_801CE658
	addu	$21, $24, $25
	lhu	$2, 2($21)
	.loc	2 32
 #  31	
 #  32	            if ((pressed & 0xB000) && (D_i2_802C8BC0 != 0)) {
	move	$6, $2
	and	$8, $6, 45056
	beq	$8, 0, $191
	lw	$9, D_i2_802C8BC0
	beq	$9, 0, $191
	.alias	$21,$sp
	.loc	2 32
	.loc	2 33
 #  33	                sound_mode = 1;
	move	$5, $19
	.loc	2 34
 #  34	                switch (*s2) {
	lw	$10, 0($18)
	bgeu	$10, 6, $188
	sll	$10, $10, 2
	lw	$10, $171($10)
	j	$10
	.rdata	
$171:
	.word	$173
	.word	$176
	.word	$182
	.word	$183
	.word	$184
	.word	$187
	.text	
$173:
	.loc	2 36
 #  35	                    case 0:
 #  36	                        *s2 = 1;
	sw	$19, 0($18)
	.loc	2 37
 #  37	                        if ((D_800DAB64 != 0) && (pressed & 0x2000)) {
	mul	$11, $16, 2
	la	$12, D_801CE6F4
	addu	$2, $11, $12
	mul	$13, $16, 4
	addu	$3, $22, $13
	lh	$14, D_800DAB64
	beq	$14, 0, $174
	and	$15, $6, 8192
	beq	$15, 0, $174
	.loc	2 37
	.loc	2 38
 #  38	                            D_801CE6F4[player] = 1;
	.noalias	$2,$sp
	sh	$19, 0($2)
$174:
	.loc	2 40
 #  39	                        }
 #  40	                        if (D_801CE6F4[player] != 0) {
	lh	$24, 0($2)
	beq	$24, 0, $175
	.alias	$2,$sp
	.loc	2 40
	.loc	2 41
 #  41	                            D_802C8C70[D_800DA9C0[player]] |= 2;
	.noalias	$3,$sp
	.noalias	$2,$3
	.noalias	$2,$sp
	lw	$25, 0($3)
	mul	$8, $25, 2
	la	$9, D_802C8C70
	addu	$2, $8, $9
	lh	$10, 0($2)
	or	$11, $10, 2
	sh	$11, 0($2)
	b	$188
$175:
	.loc	2 42
 #  42	                        } else {
	.loc	2 43
 #  43	                            D_802C8C70[D_800DA9C0[player]] |= 1;
	lw	$12, 0($3)
	mul	$13, $12, 2
	la	$14, D_802C8C70
	addu	$2, $13, $14
	lh	$15, 0($2)
	or	$24, $15, 1
	sh	$24, 0($2)
	.alias	$2,$3
	.alias	$2,$sp
	.alias	$3,$sp
	.loc	2 45
 #  44	                        }
 #  45	                        break;
	b	$188
$176:
	.loc	2 47
 #  46	                    case 1:
 #  47	                        if (D_800DA9C8[player] == 0) {
	mul	$25, $16, 4
	lw	$8, D_800DA9C8($25)
	bne	$8, 0, $180
	.loc	2 47
	.loc	2 48
 #  48	                            if (player == 0) {
	bne	$16, 0, $177
	.loc	2 48
	.loc	2 49
 #  49	                                D_801CB32C = 0;
	sw	$0, D_801CB32C
$177:
	.loc	2 51
 #  50	                            }
 #  51	                            if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 11)) {
	lw	$2, D_801CE608
	beq	$2, 0, $178
	bne	$2, 11, $179
$178:
	.loc	2 51
	.loc	2 52
 #  52	                                func_i2_802C6864(player);
	move	$4, $16
	.livereg	0x0800000E,0x00000000
	jal	func_i2_802C6864
	.loc	2 53
 #  53	                                sound_mode = 2;
	li	$5, 2
	b	$188
$179:
	.loc	2 54
 #  54	                            } else {
	.loc	2 55
 #  55	                                *s2 = 5;
	li	$9, 5
	sw	$9, 0($18)
	b	$188
$180:
	.loc	2 57
 #  56	                            }
 #  57	                        } else {
	.loc	2 58
 #  58	                            if (player == 0) {
	bne	$16, 0, $181
	.loc	2 58
	.loc	2 59
 #  59	                                D_801CB32C = 1;
	sw	$19, D_801CB32C
$181:
	.loc	2 61
 #  60	                            }
 #  61	                            *s2 = 2;
	li	$10, 2
	sw	$10, 0($18)
	.loc	2 63
 #  62	                        }
 #  63	                        break;
	b	$188
$182:
	.loc	2 65
 #  64	                    case 2:
 #  65	                        *s2 = 3;
	sw	$30, 0($18)
	.loc	2 66
 #  66	                        break;
	b	$188
$183:
	.loc	2 68
 #  67	                    case 3:
 #  68	                        *s2 = 4;
	sw	$23, 0($18)
	.loc	2 69
 #  69	                        break;
	b	$188
$184:
	.loc	2 71
 #  70	                    case 4:
 #  71	                        if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 11)) {
	lw	$2, D_801CE608
	beq	$2, 0, $185
	bne	$2, 11, $186
$185:
	.loc	2 71
	.loc	2 72
 #  72	                            func_i2_802C6864(player);
	move	$4, $16
	.livereg	0x0800000E,0x00000000
	jal	func_i2_802C6864
	.loc	2 73
 #  73	                            sound_mode = 2;
	li	$5, 2
	b	$188
$186:
	.loc	2 74
 #  74	                        } else {
	.loc	2 75
 #  75	                            *s2 = 5;
	li	$11, 5
	sw	$11, 0($18)
	.loc	2 77
 #  76	                        }
 #  77	                        break;
	b	$188
$187:
	.loc	2 79
 #  78	                    case 5:
 #  79	                        func_i2_802C6864(player);
	move	$4, $16
	sw	$5, 76($sp)
	.livereg	0x0800000E,0x00000000
	jal	func_i2_802C6864
	lw	$5, 76($sp)
	.loc	2 80
 #  80	                        break;
$188:
	.loc	2 83
 #  81	                }
 #  82	
 #  83	                if (sound_mode != 0) {
	beq	$5, 0, $251
	.loc	2 83
	.loc	2 84
 #  84	                    if (D_80228A32 == 1) {
	lh	$12, D_80228A32
	bne	$19, $12, $189
	.loc	2 84
	.loc	2 85
 #  85	                        AudioGeneral_PlaySound(0x2A, 0);
	li	$4, 42
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	AudioGeneral_PlaySound
	b	$251
$189:
	.loc	2 86
 #  86	                    } else if (sound_mode == 1) {
	bne	$5, $19, $190
	.loc	2 86
	.loc	2 87
 #  87	                        AudioGeneral_PlaySound(0x11, 0);
	li	$4, 17
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	AudioGeneral_PlaySound
	b	$251
$190:
	.loc	2 88
 #  88	                    } else {
	.loc	2 89
 #  89	                        AudioGeneral_PlaySound(0x37, 0);
	li	$4, 55
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	AudioGeneral_PlaySound
	b	$251
$191:
	.loc	2 92
 #  90	                    }
 #  91	                }
 #  92	            } else if (pressed & 0x4000) {
	and	$13, $6, 16384
	beq	$13, 0, $204
	.loc	2 92
	.loc	2 93
 #  93	                sound_mode = 1;
	move	$5, $19
	.loc	2 94
 #  94	                switch (*s2) {
	lw	$14, 0($18)
	bgeu	$14, 6, $202
	sll	$14, $14, 2
	lw	$14, $192($14)
	j	$14
	.rdata	
$192:
	.word	$194
	.word	$195
	.word	$197
	.word	$198
	.word	$199
	.word	$200
	.text	
$194:
	.loc	2 96
 #  95	                    case 0:
 #  96	                        func_i2_802C84EC(2);
	li	$4, 2
	sw	$5, 76($sp)
	.livereg	0x0800000E,0x00000000
	jal	func_i2_802C84EC
	lw	$5, 76($sp)
	.loc	2 97
 #  97	                        break;
	b	$203
$195:
	.loc	2 99
 #  98	                    case 1:
 #  99	                        *s2 = 0;
	sw	$0, 0($18)
	.loc	2 100
 # 100	                        if (D_801CE6F4[player] != 0) {
	mul	$15, $16, 4
	addu	$3, $22, $15
	mul	$24, $16, 2
	lh	$25, D_801CE6F4($24)
	beq	$25, 0, $196
	.loc	2 100
	.loc	2 101
 # 101	                            D_802C8C70[D_800DA9C0[player]] &= ~2;
	.noalias	$3,$sp
	.noalias	$2,$3
	.noalias	$2,$sp
	lw	$8, 0($3)
	mul	$9, $8, 2
	la	$10, D_802C8C70
	addu	$2, $9, $10
	lh	$11, 0($2)
	and	$12, $11, -3
	sh	$12, 0($2)
	b	$203
$196:
	.loc	2 102
 # 102	                        } else {
	.loc	2 103
 # 103	                            D_802C8C70[D_800DA9C0[player]] &= ~1;
	lw	$13, 0($3)
	mul	$14, $13, 2
	la	$15, D_802C8C70
	addu	$2, $14, $15
	lh	$24, 0($2)
	and	$25, $24, -2
	sh	$25, 0($2)
	.alias	$2,$3
	.alias	$2,$sp
	.alias	$3,$sp
	.loc	2 105
 # 104	                        }
 # 105	                        break;
	b	$203
$197:
	.loc	2 107
 # 106	                    case 2:
 # 107	                        *s2 = 1;
	sw	$19, 0($18)
	.loc	2 108
 # 108	                        break;
	b	$203
$198:
	.loc	2 110
 # 109	                    case 3:
 # 110	                        *s2 = 2;
	li	$8, 2
	sw	$8, 0($18)
	.loc	2 111
 # 111	                        break;
	b	$203
$199:
	.loc	2 113
 # 112	                    case 4:
 # 113	                        *s2 = 3;
	sw	$30, 0($18)
	.loc	2 114
 # 114	                        break;
	b	$203
$200:
	.loc	2 116
 # 115	                    case 5:
 # 116	                        if (D_800DA9C8[player] == 0) {
	mul	$9, $16, 4
	lw	$10, D_800DA9C8($9)
	bne	$10, 0, $201
	.loc	2 116
	.loc	2 117
 # 117	                            *s2 = 1;
	sw	$19, 0($18)
	b	$203
$201:
	.loc	2 118
 # 118	                        } else {
	.loc	2 119
 # 119	                            *s2 = 4;
	sw	$23, 0($18)
	.loc	2 121
 # 120	                        }
 # 121	                        break;
	b	$203
$202:
	.loc	2 123
 # 122	                    default:
 # 123	                        sound_mode = 0;
	move	$5, $0
	.loc	2 124
 # 124	                        break;
$203:
	.loc	2 127
 # 125	                }
 # 126	
 # 127	                if (sound_mode != 0) {
	beq	$5, 0, $251
	.loc	2 127
	.loc	2 128
 # 128	                    AudioGeneral_PlaySound(0x16, 0);
	li	$4, 22
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	AudioGeneral_PlaySound
	b	$251
$204:
	.loc	2 130
 # 129	                }
 # 130	            } else {
	.loc	2 131
 # 131	                if (pressed & 0xF) {
	mul	$4, $16, 4
	and	$11, $6, 15
	beq	$11, 0, $208
	.loc	2 131
	.loc	2 132
 # 132	                    s32 char_idx = D_i2_802C8BD8[D_800DA9C0[player]];
	.noalias	$22,$sp
	addu	$12, $22, $4
	.noalias	$12,$sp
	lw	$13, 0($12)
	.alias	$12,$sp
	mul	$14, $13, 4
	lw	$3, D_i2_802C8BD8($14)
	.loc	2 133
 # 133	                    UnkStruct_func_i8_802C6E00 (*arr)[4] = (UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298;
	.loc	2 134
 # 134	                    switch (*s2) {
	lw	$2, 0($18)
	beq	$2, 2, $205
	beq	$2, $30, $206
	beq	$2, $23, $207
	b	$251
$205:
	.loc	2 136
 # 135	                        case 2:
 # 136	                            arr[player][char_idx].unk_B[0] = D_800DA950[char_idx].unk_B[0];
	mul	$2, $3, 14
	lb	$15, D_800DA950+11($2)
	mul	$24, $16, 56
	addu	$25, $24, $2
	sb	$15, D_801CB298+11($25)
	.loc	2 137
 # 137	                            break;
	b	$251
$206:
	.loc	2 139
 # 138	                        case 3:
 # 139	                            arr[player][char_idx].unk_B[1] = D_800DA950[char_idx].unk_B[1];
	mul	$2, $3, 14
	lb	$8, D_800DA950+12($2)
	mul	$9, $16, 56
	addu	$10, $9, $2
	sb	$8, D_801CB298+12($10)
	.loc	2 140
 # 140	                            break;
	b	$251
$207:
	.loc	2 142
 # 141	                        case 4:
 # 142	                            arr[player][char_idx].unk_B[2] = D_800DA950[char_idx].unk_B[2];
	mul	$2, $3, 14
	lb	$11, D_800DA950+13($2)
	mul	$12, $16, 56
	addu	$13, $12, $2
	sb	$11, D_801CB298+13($13)
	.loc	2 143
 # 143	                            break;
	b	$251
$208:
	.loc	2 145
 # 144	                    }
 # 145	                } else {
	.loc	2 146
 # 146	                    s1 = &D_i2_802C8BB0[player];
	.loc	2 147
 # 147	                    s5 = &D_i2_802C8BB8[player];
	.loc	2 148
 # 148	                    can_select = 0;
	move	$7, $0
	.loc	2 149
 # 149	                    is_p2_same = 1;
	move	$3, $19
	.loc	2 150
 # 150	                    if ((gPlayers != ONE_PLAYER) && (D_800DA9C0[0] == D_800DA9C0[1])) {
	la	$14, D_i2_802C8BB0
	addu	$17, $4, $14
	la	$24, D_i2_802C8BB8
	addu	$20, $4, $24
	lw	$15, gPlayers
	beq	$19, $15, $209
	lw	$25, 0($22)
	lw	$9, 4($22)
	bne	$25, $9, $209
	.loc	2 150
	.loc	2 151
 # 151	                        is_p2_same = 0;
	move	$3, $0
$209:
	.loc	2 154
 # 152	                    }
 # 153	
 # 154	                    if (*s2 == 0) {
	lw	$8, 0($18)
	bne	$8, 0, $216
	.loc	2 154
	.loc	2 155
 # 155	                        if (is_p2_same != 0) {
	mul	$10, $16, 2
	la	$12, D_801CE6F4
	addu	$2, $10, $12
	beq	$3, 0, $211
	.loc	2 155
	.loc	2 156
 # 156	                            if (s6->unk_00.unk_0 & 0x800) {
	lhu	$11, 0($21)
	and	$13, $11, 2048
	beq	$13, 0, $210
	.loc	2 156
	.loc	2 157
 # 157	                                can_select = 1;
	move	$7, $19
	.loc	2 158
 # 158	                                D_801CE6F4[player] = player ^ 1;
	.noalias	$2,$22
	.noalias	$2,$sp
	xor	$14, $16, 1
	sh	$14, 0($2)
	b	$214
$210:
	.loc	2 159
 # 159	                            } else {
	.loc	2 160
 # 160	                                D_801CE6F4[player] = player;
	sh	$16, 0($2)
	.alias	$2,$22
	.alias	$2,$sp
	b	$214
$211:
	.loc	2 162
 # 161	                            }
 # 162	                        } else {
	.loc	2 163
 # 163	                            if (D_802C8C70[D_800DA9C0[player]] == 0) {
	addu	$24, $22, $4
	.noalias	$24,$sp
	lw	$15, 0($24)
	.alias	$24,$sp
	mul	$25, $15, 2
	lh	$3, D_802C8C70($25)
	bne	$3, 0, $212
	.loc	2 163
	.loc	2 164
 # 164	                                D_801CE6F4[player] = player;
	.noalias	$2,$22
	.noalias	$2,$sp
	sh	$16, 0($2)
	b	$214
$212:
	.loc	2 165
 # 165	                            } else if (D_802C8C70[D_800DA9C0[player]] & 1) {
	and	$9, $3, 1
	beq	$9, 0, $213
	.loc	2 165
	.loc	2 166
 # 166	                                D_801CE6F4[player] = 1;
	sh	$19, 0($2)
	b	$214
$213:
	.loc	2 167
 # 167	                            } else {
	.loc	2 168
 # 168	                                D_801CE6F4[player] = 0;
	sh	$0, 0($2)
	.alias	$2,$22
	.alias	$2,$sp
$214:
	.loc	2 172
 # 169	                            }
 # 170	                        }
 # 171	
 # 172	                        if ((D_800DAB60 != 0) && (D_801CE60C == 1)) {
	lh	$8, D_800DAB60
	beq	$8, 0, $216
	bne	$19, $5, $216
	.loc	2 172
	.loc	2 173
 # 173	                            if (s6->unk_00.unk_0 & 0x400) {
	lhu	$10, 0($21)
	and	$12, $10, 1024
	beq	$12, 0, $215
	.loc	2 173
	.loc	2 174
 # 174	                                D_800DAB64 = 1;
	sh	$19, D_800DAB64
	b	$216
$215:
	.loc	2 175
 # 175	                            } else {
	.loc	2 176
 # 176	                                D_800DAB64 = 0;
	sh	$0, D_800DAB64
$216:
	.loc	2 181
 # 177	                            }
 # 178	                        }
 # 179	                    }
 # 180	
 # 181	                    *s1 = 0;
	sw	$0, 0($17)
	.loc	2 182
 # 182	                    if (pressed & 0x200) {
	and	$11, $6, 512
	beq	$11, 0, $228
	.loc	2 182
	.loc	2 183
 # 183	                        sound_mode = 1;
	move	$5, $19
	.loc	2 184
 # 184	                        switch (*s2) {
	lw	$13, 0($18)
	bgeu	$13, 5, $226
	sll	$13, $13, 2
	lw	$13, $217($13)
	j	$13
	.rdata	
$217:
	.word	$219
	.word	$222
	.word	$223
	.word	$224
	.word	$225
	.text	
$219:
	.loc	2 186
 # 185	                            case 0:
 # 186	                                if (can_select != 0) {
	beq	$7, 0, $220
	.loc	2 186
	.loc	2 187
 # 187	                                    sound_mode = 0;
	move	$5, $0
	b	$227
$220:
	.loc	2 188
 # 188	                                } else {
	.loc	2 189
 # 189	                                    D_800DA9C0[player]--;
	.noalias	$3,$sp
	addu	$3, $22, $4
	lw	$14, 0($3)
	addu	$24, $14, -1
	sw	$24, 0($3)
	.loc	2 190
 # 190	                                    if (D_800DA9C0[player] < 0) {
	la	$15, D_802C8C60
	addu	$2, $4, $15
	lw	$25, 0($3)
	bge	$25, 0, $221
	.loc	2 190
	.loc	2 191
 # 191	                                        D_800DA9C0[player] = 3;
	sw	$30, 0($3)
	.alias	$3,$sp
$221:
	.loc	2 193
 # 192	                                    }
 # 193	                                    D_802C8C60[player] = 0x200;
	.noalias	$2,$22
	.noalias	$2,$sp
	li	$9, 512
	sw	$9, 0($2)
	.alias	$2,$22
	.alias	$2,$sp
	.loc	2 195
 # 194	                                }
 # 195	                                break;
	b	$227
$222:
	.loc	2 197
 # 196	                            case 1:
 # 197	                                D_800DA9C8[player]--;
	.noalias	$2,$22
	.noalias	$2,$sp
	la	$8, D_800DA9C8
	addu	$2, $4, $8
	lw	$10, 0($2)
	addu	$12, $10, -1
	sw	$12, 0($2)
	.loc	2 198
 # 198	                                if (D_800DA9C8[player] < 0) {
	lw	$11, 0($2)
	bge	$11, 0, $227
	.loc	2 198
	.loc	2 199
 # 199	                                    D_800DA9C8[player] = 1;
	sw	$19, 0($2)
	.alias	$2,$22
	.alias	$2,$sp
	.loc	2 201
 # 200	                                }
 # 201	                                break;
	b	$227
$223:
	.loc	2 203
 # 202	                            case 2:
 # 203	                                *s1 = 1;
	sw	$19, 0($17)
	.loc	2 204
 # 204	                                sound_mode = func_i2_802C676C(player, 0);
	move	$4, $16
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C676C
	move	$5, $2
	.loc	2 205
 # 205	                                break;
	b	$227
$224:
	.loc	2 207
 # 206	                            case 3:
 # 207	                                *s1 = 1;
	sw	$19, 0($17)
	.loc	2 208
 # 208	                                sound_mode = func_i2_802C676C(player, 1);
	move	$4, $16
	move	$5, $19
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C676C
	move	$5, $2
	.loc	2 209
 # 209	                                break;
	b	$227
$225:
	.loc	2 211
 # 210	                            case 4:
 # 211	                                *s1 = 1;
	sw	$19, 0($17)
	.loc	2 212
 # 212	                                sound_mode = func_i2_802C676C(player, 2);
	move	$4, $16
	li	$5, 2
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C676C
	move	$5, $2
	.loc	2 213
 # 213	                                break;
	b	$227
$226:
	.loc	2 215
 # 214	                            default:
 # 215	                                sound_mode = 0;
	move	$5, $0
	.loc	2 216
 # 216	                                break;
$227:
	.loc	2 219
 # 217	                        }
 # 218	
 # 219	                        if (sound_mode != 0) {
	beq	$5, 0, $240
	.loc	2 219
	.loc	2 220
 # 220	                            AudioGeneral_PlaySound(0x10, 0);
	li	$4, 16
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	AudioGeneral_PlaySound
	b	$240
$228:
	.loc	2 222
 # 221	                        }
 # 222	                    } else if (pressed & 0x100) {
	and	$13, $6, 256
	beq	$13, 0, $240
	.loc	2 222
	.loc	2 223
 # 223	                        sound_mode = 1;
	move	$5, $19
	.loc	2 224
 # 224	                        switch (*s2) {
	lw	$14, 0($18)
	bgeu	$14, 5, $238
	sll	$14, $14, 2
	lw	$14, $229($14)
	j	$14
	.rdata	
$229:
	.word	$231
	.word	$234
	.word	$235
	.word	$236
	.word	$237
	.text	
$231:
	.loc	2 226
 # 225	                            case 0:
 # 226	                                if (can_select != 0) {
	beq	$7, 0, $232
	.loc	2 226
	.loc	2 227
 # 227	                                    sound_mode = 0;
	move	$5, $0
	b	$239
$232:
	.loc	2 228
 # 228	                                } else {
	.loc	2 229
 # 229	                                    D_800DA9C0[player]++;
	.noalias	$3,$sp
	addu	$3, $22, $4
	lw	$24, 0($3)
	addu	$15, $24, 1
	sw	$15, 0($3)
	.loc	2 230
 # 230	                                    if (D_800DA9C0[player] == 4) {
	la	$25, D_802C8C60
	addu	$2, $4, $25
	lw	$9, 0($3)
	bne	$23, $9, $233
	.loc	2 230
	.loc	2 231
 # 231	                                        D_800DA9C0[player] = 0;
	sw	$0, 0($3)
	.alias	$3,$sp
$233:
	.loc	2 233
 # 232	                                    }
 # 233	                                    D_802C8C60[player] = 0x200;
	.noalias	$2,$22
	.noalias	$2,$sp
	li	$8, 512
	sw	$8, 0($2)
	.alias	$2,$22
	.alias	$2,$sp
	.loc	2 235
 # 234	                                }
 # 235	                                break;
	b	$239
$234:
	.loc	2 237
 # 236	                            case 1:
 # 237	                                D_800DA9C8[player]++;
	.noalias	$2,$22
	.noalias	$2,$sp
	la	$10, D_800DA9C8
	addu	$2, $4, $10
	lw	$12, 0($2)
	addu	$11, $12, 1
	sw	$11, 0($2)
	.loc	2 238
 # 238	                                if (D_800DA9C8[player] == 2) {
	lw	$13, 0($2)
	bne	$13, 2, $239
	.loc	2 238
	.loc	2 239
 # 239	                                    D_800DA9C8[player] = 0;
	sw	$0, 0($2)
	.alias	$2,$22
	.alias	$2,$sp
	.loc	2 241
 # 240	                                }
 # 241	                                break;
	b	$239
$235:
	.loc	2 243
 # 242	                            case 2:
 # 243	                                *s1 = 1;
	sw	$19, 0($17)
	.loc	2 244
 # 244	                                sound_mode = func_i2_802C67E4(player, 0);
	move	$4, $16
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C67E4
	move	$5, $2
	.loc	2 245
 # 245	                                break;
	b	$239
$236:
	.loc	2 247
 # 246	                            case 3:
 # 247	                                *s1 = 1;
	sw	$19, 0($17)
	.loc	2 248
 # 248	                                sound_mode = func_i2_802C67E4(player, 1);
	move	$4, $16
	move	$5, $19
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C67E4
	move	$5, $2
	.loc	2 249
 # 249	                                break;
	b	$239
$237:
	.loc	2 251
 # 250	                            case 4:
 # 251	                                *s1 = 1;
	sw	$19, 0($17)
	.loc	2 252
 # 252	                                sound_mode = func_i2_802C67E4(player, 2);
	move	$4, $16
	li	$5, 2
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C67E4
	move	$5, $2
	.loc	2 253
 # 253	                                break;
	b	$239
$238:
	.loc	2 255
 # 254	                            default:
 # 255	                                sound_mode = 0;
	move	$5, $0
	.loc	2 256
 # 256	                                break;
$239:
	.loc	2 259
 # 257	                        }
 # 258	
 # 259	                        if (sound_mode != 0) {
	beq	$5, 0, $240
	.loc	2 259
	.loc	2 260
 # 260	                            AudioGeneral_PlaySound(0x10, 0);
	li	$4, 16
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	AudioGeneral_PlaySound
$240:
	.loc	2 264
 # 261	                        }
 # 262	                    }
 # 263	
 # 264	                    if (*s1 != 0) {
	lw	$14, 0($17)
	beq	$14, 0, $241
	.loc	2 264
	.loc	2 265
 # 265	                        *s5 = -3;
	li	$24, -3
	sw	$24, 0($20)
	b	$251
$241:
	.loc	2 266
 # 266	                    } else {
	.loc	2 267
 # 267	                        (*s5)++;
	lw	$15, 0($20)
	addu	$25, $15, 1
	sw	$25, 0($20)
	.loc	2 268
 # 268	                        if (*s5 >= 4) {
	lw	$9, 0($20)
	blt	$9, 4, $251
	.loc	2 268
	.loc	2 269
 # 269	                            *s5 = 0;
	sw	$0, 0($20)
	.loc	2 270
 # 270	                            if (s6->unk_00.unk_0 & 0x200) {
	lhu	$2, 0($21)
	and	$8, $2, 512
	beq	$8, 0, $246
	.loc	2 270
	.loc	2 271
 # 271	                                switch (*s2) {
	lw	$2, 0($18)
	beq	$2, 2, $242
	beq	$2, $30, $243
	beq	$2, $23, $244
	move	$5, $0
	b	$245
$242:
	.loc	2 273
 # 272	                                    case 2:
 # 273	                                        sound_mode = func_i2_802C676C(player, 0);
	move	$4, $16
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C676C
	move	$5, $2
	.loc	2 274
 # 274	                                        break;
	b	$245
$243:
	.loc	2 276
 # 275	                                    case 3:
 # 276	                                        sound_mode = func_i2_802C676C(player, 1);
	move	$4, $16
	move	$5, $19
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C676C
	move	$5, $2
	.loc	2 277
 # 277	                                        break;
	b	$245
$244:
	.loc	2 279
 # 278	                                    case 4:
 # 279	                                        sound_mode = func_i2_802C676C(player, 2);
	move	$4, $16
	li	$5, 2
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C676C
	move	$5, $2
	.loc	2 280
 # 280	                                        break;
$245:
	.loc	2 285
 # 281	                                    default:
 # 282	                                        sound_mode = 0;
 # 283	                                        break;
 # 284	                                }
 # 285	                                if (sound_mode != 0) {
	beq	$5, 0, $251
	.loc	2 285
	.loc	2 286
 # 286	                                    AudioGeneral_PlaySound(0x10, 0);
	li	$4, 16
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	AudioGeneral_PlaySound
	b	$251
$246:
	.loc	2 288
 # 287	                                }
 # 288	                            } else if (s6->unk_00.unk_0 & 0x100) {
	and	$10, $2, 256
	beq	$10, 0, $251
	.loc	2 288
	.loc	2 289
 # 289	                                switch (*s2) {
	lw	$2, 0($18)
	beq	$2, 2, $247
	beq	$2, $30, $248
	beq	$2, $23, $249
	move	$5, $0
	b	$250
$247:
	.loc	2 291
 # 290	                                    case 2:
 # 291	                                        sound_mode = func_i2_802C67E4(player, 0);
	move	$4, $16
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C67E4
	move	$5, $2
	.loc	2 292
 # 292	                                        break;
	b	$250
$248:
	.loc	2 294
 # 293	                                    case 3:
 # 294	                                        sound_mode = func_i2_802C67E4(player, 1);
	move	$4, $16
	move	$5, $19
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C67E4
	move	$5, $2
	.loc	2 295
 # 295	                                        break;
	b	$250
$249:
	.loc	2 297
 # 296	                                    case 4:
 # 297	                                        sound_mode = func_i2_802C67E4(player, 2);
	move	$4, $16
	li	$5, 2
	.livereg	0x0C00000E,0x00000000
	jal	func_i2_802C67E4
	move	$5, $2
	.loc	2 298
 # 298	                                        break;
$250:
	.loc	2 303
 # 299	                                    default:
 # 300	                                        sound_mode = 0;
 # 301	                                        break;
 # 302	                                }
 # 303	                                if (sound_mode != 0) {
	beq	$5, 0, $251
	.loc	2 303
	.loc	2 304
 # 304	                                    AudioGeneral_PlaySound(0x10, 0);
	li	$4, 16
	move	$5, $0
	.livereg	0x0C00000E,0x00000000
	jal	AudioGeneral_PlaySound
$251:
	.loc	2 312
 # 312	            if (*s2 == 0) {
	lh	$5, D_801CE60C
	lw	$12, 0($18)
	bne	$12, 0, $252
	.loc	2 312
	.loc	2 313
 # 313	                s32 char_idx = D_i2_802C8BD8[D_800DA9C0[player]];
	mul	$11, $16, 4
	addu	$13, $22, $11
	.noalias	$13,$sp
	lw	$14, 0($13)
	.alias	$13,$sp
	mul	$24, $14, 4
	lw	$4, D_i2_802C8BD8($24)
	.loc	2 314
 # 314	                UnkStruct_func_i8_802C6E00* ptr = &D_800DA950[char_idx];
	.loc	2 315
 # 315	                struct UnkStruct_80192690* rider = &D_80192690[rider_idx];
	.loc	2 316
 # 316	                rider->unkB68 = char_idx;
	.noalias	$2,$22
	.noalias	$2,$sp
	lw	$15, 68($sp)
	mul	$25, $15, 5912
	la	$9, D_80192690
	addu	$2, $25, $9
	sw	$4, 2920($2)
	.loc	2 317
 # 317	                rider->unkB6C = ptr->unk_B[0];
	.noalias	$3,$2
	.noalias	$3,$22
	.noalias	$3,$sp
	mul	$8, $4, 14
	la	$10, D_800DA950
	addu	$3, $8, $10
	lb	$12, 11($3)
	sw	$12, 2924($2)
	.loc	2 318
 # 318	                rider->unkB70 = ptr->unk_B[1];
	lb	$11, 12($3)
	sw	$11, 2928($2)
	.loc	2 319
 # 319	                rider->unkB74 = ptr->unk_B[2];
	lb	$13, 13($3)
	sw	$13, 2932($2)
	.alias	$2,$3
	.alias	$2,$22
	.alias	$2,$sp
	.alias	$3,$22
	.alias	$3,$sp
$252:
	.loc	2 321
 # 320	            }
 # 321	            player++;
	addu	$16, $16, 1
	.loc	2 322
 # 322	            offset += 4;
	.loc	2 323
 # 323	            s2++;
	addu	$18, $18, 4
	blt	$16, $5, $168
	.alias	$22,$sp
$253:
	.loc	2 327
 # 324	        } while (player < D_801CE60C);
 # 325	    }
 # 326	
 # 327	    return SysUtils_Rand();
	.livereg	0x0000000E,0x00000000
	jal	SysUtils_Rand
	.livereg	0x2000FF0E,0x00000FFF
	lw	$16, 24($sp)
	lw	$17, 28($sp)
	lw	$18, 32($sp)
	lw	$19, 36($sp)
	lw	$20, 40($sp)
	lw	$21, 44($sp)
	lw	$22, 48($sp)
	lw	$23, 52($sp)
	lw	$31, 60($sp)
	lw	$30, 56($sp)
	addu	$sp, 80
	j	$31
	.end	func_i2_802C5E28

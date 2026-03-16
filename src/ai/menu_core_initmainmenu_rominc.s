	.globl	sub_801FFD6
	.type	 sub_801FFD6,function
	.thumb_func
sub_801FFD6:
	push	{r4-r7,lr}
	sub	sp, sp, #8
	str	r0, [sp,#4]
	cmp	r0, #1
	beq	loc_80200A0
	mov	r1, #8
	tst	r0, r1
	beq	loc_801FFEA
	nop
	b	loc_802004E
loc_801FFEA:
	ldr	r4, off_8020110
	ldr	r5, off_8020114
	mov	r6, r10
	ldr	r6, [r6,#0x18]
	ldr	r7, off_8020118
	ldrh	r1, [r5,#2]
	mov	r2, #0xfc
	lsl	r2, r2, #8
	and	r2, r1
	beq	loc_802001C
	mov	r0, #0
	bl	sub_800A0D6
	ldrb	r1, [r5,#6]
	strb	r1, [r6,#0x14]
	ldrh	r1, [r5,#0xc]
	ldr	r0, off_802011C
	strh	r1, [r0,#0x2c]
	mov	r0, #4
	ldrsb	r0, [r5,r0]
	tst	r0, r0
	blt	loc_802001C
	lsl	r0, r0, #2
	ldr	r1, [r5,#8]
	str	r1, [r7,r0]
loc_802001C:
	add	r5, #0x10
	ldr	r7, off_8020120
	ldrb	r1, [r4]
	tst	r1, r1
	beq	loc_8020030
	ldrh	r1, [r5,#2]
	mov	r2, #0xfc
	lsl	r2, r2, #8
	and	r2, r1
	beq	loc_802004E
loc_8020030:
	mov	r0, #1
	bl	sub_800A0D6
	ldrb	r1, [r5,#6]
	strb	r1, [r6,#0x15]
	ldrh	r1, [r5,#0xc]
	ldr	r0, off_8020124
	strh	r1, [r0,#0x2c]
	mov	r0, #4
	ldrsb	r0, [r5,r0]
	tst	r0, r0
	blt	loc_802004E
	lsl	r0, r0, #2
	ldr	r1, [r5,#8]
	str	r1, [r7,r0]
loc_802004E:
	ldr	r1, [sp,#4]
	mov	r2, #0x10
	tst	r1, r2
	beq	loc_802005A
	nop
	b	loc_80200A0
loc_802005A:
	ldr	r5, off_8020128
	mov	r0, r10
	ldr	r0, [r0,#4]
	ldrh	r1, [r0]
	strh	r1, [r5,#2]
	str	r1, [sp]
	mov	r0, r10
	ldr	r0, [r0,#0x18]
	ldrb	r1, [r0,#0x11]
	strb	r1, [r5,#6]
	mov	r0, #4
	bl	sub_803F740
	strh	r0, [r5,#0xc]
	ldrb	r0, [r4,#2]
	mov	r1, #1
	tst	r0, r1
	beq	loc_8020094
	mov	r0, #3
	ldrsb	r0, [r4,r0]
	sub	r0, #1
	strb	r0, [r4,#3]
	blt	loc_8020094
	strb	r0, [r5,#4]
	lsl	r0, r0, #2
	ldr	r1, off_802012C
	ldr	r0, [r0,r1]
	str	r0, [r5,#8]
	b	loc_80200A0
loc_8020094:
	ldrb	r0, [r4,#2]
	mov	r1, #1
	bic	r0, r1
	strb	r0, [r4,#2]
	mov	r0, #0xff
	strb	r0, [r5,#4]
loc_80200A0:
	add	sp, sp, #8
	pop	{r4-r7,pc}
.Lfe1:
	.size	 sub_801FFD6,.Lfe1-sub_801FFD6

	.globl	sub_800EDD0
	.type	 sub_800EDD0,function
	.thumb_func
sub_800EDD0:
	push	{r5-r7,lr}
	sub	sp, sp, #4
	str	r1, [sp]
	mov	r5, r0
	ldrh	r0, [r5,#40]
	bl	sub_800F29C
	cmp	r0, #2
	bne	loc_800EE1A
	ldrb	r0, [r5,#22]
	bl	getBattleHandAddr_8010018
	mov	r4, r0
	ldrb	r6, [r0]
	add	r1, r6, r6
	add	r0, r0, r1
	add	r0, #2
	mov	r7, r0
	ldrh	r0, [r7]
	ldr	r1, [sp]
	bl	sub_800EF34
	mov	r3, r1
	ldrh	r2, [r7,#24]
	add	r2, r2, r0
	ldrh	r0, [r7,#36]
	add	r2, r2, r0
	ldrh	r1, [r7,#12]
	ldrh	r0, [r7]
	mov	r7, #68
	add	r7, r7, r6
	ldrb	r7, [r4,r7]
	add	r6, #62
	ldrb	r4, [r4,r6]
	lsl	r4, r4, #8
	add	r4, r4, r7
	b	loc_800EE22
loc_800EE1A:
	ldrh	r0, [r5,#42]
	mov	r1, #0
	mov	r2, #0
	ldrb	r3, [r5,#26]
loc_800EE22:
	add	sp, sp, #4
	pop	{r5-r7,pc}
	.size	 sub_800EDD0,.-sub_800EDD0
	.globl	sub_800EE26
	.type	 sub_800EE26,function
	.thumb_func
sub_800EE26:
	push	{r5-r7,lr}
	mov	r5, r0
	ldrh	r0, [r5,#40]
	bl	sub_800F29C
	cmp	r0, #2
	bne	loc_800EE8E
	ldrb	r0, [r5,#22]
	bl	sub_802E070
	mov	r6, r0
	bl	sub_800EE98
	ldrh	r0, [r6,#52]
	mov	r1, #0
	bl	sub_800EF34
	push	{r0,r1}
	ldrh	r0, [r6,#52]
	bl	getChip8021DA8
	ldrb	r0, [r0,#15]
	strb	r0, [r7,#29]
	ldrh	r0, [r6,#52]
	ldrb	r1, [r5,#22]
	bl	sub_80109A4
	mov	r1, r0
	pop	{r2,r3}
	push	{r1-r3}
	ldrh	r0, [r6,#52]
	bl	getChip8021DA8
	ldrb	r0, [r0,#9]
	pop	{r1-r3}
	mov	r4, #2
	tst	r0, r4
	beq	loc_800EE7A
	ldrh	r4, [r6,#54]
	add	r2, r2, r4
	mov	r4, #0
	strh	r4, [r6,#54]
loc_800EE7A:
	mov	r4, #4
	tst	r0, r4
	beq	loc_800EE88
	ldrh	r4, [r6,#56]
	add	r2, r2, r4
	mov	r4, #0
	strh	r4, [r6,#56]
loc_800EE88:
	mov	r4, #0
	ldrh	r0, [r6,#52]
	b	locret_800EE96
loc_800EE8E:
	ldrh	r0, [r5,#42]
	mov	r1, #0
	mov	r2, #0
	ldrb	r3, [r5,#26]
locret_800EE96:
	pop	{r5-r7,pc}
	.size	 sub_800EE26,.-sub_800EE26
	.globl	sub_800EE98
	.type	 sub_800EE98,function
	.thumb_func
sub_800EE98:
	push	{r0-r4,lr}
	ldrb	r0, [r5,#22]
	ldrh	r1, [r6,#52]
	bl	sub_802E830
	mov	r4, r0
	ldrb	r0, [r5,#22]
	bl	battle_networkInvert
	tst	r0, r0
	bne	loc_800EEBA
	mov	r0, r4
	bl	sub_801E2BA
	mov	r0, #141
	bl	PlaySoundEffect
loc_800EEBA:
	ldrh	r0, [r6,#52]
	bl	getChip8021DA8
	mov	r4, r0
	ldrb	r0, [r4,#22]
	mov	r1, #128
	tst	r0, r1
	bne	locret_800EEE2
	ldrb	r0, [r4,#7]
	add	r0, r0, r0
	ldr	r1, off_800EEF4
	ldrh	r0, [r1,r0]
	ldr	r2, off_800EEF0
	add	r3, r6, r6
	strh	r0, [r2,r3]
	ldrh	r1, [r6,#40]
	sub	r1, r1, r0
	bge	loc_800EEE0
	mov	r1, #0
loc_800EEE0:
	strh	r1, [r6,#40]
locret_800EEE2:
	pop	{r0-r4,pc}
	.word	0, 0
	.byte	0, 0, 0, 0
	.balign 4, 0
off_800EEF0:
	.word	word_200F3C4
off_800EEF4:
	.word	byte_800EEF8
byte_800EEF8:
	.byte	0x0, 0x15, 0x0, 0x2A, 0x0, 0x40, 0xFF, 0xFF, 0xFF, 0xFF
	.size	 sub_800EE98,.-sub_800EE98
	.globl	sub_800EF02
	.type	 sub_800EF02,function
	.thumb_func
sub_800EF02:
	push	{r5-r7,lr}
	mov	r6, r0
	ldrh	r0, [r5,#40]
	bl	sub_800F29C
	cmp	r0, #2
	bne	loc_800EF2A
	mov	r0, r6
	mov	r1, #0
	bl	sub_800EF34
	push	{r0,r1}
	mov	r0, r6
	ldrb	r1, [r5,#22]
	bl	sub_80109A4
	mov	r1, r0
	pop	{r2,r3}
	mov	r0, r6
	b	locret_800EF32
loc_800EF2A:
	ldrh	r0, [r5,#42]
	mov	r1, #0
	mov	r2, #0
	ldrb	r3, [r5,#26]
locret_800EF32:
	pop	{r5-r7,pc}
	.size	 sub_800EF02,.-sub_800EF02

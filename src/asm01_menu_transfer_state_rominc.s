	.globl	sub_801FE24
	.type	 sub_801FE24,function
	.thumb_func
sub_801FE24:
	push	{r4,lr}
	bl	GetBattleEffects
	mov	r1, #8
	tst	r0, r1
	bne	loc_801FE4A
	bl	notZero_eByte200AD04
	beq	locret_801FE5C
	mov	r0, #0
	bl	sub_803DE88
	mov	r0, #0x10
	mov	r1, #0
	mov	r2, #2
	mov	r3, #5
	bl	sub_803DCE8
	b	loc_801FE56
loc_801FE4A:
	mov	r0, #0x10
	mov	r1, #0
	mov	r2, #2
	mov	r3, #0
	bl	sub_803DCE8
loc_801FE56:
	ldr	r3, off_80200CC
	mov	r0, #1
	strb	r0, [r3]
locret_801FE5C:
	pop	{r4,pc}
	.size	 sub_801FE24,.-sub_801FE24

	.globl	sub_801FE5E
	.type	 sub_801FE5E,function
	.thumb_func
sub_801FE5E:
	ldr	r3, off_80200D0
	ldrb	r0, [r3]
	mov	pc, lr
	.size	 sub_801FE5E,.-sub_801FE5E

	.globl	sub_801FE64
	.type	 sub_801FE64,function
	.thumb_func
sub_801FE64:
	ldr	r1, off_80200D4
	mov	r0, #0
	strb	r0, [r1]
	mov	pc, lr
	.size	 sub_801FE64,.-sub_801FE64

	.globl	sub_801FE6C
	.type	 sub_801FE6C,function
	.thumb_func
sub_801FE6C:
	push	{r4,r6,lr}
	ldr	r4, off_80200D8
	ldrb	r6, [r4,#1]
	mov	r0, #2
	strb	r0, [r4,#1]
	ldrb	r0, [r4]
	tst	r0, r0
	beq	loc_801FED2
	movflag	EVENT_172D
	bl	TestEventFlagFromImmediate
	beq	loc_801FEB6
	strb	r6, [r4,#1]
	ldrb	r0, [r4,#1]
	cmp	r0, #2
	bne	locret_801FEE6
	push	{r5}
	bl	GetBattleEffects
	mov	r1, #8
	tst	r0, r1
	pop	{r5}
	beq	locret_801FEE6
	mov	r0, #0
	bl	sub_8144D04
	cmp	r0, #1
	bne	loc_801FEB0
	mov	r0, #3
	bl	sub_8144D04
	cmp	r0, #1
	beq	locret_801FEE6
loc_801FEB0:
	mov	r0, #4
	strb	r0, [r4,#1]
	b	locret_801FEE6
loc_801FEB6:
	push	{r5}
	bl	GetBattleEffects
	mov	r1, #8
	tst	r0, r1
	pop	{r5}
	bne	loc_801FECC
	bl	sub_803DEB4
	strb	r0, [r4,#1]
	b	locret_801FEE6
loc_801FECC:
	strb	r6, [r4,#1]
	ldrb	r0, [r4,#1]
	b	locret_801FEE6
loc_801FED2:
	ldr	r0, off_80200DC
	ldr	r1, off_80200E0
	mov	r2, #0x10
	bl	CopyWords
	ldr	r0, off_80200E4
	ldr	r1, off_80200E8
	mov	r2, #0x10
	bl	CopyWords
locret_801FEE6:
	pop	{r4,r6,pc}
	.size	 sub_801FE6C,.-sub_801FE6C

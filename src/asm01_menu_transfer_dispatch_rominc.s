	.globl	eStruct203F7D8_getUnk01
	.type	 eStruct203F7D8_getUnk01,function
	.thumb_func
eStruct203F7D8_getUnk01:
	ldr	r0, off_80200EC
	ldrb	r0, [r0,#1]
	mov	pc, lr
	.size	 eStruct203F7D8_getUnk01,.-eStruct203F7D8_getUnk01

	.globl	sub_801FEEE
	.type	 sub_801FEEE,function
	.thumb_func
sub_801FEEE:
	push	{r4-r7,lr}
	mov	r7, r0
	bl	eStruct200BC30_getJumpOffset00
	ldr	r1, off_801FF04
	ldr	r2, [r1,r0]
	mov	r0, r7
	mov	lr, pc
	bx	r2
	pop	{r4-r7,pc}
	.balign 4, 0
off_801FF04:
	.word	off_801FF08
off_801FF08:
	.word	sub_801FF18+1
	.word	sub_801FFD6+1
	.word	sub_801FFD6+1
	.word	sub_801FF18+1
.Lfe1:
	.size	 sub_801FEEE,.Lfe1-sub_801FEEE

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

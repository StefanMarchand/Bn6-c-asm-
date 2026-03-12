	.globl	sub_80200A4
	.type	 sub_80200A4,function
	.thumb_func
sub_80200A4:
	ldr	r3, off_8020130
	strb	r0, [r3,#3]
	ldrb	r0, [r3,#2]
	mov	r1, #1
	orr	r0, r1
	strb	r0, [r3,#2]
	mov	pc, lr
.Lfe1:
	.size	 sub_80200A4,.Lfe1-sub_80200A4

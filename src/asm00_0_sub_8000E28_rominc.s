	.globl	sub_8000E28
	.type	 sub_8000E28,function
	.thumb_func
sub_8000E28:
	mov	r3, r10
	ldr	r3, [r3,#0x40]
	ldr	r0, [r3,#0x18]
	mov	pc, lr
	.size	 sub_8000E28,.-sub_8000E28

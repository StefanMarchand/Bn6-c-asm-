	.globl	CopyBytes
	.type	 CopyBytes,function
	.thumb_func
CopyBytes:
	sub	r2, #1
	ldrb	r3, [r0,r2]
	strb	r3, [r1,r2]
	bne	CopyBytes
	mov	pc, lr
.Lfe1:
	.size	 CopyBytes,.Lfe1-CopyBytes

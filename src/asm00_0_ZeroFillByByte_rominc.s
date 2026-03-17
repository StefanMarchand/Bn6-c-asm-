	.globl	ZeroFillByByte
	.type	 ZeroFillByByte,function
	.thumb_func
ZeroFillByByte:
	push	{r0-r2,lr}
	mov	r2, #0
.Lloop_80008B8:
	sub	r1, #1
	strb	r2, [r0,r1]
	bne	.Lloop_80008B8
	pop	{r0-r2,pc}
.Lfe1:
	.size	 ZeroFillByByte,.Lfe1-ZeroFillByByte

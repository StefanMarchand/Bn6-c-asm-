	.globl	ZeroFillByWord
	.type	 ZeroFillByWord,function
	.thumb_func
ZeroFillByWord:
	push	{r0-r3,lr}
	ldr	r2, .LWordFillCpuSetMask_80008FC
	lsr	r1, r1, #2
	orr	r2, r1
	mov	r1, r0
	sub	sp, sp, #4
	mov	r0, #0
	str	r0, [sp]
	mov	r0, sp
	bl	SWI_CpuSet
	add	sp, sp, #4
	pop	{r0-r3,pc}
	.align	2, 0
.LWordFillCpuSetMask_80008FC:
	.word	0x5000000
.Lfe1:
	.size	 ZeroFillByWord,.Lfe1-ZeroFillByWord

	.globl	ZeroFillByEightWords
	.type	 ZeroFillByEightWords,function
	.thumb_func
ZeroFillByEightWords:
	push	{r0-r3,lr}
	ldr	r2, .LFillCpuFastSetMask_800091C
	lsr	r1, r1, #2
	orr	r2, r1
	mov	r1, r0
	sub	sp, sp, #4
	mov	r0, #0
	str	r0, [sp]
	mov	r0, sp
	bl	SWI_CpuFastSet
	add	sp, sp, #4
	pop	{r0-r3,pc}
	.align	2, 0
.LFillCpuFastSetMask_800091C:
	.word	0x1000000
.Lfe1:
	.size	 ZeroFillByEightWords,.Lfe1-ZeroFillByEightWords

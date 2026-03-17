	.globl	CopyByEightWords
	.type	 CopyByEightWords,function
	.thumb_func
CopyByEightWords:
	push	{r0-r3,lr}
	ldr	r3, .LCopyFastCpuSetMask_8000960
	lsr	r2, r2, #2
	orr	r2, r3
	bl	SWI_CpuFastSet
	pop	{r0-r3,pc}
	.align	2, 0
.LCopyFastCpuSetMask_8000960:
	.word	0x0
.Lfe1:
	.size	 CopyByEightWords,.Lfe1-CopyByEightWords

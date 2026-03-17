	.globl	CopyHalfwords
	.type	 CopyHalfwords,function
	.thumb_func
CopyHalfwords:
	push	{r0-r3,lr}
	ldr	r3, .LHalfwordCopyCpuSetMask_8000938
	lsr	r2, r2, #1
	orr	r2, r3
	bl	SWI_CpuSet
	pop	{r0-r3,pc}
	.align	2, 0
.LHalfwordCopyCpuSetMask_8000938:
	.word	0x0
.Lfe1:
	.size	 CopyHalfwords,.Lfe1-CopyHalfwords

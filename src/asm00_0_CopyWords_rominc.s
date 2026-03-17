	.globl	CopyWords
	.type	 CopyWords,function
	.thumb_func
CopyWords:
	push	{r0-r3,lr}
	ldr	r3, .LWordCopyCpuSetMask_800094C
	lsr	r2, r2, #2
	orr	r2, r3
	bl	SWI_CpuSet
	pop	{r0-r3,pc}
	.align	2, 0
.LWordCopyCpuSetMask_800094C:
	.word	0x4000000
.Lfe1:
	.size	 CopyWords,.Lfe1-CopyWords

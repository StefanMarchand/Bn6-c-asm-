	.globl	ZeroFillByHalfword
	.type	 ZeroFillByHalfword,function
	.thumb_func
ZeroFillByHalfword:
	push	{r0-r3,lr}
	ldr	r2, .LHalfwordFillCpuSetMask_80008DC
	lsr	r1, r1, #1
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
.LHalfwordFillCpuSetMask_80008DC:
	.word	0x1000000
.Lfe1:
	.size	 ZeroFillByHalfword,.Lfe1-ZeroFillByHalfword

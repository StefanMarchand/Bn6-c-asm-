	.globl	ShuffleByteList_SecondaryRNG
	.type	 ShuffleByteList_SecondaryRNG,function
	.thumb_func
ShuffleByteList_SecondaryRNG:
	push	{r4-r6,lr}
loc_8000CA8:
	push	{r0,r2}
	push	{r1}
	bl	GetPositiveSignedRNGSecondary
	pop	{r1}
	push	{r1}
	svc	6
	mov	r3, r1
	pop	{r1}
	push	{r1,r3}
	bl	GetPositiveSignedRNGSecondary
	pop	{r1}
	push	{r1}
	svc	6
	mov	r4, r1
	pop	{r1,r3}
	pop	{r0,r2}
	ldrb	r5, [r0,r3]
	ldrb	r6, [r0,r4]
	strb	r6, [r0,r3]
	strb	r5, [r0,r4]
	sub	r2, #1
	bne	loc_8000CA8
	pop	{r4-r6,pc}
	.size	 ShuffleByteList_SecondaryRNG,.-ShuffleByteList_SecondaryRNG

	.globl	ShuffleHwordList_SecondaryRNG
	.type	 ShuffleHwordList_SecondaryRNG,function
	.thumb_func
ShuffleHwordList_SecondaryRNG:
	push	{r4-r6,lr}
loc_8000D14:
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
	add	r3, r3, r3
	add	r4, r4, r4
	ldrh	r5, [r0,r3]
	ldrh	r6, [r0,r4]
	strh	r6, [r0,r3]
	strh	r5, [r0,r4]
	sub	r2, #1
	bne	loc_8000D14
	pop	{r4-r6,pc}
	.size	 ShuffleHwordList_SecondaryRNG,.-ShuffleHwordList_SecondaryRNG

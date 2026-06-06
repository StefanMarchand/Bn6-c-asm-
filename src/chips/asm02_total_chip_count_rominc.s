	.globl	GetTotalChipCount
	.type	 GetTotalChipCount,function
	.thumb_func
GetTotalChipCount:
	push	{r7,lr}
	push	{r0}
	bl	encryption_testPack_8006e84
	pop	{r0}
	bne	loc_8021BFE
	mov	r7, r10
	ldr	r7, [r7,#0x4c]
	mov	r1, #12
	mul	r1, r0
	add	r7, r7, r1
	ldrb	r0, [r7]
	ldrb	r1, [r7,#1]
	add	r0, r0, r1
	ldrb	r1, [r7,#2]
	add	r0, r0, r1
	ldrb	r1, [r7,#3]
	add	r0, r0, r1
	pop	{r7,pc}
loc_8021BFE:
	mov	r0, #0
	pop	{r7,pc}
	.size	 GetTotalChipCount,.-GetTotalChipCount
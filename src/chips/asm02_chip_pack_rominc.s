	.globl	split9BitsFromBitfield_8021AE0
	.type	 split9BitsFromBitfield_8021AE0,function
	.thumb_func
split9BitsFromBitfield_8021AE0:
	push	{lr}
	lsr	r1, r0, #9
	ldr	r2, .Mask9Bits
	and	r0, r2
	pop	{pc}
	.balign	4, 0x00
.Mask9Bits:
	.hword	0x01FF
	.size	 split9BitsFromBitfield_8021AE0,.-split9BitsFromBitfield_8021AE0

	.globl	addChipsToChipPackOffset_8021b5a
	.type	 addChipsToChipPackOffset_8021b5a,function
	.thumb_func
addChipsToChipPackOffset_8021b5a:
	mov	r3, #1
	ldrb	r1, [r0]
	cmp	r1, #99
	beq	loc_8021B6E
	mov	r3, #0
	add	r1, r1, r2
	cmp	r1, #99
	ble	loc_8021B6E
	mov	r1, #99
	mov	r3, #2
loc_8021B6E:
	strb	r1, [r0]
	mov	pc, lr
	.balign	4, 0
off_8021B74:
	.word	0x1E20
	.size	 addChipsToChipPackOffset_8021b5a,.-addChipsToChipPackOffset_8021b5a

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

	.globl	zeroFill_e2002230
	.type	 zeroFill_e2002230,function
	.thumb_func
zeroFill_e2002230:
	push	{lr}
	mov	r0, r10
	ldr	r0, [r0,#0x4c]
	ldr	r1, dword_8021C78
	bl	ZeroFillByWord
	pop	{pc}
	.balign	4, 0
dword_8021C78:
	.word	0xF00
	.size	 zeroFill_e2002230,.-zeroFill_e2002230
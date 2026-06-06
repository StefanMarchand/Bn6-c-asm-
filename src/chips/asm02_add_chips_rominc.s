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
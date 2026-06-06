	.globl	getChip8021DA8
	.type	 getChip8021DA8,function
	.thumb_func
getChip8021DA8:
	ldr	r1, off_8021AB0
	mov	r2, #44
	mul	r0, r2
	add	r0, r0, r1
	mov	pc, lr
	.byte	0, 0
off_8021AB0:
	.word	ChipDataArr_8021DA8
	.size	 getChip8021DA8,.-getChip8021DA8
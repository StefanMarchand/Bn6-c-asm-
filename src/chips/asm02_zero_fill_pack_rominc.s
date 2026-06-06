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
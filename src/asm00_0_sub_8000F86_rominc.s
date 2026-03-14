	.globl	sub_8000F86
	.type	 sub_8000F86,function
	.thumb_func
sub_8000F86:
	push	{r4-r7,lr}
	mov	r4, r0
	bl	sub_803F838
	bne	.Llocret_8000FAA
	movflag	EVENT_E00
	bl	SetEventFlagFromImmediate
	movflag	EVENT_1001
	bl	SetEventFlagFromImmediate
	mov	r0, r10
	ldr	r0, [r0,#0x40]
	str	r4, [r0,#0x18]
	bl	sub_803F79E
.Llocret_8000FAA:
	pop	{r4-r7,pc}
	.size	 sub_8000F86,.-sub_8000F86

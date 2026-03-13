	.globl	eStruct2038160_clearStruct
	.type	 eStruct2038160_clearStruct,function
	.thumb_func
eStruct2038160_clearStruct:
	push	{lr}
	ldr	r0, off_8020164
	mov	r1, #4
	bl	ZeroFillByWord
	pop	{pc}
	.size	 eStruct2038160_clearStruct,.-eStruct2038160_clearStruct

	.globl	sub_8020140
	.type	 sub_8020140,function
	.thumb_func
sub_8020140:
	push	{r7,lr}
	bl	test0x200bc50_0x5_813D60C
	beq	locret_802015C
	bl	eStruct200BC30_getJumpOffset00
	cmp	r0, #0xc
	bne	locret_802015C
	ldr	r7, off_8020168
	bl	sub_813D66C
	bl	sub_803C620
	strb	r0, [r7,#1]
locret_802015C:
	pop	{r7,pc}
	.size	 sub_8020140,.-sub_8020140

	.globl	eStruct2038160_getBattleTerminate01
	.type	 eStruct2038160_getBattleTerminate01,function
	.thumb_func
eStruct2038160_getBattleTerminate01:
	ldr	r0, off_802016C
	ldrb	r0, [r0,#1]
	mov	pc, lr
	.size	 eStruct2038160_getBattleTerminate01,.-eStruct2038160_getBattleTerminate01

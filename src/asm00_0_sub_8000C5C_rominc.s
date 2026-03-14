	.globl	sub_8000C5C
	.type	 sub_8000C5C,function
	.thumb_func
sub_8000C5C:
	mov	r1, #1
	tst	r0, r0
	beq	loc_8000C6E
	mov	r1, #0
loc_8000C64:
	tst	r0, r0
	beq	loc_8000C6E
	add	r1, #1
	lsr	r0, r0, #4
	b	loc_8000C64
loc_8000C6E:
	mov	r0, r1
	mov	pc, lr
	.size	 sub_8000C5C,.-sub_8000C5C

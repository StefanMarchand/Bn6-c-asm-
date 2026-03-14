	.globl	sub_8000E30
	.type	 sub_8000E30,function
	.thumb_func
sub_8000E30:
	push	{r4-r7,lr}
	mov	r4, #0
	mov	r0, r4
	tst	r0, r0
	pop	{r4-r7,pc}
	.size	 sub_8000E30,.-sub_8000E30

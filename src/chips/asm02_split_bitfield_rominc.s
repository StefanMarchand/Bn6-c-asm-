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
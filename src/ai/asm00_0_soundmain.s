	.globl	call_m4aSoundMain
	.type	 call_m4aSoundMain,function
	.thumb_func
call_m4aSoundMain:
	push	{lr}
	bl	m4aSoundMain
	pop	{pc}
.Lfe1:
	.size	 call_m4aSoundMain,.Lfe1-call_m4aSoundMain

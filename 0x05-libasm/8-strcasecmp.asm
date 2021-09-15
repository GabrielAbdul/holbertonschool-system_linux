BITS 64
global asm_strcasecmp
section	.text

asm_strcasecmp:
	push	rbp
	mov	rbp,	rsp
	xor	rcx,	rcx
	cmp	rdi,	0
	je	out
	cmp	rsi,	0
	je	out
	jmp 	compare1

compare1:
	mov	r8b,	[rdi + rcx]
	cmp	r8b,	65
	jl	compare2
	cmp	r8b,	90
	jl	islower1

compare2:
	mov	r9b,	[rsi + rcx]
	cmp	r9b,	65
	jl	comparef
	cmp	r9b,	90
	jl	islower2

comparef:
	cmp	r8b,	r9b
	jne	out
	cmp	r8b,	0
	je	out
	cmp	r9b,	0
	je	out
	inc	rcx
	jmp	compare1

islower1:
	add     r8b,    32
	jmp     compare2

islower2:
	add     r9b,    32
	jmp     comparef

out:
	sub	r8b,	r9b
	movsx	rax,	r8b
	mov	rsp,	rbp
	pop	rbp
	ret	

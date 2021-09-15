	BITS 64
	global	asm_strcspn
	section	.text

asm_strcspn:
	push	rbp
	mov	rbp,	rsp
	xor	rcx,	rcx
	xor	r15,	r15
	cmp	rdi,	0
	je	end_strcspn
	cmp	rsi,	0
	je	end_strcspn

loop:
	cmp	byte[rdi + rcx], 0
	je	end_strcspn
	jmp	check_args

check_args:
	mov	r8b,	[rdi + rcx]
	mov	r9b,	[rsi + r15]
	cmp	r8b,  	r9b
	je	end_strcspn
	cmp	r9b	, 0
	je	reset_count
	inc 	r15
	jmp	check_args

reset_count:
	xor	r15,  r15
	inc	rcx
	jmp  	loop

end_strcspn:

	mov 	rax,	rcx
	mov	rsp,	rbp
	pop	rbp
	ret

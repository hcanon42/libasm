section	.text
	global ft_strlen

ft_strlen:			;tell linker entry point

	mov rax, 0		;initialize index

loop:

	cmp [rdi], byte 0	;is this the end ?
	jne redo		;if not i++ index_ret++
	ret

redo:

	inc rax
	inc rdi
	jmp loop

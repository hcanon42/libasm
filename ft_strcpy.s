section .text
	global ft_strcpy

ft_strcpy:

	mov rax, rdi

_loop:
	
	mov r8b, [rsi]
	mov [rdi], r8b
	cmp [rsi], byte 0
	jne _redo
	ret

_redo:

	inc rsi
	inc rdi
	jmp _loop

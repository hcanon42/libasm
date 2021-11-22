section .text
	global ft_strcmp

ft_strcmp:
	xor rcx, rcx

_loop_cmp:

	mov r15b, [rsi]
	cmp [rdi], byte 0
	je _end_cmp
	cmp [rsi], byte 0
	je _end_cmp
	cmp [rdi], r15b
	jne _end_cmp
	inc rsi
	inc rdi
	jmp _loop_cmp

_end_cmp:

	mov r14b, [rdi]
	movzx rax, r14b
	movzx rdx, r15b
	sub rax, rdx
	ret

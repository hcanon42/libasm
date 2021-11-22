section .text:
	global ft_read
	extern __errno_location

ft_read:

	mov rax, 0
	syscall
	cmp rax, byte 0
	jl _error_read
	ret

_error_read:

	mov r10, rax
	call __errno_location
	neg r10
	mov [rax], r10
	mov rax, -1
	ret

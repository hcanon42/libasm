section .text
	global ft_write
	extern __errno_location

ft_write:

	mov rax, 1
	syscall
	cmp rax, byte 0
	jl _error_read
	ret

_error_read:

	mov r10, rax
	call __errno_location
	add r10, 6
	mov [rax], r10
	mov rax, -1
	ret

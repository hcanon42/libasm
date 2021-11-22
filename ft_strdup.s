section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:

	push rdi
	call ft_strlen	;get the length to malloc
	inc rax		;add the \0

	mov rdi, rax	;rdi is malloc argument
	call malloc

	pop rsi		;rsi is now src
	cmp rax, 0
	je end
	mov rdi, rax	;rdi is now where the memory was allocted
	call ft_strcpy	;copy rsi in rdi 

end:

	ret

section .text
	global _ft_strlen

_ft_strlen:		; ft_strlen(char *s)
	push rbp
	mov rbp, rsp
	sub rsp, 16

	mov rax, 0
	.main_loop:
		cmp byte[rdi + rax], 0
		je .end
		inc rax
		jmp .main_loop

	.end:
		mov rsp, rbp
		pop rbp
		ret

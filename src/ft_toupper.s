section .text
	global _ft_toupper

_ft_toupper:		; int ft_toupper(int c)
	push rbp
	mov rbp, rsp

	cmp rdi, 'a'
	jl .no_change
	cmp rdi, 'z'
	jg .no_change
	jmp .to_upper

	.no_change:
		mov rax, rdi
		jmp .end

	.to_upper:
		sub rdi, 32
		mov rax, rdi
		jmp .end

	.end:
		mov rsp, rbp
		pop rbp
		ret

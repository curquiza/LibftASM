section .text
	global _ft_tolower

_ft_tolower:		; ft_tolower(int c)
	push rbp
	mov rbp, rsp

	cmp rdi, 'A'
	jl .no_change
	cmp rdi, 'Z'
	jg .no_change
	jmp .to_upper

	.no_change:
		mov rax, rdi
		jmp .end

	.to_upper:
		add rdi, 32
		mov rax, rdi
		jmp .end

	.end:
		mov rsp, rbp
		pop rbp
		ret

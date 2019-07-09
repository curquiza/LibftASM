%define FALSE		0
%define TRUE 		1

section .text
	global _ft_isdigit

_ft_isdigit:		; ft_isdigit(char c)
	push rbp
	mov rbp, rsp
	sub rsp, 16

	cmp rdi, '0'
	jl .false
	cmp rdi, '9'
	jg .false
	jmp .true

	.false:
		mov rax, FALSE
		jmp .end

	.true:
		mov rax, TRUE
		jmp .end

	.end:
		mov rsp, rbp
		pop rbp
		ret

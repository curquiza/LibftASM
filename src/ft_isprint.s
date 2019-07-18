%define FALSE		0
%define TRUE 		1

section .text
	global _ft_isprint

_ft_isprint:		; int ft_isprint(int c)
	push rbp
	mov rbp, rsp

	cmp rdi, 32
	jl .false
	cmp rdi, 126
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

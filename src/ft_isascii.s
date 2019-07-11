%define FALSE		0
%define TRUE 		1

section .text
	global _ft_isascii

_ft_isascii:		; ft_isascii(int c)
	push rbp
	mov rbp, rsp
	sub rsp, 16

	cmp rdi, 0
	jl .false
	cmp rdi, 127
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

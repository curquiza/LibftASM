%define FALSE		0
%define TRUE 		1

section .text
	global _ft_isalpha

_ft_isalpha:		; ft_isalpha(int c)
	push rbp
	mov rbp, rsp

	cmp rdi, 'A'
	jl .false
	cmp rdi, 'Z'
	jle .true
	cmp rdi, 'a'
	jl .false
	cmp rdi, 'z'
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

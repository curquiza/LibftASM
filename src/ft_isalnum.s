%define FALSE		0
%define TRUE 		1

section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:		; int ft_isalnum(int c)
	push rbp
	mov rbp, rsp

	call _ft_isdigit
	cmp rax, TRUE
	je .true
	call _ft_isalpha
	cmp rax, TRUE
	je .true
	jmp .false

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

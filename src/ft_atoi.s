section .text
	global _ft_atoi

_ft_atoi:		; int ft_atoi(const char *str)
	push rbp
	mov rbp, rsp

	sub rsp, 64				; save 64bits in function scope

	mov rax, 0					; rslt = 0
	mov rcx, 1					; neg = 1

	.skip_blank:
		cmp byte[rdi], 32
		je .inc
		cmp byte[rdi], 9
		je .inc
		cmp byte[rdi], 10
		je .inc
		cmp byte[rdi], 11
		je .inc
		cmp byte[rdi], 12
		je .inc
		cmp byte[rdi], 13
		je .inc
		jmp .check_sign_minus
		.inc:
			inc rdi					; str++
			jmp .skip_blank

	.check_sign_minus:
		cmp byte[rdi], '-'
		jne .check_sign_plus
		mov rcx, -1					; neg = -1
		inc rdi
		jmp .calc_loop

	.check_sign_plus:
		cmp byte[rdi], '+'
		jne .calc_loop
		inc rdi
		jmp .calc_loop

	.calc_loop:
		cmp byte[rdi], 0
		je .end
		cmp byte[rdi], '0'
		jl .end
		cmp byte[rdi], '9'
		jg .end

		mov rsp, 10
		mul rsp					; rax = rax * rsp => rslt = rslt * 10
		movzx rsp, byte[rdi]
		add rax, rsp			; rslt = rslt + str[i]
		sub rax, '0'			; rstl = rslt - '0'

		inc rdi					; str++
		jmp .calc_loop

	.end:
		mul rcx					; rax = rax * rcx => rslt = rslt * neg
		mov rsp, rbp			; Restore scope
		pop rbp
		ret

section .text
	global _ft_strcmp

_ft_strcmp:		; int ft_strcmp(const char *s1, const char *s2)
	push rbp
	mov rbp, rsp

	sub rsp, 64						; save 64bits in function scope

	.loop:

		movzx rax, byte[rdi]		; start comparison
		movzx rsp, byte[rsi]
		sub rax, rsp				; dst - src
		cmp rax, 0					; check (dest[i] - src[i] == 0)
		jne .end

		cmp byte[rdi], 0			; check (dest[i] != '\0')
		je .end
		cmp byte[rsi], 0			; check (src[i] != '\0')
		je .end

		inc rdi
		inc rsi
		jmp .loop

	.end:
		mov rsp, rbp				; Restore scope
		pop rbp
		ret

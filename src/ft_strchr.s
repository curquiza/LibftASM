section .text
	global _ft_strchr

_ft_strchr:		; char *ft_strchr(const char *s, int c)
	push rbp
	mov rbp, rsp

	sub rsp, 64						; save 64bits in function scope

	.loop:
		movzx rsp, byte[rdi]
		cmp rsi, rsp
		je .found
		cmp byte[rdi], 0
		je .not_found
		inc rdi
		jmp .loop

	.found:
		mov rax, rdi
		jmp .end

	.not_found:
		mov rax, 0
		jmp .end

	.end:
		mov rsp, rbp				; Restore scope
		pop rbp
		ret

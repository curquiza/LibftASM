section .data
	format: db "end rcx = %d", 10, 0

section .text
	global _ft_strcmp

_ft_strcmp:		; char *ft_strcmp(const char *s1, const char *s2)
	push rbp
	mov rbp, rsp

	sub rsp, 64						; save 64bits in function scope

	.loop:
		; mov [rsp], rdi
		; mov [rsp + 64], rsi
		cmp byte[rdi], 0
		je .end
		cmp byte[rsi], 0
		je .end
		cmp rdi, rsi
		je .end
		inc rdi
		inc rsi
		jmp .loop


	; cmp byte[rdi], 0
	; jne .compare
	; cmp byte[rsi], 0
	; jne .compare
	; mov rax, 0
	; jmp .end						; if dest[0] == 0 && src[0] == 0; return 0

	; .compare:
	; 	mov rcx, -1
	; 	cld
	; 	repe cmpsb					; lopp until \0 or dest != src (dest and src are incremented)

		; cmp byte[rdi - 1], byte[rdi - 1]
		; je .end

		; movzx rax, byte[rdi - 1]
		; movzx rsp, byte[rsi - 1]
		; sub rax, rsp				; dst - src

	.end:
		; mov rax, 0
		movzx rax, byte[rdi]
		movzx rsp, byte[rsi]
		sub rax, rsp				; dst - src

		mov rsp, rbp				; Restore scope
		pop rbp
		ret

section .text
	global _ft_strdup
	extern _ft_strnew
	extern _ft_strcpy
	extern _ft_strlen

_ft_strdup:		; char *ft_strdup(const char *s1)
	push rbp
	mov rbp, rsp

	sub rsp, 64				; save 64bits in function scope
	mov [rsp], rdi			; save str

	call _ft_strlen
	mov rdi, rax			; move len in rdi
	call _ft_strnew

	cmp rax, 0				; if malloc failed, leave
	je .end

	mov rdi, rax			; dest = ft_strnew return
	mov rsi, [rsp]			; src
	call _ft_strcpy

	.end:
		mov rsp, rbp		; Restore rbp
		pop rbp
		ret

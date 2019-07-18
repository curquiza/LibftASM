section .text
	global _ft_strjoin
	extern _ft_strlen
	extern _ft_strnew
	extern _ft_strcat

_concat_len:	; concat_len(char *s1, char *s2)
	push rbp
	mov rbp, rsp

	sub rsp, 64

	mov [rsp], rsi			; save s2

	call _ft_strlen			; s1_len

	mov rdi, [rsp]			; s2 as param for strlen
	mov [rsp], rax			; stock s1_len
	call _ft_strlen			; s2_len

	add rax, [rsp]			; return(s1_len + s2_len)

	mov rsp, rbp
	pop rbp
	ret

_ft_strjoin:		; char *ft_strjoin(const char *s1, const char *s2)
	push rbp
	mov rbp, rsp

	cmp rdi, 0				; if s1 == NULL; return NULL
	je .null_end
	cmp rsi, 0				; if s2 == NULL; return NULL
	je .null_end

	sub rsp, 128			; save 128bits in function scope
	mov [rsp], rdi			; save s1
	mov [rsp + 64], rsi		; save s2

	call _concat_len		; s1_len + s2_len
	mov rdi, rax
	call _ft_strnew			; strnew(s1_len + s2_len)

	cmp rax, 0				; if malloc failed, leave
	je .null_end

	mov rdi, rax			; allocated str = rslt
	mov rsi, [rsp]			; s1
	call _ft_strcat			; copy s1 in rslt

	mov rdi, rax			; allocated str = rslt = content of s1 here
	mov rsi, [rsp + 64]		; s2
	call _ft_strcat			; copy s2 in rslt

	jmp .end

	.null_end:
		mov rax, 0
		jmp .end

	.end:
		mov rsp, rbp
		pop rbp
		ret

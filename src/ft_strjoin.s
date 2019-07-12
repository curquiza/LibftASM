section .text
	global _ft_strjoin
	extern _ft_strlen
	extern _ft_strnew
	extern _ft_strcat

; _concat_len:
; 	push rbp
; 	mov rbp, rsp


; 	mov rsp, rbp
; 	pop rbp
; 	ret


_ft_strjoin:		; char *ft_strjoin(const char *s1, const char *s2)
	push rbp
	mov rbp, rsp

	cmp rdi, 0
	je .null_end
	cmp rsi, 0
	je .null_end

	sub rsp, 192			; save 192bits in function scope
	mov [rsp], rdi			; save s1
	mov [rsp + 64], rsi		; save s2

	call _ft_strlen			; s1_len
	mov [rsp + 128], rax	; stock s1_len

	mov rdi, [rsp + 64]
	call _ft_strlen			; s2_len

	add [rsp + 128], rax	; s1_len + s2_len

	mov rdi, [rsp + 128]
	call _ft_strnew

	mov rdi, rax			; allocated str = rslt
	mov rsi, [rsp]			; s1
	call _ft_strcat

	mov rdi, rax			; allocated str = rslt = content of s1 here
	mov rsi, [rsp + 64]		; s2
	call _ft_strcat

	jmp .end

	.null_end:
		mov rax, 0
		jmp .end

	.end:
		mov rsp, rbp
		pop rbp
		ret

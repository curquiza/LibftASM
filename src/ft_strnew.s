section .text
	global _ft_strnew
	extern _ft_memalloc
	extern _ft_bzero

_ft_strnew:		; char *ft_strnew(size_t size)
	push rbp
	mov rbp, rsp

	sub rsp, 64				; save 64bits in function scope

	add rdi, 1
	mov [rsp], rdi			; save length

	call _ft_memalloc

	cmp rax, 0				; if malloc failed, leave
	je .end

	mov rdi, rax			; pointer
	mov rsi, [rsp]			; len
	call _ft_bzero			; bzero

	.end:
		mov rsp, rbp	; Restore the stack and rbp
		pop rbp
		ret

section .text
	global _ft_memalloc
	extern _ft_memset
	extern _malloc

_ft_memalloc:		; void *ft_memalloc(size_t size)
	push rbp
	mov rbp, rsp
	sub rsp, 32		; save 32 bits in function scope on stack

	mov [rsp], rdi	; stock size in stack from function scope

	call _malloc
	cmp rax, 0
	je .end

	mov rdi, rax
	mov rsi, 0
	mov rdx, [rsp]
	call _ft_memset		; ft_memset return = ft_memalloc return
	jmp .end

	.end:
		mov rsp, rbp	; Restore the scope
		pop rbp
		ret

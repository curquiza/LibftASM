section .text
	global _ft_memalloc
	extern _ft_memset
	extern _malloc

_ft_memalloc:		; void *ft_memalloc(size_t size)
	push rbp
	mov rbp, rsp
	sub rsp, 32

	mov [rsp], rdi

	call _malloc

	mov rdi, rax
	mov rsi, 'a'
	mov rdx, [rsp]
	call _ft_memset		; ft_memset return = ft_memalloc return

	.end:
		mov rsp, rbp	; Restore the stack and rbp
		pop rbp
		ret

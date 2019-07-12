section .text
	global _ft_strnew
	extern _ft_memalloc

_ft_strnew:		; char *ft_strnew(size_t size)
	push rbp
	mov rbp, rsp

	add rdi, 1
	call _ft_memalloc 		; ft_memalloc return = ft_strnew return

	.end:
		mov rsp, rbp	; Restore the stack and rbp
		pop rbp
		ret

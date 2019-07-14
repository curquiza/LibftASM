section .text
	global _ft_cat

_ft_cat:		; int ft_cat()
	push rbp
	mov rbp, rsp

	mov rax, 0

	.end:
		mov rsp, rbp			; Restore scope
		pop rbp
		ret

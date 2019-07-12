section .text
	global _ft_bzero

_ft_bzero:		; ft_bzero(void *s, int size)
			push rbp
			mov rbp, rsp

	.loop:
			dec rsi
			cmp rsi, 0
			jl .end
			mov byte[rdi + rsi], 0
			jmp .loop

	.end:
			mov rsp, rbp	; Restore the scope
			pop rbp
			ret

section .text
	global _ft_memcpy

_ft_memcpy:		; void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
	push rbp
	mov rbp, rsp

	mov rax, rdi	; save rdi addr in rax = return already ready
	mov rcx, rdx

	cld				; DF = 0 => left to right
	rep movsb		; copy rsi in rdi until rcx = 0 (rsi and rdi are incremented, rcx is decremented)
	jmp .end

	.end:
		mov rsp, rbp
		pop rbp
		ret

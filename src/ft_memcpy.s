section .text
	global _ft_memcpy

_ft_memcpy:		; void *memcpy(void *restrict dst, const void *restrict src, size_t n)
	push rbp
	mov rbp, rsp

	mov rax, rdi	; save rdi addr in rax
	mov rcx, rdx

	cld			; DF = 0 => left to right
	rep movsb	; copy rsi in rdi until rcx = 0 (rsi and rdi are incremented, rcx is decremented)

	.end:
		mov rsp, rbp
		pop rbp
		ret

section .text
	global _ft_memset

_ft_memset:			; void *ft_memset(void *b, int c, size_t len);
	push rbp
	mov rbp, rsp

	mov rax, rsi	; store char in rax to be compared (stosb)
	mov rcx, rdx	; store len in 3th param
	mov rdx, rdi	; save rdi first address

	cld				; DF = 0 => left to right
	rep stosb		; copy data from rax to rdi until rcx = 0

	mov rax, rdx	; return rdi first address
	jmp .end

	.end:
		mov rsp, rbp
		pop rbp
		ret

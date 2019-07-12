section .data
	format: db "s = %s", 10, 0

section .text
	global _ft_strcpy
	extern _ft_strlen
	extern _ft_memcpy

_ft_strcpy:		; char *strcpy(char * dst, const char * src);
	push rbp
	mov rbp, rsp

	sub rsp, 128				; save 128bits in function scope
	mov [rsp], rdi				; save rdi in function scope (dest)
	mov [rsp + 64], rsi			; save rsi in function scope (src)

	mov rdi, rsi
	call _ft_strlen				; get length of src

	mov rdi, [rsp]				; dest
	mov byte[rdi + rax], 0		; add \0 to dest
	mov rsi, [rsp + 64]			; src
	mov rdx, rax				; len
	call _ft_memcpy				; return ft_memcpy = return ft_strcpy

	.end:
		mov rsp, rbp
		pop rbp
		ret

section .text
	global _ft_strcat
	extern _ft_strlen

_ft_strcat:		; ft_strcat(char *s1, char *s2)
	push rbp
	mov rbp, rsp

	sub rsp, 128			; save 128bits in scope function
	mov [rsp], rdi			; save s1
	mov [rsp + 64], rsi		; save s2

	call _ft_strlen			; len in rax

	mov rdi, [rsp]			; restore s1
	mov rsi, [rsp + 64]		; restore s2

	.main_loop:
		mov dh, byte[rsi]
		mov byte[rdi + rax], dh		; copy byte from src to dest
		inc rsi						; src++
		inc rax						; len++
		cmp byte[rsi], 0			; end condition (src[i] == 0 ?)
		je .end
		jmp .main_loop

	.end:
		mov byte[rdi + rax], 0		;add \0
		mov rax, rdi
		mov rsp, rbp
		pop rbp
		ret

; section .data
; 	msg: db "strlen = %d", 10, 0

section .text
	global _ft_strcat
	extern _printf
	extern _ft_strlen

_ft_strcat:		; ft_strcat(char *s1, char *s2)
	push rbp
	mov rbp, rsp
	sub rsp, 16

	mov rdi, rdi		; useless
	call _ft_strlen

	.main_loop:
		mov dh, byte[rsi]
		mov byte[rdi + rax], dh
		inc rsi
		inc rax
		cmp byte[rsi], 0
		je .end
		jmp .main_loop

	.end:
		mov rax, rdi
		mov rsp, rbp
		pop rbp
		ret

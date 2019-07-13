section .text
	global _ft_strcmp

_ft_strcmp:		; char *ft_strcmp(const char *s1, const char *s2)
	push rbp
	mov rbp, rsp

	sub rsp, 64

	cld
	repe cmpsb

	; mov [rsp], byte[rdi]
	; sub [rsp], byte[rsi]
	; mov rax, [rsp]

	; sub byte[rdi], byte[rsi]
	; mov rax, byte[rdi]

	movzx rax, byte[rdi]
	sub al, byte[rsi]
	; mov byte[rax], al

	.end:
		mov rsp, rbp		; Restore rbp
		pop rbp
		ret

section .text
	global _ft_strlen

; _ft_strlen:		; size_t strlen(const char *s)
; 	push rbp
; 	mov rbp, rsp
; 	sub rsp, 16

; 	mov rax, 0
; 	.main_loop:
; 		cmp byte[rdi + rax], 0
; 		je .end
; 		inc rax
; 		jmp .main_loop

; 	.end:
; 		mov rsp, rbp
; 		pop rbp
; 		ret


_ft_strlen:		; size_t strlen(const char *s);
	push rbp
	mov rbp, rsp

	push rdi		; isolate rdi and push it to the stack
	mov rax, 0		; set rax to 0 for comparison (scasb)
	mov rcx, -1		; set rcx to -1 bc it will be decremented

	cld				; DF = 0 => left to right
	repne scasb		; compare rax and rdi (scasb) until the zero-flag is set = until there are similare (repne)

	not rcx			; pass rcx in positive
	sub rcx, 1		; get the right value
	mov rax, rcx	; return result
	jmp .end

	.end:
		pop rdi
		mov rsp, rbp
		pop rbp
		ret

; enlever push et pop rdi car ce n'est pas strlen qui doit s'adapter à ceux qui l'appelent

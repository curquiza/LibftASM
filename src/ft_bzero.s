; %define MACH_SYSCALL(nb)		0x2000000 | nb
; %define STDOUT					1
; %define WRITE					4

; section .data
; 	msg db "msg = %s", 10, 0
; 	msg2 db "rsi = %d", 10, 0

section .text
	global _ft_bzero
	; extern _printf

_ft_bzero:		; ft_bzero(void *s, int size)
			push rbp
			mov rbp, rsp
			sub rsp, 16

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

; %define MACH_SYSCALL(nb)		0x2000000 | nb
; %define STDOUT					1
; %define WRITE					4

section .data

msg:
	.format db "message = %s", 10, 0 ; 10 = \n

lol db "lol", 10, 0
	; .lol db "lol", 10 ; 10 = \n
	; .len equ $ - msg.content

section .text
	global _ft_bzero
	extern _printf

_ft_bzero:		; ft_bzero(void *s, int size)
			push rbp
			mov rbp, rsp

			; mov rcx, lol
	; .test_loop:
	; 		add rdx, 1
	; 		loop .test_loop
	; .test_loop:
	; 		inc rcx
	; 		cmp byte[rcx], 0
	; 		jne .test_loop
			mov rcx, rsi
	.loop_bzero:
			mov byte[rdi], 0
			loop .loop_bzero

			mov rdi, msg.format
			mov rsi, rcx
			call _printf
			; jmp .end

	.end:
			mov rsp, rbp	; Restore the scope
			pop rbp
			ret

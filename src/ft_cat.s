%define MACH_SYSCALL(nb)		0x2000000 | nb
%define STDOUT					1
%define READ					3
%define WRITE					4

section .bss
	buff: resb 1024
	buffsize: equ $ - buff

section .text
	global _ft_cat
	extern _ft_bzero

_ft_cat:				; void ft_cat(int fd)
	push rbp
	mov rbp, rsp

	sub rsp, 64			; save 64bits in function scope

	mov [rsp], rdi		; save fd

	.read_loop:
		mov rdi, [rsp]					; fd
		mov rsi, buff					; buff
		mov rdx, buffsize				; buffsize
		mov rax, MACH_SYSCALL(READ)		; read
		syscall

		cmp rax, 0						; if read return <= 0
		jle .end						; leave loop

		mov rdi, STDOUT					; fd
		mov rsi, buff					; buff
		mov rdx, buffsize				; buffsize
		mov rax, MACH_SYSCALL(WRITE)	; write
		syscall

		mov rdi, buff
		mov rsi, buffsize
		call _ft_bzero					; fill with 0 value in buff

		jmp .read_loop

	.end:
		mov rax, 0				; return void
		mov rsp, rbp			; Restore scope
		pop rbp
		ret

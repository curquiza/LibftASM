%define MACH_SYSCALL(nb)		0x2000000 | nb
%define STDOUT					1
%define WRITE					4

section .data
hello:
	.msg db "Hello World in main.s!", 10 ; 10 = \n
	.len equ $ - hello.msg

section .text
	global start
	global _main
	extern _ft_puts

start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	; push 23					; parameter
	; mov rdi, hello.msg		; parameter
	; call _ft_puts

	mov rdi, 23					; parameter
	mov rsi, hello.msg			; parameter
	call _ft_puts

	leave
	ret

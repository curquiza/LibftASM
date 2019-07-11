%define MACH_SYSCALL(nb)		0x2000000 | nb
%define STDOUT					1
%define WRITE					4

section .data
hello:
	.msg db "Hello World in main.s!", 0; 10 = \n
	.len equ $ - hello.msg
title:
	.ft_puts db 10, "FT_PUTS", 10, 0
	.ft_bzero db 10, 10, "FT_BZERO", 10, 0
tests:
	; .lol db "lol", 10, 0
	.before db "before = %s", 10, 0
	.after db "after = %s", 10, 0

section .text
	global start
	global _main
	extern _printf
	extern _ft_puts
	extern _ft_bzero

start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	mov rdi, title.ft_puts
	call _printf
	mov rdi, 23					; param
	mov rsi, hello.msg			; param
	call _ft_puts

	mov rdi, title.ft_bzero
	call _printf				; TITLE
	mov rdi, tests.before
	mov rsi, hello.msg
	call _printf				; printf("before = %s\n", hello.msg)
	mov rdi, hello.msg
	mov rsi, hello.len
	call _ft_bzero				; ft_bzero(hello.msg, hello.len)
	mov rdi, tests.after
	mov rsi, hello.msg			; printf("after = %s\n", hello.msg)
	call _printf

	leave
	ret

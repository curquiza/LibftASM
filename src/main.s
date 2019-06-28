%define MACH_SYSCALL(nb)		0x2000000 | nb
%define STDOUT					1
%define WRITE					4

section .data
hello:
	.msg db "Hello World!", 10 ; 10 = \n
	.len equ $ - hello.msg

section .text
	global start
	global _main

start:
	call _main
	ret

_ft_puts:		; ft_puts(int string_length)
	push rbp
	mov rbp, rsp
	mov rdx, [rbp + 16]
	mov rdi, STDOUT
	mov rsi, hello.msg
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	mov rsp, rbp	; Restore the stack and rbp
	pop rbp
	ret

_main:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	push 13			; parameter
	call _ft_puts
	leave
	ret

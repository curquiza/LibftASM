%define MACH_SYSCALL(nb)		0x2000000 | nb
%define STDOUT					1
%define WRITE					4

section .data
msg:
	.content db "In ft_puts", 10 ; 10 = \n
	.len equ $ - msg.content

section .text
	global _ft_puts

_ft_puts:		; ft_puts(int string_length, char *str)
	push rbp
	mov rbp, rsp
	mov rdx, [rbp + 16]
	mov rsi, rdi
	; mov rdx, msg.len
	; mov rsi, msg.content
	mov rdi, STDOUT
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	mov rsp, rbp	; Restore the stack and rbp
	pop rbp
	ret

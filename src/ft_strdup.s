; %define MACH_SYSCALL(nb)		0x2000000 | nb
; %define WRITE					4

section .data
	format: db "len = %s", 10, 0

section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy

	extern _printf

_ft_strdup:		; char *strdup(const char *s1);
	push rbp
	mov rbp, rsp

	mov rdx, rdi		; save param string in rdx
	call _ft_strlen
	mov r9, rax			; save len in r9

	mov rdi, rax
	add rdi, 1
	call _malloc

	mov rdi, rax		; result of malloc in rdi
	mov rsi, rdx		; restaure param string
	mov rdx, r9			; restaure len of string

	mov rdi, format
	mov rsi, rsi
	call _printf

	call _ft_memcpy

	mov rax, rdi

	.end:
		mov rsp, rbp	; Restore the stack and rbp
		pop rbp
		ret


; error :
; - avant envoi dans ft_memcpy : la len et rsi sont pas bons
; - je push pas rdi dans ft_memcpy

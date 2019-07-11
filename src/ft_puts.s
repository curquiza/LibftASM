%define MACH_SYSCALL(nb)		0x2000000 | nb
%define STDOUT					1
%define WRITE					4

%define SUCCESS					10
%define EOF						0

section .data
	.null_str: db "(null)", 0
	.newline_str: db 10, 0

section .text
	global _ft_puts
	extern _ft_strlen

_ft_write:		; ft_write(char *s, int len)
	mov rdx, rsi		; 3eme: len
	mov rsi, rdi		; 2nd: str
	mov rdi, STDOUT		; 1er: stdout
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	ret

_ft_puts:		; int ft_puts(char *str)
	push rbp
	mov rbp, rsp

	cmp rdi, 0
	je .null
	jmp .puts

	.null:
		mov rdi, .null_str

	.puts:
		call _ft_strlen		; param: rdi

		mov rsi, rax			; write str
		call _ft_write

		cmp rax, -1			; check return of write
		je .failure

		mov rsi, 1			; write newline
		mov rdi, .newline_str
		call _ft_write

		cmp rax, -1			; check return of write
		je .failure
		jmp .success

	.success:
		mov rax, SUCCESS
		jmp .end

	.failure:
		mov rax, EOF
		jmp .end

	.end:
		mov rsp, rbp	; Restore the stack and rbp
		pop rbp
		ret
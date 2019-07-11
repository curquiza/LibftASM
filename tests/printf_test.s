section .data
	format: db "message = %s", 10, 0
	message: db "coco l'asticot", 0

section .text
	global start
	global _main
	extern _printf

	start:
		call _main
		ret

	_main:
		push rbp
		mov rbp, rsp

		mov rdi, format
		mov rsi, message
		call _printf

		mov rsp, rbp
		pop rbp
		ret

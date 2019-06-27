; SYSCALL
%define MACH_SYSCALL(nb)        0x2000000 | nb
%define STDOUT                  1
%define WRITE                   4

section .data
hello:
    .string db "Hello World!", 10
    .len equ $ - hello.string

section .text
    global start
    global _main

start:
    call _main
    ret

_main:
    push rbp
    mov rbp, rsp
    sub rsp, 16
    mov rdi, STDOUT
    lea rsi, [rel hello.string]
    mov rdx, hello.len
    mov rax, MACH_SYSCALL(WRITE)
    syscall
    leave
    ret

; HELLO WORD
; section .data
; hello:
;     .string db "Hello World!", 10
;     .len equ $ - hello.string

; section .text
;     global start
;     global _main
;     extern _printf

; start:
;     call _main
;     ret

; _main:
;     push rbp
;     mov rbp, rsp    ; alignement obligatoire sur Mac
;     sub rsp, 16     ; rsp = registre pour diminuer ou augmenter la stack. Ici on demande 16 octets (non utilisés ici)
;     lea rdi, [rel hello.string]     ; rdi = premier argument => ici charger l'adresse de la string (lea) dans rdi
;     call _printf
;     leave
;     ret

; BASICS
; section .text
;     global start
;     global _main

; start:
;     call _main
;     ret

; _main:
;     ret

; COMPILATION
; ~/.brew/bin/nasm -f macho main.s -o main.o
; ld main.o -macosx_version_min 10.8 -lSystem
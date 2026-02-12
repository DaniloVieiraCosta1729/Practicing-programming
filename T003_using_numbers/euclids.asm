%include "../D_lib/Macros/IO.inc"

section .data
    welcome db 9,9,"Euclids Algorithm",10,10
    size_welcome equ $-welcome

    info01 db "Digit two numbers to see their gcd", 10
    size_info01 equ $-info01

    info02 db "first number >>> "
    size_info02 equ $-info02

    info03 db "second number >>> "
    size_info03 equ $-info03

section .bss
    input01 resw 1
    input01_text resb 16
    size_input01 resb 1

    input02 resw 1
    input02_text resb 16
    size_input02 resb 1

    gcd resw 1
    size_gcd resb 1

section .text
    global _start

_start:
    WRITE welcome, size_welcome
    WRITE info01, size_info01
    WRITE info02, size_info02

.end:
    mov rax, 60
    xor rdi, rdi
    syscall
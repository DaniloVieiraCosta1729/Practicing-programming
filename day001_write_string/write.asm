%include "../D_lib/Macros/IO.inc"

section .data
    text db "Testing", 10
    size equ $-text

section .text
    global _start
_start:
    write text, size

    mov rax, 60
    xor rdi, rdi
    syscall
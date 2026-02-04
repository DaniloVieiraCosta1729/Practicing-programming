%include "../D_lib/Macros/IO.inc"

section .data
    text0 db "Digit something, please: ", 10
    size0 equ $-text0

    text1 db "You said: "
    size1 equ $-text1

section .bss
    input0 resb 50
    input0size resb 1

section .text
    global _start
_start:
    WRITE text0, size0
    READ input0, 50
    mov [input0size], al
    WRITE text1, size1
    WRITE input0, input0size
    NEWLINE

    mov rax, 60
    xor rdi, rdi
    syscall
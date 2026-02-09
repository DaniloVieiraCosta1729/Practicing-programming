%include "../D_lib/Macros/IO.inc"

extern string2integer
extern integer2string

section .data
    info db "Digit a number: "
    sizeInfo equ $-info

    result db "The value informed plus 5 is: "
    sizeResult equ $-result

section .bss
    inputText resb 20
    number resb 20

section .text
    global _start

_start:
    WRITE info, sizeInfo
    READ inputText, 20
    
    mov rsi, rax
    lea rdi, [inputText]
    call string2integer

    add rax, 5

    mov rsi, rax
    mov rdi, number
    mov rdx, 20
    call integer2string

    mov r8, rax

    WRITE result, sizeResult
    WRITE number, r8
    NEWLINE

    mov rax, 60
    xor rdi, rdi
    syscall

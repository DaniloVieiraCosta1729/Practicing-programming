%include "../D_lib/Macros/IO.inc"
%include "../D_lib/Procedures/Parser.inc"
%include "../D_lib/Macros/Math.inc"

section .data
    welcome db 9,9,"Euclids Algorithm",10,10
    size_welcome equ $-welcome

    info01 db "Digit two numbers to see their gcd...", 10
    size_info01 equ $-info01

    info02 db "first number >>> "
    size_info02 equ $-info02

    info03 db "second number >>> "
    size_info03 equ $-info03

    info04 db "The GCD between these number is "
    size_info04 equ $-info04

section .bss
    input01 resd 1
    input01_text resb 16
    size_input01 resb 1

    input02 resd 1
    input02_text resb 16
    size_input02 resb 1

    gcd_actual_result resd 1
    gcd_actual_size resd 1
    gcd_text_result resb 16

section .text
    global _start

_start:
    WRITE welcome, size_welcome
    WRITE info01, size_info01

    NEWLINE

    WRITE info02, size_info02
    READ input01_text, 16
    mov [size_input01], rax
    mov rsi, rax 
    mov rdi, input01_text
    ; string2integer(rdi = buffer, rsi = size of the string)
    ; returns in rax
    call string2integer 
    mov dword [input01], eax

    NEWLINE

    WRITE info03, size_info03
    READ input02_text, 16
    mov [size_input02], rax
    mov rsi, rax 
    mov rdi, input02_text
    ; string2integer(rdi = buffer, rsi = size of the string)
    ; returns in rax
    call string2integer
    mov dword [input02], eax    

    mov rax, qword [input01]
    mov rbx, qword [input02]
    gcd rax, rbx
    mov dword [gcd_actual_result], eax

    mov esi, eax
    mov rdi, gcd_text_result
    mov rdx, 16
    call integer2string
    mov r8, rax 
    mov [gcd_actual_size], r9

    WRITE info04, size_info04
    WRITE gcd_text_result, r8
    NEWLINE
    
.end:
    mov rax, 60
    xor rdi, rdi
    syscall
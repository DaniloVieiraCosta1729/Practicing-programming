%line 1+1 ../D_lib/Macros/IO.inc
[section .data]
 new_line db 10

%line 11+1 ../D_lib/Macros/IO.inc

%line 19+1 ../D_lib/Macros/IO.inc

%line 4+1 ../D_lib/Procedures/Parser.inc
[extern string2integer]
[extern integer2string]

%line 4+1 euclids.asm
[section .data]
 welcome db 9,9,"Euclids Algorithm",10,10
 size_welcome equ $-welcome

 info01 db "Digit two numbers to see their gcd...", 10
 size_info01 equ $-info01

 info02 db "first number >>> "
 size_info02 equ $-info02

 info03 db "second number >>> "
 size_info03 equ $-info03

[section .bss]
 input01 resw 1
 input01_text resb 16
 size_input01 resb 1

 input02 resw 1
 input02_text resb 16
 size_input02 resb 1

 gcd resw 1
 gcd_text resb 16

[section .text]
[global _start]

_start:
%line 5+1 ../D_lib/Macros/IO.inc
 mov rax, 1
 mov rdi, 1
 mov rsi, welcome
 mov rdx, size_welcome
 syscall
%line 5+1 ../D_lib/Macros/IO.inc
 mov rax, 1
 mov rdi, 1
 mov rsi, info01
 mov rdx, size_info01
 syscall
%line 21+1 ../D_lib/Macros/IO.inc
 mov rax, 1
 mov rdi, 1
 mov rsi, new_line
 mov rdx, 1
 syscall
%line 5+1 ../D_lib/Macros/IO.inc
 mov rax, 1
 mov rdi, 1
 mov rsi, info02
 mov rdx, size_info02
 syscall
%line 13+1 ../D_lib/Macros/IO.inc
 mov rax, 0
 mov rdi, 0
 mov rsi, input01_text
 mov rdx, 16
 syscall
%line 40+1 euclids.asm
 mov [size_input01], rax
 mov rsi, rax
 mov rdi, input01_text

 call string2integer

 add [gcd], eax

%line 21+1 ../D_lib/Macros/IO.inc
 mov rax, 1
 mov rdi, 1
 mov rsi, new_line
 mov rdx, 1
 syscall
%line 5+1 ../D_lib/Macros/IO.inc
 mov rax, 1
 mov rdi, 1
 mov rsi, info03
 mov rdx, size_info03
 syscall
%line 13+1 ../D_lib/Macros/IO.inc
 mov rax, 0
 mov rdi, 0
 mov rsi, input02_text
 mov rdx, 16
 syscall
%line 53+1 euclids.asm
 mov [size_input02], rax
 mov rsi, rax
 mov rdi, input02_text


 call string2integer

 add [gcd], eax

 mov esi, [gcd]
 mov rdi, gcd_text
 mov rdx, 16


 call integer2string

 mov r8, rax

%line 5+1 ../D_lib/Macros/IO.inc
 mov rax, 1
 mov rdi, 1
 mov rsi, gcd_text
 mov rdx, r8
 syscall
%line 21+1 ../D_lib/Macros/IO.inc
 mov rax, 1
 mov rdi, 1
 mov rsi, new_line
 mov rdx, 1
 syscall
%line 74+1 euclids.asm
.end:
 mov rax, 60
 xor rdi, rdi
 syscall

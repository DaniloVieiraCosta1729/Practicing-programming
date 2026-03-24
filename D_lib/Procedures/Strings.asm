section .text
    global invertString

; rdi - address of the string
; rsi - size of the string
invertString:
    push rcx
    push r8
    push r9
    push rax

    ; steps number
    mov rax, rsi
    shl rax

    xor rcx, rcx
    .loop01:
        mov r8b, byte [rdi + rcx]
        mov r9b, byte [rdi + rsi]
        mov byte [rdi + rcx], r9b
        mov byte [rdi + rsi], r8b
        dec rax
        inc rcx
        dec rsi
        test rax, rax
        jz .loop01

    pop rax
    pop r9
    pop r8
    pop rcx

    ret

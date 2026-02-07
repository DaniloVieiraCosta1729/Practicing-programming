; This file has a collection of parsers. It should fulfill any parsing need.

section .text
    global string2integer
    global integer2string

; string2integer(rdi, rsi) -> string2integer(string address, size of the string)
; return in rax
string2integer:
    push rcx
    push rdx

    xor rax, rax
    xor rcx, rcx
    dec rsi

    .loop01:
        imul rax, 10
        mov dl, byte [rdi + rcx]
        sub dl, '0'
        add rax, rdx

        inc rcx
        cmp rsi, rcx
        jne .loop01
    
    pop rdx
    pop rcx

    ret

; integer2string(rdi, rsi, rdx) -> integer2string(buffer address, number, buffer size)
; (IGNORE THIS LINE FOR NOW, please) return in rax -> 0 if everything worked fine and -1 if something broke. 
; return in rax -> the address of the resulting string.
integer2string:
    push rcx
    push rbx

    mov cl, '0'
    mov rax, rsi
    mov rbx, 10
    mov r8, rdx

    ; REMENBER -> implement LOG10(x) to improve this function.
    .loop01:
        xor rdx, rdx
        idiv rbx
        add dl, cl
        mov byte [rdi + r8], dl
        cmp r8, 0
        je .end
        cmp rax, 0
        je .end
        dec r8
        jmp .loop01

    .end:
        mov rax, rdi
        add rax, r8
        pop rbx
        pop rcx
        ret
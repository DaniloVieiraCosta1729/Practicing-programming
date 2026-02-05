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

    .loop01:
        mul rax, 10
        mov rdx, [rdi + rcx]
        sub rdx, '0'
        add rax, rdx

        inc rcx
        cmp rsi, rcx
        jle .loop01
    
    pop rdx
    pop rcx

    ret

; integer2string(rdi, rsi, rdx) -> integer2string(buffer address, number, buffer size)
; (IGNORE THIS LINE FOR NOW, please) return in rax -> 0 if everything worked fine and -1 if something broke. 
; return in rax -> the address of the resulting string.
integer2string:
    push rcx
    mov cl, '0'

    ; REMENBER -> implement LOG10(x) to improve this function.
    .loop01:
        

    pop rcx
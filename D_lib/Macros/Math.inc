; Euclids Algorithm
; gcd(%1, %2) "return" in rax
%macro gcd 2
    mov rax, %1
    mov rbx, %2
    %%loop:
        xor rdx, rdx
        idiv rbx
        cmp rdx, 0
        je %%return
        mov rax, rbx
        mov rbx, rdx
        jmp %%loop

    %%return:
        mov rax, rbx
%endmacro
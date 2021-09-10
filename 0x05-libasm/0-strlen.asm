BITS 64
global asm_strlen
section .data

asm_strlen:
        push    rbp
        mov     rbp, rsp
        mov     QWORD [rbp-24], rdi
        mov     DWORD [rbp-4], 0
        jmp     .L2
.L3:
        add     DWORD  [rbp-4], 1
.L2:
        mov     eax, DWORD  [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD  [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE  [rax]
        test    al, al
        jne     .L3
        mov     eax, DWORD  [rbp-4]
        pop     rbp
        ret
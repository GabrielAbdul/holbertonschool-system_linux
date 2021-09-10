BITS 64
global asm_strchr
section .text

asm_strchr:
        push    rbp
        mov     rbp, rsp
        mov     QWORD  [rbp-8], rdi
        mov     eax, esi
        mov     BYTE  [rbp-12], al
        jmp     .L2
.L5:
        mov     rax, QWORD  [rbp-8]
        movzx   eax, BYTE  [rax]
        cmp     BYTE  [rbp-12], al
        jne     .L3
        mov     rax, QWORD  [rbp-8]
        jmp     .L4
.L3:
        add     QWORD  [rbp-8], 1
.L2:
        mov     rax, QWORD  [rbp-8]
        movzx   eax, BYTE  [rax]
        test    al, al
        jne     .L5
        mov     rax, QWORD  [rbp-8]
        movzx   eax, BYTE  [rax]
        cmp     BYTE  [rbp-12], al
        jne     .L6
        mov     rax, QWORD  [rbp-8]
        jmp     .L4
.L6:
        mov     eax, 0
.L4:
        pop     rbp
        ret
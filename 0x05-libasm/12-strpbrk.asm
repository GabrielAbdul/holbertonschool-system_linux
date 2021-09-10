BITS 64
global asm_strpbrk
section .text

asm_strpbrk:
        push    rbp
        mov     rbp, rsp
        mov     QWORD  [rbp-24], rdi
        mov     QWORD  [rbp-32], rsi
        mov     DWORD  [rbp-4], 0
        jmp     .L2
.L7:
        mov     DWORD  [rbp-8], 0
        jmp     .L3
.L6:
        mov     eax, DWORD  [rbp-8]
        movsx   rdx, eax
        mov     rax, QWORD  [rbp-32]
        add     rax, rdx
        movzx   edx, BYTE  [rax]
        mov     eax, DWORD  [rbp-4]
        movsx   rcx, eax
        mov     rax, QWORD  [rbp-24]
        add     rax, rcx
        movzx   eax, BYTE  [rax]
        cmp     dl, al
        jne     .L4
        mov     eax, DWORD  [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD  [rbp-24]
        add     rax, rdx
        jmp     .L5
.L4:
        add     DWORD  [rbp-8], 1
.L3:
        mov     eax, DWORD  [rbp-8]
        movsx   rdx, eax
        mov     rax, QWORD  [rbp-32]
        add     rax, rdx
        movzx   eax, BYTE  [rax]
        test    al, al
        jne     .L6
        add     DWORD  [rbp-4], 1
.L2:
        mov     eax, DWORD  [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD  [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE  [rax]
        test    al, al
        jne     .L7
        mov     eax, 0
.L5:
        pop     rbp
        ret
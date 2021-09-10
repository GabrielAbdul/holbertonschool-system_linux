BITS 64
global asm_memcpy
section .data

asm_memcpy:
        push    rbp
        mov     rbp, rsp
        mov     QWORD  [rbp-24], rdi
        mov     QWORD  [rbp-32], rsi
        mov     DWORD  [rbp-36], edx
        mov     eax, DWORD  [rbp-36]
        movsx   rdx, eax
        mov     rax, QWORD  [rbp-32]
        add     rax, rdx
        cmp     QWORD  [rbp-24], rax
        ja      .L2
        mov     rax, QWORD  [rbp-24]
        cmp     rax, QWORD  [rbp-32]
        jnb     .L3
.L2:
        mov     rax, QWORD  [rbp-24]
        mov     QWORD  [rbp-8], rax
        mov     rax, QWORD  [rbp-32]
        mov     QWORD  [rbp-16], rax
        jmp     .L4
.L5:
        mov     rdx, QWORD  [rbp-16]
        lea     rax, [rdx+1]
        mov     QWORD  [rbp-16], rax
        mov     rax, QWORD  [rbp-8]
        lea     rcx, [rax+1]
        mov     QWORD  [rbp-8], rcx
        movzx   edx, BYTE  [rdx]
        mov     BYTE  [rax], dl
.L4:
        mov     eax, DWORD  [rbp-36]
        lea     edx, [rax-1]
        mov     DWORD  [rbp-36], edx
        test    eax, eax
        jne     .L5
        jmp     .L6
.L3:
        mov     eax, DWORD  [rbp-36]
        cdqe
        lea     rdx, [rax-1]
        mov     rax, QWORD  [rbp-24]
        add     rax, rdx
        mov     QWORD  [rbp-8], rax
        mov     eax, DWORD  [rbp-36]
        cdqe
        lea     rdx, [rax-1]
        mov     rax, QWORD  [rbp-32]
        add     rax, rdx
        mov     QWORD  [rbp-16], rax
        jmp     .L7
.L8:
        mov     rdx, QWORD  [rbp-16]
        lea     rax, [rdx-1]
        mov     QWORD  [rbp-16], rax
        mov     rax, QWORD  [rbp-8]
        lea     rcx, [rax-1]
        mov     QWORD  [rbp-8], rcx
        movzx   edx, BYTE  [rdx]
        mov     BYTE  [rax], dl
.L7:
        mov     eax, DWORD  [rbp-36]
        lea     edx, [rax-1]
        mov     DWORD  [rbp-36], edx
        test    eax, eax
        jne     .L8
.L6:
        mov     rax, QWORD  [rbp-24]
        pop     rbp
        ret
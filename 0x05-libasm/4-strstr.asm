BITS 64
global asm_strstr
section .text

asm_strstr:
        push    rbp
        mov     rbp, rsp
        mov     QWORD  [rbp-24], rdi
        mov     QWORD  [rbp-32], rsi
        mov     rax, QWORD  [rbp-32]
        movzx   eax, BYTE  [rax]
        test    al, al
        jne     .L2
        mov     rax, QWORD  [rbp-24]
        jmp     .L3
.L2:
        mov     rax, QWORD  [rbp-24]
        movzx   eax, BYTE  [rax]
        test    al, al
        jne     .L4
        mov     eax, 0
        jmp     .L3
.L4:
        mov     DWORD  [rbp-12], 0
        jmp     .L5
.L6:
        add     DWORD  [rbp-12], 1
.L5:
        mov     edx, DWORD  [rbp-12]
        mov     rax, QWORD  [rbp-24]
        add     rax, rdx
        movzx   eax, BYTE  [rax]
        test    al, al
        jne     .L6
        mov     DWORD  [rbp-16], 0
        jmp     .L7
.L8:
        add     DWORD  [rbp-16], 1
.L7:
        mov     edx, DWORD  [rbp-16]
        mov     rax, QWORD  [rbp-32]
        add     rax, rdx
        movzx   eax, BYTE  [rax]
        test    al, al
        jne     .L8
        mov     DWORD  [rbp-4], 0
        jmp     .L9
.L15:
        mov     DWORD  [rbp-8], 0
        jmp     .L10
.L14:
        mov     edx, DWORD  [rbp-4]
        mov     rax, QWORD  [rbp-24]
        add     rax, rdx
        movzx   edx, BYTE  [rax]
        mov     ecx, DWORD  [rbp-8]
        mov     rax, QWORD  [rbp-32]
        add     rax, rcx
        movzx   eax, BYTE  [rax]
        cmp     dl, al
        jne     .L16
        add     DWORD  [rbp-4], 1
        mov     eax, DWORD  [rbp-16]
        sub     eax, 1
        cmp     DWORD  [rbp-8], eax
        jne     .L13
        mov     eax, DWORD  [rbp-4]
        sub     eax, DWORD  [rbp-16]
        mov     edx, eax
        mov     rax, QWORD  [rbp-24]
        add     rax, rdx
        jmp     .L3
.L13:
        add     DWORD  [rbp-8], 1
.L10:
        mov     eax, DWORD  [rbp-8]
        cmp     eax, DWORD  [rbp-16]
        jb      .L14
        jmp     .L12
.L16:
        nop
.L12:
        add     DWORD  [rbp-4], 1
.L9:
        mov     eax, DWORD  [rbp-4]
        cmp     eax, DWORD  [rbp-12]
        jb      .L15
        mov     eax, 0
.L3:
        pop     rbp
        ret
BITS 64
global asm_strncmp
section .text

asm_strncmp:
        push    rbp
        mov     rbp, rsp
        mov     QWORD  [rbp-24], rdi
        mov     QWORD  [rbp-32], rsi
        mov     DWORD  [rbp-36], edx
        mov     DWORD  [rbp-4], 0
        jmp     .L2
.L7:
        mov     rax, QWORD  [rbp-24]
        movzx   edx, BYTE  [rax]
        mov     rax, QWORD  [rbp-32]
        movzx   eax, BYTE  [rax]
        cmp     dl, al
        jle     .L3
        mov     eax, 1
        jmp     .L4
.L3:
        mov     rax, QWORD  [rbp-32]
        movzx   edx, BYTE  [rax]
        mov     rax, QWORD  [rbp-24]
        movzx   eax, BYTE  [rax]
        cmp     dl, al
        jle     .L5
        mov     eax, -1
        jmp     .L4
.L5:
        add     QWORD  [rbp-24], 1
        add     QWORD  [rbp-32], 1
        add     DWORD  [rbp-4], 1
.L2:
        mov     rax, QWORD  [rbp-24]
        movzx   eax, BYTE  [rax]
        test    al, al
        je      .L6
        mov     eax, DWORD  [rbp-4]
        cmp     eax, DWORD  [rbp-36]
        jl      .L7
.L6:
        mov     eax, 0
.L4:
        pop     rbp
        ret
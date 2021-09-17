BITS 64
global asm_puti
extern asm_putc
section .text

asm_puti:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 48
        mov     DWORD  [rbp-36], edi
        mov     eax, DWORD  [rbp-36]
        mov     DWORD  [rbp-4], eax
        mov     DWORD  [rbp-8], 0
        mov     DWORD  [rbp-12], 0
        mov     DWORD  [rbp-16], 1
        mov     DWORD  [rbp-20], 0
        mov     DWORD  [rbp-24], 0
        cmp     DWORD  [rbp-36], 0
        je     .L6
        cmp     DWORD  [rbp-36], 0
        jns     .L2
        mov     edi, 45
        call    asm_putc
        neg     DWORD  [rbp-4]
        mov     DWORD  [rbp-8], 1
        jmp     .L3
.L2:
        jmp     .L3
.L9:
        mov     eax, DWORD  [rbp-4]
        mov     DWORD  [rbp-12], eax
        jmp     .L4
.L5:
        mov     eax, DWORD  [rbp-12]
        mov     edx, -858993459
        mul     edx
        mov     eax, edx
        shr     eax, 3
        mov     DWORD  [rbp-12], eax
        mov     edx, DWORD  [rbp-16]
        mov     eax, edx
        sal     eax, 2
        add     eax, edx
        add     eax, eax
        mov     DWORD  [rbp-16], eax
        add     DWORD  [rbp-24], 1
.L4:
        cmp     DWORD  [rbp-12], 9
        ja      .L5
        mov     eax, DWORD  [rbp-24]
        mov     edx, DWORD  [rbp-20]
        sub     edx, eax
        mov     eax, edx
        cmp     eax, 1
        jbe     .L6
        cmp     DWORD  [rbp-20], 0
        je      .L6
        jmp     .L7
.L8:
        mov     edi, 48
        call    asm_putc
        add     DWORD  [rbp-8], 1
        sub     DWORD  [rbp-20], 1
.L7:
        mov     eax, DWORD  [rbp-24]
        mov     edx, DWORD  [rbp-20]
        sub     edx, eax
        mov     eax, edx
        cmp     eax, 1
        ja      .L8
.L6:
        mov     eax, DWORD  [rbp-12]
        add     eax, 48
        mov     edi, eax
        call    asm_putc
        add     DWORD  [rbp-8], 1
        mov     eax, DWORD  [rbp-24]
        mov     DWORD  [rbp-20], eax
        mov     edx, DWORD  [rbp-4]
        mov     eax, DWORD  [rbp-12]
        imul    eax, DWORD  [rbp-16]
        sub     edx, eax
        mov     eax, edx
        mov     DWORD  [rbp-4], eax
        mov     DWORD  [rbp-16], 1
        mov     DWORD  [rbp-24], 0
.L3:
        cmp     DWORD  [rbp-4], 0
        jg      .L9
        mov     eax, DWORD  [rbp-8]
        leave
        ret
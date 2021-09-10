BITS 64
global asm_putc
section .data

extern write
asm_putc:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 16
    mov     eax, edi
    mov     BYTE [rbp-4], al
    lea     rax, [rbp-4]
    mov     edx, 1
    mov     rsi, rax
    mov     edi, 1
    mov     eax, 0
    call    write
    leave
    ret
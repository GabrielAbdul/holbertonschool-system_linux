BITS 64
global asm_puts
section .data

extern write
extern asm_strlen

asm_puts:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 32
    mov     QWORD [rbp-24], rdi
    mov     rax, QWORD  [rbp-24]
    mov     rdi, rax
    call    asm_strlen
    mov     DWORD  [rbp-4], eax
    mov     edx, DWORD  [rbp-4]
    mov     rax, QWORD  [rbp-24]
    mov     rsi, rax
    mov     edi, 1
    mov     eax, 0
    call    write
    mov     eax, DWORD  [rbp-4]
    leave
    ret
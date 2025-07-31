BITS 16
ORG 0x7C00

start:
    mov ah, 0x0E
    mov si, msg

.print_loop:
    lodsb
    cmp al, 0
    je .halt
    int 0x10
    jmp .print_loop

.halt:
    cli
    hlt
    jmp $

msg db "Hello from my OS!", 0

times 510 - ($ - $$) db 0
dw 0xAA55


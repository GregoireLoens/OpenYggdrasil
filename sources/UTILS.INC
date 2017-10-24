print:
        push ax
        push bx

.start:
        lodsb                   ;on load dans al les caractère compris dans ds:si
        cmp al, 0               ;on verifie la fin de la chaîne
        jz .end
        mov ah, 0x0E
        mov bx, 0x07
        int 0x10                ;syscall du bios
        jmp .start              ;on boucle

.end:
        pop bx
        pop ax
        ret


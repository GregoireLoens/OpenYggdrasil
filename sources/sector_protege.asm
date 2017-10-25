%define BASE 	0x100
%define KSIZE 	50

BITS	16
ORG	0x0

jmp start
%include "UTILS.INC"

start:
	mov ax, 0x07C0          ;intialisation of segment
        mov ds, ax              ;ds point to the current data segment
        mov es, ax              ;es extra segment determined by the programmer
        mov ax, 0x8000          ;on set le début de la stack
        mov ss, ax              ;ss simply the stack pointer
        mov sp, 0xf000          ;on set la fin de la stack

	mov [bootdrv], dl	;getting boot unit

	mov si, msgDebut	;loading message
    	call print		;print message (print --> UTILS.INC)


	; charger le noyau depuis le floppy
    	xor ax, ax
    	int 0x13

    	push es
    	mov ax, BASE
    	mov es, ax
    	mov bx, 0
    	mov ah, 2
    	mov al, KSIZE
    	mov ch, 0
    	mov cl, 2
    	mov dh, 0
    	mov dl, [bootdrv]
    	int 0x13
    	pop es

	;;init pointer gdt
	mov ax, gdtend    ; calcule la limite de GDT
    	mov bx, gdt
   	sub ax, bx
    	mov word [gdtptr], ax

    	xor eax, eax      ; calcule l'adresse lineaire de GDT
    	xor ebx, ebx
    	mov ax, ds
    	mov ecx, eax
    	shl ecx, 4
    	mov bx, gdt
    	add ecx, ebx
    	mov dword [gdtptr+2], ecx

	;;Passage en mode protégé
	cli
    	lgdt [gdtptr]    ; charge la gdt
	mov eax, cr0
	or ax, 1
	mov cr0, eax
	jmp next

next:
	;;reinitialise le segment de donnee
	mov ax, 0x10    
    	mov ds, ax
    	mov fs, ax
    	mov gs, ax
    	mov es, ax

	;;reinitialise le segment de pile
    	mov ss, ax
    	mov esp, 0x9F000    

	;; reinitialise le segment de code
    	jmp dword 0x8:0x1000

bootdrv:  db 0
msgDebut: db "loading kernel", 13, 10, 0

;;init de la gdt
gdt:
    db 0, 0, 0, 0, 0, 0, 0, 0
gdt_cs:
    db 0xFF, 0xFF, 0x0, 0x0, 0x0, 10011011b, 11011111b, 0x0
gdt_ds:
    db 0xFF, 0xFF, 0x0, 0x0, 0x0, 10010011b, 11011111b, 0x0
gdtend:
;--------------------------------------------------------------------
gdtptr:
    dw 0  ; limite
    dd 0  ; base
;--------------------------------------------------------------------

;; NOP jusqu'a 510
times 510-($-$$) db 144
dw 0xAA55

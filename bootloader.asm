 org 07c00h ; donde se carga inicialmente el código
 mov ax, cs
 mov ds, ax
 mov es, ax
 call DispStr ; vamos a desplegar una cadena
 jmp $ ; $ indica la dirección de la posición actual
DispStr:
 mov ax, BootMessage
 mov bp, ax ; ES:BP = dirección de la cadena
 mov cx, 16 ; CX = longitud de la cadena
 mov ax, 01301h ; AH = 13, AL = 01h
 mov bx, 000ch ; ROJO/NEGRO
 mov dl, 0
 int 10h
 ret
BootMessage: db "Hola, Bootloader !"
Times 510-($-$$) db 0 ;llenar de ceros para hacerlo exactamente de 512 bytes
 ;$$ indica la primer dirección del segmento actual
dw 0xaa55 ; Firma del MBR en la dirección 0x01FE 
section .data
flda dd 250
fldb dd 1fH
fldc dd 0
D1 db 0
D2 dw 1000
D3 db 110101b
D4 db 12h
D5 db 17o
D6 dd 1A92h
D7 dd 2011
D8 db "A"
D9 db 0, 1, 2, 3
D10 db "H", "O", "L", 'A', 0
D11 db 'hola', 0
D12 times 32 db 16

section .text
	global _start
_start:
 mov ecx, ebx
 sub ecx, 10
 inc ecx
 dec ecx
 mov al, [D4]
 mov eax, [D4]
 mov [D1], ch
 mov al, [D6]
 mov byte [D6], 96
 mov word [D6], 96

pilas segment para stack 'stack' ;el segmento pilas se alinea en un limite de pagina, y se combina con stack
 pila1 db 50 dup('pila1') ;se declara pila1 de 1 byte con 50 repeticiones de pila1
 tope1 equ $ ;se declara una constante, que es el caracter de fin de cadena
 pila2 db 50 dup('pila2') ;se declara pila2 de 1 byte con 50 repeticiones contiguas de pila2
 tope2 equ $ ; se declara una constante
 pilam db 50 dup('pilam') ;se declara pilam de 1 byte con 50 repeticiones contiguas de pilam
 topem equ $ ;se declara una constante
pilas ends ;finaliza el segmento

datos segment para public 'data' ;segmento datos, que se alinea a un limite de oagina, y se combina con otros programas objetos
 almacen1 dw 0 ;se declara almacen1 de tamaño 2 bytes inicializado en 0
 almacen2 dw 0 ;se declara almacen2 de tamaño 2 bytes inicializado en 0
 almacenp dw 0 ;se declara almacenp de tamaño 2 bytes inicializado en 0
 mensaje11 db ' corut 1,1 vez ',10,'$'; se declara un array(mensaje11) con datos de 1 byte
 mensaje12 db ' corut 1,2 vez ',10,'$'; se declara un array(mensaje12) con datos de 1 byte
 mensaje21 db ' corut 2,1 vez ',10,'$'; se declara un array(mensaje21) con datos de 1 byte
 mensaje22 db ' corut 2,2 vez ',13,'$'; se declara un array(mensaje22) con datos de 1 byte
datos ends; finaliza segmento

mtrans macro almacenact, almacendest ;se define la macro mtrans con parametros almacenact y almacendest
 mov almacenact, sp ;mueve el valor del stack pointer (apuntador de pila) a almacenact
 mov sp, almacendest ;mueve el valor de almacendest al sp
endm ;finaliza la declaracion de la macro

minit macro tope, almacen, corut ;se define la macro minit con parametros tope, almacen y corut
 mov sp, offset tope ;mueve al sp el desplazamiento de tope
 pushf ;coloca el valor de las banderas en la pila
 mov bp, sp ;mueve el valor del sp al base pointer(apuntador de base)
 sub bp, 2 ;resta al bp 2(bp-2)
 mov ax, seg codigo ;mueve el valor del segmento codigo, a ax
 mov [bp], ax; mueve el valor de ax, al contenido de bp
 sub bp, 2; resta al bp 2 (bp-2)
 mov ax, offset corut; mueve el valor del desplazamiento de corut, a ax
 mov [bp], ax; mueve el valor de ax, al contenido de bp
 mov sp, bp;mueve el valor del bp al sp
 push ax ;coloca el valor de ax en la pila
 push bx ;coloca el valor de bx en la pila
 push cx ;coloca el valor de cx en la pila
 push dx ;coloca el valor de dx en la pila
 push bp ;coloca el valor de bp en la pila
 push si ;coloca el valor de si(source index) en la pila
 push di  ;coloca el valor de di(destination index) en la pila
 push ds ;coloca el valor de ds(data segment) en la pila
 push es ;coloca el valor de es(extra segment) en la pila
 mov almacen, sp;mueve el valor del sp a almacen
endm ;termina la macro

codigo segment para public 'code';segmento codigo, que se alinea a un limite de pagina, y se combina con otros programas objetos
 main proc far;comienzo del procedimiento main(si es main se incluye el far)
 assume cs:codigo, ds:datos, ss:pilas ;indica que segmentos direccionar en cada registro del segmento
 push ds ;coloca el valor del ds en la pila
 sub ax, ax ;resta a ax el valor de ax
 push ax ;coloca el valor de ax en la pila
 mov ax, seg datos ;mueve el valor del segmento de datos a ax
 mov ds, ax ;mueve el valor de ax a ds
 mov bx, 184h ;int 61h x 4h = 184h , mueve el valor de 184h a bx
 sub ax, ax ;resta a ax el valor de ax
 mov es, ax ;mueve el valor de ax a es
 mov ax, offset monitor ;mueve a ax el desplazamiento de monitor
 mov [es:bx], ax ;
 mov ax, seg codigo; mueve a ax el valor del segmento de codigo a ax 
 add bx, 2 ;agrega 2 a bx
 mov [es:bx], ax
 mov ah, 0h ;Inicializa pilas de corutinas <-esto ya estaba, pero mueve el valor 0h al registro ah(acumulador)
 int 61h ;salva las banderas en la pila, y ejecuta una interrupcion con el valor indicado, o tiene que ver con algo del audio
 mov ah, 01h ;Paso de control del main a corut1
 int 61h ;salva las banderas en la pila, y ejecuta una interrupcion con el valor indicado, o tiene que ver con algo del audio
 ret ;retorna a la subrutina
main endp ;termina el proceso main

monitor proc ;indica el proceso monitor
 push ax ;coloca el valor de ax en la pila
 push bx ;coloca el valor de bx en la pila
 push cx ;coloca el valor de cx en la pila
 push dx ;coloca el valor de dx en la pila
 push bp ;coloca el valor de bp en la pila
 push si ;coloca el valor de si(source index) en la pila
 push di  ;coloca el valor de di(destination index) en la pila
 push ds ;coloca el valor de ds(data segment) en la pila
 push es ;coloca el valor de es(extra segment) en la pila
 cmp ah, 0h ;compara el valor de ah con 0h
 jz inicia ;si es cero, salta hasta la etiqueta inicia
 cmp ah, 1h ;compara el valor de ah con 1h
 jz salta ;si es cero, salta hasta la etiqueta salta
 cmp ah, 02h ;compara el valor de ah con 02h
 jz transfer12 ;si es cero, salta hasta la etiqueta transfer12
 cmp ah, 03h ;compara el valor de ah con 03h
 jz transfer21 ;si es cero, salta hasta la etiqueta transfer21
 inicia: mov almacenp, sp ;etiqueta inicia; mueve el valor de sp a almacen2
  minit tope2, almacen2, corut2 ;se llama a la macro minit
  minit tope1, almacen1, corut1 ;se llama a la macro minit
  mov sp, almacenp ;se mueve el valor de almacenp a sp
 jmp fin ;salta hasta la etiqueta fin
 salta: mov sp, almacen1 ;etiqueta salta, subrutina; mueve el valor de almacen1 a sp
 jmp fin ;salta hasta la etiqueta fin
 transfer12: mtrans almacen1, almacen2 ;etiqueta transfer12; llama a la macro mtrans
 jmp fin ;salta hasta la etiqueta fin
 transfer21: mtrans almacen2, almacen1 ;etiqueta transfer21; llama a la macro mtrans
 fin: ;etiqueta fin
  pop es ;recupera el ultimo dato de la pila y lo coloca en es
  pop ds ;recupera el ultimo dato de la pila y lo coloca en ds
  pop di ;recupera el ultimo dato de la pila y lo coloca en di
  pop si ;recupera el ultimo dato de la pila y lo coloca en si
  pop bp ;recupera el ultimo dato de la pila y lo coloca en bp
  pop dx ;recupera el ultimo dato de la pila y lo coloca en dx
  pop cx ;recupera el ultimo dato de la pila y lo coloca en cx
  pop bx ;recupera el ultimo dato de la pila y lo coloca en bx
  pop ax ;recupera el ultimo dato de la pila y lo coloca en ax
 iret ;retorno de interrupcion, restaura los indicadores de la pila
monitor endp ;fin del proceso monitor

corut1 proc ;proceso carut1
  call imp11 ;llama al proceso imp11
  mov ah, 02h ;mueve el valor 02h a ah
  int 61h ;salva las banderas en la pila, y ejecuta una interrupcion con el valor indicado, o tiene que ver con algo del audio
  call imp12 ;llama al proceso imp12
  mov ah, 02h ;mueve el valor de 02h a ah
  int 61h ;salva las banderas en la pila, y ejecuta una interrupcion con el valor indicado, o tiene que ver con algo del audio
 jmp corut1 ;salta al proceso corut1, se buclea
corut1 endp ;fin del proceso corut1

corut2 proc ;proceso corut2
  call imp21  ;llama al proceso imp21
  mov ah, 03h ;mueve el valor 03h a ah
  int 61h ,salva ;las banderas en la pila, y ejecuta una interrupcion con el valor indicado
  call imp22 ;llama al proceso impl22
  mov ah, 03h ;mueve el valor de 03h a ah
  int 61h ;salva las banderas en la pila, yejecuta una interrupcion con el valor indicado
 jmp corut2 ;salta al proceso corut2,se buclea
corut2 endp ;fin del proceso corut2

imp11 proc ;proceso imp11
 mov ah, 9 ;mueve el valor de 9 a ah
 mov dx, offset mensaje11 ;mueve el valor de desplazamiento de mensaje11 a dx
 int 21h ;salva las banderas en la pila, y ejecuta una interrupcion con el valor indicado
 ret ;retorna  a la subrutina
endp imp11 ;fin proceso imp11

imp12 proc ;proceso imp12
 mov ah, 9 ;mueve el valor de 9 a ah
 mov dx, offset mensaje12 ;mueve el valor de desplazamiento de mensaje12 en dx
 int 21h ;salva las banderas en la pila, y ejecuta una interrupcion con el valor indicado
 ret ;retorna a la subrutina
endp imp12 ;fin proceso imp12

imp21 proc ;proceso imp21
 mov ah, 9 ;mueve el valor de 9 a ah
 mov dx, offset mensaje21 ;mueve el valor de desplazamiento de mensaje21 a dx
 int 21h ;salva las banderas en la pila, y ejecuta una interrupcion con el valor indicado
 ret ;retorna a la subrutina
endp imp21 ;fin proceso imp21

imp22 proc ;proceso imp22
 mov ah, 9 ;mueve el valor de 9 a ah
 mov dx, offset mensaje22 ;mueve el valor de desplazamiento de mensaje22 a dx
 int 21h ;salva las banderas en la pila, y ejecuta una interrupcion con el valor indicado
 ret ;retorna a la subrutina
endp imp22 ;fin proceso imp22
codigo ends ;fin segmento codigo
end main ;fin del main


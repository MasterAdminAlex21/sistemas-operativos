#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
 printf("tamaño de pagina en bytes: %ld",sysconf(_SC_PAGESIZE));
 printf("\nNumero total de paginas: %ld",sysconf(_SC_PHYS_PAGES));
 printf("\nNumero total de paginas disponibles: %ld",sysconf(_SC_AVPHYS_PAGES) );
}
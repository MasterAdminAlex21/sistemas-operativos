#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
 char *cad={"Este es un mensaje de ejemplo"};
 printf("Cadena 1: %s\n",cad);
 char *sub={"xc"};
 printf("cadena a buscar: %s\n",sub);
 char *resul=strstr(cad,sub);
 if(resul!=NULL)
  printf("resultado: %s\n",resul);
 else
  printf("no hay coincidencias\n");
}
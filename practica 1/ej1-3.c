#include<stdio.h>
#include<stdlib.h>

int main(){
 char car=0;
 int ent=0;
 float flot=0;
 long largo=0;
 double doble=0;

 printf("direcciones:\ncaracter: %p\nentero: %p\nflotante: %p\nlong: %p\ndoble: %p\n",&car,&ent,&flot,&largo,&doble);

 printf("tamaños: \ncaracter: %ld\nentero: %ld\nflotante: %ld\nlong: %ld\ndoble: %ld\n",sizeof(char),sizeof(int),sizeof(float),sizeof(long),sizeof(double));
}
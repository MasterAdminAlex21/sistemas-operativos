#include<stdio.h>
#include<stdlib.h>

void ej95_1();
void ej95_7();
void ej95_10();

int main(){
 ej95_1();
 getchar();
 ej95_7();
 getchar();
 ej95_10();
}

void ej95_1(){
 int num;
 printf("Ingrese numero(1-999): ");
 scanf("%d",&num);
 if(num>0 && num<10){
  printf("El numero es de 1 digito\n");
 }else if(num>9 && num<100){
  printf("El numero es de 2 digitos\n");
 }else if(num>99 && num<1000){
  printf("El numero es de 3 digitos\n");
 }
}

void ej95_7(){
 printf("Ingrese 4 numeros enteros (a b c d): ");
 int array[4],mayor=0,menor=999999999;
 scanf("%d %d %d %d",&array[0],&array[1],&array[2],&array[3]);
 for(int i=0;i<4;i++){
  if(array[i]>mayor){
   mayor=array[i];
  }

  if(array[i]<menor){
   menor=array[i];
  }
 }

 printf("Numero mayor: %d\nNumero menor: %d\n",mayor,menor);
}

void ej95_10(){
 printf("Ingrese calificacion: ");
 int grado;
 scanf("%d",&grado);
 int index=grado/10;
 switch(index){
  case 10:
  printf("Grado: A\n");
  break;
  case 9:
  printf("Grado: A\n");
  break;
  case 8:
  printf("Grado: B\n");
  break;
  case 7:
  printf("Grado: C\n");
  break;
  case 6:
  printf("Grado: D\n");
  break;
  default:
  printf("Grado: F\n");
 }
}
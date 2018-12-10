#include<stdio.h>
#include<stdlib.h>

void ej71_1();
void ej71_4();
void ej71_5();

int main(){
 //ej71_1();
 ej71_4();
 ej71_5();
}

void ej71_1(){
 int numero;
 printf("ingresa un numero de 2 digitos: ");
 scanf("%d",&numero);
 printf("el numero al reves: %d%d\n",numero%10,numero/10);
}

void ej71_4(){
 int num,i=0;
 printf("Ingrese numero entre 0 y 32767: ");
 scanf("%d",&num);

 char octal[20];
 while(num!=0){
  int aux=num%8;
  octal[i]=0|aux;
  num/=8;
  i++;
 }
 octal[i]=num;
 for(i;i>-1;i--){
  printf("%d",octal[i]);
 }

}
void ej71_5(){
 
}
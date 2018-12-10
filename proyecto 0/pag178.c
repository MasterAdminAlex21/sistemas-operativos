#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void ej178_1();
void ej178_7();
void ej178_17();

int main(){
 ej178_1();
// ej178_7();
 //ej178_17();
}

void ej178_1(){//repdigit.c
 bool digit_seen[10]={false};
 int digit,i=0;
 long n;
 int array[10];

 printf("Ingrese numero: ");
 scanf("%ld",&n);
 while(n>0){
  digit=n%10;
  if(digit_seen[digit]==true){
   //break;
   array[i]=digit;
   i+=1;
  }
  digit_seen[digit]=true;
  n/=10;
 }
 printf("numeros repetidos: ");
 while(i>0){
  printf("%d ",array[i-1] );
  i-=1;
 }
 printf("\n");
}

void ej178_7(){
 int array[5][5];
 for(int i=0;i<5;i++){
  printf("Ingrese numeros (x x x x x): ");
  scanf("%d %d %d %d %d",&array[i][0],&array[i][1],&array[i][2],&array[i][3],&array[i][4]);
 }

 printf("Suma de filas: ");
 for(int i=0;i<5;i++){
  printf("%d ",array[i][0]+array[i][1]+array[i][2]+array[i][3]+array[i][4]);
 }

 printf("\nSuma de columnas: ");
 for(int i=0;i<5;i++){
  printf("%d ",array[0][i]+array[1][i]+array[2][i]+array[3][i]+array[4][i]);
 }
 printf("\n");

}

void ej178_17(){

}
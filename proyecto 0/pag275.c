#include<stdio.h>
#include<stdlib.h>

void ej275_1();
void ej275_6();
void ej275_7();

int main(){

 //ej275_1();
 //ej275_6();
 ej275_7();
}

void ej275_1(){
 printf("Ingrese mensaje: ");
 char msg[100];
 int i=0;
 char c;
 while((c=getchar())!='\n'){
  msg[i]=c;
  i+=1;
 }
 printf("Mensaje al reves: ");
 while(i>-1){
  printf("%c",msg[i] );
  i-=1;
 }
 printf("\n");
}

void ej275_6(){

}

void ej275_7(){


}

#include<stdio.h>
#include<stdlib.h>

void ej34_1();
void ej34_2();
void ej34_3();

int main(){
 ej34_1();
 ej34_2();
 ej34_3();
}

void ej34_1(){
 printf("ejercicio 34-1");
 printf("\n        *\n       *\n      *\n *   *\n  * * \n   *\n"); 
}

void ej34_2(){
 int radius=10;//radio de la esfera
 float pi=3.1416;//valor estandar de pi
 double v=(4.0f/3.0f)*pi*(radius*radius*radius);//volumen; nota: al hacer divisiones, colocar el f de float al final
 printf("volumen de una esfera de radio de 10 metros: %lf\n",v);//imprime el valor de v
}

void ej34_3(){
 int monto=0,m1=0,m2=0,m3=0,m4=0;//m1=20,m2=10,m3=5,m4=1 , los montos
 printf("Ingrese monto: \n");
 scanf("%d",&monto);
 //es el problema del cambio, con montos de 20, 10, 5 y 1
 while(monto!=0){
  if(monto/20!=0){
   m1=monto/20;
   monto-=(m1*20);
  }
  if(monto/10!=0){
   m2=monto/10;
   monto-=(m2*10);
  }
  if(monto/5!=0){
   m3=monto/5;
   monto-=m3*5;
  }
  if(monto/1!=0){
   m4=monto/1;
   monto-=(m4*1);
  }
 }

 printf("cantidades:\n$20: %d\n$10: %d\n$5: %d\n$1: %d\n",m1,m2,m3,m4);

}
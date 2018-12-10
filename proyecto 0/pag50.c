#include<stdio.h>
#include<stdlib.h>

void ej50_1();
void ej50_4();
void ej50_6();

int main(){
 //ej50_1();
 //ej50_4();
 ej50_6();
}

void ej50_1(){
 int d,m,a;//dia,mes,año
 printf("ingrese fecha[mm/dd/aaaa]: ");
 scanf("%d/%d/%d",&m,&d,&a);
 if(d<=31 && d>0 && m<=12 &&m>0){
  if(m<10 && d<10){
   printf("fecha ingresada: %d0%d0%d\n",a,m,d);
  }else if(m<10 && d>10){
   printf("fecha ingresada: %d0%d%d\n",a,m,d);
  }else if(d<10 && m>10){
   printf("fecha ingresada: %d%d0%d\n",a,m,d);
  }else{
   printf("fecha ingresada: %d%d%d\n",a,m,d);
  }
 }else{
  printf("ERROR: fecha incorrecta\n");
 }
}

void ej50_4(){//terminar de programar
 int lada,num1,num2;
 getchar();
 printf("ingrese numero de telefono[(xxx) xxxx-xxxx]: ");
 scanf("(%d) %d-%d",&lada,&num1,&num2);
 if(lada>0 && lada<1000 && num1>-1 && num1<10000 && num2>-1 && num2<10000){
  printf("numero ingresado: %d.%d.%d\n",lada,num1,num2);
 }

}

void ej50_6(){//suma de fracciones
 int num1,den1,num2,den2,numres,denres;
 printf("Ingrese fracciones a sumar separado por el signo '+' [a/b+c/d]: ");
 scanf("%d/%d+%d/%d",&num1,&den1,&num2,&den2);
 numres=(num1*den2)+(den1*num2);
 denres=den1*den2;
 printf("Resultado: %d/%d \n",numres,denres);
}

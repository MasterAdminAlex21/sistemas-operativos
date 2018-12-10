#include<stdio.h>
#include<stdlib.h>

void ej122_1();
void ej122_8();
void ej122_11();

int main(){
 //ej122_1();
//ej122_8();
 ej122_11();
}

void ej122_1(){
 double array[100];
 int index=0;
 double dato=1;

 while((dato!=0 && dato>0) && (index<100)){
  printf("Escribe el numero: ");
  scanf("%lf",&dato);
  array[index]=dato;
  index+=1;
 }

 double max=0;
 for(int i=0;i<=index;i++){
  if(max<array[i]){
   max=array[i];
  }
 }
 printf("El numero mayor: %0.3lf\n",max );
}

void ej122_8(){
 printf("Ingrese numero de dias: ");
 int dias,inicio;
 scanf("%d",&dias);
 printf("Ingrese dia de inicio (Dom=1, Sab=7): ");
 scanf("%d",&inicio);
 switch(inicio){
  case 1:
   for(int i=0;i<dias;i++){
    printf("%d\t",i+1);
    if((i+1)%7==0){
     printf("\n");
    }
   }
  break;
  case 2:
   printf("\t");
   for(int i=0;i<dias;i++){
    printf("%d\t",i+1);
    if((i+2)%7==0){
     printf("\n");
    }
   }
  break;
  case 3:
  printf("\t\t");
   for(int i=0;i<dias;i++){
    printf("%d\t",i+1);
    if((i+3)%7==0){
     printf("\n");
    }
   }
  break;
  case 4:
  printf("\t\t\t");
   for(int i=0;i<dias;i++){
    printf("%d\t",i+1);
    if((i+4)%7==0){
     printf("\n");
    }
   }
  break;
  case 5:
  printf("\t\t\t\t");
   for(int i=0;i<dias;i++){
    printf("%d\t",i+1);
    if((i+5)%7==0){
     printf("\n");
    }
   }
  break;
  case 6:
  printf("\t\t\t\t\t");
   for(int i=0;i<dias;i++){
    printf("%d\t",i+1);
    if((i+6)%7==0){
     printf("\n");
    }
   }
  break;
  case 7:
  printf("\t\t\t\t\t\t");
   for(int i=0;i<dias;i++){
    printf("%d\t",i+1);
    if((i+7)%7==0){
     printf("\n");
    }
   }
  break;
 }
 printf("\n");
}

void ej122_11(){
 int d[100],m[100],a[100],index=0,d1=1,m1=1,a1=1;
 while(index<100 || (d1!=0 && m1!=0 && a1!=0)){
  printf("Ingrese fecha(dd/mm/aa): ");
  scanf("%d/%d/%d",&d1,&m1,&a1);
  if(d1==0 && m1==0 && a1==0) break;
  else{
   d[index]=d1;
   m[index]=m1;
   a[index]=a1;
   index+=1;
  }
 }
 d1=m1=a1=9999;
 for(int i=0;i<index;i++){
  if(a[i]<a1){
   a1=a[i];
   m1=m[i];
   d1=d[i];
  }else if(a[i]==a1){
   if(m[i]<m1){
    a1=a[i];
    m1=m[i];
    d1=d[i];
   }else if(m[i]==m1){
    if(d[i]<d1){
     a1=a[i];
     m1=m[i];
     d1=d[i];
    }else if(d[i]==d1){
     a1=a[i];
     m1=m[i];
     d1=d[i];
    }
   }
  }
 }
 printf("Fecha mas antigua: %d/%d/%d\n",d1,m1,a1 );
}
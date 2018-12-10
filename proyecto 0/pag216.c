#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void ej216_1();
void ej216_6();
void selection_sort(int *, int);

int main(){
 ej216_1();
 //ej216_6();
}

void ej216_1(){//ordenamiento
 int array[100];
 int n,n2;
 printf("Ingrese cantidad de numeros: ");
 scanf("%d",&n);
 n2=n;
 while(n>0){
  printf("ingrese numero: ");
  scanf("%d",&array[n-1]);
  n-=1;
 }
 n=0;
 selection_sort(&array,n2-1);
 printf("Array: ");
 while(n<n2){
  printf("|%d|",array[n] );
  n+=1;
 }
 printf("\n");
}

void selection_sort(int *array, int pos){
 if(pos==0){
 }else{
  int n1=0,n2,i,x;
  for(i=pos;i>-1;i--){
   if(array[i]>=n1){
    n1=array[i];
    x=i;
   }
  }
  n2=array[pos];
  array[pos]=n1;
  array[x]=n2;
  selection_sort(array,pos-1);
 }
}


void ej216_6(){
 int x;
 printf("la expresion a evaluar es: 3x^5+2x^4-5x^3-x^2+7x-6\n");
 printf("Ingrese valor de x: ");
 scanf("%d",&x);
 double valor=(3*pow(x,5))+(2*pow(x,4))-(5*pow(x,3))-pow(x,2)+(7*x)-6;
 printf("Resultado: %0.0f\n",valor);

}

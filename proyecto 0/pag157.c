#include<stdio.h>
#include<stdlib.h>

void ej157_1();
void ej157_6();
void ej157_15();

int main(){
 ej157_1();
// ej157_6();
// ej157_15();
}

void ej157_1(){
 //int i,n;
 short i;
 short n;
 printf("Imprime una tabla de cuadrados\n");
 printf("Ingresa numero de entradas en la tabla: ");
 scanf("%hd",&n);

 for(i=1;i<=n;i++){
  printf("%10hd%10hd\n",i,i*i );
 }

 //numero minimo para que falle con enteros: 46341
 //para short, en 32677 entra en un bucle con el printf %d
 //para el short, en 182 falla
}

void ej157_6(){
 printf("size of:\nint: %d\nshort: %d\nlong: %d\nfloat: %d\ndouble: %d\nlong double: %d\n",sizeof(int),sizeof(short),sizeof(long),sizeof(float),sizeof(double),sizeof(long double));
}

void ej157_15(){
 printf("Ingrese numero para obtener factorial: ");
 int num,aux;
 scanf("%d",&num);
 for(aux=num-1;aux>0;aux--){
  if(aux==0) break;
  num*=aux;
 }
 printf("Factorial: %d\n",num);
}
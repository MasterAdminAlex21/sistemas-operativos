#include<stdio.h>
#include<stdlib.h>

void ej311_1();
void ej311_5();
void ej311_18();

int main(int argc,char *argv[]){

 printf("%d\n",atoi(argv[1])+atoi(argv[2])+atoi(argv[3]) );
}

void ej311_1(){
 
}

void ej311_5(int argc,char *argv[]){//cambiarle a int main
// printf("%d\n",argv[1]+argv[2]+argv[3] );

}

void ej311_18(){
 char *mes[]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
 printf("Ingrese fecha (dd/mm/aaaa): ");
 int d,m,a;
 scanf("%d/%d/%d",&d,&m,&a);

 printf("la fecha ingresada es: %s %d, %d\n",mes[m-1],d,a );
}
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <math.h>
long double resul=0;

int main(int argc, char *argv[]){
 if(argc!=2){
  printf("uso: %s delta_x\n",argv[0]);
  exit(0);
 }
 char *aux;
 //printf("%s\n",argv[1] );
 long double delta,y;
 delta=strtold(argv[1],NULL);
 pid_t hijo;
 unsigned long num=1/delta;//n rectangulos
 //int n=(int)num;
 printf("delta: %.16Lf\ntotal de rectangulos: %ld\n",delta,num );

 //tengo 2 nucleos
 hijo=fork();
 if(hijo==0){
  printf("Es el hijo\n");
  //saca el area de 1/2 circulo
  for(double long i=1;i<num;i+=2){
  //toca  sacar el area de los rectangulitos
  y=sqrtl(1-powl((long double)i/(long double)(num*2),2))*delta;
  //printf("%0.10Lf\n",y );
  resul+=y;
 }
 }else{
  wait(hijo);
  printf("es el padre\n");
  for(double long i=num;i<num*2;i+=2){
  //toca  sacar el area de los rectangulitos
  y=sqrtl(1-powl((long double)i/(long double)(num*2),2))*delta;
  //printf("%0.10Lf\n",y );
  resul+=y;
 }
 }
 printf("area: %.16Lf\n",resul );

}
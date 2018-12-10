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
 printf("delta: %.10Lf\ntotal de rectangulos: %ld\n",delta,num );

 for(double long i=1;i<num*2;i+=2){
  //toca  sacar el area de los rectangulitos
  y=sqrtl(1-powl((long double)i/(long double)(num*2),2))*delta;
  //printf("%.10lff\n",y );
  resul+=y;
 }

 printf("area: %.16Lf\n",resul );




}
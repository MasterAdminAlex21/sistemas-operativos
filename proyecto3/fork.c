#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
 pid_t pid;
 int val=10;
 pid=fork();
 if(pid!=0){
  val=3;
  printf("Texto del padre\n");
  printf("valor: %d\n",val);
  val-=5;
  printf("valor otra vez: %d\n",val);
  exit(0);
 }else{
  printf("Texto del proceso hijo\n");
  printf("valor: %d\n",val );
  val+=5;
  printf("valor otra vez: %d\n",val );
 }
}
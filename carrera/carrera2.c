#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[]){
 if(argc!=2){
  printf("uso: %s num_incrementos\n",argv[0] );
  exit(0);
 }
 if(atoi(argv[1])<0){
  printf("el numero debe ser mayor a 0\n");
 }
 int *valor,*turno;
 int n=atoi(argv[1]),shmid;
 printf("iteraciones: %d\n",n);
 key_t llave;
 llave=ftok(argv[0],'K');
 if((shmid = shmget(llave, sizeof(int), IPC_CREAT | 0600)) == -1){
  perror("Error en shmget");
  exit(-1);
 }
 //Nos atamos a la memoria compartida 
 if((valor = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)){
  perror("Fallo shmat");
  exit(-1);
 }
 if((turno = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)){
  perror("Fallo shmat");
  exit(-1);
 }
 printf("valor inicial: %d\n",*valor );

 pid_t hijo;
 hijo=fork();
 if(hijo==0){
  //aqui la entrada del hijo a la memoria
  while(1){
   for(int i=0;i<n;i++){
    while(*turno!=0);
    *valor-=1;
    *turno=1;
   }
   break;
  }
 }else{
  //aqui la entrada del padre a la memoria
  while(1){
   for(int i=0;i<n;i++){
    while(*turno!=1);
    *valor+=1;
    *turno=0;
   }
   break;
  }
  wait(hijo);
 printf("valor final: %d\n",*valor );
 }
 
}
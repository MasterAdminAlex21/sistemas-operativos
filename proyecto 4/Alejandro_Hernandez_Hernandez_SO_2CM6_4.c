#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>

int main(int argc, char* argv[]){
 srand(time(NULL));
 int semid;
 struct sembuf op;
 key_t llave;


 semctl(semid, 0, IPC_RMID, 0);

 llave=ftok(argv[0],'U');

 if((semid=semget(llave,5,IPC_CREAT | 0600))==-1){
  perror("Error al ejecutar semget\n");
  exit(-1);
 }//creamos una memoria compartida

 int *tiempo,*conec,shmid;
 if((shmid=shmget(llave,sizeof(int),IPC_CREAT | 0600))==-1){
  perror("Error en shmget\n");
  exit(-1);
 }
 if((tiempo=(int*)shmat(shmid,NULL,0))==(int*)(-1)){
  perror("Fallo en shmat\n");
  exit(-1);
 }
 if((conec=(int*)shmat(shmid,NULL,0))==(int*)(-1)){
  perror("Fallo en shmat\n");
  exit(-1);
 }
  if(*conec>=5){
  *conec=0;
  }
 *conec=*conec+1;
 int pos=*conec-1;

 if(pos==0 || pos==2){
  semctl(semid,pos,SETVAL,1);
 }else{
  semctl(semid,pos,SETVAL,0);
 }
 printf("paso las funciones de compartir y esas cosas \n %d conectados\n",*conec );

 while(*conec<5){
  printf("%d conectados \nposicion: %d \n",*conec,pos);
  system("clear");
 }

 conec=0;
 tiempo=rand()%8;

 //aqui la logica para los filosofos
 printf("entro antes del while\n");

 while(1){
      system("clear");
      printf("Hambriento\n");
      op.sem_flg=0;
      op.sem_op=-1;
      op.sem_num=pos;
      semop(semid,&op,1);

      system("clear");
      printf("Comiendo\n");

      sleep(tiempo);
      tiempo=rand()%7 +1;

      op.sem_op=1;
      op.sem_num=(pos+2)%5;
      semop(semid,&op,1);

      system("clear");
      printf("pensando\n" );
      sleep(tiempo);
 }
}
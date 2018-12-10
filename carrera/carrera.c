#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[]){
 if(argc !=2){
  printf("Uso: %s num_incrementos\n", argv[0]);
  exit(0);
 }
 if(atoi(argv[1])<0){
  printf("num_incrementos debe ser mayor a 1\n");
  exit(0);
 }
 int *var,shmid;
 key_t llave;
 llave=ftok(argv[0],'K');
 if((shmid = shmget(llave, sizeof(int), IPC_CREAT | 0600)) == -1)
   {
      perror("Error en shmget");
      exit(-1);
   }
  //Nos atamos a la memoria compartida 
 if((var = (int *)shmat(shmid, NULL, 0)) == (int *)(-1))
   {
      perror("Fallo shmat");
      exit(-1);
   }

   printf("Creo la variable a compartir\n");
   //var=0;
   printf("valor de var: %d\n",*var );
   //creamos el hijo
   pid_t hijo;
   hijo=fork();
   if(hijo==0){
    for(int i=0;i<atoi(argv[1]);i++){
     *var-=1;
     //printf("hijo: %d\n",*var );
    }
    exit(0);
   }
   else{
    for(int i=0;i<atoi(argv[1]);i++){
     *var+=1;
     //printf("padre: %d\n",*var);
    }
    wait(hij)o;
    printf("valor final de la variable compartida: %d\n", *var);
    shmctl(shmid, IPC_RMID, 0);
   }
}
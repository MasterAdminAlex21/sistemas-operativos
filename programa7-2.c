/* Programa para ilustrar el uso de semáforos */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMAFORO_1 0
#define SEMAFORO_2 1
#define SEMAFORO_3 2


int main(int argc, char *argv[])
{
   int semid, pid, j = 10, i;
   struct sembuf operacion;
   key_t llave;		

   llave = ftok(argv[0], 'U');

   
   if((semid = semget(llave, 5, IPC_CREAT | 0600)) == -1)
   {
      perror("Error al ejecutar semget");
      exit(-1);
   }
   semctl(semid, SEMAFORO_1, SETVAL, 1);
   semctl(semid, SEMAFORO_2, SETVAL, 0);
   semctl(semid, SEMAFORO_3, SETVAL, 0);

   for(i=0;i<3;i++){
		pid = fork();
		if(pid==0)
			break;
	}
   
   switch(i){

		case 0:
			while(j){
					/* Se realiza la operación DOWN en el semáforo del proceso hijo */
        				operacion.sem_flg = 0;
         				operacion.sem_op = -1;
         				operacion.sem_num = SEMAFORO_2 ;
         				semop(semid, &operacion, 1);

   				
         				printf("SOY EL PROCESO 1 IMPRESION: %d\n", j--);
         
         				/* Se realiza la operación UP en el semáforo del proceso padre */
        				operacion.sem_op = 1;
         				operacion.sem_num = SEMAFORO_1;
         				semop(semid, &operacion, 1);
      				}
      
      				/* Borramos el semáforo */
      				semctl(semid, 0, IPC_RMID, 0);
   
   
      		case 1: 
			while(j){
					/* Se realiza la operación DOWN en el semáforo del proceso hijo */
        				
					operacion.sem_flg = 0;
         				operacion.sem_op = -1;
         				
         				operacion.sem_num = SEMAFORO_3 ;
         				semop(semid, &operacion, 1);

         				printf("SOY EL PROCESO 2 IMPRESION: %d\n", j--);
         
         				/* Se realiza la operación UP en el semáforo del proceso padre */
        				operacion.sem_op = 1;
         				operacion.sem_num = SEMAFORO_2;
         				semop(semid, &operacion, 1);
      				}
      
      				/* Borramos el semáforo */
      				semctl(semid, 0, IPC_RMID, 0);
		case 2: 
			while(j){
					/* Se realiza la operación DOWN en el semáforo del proceso hijo */
        				operacion.sem_flg = 0;
         				operacion.sem_op = -1;
         				operacion.sem_num = SEMAFORO_1 ;
         				
         				semop(semid, &operacion, 1);
					
         				printf("SOY EL PROCESO 3 IMPRESION: %d\n", j--);
         
         				/* Se realiza la operación UP en el semáforo del proceso padre */
        				operacion.sem_op = 1;
         				operacion.sem_num = SEMAFORO_3;
         				semop(semid, &operacion, 1);
      				}
      
      				/* Borramos el semáforo */
      				semctl(semid, 0, IPC_RMID, 0);
   }
}


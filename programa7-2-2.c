/* Programa para ilustrar el uso de semáforos */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMAFORO_PADRE 2
#define SEMAFORO_HIJO 1
#define SEMAFORO_HIJO2 0

int main(int argc, char *argv[])
{
   int semid, pid, j = 10;
   struct sembuf operacion;
   key_t llave;

   llave = ftok("gabo", 'U');
   if((semid = semget(llave, 2, IPC_CREAT | 0600)) == -1)
   {
      perror("Error al ejecutar semget");
      exit(-1);
   }
   //semctl(semid, SEMAFORO_HIJO , SETVAL, 0);
   semctl(semid, SEMAFORO_PADRE, SETVAL, 1);

    /* Código correspondiente al proceso padre */
    while(j)
    {
       /* Se realiza la operación DOWN en el semáforo del proceso hijo */
       operacion.sem_flg = 0;
       operacion.sem_op = -1;
       operacion.sem_num = SEMAFORO_PADRE ;
       semop(semid, &operacion, 1);
       sleep(2);
       printf("SOY EL PROCESO PADRE IMPRESION: %d\n", j--);

       /* Se realiza la operación UP en el semáforo del proceso padre */
       operacion.sem_op = 1;
       operacion.sem_num = SEMAFORO_HIJO;
       semop(semid, &operacion, 1);
    }

    /* Borramos el semáforo */
    semctl(semid, 0, IPC_RMID, 0);
}

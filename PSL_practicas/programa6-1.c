#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
   int shmid, *variable;
   //
   //char pila[10]={'a','b','c','d','e','f','g','h','i','j'};
   char **pila[10];
   int i=0;
   //
   key_t llave;
   llave = ftok(argv[0], 'K');
   if((shmid = shmget(llave, sizeof(char), IPC_CREAT | 0600)) == -1)
   {
      perror("Error en shmget");
      exit(-1);
   }
   /* Nos atamos a la memoria compartida 
   if((variable = (int *)shmat(shmid, NULL, 0)) == (int *)(-1))
   {
      perror("Fallo shmat");
      exit(-1);
   }*/
   if((*pila=shmat(shmid,NULL,0))==(int *)(-1)){
      perror("Fallo shmat");
      exit(-1);
   }
   //pila=(char*)malloc(10*sizeof(char));
   while(1)
   {
      printf("\nIntroduzca i para ingresar un valor a la pila, s para sacar el valor de la pila, v para visualizarla y t para terminar:\n ");
      switch(leer_car()) {
      case 't':
         /* Libera la memoria compartida */
         shmctl(shmid, IPC_RMID, 0);
         exit(0);
      case 'v':
         /* Visualiza la variable */
         printf("pila = {%s}\n", pila);
         break;
      case 'i':
        if(i==9)
         printf("la pila esta llena\n");
        else{
         getchar();
         printf("Nuevo valor de la pila en memoria compartida: \n");
         scanf("%c", &pila[i]);
         i+=1;
         }
         break;
      case 's':
         if(i==0)
            printf("pila vacia\n");
         else{
               printf("valor sacado: %c\n",&pila[i] );
               pila[i]='\0';
               i-=1;
               }
      break;
      default:
         printf("Se introdujo una letra incorrecta\n");
         break;
      }
   }
}

int leer_car()
{
   char letra;
   char almacen[80];
   
   scanf("%s", &almacen);
   sscanf(almacen, "%c", &letra);
   return letra;                         
}


#include <stdio.h>
#include <signal.h>

void tratar_alarma(int signal)
{
   if(signal==18){
      printf("me han intentado detener\n");
   }
   printf("Alarma activada %d\n",signal);
}

int main(void)
{
   struct sigaction act;
   sigset_t mask;
   
   /* especifica el manejador */
   act.sa_handler = (void *)tratar_alarma; /*funcion a ejecutar */
   act.sa_flags = 0; /* Ninguna accion especifica */
   
   /* Se bloquea la señal 3 SIGQUIT */
   sigemptyset(&mask);
   sigaddset(&mask, SIGQUIT);
   sigaddset(&mask,SIGTSTP);
   sigprocmask(SIG_SETMASK, &mask, NULL);
   sigaction(SIGALRM, &act, NULL);
   for(;;)
   {
      printf("Entra al for y activa la alarma\n");
      ualarm(500000,0); /* se arma el temporizador */
      printf("termina la alarma y viene el pause\n");
      pause(); /* se suspende el proceso hasta que se reciba la señal */
      printf("termina el pause para regresar al for\n");
   }
}


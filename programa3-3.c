#include <stdlib.h>
#include <stdio.h>
extern char **environ;
int main(int argc, char *argv[])
{
   int j;
   /*printf("Las variables de entorno para %s son\n", argv[0]);
   for(j=0; environ[j] != NULL; j++)
      printf("environ[%d] = %s\n", j, environ[j]);
     */
      printf("HOME es %s\n",getenv("HOME"));
      printf("PATH es %s\n",getenv("PATH"));
      /*printf("TERM es %s\n",getenv("TERM"));
      printf("LOGNAME es %s\n",getenv("LOGNAME"));
      printf("PWD es %s\n",getenv("PWD"));
   */return 0;
}


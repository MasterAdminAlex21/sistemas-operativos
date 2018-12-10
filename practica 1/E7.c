#include <stdio.h>
#include <stdlib.h>

int main()
{
   char cadena[]= "ESCOM - IPN";
   int i;
   for(i=0;i<12; i++)
   {
        if(cadena[i]!='\0')
        printf("\n%p", &cadena[i]);
   }
   printf("\n");
}


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
   int tokens;
   for(tokens = 0;; tokens++) {
    if(argv[tokens]==NULL)
     break;
      if(argv[tokens][0] == '-')
         printf("opción: %s\n", argv[tokens]+1);
      else
         printf("argumento %d: %s tamaño: %ld\n", tokens, argv[tokens],strlen(argv[tokens]));
    }
    exit(0);
}


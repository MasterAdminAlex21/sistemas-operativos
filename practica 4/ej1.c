#include <stdio.h>
int main(void)
{
 unsigned char var = 42;
 unsigned int contador, inicio = 128; // 2^(8-1) = 128
 printf("En decimal el valor %d equivale en binario a:\n", var);
 for(contador = inicio; contador > 0; contador >>= 1)
 if(contador & var)
 printf("1");
 else
 printf("0");
 printf("\n");
 return 0;
}
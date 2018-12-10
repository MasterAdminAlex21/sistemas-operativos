#include <stdio.h>
#include <stdlib.h>

int main()
{
    char caracter= 0, *pcaracter;
    int entero=0, *pentero;
    float flotante=0, *pflotante;
    long largo=0, *plargo;
    double doble=0, *pdoble;
    pdoble=&doble;
    printf("%p\n", *pdoble);
}

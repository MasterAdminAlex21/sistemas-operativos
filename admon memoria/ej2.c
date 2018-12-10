#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
int main(){
 pid_t id=getpid();
 printf("Este es el ejercicio 2, y su pid es: %d\n",id);
 /*printf("Ahora, se muestra el contenido de /proc/[pid]:\n\n");
 char *comando;
 char *entero;
 comando=(char*)calloc(21,sizeof(char));
 entero=(char*)calloc(5,sizeof(char));
 sprintf(entero,"%d",id);
 memcpy(comando,"cat /proc/",10);
 printf("copio la wea esa\n");
 strncat(comando,entero,5);
 strncat(comando,"/statm",6);
 printf("lo concateno\n");
 printf("%s",comando);
 */pause();
 //system(comando);
}
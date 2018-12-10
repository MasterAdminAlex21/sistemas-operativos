//ahora lo intentare con fork, aber si no se mere mi compu :'v

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "colores.h"

void busca(char *direc, char *cade);

int main(int argc, char *argv[]){
 if(argc!=3){
  printf(MAGENTA"uso: %s <ruta> <cadena>\n"DEFAULT,argv[0]);
  exit(0);
 }
 printf("\n\n");
 
 busca(argv[1],argv[2]);

 sleep(1);

 printf("\n\n");
}

void busca(char *direc,char *cade){
 DIR *dire;
 struct dirent *ent;
 dire=opendir(direc);
 if(dire==NULL){
  printf(MAGENTA"ERROR AL ABRIR EL DIRECTORIO\n"DEFAULT);
  exit(0);
 }

 char *cad=cade,*eq,*ruta;
 while((ent=readdir(dire))!=NULL){
  if((strcmp(ent->d_name,".") && strcmp(ent->d_name,".."))!=0){
   if((eq=strstr(ent->d_name,cad))!=NULL){
    if(ent->d_type==4){
     printf(BACKGREEN B_GRAY"CARPETA: "BACKDEFAULT DEFAULT);
    }else if(ent->d_type==8){
     printf(BACKCREAM B_GRAY"ARCHIVO: "BACKDEFAULT DEFAULT);
    }
    printf(BACKSKY WHITE"%s"BACKDEFAULT DEFAULT,ent->d_name);
    printf("\n");
   }
   //aqui va lo del fork
   if(ent->d_type==4){
    pid_t pid=fork();
    if(pid==0){
     ruta=(char*)calloc(200,sizeof(char));
     strcat(ruta,direc);
     strcat(ruta,"/");
     strcat(ruta,ent->d_name);
     busca(ruta,cade);
     exit(0);
    }
   }
  }
 }//fin while
}
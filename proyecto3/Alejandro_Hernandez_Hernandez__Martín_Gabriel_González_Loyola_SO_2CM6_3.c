#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

//colores para texto

#define WHITE "\e[37m"
#define RED "\e[31m"
#define B_RED "\e[30m"
#define GREEN "\e[30m"
#define B_GREEN "\e[31m"
#define YELLOW "\e[33m"
#define B_YELLOW "\e[33;1m"
#define BLUE "\e[34m"
#define B_BLUE "\e[34;1m"
#define MAGENTA "\e[35m"
#define CYAN "\e[36m"
#define BRIGHT "\e[1m"
#define DEFAULT "\e[39m"

#define GRAY "\e[37m"
#define B_GRAY "\e[90m"
#define PASTELY "\e[97m"
#define EMERALD "\e[96m"

//fondos

#define BACKBLUE "\e[40m"
#define BACKGREEN "\e[41m"
#define BACKYELLOW "\e[42m"
#define BACKORANGE "\e[43m"
#define BACKSKY "\e[44m"
#define BACKPINK "\e[45m"
#define BAACKAQUA "\e[46m"
#define BACKCREAM "\e[47m"
#define BACKDEFAULT "\e[48m"

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
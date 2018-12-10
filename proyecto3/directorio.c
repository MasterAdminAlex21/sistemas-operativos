#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include <string.h>
#include "colores.h"

void busca(char *direc,char *cad);
char *ruta=NULL;

int main(int argc,char *argv[]){

 if(argc!=3){
  printf(MAGENTA"uso: %s ruta cadena\n",argv[0]);
  exit(0);
 }
 DIR *dire,*aux=NULL;
 struct dirent *enti;
 system("clear");
// dire=opendir("/home/megumi/Documents/sistemas operativos/");
 dire=opendir(argv[1]);
 if(dire==NULL){
  printf("Error al abrir el directorio\n");
  exit(0);
 }
 char *cad=argv[2],*eq;//,*ruta;
 while((enti=readdir(dire))!=NULL){
  
  if((strcmp(enti->d_name,".")!=0) && (strcmp(enti->d_name,"..")!=0)){

    if((eq=strstr(enti->d_name,cad))!=NULL){
      printf(BACKSKY WHITE"%s\n"BACKDEFAULT,enti->d_name );
     }
     //eq=NULL;

   ruta=(char*)calloc((strlen(argv[1])+strlen(enti->d_name)+1),sizeof(char));
   strcat(ruta,argv[1]);
   strcat(ruta,"/");
   strcat(ruta,enti->d_name);
   //printf("%d\n%s\n",enti->d_type,enti->d_name );
   //printf("%s\n",enti->d_name );
    if((enti->d_type)==4){//4 representa un directorio
      //printf("abrio carpeta\n%s\n",ruta);
     busca(ruta,cad);
     //closedir(aux);
    }
//    free(ruta);
    //comparamos lascadenas
     

   }
  }
  //free(ruta);
  
  closedir(dire);

}

void busca(char *direc, char *cad){
  //free(ruta);
  //printf("ingreso al busca\n");
 DIR *dire,*aux;
 char *eq;//,*ruta;
 struct dirent *enti;
 //printf("crea las variables\n");
 dire=opendir(direc);
 //'printf("abre el dir ->");
 while((enti=readdir(dire))!=NULL){
  if((strcmp(enti->d_name,".")!=0) && (strcmp(enti->d_name,"..")!=0)){
    //printf("%s\n",enti->d_name );
    if((eq=strstr(enti->d_name,cad))!=NULL){
     printf(BACKSKY WHITE"%s\n"BACKDEFAULT,enti->d_name );
    }
    //eq=NULL;
    //por aqui se corrompe lamemoria
   ruta=(char*)calloc((strlen(direc)+strlen(enti->d_name)+1),sizeof(char));
   strcat(ruta,direc);
   strcat(ruta,"/");
   strcat(ruta,enti->d_name);
  //printf("%s\n",enti->d_name );
    if(enti->d_type==4){
     busca(ruta,cad);
     //closedir(aux);
    }
//    free(ruta);
    
   }
  }
  
  closedir(dire);
}
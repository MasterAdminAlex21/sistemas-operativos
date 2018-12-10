#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
 char *cad1={"."};
 char *cad2={".."};

 if(strcmp(cad1,".")==0){
  printf("Son iguales, el '.'\n");
 }else{
  printf("no son iguales, el '.'\n");
 }

 if(strcmp(cad2,"..")==0){
  printf("Son iguales los '..'\n");
 }else{
  printf("son diferentes los '..'\n");
 }
}
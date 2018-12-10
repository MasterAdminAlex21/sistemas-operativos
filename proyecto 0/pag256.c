#include<stdio.h>
#include<stdlib.h>

void pay_amount(int, int*, int*,int*,int*);

int main(){
 int monto,v=0,d=0,c=0,u=0;//v-veinte,d-diez,c-cinco,u-uno
 printf("Ingrese monto: \n");
 scanf("%d",&monto);
 pay_amount(monto,&v,&d,&c,&u);
 printf("cantidades:\n$20: %d\n$10: %d\n$5: %d\n$1: %d\n",v,d,c,u);

}

void pay_amount(int monto1, int* veinte,int* diez, int* cinco, int* uno){
 int monto=monto1;
 while(monto!=0){
  if(monto/20!=0){
   *veinte=monto/20;
   monto-=((*veinte)*20);
  }
  if(monto/10!=0){
   *diez=monto/10;
   monto-=((*diez)*10);
  }
  if(monto/5!=0){
   *cinco=monto/5;
   monto-=((*cinco)*5);
  }
  if(monto/1!=0){
   *uno=monto/1;
   monto-=((*uno)*1);
  }
 }
}
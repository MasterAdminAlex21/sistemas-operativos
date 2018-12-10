#include <stdio.h>
#include<stdlib.h>
int main ()
{
	
	int num=1234567890;
	
	
	printf("\nDecimal = %i",num);
	printf("\nHexadecimal = %x",num);
	printf("\nEl valor decimal y Hexadecimal no coinciden");
	
	printf("\n\nAhora inicializamos el valor con -1234567890");
	
	num=-1234567890;
	printf("\nDecimal = %i",num);
	printf("\nHexadecimal = %x",num);
	printf("\nEl valor decimal y Hexadecimal no coinciden");
	
	
	
	
	int num2=-3;
	printf("\n\n\n %x",num2);
	num2=-2;
	printf("\n %x",num2);
	num2=-1;
	printf("\n %x",num2);
	num2=0;
	printf("\n %x",num2);
	num2=1;
	printf("\n %x",num2);
	num2=2;
	printf("\n %x",num2);
	num2=3;
	printf("\n %x",num2);
	
	printf("\n\n el numero maximo es de 32 bits sin signo");
	printf("\n el numero maximo positivo es  2147483647");
	printf("\n el numero maximo negativo es -2147483648");
	
	int positivo=2147483647;
	int negativo=-2147483648;
	printf("\n%i",positivo);
	printf("\n%i",negativo);
}


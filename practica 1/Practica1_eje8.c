#include <stdio.h>



int main()

{
	
	char arreglo[4];
	int i=0;
	
	for(;;){
		
		printf("\n%c-%x-%p-%i",arreglo[i],arreglo[i],&arreglo[i],i); //Lo que hay en la direccion de memoria---direccion de memoria---numero
		i++;
	}
	

	
	
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "libreria.h"


int main(int argc, char* argv[]) {

	int a;
	int b;

	a=4;
	b=5;

//	printf("Sumar %i y %d es: %d\n",a,b,a+b);

	printf("La suma es: %i\n",suma(a,b));

	/*if(execl("/bin/ls","ls","-la",NULL) == -1){
		fprintf(stderr, "Error ejecutando el comando con execl\n");
		perror("programa1.c");

	}*/

	

	

		char comando[100];

		int i = 1;

		while(i<argc){
		 strcat(comando,argv[i]);
		 strcat(comando," ");
	 	i++;	
		}
	

	system(comando);

//	podemos ejecutar programas tanto con execl o con system
	return 0;
}
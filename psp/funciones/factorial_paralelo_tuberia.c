#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	
	if(argc!=2){

		fprintf(stderr, "Error en el uso del programa\n");
		fprintf(stderr, "Uso:\n\t %s número\n", argv[0]);
		exit(-1);
	} else {

		int tuberia[2];

		if(pipe(tuberia) == -1){
			exit(-1);
		}


		int objetivo = atoi(argv[1]);
		long int resultado = 1;
		int objetivo_hijo = objetivo/2;

		pid_t pid;

		pid = fork();


		switch(pid){

			case -1:
				
				fprintf(stderr, "Error en la creación del proceso hijo\n");
				exit(-1);
			
			case 0:
				
				while(objetivo_hijo>=1){

					resultado = resultado * objetivo_hijo;
					objetivo_hijo--;
				}

			fprintf(stdout, "resultado hijo: %ld\n",resultado);
			write(tuberia[1],&resultado,sizeof(long int));
				
			break;
			
			default:
				
				while(objetivo>objetivo_hijo){
					resultado = resultado * objetivo;
					objetivo--;
				}
			
			long int resultado_hijo;
			wait(NULL);

			read(tuberia[0],&resultado_hijo,sizeof(long int));				
			fprintf(stdout, "resultado padre: %ld\n",resultado);
			fprintf(stdout, "Resultado final %ld\n",resultado*resultado_hijo);

		}


	}

	return 0;
}
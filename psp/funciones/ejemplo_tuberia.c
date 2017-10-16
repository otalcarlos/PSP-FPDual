#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int tuberia[2];

	if(pipe(tuberia)==-1){
		fprintf(stderr, "Error en el pipe\n");
		exit(-1);
	}

	pid_t pid;

	pid = fork();

	switch(pid){

		case -1:
			fprintf(stderr, "Error en el fork\n");
			exit(-1);

		case 0:
			write(tuberia[1],"Hola padre!",11*sizeof(char));
		break;

		default:

			wait(NULL);
			char buffer[30];
			read(tuberia[0],buffer,9*sizeof(char));
			fprintf(stdout, "%s\n",buffer);
			close(tuberia[0]);
			close(tuberia[1]);
	}

	return 0;
}
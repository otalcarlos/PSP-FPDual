#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	
	pid_t pid1, pid2;

	printf("%s\n","Comenzando padre-hijo-nieto...");
	
	if (pid1 = fork() == -1){
		exit(-1);
	}

	if(pid1==0){

		printf("Hola soy el hijo. Mi padre es: %d\n", getppid());
		printf("Hola soy el hijo. Mi pid es %d\n",getpid());

		if (pid2 = fork() == -1){
			exit(-1);
		}

		if(pid2==0){

			printf("Hola soy el nieto. Mi padre es %d\n",getppid());
			printf("Hola soy el nieto. Mi pid es %d\n",getpid());
		} else {
			//aqui se podria poner que es el hijo en vez de ponerlo en el if de fuera
			//el hijo espera a que finalice el nieto, es decir, a su propio hijo
			printf("El proceso %d terminó\n",wait(NULL));
		}

	} else{

		printf("Hola soy el padre. Mi pid es %d\n",getpid());
		printf("He creado un hijo cuyo pid es %d\n",pid1);

		//el padre espera a que finalice el hijo
		printf("El proceso %d terminó\n",wait(NULL));
	}

	return 0;
}
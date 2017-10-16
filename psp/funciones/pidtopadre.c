#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	
	pid_t pid1, pid2, pid3;
	int tuberia[2];
	int pid_hijo1,pid_hijo2,pid_hijo3; 

	if(pipe(tuberia)==-1){
		fprintf(stderr, "Error en la creacion de la tuberia\n");
		exit(-1);
	}

	pid1 = fork();



	if(pid1==-1){
		fprintf(stderr, "Error en la creacion del proceso hijo 1\n");
		exit(-1);
	}

	if(pid1==0){
		//hijo 1
		pid_hijo1 = getpid();
		write(tuberia[1],&pid_hijo1,sizeof(int));	

	} else {
		//padre
		wait(NULL);
		int pid_hijo1;
		read(tuberia[0],&pid_hijo1,sizeof(int));
		close(tuberia);
		fprintf(stdout, "El pid de mi proceso hijo 1 es %d\n",pid_hijo1);

		pid2 = fork();

			if(pid2==-1){
				fprintf(stderr, "Error en la creacion del proceso hijo 2\n");
				exit(-1);
			} 

			if(pid2==0){
				//hijo 2
				pid_hijo2 = getpid();
				write(tuberia[1],&pid_hijo2,sizeof(int));	

			} else {
				wait(NULL);
				int pid_hijo2;
				read(tuberia[0],&pid_hijo2,sizeof(int));
				close(tuberia);
				fprintf(stdout, "El pid de mi proceso hijo 2 es %d\n",pid_hijo2);


				pid3 = fork();


				if(pid3==-1){
					fprintf(stderr, "Error en la creacion del proceso hijo 3\n");
					exit(-1);
				}

				if(pid3==0){
					//hijo 3
					pid_hijo3 = getpid();
					write(tuberia[1],&pid_hijo3,sizeof(int));
				} else {

					wait(NULL);
					int pid_hijo3;
					read(tuberia[0],&pid_hijo3,sizeof(int));
					close(tuberia);
					fprintf(stdout, "El pid de mi proceso hijo 3 es %d\n",pid_hijo3);
				}
			}
 
	}	

	

	return 0;
}

/*

CODIGO DE TEO

int tub[2];
int i;

for(i=0;i<3;i++){

	if(fork()==0){
		pid_t pid = getpid();
		write(tub[1],&pid,sizeof(pid_t));
		return 0;
	}
}

for(i=0,i<3;i++){
	wait(NULL)
	pid_t hijo;
	read(tub[0],&hijo,sizeof(pid_t));
	fprintf(stdout, "El hijo %d ha acabado\n",hijo);
}

close(tub[0]);
close(tub[1]);
return 0;*/


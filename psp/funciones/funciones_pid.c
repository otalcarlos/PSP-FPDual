#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{	
	//obtenemos el propio pid del programa que ejecutamos
	printf("PID: %d\n", getpid());
	//obtenemos el pid del padre del proceso del programa ejecutado
	printf("PID del padre%d\n", getppid());

	return 0;
}
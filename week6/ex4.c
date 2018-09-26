#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void SIGKILL_hanlder(int sign){
	printf("\nSIGKILL signal\n");
}

void SIGSTOP_hanlder(int sign){
	printf("\nSIGSTOP signal\n");
}

void SIGUSR1_hanlder(int sign){
	printf("\nSIGUSR signal\n");
}

int main()	
{
	signal(SIGSTOP,SIGSTOP_hanlder);
	signal(SIGKILL,SIGKILL_hanlder);
	signal(SIGUSR1,SIGUSR1_hanlder);

	while(1) {
		printf("Sleeping ...\n");
		sleep(10); 
	}
}


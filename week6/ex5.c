#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigterm_handler(int sign){
	printf("Child receveid sigterm signal\n");
}

int main()	
{
	int n=getpid();
	int child=fork();
	if (getpid()==n){
		sleep(10);
		kill(child,SIGTERM);
	}
	else{
		signal(SIGTERM,sigterm_handler);
		while(1){
			printf("Still alive\n");
			sleep(1);
		}
	}
}


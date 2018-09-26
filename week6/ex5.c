#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()	
{
	int n=getpid();
	int child=fork();
	if (getpid()==n){
		sleep(10);
		kill(child,SIGTERM);
	}
	else{
		while(1){
			printf("Still alive\n");
			sleep(1);
		}
	}
}


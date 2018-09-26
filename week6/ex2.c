#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
	int n=getpid();
	int ipc[2];
	pipe(ipc);
	fork();
	if (getpid()==n){
		char* first="Message from first process";
		write(ipc[1],&first,sizeof(first));
	}
	else {
		sleep(5);
		char* second="";
		int count=read(ipc[0],&second,256);
		printf("string: %s\n",second);
	}
}


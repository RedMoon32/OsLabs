#include <stdio.h>
#include <sys/types.h> 

int main(){
	int n=getpid();
	fork();
	if (getpid()==n)
		printf("Hello from parent [%d]\n\n\n\n",getpid()-n);
	else 
		printf("Hello from child [%d]\n\n\n\n",getpid()-n);
	return 0;
}
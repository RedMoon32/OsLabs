#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void SIGINT_hanlder(int sign){
	printf(" Dear User,SIGINT signal has been arised\n");
}

int main()
{
	signal(SIGINT,SIGINT_hanlder);
	while(1) {
      printf("Sleeping ...\n");
      sleep(1); 
   }
}


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#define string_size 256

int main()
{
	int ipc[2];
	pipe(ipc);
	char* first="Message from first string";
	char* second="";
	write(ipc[1],&first,sizeof(first));
	int count=read(ipc[0],&second,sizeof(first));
	printf("string: %s\n",second);
}


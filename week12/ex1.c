#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int randomData = open("/dev/random", O_RDONLY);
	if (randomData < 0)
	{
	    return -1;
	}
	else
	{
		char cmd[64];
	    char myRandomData[20];
	    ssize_t result = read(randomData, myRandomData, sizeof(myRandomData));
	    snprintf(cmd, sizeof(cmd), "echo \"%s\" > ex1.txt", myRandomData);
	    system(cmd);
	}
	return 0;
}
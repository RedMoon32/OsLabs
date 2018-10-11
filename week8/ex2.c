#include <stdio.h>

#define mb 1024*1024
#define size 10 * mb
int main(){
	for (int i=0;i<10;i++){
		char *ptr=malloc(size);
		memset(ptr,0,size);
		sleep(1);
	}
	sleep(100);
	return 0;
}
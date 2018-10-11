#include <stdio.h>
#include <sys/resource.h>

#define mb 1024*1024
#define size 10 * mb

int main(){
	struct rusage r;
	char *ptr;
	for (int i=0;i<10;i++){
		ptr=(char*)malloc(size);
		memset(ptr,0,size);
		getrusage(RUSAGE_SELF,&r);
		printf("\n=====================\nMemory usage:\n");
		printf("\nshared memory size:%ld", r.ru_ixrss);
		printf("\nunshared data size:%ld", r.ru_idrss);
		printf("\nunshared stack size:%ld", r.ru_isrss);
		printf("\npage reclaims:%ld", r.ru_minflt);
		printf("\npage faults:%ld", r.ru_majflt);
		sleep(1);
	}
	return 0;
}
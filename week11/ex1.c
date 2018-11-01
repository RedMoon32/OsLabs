
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

#define new_str "This is a nice day"
#define mem_size 18
#define path "ex1.txt"
int main(){
	unsigned char *f;
	struct stat s;
	FILE *ptr;
	int fd = open(path,O_RDWR);
	fstat(fd,&s);
	truncate(path, mem_size);
	int size=s.st_size;
	f=(char*) mmap(0,size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	for (int i=0;i<mem_size;i++){
		f[i]=new_str[i];
	}

	munmap(f,mem_size);
	close(fd);
	return 0;
}
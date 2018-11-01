#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>


#define path1 "ex1.txt"
#define path2 "ex1.memcpy.txt"


int main() {
	int fd1 = open(path1, O_RDONLY);
	int fd2 = open(path2, O_RDWR);
	struct stat st1;
	stat(path1, &st1);
	int size = st1.st_size;
	truncate(path2,size);
	char *f1=(char*)mmap(0,size,PROT_READ,MAP_SHARED,fd1,0);
	char *f2=(char*)mmap(0,size,PROT_READ|PROT_WRITE,MAP_SHARED, fd2,0);
	memcpy(f1,f2,size);
	munmap(f1, size);
	munmap(f2, size);
	close(fd1);
	close(fd2);
	return 0;
}

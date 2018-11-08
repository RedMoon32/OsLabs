#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 1024

int main(int argc, char *argv[]){
	if (argc<2 || !strcmp(argv[1],"-a")==0) return -1;
	int* file =(int*) malloc((argc-2)*sizeof(int));
	for (int i=2;i<argc;i++){
		file[i-2]=open(argv[i],O_APPEND | O_CREAT | O_WRONLY, S_IRWXG | S_IRWXO | S_IRWXU);
	}
	char in[MAX];
	while(fgets(in,MAX,stdin)!=NULL){
		int size = strlen(in);
		for (int i=0; i <argc-2; i++){
			write(file[i],in,size);
		}
	}
	return 0;
}
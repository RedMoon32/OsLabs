#include <stdio.h>
#include <unistd.h>

int main(){
	printf("--Simplified shell---");
	while (1){
		char command[256];
		printf("\n>>>");
		scanf("%s",command);
		system(command);
	}
}
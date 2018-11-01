#include <stdio.h>
#include <unistd.h>

#define str "Hello"

int main() {
	setvbuf(stdout, NULL, _IOLBF, 0);
	for (int i = 0; i < 5; i++) {
		printf("%c", str[i]);
		sleep(1);
		printf("\n");	
	}
	printf("\n");
	return 0;
}
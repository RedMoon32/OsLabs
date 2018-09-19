
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#define threads_num 5

void *myThreadFun(int numb) 
{ 
	printf("This is thread number %d\n",numb); 
	return NULL; 
} 

int main() 
{ 
	for (int i=0;i<threads_num;i++){
		pthread_t thread_id; 
		printf("New thread is created\n");
		pthread_create(&thread_id, NULL, myThreadFun, i); 
		if (i % 2 == 0) {
			sleep(1);
		}
	}
}

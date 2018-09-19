
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#define threads_num 5
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 
pthread_t threads[threads_num];

void *myThreadFun(void* arg) 
{ 
	printf("This is thread number %d\n",*(int *)arg); 
	return NULL; 
} 

int main() 
{ 
	for (int i=0;i<threads_num;i++){
		pthread_t thread_id; 
		printf("New thread is created\n");
		pthread_create(&threads[i], NULL, myThreadFun, &i); 
		pthread_join(threads[i],NULL);
		if (i % 2 == 0) {
			sleep(1);
		}
	}
}
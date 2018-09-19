
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#define threads_num 5
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 
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
		pthread_join(&thread_id);
		if (i % 2 == 0) {
			sleep(1);
		}
	}
}
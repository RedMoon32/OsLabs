#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#define buffer_size 100
char buffer[buffer_size];
int count=0;
int pr_flag=1,cs_flag=0;

void* producer(void* data){
	while (1)
	{
		if (count >= buffer_size) 
			pr_flag = 0;
		if (pr_flag) {
			buffer[count] = rand() % 256;
			count++;
		}
		if (count > 0) 
			cs_flag = 1;
	}
	pthread_exit(NULL);
}

void* consumer(void* data){
	while (1)
	{
		if (count <= 0) 
			cs_flag = 0;

		if (cs_flag) {
			buffer[count] = '-';
			count--;
		}
		if (count < buffer_size) {
			pr_flag = 1;
		}
	}
	pthread_exit(NULL);
}

int main(){
	srand(time(NULL));
	pthread_t producer_th,consumer_th;
	pthread_create(&producer_th,NULL,producer,NULL);
	pthread_create(&consumer_th,NULL,consumer,NULL);

	while (1) {
		sleep(3);
		printf("Current buffer size  = %d,\nLast element = %c;\n",count, buffer[count]);
	}


	return 0;
}
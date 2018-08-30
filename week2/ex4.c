#include <stdio.h>

void read_int(int *n){
	printf("Enter number:");
	scanf("%d",n);
}

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	int a,b;
	read_int(&a);
	read_int(&b);
	swap(&a,&b);
	printf("Swapped number: %d %d\n",a,b);
}

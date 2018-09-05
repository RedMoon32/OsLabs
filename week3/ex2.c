#include <stdio.h>

void bubblesort(int *a, int n){
	int swapping=1;
	while (swapping){
		swapping=0;
		for (int j=1;j<n;j++){
			if (a[j]<a[j-1]){
				swap(&a[j],&a[j-1]);
				swapping=1;
			}
		}
	}
}

void print_array(int *a, int n){
	for (int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{
	int a[]={5,4,3,2,1};
	int n=5;
	bubblesort(a,n);
	print_array(a,n);
}
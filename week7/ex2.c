#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int *mas=malloc(sizeof(int)*n);
	for (int i=0;i<n;i++){
		*(mas+i)=i;
		printf("%d ",*(mas+i));
	}
	free(mas);
	printf("\n");
	return 0;
}
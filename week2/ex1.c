#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){
	int a=INT_MAX;
	float b=FLT_MAX;
	double c=DBL_MAX;
	printf("int value: %d, size:%ld \n\n",a,sizeof(a));
	printf("float value: %lf, size:%ld \n\n",b,sizeof(b));
	printf("double value:%f, size:%ld \n\n ",c,sizeof(c));
}


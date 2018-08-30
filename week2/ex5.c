#include <stdio.h>
/*

   *
  ***
 ***** 

*/
void first(int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<2*n-1;j++){
			if (j>=n-i-1 & j<=n+i-1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
/*

*
**
***

*/
void second(int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
}
/*

***
***
***

*/
void third(int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("*");
		}
		printf("\n");
	}
}

int main(int argc,char *args[]){
	int n,type;
	if (argc<3)
	{
		n=6;
		type=1;
	}
	else{
		sscanf(args[1],"%d",&n);
		sscanf(args[2],"%d",&type);
	}
	switch(type){
		case 1:first(n);break;
		case 2:second(n);break;
		case 3:third(n);break;
	}
	return 0;
}

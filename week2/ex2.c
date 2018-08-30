#include <stdio.h>
#include <string.h>
#define len 256
int main(){
	char  a[len];
	fgets(a,len,stdin);
	for (int i=strlen(a)-1;i>=0;i--)
		printf("%c",a[i]);
}

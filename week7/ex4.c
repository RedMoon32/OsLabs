#include <stdio.h>

void *realloc2(void *ptr, int n){
	if (ptr==NULL)
		return NULL;
	void *new_ptr=malloc(sizeof(*ptr)*n);
	for (int i=0;i<n;i++){
		*((char*)new_ptr+i)=*(((char*)ptr)+i);
	}
	free(ptr);
	return new_ptr;
}

int main(){
	int *a=malloc(sizeof(int)*10);
	a=realloc2(a,12);
}
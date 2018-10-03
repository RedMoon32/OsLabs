#include <stdio.h>
int main() {
	char **s = (char*)malloc(1);
	//variable s = address [ address_of_var ]   *s = [address_of_var]	
	//variable s = address_of_var , *s = memory[address_of_var] 
	char foo[] = "Hello World";
	*s = foo;
	printf("s is %s\n",*s);
	s[0] = foo;
	printf("s[0] is %s\n",s[0]);
	return(0);
}
#include <stdio.h>

int main(){
	char aletter[] = {"sdfsdfsdf"};
	char *pletter = {"ssdfdsf"};
	printf("%c\n", aletter[(-2)]);
	pletter = pletter - 3;
	
	printf("%c\n", *pletter);

}

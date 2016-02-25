#include <stdio.h>
#include <math.h>

int main(){
	int c;
	printf("Type in a number for the integer square root: ");
	scanf("%d", &c);
	c = sqrt(c);
	printf("%d\n", c);
}

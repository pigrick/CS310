#include <stdio.h>

typedef union{
	long num1;
	double num2;
} Longordoub;

int main(){
	Longordoub ld;
	ld.num1 = 3333333;
	printf("%li\n", ld.num1);
	ld.num2  = 33.34;
	printf("%f\n", ld.num2);
	printf("%li\n", ld.num1);
	ld.num1 = 44;
	printf("%li\n", ld.num1);
	printf("%f\n", ld.num2);

}

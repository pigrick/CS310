#include <stdio.h>

int factorial(int c){
	int sum = 1;
	if(c < 0){
		printf("error,negative input");
	} else {
		int i;
		for(i = 2; i <= c; i++){
			sum = (sum * i);
		}
		return sum;
	}
}

int main(){
	int num;
	printf("Type in a number to factorial: ");
	scanf("%d", &num);
	printf("%d\n", factorial(num));
}


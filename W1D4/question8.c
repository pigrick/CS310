#include <stdio.h>

void fibonacci(int len){
	int i;
	if(len <= 0){
		return;
	} else if(len == 1){
		printf("0\n");
	} else if (len == 2){
		printf("0 1\n");
	} else {
		printf("0 1 ");
		int first = 0;
		int second = 1;
		int num;
		for(i = 2; i < len; i++){
			num = (first + second);
			first = second;
			second = num;
			printf("%d ", num);
		
		}
		printf("\n");
	}
}
int main(){
	int length;
	printf("Type in the length for fibonacci :");
	scanf("%d", &length);
	fibonacci(length);
}



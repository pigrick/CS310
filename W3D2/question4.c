#include <stdio.h>

int main(){
	float money[5] = {122.3, 4.4 ,23.5, 4444.5, 3.2};
	int i;
	printf("Money\n");
	for(i = 0; i < 5; i++){
		printf("$%8.2f\n", money[i]);
	}
}


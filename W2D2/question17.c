#include <stdio.h>


int matsum3d(int *p, int first, int second, int third){
	int sum = 0;
 	
	int i;
	int totalE = first * second * third;
	for(i = 0; i < totalE; i++){
		sum += p[i];
	}
	return sum;
}


int main(){
	int num[3][3][3];
	int *p = &num[0][0][0];

	int i;
	for(i = 0; i< 27 ; i++){
		p[i] = i + 1;
	}
	printf("%d\n", matsum3d(p, 3, 3, 3));
}

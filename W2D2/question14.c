#include <stdio.h>

int main(){
	int num[10][10];
	int *n = &num[0][0];
	int i;
	for(i = 0; i < 100; i++){
		n[i] = i;
	}
	int j;
	int row1;
	int row2;
	
	int temp[10][10];
	int *t = &temp[0][0];
	for(i = 0; i < 100 ;i++){
		t[i] = i;
	}
	printf("Type in a row to change: ");
	scanf("%d", &row1);
	printf("Row to change with: ");
	scanf("%d", &row2);
	
	for(i = 0; i < 10; i++){
		temp[row1][i] = num[row2][i];
		temp[row2][i] = num[row1][i];
	}
	puts("Original:");
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			printf("%d\t", num[i][j]);
		}
		puts("");
	}

	puts("Transformed: ");
	for(i = 0; i <10; i++){
		for(j = 0; j < 10; j++){
			printf("%d\t", temp[i][j]);
		}
		puts("");
	}
}

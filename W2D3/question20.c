#include <stdio.h>
#include <stdlib.h>

int rtc(const int* row, const int* col, int s, int t){
	int sum = 0;
	while (s > 0){
		 sum += *row * *col;
		 row++;
		 col += t;
		 s--;
	}
	return sum;
}

int* matmul(const int* x, const int* y, int r, int s, int t){
	int* res = calloc(r*t, sizeof(int));
	int* p = res;
	int elem = 0;
	int i;
	for(i = 0; i < r; i++){
		x += i*s;
		int j;
		for (j = 0; j<t; j++){
			*p = rtc(x, y+j, s ,t);
			p++;
			elem++;
		}
	}
	p -= elem;
	return p;
}

int main(){
	int a[2][3] = {{1, -2, 5}, {1, 2, 3}};
	int b[3][2] = {{9, 7}, {-2, 3}, {-1, 4}};
	int *c = matmul(*a, *b, 2, 3, 2);
	printf("( %d\t%d )\n( %d\t%d )\n", *c, *(c+1), *(c+2), *(c+3));
}

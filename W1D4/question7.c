#include <stdio.h>
#include <stdlib.h>

int num[] = {12, 44, 66, 22, 33, 35, 48, 77, 55};
int len = 9;

int cmpfunc(const void * a, const void * b){
	return (*(int*)a - *(int*)b);
}

int main(){


	qsort(num, 9, sizeof(int), cmpfunc);
	int middle = ((len+1)/2);
	printf("The middle number is %d\n", num[middle]);

}

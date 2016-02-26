#include <stdio.h>

void getminmax(int num[], int len){
	int min, max;
	min = num[0];
	max = num[0];
	int i;
	for(i = 1; i < len; i++){
		if(min > num[i]){
			min = num[i];
		} else if (max < num[i]) {
			max = num[i];
		}
	}
	printf("Max is %d, min is %d.\n", max, min);

}

int main(){
	int numb[] = {3,5,2,2,7,3,4,5};
	getminmax(numb, 8);


}


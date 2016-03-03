#include <stdio.h>


register int i;
void arr_apply(void * any, int length, int num, void(*fn)(void* any, int num,  int index)){
	for(i = 0; i < length;i++){
		fn(any, num, i);
	}
}

typedef int(*func) (void* any, int num, int index);

void add(void*any,int num, int index){
	any[index] += num;
}

void product(void* any,int num, int index){
	any[index] *= num;
}

int main(){
	int a[3] = {3,4,5};
	float b[3] = {6.4f, 7.3f ,8.3f};
	double c[3] = {3.4, 4.5, 3.6};
	
	arr_apply(a, 3, 2, (func)add);
	arr_apply(b, 3, 2, (func)product);
	arr_apply(c, 3, 3, (func)add);

	for(i = 0; i < 3; i++){
		printf("%d\t", a[i]);
	}
	puts("");
	for(i = 0; i < 3; i++){
		printf("%f\t", b[i]);
	}
	puts("");
	for(i = 0; i < 3; i++){
		printf("%f\t", c[i]);
	}
	puts("");



}

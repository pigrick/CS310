#include <stdio.h>

void push(float value){
	 extern float num[];
	 extern int top;
	 top += 1;
	 num[top] = value;
}

float pop(){
	extern float num[];
	extern int top;
	if(top == 0){
		fprintf(stderr, "nothing to pop\n");
	} else {
		float temp = num[top];
		top--;
		return temp;
	}
}

int main(){
	extern float num[];
	extern int top;
	push(1.0);
	push(2.0);
	push(3.0);
	printf("%f\n", pop());
	printf("%f\n", pop());
	printf("%f\n", pop());
}

float num[100];
int top = 0;

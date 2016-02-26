#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]){
	
}

float num[100];
int top = 0;

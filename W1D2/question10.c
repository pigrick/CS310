#include <stdio.h>

int printloop(int x){
	if(x == 0){
	} else {
		printf("C is a powerful a language, especially on UNIX system. %d \n", x );
		printloop(x-1);
	}
}

int main() {
	printloop(5);
}


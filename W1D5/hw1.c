#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	if(argc != 3){
		fprintf(stderr, "Need two numbers!\n");
		exit(1);
	}

	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);
	if(num1 >= num2){
		fprintf(stderr,"First number need to be smaller than second number!\n");
		exit(1);
	}

	int difference = num2 - num1;
	srand(time(NULL));
	int randNum = ((rand() % (difference + 1)) + num1);
	printf("%d\n", randNum);	
	
}

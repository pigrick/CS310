#include <stdio.h>

int main(){
	int year;
	printf("Type in a year to check for leap year :");
	scanf("%d", &year);

	if((year % 4) == 0){
		if((year % 100) == 0){
			if((year % 400) == 0){
				printf("It is a leap year\n");
			} else {
				printf("Not a leap year\n");
			}
		} else {
			printf("It is a leap year\n");
		}
	} else {
		printf("Not a leap year\n");
	}
}

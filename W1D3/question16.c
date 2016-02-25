#include <stdio.h>

float conversion(float tempe){	
	return (((tempe * 9) / 5) + 32);
}

int main(int argc, float celsius[]){
	int i;
	for(i = 1; i < argc; i++){
	
		printf("Farenheit is :");
		printf("%.2f\n", conversion(celsius[i]));
		
	}
	float c;
	printf("Type in celsius to convert to farenheit: ");
	scanf("%f", &c);
	printf("%f\n", conversion(c));
}

#include <stdio.h>
#include <stdlib.h>

float conversion(float tempe){	
	return (((tempe * 9) / 5) + 32);
}

int main(int argc, char *celsius[]){
	int i;
	float g;

	for(i = 1; i < argc; i++){
		g = atof(celsius[i]);
		printf("Farenheit is :");
		printf("%.2f\n", conversion(g));
		
	}
	
}

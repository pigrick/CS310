#include <stdio.h>
#include <stdlib.h>

void checkfile(int cases, char filename[]){
	FILE *file = fopen(filename, "r");
	char c;
	int count = 0;
	while ((c=getc(file)) != EOF){
		if(cases == 1){
			if(c == 32){
				count++;
			}
		} else if (cases == 2){
			if(c == 9){
				count++;
			}
		} else if (cases == 3){
			if(c == 10){
				count++;
			}
		} else if (cases == 4){
			if(c == 12){
				count++;
			}
		}

	}
	printf("%d\n", count);
}

int main(int argc, char *argv[]){
	if(argc == 1){
		fprintf(stderr, "Please give a filename!\n");
		return 1;
	}
	int input;
	printf("Space = 1, Tab = 2, New Line = 3, Formfeed = 4 :");
	scanf("%d", &input);
	switch(input){
		case 1:
			checkfile(1, argv[1]);
			break;
		case 2:
			checkfile(2, argv[1]);
			break;
		case 3:
			checkfile(3, argv[1]);
			break;
		case 4:
			checkfile(4, argv[1]);
			break;
		default:
			fprintf(stderr, "Invalid input!\n");
 			break;
	}

}

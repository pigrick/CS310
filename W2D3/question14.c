#include <stdio.h>

int main(){
	int num[10][10];
	int *n = &num[0][0];
	int i;
	for(i = 0; i < 100; i++){
		n[i] = i;
	}
	int j;
	int row1;
	int row2;
	int column1;
	int column2;
	int collen = 10;
	int rowlen = 10;
	
	int temp[10][10];
	int *t = &temp[0][0];
	for(i = 0; i < 100 ;i++){
		t[i] = i;
	}
	int choice1;
	int choice2;

	printf("Type 1 for Deletion, 2 for interchange, 3 for display:  ");
	scanf("%d", &choice1);
	if(choice1 != 3){
		puts("Type 1 for row, 2 for column: ");
		scanf("%d", &choice2);
	}
	switch(choice1){
		case 1:
			switch(choice2){
				case 1:
					printf("Type in a row to delete: ");
					scanf("%d", &row1);
					for(i = 0; i < 10; i++){
						temp[row1][i] = -1;
					}
					break;
				case 2:
					printf("Type in a column to delete: ");
					scanf("%d", &column1);
					for(i = 0; i < 10; i++){
						temp[i][column1] = -1;
					}
					break;
				
			}
			break;
		case 2:
			switch(choice2){
				case 1:
					printf("Type in a row to change: ");
					scanf("%d", &row1);
					printf("Row to change with: ");
					scanf("%d", &row2);
					for(i = 0; i < 10; i++){
						temp[row1][i] = num[row2][i];
						temp[row2][i] = num[row1][i];
					}
					break;
				case 2:
					printf("Type in a column to change: ");
					scanf("%d", &column1);
					printf("Column to change with: ");
					scanf("%d", &column2);
					for(i = 0; i < 10; i++){
						temp[i][column1] = num[i][column2];
						temp[i][column2] = num[i][column1];
					}
					break;
			}
			break;
		
		}
			puts("Original:");
			for(i = 0; i < 10; i++){
				for(j = 0; j < 10; j++){
					printf("%d\t", num[i][j]);
				}		
				puts("");
			}		

			puts("Transformed: ");
			for(i = 0; i <10; i++){
				for(j = 0; j < 10; j++){
					if(temp[i][j] != -1){
						printf("%d\t", temp[i][j]);
					}

				}	
				if(temp[i][j] != -1){
					puts("");
				}
			}
			
	
}

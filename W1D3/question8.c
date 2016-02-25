#include <stdio.h>

int reverse(char string[]){
	int len = 0;
	int i;
	while(string[len] != '\0'){
		len += 1;
	}
	for(i = len; i >= 0; i--){                                                  
		printf("%c", string[i]);                                                   
	}                                                                           
	printf(" "); 

}

int main(int argc, char *argv[]){
	int j;
	for(j = (argc-1); j >= 0; j--){
		reverse(argv[j]);
	}
	printf("\n");
}

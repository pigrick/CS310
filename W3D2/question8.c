#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	char c;

	if(argc != 3){
		fprintf(stderr, "Need 2 files\n");
		return -1;
	}
	FILE * file1 = fopen(argv[1], "a+");
	FILE * file2 = fopen(argv[2], "r");
	if(file1 == NULL || file2 == NULL ){
		fprintf(stderr, "Can't open\n");
		return -2;
	}
	while((c = getc(file2)) != EOF){
		putc(c, file1);
	}

	fclose(file1);
	fclose(file2);
}

#include <stdio.h>
#include <stdlib.h>

/*int read_data(void *m, size_t size, const char* name){
	FILE* stream = fopen(name, "rb");
	if(stream == NULL){
		fprintf(stderr, "Can't open");
		return -1;
	}
	int read = fread(m, size, 1, stream);
	if(ferror(stream)){
		read = -1;
	}
	fclose(stream);
	return read;
} */


int main(){
	FILE* update = fopen("test.txt", "r");
	if(update == NULL){
		fprintf(stderr, "error");
		return -1;
	}
	int aa[10], bb[10], cc[10];
	int i = 0;
	int j = 0;
	char c;
	char* string = (char*) malloc(50*sizeof(char));
	while ((c = getc(update)) != EOF){
		if(c != '\n'){
			string[j] = c;
			j++;
		} else {
			sscanf(string, "%*d %d %*d %d %*d %*d %d", &aa[i],&bb[i],&cc[i]);
			i++;
			j=0;
		}
	}
	for(i = 0; i<3; i++){
		printf("%d, %d, %d\n", aa[i], bb[i], cc[i]);
	}
}

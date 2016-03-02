#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* drevcpy(const char* s){
	int l = (strlen(s) - 1);
	char* cp = malloc(l * sizeof(char));
	int i;
	int j = 0;
	for(i = l; i >= 0; i--){
		cp[j] = s[i];
		j++;
	}
	return cp;
}

int main(){
	char *test = "This is a test of things!";
	char *rcopy = drevcpy(test);
	puts(rcopy);
}

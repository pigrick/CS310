#include <stdio.h>

int upper(int c){
	if(c >= 'a' && c <= 'z'){
		return (c - 'a' + 'A');
	}
}

int main(){
	printf("%c\n", upper('d'));
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char* stack;
	int size;
	int tail;
	int length;
} Cirbufstack;

Cirbufstack make_stack(int max){
	Cirbufstack b = {NULL, 0, 0};
	b.size = max;
	b.stack = (char*) malloc(max*sizeof(char));
}

#define EMPTY_CIR(bp) (bp->length == 0)
#define FULL_CIR(bp) (bp->length == bp->size)

int push(char c, Cirbufstack* bp){
	if(FULL_CIR(bp)){
		fprintf(stderr, "push: stack full\n");
		return -1;
	}

	bp->stack[bp->tail] = c;
	bp->tail++;
	bp->length++;
	return 0;
}

int pop(Cirbufstack* bp){
	if(EMPTY_CIR(bp)){
		fprintf(stderr, "pop: stack empty\n");
		return -1;
	}

	char c = bp->stack[(bp->tail)-1];
	bp->tail--;
	bp->length--;
	return c;
}

void delete_stack(Cirbufstack b){
	free(b.stack);
}

int main(){
	Cirbufstack a = make_stack(10);
	push('s', &a);
	push('y', &a);
	push('g', &a);
	push('y', &a);
	push('d', &a);
	int i;
	for(i = 0; i < 3; i++){
		printf("%c\n", pop(&a));
	}
	push('m', &a);
	push('l', &a);
	for(i = 0; i< 3; i++){
		printf("%c\n", pop(&a));
	}

}

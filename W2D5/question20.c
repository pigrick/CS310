#include <stdio.h>
#include <stdlib.h>

typedef struct {
	void* buf;
	int size;
	int head;
	int tail;
	int length;
} Queue;

Queue make_queue(int max){
	Queue b = {NULL, 0, 0, 0};
	b.size = max;
	b.buf = malloc(max*sizeof(void));
	return b;
}

#define EMPTY_QUEUE(q) (q->length == 0)
#define FULL_QUEUE(q) (q->length == q->size)

int delete_queue(Queue *q){
	free(q);
	return 0;
}

int enqueue(Queue *q, const void item){
	if(FULL_QUEUE(q)){
		fprintf(stderr, "Queue is full\n");
		return 1;
	}
	q->buf[q->tail] = item;
	q->tail++;
	q->length++;
	if(q->tail == q->size){
		q->tail = 0;
	}
	return 0;
}

void* dequeue(Queue *q){
	if(EMPTY_QUEUE(q)){
		fprintf(stderr, "Queue is empty\n");
		return NULL;
	}
	void c = q->buf[q->head];
	q->head++;
	q->length--;
	if(q->head == q->size){
		q->head = 0;
	}
	return c;
}

int isempty(Queue *q){
	return EMPTY_QUEUE(q);
}

int main(){
	Queue a = make_queue(5);
	int i ;
	for(i = 1; i<6; i++){
		enqueue(&a, i);
	}
	for(i = 1; i<6; i++){
		printf("%d\n " , dequeue(&a));
	}
}




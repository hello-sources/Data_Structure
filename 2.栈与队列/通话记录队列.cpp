//这个代码还有问题 
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
	long long *data;
	int head, tail, length;
} Queue;

void init(Queue *q, int length) {
	q->data = (long long *)malloc(sizeof(long long));
	q->length = length;
	q->head = 0;
	q->tail = -1;
}

int push(Queue *q, long long element) {
	if (q->head + 1 >= q->length) return 0;
	q->tail++;
	q->data[q->tail] = element;
	return 1;
}

void pop(Queue *q) {
	q->head++;
}

void front(Queue *q) {
	printf("%lld ", q->data[q->head]);
}

int empty(Queue *q) {
	return q->head > q->tail;
}

void clear(Queue *q) {
	free(q->data);
	free(q);
}

int main() {
	Queue *q1 = (Queue *)malloc(sizeof(Queue));
	Queue *q2 = (Queue *)malloc(sizeof(Queue));
	Queue *q3 = (Queue *)malloc(sizeof(Queue));
	int num;
	long long phone;
	for (int i = 1; i <= 10; i++) {
		scanf("%d", &num);
		switch (num) {
			case 0: {
				scanf("%lld", &phone);
				push(q1, phone);
				//printf("%lld \n", phone);
				break;
			}
			case 1: {
				scanf("%lld", &phone);
				push(q2, phone);
				break;
			}
			case 2: {
				scanf("%lld", &phone);
				push(q3, phone);
				break;
			}
		}
	}
	for (int i = 1; i <= 10; i++) {
		//printf("到这\n");
		if (!empty(q1)) {
			//printf("%lld ", front(q1));
			front(q1);
			pop(q1);
		} else {
			printf("0 ");
		}
		if (!empty(q2)) {
			//printf("%lld ", front(q2));
			front(q2);
			pop(q2);
		} else {
			printf("0 ");
		}
		if (!empty(q3)) {
			//printf("%lld ", front(q3));
			front(q3);
			pop(q3);
		} else {
			printf("0");
		}
		printf("\n");
	}
	clear(q1);
	clear(q2);
	clear(q3);
	return 0;
} 

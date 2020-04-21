#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Queue {
    int *data;
    int head, tail, length;
}Queue;

void init(Queue *q, int length) {
    q->data = (int *)malloc(sizeof(int) * length);
    q->length = length;
    q->head = 0;
    q->tail = -1;
}

int push(Queue *q, int element) {
    if(q->tail + 1 >= q->length) {
        return ERROR;
    }
    q->tail++;
    q->data[q->tail] = element;
    return OK;
}

void output(Queue *q) {
    for (int i = q->head; i <= q->tail; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

// 请在下面实现队首元素输出函数 front
int front(Queue *q) {
	return q->data[q->head];
}

// 请在下面实现删除队首元素函数 pop
void pop(Queue *q) {
	q->head++;
}

// 请在下面实现判断队列是否为空的函数 empty
int empty(Queue *q) {
    return q->head > q->tail;
}

void clear(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    init(queue, 100);
    for (int i = 1; i <= 10; i++) {
        push(queue, i);
    }
    output(queue);
    if (!empty(queue)) {
        printf("%d\n", front(queue));
		pop(queue);
    }
    output(queue);
    clear(queue);
    return 0;
}

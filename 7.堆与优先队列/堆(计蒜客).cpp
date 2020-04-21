#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *data, size;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (int *)malloc(sizeof(int) * length_input);
    h->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, int value) {
    h->data[h->size] = value;
    int current = h->size;
    int father = (current - 1) / 2;
    while (h->data[current] > h->data[father]) {
        swap(&h->data[current], &h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->size++;
}

void output(Heap *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ",  h->data[i]);
    }
    printf("\n");
}

int top(Heap *h) {
    return h->data[0];
}

void update(Heap *h, int pos, int n) {
    int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
    int max_value = pos;
    if (lchild < n && h->data[lchild] > h->data[max_value]) {
        max_value = lchild;
    }
    if (rchild < n && h->data[rchild] > h->data[max_value]) {
        max_value = rchild;
    }
    if (max_value != pos) {
        swap(&h->data[pos], &h->data[max_value]);
        update(h, max_value, n);
    }
}

void pop(Heap *h) {
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

// 请在下面实现堆排序函数 heap_sort
void heap_sort(Heap *h) {
	for (int i = h->size - 1; i >= 1; i--) {
		swap(&h->data[i], &h->data[0]);
        update(h, 0, i);
    }
}

void clear(Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    int arr[10] = { 12, 9, 30, 24, 30, 4, 55, 64, 22, 37 };
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    init(heap, 100);
    for (int i = 0; i < 10; i++) {
        push(heap, arr[i]);
    }
    output(heap);
    printf("%d\n", top(heap));
    pop(heap);
    output(heap);
    heap_sort(heap);
    output(heap);
    clear(heap);
    return 0;
}

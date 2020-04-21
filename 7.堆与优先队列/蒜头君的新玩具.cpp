#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define swap(a, b) {\
	__typeof(a) __temp = a;\
	a = b; b = __temp;\
} 

typedef struct Heap {
    double *data;
	int size, cnt;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (double *)malloc(sizeof(double) * length_input);
    h->size = 0;
    h->cnt = length_input;
}

void push(Heap *h, double value) {
	if (h == NULL) return ;
	if (h->size == h->cnt) return ;
    h->data[h->size] = value;
    int current = h->size;
    int father = (current - 1) / 2;
    while (h->data[current] > h->data[father]) {
        swap(h->data[current], h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->size++;
}

double top(Heap *h) {
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
        swap(h->data[pos], h->data[max_value]);
        update(h, max_value, n);
    }
}


void pop(Heap *h) {
	if (h->size == 0) return ;
    h->size--;
    swap(h->data[0], h->data[h->size]);
    update(h, 0, h->size);
}


void clear(Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    int n, value;
	double ans = 0;
    scanf("%d", &n);
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    init(heap, n);
    for (int i = 0; i < n; i++) {
		scanf("%d", &value);
        push(heap, value);
    }
    for (int i = 1; i < n; i++) {
		double a = top(heap);
        pop(heap);
        double b = top(heap);
        pop(heap);
        ans = pow(a * b * b, 1.0 / 3.0);
        push(heap, ans);
    }
    printf("%lf\n", top(heap));
    clear(heap);
    return 0;
}


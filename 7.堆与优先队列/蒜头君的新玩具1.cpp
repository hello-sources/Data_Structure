#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define swap(a, b) { \
__typeof(a) __temp; \
__temp = (a); \
(a) = (b); \
(b) = __temp; \
}
 
typedef struct Heap {
    double *data;
    int size, length;
} Heap;
 
void init_heap(Heap *h, int n) {
    h->data = (double *)malloc(sizeof(double) * n);
    h->length = n;
    h->size = 0;
}
 
void push_heap(Heap *h, double value) {
    if (h->size >= h->length) return ;
    h->data[h->size] = value;
    int ind, f;
    ind = h->size;
    f = (ind - 1) / 2;
    while (h->data[ind] > h->data[f]) {
        swap(h->data[ind], h->data[f]);
        ind = f;
        f = (ind - 1) / 2;
    }
    h->size++;
}
 
void update_heap(Heap *h, int i, int n) {
    int l, r, m;
    l = i * 2 + 1;
    r = i * 2 + 2;
    m = i;
    if (l < n && h->data[l] > h->data[m]) {
        m = l;
    }
    if (r < n && h->data[r] > h->data[m]) {
        m = r;
    }
    if (m != i) {
        swap(h->data[m], h->data[i]);
        update_heap(h, m, n);
    }
}
 
double top_heap(Heap *h) {
    return h->data[0];
}
 
void pop_heap(Heap *h) {
    if (h->size == 0) return ;
    h->size--;
    swap(h->data[0], h->data[h->size]);
    update_heap(h, 0, h->size);
}
 
void clear_heap(Heap *h) {
    free(h->data);
    free(h);
}
 
int main() {
    int n, ans = 0;
    double a, b, new_value;
    scanf("%d", &n);
    Heap *h = (Heap *)malloc(sizeof(Heap));
    init_heap(h, n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a);
        push_heap(h, a);
    }
    for (int i = 1; i < n; i++) {
        a = top_heap(h); pop_heap(h);
        b = top_heap(h); pop_heap(h);
        new_value = pow(a, 1.0 / 3.0) * pow(b, 2.0 / 3.0);
        push_heap(h, new_value);
    }
    printf("%lf\n", top_heap(h));
    clear_heap(h);
    return 0;
}

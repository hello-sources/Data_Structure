#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define swap(a, b) { \
__typeof(a) __temp; \
__temp = (a); \
(a) = (b); \
(b) = __temp; \
}
 
typedef struct Node {
    int pi, di;
} Node;
 
typedef struct Heap {
    Node *data;
    int size, length;
} Heap;
 
int cmp_node(Node a, Node b) {
    if (a.pi < b.pi) return 1;
    if (a.pi == b.pi && a.di < b.di) return 1;
    return 0;
}
 
void init_heap(Heap *h, int n) {
    h->data = (Node *)malloc(sizeof(Node) * n);
    h->length = n;
    h->size = 0;
}
 
void push_heap(Heap *h, Node value) {
    if (h->size >= h->length) return ;
    h->data[h->size] = value;
    int ind, f;
    ind = h->size;
    f = (ind - 1) / 2;
    while (cmp_node(h->data[ind], h->data[f])) {
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
    if (l < n && cmp_node(h->data[l], h->data[m])) {
        m = l;
    }
    if (r < n && cmp_node(h->data[r], h->data[m])) {
        m = r;
    }
    if (m != i) {
        swap(h->data[m], h->data[i]);
        update_heap(h, m, n);
    }
}
 
Node top_heap(Heap *h) {
    return h->data[0];
}
 
void pop_heap(Heap *h) {
    if (h->size == 0) return ;
    h->size--;
    swap(h->data[0], h->data[h->size]);
    update_heap(h, 0, h->size);
}
 
int empty_heap(Heap *h) {
    return h->size == 0;
}
 
void clear_heap(Heap *h) {
    free(h->data);
    free(h);
}
 
int main() {
    int n, t;
    scanf("%d", &t);
    while (t--) {
        Heap *h = (Heap *)malloc(sizeof(Heap));
        Node stone;
        int ans = 0;
        scanf("%d", &n);
        init_heap(h, n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &stone.pi, &stone.di);
            push_heap(h, stone);
        }
        int i = 1;
        while (!empty_heap(h)) {
            stone = top_heap(h);
            pop_heap(h);
            ans = stone.pi;
            if (i % 2) {
                stone.pi += stone.di;
                push_heap(h, stone);
            }
            i++;
        }
        printf("%d\n", ans);
        clear_heap(h);
    }
    return 0;
}

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
    int ind, f;
} Node;
 
typedef struct Heap {
    Node *data;
    int size, length;
} Heap;
 
int cmp_node(Node a, Node b) {
    if (a.f > b.f) return 1;
    if (a.f == b.f && a.ind < b.ind) return 1;
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
    int t, n, tcase = 0;
    scanf("%d", &t);
    Heap *h[101];
    for (int i = 1; i <= 100; i++) {
        h[i] = (Heap *)malloc(sizeof(Heap));
        init_heap(h[i], 50000);
    }
    while (tcase < t) {
        printf("Case #%d:\n", ++tcase);
        scanf("%d", &n);
        Node zombie;
        int s;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &zombie.f, &s);
            zombie.ind = i + 1;
            push_heap(h[s], zombie);
        }
        for (int i = 0; i < n; i++) {
            int m = -1;
            Node zombie1, zombie2;
            for (int j = 1; j <= 100; j++) {
                if (empty_heap(h[j])) continue;
                if (m == -1) {
                    m = j;
                    continue;
                }
                zombie1 = top_heap(h[m]);
                zombie2 = top_heap(h[j]);
                zombie1.f = zombie1.f + i * m;
                zombie2.f = zombie2.f + i * j;
                if (cmp_node(zombie2, zombie1)) {
                    m = j;
                } 
            }
            printf("%d", top_heap(h[m]).ind);
            pop_heap(h[m]);
            if (i != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 1; i <= 100; i++) {
        clear_heap(h[i]);
    }
    return 0;
}

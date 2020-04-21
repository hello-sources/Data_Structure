#include <stdio.h>
#include <stdlib.h>
 
typedef struct DisjointSet {
    int *father;
    int *rank;
}DisjointSet;
 
void init(DisjointSet *s, int size) {
    s->father = (int *)malloc(sizeof(int) * size);
    s->rank = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        s->father[i] = i;
        s->rank[i] = 1;
    }
}
 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
int max(int a, int b) {
    return a > b ? a : b;
}
 
int find_set(DisjointSet *s, int node) {
    if (s->father[node] != node) {
        s->father[node] = find_set(s, s->father[node]);
    }
    return s->father[node];
}
 
int merge(DisjointSet *s, int node1, int node2) {
    int f1 = find_set(s, node1);
    int f2 = find_set(s, node2);
    if (f1 != f2) {
        if (s->rank[f1] > s->rank[f2]) {
            swap(&f1, &f2);
        }
        s->father[f1] = f2;
        s->rank[f2] = max(s->rank[f1] + 1, s->rank[f2]);
        return 1;
    }
    return 0;
}
 
void clear(DisjointSet *s) {
    if (!s) return ;
    free(s->father);
    free(s->rank);
    free(s);
}
 
int main() {
    DisjointSet *dsu = (DisjointSet *)malloc(sizeof(DisjointSet));
    int m, n, a, b;
    scanf("%d%d", &m, &n);
    init(dsu, m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        merge(dsu, a, b);
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", dsu->father[i]);
    }
    return 0;
}

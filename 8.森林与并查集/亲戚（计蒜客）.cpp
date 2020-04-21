#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
	int *father, *size;
	int n;
} UnionSet;

UnionSet *init(int n) {
	UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
	u->father = (int *)malloc(sizeof(int) * (n + 1));
	u->size = (int *)malloc(sizeof(int) * (n + 1));
	u->n = n;
	for (int i = 1; i <= n; i++) {
		u->father[i] = i;
		u->size[i] = 1;
	}
	return u;
} 

int find(UnionSet *u, int x) {
	if (u->father[x] == x) return x;
	return find(u, u->father[x]);
}

int merge(UnionSet *u, int a, int b) {
	int fa = find(u, a), fb = find(u, b);
	if (fa == fb) return 0;
	if (u->size[fa] > u->size[fb]) {
		u->father[fb] = fa;
		u->size[fa] += u->size[fb]; 
	} else{
		u->father[fa] = fb;
		u->size[fb] += u->size[fa]; 
	}
	return 1;
} 

void clear(UnionSet *u) {
	if (u == NULL) return ;
	free(u->father);
	free(u->size);
	free(u);
	return ; 
}


int main() {
	int n, m, p, a, b;
	scanf("%d%d%d", &n, &m, &p);
	UnionSet *u = init(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		merge(u, a, b);
	}
	for (int i = 0; i < p; i++) {
		scanf("%d%d", &a, &b);
		printf("%s\n", find(u, a) == find(u, b) ?  "Yes" : "No");
	}
	clear(u);
	return 0;
}

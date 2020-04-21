//按秩路径优化weighted quick_union算法 
#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {\
	__typeof(a) __temp = a;\
	a = b; b = __temp;\
}

typedef struct UnionSet {
	int *father, *size;
	int n;//元素个数 
} UnionSet;

//并查集初始化
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

//查找函数
int find(UnionSet *u, int x) {
	return u->father[x] = (u->father[x] == x ? x : find(u, u->father[x]));
} 

//合并操作 
int merge(UnionSet *u, int a, int b) {
	int fa = find(u, a), fb = find(u, b);
	if (fa == fb) return 0;
//	if (u->size[fa] < u->size[fb]) swap(fa, fb);
	u->father[fb] = fa;
//	u->size[fb] += u->size[fb];
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
	int n, m;
	scanf("%d%d", &n, &m);
	UnionSet *u = init(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		switch (a) {
			case 1:{
				merge(u, b, c);
				break;
			}
			case 2:{
				printf("%s\n", find(u, b) == find(u, c) ?  "Yes" : "No");
				break;
			}
		}
	} 
	clear(u);
	
	return 0;
}
 
 

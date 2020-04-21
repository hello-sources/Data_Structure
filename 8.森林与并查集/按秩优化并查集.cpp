//按秩路径优化weighted quick_union算法 
#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
	int *father, *size;//我们记录每棵子树节点个数 
	int n;//元素个数 
} UnionSet;

//并查集初始化
UnionSet *init(int n) {
	UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
	u->father = (int *)malloc(sizeof(int) * (n + 1));
	u->size = (int *)malloc(sizeof(int) * (n + 1));//节点个数初始化 
	u->n = n;
	for (int i = 1; i <= n; i++) {
		u->father[i] = i;
		u->size[i] = 1;//每一棵树初始的节点个数为1 
	}
	return u;
} 

//查找函数
int find(UnionSet *u, int x) {
	if (u->father[x] == x) return x;
	return find(u, u->father[x]);
} 

//合并操作 
int merge(UnionSet *u, int a, int b) {
	int fa = find(u, a), fb = find(u, b);
	if (fa == fb) return 0;
	if (u->size[fa] > u->size[fb]) {//判断两个节点对应子树节点个数大小 
		u->father[fb] = fa;//把节点个数少的接在节点个数多的树后面 
		u->size[fa] += u->size[fb];//修改新生成子树的节点个数 
	} else {
		u->father[fa] = fb;//反之亦然 
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
 
 

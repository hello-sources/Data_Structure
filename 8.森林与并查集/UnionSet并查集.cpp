//quick_find算法 
#include <stdio.h>
#include <stdlib.h>

//并查集结构定义 
typedef struct UnionSet {
	int *color;//定义指向颜色的变量,进行染色 
	int n;//元素个数 
} UnionSet;

//并查集初始化,返回值为指针类型 
UnionSet *init(int n) {//n代表数据域大小 
	UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
	u->color = (int *)malloc(sizeof(int) * (n + 1));//颜色域初始化 
	u->n = n;//并查集数据域大小 
	for (int i = 1; i <= n; i++) {
		u->color[i] = i;//初始化给每一个数分配一个颜色 
	}
	return u;
} 

//查找函数,传入x指的是返回x的颜色 
int find(UnionSet *u, int x) {
	return u->color[x];
} 

//合并(联通)操作 
int merge(UnionSet *u, int a, int b) {//传入并查集,以及a, b表示联通两个数 
	if (find(u, a) == find(u, b)) return 0;//如果两个色相同,不需要合并 
	int color_a = u->color[a];//合并方法就是把a的颜色改为b的颜色,但是要注意a的颜色是会改变的 
	//我们先定义一个遍历来存储a的颜色,避免后面被覆盖掉 
	for (int i = 1; i <= u->n; i++) {
		if (u->color[i] - color_a) continue; 
		u->color[i] = u->color[b];
	}
	return 1;
}

void clear(UnionSet *u) {
	if (u == NULL) return ;
	free(u->color);
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
 
 

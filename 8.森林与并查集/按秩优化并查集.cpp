//����·���Ż�weighted quick_union�㷨 
#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
	int *father, *size;//���Ǽ�¼ÿ�������ڵ���� 
	int n;//Ԫ�ظ��� 
} UnionSet;

//���鼯��ʼ��
UnionSet *init(int n) {
	UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
	u->father = (int *)malloc(sizeof(int) * (n + 1));
	u->size = (int *)malloc(sizeof(int) * (n + 1));//�ڵ������ʼ�� 
	u->n = n;
	for (int i = 1; i <= n; i++) {
		u->father[i] = i;
		u->size[i] = 1;//ÿһ������ʼ�Ľڵ����Ϊ1 
	}
	return u;
} 

//���Һ���
int find(UnionSet *u, int x) {
	if (u->father[x] == x) return x;
	return find(u, u->father[x]);
} 

//�ϲ����� 
int merge(UnionSet *u, int a, int b) {
	int fa = find(u, a), fb = find(u, b);
	if (fa == fb) return 0;
	if (u->size[fa] > u->size[fb]) {//�ж������ڵ��Ӧ�����ڵ������С 
		u->father[fb] = fa;//�ѽڵ�����ٵĽ��ڽڵ������������� 
		u->size[fa] += u->size[fb];//�޸������������Ľڵ���� 
	} else {
		u->father[fa] = fb;//��֮��Ȼ 
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
 
 

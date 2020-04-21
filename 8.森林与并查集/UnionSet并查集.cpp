//quick_find�㷨 
#include <stdio.h>
#include <stdlib.h>

//���鼯�ṹ���� 
typedef struct UnionSet {
	int *color;//����ָ����ɫ�ı���,����Ⱦɫ 
	int n;//Ԫ�ظ��� 
} UnionSet;

//���鼯��ʼ��,����ֵΪָ������ 
UnionSet *init(int n) {//n�����������С 
	UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
	u->color = (int *)malloc(sizeof(int) * (n + 1));//��ɫ���ʼ�� 
	u->n = n;//���鼯�������С 
	for (int i = 1; i <= n; i++) {
		u->color[i] = i;//��ʼ����ÿһ��������һ����ɫ 
	}
	return u;
} 

//���Һ���,����xָ���Ƿ���x����ɫ 
int find(UnionSet *u, int x) {
	return u->color[x];
} 

//�ϲ�(��ͨ)���� 
int merge(UnionSet *u, int a, int b) {//���벢�鼯,�Լ�a, b��ʾ��ͨ������ 
	if (find(u, a) == find(u, b)) return 0;//�������ɫ��ͬ,����Ҫ�ϲ� 
	int color_a = u->color[a];//�ϲ��������ǰ�a����ɫ��Ϊb����ɫ,����Ҫע��a����ɫ�ǻ�ı�� 
	//�����ȶ���һ���������洢a����ɫ,������汻���ǵ� 
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
 
 

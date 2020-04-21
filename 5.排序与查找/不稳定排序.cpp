#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//����ʹ���ֻ�ʵ�ֽ���������
//�ֻ����������ֵ��ͬ���ǵ�ַ��ͬ�Ŀ���ʵ�ֽ���
//���Ƕ�����ͬ��ַ�Ĳ����Խ��н�������ͬ��ַ�ֻ�Ľ��Ϊ0 
#define swap(a, b) {\
	a ^= b; b ^= a; a ^= b;\
}
//�������⣻������ͬ��ַ���߲�ͬ��ַʹ���ֻ������ 

//�궨����ʵ�ֲ�ͬ�����㷨���Ͻ������
//����ʹ�õ��Ǳ�κ���args����ʾ��ͬ�����㷨����Ĳ���
//�ڽ���������ʱ��Ҫ�ͷ���Ӧ�ռ� 
#define TEST(arr, n, func, args...) {\
	int *num = (int *)malloc(sizeof(int) * n);\
	memcpy(num, arr, sizeof(int) * n);\
	output(num, n);\
	printf("%s = ", #func);\
	func(args);\
	output(num, n);\
	free(num);\
}

//ѡ������ 
void select_sort(int *num, int n) {
	for (int i = 0; i < n - 1; i++) {
		int ind = i;//ѡ��һ����׼ֵ�±� 
		for (int j = i + 1; j < n; j++) {//�±������б�����
		//�ҵ��ȵ�ǰ�±�ֵС���������������±� 
			if (num[ind] > num[j]) ind = j;
		}
		//һ��ѭ���������±��ʾ���ǵ�ǰ��С��Ԫ�أ���������λ�� 
		if (i == ind)continue; 
		swap(num[i], num[ind]);
	}
	return ;
}

//��������
//��������ָ�룬һ��ָ������ͷ��һ��ָ��β 
void quick_sort(int *num, int l, int r) { 
	if (r < l) return ;
	int x = l, y = r, z = num[l];//����һ����׼ֵ 
	while (x < y) {//����ָ�벻ָ��һ��λ�õ�ʱ�����ѭ�� 
		//��Ӧβ��ָ����ǰ�ƶ����ҵ��Ȼ�׼ֵС��Ԫ���±� 
		while (x < y && num[y] >= z) y--;
		if (x < y) num[x++] = num[y];//���� 
		//��Ӧͷ��ָ������ƶ����ҵ��Ȼ�׼ֵ���Ԫ���±� 
		while (x < y && num[x] <= z) x++;
		if (x < y) num[y--] = num[x];
	} 
	num[x] = z;
	quick_sort(num, l ,x - 1);//������벿�ֽ��п������� 
	quick_sort(num, x + 1, r);//�����Ұ벿�ֽ��п������� 
	return ;
} 
//�������⣺���Ե�һ���ڵ�Ϊ��׼ֵ�����Ǵ��м���д��� 
//���������ǳ��Դ��м���д���ʱ�临�Ӷ�ΪO(nlogn)�ˣ���������O(n^2) 
void quick_sort1(int *num, int l, int r) { 
	while (l < r) {
		int x = l, y = r, z = num[(l + r) >> 1];
		do {
			while (x <= y && num[x] < z) x++;
			while (x <= y && num[y] > z) y--;
			if (x <= y) {
				swap(num[x], num[y]);
				x++, y--;
			}
		} while (x <= y);
		quick_sort(num, x, r);
		r = y;
	} 
} 

//��ʼ��һ��������� 
void randint(int *arr, int n) {
	while (n--) arr[n] = rand() % 100;
}

void output(int *num, int n) {
	printf("[");
	for (int i = 0; i < n; i++) {
		printf(" %d", num[i]);
	}
	printf("]\n");
	return ;
}

int main() {
	srand(time(0));
	#define max_op 20
	int arr[max_op];
	randint(arr, max_op);
	TEST(arr, max_op, select_sort, num, max_op);
	TEST(arr, max_op, quick_sort, num, 0, max_op - 1);

	return 0;
}

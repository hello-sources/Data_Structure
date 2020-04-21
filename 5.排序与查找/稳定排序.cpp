#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>

//�������Ƕ��彻������������ʹ���ֻ���ʵ���������Ľ��� 
#define swap(a, b) {\
	a ^= b; b ^= a; a ^= b;\
}
 
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

//���������Ѿ�����������ǰ����ǰ�����������������С�ͽ���λ�� 
void insert(int *num, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
			swap(num[j], num[j - 1]);
		}
	}
	return ;
}

//ð�����������������ں� 
void bubble_sort(int *num, int n) {
	int times = 1;//��ʼ���λ��Ϊ1 
	//�Ż�����ʹ�ñ��λ�����ж϶�Ӧ�������Ƿ��Ѿ�����˳�� 
	for (int i = 1; i < n && times; i++) {
		times = 0;
		for (int j = 0; j < n - i; j++) {
			if (num[j] <= num[j + 1]) continue;//ʹ�ö�ż�߼����Ż����� 
			swap(num[j], num[j + 1]);//��������С��ǰ��������ͽ�����������λ�� 
			times++;//���¶�Ӧ�ı��λ 
		}
	}
	return ;
} 

//�鲢����
void merge_sort(int *num, int l, int r) {
	if (r - l <= 1) {//�����ж϶�Ӧ����Ԫ�ش�С���С�������� 
		if (r - l == 1 && num[l] > num[r]) {
			swap(num[l], num[r]);//����������λ�� 
		}
		return ;//ֱ�ӷ��ؼ��� 
	}
	//��·�鲢�����м俪ʼ 
	int mid = (l + r) >> 1; 
	merge_sort(num, l, mid);//�ݹ�ѭ����벿�� 
	merge_sort(num, mid + 1, r);//�ֱ�������˽�������
	int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
	//���Ƕ������������ֱ���������������ʼλ�ÿ�ʼ 
	int p1 = l, p2 = mid + 1, k = 0;
	while (p1 <= mid || p2 <= r) {//��һ�����Ƚ�С�Ͱѽ�С������ֵ����ʱ���ٵ����� 
		if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
			temp[k++] = num[p1++];
		} else {
			temp[k++] = num[p2++];
		}
	} 
	memcpy(num + l, temp, sizeof(int) * (r - l + 1));//����ʱ�洢�����ݿ�����ԭ�������� 
	free(temp);//�ͷ���ʱ���ٵĿռ� 
	return ;
} 

//ʵ���������
void randint(int *arr, int n) {
	while (n--) arr[n] = rand() % 100;
	return ;
} 

//������� 
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
	randint(arr, max_op);//��ʼ��һ��������� 
	TEST(arr, max_op, insert, num, max_op);//�������� 
	TEST(arr, max_op, bubble_sort, num, max_op);//ð������ 
	TEST(arr, max_op, merge_sort, num, 0, max_op - 1);//�鲢���� 
	return 0;
}

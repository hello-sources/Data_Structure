#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define P(func, args...) {\
	printf("%s = %d\n", #func, func(args));\
}

//һ�����1��1, 3, 7, 9, 10
int binary_search1(int *num, int n, int x) {
	//������������Ƕ��Ƕ���һ��ͷָ���βָ�뻹���м�λ��ָ��
	//ÿһ�ΰ��м�λ����ͷָ���βָ������λ�õ������бȽ�Ȼ����� 
	int head = 0, tail = n - 1, mid;
	while (head <= tail) {
		mid = (head + tail) >> 1;
		if (num[mid] == x) return  mid;//��ȱ�ʾֱ�Ӳ��ҵ� 
		if (num[mid] < x) head = mid + 1;//����м�λ��С��ͷָ������λ�ø���ͷָ�� 
		else tail = mid - 1;//�������βָ�� 
	}
	return -1;
} 

//�������2 1111111100000000
int binary_search2(int *num, int n) {
	int head = -1, tail = n - 1, mid;//����ǰ�涼��1��������Ҫʵ������ͷָ��
	while (head < tail) {
		mid = (head + tail + 1) >> 1;
	//Ϊ�˱�����ѭ������Ϊ�ƶ��������ǲ��ҵ���ʱ��һֱ����haed = mid 
		if (num[mid] == 1) head = mid; //�������1���Ͱ�ͷָ�����Ϊ��ǰ���м�ָ�� 
		else tail = mid - 1; //�����Ϊ0�Ͱ�βָ�����Ϊmidǰһ�� 
	} 
	return head;
} 

//�������3��00000000000000011111111111���ҵ�һ��1 
int binary_search3(int *num, int n) {
	int head = 0, tail = n, mid;//���Ǵ�0��λ�ÿ�ʼ��βָ�������Ϊn 
	while (head < tail) {
		mid = (head + tail) >> 1;//�������м�λ��ָ��ʱ��ֱ��Ϊͷ��β�ٳ��Զ� 
		if (num[mid] == 1) tail = mid;//�Ǿ͸���β�ڵ� 
		else head = mid + 1;//ͷ�ڵ����Ϊ�м�ڵ�����һλ 
	}
	return head == n ? -1 : head;
} 

int main() {
	int arr1[10] = {1, 3, 5 ,7 ,9, 11, 13, 17, 19, 23};
	int arr2[10] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
	int arr3[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
	P(binary_search1, arr1, 10, 7);
	P(binary_search2, arr2, 10); 
	P(binary_search3, arr3, 10);
	return 0;
}

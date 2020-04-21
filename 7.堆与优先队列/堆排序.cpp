#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//ʵ�ֽ����������ݵĺ궨�� 
#define swap(a, b) {\
	__typeof(a) __temp = a;\
	a = b; b = __temp;\
}

//�������½��е����� 
void downUpdate(int *arr, int n, int ind) {
	while ((ind << 1) <= n) {//��ʾ�������ڣ��ͼ������� 
		int temp = ind, l = ind << 1, r = ind << 1 | 1;//l��ʾ�������� r��ʾ������ 
		if (arr[l] > arr[temp]) temp = l;//�����������Ӧ��ֵ���ڵ�ǰ���ڵ��ֵ�������ڵ�λ�� 
		if (r <= n && arr[r] > arr[temp]) temp = r;//�����������ֵ���ڸ��ڵ��ֵ������λ�� 
		if (temp == ind) break;//����ӵ�ǰλ�����¶��������� 
		swap(arr[temp], arr[ind]);//������Ӧλ�õ�ֵ 
		ind = temp; //��������һ���ڵ� 
	}
	return ;
}

//�����򣬴������飬�����鳤�� 
void heap_sort(int *arr, int n) {
	arr -= 1;//arr[0]�����з��� 
	for (int i = n >> 1;i >= 1; i--) {
		downUpdate(arr, n, i);//��ǰ���λ�����µ��������Խ��Ѳ���
		//��һ�����еĸ��ڵ㣬�ų�һ���󶥶�
		//�ӵ����ڶ��㿪ʼ 
	}
	for (int i = n; i > 1; i--) {
		swap(arr[i], arr[1]);
		downUpdate(arr, i - 1, 1);//���������ڵ� 
	}
	return ;
}

void output(int *arr, int n) {
	printf("arr(%d) = [", n);
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
	printf("]\n");
	return ;
}

int main() {
	srand(time(0));
	#define max_op 20
	int *arr = (int *)malloc(sizeof(int) * max_op);
	for (int i = 0; i < max_op; i++) {
		int val = rand() % 100;
		arr[i] = val;
	}
	output(arr, max_op);
	heap_sort(arr, max_op);
	output(arr, max_op);
	free(arr);
	
	return 0;
} 

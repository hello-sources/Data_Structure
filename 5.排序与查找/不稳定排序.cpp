#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//可以使用抑或实现交换函数，
//抑或对于两个数值相同但是地址不同的可以实现交换
//但是对于相同地址的不可以进行交换，相同地址抑或的结果为0 
#define swap(a, b) {\
	a ^= b; b ^= a; a ^= b;\
}
//遗留问题；对于相同地址或者不同地址使用抑或的问题 

//宏定义来实现不同排序算法整合进行输出
//我们使用的是变参函数args来表示不同排序算法传入的参数
//在结束函数的时候，要释放相应空间 
#define TEST(arr, n, func, args...) {\
	int *num = (int *)malloc(sizeof(int) * n);\
	memcpy(num, arr, sizeof(int) * n);\
	output(num, n);\
	printf("%s = ", #func);\
	func(args);\
	output(num, n);\
	free(num);\
}

//选择排序 
void select_sort(int *num, int n) {
	for (int i = 0; i < n - 1; i++) {
		int ind = i;//选择一个基准值下标 
		for (int j = i + 1; j < n; j++) {//下标向后进行遍历，
		//找到比当前下标值小的数，交换两个下标 
			if (num[ind] > num[j]) ind = j;
		}
		//一个循环下来，下标表示的是当前最小的元素，交换两个位置 
		if (i == ind)continue; 
		swap(num[i], num[ind]);
	}
	return ;
}

//快速排序
//传入两个指针，一个指向数组头，一个指向尾 
void quick_sort(int *num, int l, int r) { 
	if (r < l) return ;
	int x = l, y = r, z = num[l];//定义一个基准值 
	while (x < y) {//左右指针不指向一个位置的时候继续循环 
		//对应尾部指针向前移动，找到比基准值小的元素下标 
		while (x < y && num[y] >= z) y--;
		if (x < y) num[x++] = num[y];//放在 
		//对应头部指针向后移动，找到比基准值大的元素下标 
		while (x < y && num[x] <= z) x++;
		if (x < y) num[y--] = num[x];
	} 
	num[x] = z;
	quick_sort(num, l ,x - 1);//对于左半部分进行快速排序 
	quick_sort(num, x + 1, r);//对于右半部分进行快速排序 
	return ;
} 
//遗留问题：不以第一个节点为基准值，而是从中间进行处理 
//下面代码就是尝试从中间进行处理，时间复杂度为O(nlogn)了，不会出现最坏O(n^2) 
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

//初始化一个随机数组 
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

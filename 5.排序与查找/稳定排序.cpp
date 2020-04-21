#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>

//这里我们定义交换函数，我们使用抑或来实现两个数的交换 
#define swap(a, b) {\
	a ^= b; b ^= a; a ^= b;\
}
 
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

//插入排序，已经排序数组在前，从前到后遍历，如果后面的小就交换位置 
void insert(int *num, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
			swap(num[j], num[j - 1]);
		}
	}
	return ;
}

//冒泡排序，已排序数组在后 
void bubble_sort(int *num, int n) {
	int times = 1;//初始标记位置为1 
	//优化方案使用标记位，来判断对应的数组是否已经满足顺序 
	for (int i = 1; i < n && times; i++) {
		times = 0;
		for (int j = 0; j < n - i; j++) {
			if (num[j] <= num[j + 1]) continue;//使用对偶逻辑来优化代码 
			swap(num[j], num[j + 1]);//如果后面的小于前面的数，就交换两个数的位置 
			times++;//更新对应的标记位 
		}
	}
	return ;
} 

//归并排序
void merge_sort(int *num, int l, int r) {
	if (r - l <= 1) {//首先判断对应数组元素大小如果小于两个数 
		if (r - l == 1 && num[l] > num[r]) {
			swap(num[l], num[r]);//交换；两个位置 
		}
		return ;//直接返回即可 
	}
	//二路归并，从中间开始 
	int mid = (l + r) >> 1; 
	merge_sort(num, l, mid);//递归循环左半部分 
	merge_sort(num, mid + 1, r);//分别对于两端进行排序
	int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
	//我们定义两个变量分别从左右两个数组初始位置开始 
	int p1 = l, p2 = mid + 1, k = 0;
	while (p1 <= mid || p2 <= r) {//哪一个数比较小就把较小的数赋值给暂时开辟的数组 
		if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
			temp[k++] = num[p1++];
		} else {
			temp[k++] = num[p2++];
		}
	} 
	memcpy(num + l, temp, sizeof(int) * (r - l + 1));//把暂时存储的数据拷贝给原来的数组 
	free(temp);//释放暂时开辟的空间 
	return ;
} 

//实现随机数组
void randint(int *arr, int n) {
	while (n--) arr[n] = rand() % 100;
	return ;
} 

//输出数组 
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
	randint(arr, max_op);//初始化一个随机数组 
	TEST(arr, max_op, insert, num, max_op);//插入排序 
	TEST(arr, max_op, bubble_sort, num, max_op);//冒泡排序 
	TEST(arr, max_op, merge_sort, num, 0, max_op - 1);//归并排序 
	return 0;
}

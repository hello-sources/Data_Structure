#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//实现交换连个数据的宏定义 
#define swap(a, b) {\
	__typeof(a) __temp = a;\
	a = b; b = __temp;\
}

//自上向下进行调整堆 
void downUpdate(int *arr, int n, int ind) {
	while ((ind << 1) <= n) {//表示子树存在，就继续调整 
		int temp = ind, l = ind << 1, r = ind << 1 | 1;//l表示左子树， r表示右子树 
		if (arr[l] > arr[temp]) temp = l;//如果左子树对应的值大于当前父节点的值，交换节点位置 
		if (r <= n && arr[r] > arr[temp]) temp = r;//如果右子树的值大于父节点的值，交换位置 
		if (temp == ind) break;//如果从当前位置往下都满足性质 
		swap(arr[temp], arr[ind]);//交换对应位置的值 
		ind = temp; //调整到下一个节点 
	}
	return ;
}

//堆排序，传入数组，跟数组长度 
void heap_sort(int *arr, int n) {
	arr -= 1;//arr[0]不进行访问 
	for (int i = n >> 1;i >= 1; i--) {
		downUpdate(arr, n, i);//当前这个位置向下调整，线性建堆操作
		//走一遍所有的父节点，排成一个大顶堆
		//从倒数第二层开始 
	}
	for (int i = n; i > 1; i--) {
		swap(arr[i], arr[1]);
		downUpdate(arr, i - 1, 1);//继续调整节点 
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

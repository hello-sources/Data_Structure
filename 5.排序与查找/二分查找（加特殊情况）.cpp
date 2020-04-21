#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define P(func, args...) {\
	printf("%s = %d\n", #func, func(args));\
}

//一般情况1：1, 3, 7, 9, 10
int binary_search1(int *num, int n, int x) {
	//正常情况下我们都是定义一个头指针跟尾指针还有中间位置指针
	//每一次把中间位置与头指针和尾指针所在位置的数进行比较然后更新 
	int head = 0, tail = n - 1, mid;
	while (head <= tail) {
		mid = (head + tail) >> 1;
		if (num[mid] == x) return  mid;//相等表示直接查找到 
		if (num[mid] < x) head = mid + 1;//如果中间位置小于头指针所在位置更新头指针 
		else tail = mid - 1;//否则更新尾指针 
	}
	return -1;
} 

//特殊情况2 1111111100000000
int binary_search2(int *num, int n) {
	int head = -1, tail = n - 1, mid;//由于前面都是1，我们需要实现虚拟头指针
	while (head < tail) {
		mid = (head + tail + 1) >> 1;
	//为了避免死循环，因为移动规则当我们查找到的时候，一直就是haed = mid 
		if (num[mid] == 1) head = mid; //如果等于1，就把头指针更新为当前的中间指针 
		else tail = mid - 1; //如果不为0就把尾指针更新为mid前一个 
	} 
	return head;
} 

//特殊情况3：00000000000000011111111111中找第一个1 
int binary_search3(int *num, int n) {
	int head = 0, tail = n, mid;//我们从0号位置开始，尾指针从设置为n 
	while (head < tail) {
		mid = (head + tail) >> 1;//在设置中间位置指针时候，直接为头加尾再除以二 
		if (num[mid] == 1) tail = mid;//是就更新尾节点 
		else head = mid + 1;//头节点更新为中间节点右移一位 
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

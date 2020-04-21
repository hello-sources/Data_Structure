#include <stdio.h>
#include <stdlib.h>
 
#define swap(a, b) {\
	a ^= b; b ^= a; a ^= b;\
}

int binary_search(int *num, int n, int value) {
	int head = -1, tail = n - 1, mid;
	while (head < tail) {
		mid = (head + tail + 1) >> 1;
		if (num[mid] == value) return mid;
		if (num[mid] < value) head = mid;
		else tail = mid - 1;
	}
	return head;
}

void insert(int *num, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
			swap(num[j], num[j - 1]);
		}
	}
	return ;
}

int main() {
	int n, m, x;
	scanf("%d %d", &n, &m);
	int *num = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		num[i] = x;
	} 
	insert(num, n);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		if (binary_search(num, n ,x) == -1) {
			printf("%d", num[0]);
		} else {
			printf("%d", num[binary_search(num, n, x)]);
		}
		(i < m - 1) && printf(" ");
	}
	
	return 0;
} 

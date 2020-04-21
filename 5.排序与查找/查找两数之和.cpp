#include <stdio.h>
#include <stdlib.h>
 
int binary_search(int *num, int n, int value) {
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (num[mid] == value) return mid;
		if (num[mid] < value) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

int main() {
	int n, value, m;
	scanf("%d", &n);
	int *num = (int *)malloc(sizeof(int) * (n + 1));
	num[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&m);
		num[i] = m;
	}	
	scanf("%d", &value);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (num[i] + num[j] != value) continue;
			printf("%d %d", i, j);
		}
	}
	
	return 0;
} 

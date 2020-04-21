#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main() {
	int n, m;
	scanf("%d", &n);
	int *num = (int *)malloc(sizeof(int) * (n + 1));
	memset(num, 0, sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		if (m > 0) num[m] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (num[i] != 0) continue;
		printf("%d", i);
		break;
	} 
	return 0;
}

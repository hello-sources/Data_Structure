#include <stdio.h>

#define swap(a, b) {\
	a ^= b; b ^= a; a ^= b;\
}
int main() {
	int a;
	scanf("%d", &a);
	swap(a, a);
	printf("%d", a);
	return 0;
} 

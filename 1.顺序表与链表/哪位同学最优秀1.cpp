#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
	int *data;
	int size, length;
} Vector;

Vector *init(int n) {
	Vector *vec = (Vector *)malloc(sizeof(Vector));	
	vec->data = (int *)malloc(sizeof(int) * n);
	vec->length = 0;
	vec->size = n;
	return vec;
}

int expand(Vector *vec) {
	if (vec == NULL) return 0;
	int extr_size = vec->size;
	int *p;
	while (extr_size) {
		p = (int *)realloc(vec->data, sizeof(int) * (vec->size + extr_size));
		if (p) break;
		extr_size /= 2;
	}
	if (p == NULL) return 0;
	vec->data = p;
	vec->size += extr_size;
	return 1;
}

int insert(Vector *vec, int ind, int val) {
	if (vec == NULL) return 0;
	if (ind < 0 || ind > vec->length) return 0;
	if (vec->length == vec->size) {
		if (!expand(vec)) return 0;
	}	
	for (int i = vec->length; i > ind; i--) {
		vec->data[i] = vec->data[i - 1];
	}
	vec->data[ind] = val;
	vec->length += 1;
	return 1;
}

int erase(Vector *vec, int ind) {
	if (vec == NULL) return 0;
	if (ind < 0 || ind >= vec->length) return 0;
	for (int i = ind + 1; i < vec->length; i++) {
		vec->data[i - 1] = vec->data[i];
	}	
	vec->length -= 1;
	return 1;
}

void output(Vector *vec) {
	for (int i = 0; i < vec->length; i++) {
		printf("%d ", vec->data[i]);
	}
	printf("\n");
	return ;
}

void clear(Vector *vec) {
	if (vec == NULL) return ;
	free(vec->data);
	free(vec);
	return ;	
}

int main() {
	Vector *vec = init(1);
	int n, m, x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		insert(vec, i, i);
		//printf("%d ", vec->data[i]);
	} 
	//printf("\n"); 
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		erase(vec, x - 1);
		//output(vec);
	//printf("\n"); 
	}
	//output(vec);
	int num = vec->length  / 2;
	printf("%d", vec->data[num] + 1);
	clear(vec);
	return 0;
}

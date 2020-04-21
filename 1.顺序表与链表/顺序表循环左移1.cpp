#include <stdio.h>
#include <stdlib.h> 

typedef struct Vector{
	int *data;
	int size, length;
} Vector; 

Vector *init(int n) {
	Vector *vec = (Vector *)malloc(sizeof(Vector));
	vec->data = (int *)malloc(sizeof(int) * n);
	vec->size = n;
	vec->length = 0;
	return vec; 
}

int expand(Vector *vec) {
	int extr_size = vec->size;
	int *p;
	while (extr_size) {
		p = (int *)realloc(vec->data, sizeof(int) *(vec->size + extr_size));
		if (p) break;
		extr_size /= 2;
	}
	if (p == NULL) return 0;
	vec->data = p;
	vec->size += extr_size;
	return 1; 	
}

int insert(Vector *vec, int ind, int val) {
	if (ind < 0 || ind > vec->length) return 0;
	if (vec->length == vec->size) {
		if (!expand(vec)) return 0;
	}	
	for (int i = vec->length; i > ind; i++) {
		vec->data[i] = vec->data[i - 1];
	}
	vec->data[ind] = val;
	vec->length += 1;
	return 1;
}

int erase(Vector *vec, int ind) {
	if (ind < 0 || ind >= vec->length) return 0;
	for (int i = ind + 1; i <vec->length; i++) {
		vec->data[i - 1] = vec->data[i];
	} 
	vec->length -= 1;
	return 1;
}

int left_move(Vector *vec, int ind, int size) {
	if (ind < 0 || ind > vec->length) return 0;
	int temp[100] = {0}, j = 0;
	for (int i = ind; i < vec->length; i++) {
		temp[j++] = vec->data[i];
	}	
	for (int i = 0; i < ind; i++) {
		temp[j++] = vec->data[i];
	}
	for (int i = 0; i < vec->length; i++) {
		vec->data[i] = temp[i];
	}
	return 1;
}

void output(Vector *vec) {
	for (int i = 0; i < vec->length; i++) {
		printf("%d", vec->data[i]);
		if (i < vec->length - 1) printf(" ");
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
	int m, n, val;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		scanf("%d", &val);
		insert(vec, i, val);
	}
	left_move(vec, n, m);
	output(vec);
	clear(vec);
	return 0;
} 

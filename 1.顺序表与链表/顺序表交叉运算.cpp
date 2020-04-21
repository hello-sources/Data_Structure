#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
	int size, length;
	int *data;
} Vector;

Vector *init(int n) {
	Vector *vec = (Vector *)malloc(sizeof(Vector));
	vec->data = (int *)malloc(sizeof(int) * n);
	vec->length = 0;
	vec->size = n;
	return vec;
}

int expand(Vector *vec) {
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

void output(Vector *vec) {
	printf("%d\n", vec->length);
	for (int i = 0; i < vec->length; i++) {
		printf("%d", vec->data[i]);
		if(i < vec->length - 1) printf(" ");
	}
	printf("\n");
	return ;
}

void calc(Vector *vec1, Vector *vec2, Vector *vec3) {
	int i = 0, j = 0, k = 0;
	while (i < vec1->length && j < vec2->length) {
		if (vec1->data[i] < vec2->data[j]) {
			i++;
		} else if (vec1->data[i] > vec2->data[j]) {
			j++;
		} else {
			insert(vec3, k++, vec1->data[i]);
			i++, j++;
		}
	}
	return ;	
}

void clear(Vector *vec) {
	free(vec->data);
	free(vec);
	return ;
}

int main() {
	Vector *vec1 = init(1);
	Vector *vec2 = init(1);
	Vector *vec3 = init(2);
	int m, n, x, y;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &n);
		insert(vec1, i, n);
		//printf("%d ", vec1->data[i]); 
	}
	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		scanf("%d", &y);
		insert(vec2, i, y);
		//printf("%d ", vec2->data[i]);
	}
	calc(vec1, vec2, vec3);
	output(vec3);
	clear(vec1);
	clear(vec2);
	clear(vec3);
	return 0;
}

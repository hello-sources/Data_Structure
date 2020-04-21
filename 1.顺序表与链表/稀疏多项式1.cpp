#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
typedef struct Data {
	int c, e;
} Data;

typedef struct Vector {
	int size, length;
	Data *data;
} Vector;

Vector *init(int n) {
	Vector *vec = (Vector *)malloc(sizeof(Vector));
	vec->data = (Data *)malloc(sizeof(Data) * n);
	vec->size = n;
	vec->length = 0;
	return vec;
}

int expand(Vector *vec){
	int extr_size = vec->size;
	Data *p;
	while (extr_size) {
		p = (Data *)realloc(vec->data, vec->size * sizeof(Data));
		if (p) break;
		extr_size /= 2; 
	}	
	if (p == NULL) return 0;
	vec->data = p;
	vec->size += extr_size;
	return 1;
}

int insert(Vector *vec, int ind, Data val) {
	if (ind < 0 || ind > vec->length) return  0;
	if (vec->length == vec->size) {
		if(!expand(vec)) return 0;
	}
	for (int i = vec->length; i > ind; i--) {
		vec->data[i] = vec->data[i - 1];
	}
	vec->data[ind] = val;
	vec->length += 1;
	return 1;
}

void output(Vector *vec,int x) {
	int result = 0;
	for (int i = 0; i < vec->length; i++) {
		result += vec->data[i].c * (int)pow(x, vec->data[i].e);
	}
	printf("%d\n", result);
}

void clear(Vector *vec) {
	free(vec->data);
	free(vec);
}

int main() {
	Data data;
	int m, n;
	scanf("%d", &m);
	Vector *vec = init(m); 
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &data.c, &data.e);
		insert(vec, i, data);
	}
	scanf("%d", &n);
	output(vec, n);
	clear(vec);
	return 0;
} 

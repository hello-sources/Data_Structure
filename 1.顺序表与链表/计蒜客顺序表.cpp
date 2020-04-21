#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
	int *data;
    int size, length;
} Vector;

void init(Vector *vec, int n) {
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
}

void expand(Vector *vector) {
	// int extr_size = vec->size;
	// int *p;
	// while (extr_size) {
	// 	p = (int *)realloc(vec->data, sizeof(int) * (vec->size + extr_size));
	// if (p) break;
	// extr_size /= 2;
	// }
	// if (p == NULL) return ;
	// vec->data = p;
	// vec->size += extr_size;
	// return ;
    int *old_data = vector->data;
    vector->size = vector->size * 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
}

int insert(Vector *vector, int loc, int value) {
	// if (val == NULL) return ERROR;
	// if (ind < 0 || ind > vec->length) return ERROR;
	// if (vec->length >= vec->size) {
	// expand(vec);
	// printf("expand\n");
	// }
	// for (int i = vec->length; i > ind; i--) {
	// 	vec->data[i] = vec->data[i - 1];
	// }
	// vec->data[ind] = val;
	// vec->length += 1;
	// return OK;
    if (loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if (vector->length >= vector->size) {
        //return ERROR;
        expand(vector);
        printf("expand\n");
    }
    for (int i = vector->length; i > loc; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    return OK;
}

int search(Vector *vector, int value) {
    for (int i = 0; i < vector->length; ++i) {
        if (vector->data[i] == value) {
            return i;
        }
    }
    return -1;
}

int delete_node(Vector *vector, int index) {
    if (index < 0 || index >= vector->length) {
        return ERROR;
    }
    for (int i = index + 1; i < vector->length; ++i) {
        vector->data[i - 1] = vector->data[i];
    }
    vector->length = vector->length - 1;
    return OK;
}

void print(Vector *vector) {
    for (int i = 0; i < vector->length; i++) {
		if (i > 0) {
			printf(" ");
    	}
        printf("%d", vector->data[i]);
	}
    printf("\n");
}

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 5);
	int n, n1, n2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
		scanf("%d %d", &n1, &n2);
        if (insert(a, n1, n2)) printf("success\n");
    	else printf("failed\n");
    }
    clear(a);
    return 0;
}

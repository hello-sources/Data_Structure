/*************************************************************************
	> File Name: Vector.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 31 Oct 2020 07:36:43 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vector {
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

int insert(Vector *vec, int ind, int val) {
    if (vec == NULL) return 0;
    if (ind < 0 || ind > vec->length) return 0;
    if (vec->length == vec->size) return 0;
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
    printf("Vector(%d) = [", vec->length);
    for (int i = 0; i < vec->length; i++) {
        i && printf(", ");
        printf("%d",  vec->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(Vector *vec) {
    if (vec == NULL) return ;
    free(vec->data);
    free(vec);
    return ;
    
}

int main() {
    srand(time(0));
    #define max_op 20
    Vector *vec = init(max_op);
    int op, ind, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 2;
        int ind = rand() % (vec->length + 1); 
        val = rand() % 100;
        switch (op) {
            case 0 : {
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(vec, ind, val));
            } break;
            case 1 : {
                printf("erase item at %d from Vector = %d\n", ind, erase(vec, ind));    
            } break;
        }
        output(vec);
        printf("\n");
    }
    clear(vec);
    return 0;
}

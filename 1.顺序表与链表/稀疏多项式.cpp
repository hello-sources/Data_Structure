#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define ERROR 0
#define OK 1
 
typedef struct {
    int c, e;
} Data;
 
typedef struct {
    int size, length;
    Data *data;
} Vector;
 
int init(Vector *vec, int size) {
    vec->size = size;
    vec->data = (Data *)malloc(sizeof(Data) * size);
    if (vec->data == NULL) {
        return ERROR;
    }
    vec->length = 0;
    return OK;
}
 
void expand(Vector *vec) {
    vec->size *= 2;
    vec->data = (Data *)realloc(vec->data, vec->size * sizeof(Data));
    return ;
}
 
int insert(Vector *vec, int loc, Data value) {
    if (loc < 0 || loc > vec->length) {
        return ERROR;
    }
    if (vec->length == vec->size) {
        expand(vec);
    }
    for (int i = vec->length; i > loc; --i) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[loc] = value;
    vec->length++;
    return OK;
}
 
void output(Vector *vec, int x) {
    int ret = 0;
    for (int i = 0; i < vec->length; ++i) {
        ret += vec->data[i].c * (int)pow(x, vec->data[i].e);
    }
    printf("%d\n", ret);
}
 
void clear(Vector *vec) {
    free(vec->data);
    free(vec);
}
 
int main() {
    Data data;
    int m, x;
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    scanf("%d", &m);
    init(vec, m);
    for (int i = 0; i< m; ++i) {
        scanf("%d%d", &data.c, &data.e);
        insert(vec, i, data);
    }
    scanf("%d", &x);
    output(vec, x);
    clear(vec);
    return 0;
}

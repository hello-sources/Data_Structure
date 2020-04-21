//name : 1.Vector.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//数据结构 = 结构定义 + 结构操作 

typedef struct Vector {
	int *data;
	int size, length;
} Vector;

//返回值是顺序表指针,顺序表的初始化 
Vector *init(int n) {
	Vector *vec = (Vector *)malloc(sizeof(Vector));
	vec->data = (int *)malloc(sizeof(int) * n);	
	vec->size = n;
	vec->length = 0;
	return vec; 
}

//扩容操作 
int expand(Vector *vec) {
	int  extr_size = vec->size;
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

//插入操作
int insert(Vector *vec, int ind, int val) {
	if (vec == NULL) return 0;
	if (ind < 0 || ind > vec->length) return 0;
	if (vec->length == vec->size) {
		if (!expand(vec)) return 0;
		printf("expand successfully! size = %d\n", vec->size);
	}
	for (int i = vec->length; i > ind; i--) {
		vec->data[i] = vec->data[i - 1]; 
	}
	vec->data[ind] = val;
	vec->length += 1;
	return 1;
} 

//顺序表的删除
int erase(Vector *vec, int ind) {
	if (vec == NULL) return 0;
	if (ind < 0 || ind >= vec->length) return 0;
	//if (vec->length == 0) return 0;多余代码
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
		printf("%d", vec->data[i]); 
	}
	printf("]\n");
	return ;
}
//清空顺序表 
void clear(Vector *vec) {
	if (vec == NULL) return ;
	free(vec->data);
	free(vec);
	return ;
} 

int main() {
	srand(time(0));//这一行的可以让随机的结果各不相同 
	#define max_op 20
	Vector *vec =  init(1);
	int op, ind, val;
	for (int i = 0; i < max_op; i++) {
		op = rand() % 4;
		ind = rand() % (vec->length + 3) - 1;
		val = rand() % 100;
		switch(op) {
			case 0:
			case 1:
			case 2: {
				printf("insert %d at %d to Vector = %d\n", val,ind, insert(vec, ind, val));
				break;
			}
			case 3: {
				printf("erase item at %d from Vector = %d\n", ind, erase(vec, ind));
				break;
			}
		}
		output(vec);
		printf("\n");
	}
	clear(vec);
	return 0;
}


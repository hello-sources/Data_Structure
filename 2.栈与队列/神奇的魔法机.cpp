#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int *data;
	int top, size;
} Stack;

Stack *init(int n) {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->data = (int *)malloc(sizeof(int) * n);
	s->top = -1;
	s->size = n;
	return s;
}

int empty(Stack *s) {
	return s->top == -1;
}

int top(Stack *s) {
	return s->data[s->top];
}

int expand(Stack *s) {
	int extr_size = s->size;
	int *p;
	while (extr_size) {
		p = (int *)realloc(s->data, sizeof(int) *(extr_size + s->size));
		if (p) break;
		extr_size /= 2;
	}
	if (p == NULL) return 0;
	s->size += extr_size;
	s->data = p;
	return 1;
}

int push(Stack *s, int val) {
	if (s == NULL) return 0;
	if (s->top + 1 == s->size) {
		if (!expand(s)) return 0;
	} 
	s->data[++(s->top)] = val;
	return 1;
}

int pop(Stack *s) {
	if (s == NULL) return 0;
	if (empty(s)) return 0;
	s->top--;
	return 1;	
}

void clear(Stack *s) {
	if (s == NULL) return ;
	free(s->data);
	free(s);
	return ; 
}

int main() {
	int n, num[100];
	scanf("%d", &n);
	Stack *s = init(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		//push(s, num[i]);
	} 
	int a = 1;
	int b = 1;
	int flag = 1;
	while (b <= n) {
		if (num[b] == a) {
			a++;
			b++;
		} else if (!empty(s) && top(s) == num[b]) {
			pop(s);
			b++;
		} else if (a <= n) {
			push(s, a++);
		} else {
			flag = 0;
			break;
		}
	}
	if (flag) printf("YES");
	else printf("NO");
	return 0;
}

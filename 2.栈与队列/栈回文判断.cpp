#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
typedef struct Stack {
	char *data;
	int top, length;
} Stack; 

Stack *init(int n) {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->data = (char *)malloc(sizeof(char));
	s->top = -1;
	s->length = n;
	return s;
}

int empty(Stack *s) {
	return s->top == -1;
}

char top(Stack *s) {
	return s->data[s->top];	
}

int expand(Stack *s) {
	int extr_size = s->length;
	char *p;
	while (extr_size) {
		p = (char *)realloc(s->data, sizeof(char) * (extr_size + s->length));
		if (p) break;
		extr_size /= 2;
	} 
	if (p == NULL) return 0;
	s->length += extr_size;
	s->data = p;
	return 1;
}

int push(Stack *s, char val) {
	if (s == NULL) return 0;
	if (s->top + 1 == s->length) {
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

void output(Stack *s) {
	for(int i = 0; i <= s->top; i++) {
		printf("%c ", s->data[i]);
	}
	printf("\n");
	return ;
}

void clear(Stack *s) {
	if (s == NULL) return ;
	free(s->data);
	free(s);
	return ; 
}

int main() {
	Stack *s1 = init(1);
	Stack *s2 = init(1);
	Stack *s3 = init(1); 
	char c[100];
	scanf("%s", c);
	int sum = strlen(c);
	printf("len = %d\n", sum);
	for (int i = 0; c[i] != '@'; i++) {
		push(s1, c[i]);
		push(s3, c[i]);
	}
	output(s1);
	while (!empty(s1)) {
		push(s2, top(s1));
		pop(s1);
	}
	output(s2);
	output(s3);
	int flag = 0;
	while (top(s2) == top(s3) && !empty(s2) && !empty(s3)) {
		pop(s3);
		pop(s2);
		flag++;
	}
	printf("top s1 = %c\n", top(s3));
	printf("top s2 = %c\n", top(s2));
	printf("flag = %d\n", flag);
	if (sum == flag + 1) printf("YES");
	else printf("NO");
	clear(s1);
	clear(s2);
	clear(s3);
	return 0;
} 

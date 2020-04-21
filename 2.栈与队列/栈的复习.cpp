#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
    int *data;
    int size, top;
} Stack;

void init(Stack *s, int n) {
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
}

int push(Stack * s, int val) {
    if (s->top == s->size - 1) {
        return ERROR;
    }
    s->data[++(s->top)] = val;
    return OK;
}

int empty(Stack *s) {
    return (s->top == -1);
}

int pop(Stack *s) {
    if (!empty(s)) {
        --(s->top);
        return OK;
    }
    return ERROR;
}

int top(Stack * s) {
    return s->data[s->top];
}


int precede(int a, int b) {
    int rank_a, rank_b;
    if (a == '+' || b == '-') {
        rank_a = 1;
    } else {
        rank_a = 2;
    }
    if (b == '+' || b == '-') {
        rank_b = 1;
    } else {
        rank_b = 2;
    }
    return rank_a > rank_b;
}
int operate(int theta, int a, int b) {
    switch(theta) {
        case '+' : return a + b;
        case '-' : return b - a;
        case '*' : return a * b;
        case '/' : return b / a;
    }
    return 0;
}
void calc(Stack * numbers, Stack * operators) {
    int a = top(numbers);
    pop(numbers);
    int b = top(numbers);
    pop(numbers);
    push(numbers, operate(top(operators), a, b));
    pop(operators);
}

void clear(Stack * s) {
    free(s->data);
    free(s);
}

int main() {
    int n;
    scanf("%d", &n);
    Stack *numbers = (Stack *)malloc(sizeof(Stack));
    init(numbers, n);
    Stack *operators = (Stack *)malloc(sizeof(Stack));
    init(operators, n);
    char *buffer = (char*)malloc(n + 1);
    scanf("%s", buffer);
    for(int i = 0; i < n; i++) {
        if (isdigit(buffer[i])) {
            push(numbers, buffer[i] - '0');
        } else {
          while (!empty(operators) && !precede(buffer[i], top(operators))){
                calc(numbers, operators);
            } 
                push(operators, buffer[i]);
        }
    }
    while (!empty(operators)) {
        calc(numbers, operators);
    }
    printf("%d\n", top(numbers));
    clear(numbers);
    clear(operators);
    free(buffer);
    return 0;
}

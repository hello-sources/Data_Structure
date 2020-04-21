#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct Node {
	char data;
	struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
	int n;
	Node *root;
} Tree;

typedef struct Stack {
	Node *data;
	int top, size;
} Stack;

typedef struct Queue {
	int front;
	Node *data;
	int rear;
} Queue;

Node *getNewNode(char val) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = val;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}

Tree *getNewTree() {
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->root = NULL;
	tree->n = 0;
	return tree; 
}

Stack *init_stack(int n) {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->data = (Node *)malloc(sizeof(Node) * n);
	s->top = -1;
	s->size = n;
	return s;
}

void initQueue(Queue *q) {
	q = (Queue *)malloc(sizeof(Queue));
	q->front = q->rear = -1;
}

int empty_Queue(Queue *q) {
	if (q->front == q->rear) return 1;
	else return 0;
}

int pushQueue(Queue *q, Node *val) {
	if (q == NULL) return 0;
	q->rear++;
	q->data[q->rear]= val;
	return 1;
}

int popQueue(Queue *q, Node *val) {
	if (q->front == q->rear) return 0;
	q->front++;
	val = q->data[q->front];
	return 1;
}

int empty(Stack *s) {
	return s->top == -1;
}

Node *top(Stack *s) {
	return s->data[s->top];
}

int push(Stack *s, Node *val) {
	if (s == NULL) return 0;
	if (s->top == s->size - 1) return 0;
	s->data[++(s->top)] = val;
	return 1;
}

int pop(Stack *s) {
	if (empty(s)) return 0;
	s->top -= 1;
	return 1; 
}

void clear_stack(Stack *s) ;

Node *build(char *str, int *num) {
	Node *temp = NULL, *p = NULL;
	Stack *s = init_stack(strlen(str));
	int flag = 0;
	while (str[0]) {
		switch (str[0]) {
			case '(': {
				push(s, temp);
				flag = 0;
				temp = NULL;
				break;
			}
			case ')': {
				p = top(s);
				pop(s);
				break;
			}
			case ',': {
				flag = 1;
				temp = NULL;
				break;
			}
			default: {
				temp = getNewNode(str[0]);
				if (!empty(s) && flag == 0) {
					top(s)->lchild = temp;
				} else if(!empty(s) && flag == 1) {
					top(s)->rchild = temp;
				}
				++(*num);
				break;
			}
		}
		str++; 
	}
	clear_stack(s);
	if (temp && !p) p = temp;
	return p;
}

void level_order(Node *node) {
	Queue *q ;
	initQueue(q);
	if (node == NULL) pushQueue(q, node);
	while (!empty_Queue(q)) {
		popQueue(q, node);
		printf("%c ", node->data);
		if (node->lchild != NULL) pushQueue(q, node->lchild);
		if (node->rchild != NULL) pushQueue(q, node->rchild);
	}
	return ;
}

void post_orderNode(Node *node) {
	if (node == NULL) return ;
	post_orderNode(node->lchild);
	post_orderNode(node->rchild);
	printf("%c ", node->data);
	return ;	
}

void post_order(Tree *tree) {
	printf("post_order : ");
	post_orderNode(tree->root);
	return ;
}

void clear_node(Node *node) {
	if (node == NULL) return ;
	clear_node(node->lchild);
	clear_node(node->rchild);
	return ;
}

void clear_tree(Tree *tree) {
	if (tree == NULL) return ;
	clear_node(tree->root);
	free(tree);
	return ; 
}

void clear_stack(Stack *s) {
	if (s == NULL) return ;
	free(s->data);
	free(s);
	return ;
}

int main() {
	char str[100];
	scanf("%[^\n]s", str);
	int num = 0;
	Tree *tree = getNewTree();
	tree->root = build(str, &num);
	tree->n = num;
	post_order(tree);
	level_order(tree), printf("\n");
	clear_tree(tree);
	return 0;
} 

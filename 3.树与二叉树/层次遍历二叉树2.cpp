//此代码还存在一点bug 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
	Node *root;
	int n;
} Tree;

Node *getNewNode(char val) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = val;
	p->lchild = p->rchild = NULL;
	return p;
}

Tree *getNewTree() {
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->root = NULL;
	tree->n = 0;
	return tree;
}

typedef struct stack {
	Node **data;
	int top, size;
} Stack; 

Stack *init_stack(int n) {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->data = (Node **)malloc(sizeof(Node *) * n);
	s->top = -1;
	s->size = n;
	return s; 
}

int empty_stack(Stack *s) {
	return s->top == -1;
} 

Node *top(Stack *s) {
	return s->data[s->top];
}

int push_stack(Stack *s, Node *val) {
	if (s == NULL) return 0;
	if (s->top == s->size - 1) return 0;
	s->data[++(s->top)] = val;
	return 1;
}

int pop_stack(Stack *s) {
	if (empty_stack(s)) return 0;
	s->top -= 1;
	return 1;
}

void clear_stack(Stack *s);

Node *build(char *str, int *node_num) {
	Node *temp = NULL, *p = NULL;
	Stack *s = init_stack(strlen(str));
	int flag = 0;
	while (str[0]) {
		switch (str[0]) {
			case '(':
				push_stack(s,temp);
				flag = 0;
				temp = NULL;
				break;
			case ')':
				p = top(s);
				pop_stack(s);
				break;
			case ',':
				flag = 1;
				temp = NULL;
				break;
			case ' ':
				break;
			default:
				temp = getNewNode(str[0]);
				if (!empty_stack(s) && flag == 0) {
					top(s)->lchild = temp;
				} else if(!empty_stack(s) && flag == 1) {
					top(s)->rchild = temp;				
				}
				++(*node_num);
			break;
		}
		str++;
	}
	clear_stack(s);
	if (temp && !p) p = temp;
	return p;
}

typedef struct Queue {
	Node **data;
	int head, tail, size, cnt;
} Queue;

void init(Queue *q, int n) {
	q->data = (Node **)malloc(sizeof(Node *) * n);
	q->size = n;
	q->head = 0;
	q->tail = 0;
	q->cnt = 0;
}

int empty(Queue *q) {
	return q->cnt == 0;
}

Node *front(Queue *q) {
	return q->data[q->head];
}

int push(Queue *q, Node *val) {
	if (q->cnt == q->size) return 0;
	q->tail = (q->tail + 1) % q->size;
    q->data[q->tail] = val;
    ++(q->cnt);
	return 1;
} 

int pop(Queue *q) {
	if (q == NULL) return 0;
	if (empty(q)) return 0;
	q->head++;
	q->cnt--;
	return 1;
} 

void clear_queue(Queue *q);
void output(Node *node, int node_num) {
	if (node_num == 0) return ;
	printf("%c ", node->data);
	Queue *q = (Queue *)malloc(sizeof(Queue));
	Node *root;
	init(q, node_num);
	push(q, node);
	while (!empty(q)) {
		root = front(q);
		if (root->lchild) {
			printf("%c ", root->lchild->data);
			push(q, root->lchild);
		}
		if (root->lchild) {
			printf("%c ", root->rchild->data);
			push(q, root->rchild);
		}
		pop(q);
	}
	clear_queue(q);
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

void clear_queue(Queue *q) {
	if (q == NULL) return ;
	free(q->data);
	free(q);
	return ; 
}

int main() {
	char str[100];
	scanf("%[^\n]s", str);
	int node_num = 0;
	Tree *tree = getNewTree();
	tree->root = build(str, &node_num);
	tree->n = node_num;
	output(tree->root, node_num);
	clear_tree(tree);
	return 0;
}

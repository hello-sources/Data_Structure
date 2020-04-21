#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Node {
	int data;
	struct Node *lchild, *rchild;
} Node;

Node *init(int n) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = n;
	node->lchild = NULL;
	node->rchild = NULL;
	return node; 
} 

void post_order(Node *node) {
	if (node->lchild != NULL) {
		post_order(node->lchild);
	}
	if (node->rchild != NULL) {
		post_order(node->rchild);
	}
	printf("%c", node->data);
}

void mirror(Node *node) {
	if (node == NULL) return ;
	Node *p = node->lchild;
	node->lchild = node->rchild;
	node->rchild = p;
	mirror(node->lchild);
	mirror(node->rchild);
	return ;
}

Node *build(char pre[], char in[], int len) {
	Node *p = init(pre[0]);
	int pos = strchr(in, pre[0]) - in;
	if (pos > 0) {
		p->lchild = build(pre + 1, in, pos);
	}
	if (len - pos - 1 > 0) {
		p->rchild = build(pre + pos + 1, in + pos + 1, len - pos - 1);
	}
	return p;
}

void clear(Node *node) {
	if (node->lchild != NULL) {
		clear(node->lchild);
	}
	if (node->rchild != NULL) {
		clear(node->rchild);
	}
	free(node);
}

int main() {
	char pre[50], in[50];
	scanf("%s", pre);
	scanf("%s", in);
	Node *node = build(pre, in, strlen(pre));
	post_order(node);
	printf("\n");
	mirror(node);
	post_order(node);
	printf("\n");
	return 0;
} 

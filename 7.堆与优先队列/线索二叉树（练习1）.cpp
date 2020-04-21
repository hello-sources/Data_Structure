#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NORMAL 0
#define THREAD 1

typedef struct Node {
	int data;
	struct Node *lchild, *rchild;
	int ltag, rtag; 
} Node;

Node *getNewNode(int val) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = val;
	node->lchild = node->rchild = NULL;
	node->ltag = node->rtag = NORMAL;
	return node;
} 

Node *insert(Node *root, int val) {
	if (root == NULL) return getNewNode(val);
	if (root->data == val) return root;
	if (val > root->data) {
		root->rchild = insert(root->rchild,val);
	} else {
		root->lchild = insert(root->lchild, val);
	}
	return root;
}

void build_thread(Node *root) {
	if (root == NULL) return ;
	static Node *pre = NULL;
	build_thread(root->lchild);
	if (root->lchild == NULL) {
		root->lchild = pre;
		root->ltag = THREAD;
	}
	if (pre != NULL && pre->rchild == NULL) {
		pre->rchild = root;
		pre->rtag = THREAD;
	}
	pre = root;
	build_thread(root->rchild);
	return ;
}

Node *most_left(Node *node) {
	while (node && node->lchild && node->ltag == NORMAL) node = node->lchild;
	return node;	
} 

void output(Node *root) {
	Node *p = most_left(root);
	while (p) {
		printf("%d ", p->data);
		if (p->rtag == THREAD) {
			p = p->rchild;
		} else {
			p = most_left(p->rchild);
		}
	}
	return ;
} 

void in_order(Node *root) {
	if (root == NULL) return ;
	if (root->ltag == NORMAL) in_order(root->lchild);
	printf("%d ", root->data);
	if (root->rtag == NORMAL) in_order(root->rchild);
	return ;
}

void  clear(Node *root) {
	if (root == NULL) return ;
	if (root->ltag == NORMAL) clear(root->lchild);
	if (root->rtag == NORMAL) clear(root->rchild);
	free(root);
	return ;
}

int main() {
	srand(time(0));
	#define max_op 10
	Node *root = NULL;
	for (int i = 0; i < max_op; i++) {
		int val = rand() % 100;
		root = insert(root, val); 
	}
	build_thread(root);
	output(root), printf("\n");
	in_order(root), printf("\n");
	clear(root);
	return 0;
} 

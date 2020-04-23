/*************************************************************************
    > File Name: AVL.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 23 Apr 2020 06:17:24 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define H(root) (root)->h
#define K(root) (root)->key
#define L(root) (root)->lchild
#define R(root) (root)->rchild
typedef struct Node {
	int key, h;
	struct Node *lchild, *rchild;
} Node;

//代码技巧，我们设置了一个NIL是表示初始化的状态，变量没有赋值
//合法的空地址节点
Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
	NIL->key = NIL->h = 0;
	NIL->lchild = NIL->rchild = NIL;
	return ;
}

Node *getNewNode(int key) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->key = key;
	p->h = 1;
	p->lchild = p->rchild = NIL;
	return p;
}

void update_height(Node *root) {
	root->h = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;
	return ;
}

Node *left_rotate(Node *root) {
	Node *temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	update_height(root);
	update_height(temp);
	return temp;
}

Node *right_rotate(Node *root) {
	Node *temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	update_height(root);
	update_height(temp);
	return temp;
}

Node *maintain(Node *root) {
	if (abs(H(L(root)) - H(R(root))) <= 1) return root;
	if (H(L(root)) > H(R(root))) {
		if (H(R(L(root))) > H(L(L(root)))) {
			root->lchild = left_rotate(root->lchild);
		}
		root = right_rotate(root);
	} else {
		if (H(L(R(root))) > H(R(R(root)))) {
			root->rchild = right_rotate(root->rchild);
		}
		root = left_rotate(root);
	}
	return root;
}

//代码设计技巧,根节点可能发生改变,所以返回值应该是Node类型的
Node *insert(Node *root, int key) {
	if (root == NIL) return getNewNode(key);
	if (root->key == key) return root;
	if (root->key >key) root->lchild = insert(root->lchild, key);
	else root->rchild = insert(root->rchild, key);
	update_height(root);
	return  maintain(root);
}

Node *predeccessor(Node *root) {
	Node *temp = root->lchild;
	while (temp->rchild != NIL) temp = temp->rchild;
	return temp;
}

Node *erase(Node *root, int key) {
	if (root == NIL) return root;
	if (root->key > key) {
		root->lchild = erase(root->lchild, key);
	} else if (root->key < key) {
		root->rchild = erase(root->rchild, key);
	} else {
		if (root->lchild == NIL || root->rchild == NIL) {
			Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
			free(root);
			return temp;
		} else {
			Node *temp = predeccessor(root);
			root->key = temp->key;
			root->lchild = erase(root->lchild, temp->key);
		}
	}
	return maintain(root);
}

void clear(Node *root) {
	if (root == NIL) return ;
	clear(root->lchild);
	clear(root->rchild);
	free(root);
	return ;
}

void output(Node *root) {
	if (root == NIL) return ;
	printf("(%d, %d, %d)\n", K(root), K(root->lchild), K(root->rchild));
	output(root->lchild);
	output(root->rchild);
	return ;
}

int main() {
	#define MAX_OP 20
	Node *root = NIL;
	for (int i = 0; i < MAX_OP; i++) {
		int val = rand() % 100;
		root = insert(root, val);
		printf("insert %d to AVL tree\n", val);
		output(root);
	}
	int op;
	while (~scanf("%d", &op)) {
		root = erase(root, op);
		output(root);
	}
	clear(root);
	return 0;
}

/*************************************************************************
    > File Name: 1.RBT.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 03:06:52 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define BLACK 1
#define DBLACK 2 


typedef struct Node {
	int key;
	int color; // 0 red 1 black 2 double black
	struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor))
void init_NIL() {
	NIL->key = 0;
	NIL->lchild = NIL->rchild = NIL;
	NIL->color = BLACK;
	return ;
}

Node *getNewNode(int key) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->key = key;
	p->lchild = p->rchild = NIL;
	p->color = RED;
	return p; 
}

bool has_red_child(Node *root) {
	return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left_rotate(Node *root) {
	Node *temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	return temp;
}

Node *right_rotate(Node *root) {
	Node *temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	return temp;
}

Node *insert_maintain(Node *root) {
	if (!has_red_child(root)) return root;
	if (root->lchild->color == RED && root->rchild->color == RED) {
		root->color = RED;//黑红红改为红黑黑 
		root->lchild->color = root->rchild->color = BLACK;
		return root; 
	}
	if (root->lchild->color == RED) {
		if (!has_red_child(root->lchild)) return root;
		if (root->lchild->rchild->color == RED) {
			root->lchild = left_rotate(root->lchild);
			//lr类型的，先小左旋，然后再大右旋 
		}
		root = right_rotate(root);

	} else {
		if (!has_red_child(root->rchild)) return root;
		if (root->rchild->lchild->color == RED) {
			root->rchild = right_rotate(root->rchild);
		}		
		root = left_rotate(root);
	}
	root->color = RED;
	root->lchild->color = root->rchild->color = BLACK; 
	return root;	
} 

Node *__insert(Node *root, int key) {
	if (root == NIL) return getNewNode(key);
	if (root->key == key) return root; 
	if (root->key > key) {
		root->lchild = __insert(root->lchild, key);
	} else {
		root->rchild = __insert(root->rchild, key);
	}
	return insert_maintain(root); 
} 

Node *insert(Node *root, int key) {
	root = __insert(root, key);
	root->color = BLACK;
	return root;
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
	printf("(%d | %d, %d, %d)\n", 
		root->color, 
		root->key,
		root->lchild->key,
		root->rchild->key
	);
	output(root->lchild);
	output(root->rchild);
	return ;
}

int main() {
	int op, val;
	Node *root = NIL;
	while (~scanf("%d%d", &op, &val)) {
		switch(op) {
			case 0: root = insert(root, val); break;
			case 1: break;
		}
		output(root);
	}	
	clear(root);
	return 0;
}

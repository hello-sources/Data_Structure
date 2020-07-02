/*************************************************************************
	> File Name: 二叉树遍历递归+非递归思路.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 02 Jul 2020 03:21:56 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime> 
using namespace std;

typedef struct Node {
	int data;
	struct Node *lchild, *rchild;
} Node;

//typedef struct Tree {
//	Node *root;
//	int n;
//} Tree; 

typedef struct Stack {
	int *val;
	int top, size;
} Stack;

Node *Init_Node(int data) {
	Node *node= (Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = node->rchild = NULL;
	return node;
} 

//Tree *Init_Tree() {
//	Tree *tree = (Tree *)malloc(sizeof(Tree));
//	tree->root = NULL;
//	tree->n = 0; 
//	return tree;
//} 

Stack *Init_Stack(int n) {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->val = (int *)malloc(sizeof(int) * n);
	s->top = -1;
	s->size = n;
	return s;
}

void  preorder(Node *node) {
	if (node == NULL) return ;
	printf("%d ", node->data);
	if (node->lchild != NULL) preorder(node->lchild);
	if (node->rchild != NULL) preorder(node->rchild);
	return ;
}

void  inorder(Node *node) {
	if (node == NULL) return ;
	if (node->lchild != NULL) inorder(node->lchild);
	printf("%d ", node->data);
	if (node->rchild != NULL) inorder(node->rchild);
	return ;
}

void  postorder(Node *node) {
	if (node == NULL) return ;
	if (node->lchild != NULL) postorder(node->lchild);
	if (node->rchild != NULL) postorder(node->rchild);
	printf("%d ", node->data);
	return ;
}

int empty(Stack *s) {
	return s->top == -1;
}

int top(Stack *s) {
	return s->val[s->top];
}

int expand(Stack *s) {
	int extr_size = s->size;
	int *p;
	while (extr_size) {
		p = (int *)realloc(s->val, sizeof(int) * (s->size + extr_size));
		if (p) break;
		extr_size >> 1;
	}
	if (p == NULL) return 0;
	s->size += extr_size;
	s->val = p;
	return 1;
} 

int push(Stack *s, int val) {
	if (s == NULL) return 0;
	if (s->top + 1 == s->size) {
		if (!expand(s)) return 0;
	}
	s->val[++(s->top)] = val;
	return 1;
}

int pop(Stack *s) {
	if (s == NULL) return 0;
	if (empty(s)) return 0;
	s->top -= 1;
	return 1;
}

void clear_Stack(Stack *s) {
	if (s == NULL) return ;
	free(s->val);
	free(s);
	return ;
}

void preorder_stack(Node *root) {
	printf("\n----二叉树先序遍历-非递归----\n");
	Stack *s = Init_Stack(20);
	while (root || !empty(s)) {
		if (root) {
			printf("%d ", root->data);
			push(s, root->data);
			root = root->lchild;
		} else {
			pop(s);
			root = root->rchild;
		}
	}
	clear_Stack(s);
	return ;	
}

void inorder_stack(Node *root) {
	printf("\n----二叉树中序遍历-非递归----\n");
	Stack *s = Init_Stack(6);
	while (root|| !empty(s)) {
		if (root) {
			push(s, root->data);
			root = root->lchild;
		} else {
			printf("%d ", root->data);
			pop(s);
			root = root->rchild;
		}
	}
	clear_Stack(s);
	return ;	
}

Node* build_demo() {
    Node *node = Init_Node(4);
    node->lchild = Init_Node(2);
    node->rchild = Init_Node(6);
    node->lchild->lchild = Init_Node(1);
    node->lchild->rchild = Init_Node(3);
    node->rchild->lchild = Init_Node(5);
    node->rchild->rchild = Init_Node(7);
    return node;
}

void clear_Tree(Node *node) {
	if (node == NULL) return ;
	if (node->lchild != NULL) clear_Tree(node->lchild);
	if (node->rchild != NULL) clear_Tree(node->rchild);
	free(node);
	return ;
}

int main() {
	srand(time(0));
	#define max_op 10
	Node *root = build_demo();
	printf("----二叉树先序遍历-递归----\n");
	preorder(root);
	printf("\n----二叉树中序遍历-递归----\n");
	inorder(root);
	printf("\n----二叉树后序遍历-递归----\n");
	postorder(root);
	
	//preorder_stack(root);
	//inorder_stack(root);
	clear_Tree(root);
	return 0;
}

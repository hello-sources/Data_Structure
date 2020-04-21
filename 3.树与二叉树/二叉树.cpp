#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//二叉树结构定义 
//二叉树节点定义 
typedef struct Node {
	int data;//对应节点的值 
	struct Node *lchild, *rchild;//定义两个指向左右孩子的指针 
} Node;

//二叉树树的定义 
typedef struct Tree {
	Node *root;//指向根节点指针 
	int n;//节点个数 
} Tree;

//初始化生成一个新节点 
Node *getNewNode(int val) {
	Node *p = (Node *)malloc(sizeof(Node));//动态声明一个节点 
	p->data = val;//插入对应节点值 
	p->lchild = p->rchild = NULL;//左右孩子声明为空 
	return p;//返回的是生成的节点p 
} 

//初始化生成一个二叉树 
Tree *getNewTree() {
	Tree *tree = (Tree *)malloc(sizeof(Tree));//创建一个树 
	tree->root = NULL;//根节点为空 
	tree->n = 0;//节点个数为0 
	return tree;//返回的是一棵树 
}

//二叉排序树 
//当这棵树已经存储了这个值则插入失败，所以进行一个标记flag
Node *insertNode(Node *root, int val, int *ret) {
	//根节点为空时，从新得到一个节点 
	if (root == NULL) {
		*ret = 1;
		return getNewNode(val);
	}
	if (root->data == val) return root;
	if (val < root->data) root->lchild = insertNode(root->lchild, val, ret);//比根节点小，则插入左子树 
	else root->rchild = insertNode(root->rchild, val, ret);//否则插入右子树 
	return root;
}
 
//外层insert 
void insert(Tree *tree, int val) {
	int flag = 0; //作为传出参数，用来判断该数是否存在 
	tree->root = insertNode(tree->root, val, &flag);//插入一个节点 
	tree->n += flag;//更新节点个数，由flag决定 
	return ;
} 

//二叉树转为广义表 ，并且输出 
void outputNode(Node *root) {
	if (root == NULL) return ;
	printf("%d ", root->data);
	printf("(");
	outputNode(root->lchild);
	printf(",");
	outputNode(root->rchild);
	printf(")");
	return ;
}

void output(Tree *tree) {
	printf("tree(%d) = [\n", tree->n);
	outputNode(tree->root);//按照节点进行输出 
	printf("]\n");
	return ;
}

//前序遍历 
void pre_orderNode(Node *root) {
	if (root == NULL) return ;
	printf("%d ", root->data);//根节点 
	pre_orderNode(root->lchild);//左子树 
	pre_orderNode(root->rchild);//右子树 
	return ;
}

void pre_order(Tree *tree) {
	printf("pre_order : ");
	pre_orderNode(tree->root);
	printf("\n");
	return ;
}

//中序遍历 
void in_orderNode(Node *root) {
	if (root == NULL) return ;
	in_orderNode(root->lchild);//左子树 
	printf("%d ", root->data);//根节点 
	in_orderNode(root->rchild);//右子树 
	return ;
}

void in_order(Tree *tree) {
	printf("in_order : ");
	in_orderNode(tree->root);
	printf("\n");
	return ;
}

//后续遍历 
void post_orderNode(Node *root) {
	if (root == NULL) return ;
	post_orderNode(root->lchild);//左子树 
	post_orderNode(root->rchild);//右子树 
	printf("%d ", root->data);//根节点 
	return ;
}

void post_order(Tree *tree) {
	printf("post_order : ");
	post_orderNode(tree->root);
	printf("\n");
	return ;
}

//清空节点操作 
void clear_Node(Node *node) {
	if (node == NULL) return ;
	clear_Node(node->lchild);//清空左孩子 
	clear_Node(node->rchild);//清空右孩子 
	free(node);
	return ;
}

//清空二叉树操作 
void clear_tree(Tree *tree) {
	if (tree == NULL) return ; 
	clear_Node(tree->root);//清空根节点 
	free(tree); 
	return ;
}

int main() {
	srand(time(0));
	#define max_op 20
	Tree *tree = getNewTree();
	for (int i = 0; i < max_op; i++) {
		int val = rand() % 100;
		insert(tree, val);//插入相应的节点 
		output(tree);
	}
	pre_order(tree);
	in_order(tree);
	post_order(tree);
	clear_tree(tree);
	return 0;
} 

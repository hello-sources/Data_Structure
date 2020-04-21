#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�������ṹ���� 
//�������ڵ㶨�� 
typedef struct Node {
	int data;//��Ӧ�ڵ��ֵ 
	struct Node *lchild, *rchild;//��������ָ�����Һ��ӵ�ָ�� 
} Node;

//���������Ķ��� 
typedef struct Tree {
	Node *root;//ָ����ڵ�ָ�� 
	int n;//�ڵ���� 
} Tree;

//��ʼ������һ���½ڵ� 
Node *getNewNode(int val) {
	Node *p = (Node *)malloc(sizeof(Node));//��̬����һ���ڵ� 
	p->data = val;//�����Ӧ�ڵ�ֵ 
	p->lchild = p->rchild = NULL;//���Һ�������Ϊ�� 
	return p;//���ص������ɵĽڵ�p 
} 

//��ʼ������һ�������� 
Tree *getNewTree() {
	Tree *tree = (Tree *)malloc(sizeof(Tree));//����һ���� 
	tree->root = NULL;//���ڵ�Ϊ�� 
	tree->n = 0;//�ڵ����Ϊ0 
	return tree;//���ص���һ���� 
}

//���������� 
//��������Ѿ��洢�����ֵ�����ʧ�ܣ����Խ���һ�����flag
Node *insertNode(Node *root, int val, int *ret) {
	//���ڵ�Ϊ��ʱ�����µõ�һ���ڵ� 
	if (root == NULL) {
		*ret = 1;
		return getNewNode(val);
	}
	if (root->data == val) return root;
	if (val < root->data) root->lchild = insertNode(root->lchild, val, ret);//�ȸ��ڵ�С������������� 
	else root->rchild = insertNode(root->rchild, val, ret);//������������� 
	return root;
}
 
//���insert 
void insert(Tree *tree, int val) {
	int flag = 0; //��Ϊ���������������жϸ����Ƿ���� 
	tree->root = insertNode(tree->root, val, &flag);//����һ���ڵ� 
	tree->n += flag;//���½ڵ��������flag���� 
	return ;
} 

//������תΪ����� ��������� 
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
	outputNode(tree->root);//���սڵ������� 
	printf("]\n");
	return ;
}

//ǰ����� 
void pre_orderNode(Node *root) {
	if (root == NULL) return ;
	printf("%d ", root->data);//���ڵ� 
	pre_orderNode(root->lchild);//������ 
	pre_orderNode(root->rchild);//������ 
	return ;
}

void pre_order(Tree *tree) {
	printf("pre_order : ");
	pre_orderNode(tree->root);
	printf("\n");
	return ;
}

//������� 
void in_orderNode(Node *root) {
	if (root == NULL) return ;
	in_orderNode(root->lchild);//������ 
	printf("%d ", root->data);//���ڵ� 
	in_orderNode(root->rchild);//������ 
	return ;
}

void in_order(Tree *tree) {
	printf("in_order : ");
	in_orderNode(tree->root);
	printf("\n");
	return ;
}

//�������� 
void post_orderNode(Node *root) {
	if (root == NULL) return ;
	post_orderNode(root->lchild);//������ 
	post_orderNode(root->rchild);//������ 
	printf("%d ", root->data);//���ڵ� 
	return ;
}

void post_order(Tree *tree) {
	printf("post_order : ");
	post_orderNode(tree->root);
	printf("\n");
	return ;
}

//��սڵ���� 
void clear_Node(Node *node) {
	if (node == NULL) return ;
	clear_Node(node->lchild);//������� 
	clear_Node(node->rchild);//����Һ��� 
	free(node);
	return ;
}

//��ն��������� 
void clear_tree(Tree *tree) {
	if (tree == NULL) return ; 
	clear_Node(tree->root);//��ո��ڵ� 
	free(tree); 
	return ;
}

int main() {
	srand(time(0));
	#define max_op 20
	Tree *tree = getNewTree();
	for (int i = 0; i < max_op; i++) {
		int val = rand() % 100;
		insert(tree, val);//������Ӧ�Ľڵ� 
		output(tree);
	}
	pre_order(tree);
	in_order(tree);
	post_order(tree);
	clear_tree(tree);
	return 0;
} 

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

typedef struct Node {
	int key;
	struct Node *lchild, *rchild; 
} Node;


Node *getNewNode(int key) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->key = key;
	p->lchild = p->rchild = NULL;
	return p; 
}

Node *predeccessor(Node *root) {
	Node *temp = root->lchild;
	while (temp->rchild) temp = temp->rchild;
	return temp;
}

Node *insert(Node *root, int key) {
	if (root == NULL) return getNewNode(key);
	if (root->key == key) return root;
	if (root->key > key) root->lchild = insert(root->lchild, key);
	else root->rchild = insert(root->rchild, key);
	return root;
}

Node *erase(Node *root, int key) {
	if (root == NULL) return root;
	if (root->key > key) {
		root->lchild = erase(root->lchild, key);
	} else if (root->key < key){
		root->rchild = erase(root->rchild, key);
	} else {
		//第一个分支判断可以省略，对于度为0的节点与对于度为1的节点我们可以一同理解 
		if (root->lchild == NULL && root->rchild == NULL) {
			free(root);
			return NULL;
		} else if (root->lchild == NULL || root->rchild == NULL) {
			Node *temp = root->lchild ? root->lchild : root->rchild;
			free(root);
			return temp;
		} else {
			Node *temp = predeccessor(root);
			root->key = temp->key;
			root->lchild = erase(root->lchild, temp->key);
		}
	}
	return root;
}

void clear(Node *root) {
	if (root == NULL) return;
	clear(root->lchild);
	clear(root->rchild);
	free(root);
	return ;
}

void output(Node *root) {
	if (root == NULL) return ;
	output(root->lchild);
	printf("%d ", root->key);
	output(root->rchild);
}

int main() {
	srand(time(0));
	#define MAX_OP 30
	Node *root = NULL;
	for (int i = 0; i < MAX_OP; i++) {
		int op = rand() % 2, val = rand() % 20;
		switch (op) {
			case 0: {
				printf("insert %d to binary search tree\n", val);
				root = insert(root, val);
				break;
			}
			case 1: {
				printf("erase %d from binary search tree\n", val);
				root = erase(root, val);
				break;
			}
		}
		output(root);
		printf("\n");
	}
	clear(root);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild, *father;
}Node;

Node* init(int value, Node *_father) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->lchild = NULL;
    node->rchild = NULL;
    node->father = _father;
    return node;
}

Node* insert(Node *node, int value) {
    if (node == NULL) {
		node = init(value, NULL);
    } else if (node->data < value) {
		if (node->rchild == NULL) {
            node->rchild = init(value, node);
        } else  {
			node->rchild = insert(node->rchild, value);
        }
    } else if (node->data > value) {
		if (node->lchild == NULL) {
			node->lchild = init(value, node);
        } else {        
        	node->lchild = insert(node->lchild, value);
        }
    }
    return node;
}

Node* search(Node *node, int value) {
    if (node == NULL || node->data == value) return node;
	else if (node->data < value) {
		if (node->rchild == NULL) return NULL;
        else return search(node->rchild, value);
    } else {
        if (node->lchild == NULL) return NULL;
        else return search(node->lchild, value);
    }
}

//void in_order(Node *node) {
//    if (node == NULL) return;
//    in_order(node->lchild);
//    printf("%d ", node->data);
//    in_order(node->rchild);
//    return;
//}
void __in_order(Node *root) {
	if (root == NULL) return ;
	__in_order(root->lchild);
	printf("%d ", root->data);
	__in_order(root->rchild);
	return ;
}

void in_order(Node *root) {
	printf("in order output : ");
	__in_order(root);
	printf("\n");
	return ;
}

void clear(Node *node) {
    if (node != NULL) {
        if (node->lchild != NULL) {
            clear(node->lchild);
        }
        if (node->rchild != NULL) {
            clear(node->rchild);
        }
        free(node);
    }
}

int main() {
    Node *binarytree = NULL;
    init(100, binarytree);
    int n, m, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        binarytree = insert(binarytree, m);
    }
    scanf("%d", &x);
    if (search(binarytree, x)) {
		printf("search success!\n");
    } else {
		printf("search failed!\n");
    }
    in_order(binarytree);
    clear(binarytree);
    return 0;
}

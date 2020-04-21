#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

Node* init(int data) {
    Node *node =(Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void postorder(Node *node) {
    if (node->lchild != NULL) {
        postorder(node->lchild);
    }
    if (node->rchild != NULL) {
        postorder(node->rchild);
    }
    printf("%d ", node->data);
}

// 请在下面实现建立二叉树的函数 build
Node *build(char pre_str[], char in_str[], int len) {
	Node *p = init(pre_str[0] - '0');
    int pos = strchr(in_str, pre_str[0]) - in_str;
    if (pos > 0) {
		p->lchild = build(pre_str + 1, in_str, pos);
    }
    if (len - pos - 1 > 0) {
		p->rchild = build(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
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
    char pre_str[] = "136945827";
    char in_str[] = "963548127";
    Node *root = build(pre_str, in_str, strlen(pre_str));
    postorder(root);
    printf("\n");
    clear(root);
    return 0;
}

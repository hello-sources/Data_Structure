#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
}Node;

Node* init(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void preorder(Node *node) {
    printf("%d ", node->data);
    if (node->lchild != NULL) {
        preorder(node->lchild);
    }
    if (node->rchild != NULL) {
        preorder(node->rchild);
    }
}

void inorder(Node *node) {
    if (node->lchild != NULL) {
        inorder(node->lchild);
    }
    printf("%d ", node->data);
    if (node->rchild != NULL) {
        inorder(node->rchild);
    }
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

Node* build_demo() {
    Node *node = init(4);
    node->lchild = init(2);
    node->rchild = init(6);
    node->lchild->lchild = init(1);
    node->lchild->rchild = init(3);
    node->rchild->lchild = init(5);
    node->rchild->rchild = init(7);
    return node;
}

void clear(Node *node) {
    if (node->lchild != NULL) clear(node->lchild);
    if (node->rchild != NULL) clear(node->rchild);
    free(node);
}

int main() {
    Node *node = build_demo();
    preorder(node);
    printf("\n");
    inorder(node);
    printf("\n");
    postorder(node);
    printf("\n");
    clear(node);
    return 0;
}

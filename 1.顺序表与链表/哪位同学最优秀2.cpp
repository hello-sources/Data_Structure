#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;
 
Node insert(LinkedList head, int index, int value) {
    Node *p, ret;
    p = &ret;
    ret.data = 0;
    ret.next = head;
    while (p->next && index) {
        p = p->next;
        --index;
    }
    if (index == 0) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = value;
        node->next = p->next;
        p->next = node;
        ret.data = 1;
    }
    return ret;
}
 
Node delete(LinkedList head, int index) {
    Node ret, *p, *q;
    ret.next = head;
    ret.data = 0;
    p = &ret;
    while (p->next && index) {
        p = p->next;
        --index;
    }
    if (p->next) {
        q = p->next;
        p->next = q->next;
        ret.data = 1;
        free(q);
    }
    return ret;
}
 
void output(LinkedList head) {
    int len = 0;
    Node *p = head;
    while (p) {
        ++len;
        p = p->next;
    }
    len >>= 1;
    p = head;
    while (len--) {
        p = p->next;
    }
    printf("%d\n", p->data);
}
 
void clear(LinkedList head) {
    Node *p, *q;
    p = head;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    return ;
}
 
int main() {
    LinkedList linkedlist = NULL;
    Node ret;
    int n, m, k;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        ret = insert(linkedlist, i, i + 1);
        if (ret.data == 0) {
            printf("ERROR\n");
        }
        linkedlist = ret.next;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &k);
        ret = delete(linkedlist, k - 1);
        if (ret.data == 0) {
            printf("ERROR\n");
        }
        linkedlist = ret.next;
    }
    output(linkedlist);
    clear(linkedlist);
    return 0;
}

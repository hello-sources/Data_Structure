#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prior;
}Node, *LinkedList;
 
Node insert(LinkedList head, int index, int value) {
    Node *p, ret;
    int raw_index = index, len = 0;
    p = head;
    ret.data = 0;
    while (p && index) {
        p = p->next;
        --index;
        ++len;
        if (p == head) break;
    }
    if (index == 0) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = value;
        node->next = node;
        if (p != NULL) {
            node->next = p->next;
            p->next = node;
        }
        node->prior = NULL;
        if (p == head && len == raw_index) {
            head = node;
        }
        ret.data = 1;
    }
    ret.next = head;
    return ret;
}
 
LinkedList build(LinkedList head) {
    Node *p, *q;
    if (head == NULL) {
        return head;
    }
    p = head;
    q = head->next;
    do {
        q->prior = p;
        p = p->next;
        q = q->next;
    } while (q != head->next);
    return head;
}
 
void output(LinkedList head, int m) {
    int len = 0;
    Node *p = head, *q;
    while (p->data != m) {
        p = p->next;
    }
    q = p;
    printf("%d", p->data);
    p = p->prior;
    while (p != q) {
        printf(" %d", p->data);
        p = p->prior;
    }
    printf("\n");
    return ;
}
 
void clear(LinkedList head) {
    Node *p, *q;
    if (head == NULL) {
        return ;
    }
    p = head->next;
    head->next = NULL;
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
    int n, m, num;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        ret = insert(linkedlist, i, num);
        if (ret.data == 0) {
            printf("ERROR\n");
            return 1;
        }
        linkedlist = ret.next;
    }
    linkedlist = build(linkedlist);
    scanf("%d", &m);
    output(linkedlist, m);
    fflush(stdout);
    clear(linkedlist);
    return 0;
}

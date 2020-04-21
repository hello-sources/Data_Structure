#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    char data;
    struct Node *next;
}Node, *LinkedList;
 
Node insert(LinkedList head, int index, char value) {
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
 
LinkedList reverse(LinkedList head) {
    Node ret, *p, *q;
    ret.next = NULL;
    p = head;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}
 
void output(LinkedList head) {
    int len = 0;
    Node *p = head;
    if (p) {
        printf("%c", p->data);
        p = p->next;
    }
    while (p) {
        printf(" %c", p->data);
        p = p->next;
    }
    printf("\n");
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
    int n;
    int c;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%c", &c);
        if (i != n - 1) {
            scanf(" ");
        }
        ret = insert(linkedlist, i, c);
        if (ret.data == 0) {
            printf("ERROR\n");
            return 1;
        }
        linkedlist = ret.next;
    }
    linkedlist = reverse(linkedlist);
    output(linkedlist);
    clear(linkedlist);
    return 0;
}

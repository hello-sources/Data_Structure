#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prior; 
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            return head;
        }
        head = node;
        head->next = head;
        return head;
    }
    if (index == 0) {
        node->next = head->next;
        head->next = node;
        return head;
    }
    Node *current_node = head->next;
    int count = 0;
    while (current_node != head && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
    }
    if (node == head->next) {
		head = node;
    }
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
    int  n, m, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
    	scanf("%d", &m);
		Node *node = (Node *)malloc(sizeof(Node));
        node->data = m;
        node->next = NULL;
        linkedlist = insert(linkedlist, node, i - 1);
    }
    scanf("%d", &x); 
    output(linkedlist, x);
	clear(linkedlist); 
    return 0;
}

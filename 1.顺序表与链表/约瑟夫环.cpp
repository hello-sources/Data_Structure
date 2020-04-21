#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
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

int main() {
    LinkedList linkedlist = NULL;
    int  n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
		Node *node = (Node *)malloc(sizeof(Node));
        node->data = i;
        node->next = NULL;
        linkedlist = insert(linkedlist, node, i - 1);
    }
    return 0;
}

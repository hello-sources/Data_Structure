#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;
 

LinkedList insert(LinkedList head, Node *node, int index) {

    if (head == NULL) {

        if (index != 0) {

            printf("failed\n");

            return head;

        }

        head = node;

        printf("success\n");

        return head;

    }

    if (index == 0) {

        node->next = head;

        head = node;

        printf("success\n");

        return head;

    }

    Node *current_node = head;

    int count = 0;

    while (current_node->next != NULL && count < index - 1) {

        current_node = current_node->next;

        count++;

    }

    if (count == index - 1) {

        node->next = current_node->next;

        current_node->next = node;

        printf("success\n");

        return head;

    }

    printf("failed\n");

    return head;

}

 

void output(LinkedList head) {

    if (head == NULL) {

        return;

    }

    Node *current_node = head;

    while (current_node != NULL) {

        printf("%d ", current_node->data);

        current_node = current_node->next;

    }

    printf("\n");

}

 

Node delete_node(LinkedList head, int index) {
    Node ret, *p, *q;
    ret.data = 0;
    ret.next = head;
    p = &ret;
    while (p->next && index) {
        p = p->next;
        --index;
    }
    if (p->next) {
        q = p->next;
        p->next = q->next;
        free(q);
        ret.data = 1;
    }
    return ret;
}
LinkedList reverse(LinkedList head) {
    Node ret;
    ret.next = NULL;
    Node *p, *q;
    p = head;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}
 
void clear(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {

        Node *delete_node = current_node;

        current_node = current_node->next;

        free(delete_node);
    }
}

int main() {

    LinkedList linkedlist = NULL;

    Node *node, ret;

    int n, t, num, loc;

    scanf("%d", &n);

    while (n--) {

        scanf("%d", &t);

        switch (t) {

            case 1:

                scanf("%d%d", &loc, &num);

                node = (Node *)malloc(sizeof(Node));

                node->data = num;

                node->next = NULL;

                linkedlist = insert(linkedlist, node, loc);

                break;

            case 2:

                output(linkedlist);

                break;

            case 3:

                scanf("%d", &loc);

                ret = delete_node(linkedlist, loc);

                linkedlist = ret.next;

                printf("%s\n", ret.data ? "success" : "failed");

                break;

            case 4:

                linkedlist = reverse(linkedlist);

                break;

            default :

                printf("ERROR\n");

                break;

        }

        fflush(stdout);

    }

    return 0;

}

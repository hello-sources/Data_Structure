#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�ṹ���� 
typedef struct ListNode {
	int data;//������ 
	struct ListNode *next;//ָ���� 
} ListNode;

//��������ڲ�
typedef struct List {
	ListNode head;
	int length; 
} List;

//�ṹ����
//�ڵ��ʼ�� 
ListNode *getNewNode(int val) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = val;
	p->next = NULL;
	return p;
} 

//�����ʼ��
List *getLinkList() {
	List *l = (List *)malloc(sizeof(List));
	l->head.next = NULL;
	l->length = 0;
	return l;
}

//����������
int insert(List *l, int ind, int val) {
	if (l == NULL) return 0;
	if (ind < 0 || ind > l->length) return 0;	
	ListNode *p = &(l->head), *node = getNewNode(val);
	//ind-- ���ܻ���--ind; 
	while (ind--) p = p->next;
	node->next = p->next;
	p->next = node;
	l->length += 1;
	return 1;
} 

//����ڵ�ɾ��
int erase(List *l, int ind) {
	if (l == NULL) return 0;
	if (ind < 0 || ind >= l->length) return 0;
	ListNode *p = l->head.next, *q;
	while (ind--) p = p->next;
	q = p->next;
	p->next = p->next->next;
	free(q);
	l->length -= 1;
	return 1; 
} 

void output(List *l) {
	printf("List(%d) = [", l->length);
	for (ListNode *p = l->head.next; p ;p = p->next) {
		printf("%d->", p->data);
	}
	printf("NULL]\n");
	return ;
}
//����ڵ���� 
void clear_ListNode(ListNode *node) {
	if (node == NULL) return ;
	free(node);
	return ;
}

//����Ļ��� 
void clear_list(List *l) {
	if (l == NULL) return ;
	ListNode *p = l->head.next, *q;
	while (p) {
		q = p->next;
		clear_ListNode(p);
		p = q;
	}
	free(l);
	return ; 
}

int main() {
	srand(time(0));
	#define max_op 20
	List *l = getLinkList(); 
	int op, ind, val;
	for (int i = 0; i < max_op; i++) {
		op = rand() % 4;
		ind = rand() % (l->length + 3) - 1;
		val = rand() % 100;
		switch (op) {
			case 0:
			case 1:
			case 2: {
				printf("Insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
				break;
			}
			case 3: {
				printf("Erase item at %d from List = %d\n", ind, erase(l, ind));
				break;
			}
		}
		output(l);
		printf("\n");
	}
	clear_list(l); 
	
	return 0;
}

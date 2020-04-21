//链表反转
//采用头插法
#include <stdio.h>
#include <stdlib.h>

//结构定义 
typedef struct ListNode {
	int data;//数据域 
	struct ListNode *next;//指针域 
} ListNode;

//定义程序内部
typedef struct List {
	ListNode head;
	int length; 
} List;

//结构操作
//节点初始化 
ListNode *getNewNode(int val) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = val;
	p->next = NULL;
	return p;
} 

//链表初始化
List *getLinkList() {
	List *l = (List *)malloc(sizeof(List));
	l->head.next = NULL;
	l->length = 0;
	return l;
}

//链表插入操作
int insert(List *l, int ind, int val) {
	if (l == NULL) return 0;
	if (ind < 0 || ind > l->length) return 0;	
	ListNode *p = &(l->head), *node = getNewNode(val);
	//ind-- 不能换成--ind; 
	while (ind--) p = p->next;
	node->next = p->next;
	p->next = node;
	l->length += 1;
	return 1;
} 

//链表节点删除
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
	for (ListNode *p = l->head.next; p ;p = p->next) {
		printf("%c", p->data);
		if (p->next) printf(" ");
	}
	return ;
}

//链表反转 
void rev(List *l) {
	if (l == NULL) return ;
	ListNode *p = l->head.next, *q;
	l->head.next = NULL;
	while (p) {
		q = p->next;
		p->next = l->head.next;
		l->head.next = p;
		p = q;
	}	
	return ;
} 

//链表节点回收 
void clear_ListNode(ListNode *node) {
	if (node == NULL) return ;
	free(node);
	return ;
}

//链表的回收 
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
	List *l = getLinkList(); 
	int num, num1;
	scanf("%d\n", &num);
	for (int i = 0; i < num; i++) {
		char c;
		scanf(" %c", &c);
		insert(l, i, c - 0);
	} 
	rev(l);
	output(l);
	clear_list(l);
	return 0;
} 

#include <iostream>
#include <cstdlib>
#include <cstdio>
 
using namespace std;
 
typedef struct node
{
    int data;
    struct node *pre;
    struct node *next;
} Node, LinkList;
 
LinkList *Create()
{
    LinkList *head;
    head=(LinkList*)malloc(sizeof(LinkList));
    if(head!=NULL)
    {
        head->pre=NULL;
        head->next=NULL;
        return head;
    }
    else return NULL;
}
 
int InsertTwo(LinkList *head,int e)
{
    LinkList *p;
    LinkList *q=head;
    p=(LinkList*)malloc(sizeof(LinkList));
    if(p!=NULL)
    {
        p->data=e;
        p->pre=NULL;
        p->next=NULL;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
        return 1;
    }
    return 0;
}
 
LinkList* Change(LinkList *head) //变成双向链表后返回一个尾指针
{
    LinkList *p,*q;
    p=head;
    q=p->next;
    while(q!=NULL)
    {
        q->pre=p;
        p=p->next;
        q=q->next;
    }
    return p;
}
 
//void Output1(LinkList *head) //从头到尾遍历输出
//{
//    LinkList *p;
//    p=head->next;
//    while(p!=NULL)
//    {
//        printf("%d ",p->data);
//        p=p->next;
//    }
//    printf("\n");
//}
 
//void Output2(LinkList *tail) //从尾到头遍历输出
//{
//    LinkList *p;
//    p=tail;
//    while(p->pre!=NULL)
//    {
//        printf("%d ",p->data);
//        p=p->pre;
//    }
//    printf("\n");
//}
 
 void output(LinkList *head, int m) {
    int len = 0;
    Node *p = head, *q;
    while (p->data != m) {
        p = p->next;
    }
    q = p;
    printf("%d", p->data);
    p = p->pre;
    while (p != q) {
        printf(" %d", p->data);
        p = p->pre;
    }
    printf("\n");
    return ;
}

void FreeLink(LinkList *head)
{
    LinkList *p,*q;
    p=head;
    q=NULL;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        free(q);
    }
}
 
int main() {
    LinkList *phead,*tail;
    int n,e,flag, num;
    phead=Create();
    if(phead!=NULL) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&e);
            flag=InsertTwo(phead,e);
        }
        scanf("%d", &num); 
        tail=Change(phead);
        output(phead, num);
        //Output1(phead);
        //Output2(tail);
        FreeLink(phead);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define lld long long 
typedef struct Node
{
	int type;//来电类型
	lld num;//电话号码
	struct Node *next;
	struct Node *pre;
}Node;
typedef struct
{
	Node *front;
	Node *rear;
}Link;
void initQueue(Link *Q);
void creatQueue(Link*,Link*,Link*);
void printQueue(Link *Q);
int main()
{
	int i;
	Link Q0,Q1,Q2;
	initQueue(&Q0);initQueue(&Q1);initQueue(&Q2);
	creatQueue(&Q0,&Q1,&Q2);
	for(i=0;i<10;i++)
	{
		printQueue(&Q0);
		printf(" ");
		printQueue(&Q1);
		printf(" ");
		printQueue(&Q2);
		printf("\n");
	}
	return 0;
}
 
void initQueue(Link *Q)
{
	Q->front=Q->rear=(Node *)malloc(sizeof(Node));
	if(!Q->front)
		//printf("init error!");
		return;
	else
		Q->front->pre=Q->front->next=NULL;
}
void creatQueue(Link *Q0,Link *Q1,Link *Q2)
{
	int type;
	int i;
	lld num;
	Node *q;
	Link *Q=NULL;
	for(i=0;i<30;i++)
	{
		q=(Node *)malloc(sizeof(Node));
		if(scanf("%d %lld",&type,&num)==EOF)
			return;
		q->type=type;
		q->num=num;
		switch(type)
		{
		case 0:
			Q=Q0;break;
		case 1:
			Q=Q1;break;
		case 2:
			Q=Q2;break;
		default:
			return;
		}
		Q->rear->next=q;
		q->pre=Q->rear;
		Q->rear=q;
	}
}
void printQueue(Link *Q)
{
	Node *q;
	if(Q->front!=Q->rear)
	{
		q=Q->rear;
		printf("%lld",q->num);
		Q->rear=q->pre;
		free(q);
	}else
		printf("0");
}

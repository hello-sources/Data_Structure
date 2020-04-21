#include<stdio.h>
#include<malloc.h>

#define MaxSize 1024

typedef struct Node{						//���������
	struct Node *lchild;					//ָ�����ӽڵ�
	char data;								//����Ԫ��
	struct Node *rchild;					//ָ���Һ��ӽڵ� 
}BTNode;									//struct Node �ı���						 

typedef struct Quene{						//����˳��� 
	int front;								//��ͷָ�� 
	BTNode *data[MaxSize];					//��Ŷ���Ԫ�� 
	int rear;								//��βָ�� 
}SqQueue; 									//struct Queue �ı��� 

//��ʼ������ 
void initQueue(SqQueue * &q){
	q=(SqQueue *)malloc(sizeof(SqQueue));	//����һ���ռ� 
	q->front=q->rear=-1;					//�� -1 
}

//�ж϶����Ƿ�Ϊ��
bool emptyQueue(SqQueue * &q){
	if(q->front==q->rear){					//��ָ���βָ����ȣ�˵��Ϊ�� 
		return true;						//������ 
	}
	else{
		return false;						//���ؼ� 
	}
}

//������
bool enQueue(SqQueue * &q,BTNode * &BT){
	if(q->rear==MaxSize-1){					//�ж϶����Ƿ����� 
		return false;						//���ؼ� 
	}
	q->rear++;								//ͷָ��� 1 
	q->data[q->rear]=BT;					//��ֵ 
	return true;							//������ 
}

//������ 
bool deQueue(SqQueue * &q,BTNode * &BT){
	if(q->front==q->rear){					//�ж��Ƿ���� 
		return false;						//���ؼ� 
	}
	q->front++;								//βָ��� 1 
	BT=q->data[q->front];					//ȡֵ 
	return true;							//������ 
}

//���������� 
int createBTNode(BTNode * &BT,char *str,int n){	
	char ch=str[n];								//�ѵ� n ���ַ�����ch,��������ж� 
	n=n+1;
	if(ch!='\0'){								//��� ch �����ڽ������ͼ�������������ͽ��� 
		if( ch=='#'){							//�� # �Ŵ��� NULL������û���� 
			BT = NULL;
		}
		else{
			BT = new BTNode;					//�½�һ�������� 
			BT->data=ch;						//���ַ���������� 
			n=createBTNode(BT->lchild,str,n); 	//��ݹ鴴�� 
			n=createBTNode(BT->rchild,str,n);	//�ҵݹ鴴�� 
		}
	}
	return n;									//���� n,��¼�ַ���ʹ�õ������� 
}

//�������
void preOrder(BTNode * &BT){
    if(BT!=NULL){								//�жϲ�Ϊ�� 
        printf("%c",BT->data);					//���ʸ��ڵ�
        preOrder(BT->lchild);					//�ݹ飬������������� 
        preOrder(BT->rchild);					//�ݹ飬������������� 
    }
}

//�������
void inOrder(BTNode * &BT){
    if(BT!=NULL){
        inOrder(BT->lchild);
        printf("%c",BT->data);
        inOrder(BT->rchild);
    }
}

//�������
void postOrder(BTNode * &BT){
    if(BT!=NULL){
        postOrder(BT->lchild);
        postOrder(BT->rchild);
        printf("%c",BT->data);
    }
}

//��α��� 
void levelOrder(BTNode * &BT){
	SqQueue *q;									//������� 
	initQueue(q);								//��ʼ������ 
	if(BT!=NULL){
		enQueue(q,BT);							//���ڵ�ָ������� 
	} 
	while(emptyQueue(q)!=true){					//�Ӳ�Ϊ��ѭ�� 
		deQueue(q,BT);							//����ʱ�Ľڵ� 
		printf("%c",BT->data);					//����ڵ�洢��ֵ 
		if(BT->lchild!=NULL){					//������ʱ���ýڵ������ 
			enQueue(q,BT->lchild);
		}
		if(BT->rchild!=NULL){					//���Һ���ʱ���ýڵ������ 
			enQueue(q,BT->rchild);
		}										//һ��һ��İѽڵ������� 
	} 											//��û�к��ӽڵ�ʱ�Ͳ���ѭ�� 
} 


int main(){
	//���ӣ�ABDH###E##CF##G##
	BTNode *BT;
	printf("�����ַ�����");
	char *str=(char *)malloc(sizeof(char) * 1024);
	scanf("%s",str); 
    createBTNode(BT,str,0);
    printf("�����������ɹ�\n");
    
	printf("������������");
	preOrder(BT);
	printf("\n");
    
	printf("������������");
	inOrder(BT);
	printf("\n");
    
	printf("������������");
	postOrder(BT);
	printf("\n");

    printf("������������");
    levelOrder(BT);
    printf("\n");
    
    return 0;
}


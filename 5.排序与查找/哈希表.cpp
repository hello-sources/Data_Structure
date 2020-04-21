#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��������ڵ�,��������洢��ϣֵ 
typedef struct Node {
	char *str; 
	struct Node *next;
} Node; 

//�����ϣ�� 
typedef struct HashTable {
	Node **data;//��ǰ��ϣ��ÿһ��λ���ϴ洢�������� 
	int size;//��ϣ��洢�ռ��С 
} HashTable;

//��ʼ������ڵ���Ϣ�������ַ�������Ӧͷ�ڵ�,���ǲ���ͷ�巨 
Node *init_node(char *str, Node *head) {
	Node *p = (Node *)malloc(sizeof(Node));//��̬��������ڵ�ռ� 
	p->str = strdup(str);//���ǰ�str���������ŵ���Ӧ�ڵ����������
	p->next = head;
	return p; 
}

//��ϣ���ʼ��
HashTable *init_hashtable(int n) {
	HashTable *h = (HashTable *)malloc(sizeof(HashTable));
	h->size = n << 1;//��߹�ϣ��ռ�������ʣ��ѿռ俪�ٳ�������С 
	h->data = (Node **)calloc(sizeof(Node *), h->size);//ʹ��calloc����,
	return h; //���ع�ϣ�� 
} 

//BKDR��ϣ�������������ַ����������ٳ�ͻ 
int BKDRHash(char *str) {
	int seed = 31, hash =  0;//��ʼ��������Ϊ31����ϣֵΪ0 
	for (int i = 0; str[i]; i++) hash = hash * seed + str[i];//����õ���ϣֵ 
	return hash & 0x7fffffff;
	//�ڹ�ϣ����Ĺ����г��ֳ������εı��������ǿ�������һ���� 
}

//��ϣ��Ĳ������ 
int insert(HashTable *h, char *str) {
	int hash = BKDRHash(str);//����õ���Ӧ�Ĺ�ϣֵ 
	int ind = hash % h->size;//�����ͻ���� 
	h->data[ind] = init_node(str, h->data[ind]);//ͨ����ʼ���ڵ�ķ�����ʵ�� 
	return 1; //���ز���ɹ� 
} 

//��ϣ����Ҳ���
int search(HashTable *h, char *str) {
	int hash = BKDRHash(str);//�����Ӧ�ַ�����ϣֵ 
	int ind = hash % h->size;//�����ͻ 
	Node *p = h->data[ind];//�¶���һ���ڵ� 
	while (p && strcmp(p->str, str)) p = p->next;//�Ƚ϶�Ӧ������ַ����봫����ַ��� 
	return p != NULL;	//���pΪ�գ���ʾ�����û�ҵ�˵������ʧ�� 
} 

//�ڵ���ղ��� 
void clear_node(Node *node) {
	if (node == NULL) return ;
	Node *p = node, *q;//����һ���µĽڵ� 
	while (p) {
		q = p->next; 
		free(p->str);//��սڵ������� 
		free(p);
		p = q;
	}
	free(q);
	return ; 
}

//��չ�ϣ��
void clear_hashtable(HashTable *h) {
	if (h == NULL) return ;
	for (int i = 0; i < h->size; i++) clear_node(h->data[i]);//ѭ����չ�ϣ��ÿһ���ڵ� 
	free(h->data);//�ͷ������� 
	free(h);
	return ;
} 

int main() {
	int op;
	#define max_n 100
	char str[max_n + 5];
	HashTable *h = init_hashtable(max_n + 5);
	while (~scanf("%d%s", &op, str)) {
		switch (op) {
			case 0: {//0��ʾ������� 
				printf("insert %s to hash table\n", str);
				insert(h, str);
				break;
			}
			case 1: {//1��ʾ���Ҳ��� 
				printf("search %s from hash table result = %d\n", str, search(h, str));
				break;
			}
		}
	} 
	clear_hashtable(h);
	return 0;
} 

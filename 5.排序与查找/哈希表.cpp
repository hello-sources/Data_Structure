#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义链表节点,建立链表存储哈希值 
typedef struct Node {
	char *str; 
	struct Node *next;
} Node; 

//定义哈希表 
typedef struct HashTable {
	Node **data;//当前哈希表每一个位置上存储的是链表 
	int size;//哈希表存储空间大小 
} HashTable;

//初始化链表节点信息，传入字符串跟对应头节点,我们采用头插法 
Node *init_node(char *str, Node *head) {
	Node *p = (Node *)malloc(sizeof(Node));//动态开辟链表节点空间 
	p->str = strdup(str);//就是把str拷贝出来放到对应节点的数据域中
	p->next = head;
	return p; 
}

//哈希表初始化
HashTable *init_hashtable(int n) {
	HashTable *h = (HashTable *)malloc(sizeof(HashTable));
	h->size = n << 1;//提高哈希表空间的利用率，把空间开辟成两倍大小 
	h->data = (Node **)calloc(sizeof(Node *), h->size);//使用calloc操作,
	return h; //返回哈希表 
} 

//BKDR哈希函数用来处理字符串，来减少冲突 
int BKDRHash(char *str) {
	int seed = 31, hash =  0;//初始化种子是为31，哈希值为0 
	for (int i = 0; str[i]; i++) hash = hash * seed + str[i];//计算得到哈希值 
	return hash & 0x7fffffff;
	//在哈希处理的过程中出现超过整形的变量，我们可以与上一个数 
}

//哈希表的插入操作 
int insert(HashTable *h, char *str) {
	int hash = BKDRHash(str);//计算得到相应的哈希值 
	int ind = hash % h->size;//解决冲突方法 
	h->data[ind] = init_node(str, h->data[ind]);//通过初始化节点的方法来实现 
	return 1; //返回插入成功 
} 

//哈希表查找操作
int search(HashTable *h, char *str) {
	int hash = BKDRHash(str);//计算对应字符串哈希值 
	int ind = hash % h->size;//处理冲突 
	Node *p = h->data[ind];//新定义一个节点 
	while (p && strcmp(p->str, str)) p = p->next;//比较对应链表的字符串与传入的字符串 
	return p != NULL;	//如果p为空，表示到最后都没找到说明查找失败 
} 

//节点清空操作 
void clear_node(Node *node) {
	if (node == NULL) return ;
	Node *p = node, *q;//定义一个新的节点 
	while (p) {
		q = p->next; 
		free(p->str);//清空节点数据域 
		free(p);
		p = q;
	}
	free(q);
	return ; 
}

//清空哈希表
void clear_hashtable(HashTable *h) {
	if (h == NULL) return ;
	for (int i = 0; i < h->size; i++) clear_node(h->data[i]);//循环清空哈希表每一个节点 
	free(h->data);//释放数据域 
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
			case 0: {//0表示插入操作 
				printf("insert %s to hash table\n", str);
				insert(h, str);
				break;
			}
			case 1: {//1表示查找操作 
				printf("search %s from hash table result = %d\n", str, search(h, str));
				break;
			}
		}
	} 
	clear_hashtable(h);
	return 0;
} 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�궨�彻������������������������ 
#define swap(a, b) {\
	__typeof(a) __temp = a;\
	a = b; b = __temp;\
}

//�������ȶ��нṹ 
typedef struct priority_queue {
	int *data;
	int cnt, size;//һ����ͳ��Ԫ�ظ�����һ����ͳ�����ȶ��д�С 
} priority_queue;

//��ʼ�����ȶ��� 
priority_queue *init(int n) {
	priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
	q->data = (int *)malloc(sizeof(int) * n);//��̬�������ݿռ� 
	q->cnt = 0;//���ȶ���һ��ʼ����Ϊ0 
	q->size = n;//���ٴ�С��n 
	return q;
}

//�����пղ��� 
int empty(priority_queue *q) {
	return q->cnt == 0;
}

//����Ѷ�Ԫ�� 
int top(priority_queue *q) {
	return q->data[1];
}

//�����Ԫ�� 
int push(priority_queue *q, int val) {//������У��Լ���Ӧ��ֵ 
	if (q == NULL) return 0;
	if (q->cnt == q->size) return 0;//�ж϶����Ƿ��Ѿ����� 
	q->cnt += 1;//��Ӧͳ������һ 
	q->data[q->cnt] = val;//������ֵ�������ȶ�����
	//����ά�����ȶ������ʣ��������ϵ������� 
	int ind = q->cnt;//����ող����λ�� 
	while (ind >> 1 && q->data[ind] > q->data[ind >> 1]) {//��ջ��ʱ���ж϶�Ӧ�ĸ��ڵ���ýڵ� 
		swap(q->data[ind], q->data[ind >> 1]);//�����뵱ǰԪ�ش��Ԫ�� 
		ind >>= 1;// ���½ڵ������һ�ڵ���� 
	}
	return 1;
}

//�����Ѷ�Ԫ�� 
int pop(priority_queue *q) {
	if (q == NULL) return 0;
	if (empty(q)) return 0;//�пղ��� 
	q->data[1] = q->data[q->cnt--];//��βԪ�ظ�ֵ���Ѷ�Ԫ�� 
	int ind = 1;//�ӽڵ�Ϊ1��ʼά�����ȶ��У��������µ��� 
	while ((ind << 1) <= q->cnt) {//�жϵ�ǰ�ڵ����ӽڵ� 
		int temp = ind, l = ind << 1, r = ind << 1 | 1;//temp��¼��ǰ�±꣬l��ʾ���ӣ�r��ʾ�Һ��� 
		if (q->data[l] > q->data[temp]) temp = l;//�ж������ӵĴ�С 
		if (r <= q->cnt && q->data[r] > q->data[temp]) temp =r;//�ж����Һ��Ӵ�С 
		if (temp == ind) break;//�жϵ�ǰԪ���Ƿ���������� 
		swap(q->data[ind], q->data[temp]);//��������Ԫ��λ�� 
		ind = temp;//�������µ��� 
	}
	return 1;
}

void clear(priority_queue *q) {
	if (q == NULL) return ;
	free(q->data);
	free(q);
	return ;
}

int main() {
	srand(time(0));
	#define max_op 20
	priority_queue *q = init(max_op);
	for (int i = 0; i < max_op; i++) {
		int val = rand() % 100;
		push(q, val);
		printf("insert %d to queue \n", val);
	}
	for (int i = 0; i < max_op; i++) {
		printf("%d ", top(q));
		pop(q);
	}
	printf("\n");
	clear(q);
	
	return 0;
}

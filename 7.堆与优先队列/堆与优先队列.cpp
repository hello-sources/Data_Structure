#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//宏定义交换函数，可以区别数据类型 
#define swap(a, b) {\
	__typeof(a) __temp = a;\
	a = b; b = __temp;\
}

//定义优先队列结构 
typedef struct priority_queue {
	int *data;
	int cnt, size;//一个是统计元素个数，一个是统计优先队列大小 
} priority_queue;

//初始化优先队列 
priority_queue *init(int n) {
	priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
	q->data = (int *)malloc(sizeof(int) * n);//动态开辟数据空间 
	q->cnt = 0;//优先队列一开始个数为0 
	q->size = n;//开辟大小是n 
	return q;
}

//队列判空操作 
int empty(priority_queue *q) {
	return q->cnt == 0;
}

//输出堆顶元素 
int top(priority_queue *q) {
	return q->data[1];
}

//插入堆元素 
int push(priority_queue *q, int val) {//传入队列，以及对应的值 
	if (q == NULL) return 0;
	if (q->cnt == q->size) return 0;//判断队列是否已经满了 
	q->cnt += 1;//对应统计数加一 
	q->data[q->cnt] = val;//待插入值插入优先队列中
	//下面维护优先队列性质，自下向上调整策略 
	int ind = q->cnt;//代表刚刚插入的位置 
	while (ind >> 1 && q->data[ind] > q->data[ind >> 1]) {//入栈的时候判断对应的父节点与该节点 
		swap(q->data[ind], q->data[ind >> 1]);//交换与当前元素大的元素 
		ind >>= 1;// 更新节点进行下一节点调整 
	}
	return 1;
}

//弹出堆顶元素 
int pop(priority_queue *q) {
	if (q == NULL) return 0;
	if (empty(q)) return 0;//判空操作 
	q->data[1] = q->data[q->cnt--];//堆尾元素赋值给堆顶元素 
	int ind = 1;//从节点为1开始维护优先队列，自上向下调整 
	while ((ind << 1) <= q->cnt) {//判断当前节点有子节点 
		int temp = ind, l = ind << 1, r = ind << 1 | 1;//temp记录当前下标，l表示左孩子，r表示右孩子 
		if (q->data[l] > q->data[temp]) temp = l;//判断与左孩子的大小 
		if (r <= q->cnt && q->data[r] > q->data[temp]) temp =r;//判断与右孩子大小 
		if (temp == ind) break;//判断当前元素是否满足堆性质 
		swap(q->data[ind], q->data[temp]);//交换两个元素位置 
		ind = temp;//继续向下调整 
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

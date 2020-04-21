#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {\
	__typeof(a) __temp = a;\
	a = b; b = __temp;\
}

typedef struct Node {
	int ind, len;	
} Node;

typedef struct Heap {
	Node *data;
	int size, cnt;
} Heap;

int cmp(Node a, Node b) {
	if (a.len > b.len) return 1;
	if (a.len == b.len && a.ind < b.ind) return 1;
	return 0;
}

void init(Heap *h, int n) {
	h->data = (Node *)malloc(sizeof(Node) * n);
	h->size = n;
	h->cnt = 0; 
}

void push(Heap *h, Node val) {
	if (h == NULL) return ;
	if (h->size <= h->cnt) return ;
	h->data[h->cnt] = val;
	int pos = h->cnt;
	int father = (pos - 1) / 2;
	while (cmp(h->data[pos], h->data[father])) {
		swap(h->data[pos], h->data[father]);
		pos = father;
		father = (pos - 1) / 2;
	}
	h->cnt++;
	return ;
}

void update(Heap *h, int pos, int n) {
	//位运算优先级小于算术运算符 
	int l = (pos << 1 )+ 1, r = (pos << 1)+ 2;
	int temp = pos;
	if (cmp(h->data[l], h->data[temp]) && l < n) temp = l;
	if (cmp(h->data[r], h->data[temp]) && r < n) temp = r;
	if (temp != pos) {
		swap(h->data[temp], h->data[pos]);
		update(h, temp, n);
	}
	return ;
}

Node top(Heap *h) {
	return h->data[0];
} 
int empty(Heap *h);
void pop(Heap *h) {
	if (h == NULL) return ;
	if (empty(h)) return ;
	h->cnt--;
	swap(h->data[0], h->data[h->cnt]);
	update(h, 0, h->cnt);
	return ;
}

int empty(Heap *h) {
	return h->cnt == 0;
}

void clear(Heap *h) {
	if (h == NULL) return ;
	free(h->data);
	free(h);
}

int main() {
	int n, num, cnd = 0;
	scanf("%d", &n);
	Heap *h[101]; 
	for (int i = 1; i <= 100; i++) {
		h[i] = (Heap *)malloc(sizeof(Heap));
		init(h[i], 50000);	//创建多个堆 ，方便后面不同速度僵尸放在一个堆里面 
	}	
	while (cnd < n) {
        scanf("%d", &num);
        Node p;
        int s;
        for (int i = 0; i < num; i++) {
            scanf("%d%d", &p.len, &s);
            p.ind = i + 1;//对应节点下标加一 
            push(h[s], p);//速度相同的僵尸放到一个堆里面 
        }
        printf("Case #%d:\n", ++cnd);
        for (int i = 0; i < num; i++) {
            int m = -1;//由于创建了好多堆 
            Node p1, p2;
            //下面这个循环就是实现比较不同堆，也就是不同速度僵尸在某一时刻路程大小，然后进行输出 
            for (int j = 1; j <= 100; j++) {
                if (empty(h[j])) continue;//创建了好多无用的堆，如果对应堆是空的，则就跳过 
                if (m == -1) {
                    m = j;
                    continue;
                }
                p1 = top(h[m]);//首先取出两个堆顶元素 
                p2 = top(h[j]);
                p1.len = p1.len + i * m;//计算对应僵尸跑的路程 
                p2.len = p2.len + i * j;
                if (cmp(p2, p1)) {
                    m = j;//如果僵尸2比僵尸1跑得远，就更新堆下标，表示到哪个僵尸跑的最远 
                }  
            }
            //一趟循环下来首先被消灭的僵尸下标找到了，总共有num只僵尸所以需要循环num次 
            printf("%d", top(h[m]).ind);//输出堆顶节点的下标 
            pop(h[m]);
            if (i != num - 1)  printf(" ");
        }
        printf("\n");
    }
	for (int i = 1; i <= 100; i++) {
		clear(h[i]);
	}
	return 0;
} 


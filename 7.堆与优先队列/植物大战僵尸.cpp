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
	//λ�������ȼ�С����������� 
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
		init(h[i], 50000);	//��������� ��������治ͬ�ٶȽ�ʬ����һ�������� 
	}	
	while (cnd < n) {
        scanf("%d", &num);
        Node p;
        int s;
        for (int i = 0; i < num; i++) {
            scanf("%d%d", &p.len, &s);
            p.ind = i + 1;//��Ӧ�ڵ��±��һ 
            push(h[s], p);//�ٶ���ͬ�Ľ�ʬ�ŵ�һ�������� 
        }
        printf("Case #%d:\n", ++cnd);
        for (int i = 0; i < num; i++) {
            int m = -1;//���ڴ����˺ö�� 
            Node p1, p2;
            //�������ѭ������ʵ�ֱȽϲ�ͬ�ѣ�Ҳ���ǲ�ͬ�ٶȽ�ʬ��ĳһʱ��·�̴�С��Ȼ�������� 
            for (int j = 1; j <= 100; j++) {
                if (empty(h[j])) continue;//�����˺ö����õĶѣ������Ӧ���ǿյģ�������� 
                if (m == -1) {
                    m = j;
                    continue;
                }
                p1 = top(h[m]);//����ȡ�������Ѷ�Ԫ�� 
                p2 = top(h[j]);
                p1.len = p1.len + i * m;//�����Ӧ��ʬ�ܵ�·�� 
                p2.len = p2.len + i * j;
                if (cmp(p2, p1)) {
                    m = j;//�����ʬ2�Ƚ�ʬ1�ܵ�Զ���͸��¶��±꣬��ʾ���ĸ���ʬ�ܵ���Զ 
                }  
            }
            //һ��ѭ���������ȱ�����Ľ�ʬ�±��ҵ��ˣ��ܹ���numֻ��ʬ������Ҫѭ��num�� 
            printf("%d", top(h[m]).ind);//����Ѷ��ڵ���±� 
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


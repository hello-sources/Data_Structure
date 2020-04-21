//借用队列完美实现层次遍历二叉树
//在定义队列的时候要注意对应的数据域类型应该是Node型的，这样便于后面进行循环遍历 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
	Node *root;
	int n;
} Tree;

typedef struct Queue {
    Node **data;
    int head, tail, len, cnt;
} Queue;
 
void init_queue(Queue *q, int len) {
    q->data = (Node **)malloc(sizeof(Node *) * len);
    q->len = len;
    q->head = 0;
    q->tail = -1;
    q->cnt = 0;
}
 
int push_queue(Queue *q, Node *e) {
    if (q->cnt == q->len) {
        return 0;
    }
    q->tail = (q->tail + 1) % q->len;
    q->data[q->tail] = e;
    ++(q->cnt);
    return 1;
}
 
int empty_queue(Queue *q) {
    return q->cnt == 0;
}
 
int pop_queue(Queue *q) {
    if (empty_queue(q)) {
        return 0;
    }
    ++(q->head);
    --(q->cnt);
    return 1;
}
 
Node *front_queue(Queue *q) {
    return q->data[q->head];
}
 
void clear_queue(Queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
}

Node *getNewNode(char val) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = val;
	p->lchild = p->rchild = NULL;
	return p;
}

Tree *getNewTree() {
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->root = NULL;
	tree->n = 0;
	return tree;
}

typedef struct stack {
	Node **data;
	int top, size;
} Stack; 

Stack *init_stack(int n) {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->data = (Node **)malloc(sizeof(Node *) * n);
	s->top = -1;
	s->size = n;
	return s; 
}

int empty(Stack *s) {
	return s->top == -1;
} 

Node *top(Stack *s) {
	return s->data[s->top];
}

int push(Stack *s, Node *val) {
	if (s == NULL) return 0;
	if (s->top == s->size - 1) return 0;
	s->data[++(s->top)] = val;
	return 1;
}

int pop(Stack *s) {
	if (empty(s)) return 0;
	s->top -= 1;
	return 1;
}

void clear_stack(Stack *s);

Node *build(char *str, int *node_num) {
	Node *temp = NULL, *p = NULL;
	Stack *s = init_stack(strlen(str));
	int flag = 0;
	while (str[0]) {
		switch (str[0]) {
			case '(':
				push(s,temp);
				flag = 0;
				temp = NULL;
				break;
			case ')':
				p = top(s);
				pop(s);
				break;
			case ',':
				flag = 1;
				temp = NULL;
				break;
			case ' ':
				break;
			default:
				temp = getNewNode(str[0]);
				if (!empty(s) && flag == 0) {
					top(s)->lchild = temp;
				} else if(!empty(s) && flag == 1) {
					top(s)->rchild = temp;				
				}
				++(*node_num);
			break;
		}
		str++;
	}
	clear_stack(s);
	if (temp && !p) p = temp;
	return p;
}

//层次遍历输出重点内容 ，传入的节点，然后通过循环遍历判断是否存在 
void output(Node *p, int node_num) {
    if (node_num == 0) {
        return ;
    }
    printf("%c", p->data);
    Queue *q = (Queue *)malloc(sizeof(Queue));
    Node *temp_p;
    init_queue(q, node_num);
    push_queue(q, p);
    while (!empty_queue(q)) {
        temp_p = front_queue(q);
        if (temp_p->lchild) {
            printf(" %c", temp_p->lchild->data);
            push_queue(q, temp_p->lchild);
        }
        if (temp_p->rchild) {
            printf(" %c", temp_p->rchild->data);
            push_queue(q, temp_p->rchild);
        }
        pop_queue(q);
    }
    clear_queue(q);
    return ;
}

void clear_node(Node *node) {
	if (node == NULL) return ;
	clear_node(node->lchild);
	clear_node(node->rchild);
	return ;
}

void clear_tree(Tree *tree) {
	if (tree == NULL) return ;
	clear_node(tree->root);
	free(tree);
	return ;
}

void clear_stack(Stack *s) {
	if (s == NULL) return ;
	free(s->data);
	free(s);
	return ;
}

int main() {
	char str[100];
	scanf("%[^\n]s", str);
	int node_num = 0;
	Tree *tree = getNewTree();
	tree->root = build(str, &node_num);
	tree->n = node_num;
	output(tree->root, node_num); 
	clear_tree(tree);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node *lchild, *rchild;
} Node, *point;

point init(char data) {
	point p = (point)malloc(sizeof(Node));
	p->data = data;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}

void output(point root) {
	if (root == NULL) return ;
	printf("%c", root->data);
	if (root->lchild == NULL && root->rchild == NULL) {
        return ;
    }
	printf("(");
	if (root->lchild) {
		output(root->lchild);	
	}
	if (root->rchild) {
		printf(",");
		output(root->rchild);	
	}
	printf(")");
	return ;
}

void clearNode(point node) {
	if (node == NULL) return ;
	if (node->lchild) clearNode(node->lchild);
	if (node->rchild) clearNode(node->rchild);
	free(node);
	return ;
}

int main() {
	char str[50], x;
	int j = 0;
	str[0] = 0;
	while (scanf("%c", &x)) {
		if (x == '$') break;
		str[j++] = x;
	}
	point *p = (point *)malloc(sizeof(point) *(strlen(str) / 2 + 1));
	int ind = 1;
	p[ind] = NULL;
	for (int i = 0; i < j; ++i) {
		if (str[i] == ' ') continue;
		p[ind] = init(str[i]);
		if (ind != 1) {
			if (ind % 2) {
				p[ind / 2]->rchild = p[ind];
			} else {
				p[ind / 2]->lchild = p[ind];
			}	
		}
		++ind;
	} 
	output(p[1]);
	clearNode(p[1]);
	return 0;
} 

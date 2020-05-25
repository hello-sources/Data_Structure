/*************************************************************************
    > File Name: 海贼红黑树.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Tue 26 May 2020 01:19:31 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

typedef struct Node {
	int key, color; //red 0 black 1 double black 2
	struct Node *lchild, *rchild;
} Node;

Node _NIL, * const NIL = &_NIL;

__attribute__((constructor))
void init_NIL() {
	NIL->key = 0;
	NIL->lchild = NIL->rchild = NIL;
	NIL->color = BLACK;
	return ;
}

Node *getNewNode(int key) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->key = key;
	p->lchild = p->rchild = NIL;
	p->color = RED;
	return p;
}

int hasRedChild(Node *root) {
	return root->lchild->color == RED || root->rchild->color == RED; 
}

Node *left_rotate(Node *root) {
	Node *temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	return temp; 
}

Node *right_rotate(Node *root) {
	Node *temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	return temp;
}

//红色上提 
Node *insert_maintain(Node *root) {
	if (!hasRedChild(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!hasRedChild(root->lchild) && !hasRedChild(root->rchild)) return root;
		root->color = RED;
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }
    if (root->lchild->color == RED) {
        if (!hasRedChild(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (!hasRedChild(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *__insert(Node *root, int key) {
	if (root == NIL) return getNewNode(key);
	if (root->key == key) return root;
	if (root->key > key) root->lchild = __insert(root->lchild, key);
	else  root->rchild = __insert(root->rchild, key);
	return insert_maintain(root);
}

Node *insert(Node *root, int key) {
	root = __insert(root, key);
	root->color = BLACK;
	return root;
}

Node *predecessor(Node *root) {
	Node *temp = root->lchild;
	while (temp->rchild != NIL) temp = temp->rchild;
	return temp;
}

Node *erase_maintain(Node *root) {
//	if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK)
//	 	return root;
//	if (root->rchild->color == DOUBLE_BLACK) {
//		if (root->lchild->color == RED) {
//			root->color = RED;
//			root->lchild->color = BLACK;
//			root = right_rotate(root);
//			root->rchild = erase_maintain(root->rchild);
//		}
//		if (!hasRedChild(root->lchild)) {
//			root->color += 1;
//			root->rchild->color -= 1;
//			root->lchild->color -= 1;
//			return root;
//		}
//		if (root->lchild->lchild->color != RED) {
//			root->lchild->rchild->color = BLACK;
//			root->lchild->color = RED;
//			root->lchild = left_rotate(root->lchild);
//		}
//		root->lchild->color = root->color;
//		root->rchild->color -= 1;
//		root = right_rotate(root);
//		root->lchild->color = root->rchild->color = BLACK; 
//	} else {
//		if (root->rchild->color == RED) {
//			root->color = RED;
//			root->rchild->color = BLACK;
//			root = left_rotate(root);
//			root->lchild = erase_maintain(root->lchild);
//		}
//		if (!hasRedChild(root->rchild)) {
//			root->color += 1;
//			root->lchild->color -= 1;
//			root->rchild->color -= 1;
//			return root;
//		}
//		if (root->rchild->rchild->color != RED) {
//			root->rchild->lchild->color = BLACK;
//			root->rchild->color = RED;
//			root->rchild = right_rotate(root->rchild);
//		}
//		root->rchild->color = root->color;
//		root->lchild->color -= 1;
//		root = left_rotate(root);
//		root->lchild->color = root->rchild->color = BLACK; 
//	}
//	return root;
	if (root->lchild->color != DOUBLE_BLACK &&
        root->rchild->color != DOUBLE_BLACK) return root;
    if (hasRedChild(root)) {
        root->color = RED;
        if (root->lchild->color == RED) {
            root = right_rotate(root);
            root->rchild = erase_maintain(root->rchild);
        } else {
            root = left_rotate(root);
            root->lchild = erase_maintain(root->lchild);
        }
        root->color = BLACK;
        return root;
    }
    if ((root->lchild->color == DOUBLE_BLACK && !hasRedChild(root->rchild)) ||
        (root->rchild->color == DOUBLE_BLACK && !hasRedChild(root->lchild))) {
        root->color += 1;
        root->lchild->color -= 1;
        root->rchild->color -= 1;
        return root;
    }
    if (root->rchild->color == BLACK) {
        if (root->rchild->rchild->color != RED) {
            root->rchild->color = RED;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
        }
        root->rchild->color = root->color;
        root->color = BLACK;
        root->lchild->color -= 1;
        root = left_rotate(root);
        root->rchild->color = BLACK;
    } else {
        if (root->lchild->lchild->color != RED) {
            root->lchild->color = RED;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
        }
        root->lchild->color = root->color;
        root->color = BLACK;
        root->rchild->color -= 1;
        root = right_rotate(root);
        root->lchild->color = BLACK;
    }
    return root;
}


Node *__erase(Node *root, int key) {
	if (root == NIL) return root;
	if (root->key > key) {
		root->lchild = __erase(root->lchild, key);
	} else if (root->key < key) {
		root->rchild = __erase(root->rchild, key);
	} else {
		if (root->lchild == NIL || root->rchild == NIL) {
			Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
			temp->color += root->color;
			free(root);
			return temp;
		} else {
			Node *temp = predecessor(root);
			root->key = temp->key;
			root->lchild = __erase(root->lchild, temp->key);
		}
	}
	return erase_maintain(root);
}

Node *erase(Node *root, int key) {
	root = __erase(root, key);
	root->color = BLACK;
	return root;
}


void clear(Node *root) {
	if (root == NIL) return ;
	clear(root->lchild);
	clear(root->rchild);
	free(root);
	return ;
}

void output(Node *root) {
	if (root == NIL) return ;
	output(root->lchild);
	printf("%d %d %d %d\n", 
		root->key, 
		root->color,
		root->lchild->key, 
		root->rchild->key);
	output(root->rchild);
	return ;
}


int main() {
	int x, y;
	Node *root = NIL;
	while (~scanf("%d%d", &x, &y)) {
		switch(x) {
			case 1: root = insert(root, y); break;
			case 2: root = erase(root, y); break;
			case 3: output(root); break;
		}
	}
	return 0;
}

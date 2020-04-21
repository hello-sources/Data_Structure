#include <stdio.h>
#include <stdlib.h>
 
#define ERROR 0
#define OK 1
 
typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node, *pNode;
 
pNode init(char data) {
    pNode p = (pNode)malloc(sizeof(Node));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}
 
void clear(pNode p) {
    if (!p) return ;
    if (p->lchild) {
        clear(p->lchild);
    }
    if (p->rchild) {
        clear(p->rchild);
    }
    free(p);
}
 
void output(pNode p) {
    if (p == NULL) {
        return ;
    }
    printf("%c", p->data);
    if (p->lchild == NULL && p->rchild == NULL) {
        return ;
    }
    printf("(");
    if (p->lchild) {
        output(p->lchild);
    }
    if (p->rchild) {
        printf(",");
        output(p->rchild);
    }
    printf(")");
    return ;
}
 
pNode p_arr[26] = {0};
 
int main() {
    char str[4];
    pNode root = NULL, p = NULL;
    while (scanf("%s", str) != EOF) {
        if (str[0] == str[1] && str[0] == '^') {
            break;
        }
        p = init(str[1]);
        p_arr[str[1] - 'A'] = p;
        if (str[0] == '^') {
            root = p;
        } else {
            switch (str[2]) {
                case 'L' :
                    p_arr[str[0] - 'A']->lchild = p;
                    break;
                case 'R' :
                    p_arr[str[0] - 'A']->rchild = p;
                    break;
                default :
                    printf("ERROR\n");
                    break;
            }
        }
    }
    output(root);
    printf("\n");
    clear(root);
    return 0;
}

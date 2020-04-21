#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
 
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
    if (!p) return ;
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
}
 
int main() {
    int len = 0, size = 50;
    char *str = (char *)malloc(size);
    char ch;
    str[0] = 0;
    while (scanf("%c", &ch)) {
        if (ch == '$') {
            break;
        }
        str[len++] = ch;
        if (len == size) {
            size *= 2;
            str = (char *)realloc(str, size);
        }
    }
    printf("%d\n", len);
    printf("%s\n", str);
    pNode *p_arr = (pNode *)malloc(sizeof(pNode) * (strlen(str) / 2 + 1));
    int ind = 1;
    p_arr[ind] = NULL;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') continue;
        p_arr[ind] = init(str[i]);
        if (ind != 1) {
            if (ind % 2) {
                p_arr[ind / 2]->rchild = p_arr[ind];
            } else {
                p_arr[ind / 2]->lchild = p_arr[ind];
            }
        }
        ++ind;
    }
    output(p_arr[1]);
    printf("\n");
    clear(p_arr[1]);
    free(p_arr);
    free(str);
    return 0;
}

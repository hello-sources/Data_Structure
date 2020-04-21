#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char phone_num[3][10][12] = {0};
int ind[3];
 
int main() {
    ind[0] = ind[1] = ind[2] = 0;
    int t;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &t);
        scanf("%s", phone_num[t][ind[t]++]);
    }
    for (int i = 0; i < 10; i++) {
        printf("%s", ind[0] ? (ind[0]--, phone_num[0][i]) : "0");
        for (int j = 1; j < 3; j++) {
            printf(" %s", ind[j] ? (ind[j]--, phone_num[j][i]) : "0");
        }
        printf("\n");
    }
    return 0;
}

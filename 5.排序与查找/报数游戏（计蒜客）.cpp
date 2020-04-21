#include <stdio.h>
#include <stdlib.h>

int search(int *data, int n, int value) {
    int x = 0, y = n - 1;
    int mid;
    while (x < y) {
        mid = (x + y + 1) >> 1;
        if (data[mid] == value) {
            return mid;
        } else if (data[mid] > value) {
            y = mid - 1;
        } else {
            x = mid;
        }
    }
    return x;
}
 
int main() {
    int n, m, q;
    scanf("%d%d", &n, &m);
    int *data = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", data + i);
    }
    while (m--) {
        scanf("%d", &q);
        printf("%d", data[search(data, n, q)]);
        if (m) {
            printf(" ");
        }
    }
    free(data);
    return 0;
}

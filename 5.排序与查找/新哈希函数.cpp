#include <stdio.h>
#include <string.h>
 
void f(char str[]) {
    int len, i;
    int arr[32] = {0}, bits[32] = {0};
    len = strlen(str);
    for (i = 1; i <= len; ++i) {
        arr[i % 32] += str[i - 1];
    }
    for (i = 0; i < 32; ++i) {
        bits[i] = arr[31 - i] ^ (arr[i] << 1);
        printf("%c", bits[i] % 85 + 34);
    }
    printf("\n");
}
 
int main() {
    char str[501];
    scanf("%s", str);
    f(str);
    return 0;
}

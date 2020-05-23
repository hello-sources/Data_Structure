/*************************************************************************
    > File Name: quick_select.c
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 23 May 2020 06:57:23 PM CST
 ************************************************************************/


#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define swap(a, b) { \
    __typeof(a) temp = (b); \
    b = a, a = temp; \
}
int quick_select(int *nums, int left, int right, int k) {
    int ind = left + rand() % (right - left + 1);
    swap(nums[ind], nums[left]);
    int x = left, y = right, z = nums[left];
    while (x < y) {
        while (x < y && nums[y] >= z) --y;
        if (x < y) nums[x++] = nums[y];
        while (x < y && nums[x] <= z) ++x;
        if (x < y) nums[y--] = nums[x];
    }
    nums[x] = z;
    ind = x - left + 1;
    if (ind == k) return nums[x];
    if (ind > k) return quick_select(nums, left, x - 1, k);
    return quick_select(nums, x + 1, right, k - ind);
}

int main() {
    int n, k;
    scanf("%d", &n);
    int *num = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }
    for (int i = 1; i <= min(100, n); ++i) {
        printf("%d\n", quick_select(num, 0, n - 1, i));
    }
    free(num);
    return 0;
}

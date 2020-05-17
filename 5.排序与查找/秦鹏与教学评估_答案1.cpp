/*************************************************************************
    > File Name: 秦鹏与教学评估_答案1.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 07:15:59 PM CST
 ************************************************************************/




#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 200000
struct Node {
    long long s, e, d, num;
} arr[MAX_N + 5];

long long check(Node *arr, int n, long long pos) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].e <= pos) cnt += arr[i].num;
        else if (arr[i].s > pos) continue;
        else cnt += (pos - arr[i].s) / arr[i].d + 1;
    }
    return cnt;
}

long long binary_search(Node *arr, int n, long long l, long long r) {
    if (l == r) return l;
    long long mid = (l + r) >> 1;
    if (check(arr, n, mid) % 2) return binary_search(arr, n, l, mid);
    return binary_search(arr, n, mid + 1, r);
}


void solve() {
    long long n, min_num, max_num;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &arr[i].s, &arr[i].e, &arr[i].d);
        arr[i].num = (arr[i].e - arr[i].s) / arr[i].d + 1;
        if (i == 0) {
            min_num = arr[i].s;
            max_num = arr[i].e;
        } else {
            if (arr[i].s < min_num) min_num = arr[i].s;
            if (arr[i].e > max_num) max_num = arr[i].e;
        }
    }
    long long pos = binary_search(arr, n, min_num, max_num);
    if (check(arr, n, pos) % 2) {
        printf("%lld %lld\n", pos, check(arr, n, pos) - check(arr, n, pos - 1));
    } else {
        cout << "Poor QIN Teng:(" << endl;
    }
    return ;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}

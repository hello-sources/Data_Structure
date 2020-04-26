#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
#define MAX_N 20000
#define MAX_M 100000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i, val[i] = 0;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = root;
    }
    bool merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) {
            return (val[a] + val[b]) % 2;
        }
        fa[aa] = bb;
        val[aa] = (3 + val[b] - val[a]) % 2;
        return true;
    }
};

struct Data {
    int i, j, c;
} arr[MAX_M + 5];

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    for (int i = 0; i < m; i++) {
        cin >> arr[i].i >> arr[i].j >> arr[i].c;
    }
    sort(arr, arr + m, [](const Data &a, const Data &b) {
        return a.c > b.c;
    });
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (!u.merge(arr[i].i, arr[i].j)) {
            ans = arr[i].c;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

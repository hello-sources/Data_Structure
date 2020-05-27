/*************************************************************************
    > File Name: 超市卖货.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 27 May 2020 08:54:23 PM CST
 ************************************************************************/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define MAX_N 10000
struct Data {
    int p, d;
} a[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    return a.d < b.d;
}

typedef pair<int, int> PII;
set<PII> s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].p >> a[i].d;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        if (s.size() < a[i].d) {
            s.insert(PII(a[i].p, i));
        } else if (s.begin()->first < a[i].p) {
            s.erase(s.begin());
            s.insert(PII(a[i].p, i));
        }
    }
    int ans = 0;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        ans += iter->first;
        cout << iter->first << endl;
    }
    cout << ans << endl;
    return 0;
}

/*************************************************************************
    > File Name: 逆序对个数1.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 27 May 2020 02:23:55 PM CST
 ************************************************************************/


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 500000
#define lowbit(x) ((x) & (-x))

int arr[MAX_N + 5];
int b[MAX_N + 5], c[MAX_N + 5]; 

void add (int x, int val, int n) {
	while (x <= n) c[x] += val, x += lowbit(x);
}

int query(int x) {
	return (x ? c[x] + query(x - lowbit(x)) : 0);
}

bool cmp(int x, int y) {
	return arr[x] < arr[y];
}

int main() {
	int n;
	while (cin >> n) {
		long long ans1 = 0;
		if (n == 0) break;
		memset(arr, 0, sizeof(arr));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i++) cin >> arr[i], b[i] = i;
		sort(b + 1, b + n + 1, cmp);
		for (int i = 1; i <= n; i++) arr[b[i]] = i;// cout << arr[i] << " ";
		for (int i = 1; i <= n; i++) {
			//cout << arr[i] << " ";
			long long lnum = query(arr[i]);
			//cout << lnum << endl;
			ans1 += (i - 1 - lnum);
			add(arr[i], 1, n);
		}
		cout << ans1 << endl;
	}
	return 0;
}

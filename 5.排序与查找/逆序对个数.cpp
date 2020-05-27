/*************************************************************************
    > File Name: 逆序对个数.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 27 May 2020 02:22:38 PM CST
 ************************************************************************/


#include <iostream>
using namespace std;
#define MAX_N 500000
long long arr[MAX_N + 5];
long long temp[MAX_N + 5];
long long n;

long long merge_sort(long long l, long long r) {
	if (l == r) return 0;
	long long mid = (l + r) >> 1;
	long long ans1 = merge_sort(l, mid);
	long long ans2 = merge_sort(mid + 1, r);
	long long ans3 = 0;
	long long p1 = l, p2 = mid + 1, p3 = 0;
	while (p1 <= mid || p2 <= r) {
		if (p2 > r || p1 <= mid && (arr[p1] <= arr[p2])) {
			temp[p3++] = arr[p1++];
		} else {
			ans3 += (mid - p1 + 1);
			temp[p3++] = arr[p2++];
		}
	}
	for (long long i = l; i <= r; i++) {
		arr[i] = temp[i - l];
	}
	return ans1 + ans2 + ans3; 
}

long long solve() {
	cin >> n;
	if (n == 0) return n;
	for (long long i = 1; i <= n; i++) cin>>arr[i];
	cout << merge_sort(1, n) << endl;
	return n;
}

int main() {
	while (solve());
	
	return 0;
}

/*************************************************************************
    > File Name: 糖果传递.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 08:22:02 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm> 
#include <cmath>
using namespace std;
#define MAX_N 1000000
long long a[MAX_N + 5];
long long s[MAX_N + 5];
long long g[MAX_N + 5];
long long n, sum = 0, c, ans = 0;

int main() {
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		sum += a[i];  
	}
	c = sum / n;
	for (long long i = 1; i <= n; i++) {
		g[i] = s[i] - i * c;
	}
	sort(g + 1, g + 1 + n);
	c = g[n / 2];
	for (long long i = 1; i <= n; i++) {
		ans += abs(g[i] - c);
	}
	cout << ans << endl;
	return 0;
}

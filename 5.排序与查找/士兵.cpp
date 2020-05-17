/*************************************************************************
    > File Name: 士兵.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 09:29:26 PM CST
 ************************************************************************/


#include <iostream>
#include <algorithm> 
using namespace std;
#define MAX_N 10000
int x[MAX_N + 5];
int w[MAX_N + 5];
int y[MAX_N + 5];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i]; 
	sort(y, y + n);
	sort(x, x + n);
	for (int i = 0; i < n; i++) w[i] = x[i] - i;
	sort(w, w + n);
	int sum = 0, cy = y[n / 2], cw = w[n / 2];
	for (int i = 0; i < n; i++) {
		sum += abs(cy - y[i]);
		sum += abs(cw - w[i]);
	}
	cout << sum << endl;
	return 0;
}

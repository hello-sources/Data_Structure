#include <iostream>
using namespace std;
#define MAX_N 500000

//int a[MAX_N + 5];
//int s[MAX_N + 5], tail = -1;
int x[MAX_N + 5], y[MAX_N + 5];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> y[i];
	int p = 1, t1 = 0, t2 = 0;
	while (p < n) {
		while (t1 != -1 && x[p] <= x[t1]) --t1;
		while (t2 != -1 && y[p] <= y[t2]) --t2;
		if (t1 - t2) break;
		x[++t1] = x[p];
		y[++t2] = y[p];
		p++;
	}
	cout << p << endl;
	return 0;
}

#include <iostream>
using namespace std;
#define MAX_N 300000

int a[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	q[tail++] = 0;
	int ans = a[1];
	for (int i = 1; i <= n; i++) {
		if (i - q[head] > m) head++;
		ans = max(ans, a[i] - a[q[head]]);
		while (tail - head && a[i] < a[q[tail - 1]]) tail--;
		q[tail++] = i;
	}
	cout << ans << endl;
	return 0;
}

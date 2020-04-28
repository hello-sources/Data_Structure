#include <iostream>
using namespace std;
#define MAX_N 100000

long long a[MAX_N + 5];
long long s[MAX_N + 5], top = -1;
long long l[MAX_N + 5], r[MAX_N + 5];

int main() {
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	a[0] = a[n + 1] = -1;
	s[top = 0] = 0;
	for (long long i = 1; i <= n; i++) {
		while (a[s[top]] >= a[i]) --top;
		l[i] = s[top];
		s[++top] = i;
	}
	s[top = 0] = n + 1;
	for (long long i = n; i >= 1; i--) {
		while (a[s[top]] >= a[i]) --top;
		r[i] = s[top];
		s[++top] = i;
	}
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		ans = max(ans, a[i] * (r[i] - l[i] - 1));
	}
	cout << ans << endl;
	return 0;
}

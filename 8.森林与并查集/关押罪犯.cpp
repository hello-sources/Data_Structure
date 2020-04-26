#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20000
#define MAX_M 100000
int fa[MAX_N + 5], val[MAX_N + 5];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		val[i] = 0;
	}
	return ;
}

int get(int x) {
	if (x == fa[x]) return x;
	int root = get(fa[x]);
	val[x] += val[fa[x]];
	val[x] %= 2;
	return fa[x] = root;
}

int merge(int a, int b, int t) {
	int x = get(a), y = get(b);
	if (x == y) {
		return (val[a] - val[b] - t) % 2 == 0;
	}
	fa[x] = y;
	val[x] = (t + val[b] - val[a] + 2) % 2;
	return 1;
}

struct Data {
	int x, y, c;
} arr[MAX_M + 5];

bool cmp(const Data &a, const Data &b) {
	return a.c > b.c; 
}

int main() {
	int n, m;
	cin >> n >> m;
	init(n);
	for (int i = 0; i < m; i++) {
		cin >> arr[i].x >> arr[i].y >> arr[i].c;
	}
	sort(arr, arr + m, cmp);
	arr[m].x = arr[m].y = 1;
	arr[m].c = 0;
	for (int i = 0; i <= m; i++) {
		if (merge(arr[i].x, arr[i].y, 1)) continue;
		cout << arr[i].c << endl;
		break;
	}
	return 0;
}


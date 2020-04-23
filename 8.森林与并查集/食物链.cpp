#include <iostream>
using namespace std;
#define MAX_N 50000

//fa表示，val数组表示的是对应的同余结果 
int fa[MAX_N + 5], val[MAX_N + 5];

//并查集初始化 
void init(int n) {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		val[i] = 0;//同余结果初始化为0 
	}
	return ;
}

int get(int x) {
	if (x == fa[x]) return x;
	int root = get(fa[x]);
	val[x] += val[fa[x]];
	val[x] %= 3;
	return fa[x] = root;
}

int merge(int x, int y, int t) {
	int a = get(x), b = get(y);
	if (a == b) {
		return (val[x] - val[y] - t) % 3 == 0; 
	}
	fa[a] = b;
	val[a] = (t + val[y] - val[x] + 3) % 3;
	return 1;
}

int main() {
	int n, k, ans = 0;
	cin >> n >> k;
	init(n);
	for (int i = 0; i < k; i++) {
		int x, y, t;
		cin >> t >> x >> y;
		//权值的设置，由于关系有1与2，我们设置的权值为0同类，1吃，2被吃，
		//对应关系直接减去一即可 
		t -= 1;
		//判断x，y是否都小于n，且merge结果为真就表示是真话 
		if (x <= n && y <= n && merge(x, y, t)) continue;
		ans += 1;
	}
	cout << ans << endl;
	return 0;
} 

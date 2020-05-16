#include <iostream>
using namespace std;

int arr[10010], key[10010];
int f1(int x) {
	if (x == arr[x])
		return x;
	int root = f1(arr[x]);
	key[x] += key[arr[x]];
	key[x] %= 3;
	return arr[x] = root;
}

void f2(int x, int y) {
	int xx = f1(x), yy = f1(y);
	if (xx == yy)
		return;
	arr[xx] = yy;
	key[xx] = (key[y] - key[x] + 5) % 3;
	return;
}

int main() {
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		key[i] = 0;
	}
	while (m--) {
		cin >> a >> b >> c;
		
		if (a == 1)
			f2(b, c);
		else {
			int bb = f1(b), cc = f1(c), temp = (key[b] - key[c] + 3) % 3;
			if (bb - cc)
				cout << "Unknown" << endl;
			else {
				if (temp == 0)
					cout << "Tie" << endl;
				else if (temp == 1)
					cout << "Loss" << endl;
				else
					cout << "Win" << endl;
			}
		}
	}
	return 0;
}


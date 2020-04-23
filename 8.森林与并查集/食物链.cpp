#include <iostream>
using namespace std;
#define MAX_N 50000

//fa��ʾ��val�����ʾ���Ƕ�Ӧ��ͬ���� 
int fa[MAX_N + 5], val[MAX_N + 5];

//���鼯��ʼ�� 
void init(int n) {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		val[i] = 0;//ͬ������ʼ��Ϊ0 
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
		//Ȩֵ�����ã����ڹ�ϵ��1��2���������õ�ȨֵΪ0ͬ�࣬1�ԣ�2���ԣ�
		//��Ӧ��ϵֱ�Ӽ�ȥһ���� 
		t -= 1;
		//�ж�x��y�Ƿ�С��n����merge���Ϊ��ͱ�ʾ���滰 
		if (x <= n && y <= n && merge(x, y, t)) continue;
		ans += 1;
	}
	cout << ans << endl;
	return 0;
} 

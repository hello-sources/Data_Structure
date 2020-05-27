/*************************************************************************
    > File Name: 奇数码问题.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 27 May 2020 11:20:01 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define lowbit(x) ((x) & (-x))
int n, c[250005];
/*
	*将二维矩阵转换为一维向量，转换为求解逆序对问题，
	*去掉数字0，因为0 的左右移动不影响整个串顺序，
	*对于0上下移动类似于 swap(s[i], s[i - n - 1]) / swap(s[i], s[i + n - 1])  
	*因为n^2 - 1 为偶数, 所以逆序对的改变只能为偶数由以上推导, 若A, B向量的逆序对奇偶性相同, 则必定可以转换得解 
*/

void add(int x, int val, int n) {
	while (x <= n) c[x] += val, x += lowbit(x);
}

int query(int x) {
	return (x ? c[x] + query(x - lowbit(x)) : 0);
}

int calc() {
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (!x) continue; 
		cnt += query(n) - query(x);
		add(x, 1, n);
	}
	return cnt & 1;
}

int main() {
	cin >> n;
	n *= n;
	if (calc() == calc()) cout << "TAK" << endl;
	else cout << "NIE" << endl;
	return 0;
}

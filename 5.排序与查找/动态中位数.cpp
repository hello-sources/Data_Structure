/*************************************************************************
    > File Name: 动态中位数.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 27 May 2020 02:21:09 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

void solve() {
	int a, b, num, cnt = 0;
	priority_queue<int> maxh;
	priority_queue<int, vector<int>, cmp> minh;
	cin >> a >> b;
	cout << a << " " << (b + 1) / 2 << endl;
	for (int i = 1; i <= b; i++) {
		cin >> num;
		if (maxh.size() == 0 || num <= maxh.top()) {
			maxh.push(num);
		} else {
			minh.push(num);
		}
		//对应返回值是无符号整型数字 
		int max_cnt = maxh.size(), min_cnt = minh.size();
		if (max_cnt - min_cnt >= 2) {
			minh.push(maxh.top());
			maxh.pop();
		}
		if (min_cnt - max_cnt >= 2) {
			maxh.push(minh.top());
			minh.pop();
		}
		if (i % 2 == 0) continue;
		int x = minh.size() > maxh.size() ? minh.top() : maxh.top();
		cnt += 1;
		if (cnt % 10 == 1 && cnt != 1) cout << endl;
		cout << x << " ";
	}
	cout << endl;
	return ;	 
}

int main() {
	int n;
	cin >> n;
	while (n--) solve();	
	return 0;
} 

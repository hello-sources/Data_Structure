# Parity_game

#### 题目描述

 现在你和你的朋友正在玩一种游戏。 你的朋友写下一串0和1的序列，然后你选择其中一串子序列（如[3,5][3,5]）并且问他这个序列是包含奇数个1还是偶数个1（和是奇数还是偶数）。 你可以问你的朋友任意个问题，而你的朋友会回答你的问题。 你的任务是猜出整个朋友的序列。

 但是，你发现你的朋友告诉你的信息可能有误，所以你想写一个程序来指出他的错误。这个程序应该接受一系列你的问题和答案。程序的目标是找到第一个错误的答案。

------

#### 输入

 输入的第1行是序列长度L(L≤1000000000）

 输入的第2行是问题的数量Q(Q≤5000)

 接下来Q行包括所有的问题

 每一行由两个整数 l,r和描述奇偶的一个单词even或者odd组成

 当单词为 even 时 [l,r][l,r] 的和为偶数。

 当单词为 odd 时 [l,r][l,r] 的和为奇数。

#### 输出

 输出只有一行，输出一个整数X，表明该序列符合了前X个问题和答案。（不满足第X+1个问题）

 如果序列符合所有问题的要求，应输出问题的数量Q。

#### 输入样例1

```
10
5
1 2 even
3 4 odd
5 6 even
1 6 even
7 10 odd
```

#### 输出样例1

```
3
```

- **解题思路**

> 采用了坐标映射+并查集思想，就是我们按照从小到大的顺序来对于左右两个坐标进行排序，分别映射成为数字从1开始的顺序数，然后进行处理

- **解题代码**

``` c
#include <iostream>
#include <map>
using namespace std;
#define MAX_N 10000
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

int merge(int x, int y, int t) {
	int a = get(x), b = get(y);
	if (a == b) {
		return (val[x] - val[y] - t) % 2 == 0;
	}
	fa[a] = b;
	val[a] = (t + val[y] - val[x] + 2) % 2;
	return 1;
}

map<int, int> ind;
int ind_cnt = 0;

struct Data{
	int x, y;
	string t;
} arr[MAX_N + 5];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i].x >> arr[i].y >> arr[i].t;
		arr[i].y += 1;
		ind[arr[i].x] = 0;
		ind[arr[i].y] = 0;
	}
	for (auto iter = ind.begin(); iter != ind.end(); iter++) {
		iter->second = (++ind_cnt);
	}
	init(ind_cnt);
	for (int i = 0; i < m; i++) {
		if (merge(ind[arr[i].x], ind[arr[i].y], arr[i].t[0] == 'o')) continue;
		cout << i << endl;
		return 0;
	}
	cout << m << endl;
//	for (int i = 0; i < m; i++) {
//		cout << ind[arr[i].x] << " " << ind[arr[i].y] << endl;
//	}
	return 0;
} 
```


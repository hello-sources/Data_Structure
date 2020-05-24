/*************************************************************************
    > File Name: 楼兰图腾.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 24 May 2020 03:57:26 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000
#define lowbit(x) ((x) & (-x))
/*这里用到了一个编程技巧，就是计算机中负数对应的值是按照补码的形式实现的，当一个数“与&”上他的补码的时候对应的，补码位置要加1，导致原来位置与的结果都是零，产生进位得到值就是对应的该数字的从右到左第一个不为0的值*/

int c[MAX_N + 5] = {0};

void add(int i, int val, int n) {
	while (i <= n) c[i] += val, i += lowbit(i);
	return ;
}

//树状数组查询对应前缀和
int S(int i) {
	int sum = 0;
	while (i) sum += c[i], i -= lowbit(i);
	return sum;
}

int main() {
	int n, a;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cout << S(a) << endl;//输出对应标记数组中的值
		add(a, 1, n);//对应标记数为1
	}
	for (int i = 1; i <= n; i++) {
		cout << i << ":"  << c[i] << " " << S(i) - S(i - 1) << endl;
	}
 
	return 0;
}


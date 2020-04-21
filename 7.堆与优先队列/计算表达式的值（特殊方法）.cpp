//使用优先级高低解决表达式求值问题
//使用系统栈的结构 
//此代码依然具有问题，计算答案不对，乘除法不对特殊数字也不对 
#include <stdio.h>
#include <limits.h> 
#include <string.h>
#include <math.h>
#define max_n 100
 
 //找优先级高低位置 
int calc(const char *str, int l, int r) {//字符串不可改变，所以按照常量处理 
	int prior = 0x3f3f3f3f - 1, temp = 0, pos = -1;
	for (int i = l; i <= r; i++) {
		int cur_prior = 0x3f3f3f3f;//暂时定义当前优先级 
		switch (str[i]) {
			case '(': temp += 100; break;
			case ')': temp -= 100; break;
			case '+': 
			case '-': cur_prior = temp + 1; break;
			case '*':
			case '/': cur_prior = temp + 2; break;
			case '^': cur_prior = temp + 3; break;
		}
		if (cur_prior <= prior) {
			prior = cur_prior;
			pos = i;//找到优先级最低的位置 
		}
	}
	//通过for循环找到一个优先级最低的位置
	if (pos == -1) {
		//代表没有找到优先级最低符号的位置
		//代表当前是一个数字
		int num = 0;
		for (int i = l; i <= r; i++) {
			if (str[i] < '0' || str[i] > '9') continue; 
			num = num * 10 + str[i] - '0';
		} 
		return num;
	}
	int a = calc(str, l, pos - 1);
	int b = calc(str, pos + 1, r); 
	switch (str[pos]) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
		case '^': return (int)pow(a, b);
	}
	return 0;
}


int main() {
	char str[max_n +5] = {0};	
	while (scanf("%[^\n]s", str) != EOF) {
		getchar();//主动吞掉字符 
		printf("%d\n", calc(str, 0, strlen(str) - 1));
	}	
	return 0;
} 

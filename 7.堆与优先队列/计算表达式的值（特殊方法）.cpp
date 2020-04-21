//ʹ�����ȼ��ߵͽ�����ʽ��ֵ����
//ʹ��ϵͳջ�Ľṹ 
//�˴�����Ȼ�������⣬����𰸲��ԣ��˳���������������Ҳ���� 
#include <stdio.h>
#include <limits.h> 
#include <string.h>
#include <math.h>
#define max_n 100
 
 //�����ȼ��ߵ�λ�� 
int calc(const char *str, int l, int r) {//�ַ������ɸı䣬���԰��ճ������� 
	int prior = 0x3f3f3f3f - 1, temp = 0, pos = -1;
	for (int i = l; i <= r; i++) {
		int cur_prior = 0x3f3f3f3f;//��ʱ���嵱ǰ���ȼ� 
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
			pos = i;//�ҵ����ȼ���͵�λ�� 
		}
	}
	//ͨ��forѭ���ҵ�һ�����ȼ���͵�λ��
	if (pos == -1) {
		//����û���ҵ����ȼ���ͷ��ŵ�λ��
		//����ǰ��һ������
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
		getchar();//�����̵��ַ� 
		printf("%d\n", calc(str, 0, strlen(str) - 1));
	}	
	return 0;
} 

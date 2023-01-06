#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>


void print(int n) {
//接收一个整型值(无符号)，按照顺序打印它的每一位
//如 1234， 1 2 3 4
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ",n%10);
}

int Strlen(char* a) {
	//编写函数不允许创建中间变量，求字符串的长度
	if (*a == '\0') {
		return 0;
	}
	else {
		return 1 + Strlen(a + 1);
	}
}

int count = 0;
int factorial(int n) {
//求n得阶乘//暂不考虑溢出--->效率太低

	if (n == 3) {
		count++;
	}

	if (n <= 1) {
		return 1;

	}
	else {
		return n * factorial(n - 1);
	}
}

int factorial2(int n) {
	//求n得阶乘//暂不考虑溢出--->效率太低

	int i = 1;
	int ret = 1;
	for (i = 1; i <= n; i++) {
		ret *= i;
	}
	return ret;
}

int main() {
	SetConsoleOutputCP(65001);
	int num = 1234;
	print(num);
	printf("\n");
	char p[] = "abcdef";
	int len = Strlen(p);
	printf("len=%d\n", len);

	int input = 0;
	int res = 0;
	printf("计算n得阶乘请输入n:\n");
	scanf("%d", &input);
	res = factorial(input);
	printf("%d 得阶乘计算结果是:%d\n", input, res);
	printf("count=%d\n", count);
	printf("for factorial :%d", factorial2(input));
	return 0;


}
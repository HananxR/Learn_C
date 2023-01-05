#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main() {
	//计算阶乘：1!+2!+3!+...n!
	//版本1：
	int n = 0;//输入n
	int i = 1;
	int sum = 0;
	int tmp = 1;
	printf("请输入变量n\n");
	scanf("%d", &n);
	printf("输入的变量n=%d\n", n);
	for (; i <= n; i++) {
		tmp = 1;
		for (int j = 1; j <= i; j++) {
			tmp = j * tmp;
			printf("i=%d,j=%d,tmp=%d\n", i, j, tmp);
		}
		sum += tmp;
	}
	printf("版本1：%d的阶乘累加和为%d\n", n, sum);
	/*存在的问题：
	* 存在重复过程
	*/

	//版本2
	//初始化过程版本1中的变量
	tmp = 1;
	sum = 0;
	for (i = 1; i <= n; i++) {
		tmp *= i;
		sum += tmp;
	}

	printf("版本2：%d的阶乘累加和为%d\n", n, sum);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int NarcissisticNumber(int num) {

//判断当前数字是不是水仙花数，如果是返回1，否则返回0
//所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。
//例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。
	int sum = num;
	while (num) {
		int tmp = num % 10;
		sum -= tmp * tmp * tmp;
		num = num / 10;
		
	}
	return (sum == 0) ? 1 : 0;

}


int main01() {
	for (int i = 100; i < 1000; i++) {
		int tmp = NarcissisticNumber(i);
		if (tmp == 1) {
			printf("%d\n", i);
		}
	}
	return 0;
}


void Factorization(unsigned int num) {
//将一个正整数分解质因数
	for (int i = 2; i <= num; i++) {
		while (num % i == 0) {
			printf("%d", i);
			num /= i;
			if (num != 1)
				printf("*");
		}
	}
}

int main02() {
	unsigned int n;
	printf("请输入整数:\n");
	scanf("%d", &n);
	printf("%d=", n);
	Factorization(n);
	printf("\n");
	return 0;
}


char OutputGrade(int num) {
	//利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，
	//60-89分之间的用B表示，60分以下的用C表示。
	return (num >= 90) ? 'A' : ((num >= 60)?'B':'C');
}

int main03() {
	unsigned int num = 90;
	int score = 0;
	scanf("%d", &score);
	char res = OutputGrade(score);
	printf("%c\n", res);
	return 0;
}

int gcd(int a, int b) {
//求解a和b的最大公因数
	if (b) {
		while ((a %= b) && (b %= a));
	}
	return a + b;
}

int main() {

	int a = 252;
	int b = 105;
	int res = gcd(a, b);
	printf("%d\n", res);
}




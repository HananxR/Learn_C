#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<math.h>
/*
题目：判断 101 到 200 之间的素数。

程序分析：判断素数的方法：用一个数分别去除 2 到 sqrt(这个数)，如果能被整除，则表明此数不是素数，反之是素数。

*/

int isPrime(int x) {
	//判断x是否是素数
	for (int i = 2; i < (int)sqrt(x); i++) {
		if (x % i == 0) {
			return 1;
		}
	}
	return 0;
}

int main() {

	for (int j = 101; j < 200; j++) {
		if (isPrime(j) == 0) {
			printf("%3d\t", j);
		}
	}
	return 0;
}
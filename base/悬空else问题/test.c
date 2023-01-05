#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main() {

	int a = 0;
	int b = 0;
	/*if (a == 1)
		if (b == 2)
			printf("hehe\n");
		else
			printf("haha\n");*/
	if (a == 1) {
		if (b == 2) {
			printf("hehe\n");
		}
	}
	else {
		printf("haha\n");
	}
	return 0;
}
/*
输出结果为空
else自动就近匹配造成
解决方案：适当的使用的{}可以使代码的逻辑更加清楚

*/
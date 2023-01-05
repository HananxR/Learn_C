#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<windows.h>
/*
* 题目：输入三个整数x,y,z，请把这三个数由小到大输出。

程序分析：我们想办法把最小的数放到x上，先将x与y进行比较，如果x>y则将x与y的值进行交换，
然后再用x与z进行比较，如果x>z则将x与z的值进行交换，这样能使x最小。

*/
int main() {
	SetConsoleOutputCP(936);
	printf("\n,请输入三个整数，格式：100，200，300\n");
	//结果从小到大排列
	int x, y, z;
	int temp = 0;//中间变量
	scanf("%d,%d,%d", &x, &y, &z);
	printf("xyz:%d,%d,%d\n", x, y, z);
	if (x > y) {
		temp = x;
		x = y;
		y = temp;
	}
	printf("xyz:%d,%d,%d\n", x, y, z);
	if (x >= z) {
		printf("大小顺序：%d<=%d<=%d\n", z, x, y);
	}
	else if (y <= z) {
		printf("大小顺序：%d<=%d<=%d\n", x, y, z);
	}
	else {
		printf("大小顺序：%d<=%d<=%d\n", x, z, y);
	}


	return 0;
}
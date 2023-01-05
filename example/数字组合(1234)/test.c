#define _CRT_SECURE_NO_WARNINGS 1

/*
题目001：有1、2、3、4四个数字，能组成多少个互不相同和无重复数字的三位数？都是多少？
程序分析：可填在百位、十位、个位的数字都是1、2、3、4，组成所有的排列后再去掉不满条件的排列。

*/

#include <stdio.h>
int main() {
	int i, j, k;
	printf("\n");
	for (i = 1; i < 5; i++) {//以下为三重循环
		for (j = 1; j < 5; j++) {
			for (k = 1; k < 5; k++) {//确保i,j,k三位互不相同
				if (i != k && i != j && j != k) {
					printf("%d,%d,%d\n", i, j, k);
				}

			}
		}

	}

	return 0;
}
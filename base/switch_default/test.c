#define _CRT_SECURE_NO_WARNINGS 1

/*
* default子句
* 当switch表达式的值并不能匹配所有的case标签的值时，
* 这个default子句后的语句就会执行
*/

#include <stdio.h>
int main() {
	int n = 1;
	int m = 2;
	switch (n) {
	case 1: m++;
	case 2:n++;
	case 3:
		switch (n) {
			//switch允许嵌套使用
		case 1:n++;
		case 2:m++;
			n++;
			break;

		}
		//当前case后无break
	case 4:
		m++;
		break;
	default:
		break;

	}
	printf("m=%d,n=%d\n", m, n);
	//m=5,n=3
	return 0;
}
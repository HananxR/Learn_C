#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

void new_line() {
	printf("hehe\n");
}


void three_line() {
	for (int i = 0; i < 3; i++) {
		new_line();
	}
}
int main() {
	//嵌套调用
	three_line();
	//链式访问
	char arr[20] = "hello";
	int ret = strlen(strcat(arr, " world"));
	printf("%d\n", ret);
	//printf返回值是字符串的长度
	//典型案例
	printf("%d", printf("%d", printf("%d", 43)));
	//输出结果 43 2 1
	//第一个是实际值，后面开始将其当作字符串，显示其长度
	return 0;
}
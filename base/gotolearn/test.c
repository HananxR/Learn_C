#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	//go to语句
	char input[10] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("请输入‘哈哈’，否则电脑自动关机\n");
	scanf("%s", &input);
	if (strcmp(input, "哈哈")) {
		system("shutdown -a");
	}
	else {
		goto again;
	}
	return 0;
}
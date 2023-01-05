#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main() {
	/*
	* 需求1：按照输入的数字输出对应的星期
	*/
	/*int day = 2;
	switch (day) {
	case 1:printf("星期1"); break;
	case 2:printf("星期2"); break;
	case 3:printf("星期3"); break;
	case 4:printf("星期4"); break;
	case 5:printf("星期5"); break;
	case 6:printf("星期6"); break;
	case 7:printf("星期7"); break;
	}*/
	/*
	* 需求2：
	* 输入1-5：输出weekday
	* 输入6-7输出weekend
	*/
	int day = 2;
	switch (day) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("weekday\n");
		break;
	case 6:
	case 7:
		printf("weekend\n");
		break;//break的实际效果是把语句列表划分为不同的分支部分
	}
	return 0;
}
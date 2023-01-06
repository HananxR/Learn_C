#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<string.h>
#include <windows.h>
/*
需求：编写代码，演示多个字符从两端移动，向中间汇聚。
*/
int main() {
	char arr[] = "Hello.World!";
	char mask[] = "############";
	int left = 0;
	int right = strlen(arr) - 1;
	printf("arr=%d\n", right + 1);
	//while循环实现
	/*while (left <= right) {
		Sleep(2000);
		mask[left] = arr[left];
		mask[right] = arr[right];
		left++;
		right--;
		printf("%s\n", mask);
	}*/

	//for循环实现
	for (left = 0, right = strlen(arr) - 1;
		left <= right;
		left++, right--) {
		Sleep(1000);
		mask[left] = arr[left];
		mask[right] = arr[right];
		printf("%s\n", mask);
		system("cls");//清屏

	}
	return 0;
}
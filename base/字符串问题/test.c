#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	char arr1[] = "abc";//数组
	// 后面隐藏了'\0'值是0
	char arr2[] = { 'a','b','c',0 };//数组
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%d\n", strlen(arr1));
	printf("%d\n", strlen(arr2));
	printf("\a(are you OK??))");
	printf("\132");//转换成ASCII--->Z

	return 0;


}
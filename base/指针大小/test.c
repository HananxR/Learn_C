#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main() {
	int a = 10;
	int* p = &a;
	*p = 20;
	printf("%p,%d\n", p, a);
	printf("pointer size:%d", sizeof(p));
	//指针大小在32位平台上是4个字节；64位字节上是8个字节；
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>


int get_max(int x, int y) {
	if (x >= y)
		return x;
	else
		return y;
}

void swap(int x, int y) {
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}


void swap2(int* px, int* py) {
	int tmp = 0;
	tmp = *px;
	(*px) = (*py);
	(*py) = tmp;


}

int is_prime(int x) {
//判断输入的x是不是素数
	for (int i = 2; i < x; i++) {
		if (x % i == 0)
			return 1;//1不是素数
	}
	return 0;//是素数
}

int is_leap(int x) {
//判断x是不是闰年
	if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0))
		return 0;
	else
		return 1;
}

void auto_add1(int* x) {
//每调用函数一次，变量自动加1
	(*x)++;
}


int binary_search(int* a, int k, int sz) {

//实现查找
//需要注意的是，输出当作实参传递时，传入的实际参数值为第一个元素的地址
	int left = 0;
	int right = sz - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] < k)
			left = mid + 1;
		else if(a[mid] > k)
			right = mid - 1;
		else
			return mid;
	}
	return -1;

}

int main() {
	SetConsoleOutputCP(65001);
	int a = 10;
	int b = 20;
	printf("before a=%d b=%d\n", a, b);
	int res = get_max(a, b);//获取a和b中的最大值
	printf("max value=%d\n", res);
	swap(a, b);
	printf("after a=%d b=%d\n", a, b);
	//此时a和b的值并未实现交换，主要原因是形参不影响实参的值,两个数值对应的内存地址不同
	swap2(&a, &b);
	printf("after2 a=%d b=%d\n", a, b);
	//此时可以正常交换
	printf("请输入一个整数:\n");
	int input = 0;
	scanf("%d", &input);
	int res2 = 0;
	res2 = is_prime(input);
	if (res2 == 1)
		printf("%d 不是素数\n",input);
	else
		printf("%d是素数\n", input);

	int res3 = 0;
	res3 = is_leap(input);

	if (res3 == 1)
		printf("%d 不是闰年\n", input);
	else
		printf("%d是闰年\n", input);
	for (int k = 0; k < 3; k++) {
		printf("x的调用前的值为:%d\n", input);
		auto_add1(&input);
		printf("x的调用后的值为:%d\n", input);
	}

	//-----------------------
	int z[] = { 1,2,3,4,5,6,7,8,9,10 };
	int z_k = 7;
	int sz = 0;
	sz = sizeof(z) / sizeof(z[0]);
	int res4 = 0;
	res4 = binary_search(z, z_k, sz);
	printf("res4=%d\n", res4);
	return 0;
}
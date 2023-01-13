#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main01() {

	char ch = 'w';
	char* pc = &ch;
	*pc = 'w';

	/*char* pstr = "hello world.";*/
	const char* pstr = "hello world.";
	printf("%s\n", pstr);
	//*pstr = "W";//不能修改
	//printf("%s\n", pstr);
	return 0;

}

int main02() {

	char str1 = "hello bit.";
	char str2[] = "hello bit.";
	const char* str3 = "hello bit.";
	const char* str4 = "hello bit.";
	if (str1 == str2) {
		printf("str1 and str2 are same\n");
	}
	else {
		printf("str1 and str2 are not same\n");//output
	}

	if (str3 == str4) {
		printf("str3 and str4 are same\n");
	}
	else {
		printf("str3 and str4 are not same\n");//output
	}
	return 0;
 }


int main03() {


	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", arr + 1);
	printf("%p\n", &arr);
	printf("%p\n", &arr+1);
	//9c0-998=28=16*2+8=40

	return 0;
}


int main04() {

	int arr[10] = { 1,2,3,4,5,6,7,8,9 ,0};
	int(*p)[10] = &arr;//把数组arr的地址赋值给数组指针变量p
	//但是我们一般很少这样写代码
	return 0;
}

void print_arr1(int arr[3][5],int row, int col) {

	int i = 0;
	for (i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%-2d ", arr[i][j]);
		}
		printf("\n");
	}
}


void print_arr2(int(*arr)[5], int row, int col) {

	int i = 0;
	for (i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%-2d ", arr[i][j]);
		
		}
		printf("\n");
	}
}


int main05() {
	//数组指针的使用
	int arr[3][5] = { { 1,2,3,4,5 }, { 6, 7, 8, 9, 10 }, { 7,8,9,10,11 } };
	print_arr1(arr, 3, 5);
	//数组名arr，表示首元素的地址
	//但是二维数组的首元素是二维数组的第一行
	//所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
	//可以数组指针来接收
	printf("--------------------------------------------\n");
	print_arr2(arr, 3, 5);
	return 0;
}



void test(int arr[]) {}//ok
//void test(int arr[10]) {}//ok
//void test(int* arr) {}//ok
//void test2(int* arr[20]) {}//ok
void test2(int** arr) {}//ok,因为arr本身就是指针数组


int main06() {


	int arr[10] = { 0 };
	int* arr2[20] = { 0 };
	test(arr);
	test2(arr2);
	return 0;
}

void print(int* p, int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d\n", *(p + i));
	}
	printf("\n");

}

int main07() {
	//一级指针传参
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//一级指针p,传给函数
	print(p, sz);
	print(arr, sz);
	print(&arr, sz);
	return 0;
}


void test_char(char* p) {}

int main08() {
	char ch = 'w';
	char* p1 = &ch;
	test(&ch);//ok
	test(p1);//ok
	return 0;
}


void test_001(int **ptr) {

	printf("num=%d\n", **ptr);
}


int main() {

	int n = 10;
	int *p = &n;
	int **pp = &p;
	test_001(pp);
	test_001(&p);
	return 0;
}
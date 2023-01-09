#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<string.h>
#include <windows.h>
int main01() {
	//创建数组
	//int arr1[10];
	//char arr3[10];
	//float arr4[10];
	//double arr5[10];
	int arr1[10] = { 1,2,3 };
	//数组在创建的时候如果不想指定数组数组的大写
	//数组元素的个数由初始化的内容；唉确定
	int arr2[] = { 1,2,3 };
	//打印数据元素
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	int sz1= sizeof(arr1) / sizeof(arr1[0]);
	printf("sz1=%d sz2=%d\n", sz1, sz2);
	for (int i = 0; i < sz2; i++) {
		printf("arr[%d]=%d\n", i, arr2[i]);
	}

	char ch1[5] = { 'b','i','t' };
	char ch2[] = { 'b','i','t' };
	printf("sizeof=%d\n", sizeof(ch1));
	printf("sizeof=%d\n", sizeof(ch2));
	printf("strlen=%d\n", strlen(ch1));//3
	printf("strlen=%d\n", strlen(ch2));//随机值42
	return 0;

}

int main02() {
	//一维数组在内存中的存储
	int arr[10] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++) {
		printf("&arr[%d]=%p\n",i,&arr[i]);//间隔4个字节，连续存储

	}
	return 0;
}


int main03() {
	//二维数组创建
	int arr[3][4] = { {1,2},{3,4} };
	//二维数组如果有初始化，行可以省略，列不能省略
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("&arr[%d][%d]=%p\n", i, j, &arr[i][j]);
		}
	}
	//二维数组，按行连续存储


	//数组越界问题
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 12; i++) {
		printf("%d\n", arr2[i]);
	}
	//C语言本身是不做数组下标的越界检查，编译阿奇也不一定报错，
	//当时编译器不报错，并不意味着程序是正确的
	return 0;
}

void bubble_sort(int* arr, int sz) {

//实现冒泡排序:从大到小
	printf("sz=%d\n", sz);
	for (int i = 0; i < sz - 1; i++) {

		//优化：如果一轮都尾出现调整顺序，说明数据不需要再排序
		int flag = 1;//假定不需要排序
		for (int j = 0; j < sz - 1 - i; j++) {
			if (arr[j] < arr[j+1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		
		}
		if (0 == flag) {
			printf("冒泡排序提前完成任务!\n");
			break;
		}
	}
}


int main04() {
	SetConsoleOutputCP(65001);
	/*int arr[] = { 3,1,7,5,8,9,0,2,4,6 };*/
	int arr[] = { 9,0,1,2,3,4,5,6,7,8 };

	int sz = sizeof(arr) / sizeof(arr[0]);
	//实现冒泡排序
	bubble_sort(arr,sz);
	//数组传参时，传递的其实时数组首元素的地址
	//然后打印数据
	
	for (int i = 0; i < sz; i++) {
		printf("arr[%d]=%d\n", i, arr[i]);
	}
	return 0;

}

/*
* 数组名是什么？
* 数组名是数组首元素的地址
* 但有两个列外
* 1.sizeof(数组名):数组名表示整个数组-
* 计算的是整个数组的大小，单位是字节
* 2.&数组名：数据名表示整个数组，取出的是整个数组的地址
* 


*/
int main() {

	int arr[3] = { 0 };
	printf("%d\n", sizeof(arr));
	printf("%p\n", &arr);//&arr取出的是整个数组的地址
	printf("%p\n", &arr + 1);//&arr[0]+sizeof(arr)


	printf("%p\n", arr);//&arr取出的是整个数组的地址
	printf("%p\n", arr + 1);

	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[0] + 1);
}

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main01() {
	int n = 10;
	char* pc = (char*)&n;
	int* pi = &n;
	printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc + 1);
	printf("%p\n", pi);
	printf("%p\n", pi + 1);
	//指针类型的意义：
	//1指针类型决定了：指针解引用的权限有多大
	//2指针类型决定了，指针走一步，能走多远(步长)
	return 0;
}

int main02() {

	int arr[10] = { 0 };
	int* p = arr;
	for (int i = 0; i < 10; i++) {
		*(p + i) = 1;
	/*	*p = 1;
		p++;*/
	}

	for (int i = 0; i < 10; i++) {
	
		printf("%d\n", arr[i]);
	}
}


void print(int arr[], int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[], int sz) {

	int left = 0;
	int right = sz - 1;
	while (left <= right) {
		arr[left] = arr[left] ^ arr[right];
		arr[right]= arr[left] ^ arr[right];
		arr[left]=arr[left] ^ arr[right];
		left++;
		right--;
	}

}
int main() {

//数组逆序打印
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	reverse(arr, sz);
	print(arr, sz);
	return 0;
}
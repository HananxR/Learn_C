#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
/*二分查找
* 在一个有序数组中查找具体的某个数字n。（讲解二分查找）
*/
int main() {
	int arr[] = { 1,2,3,4,5,6,6,8,9,10 };
	int n = 7;
	//计算数组的长度
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("数组长度:%d\n", len);
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] > n) {
			right = mid - 1;
		}
		else if (arr[mid] < n) {
			left = mid + 1;
		}
		else {
			printf("找到了，位置=%d\n", mid);
			break;
		}
	}
	if (left > right) {
		printf("未找到满足要求的n\n");
	}
	return 0;
}
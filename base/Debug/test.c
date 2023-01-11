#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main01() {

	/*char* p = "hello world";
	printf("%s\n", p);*/
	int i = 0;
	int arr[10] = { 0 };
	for (i = 0; i <10; i++) {
	
		arr[i] = 0;
		printf("hehe\n");
	}
	return 0;
}

//2013 如果是debug模式去编译，程序地结果是死循环
//2022版本没有出现死循环
//2013版本 release 也没有出现死循环，主要原因是优化导致地

//debug示例：阶乘
//实现代码：求 1！+2！+3！ ...+ n! ；不考虑溢出。

int main02() {

	int i = 0;
	int sum = 0;//保存最终结果
	int n = 0;
	int ret = 1;//保存n的阶乘
	scanf("%d", &n);//3 --->9
	//正常情况下输入3，应该输出9
	//但现在输出的结果是15，现在进行问题定位
	for (i = 1; i <= n; i++) {
	
		int j = 1;
		ret = 1;
		for (j = 1; j <= i; j++) {
			ret *= j;
		}
		sum += ret;

	}
	printf("%d\n", sum);
	return 0;

}



int main03() {

	int i = 0;
	int sum = 0;//保存最终结果
	int n = 0;
	int ret = 1;//保存n的阶乘
	scanf("%d", &n);//3 --->9
	//正常情况下输入3，应该输出9
	//但现在输出的结果是15，现在进行问题定位
	for (i = 1; i <= n; i++) {
		ret *= i;
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}


void test1() {
	int n = 10;
	int m = 20;
	int* p = &n;
	*p = 20;//ok?ok
	p = &m;//ok?ok

}

void test2() {
	int n = 10;
	int m = 20;
	const int* p = &n;
	//*p = 20;//ok? 当前地址指向的对象不可修改
	p = &m;//ok?ok

}


void test3() {
	int n = 10;
	int m = 20;
	int* const p = &n;
	*p = 20;//ok? 
	//p = &m;//ok?当前地址变量不可修改

}

int main04() {

	//测试无const的
	test1();
	//测试const放在*的左边
	test2();
	//测试const放在*的右边
	test3();

	return 0;
}

#include <assert.h>

int my_strlen(const char* str) {
	int count = 0;
	//保证str不是空指针
	assert(str != NULL);
	while (*str != '\0') {
		count++;
		str++;
	}
	return count;
}


int my_strlen2(const char* str) {
	
	//保存第一个元素的地址
	char* start = str;
	while (*str != '\0') {
		str++;

	}
	return str - start;
}

int main05() {
	//模拟实现strcpy的功能
	const char* p = "abcdef";
	//测试
	int len = my_strlen(p);
	printf("len=%d\n", len);

	int len2 = my_strlen2(p);
	printf("len2=%d\n", len2);

	return 0;
}


//字符串复制
void my_strcpy(char* dest, char* src) {
//实现字符串的复制
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;//解引用
}

//字符串复制
void my_strcpy2(char* dest, char* src) {
	//实现字符串的复制
	while (*src != '\0') {
		*dest++ = *src++;
	/*	dest++;
		src++;*/
	}
	*dest = *src;//解引用
}

//字符串复制
void my_strcpy3(char* dest, const char* src) {
	//实现字符串的复制
	assert(src != NULL);
	assert(dest != NULL);
	while (*src != '\0') {
		*dest++ = *src++;
		/*	dest++;
			src++;*/
	}
	*dest = *src;//解引用-->赋值
}


//字符串复制
char*   my_strcpy4(char* dest, const char* src) {
	//实现字符串的复制
	assert(src != NULL);
	assert(dest != NULL);
	char* ret = dest;
	while (*dest++ = *src++) {
	
	}
	return ret;
}


int main()
{
	char arr1[20] = "xxxxxxx";
	char arr2[] = "hello";
	/*my_strcpy(arr1, arr2);*/
	/*my_strcpy2(arr1, arr2);*/
	/*my_strcpy3(arr1, arr2);*/
	my_strcpy4(arr1, arr2);

	//strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}


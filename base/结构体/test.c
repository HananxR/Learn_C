#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//定义结构体
struct Books {

	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};
int main() {
	//声明结构体变量，并进行初始化
	struct Books book = { "C语言","RUNOOB","编程语言",123456 };
	printf("title:%s\n", book.title);
	struct Books* bp = &book;
	//基于指针的方式访问成员变量
	printf("subject:%d\n", (*bp).book_id);
	printf("author:%s\n", bp->author);
	return 0;
}
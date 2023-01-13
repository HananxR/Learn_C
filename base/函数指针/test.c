#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



int Add(int x, int y) {

	return x + y;
}

void testfunc(char* str) {
	printf("func pointer\n");
}
int main01() {
	//对于变量或数组的地址使用&,当然对于一个函数的地址也可以使用&
	printf("%p\n", &Add);
	printf("%p\n", Add);
	//疑问：对于函数名同数组名是一样的概念吗？
	//&数组名！=数组名；
	//&函数名==函数名；
	//----------------------------------
	//如何存储函数的地址
	//函数指针
	//这里pf就是一个函数指针变量，它指向2个int类型的参数，返回
	//类型是int的函数
	int (*pf)(int, int) = &Add;
	int (*pfun)(char) = &testfunc;
	char str = 'a';
	char* pstr = &"a";
	pfun(pstr);


	/*int ret = (*pf)(3, 5);*/
	//指向函数的指针可以不用解引用
	int ret = pf(3, 5);
	printf("%d\n", ret);
	//int ret2 = *pf(3, 5);//err 这里相当于把3和5传参后的返回值再解应用

	return 0;
}



struct Student {

	int age;
	char name[20];
	char sex[10];

};


int main() {

	/*struct Student s = { 0 };*/
	//
	typedef struct Student s_Stu;
	s_Stu s = { 0 };//同时注释


	void(*signal(int, void(*)(int)))(int);
	//typedef void(*)(int)pfun_t;//err这里又有点特殊，pfun_t不能写在后面
	typedef void(*pfun_t)(int);//而应该写在这里，这里就将void(*)()类型重命名为pfun_t
	pfun_t signal(int, pfun_t);



	return 0;
}
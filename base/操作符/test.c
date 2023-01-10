#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main01() {
	//移位操作符
	/*左移
	* 左边抛弃、右边补零
	*/
	int num = 1;
	//00000001
	num=num << 1;
	//00000010-->2
	printf("num=%d\n", num);


	int num2 = -1;
	//10000000000000000000000000000001
	//反码
	//11111111111111111111111111111110
	//补码=反码+1
	//11111111111111111111111111111111
	/*右移操作*/
	//1.逻辑操作(无符号)：左边用零填充，右边丢弃
	//2.算术移位(符号)：左边用原该值的符号位填充，右边丢弃
	num2 = num2 >> 1;
	num = num >> 2;
	printf("num2=%d\n", num2);//-1
	printf("num=%d\n", num);//0
	return 0;
}


int main02() {

	int num1 = 1;
	int num2 = 2;
	int num3 = 0;
	num3=num1& num2;
	printf("num3=%d\n", num3);//0
	num3 = num1 | num2;
	//001
	//010
	//011<- A*B
	printf("num3=%d\n", num3);//3
	num3 = num1 ^ num2;
	//(A+B)-(A*B)=>011
	printf("num3=%d\n", num3);//3


}


void swap(int* a, int* b) {
	//交换两个变量
	//第一种方案，使用临时变量
	int tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;

}


void swap2(int* a, int* b) {
	//交换两个变量
	//第二种方案，使用加法
	*a = *a + *b;
	*b = *a - *b;
	*a = (*a) - (*b);
	//存在的问题，可能会出现内存溢出


}

void swap3(int* a, int* b) {
	//交换两个变量
	//第三种方案，使用异或
	*a = (*a) ^(*b);
	*b = *a ^ *b;
	*a = (*a) ^ (*b);
	//存在的问题，可能会出现内存溢出


}



int main03() {

	//不创建临时变量(第三个变量)实现两个数的交换
	int a = 10;
	int b = 20;
	printf("before a=%d b=%d\n", a, b);
	swap(&a, &b);
	printf("after a=%d b=%d\n", a, b);
	swap2(&a, &b);
	printf("after2 a=%d b=%d\n", a, b);
	swap3(&a, &b);
	printf("after3 a=%d b=%d\n", a, b);


}


int get_byte_1( int num) {
	//获取整数再内存中二进制中个数1
	int count = 0;
	while (num) {
		if (num % 2 == 1) {
			count++;
		}
		num = num / 2;
	}
	return count;
}

int get_byte_2(int num) {
	//获取整数再内存中二进制中个数1
	int count = 0;
	unsigned int tmp = (unsigned)num;
	while (tmp) {
		if (tmp % 2 == 1) {
			count++;
		}
		tmp = tmp / 2;
	}
	return count;
}


int get_byte_3(int num) {
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (num & (1 << i)) {
			count++;
		}
	}
	//缺点是需要是必须循环32次
	return count;
}


int get_byte_4(int num) {
	int count = 0;
	while (num) {
		num = num & (num - 1);
		count++;
	}
	return count;
}


int main04() {

	//求一个整数存储在内存中的二进制中1的个数；
	int num = 10;
	// 1010
	int count = get_byte_1(10);
	unsigned int num3 = (unsigned)num;

	

	printf("count=%d\n", count);
	printf("%u\n", num3);
	int count2 = get_byte_2(num);
	printf("count2=%d\n", count2);

	int count3 = get_byte_3(num);
	printf("count3=%d\n", count3);


	int count4 = get_byte_4(num);
	printf("count4=%d\n", count4);
	return 0;

}


int main05() {
	//单目运算符
	int a = -10;
	int* p = NULL;
	printf("%d\n", !3);//0
	printf("%d\n", !0);//1
	a = -a;
	p = &p;
	printf("%d\n", sizeof(a));//4
	printf("%d\n", sizeof(int));//4
	printf("%d\n", sizeof a);//4
	/*printf("%d\n", sizeof int);*///不能这样写

	return 0;
}

void test1(int arr[]) {

	printf("%d\n", sizeof(arr));//8-->指针
}


void test2(char ch[]) {
	printf("%d\n", sizeof(ch));//8-->指针
}
int main06() {
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));//40
	printf("%d\n", sizeof(ch));//10
	test1(arr);
	test2(ch);
	return 0;

}

int main07() {
	int i = 0, a = 0,b = 0, c = 3, d = 4;
	i = a++ && ++b && d++;
	printf("a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);
	//a=1 b=0 c=3 d=4
	//a为前置++，所以(a++)为假，后面的不再计算
	i = 0, a = 1, b = 0, c = 3, d = 4;
	i = a++ && ++b && d++;
	printf("a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);
	//  2 1 3 5


	i = 0, a = 0, b = 0, c = 3, d = 4;
	i = a++ || ++b && d++;
	printf("a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);
	//  1 1 3 5

	i = 0, a = 0, b = 0, c = 3, d = 4;
	i = a++ || ++b || d++;
	printf("a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);
	//  1 1 3 4
	return 0;

}


int main08() {

	int a = 10;
	int b = (a > 5) ? 3 : -3;

	printf("%d\n", b);

	return 0;

}


int main09() {

	int a = 1;
	int b = 2;
	int c = (a > b, a = b + 10, a, b = a + 1);
	//a=12 
	//b=12+1=13
	printf("c=%d\n", c);//13
	printf("a=%d \n b=%d\n", a, b);//12 13

	return 0;

}


int main() {


	char a = 0xb6;
	short b = 0xb600;
	int c = 0xb6000000;
	if (a == 0xb6) {

		printf("a\n");//
	}
	if (b == 0xb600)
		printf("b\n");

	if (c == 0xb6000000)
		printf("c\n");//c
	// ab要及逆行整型提升，但是c不需要整型提升


	char d = 1;
	printf("%u\n", sizeof(d));//1
	printf("%u\n", sizeof(+d));//4-->int
	printf("%u\n", sizeof(-d));//4-->int

}
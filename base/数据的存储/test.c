#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<windows.h>
#include<string.h>
int main01() {
	//数据类型及存储空间大小
	printf("char=%d\n",sizeof(char));
	printf("short=%d\n", sizeof(short));
	printf("int=%d\n", sizeof(int));
	printf("long=%d\n", sizeof(long));
	printf("long long=%d\n", sizeof(long ));
	printf("float=%d\n", sizeof(float));
	printf("double=%d\n", sizeof(double));


	return 0;
}


int main02() {

	int a = 20;
	int b = -10;
	return 0;

}

int check_sys() {
	int i = 1;
	//先取地址
	//然后做指针类型转换
	//最后解引用
	return *(char*)&i;


}

int main03() {
	SetConsoleOutputCP(65001);

	int ret = check_sys();
	if(ret==1)
		printf("小端\n");
	else
		printf("大端\n");

	return 0;
}


int main04() {

	char a = -1;
	//原码：10000001
	//反码：11111110
	//补码：11111111
	//整型提升，按照符号进行补1(当前为负)-->int
	//11111111 11111111 11111111 11111111
	//然后按照char去截取11111111--->-1
	//11111110

	signed char b = -1;
	//同上结果是-1

	unsigned char c= -1;
	//整型提升，按照符号进行补0(当前为负)-->int
	//00000000 00000000 00000000 11111111
	//截取
	//11111111
	printf("a=%d,b=%d,c=%d",a,b,c);// -1 -1 255



}


int main05() {

	//%u：标识无符整数
	//a:
	//原码：11111111
	//反码：10000000-->仅剩符号位
	//补码：10000000
	//整型提升
	// 11111111111111111111111110000000
	char a = -128;
	printf("%u\n", a);// 11111111111111111111111110000000
	return 0;
}


int main06() {
	char a = 128;
	//char的范围为-128~127
	//此时a按照%d的形式打印其实为-128，所以其无符号整数与char -128标识一致
	printf("aa=%u\n", a);//11111111111111111111111110000000

	return 0;
}

int main07() {
	//按照补码形式进行运算，最后格式化为有符号的整数
	int i = -20;
	//原码
	//10000000 00000000 00000000 00010100
	// 反码
	//11111111 11111111 11111111 11101011
	// 补码
	//11111111 11111111 11111111 11101100
	unsigned int j = 10;
	//11111111 11111111 11111111 11101100
	//00000000 00000000 00000000 00001010
	//11111111 11111111 11111111 11110110
	//反码=补码-1
	//11111111 11111111 11111111 11110101
	//10000000 00000000 00000000 00001010

	printf("%d\n", i + j);//-10
	return 0;

}

int main08() {

	unsigned int i;
	for (i = 9; i >= 0; i--) {
	
		printf("%u\n", i);
	}
}

int main09() {

	char a[1000];
	int i;
	for (i = 0; i < 1000; i++) {
		a[i] = -1 - i;
	}
	//因为char类型的范围-128~127，长度为255
	//所以长度为255
	printf("%d\n", strlen(a));
}

unsigned char i = 0;

int main10() {

	for (i = 0; i <= 255; i++) {
		printf("hello\n");
		//死循环，因为unsigner char的最大值为255,
	}
	
}

int main() {

	int n = 9;
	//原码 00000000 00000000 00000000 00001001
	//反码和补码一样
	// 00 00 00 09

	float* pFloat = (float*)&n;
	printf("n=%d\n", n); 
	//32-1-8-3=32-13=19
	// 0 00000000 0000000 00000000 00001001
	//还原浮点数
	//s=0；E=0 
	//V=(-1)^0*0.00000000000000000001001
	//V=(-1)^0*1.001*2^(-19-127)=(-1)^0*1.001*2^(146)

	printf("*pFloat=%lf\n", *pFloat);//0.000
	*pFloat = 9.0;
	//IEEE 754 :9.=1001.0
	//1.001*2^3
	//s：0 ;M=1.001；E=3+127=130;
	// s=1230=128+2=1000 0010
	//M:001 有效数字M等于001后面再加20个0，凑满23位
	//V=0 1000 0010 00100000000000000000000 
	//V=01000001000100000000000000000000 =1091567616
	printf("num=%d\n", n);//1091567616
	printf("*pFloat=%f\n", *pFloat);//9.0

}
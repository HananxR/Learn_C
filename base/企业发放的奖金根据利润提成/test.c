#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
/*
* 题目：企业发放的奖金根据利润提成。

利润(I)低于或等于10万元时，奖金可提10%；
利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
20万到40万之间时，高于20万元的部分，可提成5%；
40万到60万之间时高于40万元的部分，可提成3%；
60万到100万之间时，高于60万元的部分，可提成1.5%；
高于100万元时，超过100万元的部分按1%提成。
从键盘输入当月利润I，求应发放奖金总数？

*/

int main() {
	SetConsoleOutputCP(65001);

	double I;//定义利润变量

	//定义提成
	double bouns10, bouns20, bouns40, bouns60, bouns100, bouns;
	int unit = 10000;//单元 万
	bouns10 = 10 * unit * 0.1;
	bouns20 = bouns10 + 10 * unit * 0.075;
	bouns40 = bouns20 + 20 * unit * 0.05;
	bouns60 = bouns40 + 20 * 0.03 * unit;
	bouns100 = bouns60 + 40 * unit * 0.015;

	printf("请输入当月利润：");
	scanf("请输入当月利润I: %lf", &I);
	printf("输入的利润是:%lf\n", I);
	printf("bouns10=%lf\n", bouns10);

	if (I <= 10 * unit) {
		bouns = I * 0.1;
	}
	else if (I <= 20 * unit) {
		bouns = (I - 10 * unit) * 0.075 + bouns10;
	}
	else if (I <= 40 * unit) {
		bouns = (I - 20 * unit) * 0.05 + bouns20;
	}
	else if (I <= 60 * unit) {
		bouns = (I - 40 * unit) * 0.03 + bouns40;
	}
	else if (I <= 100 * unit) {
		bouns = (I - 60 * unit) * 0.015 + bouns60;
	}
	else {
		bouns = (I - 100 * unit) * 0.01 + bouns100;
	}
	printf("最终发放的奖金数:%lf \n", bouns);

	return 0;

}
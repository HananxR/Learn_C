#define _CRT_SECURE_NO_WARNINGS 1
/*

题目：输入某年某月某日，判断这一天是这一年的第几天？
程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊情况，闰年且输入月份大于3时需考虑多加一天。
*/


#include <stdio.h>
int main() {


	int day, month, year, sum;
	printf("\n 请输入年、月、日，格式为：年，月，日(2015,12,10)\n");
	scanf("%d,%d,%d", &year, &month, &day);
	printf("年、月、日：%d %d %d \n", year, month, day);
	//定义天数数组
	int month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//判断当前年月是不是闰年
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		month_days[1] = 29;

	}
	else {
		month_days[1] = 28;
	}
	printf("2月份有%d天\n", month_days[1]);
	//计算天数
	sum = 0;
	for (int i = 0; i < month - 1; i++) {
		sum += month_days[i];
		printf("当前月(%d)之前的天数:%d\n", i + 1, sum);
	}
	//加上天数
	sum += day;
	printf("总的天数:%d\n", sum);



	//switch (month) {//先计算某月以前月份的总天数
	//case 1:sum = 0; break;
	//case 2:sum = 1*31; break;
	//case 3:sum = 1*31 + 1*28; break;
	//case 4:sum = 1*31 + 1*28+1*30; break;
	//case 5:sum = 1 * 31 + 1 * 28 + 1 * 30; break;
	//case 6:sum = 1 * 31 + 1 * 28 + 1 * 308; break;
	//case 7:sum = 1 * 31 + 1 * 28 + 1 * 30; break;
	//case 8:sum = 1 * 31 + 1 * 28 + 1 * 30; break;
	//case 9:sum = 1 * 31 + 1 * 28 + 1 * 30; break;
	//case 10:sum = 1 * 31 + 1 * 28 + 1 * 30; break;
	//case 11:sum = 31 + 28; break;
	//case 12:sum = 31 + 28; break;



	//}
	return 0;
}
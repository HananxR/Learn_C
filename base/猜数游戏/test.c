#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include <windows.h>

/*
* 需求：
* 1.自动生成1-100之间得随机数；
* 2.猜数字；
* 2.a 猜对了，恭喜您，游戏结束；
* 2.b你猜错了，会告诉你猜大了，还是猜小了，继续猜，知道猜对；
* 3.游戏一个一直玩，除非退出游戏

*/

void menu() {
	//定义一个菜单
	printf("*************************\n");
	printf("*********0. exit ********\n");
	printf("*********1. play********\n");
	printf("*************************\n");


}

void game() {

	//猜数字游戏
	/*
	1.生成随机数
	*/
	int ret = rand() % 100 + 1;
	//printf("%d\n", ret);
	//2猜数字
	int guess = 0;
	while (1) {
		printf("请猜数字>\n");
		scanf("%d", &guess);
		if (guess < ret) {
			printf("猜小了\n");
		}
		else if (guess > ret) {
			printf("猜大了\n");
		}
		else {
			printf("恭喜你猜对了\n");
		}

	}
}

int main() {
	SetConsoleOutputCP(65001);

	int input = 0;
	srand((unsigned int)time(NULL));


	do {
		//打印菜单
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input) {
		case 0:
			printf("exit\n");
			break;
		case 1:
			printf("start playing...\n");
			game();
			break;
		default:
			printf("选择错误，重新选择\n");
			break;

		}

	} while (input);

	return 0;
}
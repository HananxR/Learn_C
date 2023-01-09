#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<windows.h>
#include "game.h"



void game() {

	//实现游戏过程
	//存储数据，二维数组
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;//接收游戏状态
	while (1) {
		//玩家下棋
		PlayerMove(board, ROW, COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		//只要棋盘未满就继续
		if (ret != 'C') {
			printf("游戏结束、正在统计结果...\n");
			break;
		}
		//电脑开始下
		ComputerMove(board, ROW, COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			printf("游戏结束、正在统计结果...\n");
			break;
		}

	
	}
	if (ret == '*') {
		printf("恭喜玩家获胜!\n");
	}
	else if (ret == '#') {
		printf("恭喜电脑获胜!\n");
	}
	else {
		printf("本次游戏平局\n");
	}

	


}


void Menu() {
//打印游戏菜单
	printf("************************\n");
	printf("****0.game 1.exit*******\n");
	printf("************************\n");

}

int main() {
	SetConsoleOutputCP(65001);

	int input = 0;
	do {

		//打印游戏菜单
		Menu();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input) {
		case 0:
			printf("starting game...\n");
			game();
			break;
		case 1:
			printf("exit game");
			break;
		default:
			printf("input error");
			break;
		}
		}while (input);


		return 0;

	
}
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include "game.h"
#include <time.h>

/*
需求：实现扫雷游戏(简单版9*9)
*/

void game() {
//game
	printf("row,col=%d,%d\n", ROW, COL);
	//前端页面看到的棋盘
	char mine[ROWS][COLS] = { 0 };
	//后端页面看到的棋盘
	char show[ROWS][COLS] = { 0};
	//棋盘初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印一下棋盘
	DisplayBoard(show, ROW, COL);
	/*DisplayBoard(mine, ROW, COL);*/

	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);

	//排查雷
	FineMine(mine, show, ROW, COL);



}

void Menu() {

	printf("*********************************\n");
	printf("******1.game  2.exit ************\n");
	printf("*********************************\n");

}
int main() {
	SetConsoleOutputCP(65001);
	//选择游戏
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		Menu();
		printf("Please select 1 or 2>");
		scanf("%d", &input);
		switch (input) {
		
		case 1: {
			printf("start game...\n");
			game();
			break;
		}
		case 2: {
			printf("exit game");
			break;
		}
		default:
			printf("input code is invalid!");
			break;
		}

	} while (input);



	return 0;
}
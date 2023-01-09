#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdio.h>


void InitBoard(char board[ROW][COL], int row, int col) {
	//初始化棋盘，让其等于空
	for (int i = 0; i < row; i++) {
	
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}


}


//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}

		}
		printf("\n");
		if (i < row - 1) {
			for (int j = 0; j < col; j++) {
				printf("___");
				if (j < col - 1) {
					printf("|");
				}
			}
		}
		printf("\n");
	}
}


void PlayerMove(char board[ROW][COL], int row, int col) {

	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while (1) {
		printf("请输入下棋的坐标:>");
		scanf("%d %d", &x, &y);
		//判断其合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
		
		//下棋
		//坐标是否被占用
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				//输入完成，结束
				break;
			}
			else {
				printf("坐标被占用，请重新输入\n");
			}
		}
		else {
			printf("坐标非法，请重新输入\n");
		}
	}
}




void ComputerMove(char board[ROW][COL], int row, int col) {


	//电脑开始下棋
	printf("电脑走:>\n");
	int x = 0;
	int y = 0;
	while (1) {
		int x = rand() % row;
		int y = rand() % col;
		//判断占用
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	
	}

}


int IsFull(char board[ROW][COL], int row, int col) {

//判断棋盘是否满了
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}


char IsWin(char board[ROW][COL], int row, int col) {
//判断哪一方输、哪一方赢
	//判断三行
	for (int i=0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	
	}

	//判断三列
	for (int j = 0; j < col; j++) {

		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
			return board[0][j];
		}
	}

	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];

	}

	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ') {
		return board[1][1];

	}
	//判断棋盘是否满了
	//棋盘未满返回1，满了返回0
	int ret = IsFull(board, ROW, COL);
	//继续
	if (ret == 0) {
		return 'C';
	}
	//平局
	return 'Q';



}
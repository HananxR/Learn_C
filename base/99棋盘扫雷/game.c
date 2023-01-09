#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "game.h"
#include<stdlib.h>
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = set;

		}
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int col) {

	printf("----------------扫雷游戏----------------------\n");
	printf("row=%d col=%d\n",row,col);
	//打印列号
	for (int i = 0; i <= col; i++) {
		printf("%d ", i);
	}
	printf("\n");
	//展示的是前端的业务
	for (int i=1; i <=row; i++) {
		printf("%d ", i);
		for (int j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------------扫雷游戏----------------------\n");
}


void SetMine(char board[ROWS][COLS], int row, int col) {


//设置雷数
	int count = EASY_COUNT;
	while (count) {
	//产生随机坐标
		int x = rand() % row+1;
		int y = rand() % col+1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			printf("雷 board[%d][%d]=%c\n", x, y, board[x][y]);
			count--;
		}
	}
}


static int get_mine_count(char mine[ROWS][COLS], int x, int y) {
//判断这个点的周围八个点是否有雷
	//通过求和的方式实现
	printf("c=%c\n", mine[x - 1][y - 1]);
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';


}



void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	//1.输入排查的坐标
	//2.检查坐标处是不是雷
	//（1）是雷，---很遗憾炸死了--游戏结束
	//（2）不是雷---统计坐标周围有几个雷
	//存储排查雷的信号到show的数组游戏继续
	int x = 0;
	int y = 0;
	int win = 0;

	while (win < row * col - EASY_COUNT) {
	
		printf("请输入要排查的坐标:>");
		scanf("%d %d", &x, &y);
		//判断坐标的合法性
		/*printf("输入的坐标:x=%d,y=%d\n", x, y);*/
		if (x >= 1 && x <= row && y >= 1 && y <= col) {

			printf("mine[%d][%d]=%c\n", x, y, mine[x][y]);
		
			if (mine[x][y] == '1') {
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			
			}
			else {
				//不是雷情况下，统计x,y坐标周围有几个雷
				int count = get_mine_count(mine, x, y);
				printf("count=%d\n", count);
				show[x][y] = count + '0';
				//显示排查出的信息
				DisplayBoard(show, row, col);
				win++;
			
			}
		}
		else {
		
			printf("坐标不合法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT) {
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, row, col);
	
	}

}
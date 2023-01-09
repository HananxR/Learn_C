#pragma once
#define ROW 3
#define COL 3
#include <stdlib.h>
#include <time.h>

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);


//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家
void PlayerMove(char board[ROW][COL], int row, int col);


//电脑
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢
char IsWin(char board[ROW][COL], int row, int col);

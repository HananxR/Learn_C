#pragma once
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
//本来应该是9*9，这里设定为11*11的目的，是为了更好的处理边界；
#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS],int row,int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

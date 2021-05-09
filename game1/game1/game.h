#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int  row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char borad[ROW][COL], int row, int col);
void ComputerMove(char borad[ROW][COL], int row, int col);

//如果玩家赢反回一个’*‘
 //如果电脑赢反回一个’#‘
 //如果平局反回一个’Q‘
 //如果继续游戏则返回一个’C‘
char IsWin(char borad[ROW][COL], int row , int col);
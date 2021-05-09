#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int  row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';

		}

	}

}


void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			
			printf(" %c ", board[i][j]);
			
			if (j < col - 1)
				printf("|");
			
		}
		printf("\n");

		if (i < row - 1) 
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");

			}
			printf("\n");
		}
	}
	
}

void PlayerMove(char borad[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走 :>\n");
	while (1)
	{
		printf("请输入坐标;>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (borad[x - 1][y - 1] == ' ')
			{
				borad[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("非法坐标，请重新输入\n");
		}
	}
}


void ComputerMove(char borad[ROW][COL], int row, int col)
{
    int	x = 0;
    int	y = 0;
	printf("电脑走\n");
	while (1)
	{
		
		x = rand() % row;
		y = rand() % col;

		if (borad[x][y] == ' ')
		{
			borad[x][y] = '#';
			break;
		}

	}
}

int IsFull(char borad[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (borad[i][j] == ' ')

				return 0;
		}
	} 
	return 1;
}

char IsWin(char borad[ROW][COL], int row, int col)
{ 
	int i = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (borad[i][0] == borad[i][1] && borad[i][1] == borad[i][2] && borad[i][1] != ' ');
		{
			return  borad[i][1];	
		}

	}
	//su三列
	for (i = 0; i < col; i++)
	{
		if (borad[0][i] == borad[1][i] && borad[1][i] == borad[2][i] && borad[1][i] != ' ');
		{
			return borad[1][i];
		}
	}
	if (borad[0][0] == borad[1][1] && borad[1][1] == borad[2][2] && borad[1][1] != ' ')
		return borad[1][1];
	if (borad[2][0] == borad[1][1] && borad[1][1] == borad[0][2] && borad[1][1] != ' ')
		return borad[1][1];

	if(1 == IsFull(borad, ROW, COL))
	{
		return 'Q';
	}
		return 'C';
}

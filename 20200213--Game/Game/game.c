#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//初始化棋谱
void InitBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			Board[i][j] = ' ';
		}
	}
}
//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |   

void PrintBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			printf(" %c ", Board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int k = 0; k < col; ++k)
			{
				printf("---");
				if (k < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void PalyerMove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下->\n");
	while (1)
	{
		printf("请输入坐标->");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (Board[x - 1][y - 1] == ' ')
			{
				Board[x - 1][y - 1] = '*';
				break;
			}
			printf("该坐标已经有棋子，请重新落子->\n");
		}
		else
			printf("输入错误，请重新输入！\n");
	}
}

void ComputerMove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走->\n");
	while (1)
	{	
		x = rand() % ROW;
	    y = rand() % COL;
		if (Board[x][y] == ' ')
		{
			Board[x][y] = '#';
			break;
		}
	}
}
//return * - 玩家赢
//return # - 电脑赢
//return C - 继续
//return Q - 平局
char IsWin(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//判断三行
	for (i = 0; i < ROW; ++i)
	{
		if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][1] != ' ')
			return Board[i][1];
	}
	//判断三列
	for (i = 0; i < COL; ++i)
	{
		if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[1][i] != ' ')
			return Board[1][i];
	}
	//判断对角线
	if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[1][1] != ' ')
		return Board[1][1];
	if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[1][1] != ' ')
		return Board[1][1];

	//判断是否平局
	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			if (Board[i][j] == ' ')
			{
				return 'C';
				break;
			}
		}
	}

	return 'Q';
}
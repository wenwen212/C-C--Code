#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void Displayboard(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= rows; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for (i = 1; i <= rows; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= cols; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}
void Setboard(char board[ROWS][COLS], int rows, int cols)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % rows + 1;
		int y = rand() % cols + 1;
		if (board[x][y] == '0')
		{
			board[x][y] =  '1' ;
			count--;
		}
	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x+1][y+1] - 8 * '0';
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < cols*rows - EASY_COUNT)
	{
		printf("请输入坐标:>");
		scanf("%d%d",&x,&y);
		if (x >= 1 && x <= rows && y >= 1 && y <= cols)
		{
			if (mine[x][y] == '1')
			{
				printf("Game Over!!\n");
				Displayboard(mine,rows, cols);
				break;
			}
			else
			{
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				Displayboard(show,rows,cols);
			}
		}
		else
		{
			printf("坐标非法，重新输入！\n");
		}
	}

}
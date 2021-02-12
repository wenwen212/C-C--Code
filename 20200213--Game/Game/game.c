#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//��ʼ������
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
	printf("�����->\n");
	while (1)
	{
		printf("����������->");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (Board[x - 1][y - 1] == ' ')
			{
				Board[x - 1][y - 1] = '*';
				break;
			}
			printf("�������Ѿ������ӣ�����������->\n");
		}
		else
			printf("����������������룡\n");
	}
}

void ComputerMove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������->\n");
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
//return * - ���Ӯ
//return # - ����Ӯ
//return C - ����
//return Q - ƽ��
char IsWin(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//�ж�����
	for (i = 0; i < ROW; ++i)
	{
		if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][1] != ' ')
			return Board[i][1];
	}
	//�ж�����
	for (i = 0; i < COL; ++i)
	{
		if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[1][i] != ' ')
			return Board[1][i];
	}
	//�ж϶Խ���
	if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[1][1] != ' ')
		return Board[1][1];
	if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[1][1] != ' ')
		return Board[1][1];

	//�ж��Ƿ�ƽ��
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
#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
//菜单
void Menu()
{
	printf("**********************************\n");
	printf("***** 1:开始游戏 0：退出游戏 *****\n");
	printf("**********************************\n");
}
void Game()
{
	char rel = 0;
	srand((unsigned int)time(NULL));
	//创建棋谱
	char Board[ROW][COL] = {0};
	//初始化棋谱
	InitBoard(Board, ROW, COL);
	//打印棋谱
	PrintBoard(Board, ROW, COL);
	//开始下棋
	while (1)
	{
		//玩家下
		PalyerMove(Board, ROW, COL);
		PrintBoard(Board, ROW, COL);
		//判断输赢
		rel = IsWin(Board, ROW, COL);
		if (rel != 'C')
		{
			break;
		}
		//电脑下
		ComputerMove(Board, ROW, COL);
		PrintBoard(Board, ROW, COL);
		rel = IsWin(Board, ROW, COL);
		if (rel != 'C')
		{
			break;
		}

	}
	if (rel == '*')
	{
		printf("玩家赢\n");
	}
	else if (rel == '#')
	{
		printf("电脑赢\n");
	}
	else
		printf("平局\n");
}
void Test()
{
	
	int input = 0;
	do
	{
		//打印选择菜单
		Menu();
		printf("请输入->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//开始游戏
		    Game();
			break;
		case 0:	
			//退出游戏
			break;
		default:
			printf("请重新输入！！！\n");
			break;
		}
		Sleep(500);
	} while (input);
}
int main()
{
	Test();
	system("pause");
	return 0;
}
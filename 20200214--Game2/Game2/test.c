#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Menu()
{
	printf("*********************************\n");
	printf("********     1.Play     *********\n");
	printf("********     0.Exit     *********\n");
	printf("*********************************\n");
}
void Game()
{
	//雷的信息存储
	//布置雷信息
	char mine[ROWS][COLS] = { 0 };
	//排查雷信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show,ROWS,COLS,'*');
	//打印棋盘
	Displayboard(show,ROW,COL);
	//布置雷
	Setboard(mine,ROW,COL);
	//Displayboard(mine, ROW, COL);
	//开始游戏
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("请输入:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
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
	//�׵���Ϣ�洢
	//��������Ϣ
	char mine[ROWS][COLS] = { 0 };
	//�Ų�����Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show,ROWS,COLS,'*');
	//��ӡ����
	Displayboard(show,ROW,COL);
	//������
	Setboard(mine,ROW,COL);
	//Displayboard(mine, ROW, COL);
	//��ʼ��Ϸ
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("������:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}
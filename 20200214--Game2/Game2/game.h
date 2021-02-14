#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Initboard(char board[ROWS][COLS],int rows,int cols,char set);
void Displayboard(char board[ROWS][COLS],int rwos,int cols);
void Setboard(char board[ROWS][COLS],int rows,int cols);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int rows,int cols);
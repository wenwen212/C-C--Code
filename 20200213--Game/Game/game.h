#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
void InitBoard(char Board[ROW][COL], int row, int col);
void PrintBoard(char Board[ROW][COL], int row, int col);
void PalyerMove(char Board[ROW][COL], int row, int col);
void ComputerMove(char Board[ROW][COL], int row, int col);
char IsWin(char Board[ROW][COL], int row, int col);
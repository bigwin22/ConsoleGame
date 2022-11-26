//disable warnings
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#include "Header/Console.h"

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void ReSizeConsole(int w, int h)
{
    char chTemp[30];
    sprintf(chTemp, "mode con cols=%d lines=%d", w, h);
    system(chTemp);
}
void ClearCursor()
{
    CONSOLE_CURSOR_INFO c = { 0 };
    c.dwSize = 1;
    c.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}

void Console_init()
{
    system("title ConsoleGame");
    ReSizeConsole(DEFAULT_CONSOLE_WIDTH, DEFAULT_CONSOLE_HEIGHT);
    ClearCursor();
}
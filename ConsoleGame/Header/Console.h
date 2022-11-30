#pragma once

//Disable security warnigs
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define DEFAULT_CONSOLE_WIDTH 60  //기본 콘솔 크기
#define DEFAULT_CONSOLE_HEIGHT 43 //기본 콘솔 크기

//#pragma comment(lib, "winmm.lib")

void gotoxy(int x, int y);
void ReSizeConsole(int w, int h);
void ClearCursor();
void Console_init();


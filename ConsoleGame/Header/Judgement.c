#include "Image/ImageLayer.h"
#include <Windows.h>
#include <WinUser.h>
#include <stdlib.h>
#include <stdbool.h>


#define DEFAULT_CONSOLE_WIDTH 60  
#define DEFAULT_CONSOLE_HEIGHT 43

INPUT_RECORD rec;
DWORD dwNOER;
HANDLE CIN = 0;

int Boarder_Check(int x, int y)
{
	if (x < 0 || x > DEFAULT_CONSOLE_WIDTH * 13.9 || y < 0 || y > DEFAULT_CONSOLE_HEIGHT * 28.5)//콘솔 창 크기와 이미지 출력의 단위가 달라 이렇게 해야함
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int Attacked(int x, int y, int x1, int y1, int x2, int y2)
{
	if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Keyboard_pressed()
{
	if (_kbhit())
	{
		return _getch();
	}
	else
	{
		return 0;
	}
}

int Images_Input_location(Image* images)
{
	for (int i = 99; i >= 0; i--)
	{
		if (images[i].fileName == NULL)
		{
			return i;
		}
	}
	return -1;
}
/// <summary>
/// /////////////////////////////////////////////////////////////////////
/// </summary>

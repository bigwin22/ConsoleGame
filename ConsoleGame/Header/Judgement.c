#include "Image/ImageLayer.h"
#include "Judgement.h"
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


int Bumpped_Check(struct Bumpped_range_args args1, struct Bumpped_range_args args2)
{
    //width is 500*args.size
	//height is 500*args.size
	const double width1 = 500 * args1.scale;
	const double width2 = 500 * args2.scale;
	
	if ((args1.x <= args2.x + width2 && args1.y <= args2.y + width2) && (args1.x+width1 >= args2.x && args1.y+width1 >= args2.y))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Bumpped(Image* images, int image_count, int obj_lo)//이미지 배열, 이미지 개수, 객체의 위치
{
	for (int i = 0; i < image_count; i++)
	{
		if (i == obj_lo || images[i].fileName == NULL || images[i].type == -1)
		{
			continue;
		}
		struct Bumpped_range_args args1 = { images[obj_lo].x, images[obj_lo].y, images[obj_lo].scale };
		struct Bumpped_range_args args2 = { images[i].x, images[i].y, images[i].scale };
		if (Bumpped_Check(args1, args2))
		{
			printf("Bummped");
			return images[i].type;
		}
	}
	return -1;
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

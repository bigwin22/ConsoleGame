#pragma once
#include "Image/ImageLayer.h"
#include "Console.h"
#include "Object.h"
#include <stdio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#define ESC 27
#define SPACE 32




int Boarder_Check(int x, int y)
{
	if (x < 0 || x > DEFAULT_CONSOLE_WIDTH || y < 0 || y > DEFAULT_CONSOLE_HEIGHT)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}





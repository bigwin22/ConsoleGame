#pragma once

#include "Object.h"


struct Bumpped_range_args
{
	int x, y;
	double scale;
};

int Boarder_Check(int x, int y);
int Bumpped(Image* images, int image_count, int obj_lo);
int Keyboard_pressed();
int Images_Input_location(Image *images);
void GetInput();



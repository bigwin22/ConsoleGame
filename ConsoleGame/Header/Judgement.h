#pragma once

#include "Object.h"

/**
* @brief		��ü �浹 ���� �Լ�
* @param args1	��꿡 �ʿ��� ��ü�� ��(x,y, scale)
*/
struct Bumpped_range_args
{
	int x, y;// ��ǥ
	double scale;// ũ��
};

int Boarder_Check(int x, int y);
int Bumpped(Image* images, int image_count, int obj_lo, int cnt, ...);
int Keyboard_pressed();
//int input_location = 0;
int Images_Input_location(Image *images);
void GetInput();



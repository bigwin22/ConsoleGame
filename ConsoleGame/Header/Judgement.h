#pragma once

#include "Object.h"
#include <stdbool.h>

/**
* @brief		객체 충돌 감지 함수
* @param args1	계산에 필요한 객체의 값(x,y, scale)
*/
struct Bumpped_range_args
{
	int x, y;// 좌표
	double scale;// 크기
};

int Boarder_Check(int x, int y);
int Bumpped(Image* images, int image_count, int obj_lo, int cnt, ...);
int Keyboard_pressed();
int Images_Input_location(Image* images, bool direction);
void GetInput();


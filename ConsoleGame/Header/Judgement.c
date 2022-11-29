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

/// <summary>
/// x,y가 유효한 영역에 있는지를 체크
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns>유효하지 않으면 -> 0, 유효하면 -> 1</returns>
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

/// <summary>
///	객체 충돌 감지 함수 
///
/// </summary>
/// <param name="args1">계산에 필요한 객체의 값(x,y, scale)</param>
/// <param name="args2"></param>
/// <returns></returns>
int Bumpped_Check(struct Bumpped_range_args args1, struct Bumpped_range_args args2)
{
    //width is 500*args.size
	//height is 500*args.size
	const double width1 = 500 * args1.scale;//모든 오브젝트는 500*500이므로 사이즈를 고려해 차지하는 크기 계산
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

/// <summary>
/// 모든 이미지를 순회하며 image[obj_lo]와 충돌하는 얘가 있는지를 탐색
/// </summary>
/// <param name="images">이미지 레이어 배열</param>
/// <param name="image_count">레이어의 갯수</param>
/// <param name="obj_lo">기준이 되는 오브젝트가 images에서 어디 있는지</param>
/// <returns>충돌되는 객체의 위치</returns>
int Bumpped(Image* images, int image_count, int obj_lo)//이미지 배열, 이미지 개수, 객체의 위치
{
	for (int i = image_count; i >= 0; i--)
	{
		if (i == obj_lo || images[i].fileName == NULL || images[i].type == -1)
		{
			continue;
		}
		struct Bumpped_range_args args1 = { images[obj_lo].x, images[obj_lo].y, images[obj_lo].scale };
		struct Bumpped_range_args args2 = { images[i].x, images[i].y, images[i].scale };
		if (Bumpped_Check(args1, args2))
		{
			return i;
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

/**
* @brief 이미지를 넣을 수 있는 공간은 역순으로 찾아준다
* @param images 이미지 배열
* @returns 이미지를 넣을 수 있는 공간의 인덱스
*/
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

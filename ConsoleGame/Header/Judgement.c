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
/// x,y�� ��ȿ�� ������ �ִ����� üũ
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns>��ȿ���� ������ -> 0, ��ȿ�ϸ� -> 1</returns>
int Boarder_Check(int x, int y)
{
	if (x < 0 || x > DEFAULT_CONSOLE_WIDTH * 13.9 || y < 0 || y > DEFAULT_CONSOLE_HEIGHT * 28.5)//�ܼ� â ũ��� �̹��� ����� ������ �޶� �̷��� �ؾ���
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/// <summary>
///	��ü �浹 ���� �Լ� 
///
/// </summary>
/// <param name="args1">��꿡 �ʿ��� ��ü�� ��(x,y, scale)</param>
/// <param name="args2"></param>
/// <returns></returns>
int Bumpped_Check(struct Bumpped_range_args args1, struct Bumpped_range_args args2)
{
    //width is 500*args.size
	//height is 500*args.size
	const double width1 = 500 * args1.scale;//��� ������Ʈ�� 500*500�̹Ƿ� ����� ����� �����ϴ� ũ�� ���
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
/// ��� �̹����� ��ȸ�ϸ� image[obj_lo]�� �浹�ϴ� �갡 �ִ����� Ž��
/// </summary>
/// <param name="images">�̹��� ���̾� �迭</param>
/// <param name="image_count">���̾��� ����</param>
/// <param name="obj_lo">������ �Ǵ� ������Ʈ�� images���� ��� �ִ���</param>
/// <returns>�浹�Ǵ� ��ü�� ��ġ</returns>
int Bumpped(Image* images, int image_count, int obj_lo)//�̹��� �迭, �̹��� ����, ��ü�� ��ġ
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
* @brief �̹����� ���� �� �ִ� ������ �������� ã���ش�
* @param images �̹��� �迭
* @returns �̹����� ���� �� �ִ� ������ �ε���
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

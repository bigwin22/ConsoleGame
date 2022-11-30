#pragma once

#include <Windows.h>
#include <WinUser.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>

//Ű ���¸� �����ϴ� ����ü
typedef struct {
    bool pressedList[255];//Ű ��������
    int keyState[255];// 0 : not pressed, 1 : started pressing(1 frame), 2 : pressing, 3 : let go(1 frame)
}InputList;

InputList inputList;

//���콺 ��ǥ���� �����ϴ� ����ü
typedef struct {
    int x, y;
}Pixel;
Pixel mousePos;

//Ű �Է��� �޾ƿ��� �Լ�
void GetInput()
{
    for (int checkKey = 0; checkKey <= 0xfe; checkKey++)//check every key
    {
        if (GetAsyncKeyState(checkKey) & 0x8000)
        {
            inputList.pressedList[checkKey] = true;//Ű ���� ����
			inputList.keyState[checkKey] = (inputList.keyState[checkKey] + 1) % 15;//�ݺ� �Է� ������ ���� 15���� ���� ������ ����
        }
        else
        {
            inputList.pressedList[checkKey] = false;
            inputList.keyState[checkKey] = 0;
        }

        POINT _mousePos;
		GetCursorPos(&_mousePos);//���콺 ��ǥ�� ����
        mousePos.x = (int)(_mousePos.x * 1.25);
        mousePos.y = (int)(_mousePos.y * 1.25); 
    }
}

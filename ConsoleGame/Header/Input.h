#pragma once

#include <Windows.h>
#include <WinUser.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>

//키 상태를 저장하는 구조체
typedef struct {
    bool pressedList[255];//키 눌림여부
    int keyState[255];// 0 : not pressed, 1 : started pressing(1 frame), 2 : pressing, 3 : let go(1 frame)
}InputList;

InputList inputList;

//마우스 좌표값을 저장하는 구조체
typedef struct {
    int x, y;
}Pixel;
Pixel mousePos;

//키 입력을 받아오는 함수
void GetInput()
{
    for (int checkKey = 0; checkKey <= 0xfe; checkKey++)//check every key
    {
        if (GetAsyncKeyState(checkKey) & 0x8000)
        {
            inputList.pressedList[checkKey] = true;//키 눌림 저장
			inputList.keyState[checkKey] = (inputList.keyState[checkKey] + 1) % 15;//반복 입력 방지를 위해 15으로 나눈 나머지 저장
        }
        else
        {
            inputList.pressedList[checkKey] = false;
            inputList.keyState[checkKey] = 0;
        }

        POINT _mousePos;
		GetCursorPos(&_mousePos);//마우스 좌표값 저장
        mousePos.x = (int)(_mousePos.x * 1.25);
        mousePos.y = (int)(_mousePos.y * 1.25); 
    }
}

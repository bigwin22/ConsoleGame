#pragma once

#include <Windows.h>
#include <WinUser.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool pressedList[255];
    int keyState[255];// 0 : not pressed, 1 : started pressing(1 frame), 2 : pressing, 3 : let go(1 frame)
}InputList;

InputList inputList;

typedef struct {
    int x, y;
}Pixel;
Pixel mousePos;

void GetInput()
{
    for (int checkKey = 0; checkKey <= 0xfe; checkKey++)//check every key
    {
        if (GetAsyncKeyState(checkKey) & 0x8000)
        {
            inputList.pressedList[checkKey] = true;
        }
        else
        {
            inputList.pressedList[checkKey] = false;
        }

        POINT _mousePos;
        GetCursorPos(&_mousePos);
        mousePos.x = (int)(_mousePos.x * 1.25);
        mousePos.y = (int)(_mousePos.y * 1.25); 
    }
}



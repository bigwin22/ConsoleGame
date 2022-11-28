#pragma once

#include "Input.h"


void GetInput()
{
    for (int checkKey = 0; checkKey <= 0xfe; checkKey++)//check every key
    {
        if (GetAsyncKeyState(checkKey) & 0x8000)
        {
            inputList.pressedList[checkKey] = true;
            inputList.keyState[checkKey] = (inputList.keyState[checkKey] + 1) % 10;
            printf("%d", inputList.keyState[checkKey]);
        }
        else
        {
            inputList.pressedList[checkKey] = false;
            inputList.keyState[checkKey] = 0;
        }

        POINT _mousePos;
        GetCursorPos(&_mousePos);
        mousePos.x = (int)(_mousePos.x * 1.25);
        mousePos.y = (int)(_mousePos.y * 1.25);
    }
}

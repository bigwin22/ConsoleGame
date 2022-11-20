//disable warnings
#pragma warning(disable:4996)

#include <stdio.h>
#include "Header/Image/ImageLayer.h"
#include "Header/Console.h"
#include "Header/Define.h"

int main() {
	Console_init();//콘솔 기본 설정
	
    ImageLayer imageLayer = DEFAULT_IMAGE_LAYER;
    imageLayer.initialize(&imageLayer); //초기화

    Image images[3] = {

        {"Resource/background/background3.bmp", 0, 0,1.7}, //{이미지 이름, 시작 x좌표, 시작 y좌표, 크기 배율(쓰지 않으면 기본값인 16이 들어감)} 
        {"Resource/Spaceship.bmp",0,0,0.2},
    }; //배열의 첫 원소가 가장 아래 그려진다.

    imageLayer.imageCount = 3; //images 배열의 크기보다 작거나 같아야 한다.
    imageLayer.images = images;
    
    int i = 0;
    while (1)
    {
        if (_kbhit())
        {
            char key = _getch();
            switch (key)
            {
            case LEFT:
				images[1].x -= 10;
                break;
            case RIGHT:
				images[1].x += 10;
                break;
            case DOWN:
				images[1].y += 10;
                break;
            case UP:
				images[1].y -= 10;
                break;
            }
        }
		imageLayer.renderAll(&imageLayer);
    }
}
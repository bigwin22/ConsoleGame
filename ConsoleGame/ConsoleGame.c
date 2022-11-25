//disable warnings
#pragma warning(disable:4996)

#include <stdio.h>
#include "Header/Define.h"

int main()
{
    Console_init();//콘솔 기본 설정
    ImageLayer imageLayer = DEFAULT_IMAGE_LAYER;
    imageLayer.initialize(&imageLayer); //초기화

    Image images[100] = {
        {"Resource/background/background3.bmp", 0, 0,1.4}, //{이미지 이름, 시작 x좌표, 시작 y좌표, 크기 배율(쓰지 않으면 기본값인 16이 들어감)} 
    }; //배열의 첫 원소가 가장 아래 그려진다.

    imageLayer.imageCount = 100; //images 배열의 크기보다 작거나 같아야 한다.
    imageLayer.images = images;

    while (1)
    {
        gotoxy(1,42);
        printf("score");
	    imageLayer.renderAll(&imageLayer); //모든 이미지를 그린다.
    }

    getch();
}
﻿//disable warnings
#pragma warning(disable:4996)

#include <stdio.h>
#include "Header/Define.h"

int Using_location;

int main()
{
	int score = 0, high_score = 0;



    Console_init();//콘솔 기본 설정
    ImageLayer imageLayer = DEFAULT_IMAGE_LAYER;
    imageLayer.initialize(&imageLayer); //초기화

    Image images[100] = {
        {"Resource/background/background3.bmp", 0, 0,1.4,0,-1},
    }; //배열의 첫 원소가 가장 아래 그려진다.

    imageLayer.imageCount = 100; //images 배열의 크기보다 작거나 같아야 한다.
    imageLayer.images = images;

	
    images[99].fileName = "Resource/Spaceship/Spaceship_fire.bmp";
	images[99].x = 400;
	images[99].y = 400;
	images[99].scale = 0.25;
	images[99].type = 0;


	User user = {3, &images[99].x, &images[99].y, 5, 1,99,3};
    
    srand(time(NULL));
    HANDLE hThread;
    //print hello

	
    hThread = (HANDLE)_beginthreadex(NULL, 0,MobGenerator, images, 0, NULL);
	//hThread1 = (HANDLE)_beginthreadex(NULL, 0, Getinpu)
    while (1)
    {
		print_score(score, high_score);
        GetInput();
		User_update(&user, &images[user.lo]);
		imageLayer.renderAll(&imageLayer);
    }

    getch();
}
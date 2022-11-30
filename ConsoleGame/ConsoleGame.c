﻿//disable warnings
#pragma warning(disable:4996)

#include <stdio.h>
#include "Header/Define.h"
#include "Header/easyAudio.h"
#include <tchar.h>
#include <windows.h>
#include <strsafe.h>


User user;//유저 객체에 대한 값 설정
int score = 0, high_score = 0;//점수

void In_game()
{

    score = 0;
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
    images[99].type = 0;//유저 객체 이미지에 대한 기본 설정

    user.HP = 3, user.x = &images[99].x, user.y = &images[99].y, user.speed = 5, user.lo = 99, user.Missile_limit = 3, user.damage = 1;//유저 객체에 대한 값 설정


    srand(time(NULL));
    HANDLE hThread;//멀티프로세스 핸들
    //print hello

    hThread = (HANDLE)_beginthreadex(NULL, 0, MobGenerator, images, 0, NULL);
    //hThread1 = (HANDLE)_beginthreadex(NULL, 0, Getinpu)
    while (1)
    {
        FILE* fp;
        fp = fopen("High.txt", "r");
        fscanf(fp, "%d", &high_score);
        fclose(fp);
        print_info(score, high_score, user);
        GetInput();//동시 입력 가능
        User_update(&user, images);//유저의 상태 업데이트
        if (user.HP <= 0)
        {
            if (End_Game(&score, &high_score) == 1)
            {
                In_game();
                return;
            }
            else {
                fclose(fp); return;
            }
        }
		if (score > high_score)
		{
			high_score = score;
            FILE* fp;
            fp = fopen("High.txt", "w");
			fprintf(fp, "%d", high_score);
            fclose(fp);
		}
        if (score > 1000)
        {
			images[0].fileName = "Resource/background/background4.bmp";
			images[0].scale = 1.4;
        }
        if (score > 5000)
        {
			images[0].fileName = "Resource/background/background5.bmp";
			images[0].scale = 1.4;
        }
		if (score > 15000)
		{
			images[0].fileName = "Resource/background/background6.bmp";
			images[0].scale = 1.4;
		}
        imageLayer.renderAll(&imageLayer);
    }

}

int main()
{
    Console_init();
   // playBGM("Resource/Sound/");
    Start_Game();
	In_game();
	return 0;
}
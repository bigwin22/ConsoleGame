/*
이 게임은 미사일을 쏴 적들과 방해물을 부수며 가장 높은 점수를 받으면 이기는 게임이다.
스테이지는 점수가 1000단위로 달라지며 스테이지가 높아질 수록 적들과 방해물의 속도과 목숨이 점점 늘어난다.
HP가 0이되면 게임은 종료되며
마지막 화면에서 좌클릭을 누르면 재시작, 우클릭은 게임을 종료시킨다.
*/

//disable warnings
#pragma warning(disable:4996)

#include <stdio.h>
#include "Header/Define.h"
#include "Header/easyAudio.h"
#include <tchar.h>
#include <windows.h>
#include <strsafe.h>


User user;//유저 객체에 대한 값 설정
int score = 0, high_score = 0;//점수


//인게임 함수, 여기서 엔드 게임을 담당함.
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
    FILE* fp;
    fp = fopen("High.txt", "r");
    fscanf(fp, "%d", &high_score);
    while (1)
    {
        fclose(fp);
        print_info(score, high_score, user);
        GetInput();//동시 입력 가능
        User_update(&user, images);//유저의 상태 업데이트
        if (user.HP <= 0)
        {
            FILE* fp;
            fp = fopen("High.txt", "w");
            fprintf(fp, "%d", high_score);
            fclose(fp);
            if (End_Game(&score, &high_score) == 1)
            {
                In_game();
                return;
            }
            else {
                return;
            }
        }
		if (score > high_score)
		{
			high_score = score;

		}
        if (score%1000 <= 9)
        {
			images[0].fileName = "Resource/background/background4.bmp";
			images[0].scale = 1.4;
        }
        if (score%3000 <= 9)
        {
			images[0].fileName = "Resource/background/background3.bmp";
			images[0].scale = 1.4;
        }
        imageLayer.renderAll(&imageLayer);
    }

}

//콘솔 기본 설정 후 게임 시작
int main()
{
 
    Console_init();
   // playBGM("Resource/Sound/");
    Start_Game();
	In_game();
	return 0;
}
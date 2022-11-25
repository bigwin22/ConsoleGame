//disable warnings
#pragma warning(disable:4996)

#include <stdio.h>
#include "Header/Define.h"




int main()
{
	int score = 0, high_score = 0;



    Console_init();//콘솔 기본 설정
    ImageLayer imageLayer = DEFAULT_IMAGE_LAYER;
    imageLayer.initialize(&imageLayer); //초기화

    Image images[100] = {
        {"Resource/background/background3.bmp", 0, 0,1.4},
        {"Resource/Spaceship/Spaceship_fire.bmp",10,1,0.25}
    }; //배열의 첫 원소가 가장 아래 그려진다.

    imageLayer.imageCount = 100; //images 배열의 크기보다 작거나 같아야 한다.
    imageLayer.images = images;

	User user = {3, &images[1].x, &images[1].y, 10, 1,1};
    

    while (1)
    {
		print_score(score, high_score);
		User_update(&user, &images[user.lo]);
		imageLayer.renderAll(&imageLayer);
    }

    getch();
}
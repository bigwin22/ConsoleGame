#include "Object.h"
#include <stdlib.h>
#include <stdlib.h>
#include "Judgement.h"
#include "Image/ImageLayer.h"


void Misile_Func(struct Misile_args Misile_arg)
{
	Misile misile = Misile_arg.misile;
	Image* images = Misile_arg.images;
	int* missile_limit = Misile_arg.missile_limit;

	int images_input = Images_Input_location(images);
	
	if (images_input == -1)
	{
		return;
	}
	
	images[images_input].fileName = "Resource/Missile/Missile1.bmp";
	images[images_input].x = *(misile.x);
	images[images_input].y = *(misile.y);
	images[images_input].scale = 0.25;

	for (int i = 1; Boarder_Check(images[images_input].x, images[images_input].y - misile.speed); i++)
	{
		images[images_input].y -= misile.speed;
		Sleep(10);
	}
	images[images_input].fileName = NULL, images[images_input].x = 0, images[images_input].y = 0, images[images_input].scale = 0;
	*missile_limit += 1;
	return;

}



void User_Move(User* user, Image* images)
{
	HANDLE hThread;
	int key = 0;
	if (_kbhit())
	{
		key = _getch();
		struct Misile_args Misile_arg = { {((*user).x), ((*user).y), 8, (*user).damage, 2},images - (*user).lo, &((*user).Missile_limit)};
		switch (key)
		{
		case LEFT:
			if (Boarder_Check(*((*user).x) - (*user).speed, *((*user).y)) == 1)
			{
				*((*user).x) -= (*user).speed;
				(*images).fileName = "Resource/Spaceship/Spaceship_fire.bmp";
			}
			break;
		case RIGHT:
			if (Boarder_Check(*((*user).x) + (*user).speed, *((*user).y)) == 1)
			{
				*((*user).x) += (*user).speed;
				(*images).fileName = "Resource/Spaceship/Spaceship_fire.bmp";
			}
			break;
		case UP:
			if (Boarder_Check(*((*user).x), *((*user).y) - (*user).speed) == 1)
			{
				*((*user).y) -= (*user).speed;
				(*images).fileName = "Resource/Spaceship/Spaceship_strong_fire.bmp";
			}
			break;
		case DOWN:
			if (Boarder_Check(*((*user).x), *((*user).y) + (*user).speed) == 1)
			{
				*((*user).y) += (*user).speed;
				(*images).fileName = "Resource/Spaceship/Spaceship_nonfire.bmp";
			}
			break;
		case SPACE:
			if ((*user).Missile_limit > 0)
			{
				(*user).Missile_limit--;
				hThread = (HANDLE)_beginthreadex(NULL, 0, Misile_Func, &Misile_arg, 0, NULL);
			}
			break;
		}
	}
}

void User_update(User* user, Image* images)//Usesr update
{
	User_Move(user, images);
	//printf("%p",images - (*user).lo);
}

void MobGenerator(Image *images)
{
	char list[100][100] = {"Resource/Mob/3q3/mob1.bmp", "Resource/Mob/3q3/mob2.bmp", "Resource/Mob/3q3/mob3.bmp", "Resource/Mob/3q3/mob4.bmp" }
	while (1)
	{
		int images_input = Images_Input_location(images);
		
		images[images_input] = 
		
		//Sleep(10);
	}

}
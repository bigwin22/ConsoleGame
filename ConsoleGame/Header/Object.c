#include "Object.h"
#include <stdlib.h>
#include <stdlib.h>
#include "Judgement.h"
#include "Input.h"
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
	images[images_input].type = 2;

	for (int i = 1; Boarder_Check(images[images_input].x, images[images_input].y - misile.speed); i++)
	{
		images[images_input].y -= misile.speed;
		if (Bumpped(images, 100, images_input) == 1) {
			images[images_input].fileName = NULL;
			images[images_input].x = 0;
			images[images_input].y = 0;
			images[images_input].scale = 0;
			images[images_input].type = 0;
			break;
		}
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
	struct Misile_args Misile_arg = { {((*user).x), ((*user).y), 8, (*user).damage, 2},images - (*user).lo, &((*user).Missile_limit) };
	
	//up down left right space
	if (inputList.pressedList[0x26])
	{
		printf("up");
		if (Boarder_Check(*((*user).x), *((*user).y) - (*user).speed))
		{
			*((*user).y) -= (*user).speed;
		}
	}
	if (inputList.pressedList[0x28])
	{
		if (Boarder_Check(*((*user).x), *((*user).y) + (*user).speed))
		{
			*((*user).y) += (*user).speed;
		}
	}
	if (inputList.pressedList[0x25])
	{
		if (Boarder_Check(*((*user).x) - (*user).speed, *((*user).y)))
		{
			*((*user).x) -= (*user).speed;
		}
	}
	if (inputList.pressedList[0x27])
	{
		if (Boarder_Check(*((*user).x) + (*user).speed, *((*user).y)))
		{
			*((*user).x) += (*user).speed;
		}
	}
	if (inputList.pressedList[0x20] && inputList.keyState[0x20] == 9)//얘 너무 빠른데
	{
		if ((*user).Missile_limit > 0)
		{
			(*user).Missile_limit--;
			hThread = (HANDLE)_beginthreadex(NULL, 0, Misile_Func, &Misile_arg, 0, NULL);
		}
	}
}

void User_update(User* user, Image* images)//Usesr update
{
	User_Move(user, images);
	//printf("%p",images - (*user).lo);
}

void Mob_Move(struct Mob_args args)
{
	Mob mob = args.mob;
	Image* images = args.images;

	while (1)
	{
		if (Boarder_Check(*(mob.x) + mob.speed, *(mob.y)))
		{
			*(mob.x) += mob.speed;
		}
		else
		{
			if (Boarder_Check(0, *(mob.y) + 100))
			{
				*(mob.x) = 0, *(mob.y) += 300;
			}
			else
			{
				break;
			}
		}
		Sleep(100);
	}
	images[mob.lo].fileName = NULL, images[mob.lo].x = 0, images[mob.lo].y = 0, images[mob.lo].scale = 0;
}

void MobGenerator(Image *images)
{
	
	char list[100][100] = { "Resource/Mob/3q3/mob1.bmp", "Resource/Mob/3q3/mob2.bmp", "Resource/Mob/3q3/mob3.bmp", "Resource/Mob/3q3/mob4.bmp", "Resource/Mob/3q3/mob5.bmp", "Resource/Mob/3q3/mob6.bmp", "Resource/Mob/3q3/mob7.bmp" };
	for (int i = 1; ; i++)
	{
		HANDLE hThread;
		int images_input = Images_Input_location(images); 
		if (images_input == -1)
		{
			continue;
		}
		int mob_number = rand() % 7;
		images[images_input].fileName = list[mob_number], images[images_input].x = 0, images[images_input].y = 0, images[images_input].scale = 0.25, images[images_input].type = 1;
		struct Mob_args args = {{3,3,&images[images_input].x, &images[images_input].y, 10, 1, images_input},images};
		hThread = (HANDLE)_beginthreadex(NULL, 0, Mob_Move, &args, 0, NULL);
		Sleep(2000);
	}

}
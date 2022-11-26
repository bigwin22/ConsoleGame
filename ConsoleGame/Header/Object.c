#include "Object.h"

#include "Judgement.h"


void Misile_Func(struct Misile_args Misile_arg)
{
	Misile misile = Misile_arg.misile;
	Image* images = Misile_arg.images;

	images[2].fileName = "Resource/Missile/Missile1.bmp";
	images[2].x = *(misile.x);
	images[2].y = *(misile.y);
	images[2].scale = 0.25;

	for (int i = 1; Boarder_Check(images[2].x, images[2].y - misile.speed); i++)
	{
		images[2].y -= misile.speed;
		Sleep(10);
	}
	images[2].fileName = NULL, images[2].x = 0, images[2].y = 0, images[2].scale = 0;

	return;

}

void User_Move(User* user, Image* images)
{
	HANDLE hThread;
	int key = 0;
	if (_kbhit())
	{
		key = _getch();
		struct Misile_args Misile_arg = { {((*user).x), ((*user).y), 1, (*user).damage, 2},images - (*user).lo };
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
			hThread = (HANDLE)_beginthread(Misile_Func, 0, &Misile_arg);
			break;
		}
	}
}

void User_update(User* user, Image* images)//Usesr update
{
	User_Move(user, images);
	//printf("%p",images - (*user).lo);
}
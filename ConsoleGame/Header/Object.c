#include "Object.h"
#include <stdlib.h>
#include <stdlib.h>
#include "Judgement.h"
#include "Input.h"
#include "Image/ImageLayer.h"
#include "easyAudio.h"

/*
* @brief 장애물 생성
* 
*/
void Obstacle(Image* images, int x, int y, int hp)
{
	if (!Boarder_Check(x, y)) return;
	
	extern int score;
	int image_input = Images_Input_location(images, 0);
	if (image_input == -1)
	{
		return;
	}
	images[image_input].fileName = "Resource/Obstacle/Obstacle1.bmp", images[image_input].x = x, images[image_input].y = y + 150, images[image_input].scale = 0.2, images[image_input].type = 3, images[image_input].status = 0;
	while (1)
	{
		if (images[image_input].status == 3) {
			playSound("Resource/Sound/SoundEffect/ObstacleAttacked.wav");
			if (hp == 0)
			{
				images[image_input].fileName = NULL, images[image_input].x = 0, images[image_input].y = 0, images[image_input].scale = 0, images[image_input].type = 0, images[image_input].status = 0;
				score += 5;
				return;
			}
			hp -= 1;
			images[image_input].status = 0;
			continue;
		}
	}

}
	//struct Obstacle obstacle = { 1, &images[].x, &images[OBSTACLE].y, OBSTACLE };
   
/**
* @brief		미사일 객체 생성
* @param struct Misile_args Misile_arg : 미사일 객체 생성에 필요한 값들
* @return		void
*/
void Misile_Func(struct Misile_args Misile_arg)
{
	Misile misile = Misile_arg.misile;
	Image* images = Misile_arg.images;
	int* missile_limit = Misile_arg.missile_limit;

	int images_input = Images_Input_location(images, 0);
	
	if (images_input == -1)//넣을데 없으면 리턴 
	{
		return;
	}
	
	images[images_input].fileName = "Resource/Missile/Missile1.bmp";//객체 생성
	images[images_input].x =  *(misile.x), images[images_input].y = *(misile.y);
	images[images_input].scale = 0.25;
	images[images_input].type = 2;
	images[images_input].status = 0;

	for (int i = 1; Boarder_Check(images[images_input].x, images[images_input].y - misile.speed); i++)
	{
		images[images_input].y -= misile.speed;
		int bump = Bumpped(images, 100, images_input,3,-1,0,2);
		if (bump != -1 && (images[bump].type == 1 || images[bump].type == 3)) {//충돌 감지
			images[images_input].fileName = NULL;
			images[images_input].x = 0;
			images[images_input].y = 0;
			images[images_input].scale = 0;
			images[images_input].type = 0;

			images[bump].status = 3;
			break;
		}
		Sleep(10);
	}
	images[images_input].fileName = NULL, images[images_input].x = 0, images[images_input].y = 0, images[images_input].scale = 0;//객체 삭제
	*missile_limit += 1; //미사일 리밋 복구
	return;

}


/**
* @brief		유저 객체 이동
* @param User* user : 유저 객체
* @param Image* images : 이미지 객체
* @return		void
*/
void User_Move(User* user, Image* images)
{

	HANDLE hThread;//스레드 핸들
	struct Misile_args Misile_arg = { {((*user).x), ((*user).y), 8, (*user).damage, 2},images, &((*user).Missile_limit) };// 미사일 객체 생성에 필요한 값들
	
	//up down left right space
	if (inputList.pressedList[0x26])
	{		
		if (Boarder_Check(*((*user).x), *((*user).y) - (*user).speed))
		{
			*((*user).y) -= (*user).speed;
		}
		if (Bumpped(images, 100, (*user).lo, 4, -1, 0, 2,1) != -1)
		{
			if (Boarder_Check(*((*user).x), *((*user).y) +10))
			{
				*((*user).y) += 10;
			}
		}

	}
	if (inputList.pressedList[0x28])
	{		
		if (Boarder_Check(*((*user).x), *((*user).y) + (*user).speed))
		{
			*((*user).y) += (*user).speed;
		}
		if (Bumpped(images, 100, (*user).lo, 4, -1, 0, 2,1) != -1)
		{
			if (Boarder_Check(*((*user).x), *((*user).y) - 10))
			{
				*((*user).y) -= 10;
			}
		}

	}
	if (inputList.pressedList[0x25])
	{		
		if (Boarder_Check(*((*user).x) - (*user).speed, *((*user).y)))
		{
			*((*user).x) -= (*user).speed;
		}
		if (Bumpped(images, 100, (*user).lo, 4, -1, 0, 2,1) != -1)
		{
			if (Boarder_Check(*((*user).x)+10, *((*user).y)))
			{
				*((*user).x) += 10;
			}
		}

	}
	if (inputList.pressedList[0x27])
	{		
		if (Boarder_Check(*((*user).x) + (*user).speed, *((*user).y)))
		{
			*((*user).x) += (*user).speed;
		}
		if (Bumpped(images, 100, (*user).lo, 4, -1, 0, 2,1) != -1)
		{
			if (Boarder_Check(*((*user).x)-10, *((*user).y)))
			{
				*((*user).x) -= 10;
			}
		}

	}
	if (inputList.pressedList[0x20] && inputList.keyState[0x20] == 14)//미사일 발사(딜레이를 위해 9 조건 추가)
	{
		if ((*user).Missile_limit > 0)
		{
			playSound("Resource/Sound/SoundEffect/wav/shooting.wav");
			(*user).Missile_limit--;//갯수 차감
			hThread = (HANDLE)_beginthreadex(NULL, 0, Misile_Func, &Misile_arg, 0, NULL);//발사(객체는 함수에서 생성)
		}
	}
	
	int bumpped = Bumpped(images, 100, (*user).lo, 3, -1, 0, 2);
	if (images[bumpped].type == 1)
	{
		images[bumpped].status = 1;
	}
}

/**
* @brief		유저 객체 업데이트
* @param User* user : 유저 객체
* @param Image* images : 이미지 객체
* @return		void
*/
void User_update(User* user, Image* images)//Usesr update
{
	User_Move(user, images);
}

/**
* @brief		적 객체 이동
* @param struct Enemy_args Enemy_arg : 적 객체 생성에 필요한 값들
* @return		void
*/
void Mob_Move(struct Mob_args args)
{
	Mob mob = args.mob;
	Image* images = args.images;

	while (1)
	{
		extern User user;
		if (user.HP <= 0)
		{
			break;
		}
		if (Boarder_Check(*(mob.x) + mob.speed, *(mob.y)))
		{
			*(mob.x) += mob.speed;
		}
		else
		{
			if (Boarder_Check(0, *(mob.y) + 100))//끝에 닿으면 밑으로 이동
			{
				*(mob.x) = 0, *(mob.y) += 300;
			}
			else
			{
				extern User user;
				user.HP -= 1;
				break;
			}
		}
		if (images[mob.lo].status == 3) {//충돌 감지
			int x = *(mob.x), y = *(mob.y);
			mob.HP -= 1;
			if (mob.HP == 0)
			{
				images[mob.lo].fileName = NULL;
				images[mob.lo].x = 0;
				images[mob.lo].y = 0;
				images[mob.lo].scale = 0;
				images[mob.lo].type = 0;
				images[mob.lo].status = 0;	
				extern int score;
				score += 100;
				Obstacle(images, x, y, rand() % (score / 800 + 1) + 1);				
				return;
			}
			images[mob.lo].status = 0;
			playSound("Resource/Sound/SoundEffect/wav/dead.wav");
			continue;
		}
		if (images[mob.lo].status == 1)
		{
			extern int score;
			mob.HP -= 1;
			
			images[mob.lo].fileName = NULL;
			images[mob.lo].x = 0;
			images[mob.lo].y = 0;
			images[mob.lo].scale = 0;
			images[mob.lo].type = 0;
			images[mob.lo].status = 0;
			score -= 100;

			extern User user;
			playSound("Resource/Sound/SoundEffect/wav/UserAttacked.wav");
			user.HP -= 1;
			return;
		}
		Sleep(100);
	}
	images[mob.lo].fileName = NULL, images[mob.lo].x = 0, images[mob.lo].y = 0, images[mob.lo].scale = 0, images[mob.lo].status = 0;
}

/**
* @brief		적 객체 생성
* @param Image *images : 이미지 객체
*/
void MobGenerator(Image *images)
{
	
	char list[100][100] = { "Resource/Mob/3q3/mob1.bmp", "Resource/Mob/3q3/mob2.bmp", "Resource/Mob/3q3/mob3.bmp", "Resource/Mob/3q3/mob4.bmp", "Resource/Mob/3q3/mob5.bmp", "Resource/Mob/3q3/mob6.bmp", "Resource/Mob/3q3/mob7.bmp" };
	for (int i = 1; ; i++)
	{
		extern User user;
		if (user.HP <= 0)
		{
			break;
		}
		HANDLE hThread;
		int images_input = Images_Input_location(images, 1);
		if (images_input == -1)
		{
			continue;
		}
		int mob_number = rand() % 7;//몹 종류 랜덤
		images[images_input].fileName = list[mob_number], images[images_input].x = 0, images[images_input].y = 0, images[images_input].scale = 0.25, images[images_input].type = 1, images[images_input].status = 0;//객체 생성
		extern int score;
		struct Mob_args args = {{3,3,&images[images_input].x, &images[images_input].y, rand()%(score/1000+10)+1, rand()%3+1, images_input},images};//args생성
		hThread = (HANDLE)_beginthreadex(NULL, 0, Mob_Move, &args, 0, NULL);//몹 이동
		Sleep(1000*(rand()%3+3));
	}

}
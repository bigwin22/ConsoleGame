#pragma once
#include "Image/ImageLayer.h"
#include <stdio.h>
#include <windows.h>
#include <process.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#define ESC 27
#define SPACE 32


/*
* @brief 유제 객체
* @param HP : 체력
* @param *x: images의 x 주소값
* @param *y: images의 y 주소값
* @param speed :이동속도
* @param lo: images의 위치
* @param Missile_limit: 미사일 발사 제한
* @param damage: 미사일 데미지
*/
typedef struct _User
{
	int HP;
	int* x, * y;
	int speed;
	int damage;
	int lo;//Image에서 몇번째 이미지인지
	int Missile_limit;
}User;

/*
* @brief 미사일 객체
* @param *x: images의 x 주소값
* @param *y: images의 y 주소값
* @param speed :이동속도
* @param damage: 미사일 데미지
* @param lo : images의 위치
*/
typedef struct _Misile
{
	int* x, * y;
	int speed;
	int damage;
	int lo;
}Misile;


/*
* @brief 몹 객체
* @param Orginal_HP : 시작체력
* @param HP : 현제 체력
* @param *x: images의 x 주소값
* @param *y: images의 y 주소값
* @param speed :이동속도
* @param damage : 데미지
* @param lo : images의 위치
*/
typedef struct _Mob
{
	int Original_HP;
	int HP;
	int* x, * y;
	int speed;
	int damage;
	int lo; //Image에서 어디 있는지를 나타내는 변수
}Mob;


/*
* @brief 미사일 함수에 필요한 파라미터
* @param Misile misile : 미사일 객체
* @param Image *images : 이미지 객체
* @param int * missile_limit: 미사일 갯수 제한 주소값
*/
struct Misile_args
{
	Misile misile;
	Image* images;
	int* missile_limit;
};

/*
* @brief 몹 함수에 필요한 파라미터
* @param Mob mob : 몹 객체
* @param Image *images : 이미지 객체
*/
struct Mob_args
{
	Mob mob;
	Image* images;
};


void Misile_Func(struct Misile_args Misile_arg);
void User_Move(User* user, Image* images);
void User_update(User* user, Image* images);
void MobGenerator();



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

extern int Using_location;

typedef struct _User
{
	int HP;
	int* x, * y;
	int speed;
	int damage;
	int lo;//Image에서 몇번째 이미지인지
	int Missile_limit;
}User;

typedef struct _Misile
{
	int* x, * y;
	int speed;
	int damage;
	int lo;
}Misile;

typedef struct _Mob
{
	int Original_HP;
	int HP;
	int* x, * y;
	int speed;
	int damage;
	int lo; //Image에서 어디 있는지를 나타내는 변수
}Mob;

struct Misile_args
{
	Misile misile;
	Image* images;
	int* missile_limit;
};

struct Mob_args
{
	Mob mob;
	Image* images;
};


void Misile_Func(struct Misile_args Misile_arg);
void User_Move(User* user, Image* images);
void User_update(User* user, Image* images);
void MobGenerator();



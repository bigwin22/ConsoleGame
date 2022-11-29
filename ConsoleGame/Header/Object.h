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
* @brief ���� ��ü
* @param HP : ü��
* @param *x: images�� x �ּҰ�
* @param *y: images�� y �ּҰ�
* @param speed :�̵��ӵ�
* @param lo: images�� ��ġ
* @param Missile_limit: �̻��� �߻� ����
* @param damage: �̻��� ������
*/
typedef struct _User
{
	int HP;
	int* x, * y;
	int speed;
	int damage;
	int lo;//Image���� ���° �̹�������
	int Missile_limit;
}User;

/*
* @brief �̻��� ��ü
* @param *x: images�� x �ּҰ�
* @param *y: images�� y �ּҰ�
* @param speed :�̵��ӵ�
* @param damage: �̻��� ������
* @param lo : images�� ��ġ
*/
typedef struct _Misile
{
	int* x, * y;
	int speed;
	int damage;
	int lo;
}Misile;


/*
* @brief �� ��ü
* @param Orginal_HP : ����ü��
* @param HP : ���� ü��
* @param *x: images�� x �ּҰ�
* @param *y: images�� y �ּҰ�
* @param speed :�̵��ӵ�
* @param damage : ������
* @param lo : images�� ��ġ
*/
typedef struct _Mob
{
	int Original_HP;
	int HP;
	int* x, * y;
	int speed;
	int damage;
	int lo; //Image���� ��� �ִ����� ��Ÿ���� ����
}Mob;


/*
* @brief �̻��� �Լ��� �ʿ��� �Ķ����
* @param Misile misile : �̻��� ��ü
* @param Image *images : �̹��� ��ü
* @param int * missile_limit: �̻��� ���� ���� �ּҰ�
*/
struct Misile_args
{
	Misile misile;
	Image* images;
	int* missile_limit;
};

/*
* @brief �� �Լ��� �ʿ��� �Ķ����
* @param Mob mob : �� ��ü
* @param Image *images : �̹��� ��ü
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



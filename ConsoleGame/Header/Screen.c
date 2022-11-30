#include "Console.h"
#include "Object.h"


void End_Game(int* score, int* high_score)
{
	return;
}

void Playing_Game()
{

	return;
}

void Start_Game(int* score, int* high_score)
{
	return;
}

/*
* @brief 점수 출력
* @param score : 현재 점수
* @param high_score : 최고 점수
*/
void print_info(int score, int high_score, User user)
{
    gotoxy(1, 42);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x60);
    printf("score:%03d", score);
    gotoxy(15, 42);
    printf("high:%03d", high_score);
    gotoxy(25, 42);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x30);
	printf("HP:%d", user.HP);
}




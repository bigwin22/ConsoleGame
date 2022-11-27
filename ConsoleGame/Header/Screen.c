#include "Console.h"

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
void print_score(int score, int high_score)
{
    gotoxy(1, 42);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x60);
    printf("score:%03d", score);
    gotoxy(37, 42);
    printf("high score:%03d", high_score);
}




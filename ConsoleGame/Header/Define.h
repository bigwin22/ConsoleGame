#pragma once
#include "Image/ImageLayer.h"
#include "Console.h"
#include "Object.h"
#include "Screen.h"
#include "Judgement.h"
#include <stdio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#define ESC 27
#define SPACE 32

void print_score(int score, int high_score)
{
    gotoxy(1, 42);
    printf("score:%03d", score);
    gotoxy(37, 42);
    printf("high score:%03d", high_score);
}







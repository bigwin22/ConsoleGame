#pragma once
#include <stdio.h>
#include "Object.h"

void End_Game(int* score, int* high_score);
void Playing_Game();
void Start_Game(int* score, int* high_score);
void print_info(int score, int high_score, User user);

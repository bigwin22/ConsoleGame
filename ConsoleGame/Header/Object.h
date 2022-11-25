#pragma once

typedef struct
{
	int HP;
	int* x, * y;
	int direction;//0: left, 1: right, 2: up, 3: down
}User;

typedef struct
{
	int Original_HP;
	int HP;
	int* x, * y;
}Mob;
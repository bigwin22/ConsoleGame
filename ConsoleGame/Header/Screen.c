#include "Console.h"
#include "Object.h"
#include "Judgement.h"


int End_Game(int* score, int* high_score)
{
	//Change color to default;
	system("cls");
	system("color 07");
    gotoxy(18,15);
	printf("Game Over");
	gotoxy(18, 16);
	printf("Your Score : %d", *score);
	
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);

    INPUT_RECORD rec;
    DWORD dwNOER;
    HANDLE CIN = 0;

    int mouse_xx, mouse_yy, mouse_lr;
    while (1)
    {
        ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // �ܼ�â �Է��� �޾Ƶ���.
        if (rec.EventType == MOUSE_EVENT) {// ���콺 �̺�Ʈ�� ���

            if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
                mouse_xx = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
                mouse_yy = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

                mouse_lr = 1;

                printf("%2d %2d %2d\n", mouse_xx, mouse_yy, mouse_lr);

                break;
            }
            else if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
                mouse_xx = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
                mouse_yy = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�


                mouse_lr = 0;

                printf("%2d %2d %2d\n", mouse_xx, mouse_yy, mouse_lr);

                break;
            }
        }

        Sleep(1);
    }

	
	return mouse_lr;
}

void Playing_Game()
{
	
    return;
}

void Start_Game()
{
    typedef struct {
        bool pressedList[255];//Ű ��������
        int keyState[255];// 0 : not pressed, 1 : started pressing(1 frame), 2 : pressing, 3 : let go(1 frame)
    }InputList;

    while (1)
    {
        system("cls");
        system("color 07");
        gotoxy(20,20);
        printf("Pixel Space\n\n                       Press Space to Start");
        //printf("                 ");
        GetInput();
		extern InputList inputList;
        if (inputList.pressedList[0x20])
        {
			break;
        }
        Sleep(100);
    }
    return;

}

/*
* @brief ���� ���
* @param score : ���� ����
* @param high_score : �ְ� ����
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x60);
    gotoxy(30, 42);
    printf("Stage:%d", score / 1000);
	
}




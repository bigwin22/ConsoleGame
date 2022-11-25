//disable warnings
#pragma warning(disable:4996)

#include <stdio.h>
#include <windows.h>
#include <process.h>

int a = 1;

unsigned ThredFunc(void* arg)
{
	int i;
	int cnt = *((int*)arg);
	
	// for (i = 0; i < cnt; i++)
	// {
	// 	Sleep(1000);
	// 	printf("%d %d %d\n", ((int*)arg)[0], ((int*)arg)[1], ((int*)arg)[2]);
	// }
	printf("%d", a);
	print();
	((int*)arg)[0] = 8;
}

void print()
{
	printf("hello world");
}

int main()
{
	HANDLE hThread;
	int param[3] = { 5, 3, 2 };
	while (1)
	{
		hThread = (HANDLE)_beginthreadex(NULL, 0, ThredFunc, (void*)param, 0, NULL);
		Sleep(1000);
		if (hThread == 0)
		{
			printf("Thread creation failed %d", param);
			
			return 1;
		}
	}
	
}


#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>
WINBASEAPI HWND WINAPI GetConsoleWindow ();

int main1(int argc,char *argv[])
{// 主线程运行结束，辅助线程也结束。
	HWND hwnd;
	HDC hdc;
	WORD* ptext;
	printf("there are some words in console window!\n下面的程序:\n用于在控制台程序中创建windows窗口\n");
	//system("color 3d");
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	LineTo(hdc,200,300);
	Rectangle(hdc,10,30,300,50);
	TextOut(hdc,10,10,_TEXT("HELLO WORLD\nyesnocancel!"),20);
	ReleaseDC(hwnd,hdc);
	getch();
	printf("after drawing\n");
    return 0;
}
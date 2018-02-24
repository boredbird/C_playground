#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

#include <windows.h>
#include <tchar.h>
WINBASEAPI HWND WINAPI GetConsoleWindow ();

#define M 15
#define N 15

enum Boolean {false, true};
enum Orient {east = 0, south, west, north};

typedef struct
{
	int hori;
	int vert;
}Coordinate;

typedef struct cell
{
	enum Boolean wall[4];
	enum Boolean visited;
	int visitID;
}Cell;

Cell maze[M][N];
Coordinate stack[M * N];
int top = -1;	/*指向实际的栈顶*/


void Push(int hori, int vert)
{
	stack[++top].hori = hori;
	stack[top].vert = vert;
}

void Pop()	/*Coordinate *coordinate*/
{
	top--;
/*	coordinate->hori = stack[top].hori;*/
/*	coordinate->vert = stack[top--].vert;*/
}

void ClearStack()
{
	int i;
	for(i = 0; i < M * N; i++)
	{
		stack[i].hori = -1;
		stack[i].vert = -1;
	}

	top = -1;
}

enum Boolean StackEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

int NextOrient(int current_hori, int current_vert)
{
	int rnd = (int)(4 * rand() / (RAND_MAX));
	int times = 0;
	int next_hori, next_vert;

	while(times < 4)
	{
		switch(rnd)
		{
			case east:
				next_hori = current_hori;
				next_vert = current_vert + 1;				
				break;
			case south:
				next_hori = current_hori + 1;
				next_vert = current_vert;
				break;
			case west:
				next_hori = current_hori;
				next_vert = current_vert - 1;
				break;
			case north:
				next_hori = current_hori - 1;
				next_vert = current_vert;
				break;
		}

		if((next_hori >= 0) && (next_hori < M) && (next_vert >= 0) && (next_vert < N)
			&& (!maze[next_hori][next_vert].visited))
			break;

		rnd++;
		rnd %= 4;
		times++;
	}

	if(times == 4)
		return -1;
	else
		return rnd;
}

void CreateMaze()
{
	int i, j, visit_num = 0, nextOrient;
	int current_hori, current_vert;/* next_hori, next_vert;*/

	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
		{
			maze[i][j].wall[east] = true;
			maze[i][j].wall[south] = true;
			maze[i][j].wall[west] = true;
			maze[i][j].wall[north] = true;
			maze[i][j].visited = false;
			maze[i][j].visitID = -1;
		}

	ClearStack();

	current_hori = 0;
	current_vert = 0;
	maze[current_hori][current_vert].visited = true;
	maze[current_hori][current_vert].visitID = visit_num++;

	Push(current_hori, current_vert);

	srand((unsigned)time(NULL));          /*初始化随机数*/
	while(visit_num < M * N)
	{
		nextOrient = NextOrient(current_hori, current_vert);

		if(nextOrient == -1)
		{
			if(!StackEmpty())
			{
				Pop();

				current_hori = stack[top].hori;
				current_vert = stack[top].vert;
			}
			else
			{
				printf("Error: Stack is empty.");
				exit(0);
			}
			continue;
		}
		else
		{
			maze[current_hori][current_vert].wall[nextOrient] = false;	/*拆当前格子的墙*/

			switch(nextOrient)
			{
				case east:					
					current_vert = current_vert + 1;
					break;
				case south:
					current_hori = current_hori + 1;
					break;
				case west:
					current_vert = current_vert - 1;
					break;
				case north:
					current_hori = current_hori - 1;
					break;
			}

			maze[current_hori][current_vert].wall[(nextOrient + 2) % 4] = false;	/*拆下一格子的墙*/
			maze[current_hori][current_vert].visited = true;
			maze[current_hori][current_vert].visitID = visit_num++;

			Push(current_hori, current_vert);
		}
	}
}

void PrintMaze()
{
	int i, j, x, y;
	HWND hwnd;
	HDC hdc;
//	WORD* ptext;
	HPEN pen, OldPen;

	//printf("\n");
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf(" %3d", maze[i][j].visitID);
			//printf("%1d, %2d; ",maze[i][j].visited, maze[i][j].visitID);
		}
		printf("\n");
	}

	x = 1, y = 1;
	//printf("there are some words in console window!\n下面的程序:\n用于在控制台程序中创建windows窗口\n");
	//system("color 3d");
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	//pen = CreatePen(PS_DOT, 1, 1104);

	pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    OldPen= (HPEN)SelectObject(hdc, pen) ;

	//MoveToEx(hdc, x, y, NULL);
	//LineTo(hdc,200,300);

	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(maze[i][j].wall[north])
			{
				MoveToEx(hdc, x + j * 32, y + i * 16, NULL);
				LineTo(hdc, x + j * 32 + 32, y + i * 16);
			}
			if(maze[i][j].wall[west])
			{
				MoveToEx(hdc, x + j * 32, y + i * 16, NULL);
				LineTo(hdc, x + j * 32, y + i * 16 + 16);
			}
		}
	}
	printf("\n");

	MoveToEx(hdc, x + N * 32, y, NULL);
	LineTo(hdc, x + N * 32, y + M * 16);
	LineTo(hdc, x, y + M * 16);

	//Rectangle(hdc,10,30,300,50);
	//TextOut(hdc,10,10,_TEXT("HELLO WORLD\nyesnocancel!"),20);
	ReleaseDC(hwnd,hdc);

	/*printf("\n");
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(maze[i][j].wall[north] && maze[i][j].wall[west])
				printf("┌");
			else if(maze[i][j].wall[north])
				printf("─");
			else if(maze[i][j].wall[west])
				printf("│");
			else
				printf("　");
		}
		printf("\n");
	}*/
}

void PrintPath()
{
	int i, x, y;
	HWND hwnd;
	HDC hdc;
//	WORD* ptext;
	HPEN pen, OldPen;

	x = 20, y = 8;
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);

	pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    OldPen= (HPEN)SelectObject(hdc, pen) ;

	MoveToEx(hdc, x, y, NULL);

	for(i = 0; i <= top; i++)
	{
		LineTo(hdc, x + stack[i].vert * 32, y + stack[i].hori * 16);
	}

	ReleaseDC(hwnd,hdc);
}

void SolveMaze()
{
	int i, j, nextOrient;//visit_num = 0
	int current_hori, current_vert, next_hori, next_vert;

	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
		{
			maze[i][j].visited = false;
			//maze[i][j].visitID = -1;
		}

	ClearStack();

	current_hori = 0;
	current_vert = 0;
	maze[current_hori][current_vert].visited = true;

	Push(current_hori, current_vert);

	do
	{
		printf("[%2d, %2d]->", current_hori, current_vert);

		nextOrient = east;

		while(nextOrient <= north)
		{
			if(maze[current_hori][current_vert].wall[nextOrient])	//此方向有墙
			{
				nextOrient++;
				continue;
			}

			switch(nextOrient)
			{
				case east:					
					next_hori = current_hori;
					next_vert = current_vert + 1;
					break;
				case south:
					next_hori = current_hori + 1;
					next_vert = current_vert;
					break;
				case west:
					next_hori = current_hori;
					next_vert = current_vert - 1;
					break;
				case north:
					next_hori = current_hori - 1;
					next_vert = current_vert;
					break;
			}

			if(!maze[next_hori][next_vert].visited)
			{
				current_hori = next_hori;
				current_vert = next_vert;

				maze[current_hori][current_vert].visited = true;

				Push(current_hori, current_vert);

				break;
			}
			else
				nextOrient++;
		}

		if(nextOrient > north)	//走到死胡同了，需要回退
		{
			if(!StackEmpty())
			{
				Pop();

				current_hori = stack[top].hori;
				current_vert = stack[top].vert;
			}
			else
			{
				printf("Error: Stack is empty.");
				exit(0);
			}
		}
	}while(!(current_hori == M - 1 && current_vert == N - 1));

	printf("[%2d, %2d]\n", current_hori, current_vert);

}

int main()
{
	CreateMaze();

	PrintMaze();

	SolveMaze();

	PrintPath();

	getch();
}

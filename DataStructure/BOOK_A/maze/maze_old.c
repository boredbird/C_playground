#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

#define M 10
#define N 16

enum Boolean {false, true};
enum Orient {east = 0, south, west, north};

typedef struct
{
	int hori;
	int vert;
}Coordinate;

typedef struct cell
{
	Coordinate coordinate;
	enum Boolean wall[4];
	enum Boolean visited;
	int visitID;
}Cell;

Cell maze[M][N];
Coordinate stack[M * N];
int top = -1;	//指向实际的栈顶


void Push(Coordinate coordinate)
{
	stack[++top].hori = coordinate.hori;
	stack[top].vert = coordinate.vert;
}

void Pop()	//Coordinate *coordinate
{
	top--;
//	coordinate->hori = stack[top].hori;
//	coordinate->vert = stack[top--].vert;
}

enum Boolean StackEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

int NextOrient(Coordinate current)
{
	int rnd = (int)(4 * rand() / (RAND_MAX));
	int times = 0;
	Coordinate next;

	while(times < 4)
	{
		switch(rnd)
		{
			case east:
				next.hori = current.hori + 1;
				next.vert = current.vert;
				break;
			case south:
				next.hori = current.hori;
				next.vert = current.vert + 1;
				break;
			case west:
				next.hori = current.hori - 1;
				next.vert = current.vert;
				break;
			case north:
				next.hori = current.hori;
				next.vert = current.vert - 1;
				break;
		}

		if((!maze[next.hori][next.vert].visited) && 
			((next.hori < 0)||(next.hori >= M)||(next.vert < 0)||(next.vert >= N)))
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
	Coordinate current;

	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
		{
			maze[i][j].coordinate.hori = i;
			maze[i][j].coordinate.vert = j;
			maze[i][j].wall[east] = true;
			maze[i][j].wall[south] = true;
			maze[i][j].wall[west] = true;
			maze[i][j].wall[north] = true;
			maze[i][j].visited = false;
			maze[i][j].visitID = -1;
		}

	for(i = 0; i < M * N; i++)
	{
		stack[i].hori = -1;
		stack[i].vert = -1;
	}

	i = 0;
	j = 0;
	maze[i][j].visited = true;
	maze[i][j].visitID = visit_num++;

	Push(maze[i][j].coordinate);

	srand((unsigned)time(NULL));          //初始化随机数
	while(visit_num < M * N)
	{
		current = stack[top];
		nextOrient = NextOrient(current);

		if(nextOrient == -1)
		{
			if(!StackEmpty())
				Pop();
			else
			{
				printf("Error: Stack is empty.");
				exit(0);
			}
			continue;
		}
		else
		{
			switch(nextOrient)
			{
				case east:
					current.hori = current.hori + 1;
					break;
				case south:
					current.vert = current.vert + 1;
					break;
				case west:
					current.hori = current.hori - 1;
					break;
				case north:
					current.vert = current.vert - 1;
					break;
			}

			maze[current.hori][current.vert].visited = true;
			maze[current.hori][current.vert].visitID = visit_num++;

			Push(maze[current.hori][current.vert].coordinate);
		}
	}


}

int main()
{


	printf("hello");
}

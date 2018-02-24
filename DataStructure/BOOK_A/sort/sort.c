#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

#include <windows.h> 

#define NUM_SIZE 20000
#define DATA_FILE "data.dat"

enum Boolean {false, true};

int *num;
LARGE_INTEGER t1, t2, tc; 
double dfMinus, dfFreq, dfLast; 

void TimerStart();
void TimerStop();
void CreateNumbers();
void ReadNumbers();
void WriteNumbers();
void StraightInsertion();
void StraightSelection();
void BubbleSorting();
void QuickSorting();

void TimerStart()
{
	QueryPerformanceCounter(&t1); 
	printf("Begin Time: %u\n", t1.QuadPart);
}

void TimerStop()
{
	QueryPerformanceCounter(&t2); 
	printf("End Time: %u\n", t2.QuadPart); 

	printf("Lasting Time: %u\n", t2.QuadPart - t1.QuadPart); 
	dfMinus = (double)(t2.QuadPart - t1.QuadPart); 
	dfLast = dfMinus / dfFreq;// 获得对应的时间值，单位为秒 
	printf("Lasting Time: %2.15f\n", dfLast); 

	getch();
}

void CreateNumbers()
{
	int i;

	srand((unsigned)time(NULL));          /*初始化随机数*/

	for(i = 0; i < NUM_SIZE; i++)
		num[i] = (int)(NUM_SIZE * rand() / (RAND_MAX));

	printf("Create %d random numbers complete.", NUM_SIZE);

	getch();
}

void ReadNumbers()
{
	FILE *fp;

	if((fp = fopen(DATA_FILE, "rb")) == NULL)
	{
		printf("Can not read data file!\n");
		exit(0);
	}

	if(fread(num, sizeof(int), NUM_SIZE, fp) != NUM_SIZE)
		printf("Data file read error!\n");
	else
		printf("Data file has been read down!\n");

	fclose(fp);

	getch();
}

void WriteNumbers(char *filename)
{
	FILE *fp;

	if((fp = fopen(filename, "wb")) == NULL)
	{
		printf("Can not write data file!\n");
		exit(0);
	}

	if(fwrite(num, sizeof(int), NUM_SIZE, fp) != NUM_SIZE)
		printf("Data file write error!\n");
	else
		printf("Data file has been writed down!\n");

	fclose(fp);

	getch();
}

void StraightInsertion()
{
	int i, j;
	int tmp;

	for(i = 1; i < NUM_SIZE; i++)
	{
		tmp = num[i];
		for(j = i - 1; j >= 0; j--)
		{
			if(num[j] > tmp)
				num[j + 1] = num[j];
			else
				break;
		}
		num[j + 1] = tmp;
	}
}

void swap(int *ia, int *ib)
{
	int tmp;
	tmp = *ia;
	*ia = *ib;
	*ib = tmp;
}

void StraightSelection()
{
	int i, j;
	int min;

	for(i = 0; i < NUM_SIZE; i++)
	{
		min = i;
		for(j = i + 1; j < NUM_SIZE; j++)
		{
			if(num[min] > num[j])
				min = j;
		}
		swap(&num[i], &num[min]);
	}
}

void BubbleSorting()
{
	int i, j;
	enum Boolean swaped;

	for(i = 0; i < NUM_SIZE; i++)
	{
		swaped = false;
		for(j = NUM_SIZE - 1; j > i; j--)
		{
			if(num[j] < num[j - 1])
			{
				swap(&num[j], &num[j - 1]);
				swaped = true;
			}
		}
		if(!swaped)
			break;
	}
}

int Partition(int low, int high)
{
	int tmp, pivotkey;

	tmp = num[low];
	pivotkey = num[low];//(num[low] + num[high] + num[(low + high) / 2]) /3;

	while(low < high)
	{
		while(low < high && num[high] >= pivotkey)
			high--;
		num[low] = num[high];

		while(low < high && num[low] <= pivotkey)
			low++;
		num[high] = num[low];
	}

	num[low] = tmp;
	return low;
}

void QSort(int low, int high)
{
	int pivotkey;

	if(low < high)
	{
		pivotkey = Partition(low, high);
		QSort(low, pivotkey - 1);
		QSort(pivotkey + 1, high);
	}
}

void QuickSorting()
{
	QSort(0, NUM_SIZE - 1);
}

void test()
{
	LARGE_INTEGER t1, t2, tc; 
	double dfMinus, dfFreq, dfTim; 
	QueryPerformanceFrequency(&tc); 
	dfFreq = (double)tc.QuadPart;// 获得计数器的时钟频率 
	printf("Frequency: %u\n", tc.QuadPart); 
	QueryPerformanceCounter(&t1); 
	Sleep(1000); 
	QueryPerformanceCounter(&t2); 
	printf("Begin Time: %u\n", t1.QuadPart); 
	printf("End Time: %u\n", t2.QuadPart); 
	printf("Lasting Time: %u\n", t2.QuadPart - t1.QuadPart); 

	dfMinus = (double)(t2.QuadPart - t1.QuadPart); 
	dfTim = dfMinus / dfFreq;// 获得对应的时间值，单位为秒 
	printf("Lasting Time: %2.15f\n", dfTim); 

	getch();
}

void main()
{
	int choice = 0;

	num = (int *)malloc(sizeof(int) * NUM_SIZE);
	QueryPerformanceFrequency(&tc); 
	dfFreq = (double)tc.QuadPart;// 获得计数器的时钟频率 
//	printf("Frequency: %u\n", tc.QuadPart); 

	do
	{
		system("cls");	//clrscr();

		printf("---------------    Menu    ---------------\n");
		printf("------------------------------------------\n\n");
		printf("1. Create new random numbers;\n");
		printf("2. Read numbers from file;\n");
		printf("3. Write numbers from file;\n");
		printf("4. Sort numbers by straight insertion;\n");
		printf("5. Sort numbers by straight selection;\n");
		printf("6. Sort numbers by bubble sorting;\n");
		printf("7. Sort numbers by quick sorting;\n");
		printf("0. Exit.\n");
		printf("------------------------------------------\n\n");
		printf("Please make a choice:");
		scanf("%d", &choice);

		switch(choice)
	  	{
	    	case 1:
	    		CreateNumbers();
				break;
	     	case 2:
				ReadNumbers();
	    		break;
	     	case 3:
				WriteNumbers(DATA_FILE);
	    		break;
	     	case 4:
				TimerStart();
				StraightInsertion();
				TimerStop();
				WriteNumbers("insertion.dat");
	    		break;
	     	case 5:
				TimerStart();
				StraightSelection();
				TimerStop();
				WriteNumbers("selection.dat");
	    		break;
	     	case 6:
				TimerStart();
				BubbleSorting();
				TimerStop();
				WriteNumbers("bubble.dat");
	    		break;
	     	case 7:
				TimerStart();
				QuickSorting();
				TimerStop();
				WriteNumbers("quick.dat");
	    		break;
			case 0:
				break;
		    default:
	    		printf("Your choice must between 0 to 7!");
		}
	}while(choice != 0);

	free(num);
}

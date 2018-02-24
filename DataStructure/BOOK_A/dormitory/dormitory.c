#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

//定义数据文件为符号常量
#define DATA_FILE "data.dat"
#define MAX_SIZE 100
//定义住宿信息结构体
typedef struct dormitory
{
	char dormID[10];
	char studentID[10];
	char Name[10];
} dormitory;

//定义住宿信息链表节点，包括dormitory型的数据域和指向下一个节点的指针域
typedef struct node_dormitory
{
	dormitory data;
	struct node_dormitory *next;
} node_dormitory, *p_node_dormitory;

//定义住宿信息链表的头指针为全局变量
p_node_dormitory headDormitory;

//定义三个指针数组，分别按照关键字学号、姓名、宿舍号顺序存储住宿信息的节点地址
dormitory *arrayDormID[MAX_SIZE], *arrayStudentID[MAX_SIZE], *arrayName[MAX_SIZE];
int countRecord;

//声明函数
void PrintTitle();
void PrintDormitory(dormitory);
void Read();
void Write();
void View();
void Add();
void Delete();
void Edit();
void Find(int);
void SortWithDormID();
void SortWithStudentID();
void SortWithName();
void SearchWithDormID(char *);
void SearchWithStudentID(char *);
void SearchWithName(char *);

//下列函数是系统主函数，功能是显示系统主菜单，并提供输入选项
void main()
{
	int choice = 0;
	countRecord = 0;
	headDormitory = NULL;

	do
	{
		system("cls");
		printf("---------------    Menu    ---------------\n");
		printf("------------------------------------------\n\n");
		printf("1. Read records from file;\n");
		printf("2. View all records;\n");
		printf("3. Add record;\n");
		printf("4. Edit record;\n");
		printf("5. Delete record;\n");
		printf("6. Find record by name;\n");
		printf("7. Find record by student ID;\n");
		printf("8. Find record by dormitory ID;\n");
		printf("9. Write records to file;\n");
		printf("0. Exit.\n");
		printf("------------------------------------------\n\n");
		printf("Please make a choice:");
		scanf("%d", &choice);

		switch(choice)
	  	{
	    	case 1:
	    		Read();		break;
	     	case 2:
	    		View();  	break;
	     	case 3:
	    		Add(); 		break;
	     	case 4:
	    		Edit(); 	break;
	     	case 5:
	    		Delete(); 	break;
	     	case 6:
	    		Find(1); 	break;
	     	case 7:
	    		Find(2); 	break;
	     	case 8:
	    		Find(3);    break;
			case 9:
				Write();	break;
			case 0:
				break;
		    default:
	    		printf("Your choice must between 0 to 9!");

		}
	}while(choice != 0);
}

//下列函数是输出住宿信息时要调用的函数，为了输出格式便于查看，在输出住宿信息之前输出住宿信息的表头（宿舍号、学号、姓名）
void PrintTitle()
{
	printf("--------------------------------------------\n");
	printf(" Dormitory ID |  Student ID  |     Name     \n");
}

//下列函数是输出节点P所代表的住宿信息的内容（宿舍号、学号、姓名）
void PrintDormitory(dormitory p)
{
	printf("  %10s", p.dormID);
	printf("  |  %10s", p.studentID);
	printf("  |  %10s\n", p.Name);
}

//下列函数是读入文件的函数，把事先保存在数据文件中的住宿信息读入到内存中，创建住宿信息组成的单链表，同时把链表节点的地址保存到住宿号指针数组、学号指针数组和姓名指针数组中

void Read()
{
	FILE *fp;
	p_node_dormitory pNodeDormitory;
	int size;
countRecord = 0;
	fp = fopen(DATA_FILE, "rb");
	fseek(fp, 0, 2);	/*get the size of the file*/
	size = ftell(fp);
	rewind(fp);
	while(size != 0)
	{
		size -= sizeof(struct dormitory);
		pNodeDormitory = (p_node_dormitory)malloc(sizeof(node_dormitory));
		if(fread(&pNodeDormitory->data, sizeof(struct dormitory), 1, fp) != 1)
			exit(0);
		pNodeDormitory->next = headDormitory;
		headDormitory = pNodeDormitory;
		arrayDormID[countRecord] = &headDormitory->data;
		arrayStudentID[countRecord] = &headDormitory->data;
		arrayName[countRecord] = &headDormitory->data;
		countRecord++;
	}
	fclose(fp);
	SortWithDormID();
	SortWithStudentID();
	SortWithName();
	printf("Read %d dormitory records to memory!\n", countRecord);
	getch();
}

//下列函数是写入文件，功能是把住宿信息链表中的内容保存到数据文件中。添加、修改、删除链表的函数完成操作后，只是链表的内容改变了，并没有把修改后的内容写入到数据文件中，只有调用下列函数修改后的内容才写入数据文件中
void Write()
{
	FILE *fp;
	p_node_dormitory pNodeDormitory;
	int count = 0;
	if((fp = fopen(DATA_FILE, "wb+")) == NULL)
	{
		printf("Cann't open file!\n");
		return;
	}
	pNodeDormitory = headDormitory;
	while(pNodeDormitory != NULL)
	{
		if(fwrite(&pNodeDormitory->data, sizeof(dormitory), 1, fp) != 1)
			printf("File write error!\n");
		pNodeDormitory = pNodeDormitory->next;
		count++;
	}
	fclose(fp);
	printf("Write %d dormitory records complete!\n", count);
	getch();
}

//下列函数是显示住宿信息的函数，功能是把目前住宿信息链表中的所有节点内容显示出来。首先按照链表顺序显示链表内容（宿舍号、学号、姓名），然后分别按照分别按照姓名、学号、宿舍号为关键字排序后显示住宿信息（宿舍号、学号、姓名）
void View()
{
	int count;
	p_node_dormitory pNodeDormitory;

pNodeDormitory = headDormitory;

	count = 0;
	PrintTitle();
	while(pNodeDormitory != NULL)
	{
		PrintDormitory(pNodeDormitory->data);
		pNodeDormitory = pNodeDormitory->next;
		count++;
	}

	printf("Totle: %d dormitory records!\n", count);
	printf("\nSort by Name\n");
	PrintTitle();
	for(count = 0; count < countRecord; count++)
	{
		PrintDormitory(*arrayName[count]);
	}
	printf("\nSort by Student ID\n");
	PrintTitle();
	for(count = 0; count < countRecord; count++)
	{
		PrintDormitory(*arrayStudentID[count]);
	}
	printf("\nSort by Dormitory ID\n");
	PrintTitle();
	for(count = 0; count < countRecord; count++)
	{
		PrintDormitory(*arrayDormID[count]);
	}
	getch();
}

//下列函数是添加住宿信息的函数，功能是在住宿信息链表的表头插入一个新的节点，并把该节点的地址分别添加到宿舍号指针数组、姓名指针数组、学号指针数组的末尾，然后把宿舍号指针数组、姓名指针数组、学号指针数组分别排序

void Add()
{
	int i, j, k;
	p_node_dormitory pNodeDormitory;
	pNodeDormitory = (p_node_dormitory)malloc(sizeof(node_dormitory));
	printf("\n Dormitory ID = ");
	scanf("%s", pNodeDormitory->data.dormID);
	printf("\n Student ID = ");
	scanf("%s", pNodeDormitory->data.studentID);
	printf("\n Name = ");
	scanf("%s", pNodeDormitory->data.Name);
	if(headDormitory == NULL)
	{
		headDormitory = pNodeDormitory;
		pNodeDormitory->next = NULL;
	}
	else
	{
		pNodeDormitory->next = headDormitory;
		headDormitory = pNodeDormitory;
	}

	//rearrange array of DormID after add a record
	for(i = 0; i < countRecord; i++)
	{
		if(strcmp(arrayDormID[i]->dormID, &headDormitory->data.dormID) > 0)
			break;
	}
	for(j = countRecord; j > i; j--)
		arrayDormID[j] = arrayDormID[j - 1];
	arrayDormID[i] = &headDormitory->data;

	//rearrange array of StudentID after add a record
	for(i = 0; i < countRecord; i++)
	{
		if(strcmp(arrayStudentID[i]->studentID, &headDormitory->data.studentID) > 0)
			break;
	}
	for(j = countRecord; j > i; j--)
		arrayStudentID[j] = arrayStudentID[j - 1];
	arrayStudentID[i] = &headDormitory->data;

	//rearrange array of Name after add a record
	for(i = 0; i < countRecord; i++)
	{
		if(strcmp(arrayName[i]->Name, &headDormitory->data.Name) > 0)
			break;
	}
	for(j = countRecord; j > i; j--)
		arrayName[j] = arrayName[j - 1];
	arrayName[i] = &headDormitory->data;

	countRecord++;

	PrintTitle();
	PrintDormitory(pNodeDormitory->data);
	getch();
}

//下列函数是删除住宿信息的函数，功能是根据学号查找到要删除的节点，在信息链表中删除该节点，同时把宿舍号指针数组、姓名指针数组、学号指针数组中与该节点相关的指针域置为空
void Delete()
{
	p_node_dormitory pNodeDormitory, p1;
	char sID[10];
	int i, j;

	p1 = headDormitory;

	printf("\nPlease input the student id which you want to delete");
	printf("\nStudent ID = ");
	scanf("%s", sID);

	if(strcmp(p1->data.studentID, sID) == 0)
	{
		headDormitory = p1->next;
		pNodeDormitory = p1;
	}
	else
	{
		pNodeDormitory = p1->next;

		while(pNodeDormitory != NULL)
		{
			if(strcmp(pNodeDormitory->data.studentID, sID) == 0)
			{
				p1->next = pNodeDormitory->next;
				break;
			}
			p1 = pNodeDormitory;
			pNodeDormitory = pNodeDormitory->next;
		}
	}

	if(pNodeDormitory)
	{
		//rearrange array of DormID while delete a record
		for(i = 0; i < countRecord; i++)
			if(arrayDormID[i] == &pNodeDormitory->data)
				break;
		for(j = i; j < countRecord - 1; j++)
			arrayDormID[j] = arrayDormID[j + 1];

		//rearrange array of StudentID while delete a record
		for(i = 0; i < countRecord; i++)
			if(arrayStudentID[i] == &pNodeDormitory->data)
				break;
		for(j = i; j < countRecord - 1; j++)
			arrayStudentID[j] = arrayStudentID[j + 1];

		//rearrange array of Name while delete a record
		for(i = 0; i < countRecord; i++)
			if(arrayName[i] == &pNodeDormitory->data)
				break;
		for(j = i; j < countRecord - 1; j++)
			arrayName[j] = arrayName[j + 1];
		free(pNodeDormitory);
		countRecord--;
		printf("\nOne record has been deteled!");
	}
	else
		printf("\nNo record is matched!");
	getch();
}

//下列函数是修改住宿信息函数，首先根据输入的学号找到要修改的住宿信息节点，然后修改该节点的数据域（宿舍号、学号、姓名）
void Edit()
{
	p_node_dormitory pNodeDormitory;
	char sID[10];
	pNodeDormitory = headDormitory;
	printf("\nPlease input the student id which you want to edit");
	printf("\nStudent ID = ");
	scanf("%s", sID);
	while(pNodeDormitory != NULL)
	{
		if(strcmp(pNodeDormitory->data.studentID, sID) == 0)
		{
			PrintTitle();
			PrintDormitory(pNodeDormitory->data);
			printf("\n New Dormitory ID = ");
			scanf("%s", pNodeDormitory->data.dormID);
			printf("\n New Student ID = ");
			scanf("%s", pNodeDormitory->data.studentID);
			printf("\n New Name = ");
			scanf("%s", pNodeDormitory->data.Name);
			printf("\n\n\n");
			PrintTitle();
			PrintDormitory(pNodeDormitory->data);
			printf("\nOne record has been changed!");
			getch();
			return;
		}
		pNodeDormitory = pNodeDormitory->next;
	}
	printf("\nNo record is matched!");
	getch();
}

//下列函数是排序函数，功能是根据宿舍号进行排序，排序时住宿信息链表并不改变，只是把宿舍指针数组中的内容根据指针所指的节点的宿舍号大小进行排序
void SortWithDormID()
{
	int i, j, k;
	dormitory *tmp;
	for(i = 0; i < countRecord - 1; i++)
	{
		k = i;
		for(j = i + 1; j < countRecord; j++)
			if(strcmp(arrayDormID[j]->dormID, arrayDormID[k]->dormID) < 0)
				k = j;
		if(k != i)
		{
			tmp = arrayDormID[i];
			arrayDormID[i] = arrayDormID[k];
			arrayDormID[k] = tmp;
		}
	}
}
//下列函数是排序函数，功能是根据学号进行排序，排序时住宿信息链表并不改变，只是把学号指针数组中的内容根据指针所指的节点的学号大小进行排序
void SortWithStudentID()
{
	int i, j, k;
	dormitory *tmp;
	for(i = 0; i < countRecord - 1; i++)
	{
		k = i;
		for(j = i + 1; j < countRecord; j++)
			if(strcmp(arrayStudentID[j]->studentID, arrayStudentID[k]->studentID) < 0)
				k = j;
		if(k != i)
		{
			tmp = arrayStudentID[i];
			arrayStudentID[i] = arrayStudentID[k];
			arrayStudentID[k] = tmp;
		}
	}
}

//下列函数是排序函数，功能是根据姓名进行排序，排序时住宿信息链表并不改变，只是把姓名指针数组中的内容根据指针所指的节点的姓名大小进行排序
void SortWithName()
{
	int i, j, k;
	dormitory *tmp;
	for(i = 0; i < countRecord - 1; i++)
	{
		k = i;
		for(j = i + 1; j < countRecord; j++)
			if(strcmp(arrayName[j]->Name, arrayName[k]->Name) < 0)
				k = j;
		if(k != i)
		{
			tmp = arrayName[i];
			arrayName[i] = arrayName[k];
			arrayName[k] = tmp;
		}
	}
}
}

//下列函数是查找函数，进入查找函数后再次进行选择查找的方式
void Find(int type)
{
	char key[10];
	printf("\nPlease input the key which you want to find");
	printf("\nkey = ");
	scanf("%s", key);
	switch(type)
	{
	    case 1:
	    	SearchWithName(key);		break;
	    case 2:
	    	SearchWithStudentID(key); 	break;
	    case 3:
	    	SearchWithDormID(key); 		break;
	}
}

//下列函数是根据姓名查找函数，功能是采用二分查找法在姓名指针数组中查找节点
void SearchWithName(char *key)
{
	int low, high, mid, i, matchCount;	//matchCount为匹配记录数目
	low = 0;
	high = countRecord - 1;
	matchCount = 0;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(strcmp(arrayName[mid]->Name, key) == 0)
		{
			PrintTitle();
			i = mid - 1;
			while(i >= low)
			{
				if(strcmp(arrayName[i]->Name, key) == 0)
					i--;
				else
					break;
			}
			low = i + 1;	//low此时为匹配的第一条记录下标
			i = mid;
			while(i <= high)
			{
				if(strcmp(arrayName[i]->Name, key) == 0)
					i++;
				else
					break;
			}
			high = i - 1;	//high此时为匹配的最后一条记录下标
			matchCount = high - low + 1;
			for(i = low; i <=high; i++)
				PrintDormitory(*arrayName[i]);
			printf("\n%d record has been found!", matchCount);
			getch();
			return;
		}
		else if(strcmp(arrayName[mid]->Name, key) < 0)
			low = mid + 1;
		else
			high = mid - 1;
	}

	printf("\nNo record is matched!");
	getch();
}
//下列函数是根据学号查找函数，功能是采用二分查找法在学号指针数组中查找节点
void SearchWithStudentID(char *key)
{
	int low, high, mid;
	low = 0;
	high = countRecord - 1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(strcmp(arrayStudentID[mid]->studentID, key) == 0)
		{
			PrintTitle();
			PrintDormitory(*arrayStudentID[mid]);
			printf("\nOne record has been found!");
			getch();
			return;
		}
		else if(strcmp(arrayStudentID[mid]->studentID, key) < 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	printf("\nNo record is matched!");
	getch();
}

//下列函数是根据宿舍号查找函数，功能是采用二分查找法在宿舍指针数组中查找节点
void SearchWithDormID(char *key)
{
	int low, high, mid, i, matchCount;	//matchCount为匹配记录数目
	low = 0;
	high = countRecord - 1;
	matchCount = 0;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(strcmp(arrayDormID[mid]->dormID, key) == 0)
		{
			PrintTitle();

			i = mid - 1;
			while(i >= low)
			{
				if(strcmp(arrayDormID[i]->dormID, key) == 0)
					i--;
				else
					break;
			}
			low = i + 1;	//low此时为匹配的第一条记录下标
			i = mid;
			while(i <= high)
			{
				if(strcmp(arrayDormID[i]->dormID, key) == 0)
					i++;
				else
					break;
			}
			high = i - 1;	//high此时为匹配的最后一条记录下标
			matchCount = high - low + 1;

			for(i = low; i <=high; i++)
				PrintDormitory(*arrayDormID[i]);
			printf("\n%d record has been found!", matchCount);
			getch();
			return;
		}
		else if(strcmp(arrayDormID[mid]->dormID, key) < 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	printf("\nNo record is matched!");
	getch();
}

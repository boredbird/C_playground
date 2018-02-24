#include<stdio.h>
#include<stdlib.h>
#define N 100 //顺序表的最大容量
int length=0;  //顺序表的当前元素个数
void CreatList(int[]);
void Display(int[]);
int Search(int[],int);

void main()
{
	int List[N];
	int ch;
	int loc,data,result;
	char exit='N';
	do
	{
		system("CLS");
		printf("\t\t********************************************\n");
		printf("\t\t*  1.创建一个顺序表    .........(1)        *\n");
		printf("\t\t*  2.在顺序表中查找元表.........(2)        *\n");
		printf("\t\t*  3.在顺序表中插入元表.........(3)        *\n");
	    printf("\t\t*  4.在顺序表中删除元表.........(4)        *\n");
		printf("\t\t*  5.退出              .........(5)        *\n");
		printf("\t\t********************************************\n");
		printf("\n请选择操作代码：");
        scanf("%d",&ch);
		getchar();
		switch(ch)
		{
			case  1 :
			    CreatList(List);
				Display(List);
				system("pause");
				break;
			case  2 :
				printf("在顺序表中查找元表\n");
				printf("请输入待查找的元素的值:");
				scanf("%d",&data);
				result=Search(List,data);
				if(result==-1)printf("找不到元素%d\n",data);
				else printf("找到了元素%d,是顺序表中的第%d个元素\n",data,result+1);
				system("pause");
				break;
			case  3 :
				
				printf("在顺序表中插入元表\n");
			
				system("pause");
				break;
			case  4 :
				
				printf("在顺序表中删除元表\n");
			
				system("pause");
				break;
			case  5 :
				printf("\n您是否真的要退出程序(Y/N):");
				exit=getchar();getchar();
				break;
			default:
				printf("\n无效输入，请重新选择...:");
				system("pause");

		}
		
	}while(exit!='y'&&exit!='Y');

}
//创建一个顺序表，依次输入元素值，当输入0时结束
void CreatList(int sl[])
{
	int data;
	length=0;
	printf("请输入一系列整数(当输入0时结束:)");
	do
	{
		if(length>=N)return;
		scanf("%d",&data);
		if(data!=0)
			sl[length++]=data;
		
		
	}while(data!=0);
}
//顺序表的查找
int Search(int sl[],int e)
{
	int i;
	sl[length]=e;//哨兵
	for(i=0;sl[i]!=e;i++);
	if(i<length)return i;//查找到，返回元素的索引号
	else return -1;//查不到
	
}

void Display(int sl[])
{
	int i;
	printf("当前元素序列为：");
	for(i=0;i<length;i++)
	{
		printf("%4d",sl[i]);
	}
	printf("\n");
}

#include<stdio.h>
#include<stdlib.h>
#include"file.h"

void printHead( )
{
	printf("%8s%10s%8s%6s%6s%8s%6s%6s\n","学号","姓名","性别","数学","英语","计算机","总分","名次");
}

void menu( )
{
	printf("******** 1. 显示基本信息 ********\n");
	printf("******** 2. 基本信息管理 ********\n");
	printf("******** 3. 学生成绩管理 ********\n");
	printf("******** 4. 考试成绩统计 ********\n");
    printf("******** 5. 根据条件查询 ********\n");
	printf("******** 0. 退出         ********\n");
	return;
}


void menuBase( )
{
	printf("%%%%%%%% 1. 插入学生记录 %%%%%%%%\n");
	printf("%%%%%%%% 2. 删除学生记录 %%%%%%%%\n");
	printf("%%%%%%%% 3. 修改学生记录 %%%%%%%%\n");
	printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuScore( )
{
	printf("@@@@@@@@ 1. 计算学生总分 @@@@@@@@\n");
	printf("@@@@@@@@ 2. 根据总分排名 @@@@@@@@\n");
	printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}



void menuCount( )
{
	printf("&&&&&&&& 1. 求课程最高分 &&&&&&&&\n");
	printf("&&&&&&&& 2. 求课程最低分 &&&&&&&&\n");
	printf("&&&&&&&& 3. 求课程平均分 &&&&&&&&\n");
	printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()
{
	printf("######## 1. 按学号查询   ########\n");
	printf("######## 2. 按姓名查询   ########\n");
	printf("######## 3. 按名次查询   ########\n");
	printf("######## 0. 返回上层菜单 ########\n");
}


struct node * baseManage(struct node *head)
{  
	int choice;
	Type data;
	struct node *p;     	
	do
	{   menuBase( );
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	
		switch(choice)
		{
			case 1:	 readNode(&data);
					 head=InsertOrder(head,data,1);
					 break;
			case 2:  printf("Input the number deleted\n");
					 scanf("%d",&data.num);
					 head=Delete(head,data); 
					 break;
			case 3:  readNode(&data);
					 p=SearchNode(head,data,1);
					 if (p) p->data=data;
					 else printf("this student is not in\n");
					 break;
			case 0:  break;
		}
	}while(choice);
	return head;
}

void rankCalculate(struct node *head)
{
    struct node *head2=NULL,*p,*q;
	int count=0,current=0;
	for (p=head; p; p=p->next,count++)
		head2=InsertOrder(head2, p->data,2);

	for (p=head2; p; p=p->next)
	{
		current++;
		q=SearchNode(head,p->data,1);  
		(q->data).rank=count-current+1;
	}
}

struct node * scoreManage(struct node *head)
{  
	int choice,i;
	struct node *p;
	do
	{
		menuScore( ); 
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	
		switch(choice)
		{
			case 1:	  for(p = head; p; p = p->next)
					  {
						 (p->data).total=0;
						 for (i=0;i<3;i++)
							(p->data).total+=(p->data).score[i];
					  }
					  break;
			case 2:   rankCalculate(head); 
				      break;		
			case 0:   break;
		}
	}while(choice);
	return head;
}

void highMark(struct node *head,int *high)
{
	struct node *p;
	int i;
	for(p = head; p; p = p->next)
        for (i=0;i<3;i++)
		    if ((p->data).score[i]>high[i])
				high[i]=(p->data).score[i];
	printf("the highest score of each course:\n");
	for (i=0;i<3;i++)
	    printf("%8d",high[i]);
	printf("\n");
}

void lowMark(struct node *head,int *low)
{
	struct node *p;
	int i;
	for(p = head; p; p = p->next)
       for (i=0;i<3;i++)
		   if ((p->data).score[i]<low[i])
				low[i]=(p->data).score[i];
	printf("the lowest score of each course:\n");
	for (i=0;i<3;i++)
		printf("%8d",low[i]);
	printf("\n");
}

void average(struct node *head,double *aver)
{
	struct node *p;
	int i,count=0;
	for(p = head; p; p = p->next)
	{
	   count++;
       for (i=0;i<3;i++)
		   aver[i]+=(p->data).score[i];
	}
	for (i=0;i<3;i++)
		aver[i]/=count;
	printf("the average score of each course:\n");
	for (i=0;i<3;i++)
		printf("%8.2f",aver[i]);
	printf("\n");
}


void countManage(struct node *head)
{
	int choice;
	int high[3]={0,0,0},low[3]={100,100,100};
	double aver[3]={0};	
	do
	{
		menuCount( );
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	  highMark(head,high);	  break;
			case 2:   lowMark(head,low);      break;
			case 3:   average(head,aver);     break;
			case 0:   break;
		}
	}while (choice);
}

struct node * searchManage(struct node *head)
{
    int choice;
	Type data;
	struct node *p;
	do
	{
		menuSearch( );
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	  printf("Input a student\'s num will be searched:\n");
				      scanf("%ld",&data.num);
					  break;
			case 2:   printf("Input a student\'s name will be searched:\n");
				      scanf("%s",&data.name);					  
				      break;   
			case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&data.rank);
					  break;
			case 0:   break;
		}
		if (choice>=1&&choice<=3)
			if (p=SearchNode(head, data,choice))					
			{
			     printHead( );
			     printNode(p->data);
			}
		    else
			     printf("it is not in the list\n");
		
	}while (choice);
	return head;
}


struct node *  runMain(struct node *head,int choice)
{
	switch(choice)
	{
		case 1: printHead( );
                head=printList(head); 
				break;
		case 2: head=baseManage(head);  
			    break;
		case 3: head=scoreManage(head);
				break;
		case 4: countManage(head);
				break;
		case 5: head=searchManage(head);
				break;
        case 0: break;
	}
	return head;
}

int main()
{
	struct node *head=NULL;
    int choice;
	head=readFile(head); 
	if (!head) 
	{
		createFile();
        head=readFile(head); 
	}
	do
	{
	   menu();
	   printf("Please input your choice: ");
	   scanf("%d",&choice);
	   if (choice>=0&&choice<=5)
	      head=runMain(head,choice);
	   else 
		   printf("error input,please input your choice again!\n");
	}while (choice);
	saveFile(head);
    return 0;
}

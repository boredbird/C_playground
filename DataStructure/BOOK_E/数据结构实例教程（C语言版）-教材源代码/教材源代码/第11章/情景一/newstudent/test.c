#include "stdio.h"
#include "string.h"
int i=0;
//新生注册信息的结构体定义
typedef struct
{
	char nam[10];    //姓名
	char sex[4];     //性别  
	char spec[20];   //专业
	char classid[10];//班级
	char phone[15];  //电话号码
    char bedroom[8]; //宿舍号
}student;
student stu[4000];
//信息注册功能
void regis()
{
  printf("请输入学生信息:\n");
  printf("姓名    性别    专业        班级    电话号码    宿舍号\n");
  scanf("%s%s%s%s%s%s",stu[i].nam,stu[i].sex,stu[i].spec,stu[i].classid,stu[i].phone,stu[i].bedroom);
  i++;
}
//打印学生信息
void pri()
{
  int j;
  printf("姓名    性别    专业        班级    电话号码    宿舍号\n");
  for(j=0;j<=i-1;j++)
  {
    printf("--------------------------------------------------------\n");
	printf("%-8s%-8s%-12s%-8s%-12s%-8s\n",stu[j].nam,stu[j].sex,stu[j].spec,stu[j].classid,stu[j].phone,stu[j].bedroom);
  }
    printf("--------------------------------------------------------\n");
}
//按姓名查询
void search_name()
{
    int flag=0,j;
	char nam[10];
	printf("请输入要查询学生姓名:");
	gets(nam);
	printf("姓名    性别    专业        班级    电话号码    宿舍号\n");
	for(j=0;j<=i-1;j++)
	{
		if(strcmp(stu[j].nam,nam)==0)
		{  printf("--------------------------------------------------------\n");
           printf("%-8s%-8s%-12s%-8s%-12s%-8s\n",stu[j].nam,stu[j].sex,stu[j].spec,stu[j].classid,stu[j].phone,stu[j].bedroom);
		   flag=1;
		}
	}
	printf("--------------------------------------------------------\n");
	if(flag==0)
	{
		printf("该校无此学生!\n");
		printf("--------------------------------------------------------\n");
	}
}
//按专业查询
void search_spec()
{
    int flag=0,j,num=0;
	char spec[10];
	printf("请输入要查询专业:");
	gets(spec);
	printf("姓名    性别    专业        班级    电话号码    宿舍号\n");
	for(j=0;j<=i-1;j++)
	{
		if(strcmp(stu[j].spec,spec)==0)
		{  printf("--------------------------------------------------------\n");
           printf("%-8s%-8s%-12s%-8s%-12s%-8s\n",stu[j].nam,stu[j].sex,stu[j].spec,stu[j].classid,stu[j].phone,stu[j].bedroom);
		   flag=1;
		   num++;
		}
	}
	printf("--------------------------------------------------------\n");
	if(flag==0)
	{
		printf("该专业无学生!\n");
		printf("--------------------------------------------------------\n");
	}
	else
		printf("该专业共有%d名学生已报到!\n",num);
}
main()
{
	int choice;
	printf("              大中专院校新生报到信息注册系统\n\n");
	printf("********************************************************************\n");
    printf(" 1.注册学生信息 2.打印学生信息 3.按姓名查询 4.按专业查询 5.退出系统\n");
    printf("********************************************************************\n");
	while(1)
	{ printf("请输入选项:");
	  scanf("%d",&choice);
	  getchar();
	  switch(choice)
	  {
	    case 1:regis();break;
		case 2:pri();break;
		case 3:search_name();break;
		case 4:search_spec();break;
	  }
	  if(choice==5)
		  break;
	}
}
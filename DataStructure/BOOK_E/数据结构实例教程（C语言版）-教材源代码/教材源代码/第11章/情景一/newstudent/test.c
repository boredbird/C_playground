#include "stdio.h"
#include "string.h"
int i=0;
//����ע����Ϣ�Ľṹ�嶨��
typedef struct
{
	char nam[10];    //����
	char sex[4];     //�Ա�  
	char spec[20];   //רҵ
	char classid[10];//�༶
	char phone[15];  //�绰����
    char bedroom[8]; //�����
}student;
student stu[4000];
//��Ϣע�Ṧ��
void regis()
{
  printf("������ѧ����Ϣ:\n");
  printf("����    �Ա�    רҵ        �༶    �绰����    �����\n");
  scanf("%s%s%s%s%s%s",stu[i].nam,stu[i].sex,stu[i].spec,stu[i].classid,stu[i].phone,stu[i].bedroom);
  i++;
}
//��ӡѧ����Ϣ
void pri()
{
  int j;
  printf("����    �Ա�    רҵ        �༶    �绰����    �����\n");
  for(j=0;j<=i-1;j++)
  {
    printf("--------------------------------------------------------\n");
	printf("%-8s%-8s%-12s%-8s%-12s%-8s\n",stu[j].nam,stu[j].sex,stu[j].spec,stu[j].classid,stu[j].phone,stu[j].bedroom);
  }
    printf("--------------------------------------------------------\n");
}
//��������ѯ
void search_name()
{
    int flag=0,j;
	char nam[10];
	printf("������Ҫ��ѯѧ������:");
	gets(nam);
	printf("����    �Ա�    רҵ        �༶    �绰����    �����\n");
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
		printf("��У�޴�ѧ��!\n");
		printf("--------------------------------------------------------\n");
	}
}
//��רҵ��ѯ
void search_spec()
{
    int flag=0,j,num=0;
	char spec[10];
	printf("������Ҫ��ѯרҵ:");
	gets(spec);
	printf("����    �Ա�    רҵ        �༶    �绰����    �����\n");
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
		printf("��רҵ��ѧ��!\n");
		printf("--------------------------------------------------------\n");
	}
	else
		printf("��רҵ����%d��ѧ���ѱ���!\n",num);
}
main()
{
	int choice;
	printf("              ����רԺУ����������Ϣע��ϵͳ\n\n");
	printf("********************************************************************\n");
    printf(" 1.ע��ѧ����Ϣ 2.��ӡѧ����Ϣ 3.��������ѯ 4.��רҵ��ѯ 5.�˳�ϵͳ\n");
    printf("********************************************************************\n");
	while(1)
	{ printf("������ѡ��:");
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
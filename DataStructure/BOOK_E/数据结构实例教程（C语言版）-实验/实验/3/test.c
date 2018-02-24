#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//任务结构体定义
typedef struct node
{
	long task_id;
	char task_nam[20];
	struct node *next;
}taskList;
//创建任务链表
taskList *create()
{
  taskList *head,*last,*p;
  long task_id;
  char task_nam[20];
  p=(taskList *)malloc(sizeof(taskList));//建立头结点
  head=p;
  last=p;//last始终指向最后的结点，方便链接下一个新插入结点
  p->next=NULL;
  printf("请输入任务编号:");
  scanf("%ld",&task_id);
  getchar();
  printf("请输入任务名称:");
  gets(task_nam);
  while(task_id!=0)//输入任务编号为0时循环结束
  {
     p=(taskList *)malloc(sizeof(taskList));//建立数据结点
	 p->task_id=task_id;
	 strcpy(p->task_nam,task_nam);
	 last->next=p;
	 last=p;
	 p->next=NULL;
	 printf("请输入任务编号:");
     scanf("%ld",&task_id);
	 getchar();
     printf("请输入任务名称:");
     gets(task_nam);
  }
  return head;
}
//任务信息输出
void print(taskList *head)
{
	taskList *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%ld,%s->",p->task_id,p->task_nam);
		p=p->next;
	}
	printf("NULL\n");
}
//插入任务操作
void insert(taskList *head,long task_id,char *task_nam)
{
	taskList *h,*p;
    h=(taskList *)malloc(sizeof(taskList));//新开辟要插入结点
	h->task_id=task_id;
	strcpy(h->task_nam,task_nam);
	h->next=NULL;
	p=head;
    while(p->next!=NULL)//寻找最后位置
	{
      p=p->next;
	}
	p->next=h;
}
//删除操作
void delete(taskList *head,char *task_nam)
{
	taskList *p,*q;
    p=head->next;
	while(p->next!=NULL)
	{
      if(strcmp(p->next->task_nam,task_nam)==0)
	    break;
	  p=p->next;
	}
	if(p->next==NULL)
		printf("delete fail!");
	else
	{
	  q=p->next;
	  p->next=q->next;
	  free(q);
	}
}

main()
{
    taskList *head;
	long task_id;
	char task_nam[20];
	head=create();//创建任务链表
	print(head);
	printf("请输入新任务编号:");
    scanf("%ld",&task_id);
	getchar();
    printf("请输入新任务名称:");
    gets(task_nam);
	insert(head,task_id,task_nam);//插入任务信息操作
	print(head);
	printf("请输入要删除任务的名称:");
    gets(task_nam);
    delete(head,task_nam);
	print(head);
}
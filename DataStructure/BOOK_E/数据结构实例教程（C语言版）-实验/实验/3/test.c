#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//����ṹ�嶨��
typedef struct node
{
	long task_id;
	char task_nam[20];
	struct node *next;
}taskList;
//������������
taskList *create()
{
  taskList *head,*last,*p;
  long task_id;
  char task_nam[20];
  p=(taskList *)malloc(sizeof(taskList));//����ͷ���
  head=p;
  last=p;//lastʼ��ָ�����Ľ�㣬����������һ���²�����
  p->next=NULL;
  printf("������������:");
  scanf("%ld",&task_id);
  getchar();
  printf("��������������:");
  gets(task_nam);
  while(task_id!=0)//����������Ϊ0ʱѭ������
  {
     p=(taskList *)malloc(sizeof(taskList));//�������ݽ��
	 p->task_id=task_id;
	 strcpy(p->task_nam,task_nam);
	 last->next=p;
	 last=p;
	 p->next=NULL;
	 printf("������������:");
     scanf("%ld",&task_id);
	 getchar();
     printf("��������������:");
     gets(task_nam);
  }
  return head;
}
//������Ϣ���
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
//�����������
void insert(taskList *head,long task_id,char *task_nam)
{
	taskList *h,*p;
    h=(taskList *)malloc(sizeof(taskList));//�¿���Ҫ������
	h->task_id=task_id;
	strcpy(h->task_nam,task_nam);
	h->next=NULL;
	p=head;
    while(p->next!=NULL)//Ѱ�����λ��
	{
      p=p->next;
	}
	p->next=h;
}
//ɾ������
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
	head=create();//������������
	print(head);
	printf("��������������:");
    scanf("%ld",&task_id);
	getchar();
    printf("����������������:");
    gets(task_nam);
	insert(head,task_id,task_nam);//����������Ϣ����
	print(head);
	printf("������Ҫɾ�����������:");
    gets(task_nam);
    delete(head,task_nam);
	print(head);
}
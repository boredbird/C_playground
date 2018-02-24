#include "stdio.h"
#include "stdlib.h"
//成绩结构体定义
typedef struct node
{
	long id;
	int score;
	struct node *next;
}LinkList;
//创建成绩单链表
LinkList *create()
{
  LinkList *head,*last,*p;
  long id;
  int score;
  p=(LinkList *)malloc(sizeof(LinkList));//建立头结点
  head=p;
  last=p;//last始终指向最后的结点，方便链接下一个新插入结点
  p->next=NULL;
  printf("请输入学号和成绩:\n");
  scanf("%ld,%d",&id,&score);
  while(id!=0)//输入学号为0时循环结束
  {
     p=(LinkList *)malloc(sizeof(LinkList));//建立数据结点
	 p->id=id;
	 p->score=score;
	 last->next=p;
	 last=p;
	 p->next=NULL;
	 scanf("%ld,%d",&id,&score);
  }
  return head;
}
//成绩信息输出
void print(LinkList *head)
{
	LinkList *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%ld,%d->",p->id,p->score);
		p=p->next;
	}
	printf("NULL\n");
}
//插入操作
void insert(LinkList *head,int i,long id,int score)
{
	int j=0;
	LinkList *h,*p;
    h=(LinkList *)malloc(sizeof(LinkList));//新开辟要插入结点
	h->id=id;
	h->score=score;
	h->next=NULL;
	p=head;
    while((j<i-1)&&(p->next!=NULL))//寻找前一个位置
	{
      p=p->next;
	  j=j+1;
	}
	if(j==i-1)
	{
		h->next=p->next;
		p->next=h;
	}
	else 
	   printf("insert fail!\n");
}
//删除操作
void delete(LinkList *head,int i)
{
	int j=0;
	LinkList *p,*q;
    p=head;
	while((j<i-1)&&(p->next!=NULL))
	{
      p=p->next;
	  j=j+1;
	}
	if((p->next!=NULL)&&(j==i-1))
	{
		q=p->next;
		p->next=q->next;
		free(q);
	}
	else
		printf("delete fail!");

}
main()
{
    LinkList *head;
	long id;
	int i,score;
	head=create();//创建学生成绩链表
	print(head);
	printf("请输入要插入的位置、学号和成绩:");
    scanf("%d,%ld,%d",&i,&id,&score);
	insert(head,i,id,score);//插入操作
	print(head);
	printf("请输入要删除信息的位置:");
    scanf("%d",&i);
	delete(head,i);//删除操作
	print(head);



}
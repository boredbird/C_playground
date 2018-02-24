#include "stdio.h"
#include "stdlib.h"
//�ɼ��ṹ�嶨��
typedef struct node
{
	long id;
	int score;
	struct node *next;
}LinkList;
//�����ɼ�������
LinkList *create()
{
  LinkList *head,*last,*p;
  long id;
  int score;
  p=(LinkList *)malloc(sizeof(LinkList));//����ͷ���
  head=p;
  last=p;//lastʼ��ָ�����Ľ�㣬����������һ���²�����
  p->next=NULL;
  printf("������ѧ�źͳɼ�:\n");
  scanf("%ld,%d",&id,&score);
  while(id!=0)//����ѧ��Ϊ0ʱѭ������
  {
     p=(LinkList *)malloc(sizeof(LinkList));//�������ݽ��
	 p->id=id;
	 p->score=score;
	 last->next=p;
	 last=p;
	 p->next=NULL;
	 scanf("%ld,%d",&id,&score);
  }
  return head;
}
//�ɼ���Ϣ���
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
//�������
void insert(LinkList *head,int i,long id,int score)
{
	int j=0;
	LinkList *h,*p;
    h=(LinkList *)malloc(sizeof(LinkList));//�¿���Ҫ������
	h->id=id;
	h->score=score;
	h->next=NULL;
	p=head;
    while((j<i-1)&&(p->next!=NULL))//Ѱ��ǰһ��λ��
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
//ɾ������
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
	head=create();//����ѧ���ɼ�����
	print(head);
	printf("������Ҫ�����λ�á�ѧ�źͳɼ�:");
    scanf("%d,%ld,%d",&i,&id,&score);
	insert(head,i,id,score);//�������
	print(head);
	printf("������Ҫɾ����Ϣ��λ��:");
    scanf("%d",&i);
	delete(head,i);//ɾ������
	print(head);



}
#include "stdio.h"
#include "stdlib.h"
typedef struct node
{   
  char data;    //结点的数据域，DataType为数据类型
  struct node *next;//结点的指针域
}ListNode;
ListNode *CreatList() 
{  
  char ch; 
  ListNode *head=(ListNode *)malloc(sizeof(ListNode));//生成头结点 
  ListNode *s,*r; //工作指针 
  r=head; // 尾指针初值也指向头结点 
  while((ch=getchar())!='\n')
  { 
    s=(ListNode *)malloc(sizeof(ListNode));//生成新结点 
    s->data=ch; //将读入的数据放入新结点的数据域中 
    r->next=s; 
    r=s;
  } 
 r->next=NULL;//终端结点的指针域置空，或空表的头结点指针域置空 
 return head;
} 
ListNode *reverse(ListNode *head) 
{  
  ListNode *p,*s; //工作指针
  ListNode *head1=(ListNode *)malloc(sizeof(ListNode));//生成头结点
  head1->next=NULL;
  p=head->next;
  while(p!=NULL)
  { 
      s=(ListNode *)malloc(sizeof(ListNode));//生成新结点 
      s->data=p->data;
	  s->next=head1->next;
	  head1->next=s;
	  p=p->next;
  } 
 return head1;
}
void print(ListNode *head)
{
	ListNode *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
}
main()
{
    ListNode *head,*head1;
	head=CreatList();
	print(head);
	head1=reverse(head);
	print(head1);
} 






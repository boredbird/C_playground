#include "stdio.h"
#include "stdlib.h"
typedef struct node
{   
  char data;    //����������DataTypeΪ��������
  struct node *next;//����ָ����
}ListNode;
ListNode *CreatList() 
{  
  char ch; 
  ListNode *head=(ListNode *)malloc(sizeof(ListNode));//����ͷ��� 
  ListNode *s,*r; //����ָ�� 
  r=head; // βָ���ֵҲָ��ͷ��� 
  while((ch=getchar())!='\n')
  { 
    s=(ListNode *)malloc(sizeof(ListNode));//�����½�� 
    s->data=ch; //����������ݷ����½����������� 
    r->next=s; 
    r=s;
  } 
 r->next=NULL;//�ն˽���ָ�����ÿգ���ձ��ͷ���ָ�����ÿ� 
 return head;
} 
ListNode *reverse(ListNode *head) 
{  
  ListNode *p,*s; //����ָ��
  ListNode *head1=(ListNode *)malloc(sizeof(ListNode));//����ͷ���
  head1->next=NULL;
  p=head->next;
  while(p!=NULL)
  { 
      s=(ListNode *)malloc(sizeof(ListNode));//�����½�� 
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






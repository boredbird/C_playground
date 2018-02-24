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
ListNode* GetNode(ListNode *head,int i) 
{  
 int j; 
 ListNode *p; 
 p=head;j=0; //��ͷ��㿪ʼɨ�� 
 while(p->next&&j<i)
 { //˳ָ�����ɨ�裬ֱ��p->nextΪNULL��i=jΪֹ
   p=p->next; 
   j++;  
 } 
 if(i==j) 
  return p;      //�ҵ��˵�i����� 
 else return NULL;//��i<0��i>nʱ���Ҳ�����i����� 
} 
//��ֵΪx���½����뵽��ͷ���ĵ�����head�ĵ�i������λ����
void InsertList(ListNode *head,char x,int i) 
{  
  ListNode *p,*s; 
  p=GetNode(head,i-1);     //Ѱ�ҵ�i-1����� 
  if (p==NULL)             //i<1��i>n+1ʱ����λ��i�д� 
    printf("position error"); 
  s=(ListNode *)malloc(sizeof(ListNode)); 
  s->data=x;
  s->next=p->next;
  p->next=s;  
}
void DeleteList(ListNode *head,int i) 
{  //ɾ����ͷ���ĵ�����head�ϵĵ�i����� 
 ListNode *p,*r; 
 p=GetNode(head,i-1);        //�ҵ���i-1����� 
 if (p==NULL||p->next==NULL) //i<1��i>nʱ��ɾ��λ�ô� 
  printf("position error");//�˳��������� 
 r=p->next;      //ʹrָ��ɾ���Ľ��a i 
 p->next=r->next;//��a i�����Ͽ�� 
 free(r);        //�ͷŽ��a i �Ŀռ�
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
    ListNode *head;
	char x;
	int i;
	head=CreatList();
	print(head);
	printf("������Ҫ����ĵ����ݺ�λ��:");
    scanf("%c,%d",&x,&i);
	InsertList(head,x,i);//�������
	print(head);
	printf("������Ҫɾ����Ϣ��λ��:");
    scanf("%d",&i);
	DeleteList(head,i);//ɾ������
	print(head);
} 






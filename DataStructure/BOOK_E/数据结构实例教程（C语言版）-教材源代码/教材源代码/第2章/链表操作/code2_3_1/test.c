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
ListNode* GetNode(ListNode *head,int i) 
{  
 int j; 
 ListNode *p; 
 p=head;j=0; //从头结点开始扫描 
 while(p->next&&j<i)
 { //顺指针向后扫描，直到p->next为NULL或i=j为止
   p=p->next; 
   j++;  
 } 
 if(i==j) 
  return p;      //找到了第i个结点 
 else return NULL;//当i<0或i>n时，找不到第i个结点 
} 
//将值为x的新结点插入到带头结点的单链表head的第i个结点的位置上
void InsertList(ListNode *head,char x,int i) 
{  
  ListNode *p,*s; 
  p=GetNode(head,i-1);     //寻找第i-1个结点 
  if (p==NULL)             //i<1或i>n+1时插入位置i有错 
    printf("position error"); 
  s=(ListNode *)malloc(sizeof(ListNode)); 
  s->data=x;
  s->next=p->next;
  p->next=s;  
}
void DeleteList(ListNode *head,int i) 
{  //删除带头结点的单链表head上的第i个结点 
 ListNode *p,*r; 
 p=GetNode(head,i-1);        //找到第i-1个结点 
 if (p==NULL||p->next==NULL) //i<1或i>n时，删除位置错 
  printf("position error");//退出程序运行 
 r=p->next;      //使r指向被删除的结点a i 
 p->next=r->next;//将a i从链上跨过 
 free(r);        //释放结点a i 的空间
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
	printf("请输入要插入的的数据和位置:");
    scanf("%c,%d",&x,&i);
	InsertList(head,x,i);//插入操作
	print(head);
	printf("请输入要删除信息的位置:");
    scanf("%d",&i);
	DeleteList(head,i);//删除操作
	print(head);
} 






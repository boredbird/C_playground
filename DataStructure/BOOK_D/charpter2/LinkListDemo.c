#include<stdio.h>
#include<stdlib.h>
//线性链表的存储结构
typedef struct  LNode 
{
       int    data;//数据域
       struct  LNode  *next;//指针域
} node;
void Display(node*);
void GreatLink(node*);
void DeleteRepeat(node *head);
void SingleToCycle(node *head);
void DisplayCycle(node *head);
int  Search(node *head, int e);
int listInsert(node *head, int i, int e);
int listDelete(node *head, int i,int *e);
void  DeleteEven(node *head);
void main()
{

	node *Head;
	char exit='N';
	int ch,result,loc;
	int data;
	//构建一个头结点。
	Head=(node *)malloc(sizeof(node));
	if(Head!=NULL)
	{
		Head->next=NULL;
	}
	else return;
	do
	{
		system("CLS");
		printf("\t\t********************************************\n");
		printf("\t\t*  1.创建一个单链表表  ...............(1)  *\n");
		printf("\t\t*  2.在单链表中查找元表...............(2)  *\n");
		printf("\t\t*  3.在单链表中插入元表...............(3)  *\n");
	    printf("\t\t*  4.在单链表中删除元表...............(4)  *\n");
		printf("\t\t*  5.删除单链表中重复元表.............(5)  *\n");
		printf("\t\t*  6.删除单链表中数据值为偶数的元表...(6)  *\n");
		printf("\t\t*  7.把单链表变成带表头结点的循环链表.(7)  *\n");
		printf("\t\t*  8.退出              ...............(8)  *\n");
		printf("\t\t********************************************\n");
		printf("\n请选择操作代码：");
        scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("创建一个单链表表\n");
				GreatLink(Head);
				Display(Head);
				system("pause");
				break;
			case 2:
				printf("在单链表中查找元表\n");
				printf("请输入待查找的元素的值:");
				scanf("%d",&data);
				result=Search(Head,data);
				if(result==0)printf("找不到元素%d\n",data);
				else printf("找到了元素%d,是单链表中的第%d个元素\n",data,result);
				system("pause");
				break;
			case 3:
				printf("在单链表中插入元表\n");
				printf("请输入待插入的元素的位置:");
				scanf("%d",&loc);
				printf("请输入待插入的元素的值:");
				scanf("%d",&data);
				result=listInsert(Head,loc,data);
				if(result==0)printf("插入位置不正确，无法插入!\n");
				else printf("插入元素%d成功!\n",data);
				Display(Head);
				system("pause");
				break;
			case 4:
				
				printf("在单链表中删除元表\n");	
				printf("请输入待删除的元素的位置:");
				scanf("%d",&loc);
				result=listDelete(Head,loc,&data);
				if(result==0)printf("删除位置不正确，无法删除!\n");
				else printf("删除元素%d成功!\n",data);
				Display(Head);
				system("pause");
				break;
			case 5:
			    printf("删除单链表中重复元表\n");
				DeleteRepeat(Head);
                Display(Head);
				system("pause");
				break;
			case 6:
				
				printf("删除单链表中数据值为偶数的元表\n");
			    DeleteEven(Head);
				Display(Head);
				system("pause");
				break;
			case 7:
				printf("把单链表变成带表头结点的循环链表!\n注意,该操作具有破坏性，操作后第2到6步将不能正常执行，请谨慎!\n");
				SingleToCycle(Head);
				DisplayCycle(Head);
				system("pause");
				break;
			case 8:
				getchar();
				printf("\n您是否真的要退出程序(Y/N):");
				exit=getchar();getchar();
				break;
			default:
				printf("\n无效输入，请重新选择...:");				

		}
		
	}while(exit!='y'&&exit!='Y');

}
//显示单链表中所有元素
void Display(node *head)
{
	node *p=head->next;
	printf("\n当前单键表中所有元素为：\n");
	while(p!=NULL)
	{
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");

}
/*从键盘输入一系列整数，当输入值为0时，停止输入，产生单链表*/
void GreatLink(node *head)
{
	int elem;
	node *p,*q;
	printf("请输入一系列整数，当输入0时，结束输入:");
	p=head;
	do
	{
		scanf("%d",&elem);
		if(elem!=0)
		{
			q=malloc(sizeof(node));
			if(q!=NULL)
			{
				q->next=NULL;
				q->data=elem;
				p->next=q;//把结点q放在p之后
				p=q;

			}
		}
	}while(elem!=0);

}
/*将单链表中值重复的结点删除，使所得的结果表中个结点值均不相同*/
void DeleteRepeat(node *head)
{
	int elem;
	node *p,*q,*r;
	p=head->next;
	while(p!=NULL&&p->next!=NULL)
	{
		//查找有没有和p->data相同的元素
		elem=p->data;
		r=p;//r始终指向q结点的前驱
		q=r->next;//为当前结点，用于比较是否和p->data相同
		while(q!=NULL)
		{

			if(q->data==elem)//q->data和p->data相同，删除q指向的结点，并使q指向下一个元素，继续查找
			{
				r->next=q->next;
				free(q);
				q=r->next;
			}
			else//如果q->data和p->data不相同，将q指向下一个元素，继续查找
			{
				r=q;
				q=q->next;
			}			
		}
		
		p=p->next;

	}

}
//把单链表变成循环链表
void SingleToCycle(node *head)
{
	node *p;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=head;//把原来单链表的尾结点的next指针指向头结点。

}
//显示循环链表
void DisplayCycle(node *head)
{
	node *p=head->next;
	printf("\n当前循环链表中所有元素为：\n");
	while(p!=head)
	{
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");

}
//查找 成功--返回位置，失败--0
int  Search(node *head, int e)
{ 
	node *p;
	int i;
	p= head->next;  
    i=1;
	while (p!=NULL&&p->data!=e)
	{
		p = p -> next;
		++i;
	} 
	if(p==NULL)return 0;
	return i;
} 
// 成功--1，失败--0
int listInsert(node *head, int i, int e)
{
  	node *p,*s;
	int j;
	p =head;j = 0;
	while (p && j < i - 1)
	{
     p = p -> next; ++ j;
	}
	if ( !p||j > i - 1) return 0;
	s = (node *) malloc ( sizeof (node)); 
	s -> data = e; 
	s -> next = p -> next; 
	p -> next = s;
	return 1;
}
// 成功--1，失败--0
int listDelete(node *head, int i,int *e)
{ 
	node *p,*q;
	int j;
    p =head; j = 0;
   while (p -> next && j < i-1)
   {
     p = p -> next; ++j; 
   }
   if ( !(p -> next) ||j > i - 1)return 0; // 删除位置不合理
   q = p -> next ; 
   p -> next = q -> next; 
   *e=q->data;
   free(q); // 删除并释放结点
   return 1;
} 
//删除偶数节点
void  DeleteEven(node *head)
{
	node *p,*q;//p为当前结点，q为前驱
	p=head->next;
	q=head;
	while(p!=NULL)
	{
		if(p->data%2==0)//偶数，删除，并把p指向下一个元素。q不变
		{
			q->next=p->next;
			free(p);
			p=q->next;
		}
		else//非偶数，p指向下一个元素，q指向其前驱。
		{
			q=p;
			p=p->next;
			
		}
	}
}


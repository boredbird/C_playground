#include<stdio.h>
#include <stdlib.h>

typedef  int ElemType;   //默认数据类型为int
//线性表的单链表存储结构描述
typedef struct LNode{
	ElemType    data;
	struct  LNode   *next;
}LNode, *LinkList;

typedef struct DuLNode{
	ElemType    data;
	struct  DuLNode   *prior;
	struct  DuLNode   *next;
}DuLNode, *DuLinkList;


//初始化一个单链表，成功返回头指针，失败返回NULL
LNode * LinkListInit()
{
	LNode *L;
	L=(LNode *)malloc(sizeof(LNode));   //申请一个头结点
	if(L==NULL)  return NULL;                   //申请失败
	L->next = NULL;                     //头结点的指针域为空
	return L;
}

//在带头结点的单链表L中第i个位置之前插入元素e，成功返回1，失败返回0
int LinkListInsert(LNode *L, int i, ElemType e)
{
	LNode  *p, *s;
	int  j;
	p=L;   j=0;
	while(p!=NULL&&j<i-1){p=p->next;  ++j;}   //寻找第i-1个结点
	if(p==NULL||j>i-1)return 0;             //插入位置不合法
	s=(LNode *)malloc(sizeof(LNode));           //生成新结点
	s->data=e; 
	s->next=p->next;p->next=s;             //实现插入
	return 1;
}
//在带头结点的单链表L中，删除第i个元素，并由e返回其值，成功返回1，失败返回0
int LinkListDelete(LNode *L, int i, ElemType *e)
{
	LNode *p, *q;
	int j;
	p=L;   j=0;
	while(p->next!=NULL&&j<i-1)          //寻找第i个结点，并令p指向其前趋
	{ 
		p=p->next;++j;
	}  
	if(!(p->next)||j>i-1)  return 0;     //删除位置不合理
	q=p->next; 
	*e=q->data;                       //用e返回被删结点数据域的值
	p->next=q->next;free(q);   //删除并释放结点
	return 1;
}
//在带头结点的单链表L中,查找是否存在与给定值相同的元素，如果存在，则返回位置，否则返回0。
int LinkListLocate(LNode L, ElemType e)
{
	int i=1;
	LNode *p=L.next;//指向第1个元素
	while (p!=NULL&& p->data!=e)
	{
		p=p->next;//指向下一个元素
		i++;
	}
	if(p==NULL)return 0;//没有待查找的元素
	return i;//找到了，返回该元素的位序
}

//在带头结点的单链表L中,返回第i个元素的值，返回0表示错误。
ElemType LinkListGetElem(LNode L,int i)
{

	LNode * p;
	int  j; //j表示当前是第几个元素
	if (i<1) return 0;
	p=L.next;j=1; //指向第1个元素
	while (p!=NULL && j<i)
	{
		j++;p=p->next;//指向下一个元素
	}
	if (p!=NULL) return 0;  
	return p->data;
}

//在带头结点的单链表L中,依次显示每一个元素的值
void PrintList(LNode L)
{
	LNode *p;
	p=L.next;//指第一个元素
	while(p!=NULL)
	{
		printf("%3d",p->data);
		p=p->next;//指向下一个元素
	}
	printf("\n");
}

//已知单链表La和Lb的元素按值非递减排列。
//归并La和Lb得到新的单链表La，La的元素也按值非递减排列
void LinkListMerge(LNode *La, LNode *Lb)
{
	LNode* pa = La->next;//pa指向La中的第1个结点
	LNode* pb = Lb->next; //pb指向Lb中的第1个结点
	LNode* pc=La; //pc表示新形成的链表中的最后一个结点
	while (pa!=NULL && pb!=NULL)
	{ 
		if ( pa->data <= pb->data){
		// 将 *pa 插入Lc表，指针 pa 后移
			pc->next = pa; pc = pa; pa = pa->next; 
		}
		else{// 将 *pb 插入Lc表，指针 pb 后移
			pc->next = pb; pc = pb; pb = pb->next;  
		}
	}
	pc->next = pa!=NULL ? pa : pb; // 插入剩余段
	free(Lb);
}

//将在带头结点的单链表反转
void LinkListInvert(LNode *L)
{ 
	LNode *p,*q;
	p=L->next; //p指向a1结点
	q=p->next; //q指向a2结点
	L->next=NULL; //设当前链表为空
	while(p!=NULL) //*p不是空时循环
	{
		p->next=L->next;
		L->next=p; //结点*p的next逆向
		p=q;
		if(p!=NULL)q=p->next;
	} 
}



int main()
{
	/*LNode *head;
	int x,loc;
	int i=0;
	system("title 第3章 线性表-单链表的表示与实现");
	head=LinkListInit();//初始化一个线性链表
	if(head==NULL)
	{
		printf("初始化链表失败！\n");return 0;
	}
	//依次插入元素，以0做为结束标志
	do{
		printf("请输入第%d个元素的值(结束输入请输0）:",i+1);
		scanf("%d",&x);
		if(x!=0)
		{
			LinkListInsert(head,++i,x);//依次插入元素
		}		
	}while(x!=0);
	printf("当前线性表中的元素依次为：\n");
	PrintList(*head);
	//插入一个元素
	printf("请输入需要插入元素的位置和值：");
	scanf("%d%d",&loc,&x);
	LinkListInsert(head,loc,x);//在第loc个位置插入x
	printf("插入后线性表中的元素依次为：\n");
	PrintList(*head);
	//删除一个元素
	printf("请输入需要删除元素的位置：");
	scanf("%d",&loc);
	LinkListDelete(head,loc,&x);//删除第loc个元素
	printf("删除%d后线性表中的元素依次为：\n",x);
	PrintList(*head);
	//查找元素
	printf("请输入需要查找元素的值：");
	scanf("%d",&x);
	loc=LinkListLocate(*head, x);//查找值为x的元素位置
	if(loc>0)
		printf("找到了！%d是线性表中第%d个元素\n",x,loc);
	else
		printf("在线性表中没有找到值为%d的元素\n",x);*/


	LNode *la,*lb;
	la=LinkListInit();
	lb=LinkListInit();

	LinkListInsert(la,1,23);
	LinkListInsert(la,2,27);
	LinkListInsert(la,3,32);
	LinkListInsert(la,4,39);
	LinkListInsert(la,5,41);

	PrintList(*la);

	LinkListInsert(lb,1,13);
	LinkListInsert(lb,2,28);
	LinkListInsert(lb,3,30);
	LinkListInsert(lb,4,42);
	LinkListInsert(lb,5,47);
	PrintList(*lb);

	LinkListMerge(la,lb);
	PrintList(*la);

	LinkListInvert(la);
	PrintList(*la);
	return 0;
}

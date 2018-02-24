#include<iostream>
using namespace std;

typedef struct LNode
{
	int data;							//结点的数据域
	struct LNode *next;						//结点的指针域
}LNode,*List;							//LinkList为指向结构体LNode的指针类型


void InitList(List &L)						//创建链表
{
	L=new LNode;
	L->next=NULL;
}

void ListInput(List &L,int n)				//链表数据的输入
{
	int i;
	LNode *p,*r;
	cout<<"请输入"<<n<<"个数：\n";
	r=L;
	for(i=0;i<n;i++)
	{
		p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
}

bool LocateElem(List L,int e)				//判断List里有没有e这个元素
{
	LNode *p;
	p=L->next;
	while(p!=NULL)
	{
		if(p->data==e)
			return true;
		p=p->next;
	}
	return false;
}

void ListInsert(List &L,int e)				//将e插入到List中
{
	LNode *p;
	p=new LNode;
	p->data=e;
	p->next=L->next;
	L->next=p;
}

void ListOutput(List L)						//输出List
{
	LNode *p;
	p=L->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void unionList(List &LA,List LB)					//算法2.14 线性表的合并（链表）
{
	//将所有在线性表LB中但不在LA中的数据元素插入到LA中
	int e;
	LNode *p;
	p=LB->next;
	while(p!=NULL)
	{
		e=p->data;
		if(!LocateElem(LA,e))						//LA中不存在和e相同的数据元素，则插入之
			ListInsert(LA,e);
		p=p->next;
	}
}													//unionList

int main()
{
	List LA,LB;
	int n,m;
	InitList(LA);
	InitList(LB);

	cout<<"请输入线性表LA的元素个数：";
	cin>>n;
	ListInput(LA,n);
	cout<<"请输入线性表LB的元素个数：";
	cin>>m;
	ListInput(LB,m);
	
	unionList(LA,LB);

	cout<<"LA和LB合并后的集合为：\n";
	ListOutput(LA);
	return 0;
}
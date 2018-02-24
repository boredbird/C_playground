#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;		//Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType;	 //ElemType 为可定义的数据类型，此设为int类型

typedef struct LNode
{
	ElemType data;							//结点的数据域
	struct LNode *next;						//结点的指针域
}LNode,*LinkList;							//LinkList为指向结构体LNode的指针类型


Status InitList_L(LinkList &L){				//算法2.5 单链表的初始化
	//构造一个空的单链表L
	L=new LNode;							//生成新结点作为头结点，用头指针L指向头结点
	L->next=NULL;							//头结点的指针域置空
	return OK;
}

Status GetElem_L(LinkList L,int i,ElemType &e){		//算法2.6 按序号查找
	//在带头结点的单链表L中查找第i个元素
	int j;
	LNode *p;
	p=L->next;j=1;							//初始化，p指向第一个结点，j为计数器
	while(j<i&&p){							//顺链域向后扫描，直到p指向第i个元素或p为空
		p=p->next;++j;
	}
	if(!p || j>i)	return ERROR;			//第i个元素不存在
	e=p->data;								//取第i个元素
	return OK;
}											//GetElem_L

LNode *LocateElem_L(LinkList L,ElemType e){			//算法2.7 按值查找
	//在带头结点的单链表L中查找值为e的元素
	LNode *p;
	p=L->next;
	while(p&&p->data!=e)
		p=p->next;							//寻找满足条件的结点
	return p;								//返回L中的值为e的数据元素的位置，查找失败返回NULL
}											//LocateElem_L

Status ListInsert_L(LinkList &L,int i,ElemType &e){		//算法2.8 单链表的插入
	//在带头结点的单链表L中第i个位置之前插入元素e
	int j;
	LNode *p,*s;
	p=L;j=0;
	while(p && j<i-1){p=p->next;++j;}		//寻找第i-1个结点
	if(!p||j>i-1)	return ERROR;			//i大于表长+1或者小于1
	s=new LNode;							//生成新结点s
	s->data=e;								//将结点s的数据域置为e
	s->next=p->next;						//将结点s插入L中
	p->next=s;
	return OK;
}											//ListInsert_L

Status ListDelete_L(LinkList &L,int i,ElemType &e){		//算法2.9 单链表的删除
	//在带头结点的单链表L中，删除第i个位置，并由e返回值
	LNode *p,*q;
	int j;
	p=L;j=0;
	while(p->next && j<i-1){p=p->next;++j;}		//寻找第i-1个结点
	if(!(p->next) || j>i-1)		return ERROR;	//i大于表长+1或者小于1
	q=p->next;									//临时保存被删结点的地址以备释放
	p->next=q->next;							//改变删除结点前驱结点的指针域
	e=q->data;									//保存删除结点的数据域
	delete q;									//释放删除结点的空间
	return OK;
}												//ListDelete_L

void CreateList_F(LinkList &L,int n){				//算法2.10 前插法创建单链表
	//逆位序输入n个元素的值，建立到头结点的单链表L
	LNode *p;
	L=new LNode;
	L->next=NULL;								//先建立一个带头结点的空链表
	cout<<"请输入 "<<n<<" 个数:\n";
	for(int i=n;i>0;--i){
		p=new LNode;							//生成新结点
		cin>>p->data;							//输入元素值
		p->next=L->next;L->next=p;				//插入到表头
	}
}												//CreateList_F

void CreateList_L(LinkList &L,int n){				//算法2.11 后插法创建单链表
	//正位序输入n个元素的值，建立到头结点的单链表L
	LNode *r,*p;
	L=new LNode;
	L->next=NULL;								//先建立一个带头结点的空链表
	r=L;										//尾指针r指向头结点
	cout<<"请输入 "<<n<<" 个数:\n";
	for(int i=0;i<n;i++){
		p=new LNode;							//生成新结点
		cin>>p->data;							//输入元素值
		p->next=NULL;r->next=p;					//插入到表尾
		r=p;									//r指向新的尾结点
	}
}												//CreateList_L

int main()
{
	int res,a,b,choose;
	LNode *L,*p;
	cout<<"1. 建立链表\n";
	cout<<"2. 输入数据\n";
	cout<<"3. 按位置查找\n";
	cout<<"4. 按值查找\n";
	cout<<"5. 链表的插入\n";
	cout<<"6. 链表的删除\n";
	cout<<"7. 输出数据\n";
	cout<<"0. 退出\n\n";
	
	choose=-1;
	while(choose!=0)
	{
		cout<<"请选择:";
		cin>>choose;
		switch(choose)
		{
		case 1:					//建立一个单链表
			if(InitList_L(L))
				cout<<"成功建立链表!\n\n";
			break;
		case 2:					//使用后插法创建单链表
			CreateList_L(L,10);
			cout<<"成功创建链表!\n\n";
			break;
		case 3:					//单链表的按序号查找
			cout<<"请输入一个位置用来查找:";
			cin>>a;
			if(GetElem_L(L,a,res))
				cout<<"查找成功!第"<<a<<"个数是："<<res<<"\n\n";
			else
				cout<<"查找失败\n\n";	
			break;
		case 4:					//单链表的按值查找
			cout<<"请输入一个数值用来查找:";
			cin>>b;
			if(LocateElem_L(L,b)!=NULL)
				cout<<"查找成功\n\n";
			else
				cout<<"查找失败! "<<b<<" 没有找到\n\n";
			break;
		case 5:					//单链表的插入
			cout<<"请输入两个数分别代表插入的位置和数值:";
			cin>>a>>b;
			if(ListInsert_L(L,a,b))
   				cout<<"成功将"<<b<<"插在第"<<a<<"个位置\n\n";
			else
				cout<<"插入失败!\n\n";
			break;
		case 6:					//单链表的删除
			cout<<"请输入一个位置用来删除:";
			cin>>a;
			if(ListDelete_L(L,a,res))
				cout<<"删除成功!被删除的数是："<<res<<"\n\n";
			else
				cout<<"删除失败!\n\n";	
			break;
		case 7:					//单链表的输出
			cout<<"现在链表里的数分别是:\n";
			p=L->next;
			while(p)
			{
				cout<<p->data<<" ";
				p=p->next;
			}
			cout<<endl;
			break;
		}
	}
	return 0;
}

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;							//Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType;						//ElemType 为可定义的数据类型，此设为int类型

typedef struct DuLNode
{
	ElemType data;							//结点的数据域
	struct DuLNode *prior;
	struct DuLNode *next;					//结点的指针域
}DuLNode,*DuLinkList;						//DuLinkList为指向结构体DuLNode的指针类型

Status InitDuList_L(DuLinkList &L){
	//构造一个空的双向链表L
	L=new DuLNode;							//生成新结点作为头结点，用头指针L指向头结点
	L->next=NULL;							//头结点的指针域置空
	L->prior=NULL;
	return OK;
}

DuLNode *GetElemP_DuL(DuLinkList L,int i){
	//在带头结点的双向链表L中查找第i个元素，返回结点的地址
	int j;
	DuLNode *p;
	p=L->next;j=1;							//初始化，p指向第一个结点，j为计数器
	while(j<i&&p){							//顺链域向后扫描，直到p指向第i个元素或p为空
		p=p->next;++j;
	}
	if(!p || j>i)	return NULL;			//第i个元素不存在
	return p;
}											//GetElemP_DuL

Status ListInsert_DuL(DuLinkList &L,int i,ElemType e){		//算法2.12 双向链表的插入
	//在带头结点的双向链表L中第i个位置之前插入元素e，i的合法值为1<=i<=表长+1
	DuLNode *s,*p;
	if(!(p=GetElemP_DuL(L,i)))				//在L中确定第i个元素的位置指针p
		return ERROR;						//p为NULL时，第i个元素不存在
	s=new DuLNode;							//生成新结点s
	s->data=e;								//将结点s数据置为e
	s->prior=p->prior;						//将结点s插入L中，需要修改4个指针域
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return OK;
}											//ListInsert_DuL

Status ListDelete_DuL(DuLinkList &L,int i,ElemType &e){		//算法2.13 双向链表的删除
	//删除带头结点的双向链表L中第i个位置之前插入元素e，i的合法值为1<=i<=表长
	DuLNode *p;
	if(!(p=GetElemP_DuL(L,i)))				//在L中确定第i个元素的位置指针p
		return ERROR;						//p为NULL时，第i个元素不存在
	e=p->data;								//保存被删结点的数据域
	p->prior->next=p->next;					//修改被删结点的前驱结点的后继指针
	p->next->prior=p->prior;				//修改被删结点的后继结点的前驱指针
	delete p;								//释放被删结点的空间
	return OK;
}											//ListDelete_DuL


void CreateDuList_L(DuLinkList &L,int n){
	//正位序输入n个元素的值，建立带表头结点的双向链表L，同时建立前驱指针
	DuLNode *r,*p;
	L=new DuLNode;
	L->next=NULL;								//先建立一个带头结点的空链表
	r=L;
	cout<<"请输入"<<n<<"个数\n";										//尾指针r指向头结点
	for(int i=0;i<n;i++){
		p=new DuLNode;							//生成新结点
		cin>>p->data;							//输入元素值
		p->next=NULL;r->next=p;					//插入到表尾
		r=p;									//r指向新的尾结点

		p->prior=L->prior;						//插入到表头
		L->prior=p;
	}
}												//CreateDuList_L

int main()
{
	int res,a,b,choose;
	DuLNode *L,*p;
	cout<<"1. 建立双向链表\n";
	cout<<"2. 输入数据\n";
	cout<<"3. 双向链表的插入\n";
	cout<<"4. 双向链表的删除\n";
	cout<<"5. 输出数据\n";
	cout<<"0. 退出\n\n";
	
	choose=-1;
	while(choose!=0)
	{
		cout<<"请选择:";
		cin>>choose;
		switch(choose)
		{
		case 1:		//建立一个双向链表
			if(InitDuList_L(L))
				cout<<"成功建立双向链表!\n";
			break;
		case 2:		//使用后插法创建双向链表
			CreateDuList_L(L,10);
			break;
		case 3:		//双向链表的插入
			cout<<"请输入两个数分别代表插入的位置和数值:";
			cin>>a>>b;
			if(ListInsert_DuL(L,a,b))
				cout<<"成功在"<<a<<"位置插入"<<b<<endl;
			else
				cout<<"插入失败!\n";
			break;
		case 4:		//双向链表的删除
			cout<<"请输入一个位置用来删除:";
			cin>>a;
			if(ListDelete_DuL(L,a,res))
				cout<<"删除成功!被删除的数是"<<res<<endl;
			else
				cout<<"删除失败!\n";
			break;
		case 5:		//双向链表的输出
			cout<<"现在的链表是:\n";
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
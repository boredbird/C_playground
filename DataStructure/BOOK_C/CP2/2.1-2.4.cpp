#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;		//Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType;	 //ElemType 为可定义的数据类型，此设为int类型

#define MAXSIZE 100			//顺序表可能达到的最大长度

typedef struct{
	ElemType *elem;			//存储空间的基地址
	int length;				//当前长度
}SqList;

Status InitList_Sq(SqList &L){				//算法2.1 顺序表的初始化
	//构造一个空的顺序表L
	L.elem=new ElemType[MAXSIZE];		//为顺序表分配一个大小为MAXSIZE的数组空间
	if(!L.elem)  exit(OVERFLOW);		//存储分配失败
	L.length=0;							//空表长度为0
	return OK;
}

int LocateElem_Sq(SqList L,ElemType e){		//算法2.2 顺序表的查找
	//顺序表的查找
	for(int i=0;i<L.length;i++)
		if(L.elem[i]==e) return i+1;
	return 0;
}

Status ListInsert_Sq(SqList &L,int i,ElemType e){		//算法2.3 顺序表的插入
	//在顺序表L中第i个位置之前插入新的元素e
	//i值的合法范围是1<=i<=L.length+1
	if(i<1 || i>L.length+1)	return ERROR;		//i值不合法
	if(L.length==MAXSIZE)	return ERROR;		//当前存储空间已满
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];					//插入位置及之后的元素后移
	L.elem[i-1]=e;								//将新元素e放入第i个位置
	++L.length;									//表长增1
	return OK;
}

Status ListDelete_Sq(SqList &L,int i,ElemType &e){		//算法2.4 顺序表的删除
	//在顺序表L中删除第i个元素，并用e返回其值
	//i值的合法范围是1<=i<=L.length
	if(i<1 || i>L.length)	return ERROR;		//i值不合法
	e=L.elem[i-1];								//将欲删除的元素保留在e中
	for(int j=i;j<=L.length;j++)				
		L.elem[j-1]=L.elem[j];					//被删除元素之后的元素前移
	--L.length;									//表长减1
	return OK;
}

int main()
{
	SqList L;
	int i,res,temp,a,b,c,e,choose;
	cout<<"1. 建立顺序表\n";
	cout<<"2. 输入数据\n";
	cout<<"3. 查找\n";
	cout<<"4. 插入\n";
	cout<<"5. 删除\n";
	cout<<"6. 输出数据\n";
	cout<<"0. 退出\n\n";

	choose=-1;
	while(choose!=0)
	{
		cout<<"请选择:";
		cin>>choose;
		switch(choose)
		{
		case 1:
			if(InitList_Sq(L))						//创建顺序表
				cout<<"成功建立顺序表\n\n";
			else
				cout<<"顺序表建立失败\n\n";
			break;
		case 2:										//输入10个数
			cout<<"请输入10个数:\n";
			for(i=0;i<10;i++)
				cin>>L.elem[i];
			L.length=10;
			cout<<endl;
			break;
		case 3:										//顺序表的查找
			cout<<"请输入所要查找的数:";
			cin>>e;							//输入e，代表所要查找的数值
			temp=LocateElem_Sq(L,e);
			if(temp!=0)
				cout<<e<<" 是第 "<<temp<<"个数.\n\n";
			else
				cout<<"查找失败！没有这样的数\n\n";
			break;
		case 4:										//顺序表的插入
			cout<<"请输入两个数，分别代表插入的位置和插入数值:";
			cin>>a>>b;				//输入a和b，a代表插入的位置，b代表插入的数值
			if(ListInsert_Sq(L,a,b))
				cout<<"插入成功.\n\n";
			else
				cout<<"I插入失败.\n\n";
			break;
		case 5:										//顺序表的删除
			cout<<"请输入所要插入的数:";
			cin>>c;					//输入c，代表要删除数的位置
			if(ListDelete_Sq(L,c,res))
				cout<<"删除成功.\n被删除的数是:"<<res<<endl<<endl;
			else
				cout<<"删除失败.\n\n";
			break;
		case 6:										//顺序表的输出
			cout<<"当前顺序表为:\n";
			for(i=0;i<L.length;i++)
				cout<<L.elem[i]<<" ";
			cout<<endl<<endl;
			break;
		}
	}
	return 0;
}
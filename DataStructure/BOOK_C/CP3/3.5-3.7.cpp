//链栈的实现
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;
typedef struct SNode{
	SElemType data;
	struct SNode *next;
}SNode,*LinkStack;

//算法3.5　链栈的初始化
Status InitStack (LinkStack &S)
{
      // 构造一个空栈 S，栈顶指针置空
      S=NULL;
      return OK;
}

//算法3.6　链栈的入栈
Status Push(LinkStack &S , SElemType e)
{//在栈顶插入元素e
	SNode *p = new SNode;//生成新结点p
	if(!p)
	{
		return OVERFLOW;
	}
	p->data = e;//将新结点数据域置为e
	p->next = S;//将新结点p插入栈顶
	S = p;//修改栈顶指针
	return OK;
}

//算法3.7　链栈的出栈
Status Pop (LinkStack &S,SElemType & e)
{// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	SNode *p;
		if(!S)
			return ERROR;
		e = S->data;//将栈顶元素赋给e
		p = S;
		S = S->next;//修改栈顶指针
		delete p;//释放原栈顶结点空间
		return OK;
}

int main()
{
	LinkStack s;
	SElemType e;
	cout<<"进栈元素依次为："<<endl;
	if(InitStack(s)==OK)
		for(int j=1;j<=15;j++)
		{
			Push(s,j);
			cout<<j<<"  ";
		}
	cout<<endl<<"依次弹出的栈顶元素为："<<endl;
	while(Pop(s,e) == OK)
	{
		cout<<e<<"  ";
	}
	return 0;
}

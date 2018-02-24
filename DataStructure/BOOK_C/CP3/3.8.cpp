/***链栈实现数制的转换***/
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct SNode{
	int data;
	struct SNode *next;
}SNode,*LinkStack;

Status InitStack(LinkStack &S)
{
	S = NULL;
	return OK;
}
bool StackEmpty(LinkStack S)
{
	if(!S)
		return true;
	return false;
}
Status Push(LinkStack &S,int e)
{
	SNode *p = new SNode;
	if(!p)
	{
		return OVERFLOW;
	}
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
Status Pop(LinkStack &S,int &e)
{
	SNode *p;
	if(!S)
		return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}

//算法3.8　数制的转换(链栈实现)
void conversion ( ) {
   //对于输入的任意一个非负十进制数，打印输出与其等值的八进制数
	LinkStack S;
	int N,e;
	InitStack(S); //构造空栈
	cout<<"输入一个非负十进制数:"<<endl;
	cin>>N;
	while(N)
	{
		Push(S,N%8);
		N=N/8;
	}
	cout<<"与其等值的八进制数是:"<<endl;
	while (!StackEmpty(S))
	{  	//当栈非空时
		Pop(S,e);
		cout<<e;
	}
}
int main()
{
	conversion();
	return 0;
}


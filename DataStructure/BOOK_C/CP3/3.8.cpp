/***��ջʵ�����Ƶ�ת��***/
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

//�㷨3.8�����Ƶ�ת��(��ջʵ��)
void conversion ( ) {
   //�������������һ���Ǹ�ʮ����������ӡ��������ֵ�İ˽�����
	LinkStack S;
	int N,e;
	InitStack(S); //�����ջ
	cout<<"����һ���Ǹ�ʮ������:"<<endl;
	cin>>N;
	while(N)
	{
		Push(S,N%8);
		N=N/8;
	}
	cout<<"�����ֵ�İ˽�������:"<<endl;
	while (!StackEmpty(S))
	{  	//��ջ�ǿ�ʱ
		Pop(S,e);
		cout<<e;
	}
}
int main()
{
	conversion();
	return 0;
}


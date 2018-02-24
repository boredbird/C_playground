/***��ջʵ������ƥ��***/
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char SElemType;
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
Status Push(LinkStack &S,SElemType e)
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
Status Pop(LinkStack &S,SElemType &e)
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
Status GetTop(LinkStack &S,SElemType &e)
{
	if(!S)
		return ERROR;
	e = S->data;
	return OK;
}

//�㷨3.9�����ŵ�ƥ��
Status Matching(LinkStack S)
{
	//������ʽ�����������Ƿ���ȷƥ�䣬���ƥ�䣬�򷵻�true�����򷵻�false��
	//���ʽ�ԡ�#������
	int flag=1;        						//��ǲ��ҽ���Կ���ѭ�������ؽ��
	char c;
	SElemType x;
	cin>>c;            						//�����һ���ַ�
	while(c!='#' &&flag)
	{
	   switch (c){
		   case '[':
		   case '(':  				//���������ţ�����ѹ��ջ
				Push(S,c);
				break;
		   case ')' :     					//���������š�)��������ݵ�ǰջ��Ԫ�ص�ֵ���������
			    GetTop(S,x);
				if (!StackEmpty(S) && x=='(' )	//��ջ�ǿ���ջ��Ԫ���ǡ�(������ƥ��ɹ�
					Pop(S,x);
				else
					flag=0;                 		//��ջ�ջ�ջ��Ԫ�ز��ǡ�(������Ƿ�
				break;
		   case ']' :     //���������š�]��������ݵ�ǰջ��Ԫ�ص�ֵ���������
				GetTop(S,x);
				if (!StackEmpty(S) && x=='[' )	//��ջ��Ԫ���ǡ�[������ƥ��ɹ�
					 Pop(S,x);
				else
					flag=0;                 		//��ջ�ջ�ջ��Ԫ�ز��ǡ�[������Ƿ�
			   break;
	   }//switch
	   cin>>c;       							//����������һ���ַ�
	}//while
	if (StackEmpty(S) &&flag )
	   return 1;
	else
	   return 0;
}//Matching

int main()
{
	LinkStack S;
	cout<<"�������ƥ��ı��ʽ���ԡ�#��������"<<endl;
	int flag = (int)Matching(S);
	if(flag)
		cout<<"����ƥ��ɹ���"<<endl;
	else
		cout<<"����ƥ��ʧ�ܣ�"<<endl;
	return 0;
}

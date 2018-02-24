/***��ջʵ�ֱ��ʽ��ֵ***/
#include<iostream>
using namespace std;

const char oper[7] = {'+','-','*','/','(',')','#'};
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
bool In(char ch)
{//�ж�ch�Ƿ�Ϊ�����
	for(int i = 0;i < 7;i ++)
	{
		if(ch == oper[i])
		{
			return true;
		}
	}
	return false;
}
char Precede(char theta1,char theta2)
{//�ж���������ȼ�
	if((theta1 == '('&&theta2 == ')')||(theta1 == '#'&&theta2 == '#'))
	{
		return '=';
	}
	else if(theta1 == '('||theta1 == '#'||theta2 == '('
		||(theta1 == '+'||theta1 == '-')&&(theta2 == '*'||theta2 == '/'))
	{
		return '<';
	}
	else
		return '>';
}
char Operate(char first,char theta,char second)
{//��������������
	switch(theta)
	{
	case '+':
		return (first - '0')+(second - '0')+ 48;
	case '-':
		return (first - '0')-(second - '0')+ 48;
	case '*':
		return (first - '0')*(second - '0')+ 48;
	case '/':
		return (first - '0')/(second - '0')+ 48;
	}
	return 0;
}

//�㷨3.10�����ʽ��ֵ
char EvaluateExpression()
{
	// �������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ�Ͳ�����ջ��
	// OP Ϊ���������
	LinkStack OPTR,OPND;
	char ch,theta,a,b,x,top;
	InitStack ( OPTR);
	Push (OPTR,'#');
	InitStack ( OPND);
	ch = getchar();
	while (ch != '#' || (GetTop(OPTR,top) ,top!= '#') )
	{
		if (!In(ch))
		{
			Push(OPND, ch);
			ch = getchar();
		} // ch������������ջ
		else
			switch (GetTop(OPTR, top),Precede(top,ch))
			{ //�Ƚ�OPTR��ջ��Ԫ�غ�ch������Ȩ
			case '<': //��ǰ�ַ�chѹ��OPTRջ��������һ�ַ�ch
				Push(OPTR, ch);
				ch = getchar();
				break;
			case '>': //����OPTRջ���������������Ӧ���㣬������������ջ
				Pop(OPTR, theta);
				Pop(OPND, b);
				Pop(OPND, a);
				Push(OPND, Operate(a, theta, b));
				break;
			case '=': //�����Ų�������һ�ַ�
				Pop(OPTR, x);
				ch = getchar();
				break;
			} // switch
	} // while
	GetTop(OPND,ch);
	return ch;
} // EvaluateExpression

int main()
{
	cout<<"������Ҫ����ı��ʽ���������ͽ������0-9�ķ�Χ�ڣ���#��������"<<endl;
	char res = EvaluateExpression();
	cout<<"������Ϊ"<<res<<endl;
	return 0;
}

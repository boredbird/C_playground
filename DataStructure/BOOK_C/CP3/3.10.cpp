/***链栈实现表达式求值***/
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
{//判断ch是否为运算符
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
{//判断运算符优先级
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
{//计算两数运算结果
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

//算法3.10　表达式求值
char EvaluateExpression()
{
	// 算术表达式求值的算符优先算法。设OPTR和OPND分别为运算符栈和操作数栈，
	// OP 为运算符集合
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
		} // ch不是运算符则进栈
		else
			switch (GetTop(OPTR, top),Precede(top,ch))
			{ //比较OPTR的栈顶元素和ch的优先权
			case '<': //当前字符ch压入OPTR栈，读入下一字符ch
				Push(OPTR, ch);
				ch = getchar();
				break;
			case '>': //弹出OPTR栈顶的运算符进行相应运算，并将运算结果入栈
				Pop(OPTR, theta);
				Pop(OPND, b);
				Pop(OPND, a);
				Push(OPND, Operate(a, theta, b));
				break;
			case '=': //脱括号并接收下一字符
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
	cout<<"请输入要计算的表达式（操作数和结果都在0-9的范围内，以#结束）："<<endl;
	char res = EvaluateExpression();
	cout<<"计算结果为"<<res<<endl;
	return 0;
}

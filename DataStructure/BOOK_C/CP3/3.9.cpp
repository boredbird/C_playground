/***链栈实现括号匹配***/
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

//算法3.9　括号的匹配
Status Matching(LinkStack S)
{
	//检验表达式中所含括号是否正确匹配，如果匹配，则返回true，否则返回false。
	//表达式以“#”结束
	int flag=1;        						//标记查找结果以控制循环及返回结果
	char c;
	SElemType x;
	cin>>c;            						//读入第一个字符
	while(c!='#' &&flag)
	{
	   switch (c){
		   case '[':
		   case '(':  				//若是左括号，则将其压入栈
				Push(S,c);
				break;
		   case ')' :     					//若是右括号“)”，则根据当前栈顶元素的值分情况考虑
			    GetTop(S,x);
				if (!StackEmpty(S) && x=='(' )	//若栈非空且栈顶元素是“(”，则匹配成功
					Pop(S,x);
				else
					flag=0;                 		//若栈空或栈顶元素不是“(”，则非法
				break;
		   case ']' :     //若是右括号“]”，则根据当前栈顶元素的值分情况考虑
				GetTop(S,x);
				if (!StackEmpty(S) && x=='[' )	//若栈顶元素是“[”，则匹配成功
					 Pop(S,x);
				else
					flag=0;                 		//若栈空或栈顶元素不是“[”，则非法
			   break;
	   }//switch
	   cin>>c;       							//继续读入下一个字符
	}//while
	if (StackEmpty(S) &&flag )
	   return 1;
	else
	   return 0;
}//Matching

int main()
{
	LinkStack S;
	cout<<"请输入待匹配的表达式，以“#”结束："<<endl;
	int flag = (int)Matching(S);
	if(flag)
		cout<<"括号匹配成功！"<<endl;
	else
		cout<<"括号匹配失败！"<<endl;
	return 0;
}

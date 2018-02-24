#include<stdio.h>
#include <stdlib.h>

#define STACKSIZE 100         //栈的允许的最大长度
typedef int ElemType;         //栈的存储类型
typedef struct  SqStack
{
	ElemType stack[STACKSIZE];   //栈存储空间
	int top;          //栈顶位置
	int stacksize;    //栈表的允许的最大长度
}SqStack;             // 顺序栈

//构造空栈，如果成功，返回1，如果失败，返回0
int InitStack(SqStack *S)
{
	S->top=-1;
	S->stacksize=STACKSIZE;
	return 1;
 }
// 插入元素e为新的栈顶元素 ,如果成功，返回1，如果失败，返回0
int Push (SqStack *S,ElemType e)
{ 
	if(S->top>=S->stacksize-1)return 0;  //栈满	
	S->stack[++S->top]=e;  //先将栈顶位置上移一位，然后插入元素
	return 1;
}
//若栈不空，则删除栈顶元素，用e返回其值；否则返回NULL
ElemType Pop(SqStack *S)
{ 
	ElemType e;
	if(S->top<0)return NULL;  //栈空		
	e=S->stack[S->top--];// 先取出元素值赋值给e，然后将栈顶位置下移一位
	return e; 
 }
//若栈不空，则用e返回栈顶元素；否则返回NULL
ElemType GetTop(SqStack S)
{
	ElemType e;
	if(S.top<0)return NULL;    //栈空
	else
	{
		e=S.stack[S.top]; // 将栈顶元素的值赋值给e
		return e;
	}	
 }
//若栈为空栈，则返回1，否则返回0 
int StackEmpty(SqStack S)//栈非空
{ 
	if(S.top<0)return 1;//栈空
	else return 0;
}
//返回栈的元素个数，即栈的长度
int StackLength(SqStack S)
{ 
	return S.top+1;
}


int main()
{
	int i,n;
	ElemType e;
	SqStack s;//声明一个栈
	InitStack(&s);//初始化栈
	system("title 第3章 顺序栈-top指向栈顶元素的下一个位置");
	Push(&s,3);Push(&s,4);Push(&s,5);Push(&s,6); //依次将3，4，5，6进栈
	e=Pop(&s);printf("出栈的元素为%d\n",e);     //出栈并打印栈顶元素
	Push(&s,7); //7进栈
	e=Pop(&s);  //出栈
	Push(&s,8); //8进栈
	n=StackLength(s); //获取栈的长度
	printf("栈中元素依次出栈:");
	for(i=0;i<n;i++) //栈中元素依次出栈并打印
	{
		e=Pop(&s);
		printf("%3d",e);;
	}	
	printf("\n");
	
	return 0;
}







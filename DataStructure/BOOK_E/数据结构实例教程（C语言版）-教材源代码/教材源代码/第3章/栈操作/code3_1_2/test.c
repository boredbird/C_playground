#include "stdio.h"
#define StackSize 10
typedef struct
{
	int data[StackSize];
    int top;
}SeqStack;
//栈的初始化
void InitStack(SeqStack *S)
{
	S->top=-1;
}
//判断栈是否为空
int StackEmpty(SeqStack *S)
{
	if(S->top==-1)
		return 1;
	else
		return 0;
}
int StackFull(SeqStack *S)
{ 
  return S->top==StackSize-1; // StackSize为栈的空间大小
} 

//进栈操作
void Push(SeqStack *S,char x) 
{
   if(StackFull(S)) 
     printf("Stack overflow"); //上溢，退出运行 
   S->top++;   //栈顶位置变量加1
   S->data[S->top]=x;//将x入栈
} 

//出栈操作
char Pop(SeqStack *S) 
{ 
  char x;
  if(StackEmpty(S)) 
    printf("Stack underflow"); //下溢，退出运行
  x=S->data[S->top];//获取栈顶元素
  S->top--;//栈顶位置减1	
  return x;//栈顶元素返回
} 
//取栈顶元素
char StackTop(SeqStack *S)
{  
    if(StackEmpty(S))    
        printf("Stack is empty");  
    return S->data[S->top];  
} 

main()
{
    SeqStack s;
    InitStack(&s);
    printf("AB进栈!");
	Push(&s,'A');
	Push(&s,'B');
	printf("栈顶元素为%c\n",StackTop(&s));
	printf("执行一次出栈!");
	Pop(&s);
	printf("栈顶元素为%c\n",StackTop(&s));


}
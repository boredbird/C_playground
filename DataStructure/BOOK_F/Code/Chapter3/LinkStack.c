#include<stdio.h>
#include <stdlib.h>

typedef int ElemType;     //栈的存储类型
typedef struct LNode  //链栈结点
{
	ElemType data;      //数据域
	struct Node  *next; //指针域
}LNode;

typedef struct  LinkStack // 链栈
{
	LNode *top;   //栈顶指针	
}LinkStack; 
           
//构造空栈
void InitStack(LinkStack *S)
{
	S->top=NULL;
}
// 插入元素e为新的栈顶元素 ,如果成功，返回1，如果失败，返回0
int Push (LinkStack *S,ElemType e)
{ 
	LNode *p;
	p=(LNode*)malloc(sizeof(LNode));
	if(p==NULL)return NULL;
	p->data=e;
	p->next=S->top;
	S->top=p;
	return 1;
}
//若栈不空，则删除栈顶元素，用e返回其值,并返回1；否则返回0
int Pop(LinkStack *S,ElemType *e)
{ 
	LinkStack *p;
	if(S->top==NULL)return 0;  //栈空
	*e=S->top->data;
	p=S->top;
	S->top=S->top->next;
	free(p);
	return 1; 
 }
//若栈不空，则用e返回栈顶元素,并返回1；否则返回0
int GetTop(LinkStack S,ElemType *e)
{
	if(S.top==NULL)return 0;    //栈空
	else
	{
		*e=S.top->data; // 将栈顶元素的值赋值给e
		return 1;
	}	
 }
//若栈为空栈，则返回1，否则返回0 
int StackEmpty(LinkStack S)//栈非空
{ 
	if(S.top==NULL)return 1;//栈空
	else return 0;
}



int main()
{
	int i,n;
	ElemType e;
	LinkStack s;//声明一个栈
	InitStack(&s);//初始化栈
	system("title 第3章 链栈");
	Push(&s,3);Push(&s,4);Push(&s,5);Push(&s,6); //依次将3，4，5，6进栈
	Pop(&s,&e);printf("出栈的元素为%d\n",e);     //出栈并打印栈顶元素
	Push(&s,7); //7进栈
	Pop(&s,&e);  //出栈
	Push(&s,8); //8进栈

	printf("栈中元素依次出栈:");
	while(s.top!=NULL) //栈中元素依次出栈并打印
	{
		Pop(&s,&e);
		printf("%3d",e);
	}	
	printf("\n");
	
	return 0;
}







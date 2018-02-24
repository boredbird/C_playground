#include "stdio.h"
typedef struct
{
	int data[50];//进制设为整型
    int top;
}seqstack;
//栈的初始化
void initstack(seqstack *s)
{
	s->top=-1;
}
//判断栈是否为空
int empty(seqstack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
//进栈操作
void push(seqstack *s,int x)
{
	if(s->top==49)//栈的下标为0-49
		printf("overflow!\n");
	else
	{
		s->top++;
		s->data[s->top]=x;
	}
}
//出栈操作
char pop(seqstack *s)
{
	int x;
	if(empty(s))
	{
		printf("underflow!\n");
		x='\0';
	}
	else
	{
		x=s->data[s->top];
		s->top--;
	}
	return x;
}
void multibase(int n,int b)
{
	int i;
	seqstack s;
	initstack(&s);
	while(n!=0)
	{
		push(&s,n%b);//进栈
		n=n/b;
	}
	printf("转换后的结果:");
	while(!empty(&s))
	{
		i=pop(&s);//出栈
		printf("%d",i);
	}
	printf("\n");
}
main()
{
	int n,b;
	printf("请输入十进制数:");
	scanf("%d",&n);
	printf("请输入要转换的进制:");
	scanf("%d",&b);
	multibase(n,b);//调用转换函数

}

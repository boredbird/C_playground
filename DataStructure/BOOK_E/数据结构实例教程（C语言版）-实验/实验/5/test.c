#include "stdio.h"
typedef struct
{
	char data[10];//任务设定为char
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
//任务进栈操作
void push(seqstack *s,char task)
{
	if(s->top==9)//栈的下标为0-9
		printf("overflow!\n");
	else
	{
		s->top++;
		s->data[s->top]=task;
	}
}
//任务出栈操作
char pop(seqstack *s)
{
	char x;
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
//任务中断的模拟设计
void task_break()
{
	int task1,task2,task3,task;
	seqstack s;
	initstack(&s);
	printf("请输入要进行的任务:");
	task1=getchar();
	getchar();
	printf("任务%c正在进行.\n",task1);
    printf("请输入要进行的任务:");
	task2=getchar();
	getchar();
	printf("任务%c正在进行.\n",task2);
    printf("任务%c被任务%c中断后进栈.\n",task1,task2);
	push(&s,task1);//task1进栈
	printf("请输入要进行的任务:");
	task3=getchar();
	getchar();
	printf("任务%c正在进行.\n",task3);
    printf("任务%c被任务%c中断后进栈.\n",task2,task3);
	push(&s,task2);//task2进栈
    task=pop(&s);//task2出栈
	printf("任务%c执行完毕,任务%c出栈后开始恢复执行.\n",task3,task);
	task=pop(&s);//task1出栈
	printf("任务%c执行完毕,任务%c出栈后开始恢复执行.\n",task2,task);
}
main()
{
   task_break();
}

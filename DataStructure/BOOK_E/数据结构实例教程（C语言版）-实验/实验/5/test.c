#include "stdio.h"
typedef struct
{
	char data[10];//�����趨Ϊchar
    int top;
}seqstack;
//ջ�ĳ�ʼ��
void initstack(seqstack *s)
{
	s->top=-1;
}
//�ж�ջ�Ƿ�Ϊ��
int empty(seqstack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
//�����ջ����
void push(seqstack *s,char task)
{
	if(s->top==9)//ջ���±�Ϊ0-9
		printf("overflow!\n");
	else
	{
		s->top++;
		s->data[s->top]=task;
	}
}
//�����ջ����
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
//�����жϵ�ģ�����
void task_break()
{
	int task1,task2,task3,task;
	seqstack s;
	initstack(&s);
	printf("������Ҫ���е�����:");
	task1=getchar();
	getchar();
	printf("����%c���ڽ���.\n",task1);
    printf("������Ҫ���е�����:");
	task2=getchar();
	getchar();
	printf("����%c���ڽ���.\n",task2);
    printf("����%c������%c�жϺ��ջ.\n",task1,task2);
	push(&s,task1);//task1��ջ
	printf("������Ҫ���е�����:");
	task3=getchar();
	getchar();
	printf("����%c���ڽ���.\n",task3);
    printf("����%c������%c�жϺ��ջ.\n",task2,task3);
	push(&s,task2);//task2��ջ
    task=pop(&s);//task2��ջ
	printf("����%cִ�����,����%c��ջ��ʼ�ָ�ִ��.\n",task3,task);
	task=pop(&s);//task1��ջ
	printf("����%cִ�����,����%c��ջ��ʼ�ָ�ִ��.\n",task2,task);
}
main()
{
   task_break();
}

#include "stdio.h"
#include "string.h"
typedef struct
{
	int data[50];//������Ϊ����
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
//��ջ����
void push(seqstack *s,int x)
{
	if(s->top==49)//ջ���±�Ϊ0-49
		printf("overflow!\n");
	else
	{
		s->top++;
		s->data[s->top]=x;
	}
}
//��ջ����
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
int ishw(char a[],int n)
{
    int i;
	char b[10];
	seqstack s;
	initstack(&s);
	for(i=0;i<n;i++)
		push(&s,a[i]);
	i=0;
	while(!empty(&s))
	{
		b[i]=pop(&s);
		i++;
	}
	b[i]='\0';
	if(strcmp(a,b)==0)
		return 1;
	else
		return 0;
}

main()
{
	char str[10];
	gets(str);
    if(ishw(str,strlen(str))==1)
		printf("�ǻ��ģ�");
	else
		printf("���ǻ��ģ�");


}

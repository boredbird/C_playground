#include "stdio.h"
#define StackSize 10
typedef struct
{
	int data[StackSize];
    int top;
}SeqStack;
//ջ�ĳ�ʼ��
void InitStack(SeqStack *S)
{
	S->top=-1;
}
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(SeqStack *S)
{
	if(S->top==-1)
		return 1;
	else
		return 0;
}
int StackFull(SeqStack *S)
{ 
  return S->top==StackSize-1; // StackSizeΪջ�Ŀռ��С
} 

//��ջ����
void Push(SeqStack *S,char x) 
{
   if(StackFull(S)) 
     printf("Stack overflow"); //���磬�˳����� 
   S->top++;   //ջ��λ�ñ�����1
   S->data[S->top]=x;//��x��ջ
} 

//��ջ����
char Pop(SeqStack *S) 
{ 
  char x;
  if(StackEmpty(S)) 
    printf("Stack underflow"); //���磬�˳�����
  x=S->data[S->top];//��ȡջ��Ԫ��
  S->top--;//ջ��λ�ü�1	
  return x;//ջ��Ԫ�ط���
} 
//ȡջ��Ԫ��
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
    printf("AB��ջ!");
	Push(&s,'A');
	Push(&s,'B');
	printf("ջ��Ԫ��Ϊ%c\n",StackTop(&s));
	printf("ִ��һ�γ�ջ!");
	Pop(&s);
	printf("ջ��Ԫ��Ϊ%c\n",StackTop(&s));


}
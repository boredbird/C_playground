#include "stdio.h"
#include "stdlib.h"
typedef struct stacknode
{ 
  char data;
  struct stacknode *next; 
}StackNode;
//��ʼ��Ϊջ�� 
void InitStack(StackNode **top) 
{ 
  *top=NULL;
}
//�ж�ջ�Ƿ�Ϊ�� 
int StackEmpty(StackNode *top)
{  
   return top==NULL;
} 
//��ջ����
void Push(StackNode **top, char x) 
{//��Ԫ��x������ջͷ�� 
  StackNode *p=(StackNode *)malloc(sizeof(StackNode)); 
  p->data=x; 
  p->next=*top; 
  *top=p;     
}
//��ջ����
char Pop(StackNode **top) 
{    
	char x; 
	StackNode *p=*top;//����ջ��ָ�� 
	if(StackEmpty(*top)) 
		printf("Stack underflow."); //���� 
	x=(*top)->data; //����ջ��������� 
	*top=p->next; //��ջ����������ժ�� 
	free(p); 
	return x;   
}
//ȡջ��Ԫ�� 
char StackTop(StackNode *top) 
{   
	if(StackEmpty(top)) 
		printf("Stack is empty."); 
	return top->data;
}
main()
{
    StackNode *top;
    InitStack(&top);
    printf("AB��ջ!");
    Push(&top,'A');
	Push(&top,'B');
	printf("ջ��Ԫ��Ϊ%c\n",StackTop(top));
	printf("ִ��һ�γ�ջ!");
	Pop(&top);
	printf("ջ��Ԫ��Ϊ%c\n",StackTop(top));
}





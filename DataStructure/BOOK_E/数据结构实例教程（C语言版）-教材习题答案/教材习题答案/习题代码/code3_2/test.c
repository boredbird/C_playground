#include "stdio.h"
#include "stdlib.h"
typedef struct stacknode
{ 
  char data;
  struct stacknode *next; 
}StackNode; 
                                 
void InitStack(StackNode **top) 
{ 
    
	*top=NULL;
} 
void Push(StackNode **top,char x) 
{//��Ԫ��x������ջͷ�� 
  StackNode *p=(StackNode *)malloc(sizeof(StackNode)); 
  p->data=x; 
  p->next=*top;//���½��*p������ջͷ�� 
  *top=p;     
} 
int sum(StackNode **top)
{
	int n=0;
	while(*top!=NULL)
	{
		n++;
		*top=(*top)->next;
	}
	return n;
}

main()
{
   StackNode *top;
   char ch;
   InitStack(&top);
   while((ch=getchar())!='\n')
   {
     Push(&top,ch);
   }
   printf("%d",sum(&top));
}

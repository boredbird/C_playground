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
{//将元素x插入链栈头部 
  StackNode *p=(StackNode *)malloc(sizeof(StackNode)); 
  p->data=x; 
  p->next=*top;//将新结点*p插入链栈头部 
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

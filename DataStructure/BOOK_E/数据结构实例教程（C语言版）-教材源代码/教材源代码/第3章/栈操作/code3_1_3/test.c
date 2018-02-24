#include "stdio.h"
#include "stdlib.h"
typedef struct stacknode
{ 
  char data;
  struct stacknode *next; 
}StackNode;
//初始化为栈空 
void InitStack(StackNode **top) 
{ 
  *top=NULL;
}
//判断栈是否为空 
int StackEmpty(StackNode *top)
{  
   return top==NULL;
} 
//进栈操作
void Push(StackNode **top, char x) 
{//将元素x插入链栈头部 
  StackNode *p=(StackNode *)malloc(sizeof(StackNode)); 
  p->data=x; 
  p->next=*top; 
  *top=p;     
}
//出栈操作
char Pop(StackNode **top) 
{    
	char x; 
	StackNode *p=*top;//保存栈顶指针 
	if(StackEmpty(*top)) 
		printf("Stack underflow."); //下溢 
	x=(*top)->data; //保存栈顶结点数据 
	*top=p->next; //将栈顶结点从链上摘下 
	free(p); 
	return x;   
}
//取栈顶元素 
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
    printf("AB进栈!");
    Push(&top,'A');
	Push(&top,'B');
	printf("栈顶元素为%c\n",StackTop(top));
	printf("执行一次出栈!");
	Pop(&top);
	printf("栈顶元素为%c\n",StackTop(top));
}





#include "stdio.h"
#include "stdlib.h"
typedef struct Queuenode//链队列结点的类型
{	
  char data;
  struct  Queuenode *next;
}Linknode; 
typedef struct //将头尾指针封装在一起的链队列
{
	Linknode *front,*rear;
}LinkQueue;     

//初始化为空队列
void InitQueue(LinkQueue *Q)
{ 
  Q->front=Q->rear=NULL;
} 
//判断队列是否空
int QueueEmpty(LinkQueue *Q) 
{
  return Q->front==NULL&&Q->rear==NULL;
} 
//进队操作
void EnQueue(LinkQueue *Q,char x) 
{  //将元素x插入链队列尾部 
	Linknode *p=(Linknode *)malloc(sizeof(Linknode));//开辟新结点 
	p->data=x;
	p->next=NULL; 
	if(QueueEmpty(Q)) 
		Q->front=Q->rear=p; //将x插入空队列 
	else
	{ //x插入非空队列的尾 
		Q->rear->next=p; //p链到队尾
		Q->rear=p; //队尾指针指向p
	} 
} 
//出队操作
char DeQueue(LinkQueue *Q) 
{   
	char x;   
	Linknode *p; 
	if(QueueEmpty(Q)) 
		printf("Queue underflow");//下溢 
	p=Q->front; //指向对头结点 
	x=p->data; //保存对头结点的数据 
	Q->front=p->next; //将对头结点从链上摘下 
	if(Q->rear==p)//原队中只有一个结点，删去后队列变空，此时队头指针已为空 
		Q->rear=NULL; 
	free(p); //释放被删队头结点 
	return x; //返回原队头数据
} 
//取队头元素操作
char QueueFront(LinkQueue *Q) 
{  
	if(QueueEmpty(Q)) 
		printf("Queue if empty.");
	return Q->front->data;
} 

main()
{
   LinkQueue queue,*q;
   q=&queue;
   InitQueue(q);
   printf("ABC进队!");
   EnQueue(q,'A');
   EnQueue(q,'B');
   EnQueue(q,'C');
   printf("队头元素为%c\n",QueueFront(q));
   printf("执行一次出队!");
   DeQueue(q);
   printf("队头元素为%c\n",QueueFront(q));
}

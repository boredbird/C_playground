#include "stdio.h"
#define QueueSize 10
typedef struct
{
    char data[QueueSize];//char为数据类型，QueueSize为队列大小
    int front,rear;
}CirQueue;
//初始化为空队列
void InitQueue(CirQueue *q)
{
   q->front=0;
   q->rear=0;
}
//判断队列是否满
int QueueFull(CirQueue *q)
{
   if(q->front==(q->rear+1)%QueueSize) 
      return 1;
   else
	  return 0;
}
//判断队列是否空
int QueueEmpty(CirQueue *q)
{
   if(q->front==q->rear) 
      return 1;
   else 
	  return 0;
}
//进队操作
void EnQueue(CirQueue *q,char x)
{
   if(QueueFull(q)) 
    printf("overflow!"); //队满上溢
   q->data[q->rear]=x;
   q->rear=(q->rear+1)%QueueSize; 
}

//出队操作
char DeQueue(CirQueue *q)
{
    char x;
    if(QueueEmpty(q))
      printf("underflow!");//队空下溢
    x=q->data[q->front];
    q->front =(q->front +1)%QueueSize;
    return x;
}
//取队头元素操作
char QueueFront(CirQueue *q)
{
    char x;
    if(QueueEmpty(q))
       printf("underflow!");//队空下溢
    x=q->data[q->front];
    return x;
}

main()
{
  CirQueue queue,*q;
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


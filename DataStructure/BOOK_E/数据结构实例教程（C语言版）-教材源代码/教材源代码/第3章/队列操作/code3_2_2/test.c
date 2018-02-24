#include "stdio.h"
#define QueueSize 10
typedef struct
{
    char data[QueueSize];//charΪ�������ͣ�QueueSizeΪ���д�С
    int front,rear;
}CirQueue;
//��ʼ��Ϊ�ն���
void InitQueue(CirQueue *q)
{
   q->front=0;
   q->rear=0;
}
//�ж϶����Ƿ�������
int QueueFull(CirQueue *q)
{
   if(q->front==(q->rear+1)%QueueSize) 
      return 1;
   else
	  return 0;
}
//�ж϶����Ƿ�գ���
int QueueEmpty(CirQueue *q)
{
   if(q->front==q->rear) 
      return 1;
   else 
	  return 0;
}
//���Ӳ���
void EnQueue(CirQueue *q,char x)
{
   if(QueueFull(q)) 
    printf("overflow!"); //��������
   q->data[q->rear]=x;
   q->rear=(q->rear+1)%QueueSize; 
}

//���Ӳ�������
char DeQueue(CirQueue *q)
{
    char x;
    if(QueueEmpty(q))
      printf("underflow!");//�ӿ�����
    x=q->data[q->front];
    q->front =(q->front +1)%QueueSize;
    return x;
}
//ȡ��ͷԪ�ز���
char QueueFront(CirQueue *q)
{
    char x;
    if(QueueEmpty(q))
       printf("underflow!");//�ӿ�����
    x=q->data[q->front];
    return x;
}

main()
{
  CirQueue queue,*q;
  q=&queue;
  InitQueue(q);
  printf("ABC����!");
  EnQueue(q,'A');
  EnQueue(q,'B');
  EnQueue(q,'C');
  printf("��ͷԪ��Ϊ%c\n",QueueFront(q));
  printf("ִ��һ�γ���!");
  DeQueue(q);
  printf("��ͷԪ��Ϊ%c\n",QueueFront(q));
}


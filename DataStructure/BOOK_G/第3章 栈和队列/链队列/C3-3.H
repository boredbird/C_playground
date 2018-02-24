// c3-3.h 单链队列－－队列的链式存储结构

#include "C1.h"

#ifndef C3_3_h
#define C3_3_h

typedef int SElemType;


typedef struct QNode
{
	SElemType data;
	QNode *next;
} *QueuePtr;

struct LinkQueue
{
	QueuePtr front,rear; // 队头、队尾指针
};

extern Status InitQueue(LinkQueue &Q);           //构造一个空队列Q
extern Status DestroyQueue(LinkQueue &Q);        //销毁队列Q
extern Status ClearQueue(LinkQueue &Q);          //将Q清为空队列
extern Status QueueEmpty(LinkQueue Q);           //若Q为空队列,则返回TRUE,否则返回FALSE
extern int	  QueueLength(LinkQueue Q);          //求队列的长度
extern SElemType GetHead(LinkQueue Q); //队列不空,则返回队头元素,否则返回ERROR
extern Status EnQueue(LinkQueue &Q,SElemType e); //插入元素e为Q的新的队尾元素
extern SElemType DeQueue(LinkQueue &Q);//队列不空,删除队头元素并返回,否则返回ERROR
extern Status QueueTraverse(LinkQueue Q);//从队头到队尾依次对队列Q中每个元素访问
extern void visit(SElemType e);
#endif
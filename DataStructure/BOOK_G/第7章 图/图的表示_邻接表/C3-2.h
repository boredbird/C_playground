// C3-2.h 单链队列－－队列的链式存储结构

#ifndef C3_2_H
#define C3_2_H

#include "C1.h"

typedef int QElemType;  // 用户指定的队列元素类型

typedef struct QNode
{
    QElemType data;
    QNode     *next;
} *QueuePtr;

struct LinkQueue
{
    QueuePtr front; // 队头指针
    QueuePtr rear;  // 队尾指针
};


// 链队列的基本操作(9个)

void InitQueue(LinkQueue &Q);
// 构造一个空队列Q

void DestroyQueue(LinkQueue &Q);
// 销毁队列Q(无论空否均可)

void ClearQueue(LinkQueue &Q);
// 将Q清为空队列

Status QueueEmpty(LinkQueue Q);
// 若Q为空队列，则返回TRUE，否则返回FALSE

int QueueLength(LinkQueue Q);
// 求队列的长度

Status GetHead(LinkQueue Q, QElemType &e);
// 若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR

void EnQueue(LinkQueue &Q, QElemType e);
// 插入元素e为Q的新的队尾元素

Status DeQueue(LinkQueue &Q, QElemType &e);
// 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR

void QueueTraverse(LinkQueue Q, void(*vi)(QElemType));
// 从队头到队尾依次对队列Q中每个元素调用函数vi()

#endif
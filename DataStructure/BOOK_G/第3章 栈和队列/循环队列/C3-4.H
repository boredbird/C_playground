 // c3-4.h 队列的顺序存储结构(可用于循环队列和非循环队列)

#include "C1.H"

#ifndef C3_4_H
#define C3_4_H

#define MAXQSIZE 10 /* 最大队列长度+1 */

typedef int QElemType;
 
 typedef struct
 {
   QElemType *base; /* 初始化的动态分配存储空间 */
   int front; /* 头指针，若队列不空，指向队列头元素 */
   int rear; /* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
 }SqQueue;

extern  void InitQueue(SqQueue *Q);   // 构造一个空队列Q
extern void DestroyQueue(SqQueue *Q);// 销毁队列Q,Q不再存在
extern  void ClearQueue(SqQueue *Q);  // 将Q清为空队列
extern Status QueueEmpty(SqQueue Q);   // 若队列Q为空队列,则返回TRUE,否则返回FALSE
extern int QueueLength(SqQueue Q);  // 返回Q的元素个数,即队列的长度
extern Status GetHead(SqQueue Q,QElemType *e);// 若队列不空,则用e返回Q的队头元素,否则返回ERROR
extern Status EnQueue(SqQueue *Q,QElemType e);// 插入元素e为Q的新的队尾元素
extern Status DeQueue(SqQueue *Q,QElemType *e);// 若队列不空,则删除Q的队头元素,用e返回其值;否则返回ERROR
extern  void QueueTraverse(SqQueue *Q,void(*vi)(QElemType));// 从队头到队尾依次对队列Q中每个元素访问
extern  void print(QElemType e);
#endif
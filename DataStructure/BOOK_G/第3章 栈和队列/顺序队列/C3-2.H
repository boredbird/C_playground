
#include "C3.H"

#ifndef C3_2_H
#define C3_2_H

 #define QUEUE_INIT_SIZE 10 /* 队列存储空间的初始分配量 */
 #define QUEUE_INCREMENT 2 /* 队列存储空间的分配增量 */

typedef int QElemType; 

 typedef struct
 {
   QElemType *base; /* 初始化的动态分配存储空间 */
   int front; /* 头指针，若队列不空,指向队列头元素 */
   int rear; /* 尾指针，若队列不空,指向队列尾元素的下一个位置 */
   int queuesize; /* 当前分配的存储容量(以sizeof(QElemType)为单位) */
 }SqQueue1;

extern  void InitQueue(SqQueue1 *Q);// 构造一个空队列Q 
extern  void DestroyQueue(SqQueue1 *Q);
extern  void ClearQueue(SqQueue1 *Q);
extern   Status QueueEmpty(SqQueue1 Q);
extern void QueueTraverse(SqQueue1 Q,void(*visit)(QElemType));
extern  Status GetHead(SqQueue1 Q,QElemType *e);
extern  void EnQueue(SqQueue1 *Q,QElemType e);
extern  Status DeQueue(SqQueue1 *Q,QElemType *e);
extern void print(QElemType e);
extern Status QueueLength(SqQueue1 Q);
#endif
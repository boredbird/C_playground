#ifndef C3_3_h
#define C3_3_h

#include "C3.H"

 typedef struct
 {
   int ArrivalTime; /* 到达时刻 */
   int Duration; /* 办理事务所需时间 */
 }QElemType; /* 定义队列的数据元素类型QElemType为结构体类型 */

 typedef struct /* 定义ElemType为结构体类型 */
 {
   int OccurTime; /* 事件发生时刻 */
   int NType; /* 事件类型，Qu表示到达事件，0至Qu-1表示Qu个窗口的离开事件 */
 }Event,ElemType; /* 事件类型，有序链表LinkList的数据元素类型 */

 typedef struct LNode /* 结点类型 */
 {
   ElemType data;
   struct LNode *next;
 }LNode,*Link,*Position;

 typedef struct /* 链表类型 */
 {
   Link head,tail; /* 分别指向线性链表中的头结点和最后一个结点 */
   int len; /* 指示线性链表中数据元素的个数 */
 }LinkList;

typedef LinkList EventList; /* 事件链表指针类型，定义为有序链表 */

 EventList ev; /* 事件表头指针 */
 Event en, et; /* 事件,临时变量 */

 #define Qu 4 /* 窗口数 */
 #define Khjg 5 /* 两相邻到达的客户的时间间隔最大值 */
 #define Blsj 30 /* 每个客户办理业务的时间最大值 */

  typedef struct QNode
 {
   QElemType data;
   struct QNode *next;
 }QNode,*QueuePtr;

 typedef struct
 {
   QueuePtr front,rear; /* 队头、队尾指针 */
 }LinkQueue;

#endif
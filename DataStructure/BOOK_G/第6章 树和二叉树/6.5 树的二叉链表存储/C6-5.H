#ifndef C6_5_H
#define C6_5_H

#include "C6.H"

#define ClearTree InitTree /* 二者操作相同 */

 typedef struct CSNode
 {
   TElemType data;
   struct CSNode *firstchild,*nextsibling;
 }CSNode,*CSTree;

  typedef CSTree QElemType; /* 定义队列元素类型 */

//----------------------------------------------
//需要用到的单链队列－－队列的链式存储结构

 typedef struct QNode
 {
   QElemType data;
   struct QNode *next;
 }QNode,*QueuePtr;

 typedef struct
 {
   QueuePtr front,rear; /* 队头、队尾指针 */
 }LinkQueue;
//----------------------------------------------

 extern void InitTree(CSTree *T);
// 操作结果：构造空树T 

extern void PreOrderTraverse(CSTree T);
//先根遍历孩子—兄弟二叉链表结构的树T 

extern void DestroyTree(CSTree *T);
// 初始条件：树T存在。操作结果：销毁树T 

extern void CreateTree(CSTree *T);
//构造树T 

extern Status TreeEmpty(CSTree T);
// 初始条件：树T存在。操作结果：若T为空树，则返回TURE，否则返回FALSE 
  
extern int TreeDepth(CSTree T);
// 初始条件：树T存在。操作结果：返回T的深度 

extern void visit(TElemType e);
//打印

extern TElemType Root(CSTree T);
// 初始条件：树T存在。操作结果：返回T的根 

extern CSTree Point(CSTree T,TElemType s);
//返回二叉链表(孩子—兄弟)树T中指向元素值为s的结点的指针。另加 

extern Status Assign(CSTree *T,TElemType cur_e,TElemType value);
//初始条件：树T存在，cur_e是树T中结点的值。操作结果：改cur_e为value 

extern TElemType Parent(CSTree T,TElemType cur_e);
//操作结果：若cur_e是T的非根结点，则返回它的双亲，否则函数值为＂空＂

extern TElemType LeftChild(CSTree T,TElemType cur_e);
// 操作结果：若cur_e是T的非叶子结点，则返回它的最左孩子，否则返回＂空＂

extern TElemType RightSibling(CSTree T,TElemType cur_e);
// 操作结果：若cur_e有右兄弟，则返回它的右兄弟，否则返回＂空＂

extern Status InsertChild(CSTree *T,CSTree p,int i,CSTree c);
// 操作结果：插入c为T中p结点的第i棵子树 
  
extern Status DeleteChild(CSTree *T,CSTree p,int i);
// 操作结果：删除T中p所指结点的第i棵子树 
  
extern void PostOrderTraverse(CSTree T);
// 后根遍历孩子—兄弟二叉链表结构的树T 

extern void LevelOrderTraverse(CSTree T);
// 层序遍历孩子—兄弟二叉链表结构的树T 

//-----------------------------------------------------
//需要用到的队列元素
extern void InitQueue(LinkQueue *Q);
//构造一个空队列Q 
 
extern Status QueueEmpty(LinkQueue Q);
//若Q为空队列，则返回TRUE，否则返回FALSE 

extern void EnQueue(LinkQueue *Q,QElemType e);
//插入元素e为Q的新的队尾元素

extern Status DeQueue(LinkQueue *Q,QElemType *e);
// 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR 

//-----------------------------------------------------
#endif
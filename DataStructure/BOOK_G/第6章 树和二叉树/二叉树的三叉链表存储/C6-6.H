 /* c6-6.h 二叉树的三叉链表存储表示 */
#ifndef C6_6_H
#define C6_6_H

#include "C6.H"

#define ClearBiTree DestroyBiTree /* 清空二叉树和销毁二叉树的操作一样 */

 typedef struct BiTPNode
 {
   TElemType data;
   struct BiTPNode *parent,*lchild,*rchild; /* 双亲、左右孩子指针 */
 }BiTPNode,*BiPTree;

 typedef BiPTree QElemType; /* 设队列元素为二叉树的指针类型 */

//-----------------------------------------------
//需要用到的单链队列－－队列的链式存储结构
 /*typedef struct
 {
   int num;
   TElemType name;
 }QElemType; // 定义队列元素类型 */

 typedef struct QNode
 {
   QElemType data;
   struct QNode *next;
 }QNode,*QueuePtr;

 typedef struct
 {
   QueuePtr front,rear; /* 队头、队尾指针 */
 }LinkQueue;
//-----------------------------------------------

extern void InitBiTree(BiPTree *T);
//操作结果：构造空二叉树T 

extern void DestroyBiTree(BiPTree *T);
// 初始条件：二叉树T存在。操作结果：销毁二叉树T 
  
extern void CreateBiTree(BiPTree *T);
// 按先序次序输入二叉树中结点的值(可为字符型或整型，在主程中定义)，
// 构造三叉链表表示的二叉树T 

extern Status BiTreeEmpty(BiPTree T);
// 初始条件：二叉树T存在。操作结果：若T为空二叉树，则返回TRUE，否则FALSE 

extern int BiTreeDepth(BiPTree T);
// 初始条件：二叉树T存在。操作结果：返回T的深度 

extern TElemType Root(BiPTree T);
// 初始条件：二叉树T存在。操作结果：返回T的根 

extern TElemType Value(BiPTree p);
// 初始条件：二叉树T存在，p指向T中某个结点。操作结果：返回p所指结点的值 

 void Assign(BiPTree p,TElemType value);
// 给p所指结点赋值为value */

extern BiPTree Point(BiPTree T,TElemType e);
// 返回二叉树T中指向元素值为e的结点的指针。加 */

extern TElemType Parent(BiPTree T,TElemType e);
// 初始条件：二叉树T存在，e是T中某个结点 
// 操作结果：若e是T的非根结点，则返回它的双亲，否则返回＂空＂

extern TElemType LeftChild(BiPTree T,TElemType e);
// 初始条件：二叉树T存在，e是T中某个结点。操作结果：返回e的左孩子。若e无左孩子,则返回"空" 

extern TElemType RightChild(BiPTree T,TElemType e);
// 初始条件：二叉树T存在，e是T中某个结点。操作结果：返回e的右孩子。若e无右孩子,则返回"空" 

extern TElemType LeftSibling(BiPTree T,TElemType e);
// 初始条件：二叉树T存在，e是T中某个结点 
// 操作结果：返回e的左兄弟。若e是T的左孩子或无左兄弟，则返回＂空＂

extern TElemType RightSibling(BiPTree T,TElemType e);
// 初始条件：二叉树T存在，e是T中某个结点 
// 操作结果：返回e的右兄弟。若e是T的右孩子或无右兄弟，则返回＂空＂


extern Status InsertChild(BiPTree p,int LR,BiPTree c); // 形参T无用 
// 初始条件：二叉树T存在，p指向T中某个结点，LR为0或1，非空二叉树c与T不相交且右子树为空 
// 操作结果：根据LR为0或1，插入c为T中p所指结点的左或右子树。p所指结点 
//           的原有左或右子树则成为c的右子树 

extern Status DeleteChild(BiPTree p,int LR); // 形参T无用 
// 初始条件：二叉树T存在，p指向T中某个结点，LR为0或1 
// 操作结果：根据LR为0或1，删除T中p所指结点的左或右子树 

extern void PreOrderTraverse(BiPTree T);
// 先序递归遍历二叉树T 

extern void InOrderTraverse(BiPTree T);
//中序递归遍历二叉树T 

extern void PostOrderTraverse(BiPTree T);
// 后序递归遍历二叉树T 

extern void LevelOrderTraverse(BiPTree T);
// 层序遍历二叉树T(利用队列) 

extern void visit(BiPTree T);
// 打印

//-----------------------------------------------------
//需要用到的队列元素
extern void InitQueue(LinkQueue *Q);
//构造一个空队列Q 

extern void ClearQueue(LinkQueue *Q);
// 将Q清为空队列 
 
extern Status QueueEmpty(LinkQueue Q);
//若Q为空队列，则返回TRUE，否则返回FALSE 

extern int QueueLength(LinkQueue Q);
//求队列的长度 

extern Status GetHead_Q(LinkQueue Q,QElemType *e) ;
//若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR 

extern void EnQueue(LinkQueue *Q,QElemType e);
//插入元素e为Q的新的队尾元素

extern Status DeQueue(LinkQueue *Q,QElemType *e);
// 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR 

extern void QueueTraverse(LinkQueue Q);
//从队头到队尾依次对队列Q中每个元素调用函数visit()
//-----------------------------------------------------

#endif
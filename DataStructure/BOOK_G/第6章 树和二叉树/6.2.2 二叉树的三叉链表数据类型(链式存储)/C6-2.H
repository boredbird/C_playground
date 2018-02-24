//二叉树数据结构存储结构

#include "C6.H"

#ifndef C6_2_H
#define C6_2_H

 typedef struct BiTPNode
 {
   TElemType data;
   struct BiTPNode *parent,*lchild,*rchild; /* 双亲、左右孩子指针 */
 }BiTPNode,*BiPTree;

//需要使用到的链队列
typedef BiPTree QElemType; /* 设队列元素为二叉树的指针类型 */

typedef struct QNode
{
	QElemType	data;
	QNode		*next;
} *QueuePtr;
 
struct LinkQueue
{
	QueuePtr front, rear; 
};

//*************************
//二叉树抽象数据类型算法实现
extern   void InitBiTree(BiPTree *T);
extern  void DestroyBiTree(BiPTree *T);
extern  void CreateBiTree(BiPTree *T);
extern  Status BiTreeEmpty(BiPTree T);
extern  int BiTreeDepth(BiPTree T);
extern  TElemType Root(BiPTree T);
extern  TElemType Value(BiPTree p);
extern  BiPTree Point(BiPTree T,TElemType e);
extern  TElemType Parent(BiPTree T,TElemType e);
extern  TElemType LeftChild(BiPTree T,TElemType e);
extern  TElemType RightChild(BiPTree T,TElemType e);
extern  TElemType LeftSibling(BiPTree T,TElemType e);
extern  TElemType RightSibling(BiPTree T,TElemType e);
extern  Status InsertChild(BiPTree p,int LR,BiPTree c);
extern  Status DeleteChild(BiPTree p,int LR);
extern  void PreOrderTraverse(BiPTree T);
extern  void Assign(BiPTree p,TElemType value);
extern  void InOrderTraverse(BiPTree T);
extern  void PostOrderTraverse(BiPTree T);
extern  void LevelOrderTraverse(BiPTree T);
extern  void Visit(BiPTree T);

//*************************************
//下列为二叉树操作所要调用的队列函数
extern Status InitQueue(LinkQueue &Q);
    // 构造一个空队列Q
extern Status DestroyQueue(LinkQueue &Q);
    // 销毁队列Q(无论空否均可)
extern Status	QueueEmpty(LinkQueue Q);
	// 若Q为空队列,则返回TRUE,否则返回FALSE
extern Status EnQueue(LinkQueue &Q,QElemType e);
	// 插入元素e为Q的新的队尾元素
extern Status DeQueue(LinkQueue &Q,QElemType &e);
    // 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR

#endif
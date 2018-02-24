 /* c6-1.h 二叉树的顺序存储表示 */
#ifndef C6_1_H
#define C6_1_H

#include "C6.H"

 #define MAX_TREE_SIZE 100 /* 二叉树的最大结点数 */
 typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0号单元存储根结点 */
 typedef int QElemType; 

typedef struct
 {
   int level,order; /* 结点的层,本层序号(按满二叉树计算) */
 }position;

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
#define ClearBiTree InitBiTree /* 在顺序存储结构中，两函数完全一样 */
#define DestroyBiTree InitBiTree /* 在顺序存储结构中，两函数完全一样 */

extern void InitBiTree(SqBiTree T);
    //初始化二叉树
extern Status DeleteChild(SqBiTree T,position p,int LR);
    //删除二叉树(条件：二叉树存在)
extern void CreateBiTree(SqBiTree T);
    //按先序序列生成二叉树
extern void ClearBiTree(SqBiTree T);
    //清空二叉树(条件：二叉树存在)
extern Status BiTreeEmpty(SqBiTree T);                    
    //判定二叉树是否为空
extern int  BiTreeDepth(SqBiTree T);                   	
    //返回二叉树的深度
extern TElemType Root(SqBiTree T);
    //求二叉树的根
extern TElemType Value(SqBiTree T,position e);
    //求给定节点的值
extern  Status Assign(SqBiTree T,position e,TElemType value);
    //为给定节点赋值
extern TElemType Parent(SqBiTree T,TElemType node);
    //求值为node的节点的双亲节点,若无则返回空
extern TElemType LeftChild(SqBiTree T,TElemType e);
    //求值为node的节点的左孩子,若无则返回空
extern TElemType RightChild(SqBiTree T,TElemType node);
    //求值为node的节点的右孩子,若无则返回空
extern TElemType LeftSibling(SqBiTree T, TElemType e);
    //返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂
extern TElemType RightSibling(SqBiTree T, TElemType e);
    //返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂
extern void InsertChild(SqBiTree T,TElemType p,int LR,SqBiTree c);
    //根据LR为0或1,插入c为T中p所指结点的左或右子树。p所指结点的原有左或右子树则成为c的右子树
extern Status DeleteChild(SqBiTree p, int LR);
    //根据LR为0或1,删除T中p所指结点的左或右子树
extern Status Visit(TElemType e);
    //访问节点并输出
extern void PreOrderTraverse(SqBiTree T);
    //先序递归遍历T
extern void InOrderTraverse(SqBiTree T);
    //中序递归遍历T
extern void PostOrderTraverse(SqBiTree T);
    //后序递归遍历T
extern void LevelOrderTraverse(SqBiTree T);
    // 层序递归遍历T(利用队列,需要预先编辑队列算法)
extern void Print(SqBiTree T);
    // 层序递归遍历T(利用队列,需要预先编辑队列算法),并分层输出

//*************************************
//下列为层次遍历二叉树所要调用的队列函数
extern Status InitQueue(LinkQueue &Q);
    // 构造一个空队列Q
extern Status DestroyQueue(LinkQueue &Q);
    // 销毁队列Q(无论空否均可)
extern Status QueueEmpty(LinkQueue Q);
	// 若Q为空队列,则返回TRUE,否则返回FALSE
extern Status EnQueue(LinkQueue &Q,QElemType e);
	// 插入元素e为Q的新的队尾元素
extern Status DeQueue(LinkQueue &Q,QElemType &e);
    // 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR
#endif
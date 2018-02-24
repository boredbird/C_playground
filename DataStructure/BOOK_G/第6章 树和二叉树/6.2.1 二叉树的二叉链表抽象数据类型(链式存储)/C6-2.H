//二叉树数据结构存储结构

#include "C6.H"

#ifndef C6_2_H
#define C6_2_H

typedef struct BiTNode{
TElemType data;
struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef BiTree QElemType;

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

extern Status InitBiTree(BiTree &T);
    //初始化二叉树
extern BiTree Point(BiTree T,TElemType s);
//返回s节点所指向的节点的指针
extern void DeleteBiTree(BiTree *T);
    //删除二叉树(条件：二叉树存在)
extern Status CreateBiTree(BiTree *T);	
    //按先序序列生成二叉树
extern void ClearBiTree(BiTree T);                   
    //清空二叉树(条件：二叉树存在)
extern Status BiTreeEmpty(BiTree T);                    
    //判定二叉树是否为空
extern int  BiTreeDepth(BiTree T);                   	
    //返回二叉树的深度
extern TElemType Root(BiTree T);
    //求二叉树的根
extern TElemType Value(BiTNode node);
    //求给定节点的值
extern void  Assign(BiTree T,TElemType value);
    //为给定节点赋值
extern TElemType Parent(BiTree T,TElemType node);
    //求值为node的节点的双亲节点,若无则返回空
extern TElemType LeftChild(BiTree T,TElemType e);
    //求值为node的节点的左孩子,若无则返回空
extern TElemType RightChild(BiTree T,TElemType node);
    //求值为node的节点的右孩子,若无则返回空
extern TElemType LeftSibling(BiTree T, TElemType e);
    //返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂
extern TElemType RightSibling(BiTree T, TElemType e);
    //返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂
extern Status InsertChild(BiTree p, int LR, BiTree c);
    //根据LR为0或1,插入c为T中p所指结点的左或右子树。p所指结点的原有左或右子树则成为c的右子树
extern Status DeleteChild(BiTree p, int LR);
    //根据LR为0或1,删除T中p所指结点的左或右子树
extern Status Visit(TElemType e);
    //访问节点并输出
extern void PreOrderTraverse(BiTree T);
    //先序递归遍历T
extern void InOrderTraverse(BiTree T);
    //中序递归遍历T
extern void PostOrderTraverse(BiTree T);
    //后序递归遍历T
extern void LevelOrderTraverse(BiTree T);
    // 层序递归遍历T(利用队列,需要预先编辑队列算法)

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
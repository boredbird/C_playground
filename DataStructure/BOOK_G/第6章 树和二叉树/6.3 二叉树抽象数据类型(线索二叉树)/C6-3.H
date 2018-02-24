 /* c6-3.h 二叉树的二叉线索存储表示 */

#include "C6.H"

#ifndef C6_3_H
#define C6_3_H

 typedef enum{Link,Thread}PointerTag; /* Link==0:指针，Thread==1:线索 */

 typedef struct BiThrNode
 {
   TElemType data;
   struct BiThrNode *lchild,*rchild; // 左右孩子指针 
   PointerTag LTag,RTag; // 左右标志 
 }BiThrNode,*BiThrTree;

extern  void CreateBiThrTree(BiThrTree *T);
 // 按先序输入线索二叉树中结点的值，构造线索二叉树T。空格(字符型)表示空结点

extern void PreOrderThreading(BiThrTree *Thrt,BiThrTree T); 
// 先序线索化二叉树T，头结点的右指针指向先序遍历的最后1个结点 
 
extern void PreThreading(BiThrTree p);
//PreOrderThreading()调用的递归函数 

extern void PreOrderTraverse_Thr(BiThrTree T);
 // 先序遍历线索二叉树T(头结点)的非递归算法 

extern void InOrderThreading(BiThrTree *Thrt,BiThrTree T);
 //中序遍历二叉树T，并将其中序线索化，Thrt指向头结点。

extern void InThreading(BiThrTree p);
 // 通过中序遍历进行中序线索化，线索化之后pre指向最后一个结点

extern  void InOrderTraverse_Thr(BiThrTree T);
 //中序遍历线索二叉树T(头结点)的非递归算法。
 
extern void PostOrderThreading(BiThrTree *Thrt,BiThrTree T);
 // 后序递归线索化二叉树 

extern void PostThreading(BiThrTree p);
 // PostOrderThreading()调用的递归函数 
		 
extern void DestroyBiThrTree(BiThrTree *Thrt);
 // 初始条件：线索二叉树Thrt存在。操作结果：销毁线索二叉树Thrt 

extern void DestroyBiTree(BiThrTree *T);
//  销毁二叉树
extern void Visit(TElemType e);
//打印程序

#endif
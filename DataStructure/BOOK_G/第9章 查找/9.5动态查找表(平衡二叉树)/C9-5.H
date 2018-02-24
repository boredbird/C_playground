#include "C9.H"

#ifndef C9_5_H
#define C9_5_H

 #define N 5 /* 数据元素个数 */
 typedef char KeyType; /* 设关键字域为字符型 */
 typedef struct
 {
   KeyType key;
   int order;
 }ElemType; /* 数据元素类型 */

 /*  平衡二叉树的类型 */
 typedef struct BSTNode
 {
   ElemType data;
   int bf; /* 结点的平衡因子 */
   struct BSTNode *lchild,*rchild; /* 左、右孩子指针 */
 }BSTNode,*BSTree;

 typedef BSTree BiTree; /* 定义二叉树基本操作的指针类型 */
 typedef ElemType TElemType; /* 定义二叉树基本操作的树元素类型 */

 /* 对两个数值型关键字的比较约定为如下的宏定义 */
 #define EQ(a,b) ((a)==(b))
 #define LT(a,b) ((a)<(b))
 #define LQ(a,b) ((a)<=(b))

 #define InitDSTable InitBiTree /* 与初始化二叉树的操作同 */
 #define DestroyDSTable DestroyBiTree /* 与销毁二叉树的操作同 */
 #define TraverseDSTable InOrderTraverse /* 与中序遍历二叉树的操作同 */

	 extern void R_Rotate(BSTree *p);
	 extern void L_Rotate(BSTree *p);
	 extern void LeftBalance(BSTree *T);
	 extern void RightBalance(BSTree *T);
	 extern Status InsertAVL(BSTree *T,ElemType e,Status *taller);
	 extern void print(ElemType c);
	 extern  BiTree SearchBST(BiTree T,KeyType key);
   /* 在根指针T所指二叉排序树中递归地查找某关键字等于key的数据元素， */
   /* 若查找成功，则返回指向该数据元素结点的指针，否则返回空指针。算法9.5(a) */
 //二叉树操作
 extern  void InOrderTraverse(BiTree T,void(*Visit)(TElemType));
extern void PreOrderTraverse(BiTree T,void(*Visit)(TElemType));
extern void DestroyBiTree(BiTree *T);
extern  void InitBiTree(BiTree *T);



#endif
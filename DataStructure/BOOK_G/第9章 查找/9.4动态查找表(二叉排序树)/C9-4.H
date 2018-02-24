#include "C9.H"

#ifndef C9_4_H
#define C9_4_H

 #define N 10 /* 数据元素个数 */
 typedef int KeyType; /* 设关键字域为整型 */

 typedef struct
 {
   KeyType key;
   int others;
 } ElemType; /* 数据元素类型 */
 
 typedef ElemType TElemType;

  //对两个数值型关键字的比较约定为如下的宏定义 
 #define EQ(a,b) ((a)==(b))
 #define LT(a,b) ((a)<(b))
 #define LQ(a,b) ((a)<=(b))

  // 二叉树的二叉链表存储表示 
 typedef struct BiTNode
 {
   TElemType data;
   struct BiTNode *lchild,*rchild; /* 左右孩子指针 */
 }BiTNode,*BiTree;


 #define InitDSTable InitBiTree /* 与初始化二叉树的操作同 */
 #define DestroyDSTable DestroyBiTree /* 与销毁二叉树的操作同 */
 #define TraverseDSTable InOrderTraverse /* 与中序遍历二叉树的操作同 */

     extern Status SearchBST1(BiTree *T,KeyType key,BiTree f,BiTree *p);
	 extern Status InsertBST(BiTree *T, ElemType e);
	 extern  Status DeleteBST(BiTree *T,KeyType key);
	 extern  void Delete(BiTree *p);
	 extern  BiTree SearchBST(BiTree T,KeyType key);
	 extern   void print(ElemType c);

//二叉树操作
	 extern  void InitBiTree(BiTree *T);
	 extern void DestroyBiTree(BiTree *T);
	 extern void PreOrderTraverse(BiTree T,void(*Visit)(TElemType));
extern void InOrderTraverse(BiTree T,void(*Visit)(TElemType));


#endif
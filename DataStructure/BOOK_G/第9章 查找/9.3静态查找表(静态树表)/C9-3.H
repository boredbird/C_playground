 #include "C9.h"

#ifndef C9_3_H
#define C9_3_H

 #define N 9 /* 数据元素个数 */
 typedef char KeyType; /* 设关键字域为字符型 */

 typedef struct// 数据元素类型 
 {
   KeyType key; /* 关键字 */
   int weight; /* 权值 */
 }ElemType; // 数据元素类型 

 typedef ElemType TElemType; 

  // 二叉树的二叉链表存储表示 
 typedef struct BiTNode
 {
   TElemType data;
   struct BiTNode *lchild,*rchild; // 左右孩子指针 
 }BiTNode,*BiTree;

 typedef BiTree SOSTree; /* 次优查找树采用二叉链表的存储结构 */

  typedef struct
 {
   ElemType *elem; /* 数据元素存储空间基址，建表时按实际长度分配，0号单元留空 */
   int length; /* 表长度 */
 }SSTable;  

 //对两个数值型关键字的比较约定为如下的宏定义 
 #define EQ(a,b) ((a)==(b))
 #define LT(a,b) ((a)<(b))
 #define LQ(a,b) ((a)<=(b))


extern  void print(ElemType c); /* Traverse()调用的函数 */
extern  void Traverse(SSTable ST,void(*Visit)(ElemType));
extern  int Search_Bin(SSTable ST,KeyType key);
extern  int Search_Seq(SSTable ST,KeyType key);
extern  Status Destroy(SSTable *ST);
extern  void Creat_Ord(SSTable *ST,ElemType r[],int n);
extern void Ascend(SSTable *ST);
extern  void Creat_Seq(SSTable *ST,ElemType r[],int n);
extern  Status Search_SOSTree(SOSTree *T,KeyType key);
extern  void CreateSOSTree(SOSTree *T,SSTable ST);
extern  void FindSW(int sw[],SSTable ST);
extern  Status SecondOptimal(BiTree *T, ElemType R[],int sw[],int low,int high);


#endif
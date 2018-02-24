#include "C9.H"

#ifndef C9_2_H
#define C9_2_H

 #define EQ(a,b) ((a)==(b))
 #define LT(a,b) ((a)<(b))
 #define LQ(a,b) ((a)<=(b))

 #define N 11 /* 数据元素个数 */
 typedef int KeyType; /* 设关键字域为整型 */
 typedef struct
 {
   KeyType key; /* 仅有关键字域 */
 }ElemType; /* 数据元素类型 */

 typedef struct
 {
   ElemType *elem; /* 数据元素存储空间基址，建表时按实际长度分配，0号单元留空 */
   int length; /* 表长度 */
 }SSTable;

extern void print(ElemType c); /* Traverse()调用的函数 */
extern  void Traverse(SSTable ST,void(*Visit)(ElemType));
extern  int Search_Bin(SSTable ST,KeyType key);
extern  int Search_Seq(SSTable ST,KeyType key);
extern  Status Destroy(SSTable *ST);
extern  void Creat_Ord(SSTable *ST,ElemType r[],int n);
extern  void Ascend(SSTable *ST);
extern  void Creat_Seq(SSTable *ST,ElemType r[],int n);

#endif

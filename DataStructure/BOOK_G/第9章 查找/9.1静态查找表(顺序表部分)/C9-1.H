#include "C9.H"

#ifndef C9_1_H
#define C9_1_H

#define N 5 /* 数据元素个数 */
#define key number /* 定义关键字为准考证号 */
typedef long KeyType; /* 设关键字域为长整型 */

 typedef struct//存储数据结构
 {
   long number; /* 准考证号，与关键字类型同 */
   char name[9]; /* 姓名(4个汉字加1个串结束标志) */
   int politics; /* 政治 */
   int Chinese; /* 语文 */
   int English; /* 英语 */
   int math; /* 数学 */
   int physics; /* 物理 */
   int chemistry; /* 化学 */
   int biology; /* 生物 */
   int total; /* 总分 */
 }ElemType; /* 数据元素类型(以教科书图9.1高考成绩为例) */

 typedef struct//表结构
 {
   ElemType *elem;//数据元素存储空间基址，建表时按实际长度分配，0号单元留空 
   int length; /* 表长度 */
 }SSTable;

extern void print(ElemType c); /* Traverse()调用的函数 */
extern  void Traverse(SSTable ST,void(*Visit)(ElemType));
extern  int Search_Seq(SSTable ST,KeyType key);
extern Status Destroy(SSTable *ST);
extern  void Creat_Seq(SSTable *ST,ElemType r[],int n);
 
#endif